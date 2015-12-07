#!/usr/bin/env bash
# this script generates and tiles contours from a DSM
# usage: contours.sh <dsm.tif> <interval> <color_slope> <mapnik_style> <zoom> <piles.json> <colors>
# example: contours.sh dsm.tif 1.0 style.xml 15-22 piles.json "#d53e4f,#fc8d59,#fee08b,#e6f598,#99d594,#3288bd"
# outputs: the directory that contains the tileset
dsm=$1
interval=$2
color_slope=$3
style=$4
zoom=$5
piles=$6
colors=$7
outputDir=/tmp/$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32)
outputHillShadeTif=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32).tif
outputColorReliefTif=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32).tif
outputSlopeTif=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32).tif
outputSlopeShadeTif=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32).tif
outputPng=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 32).png

SCRIPT_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# replace these variables with the locations of these gdal utilities
gdalbuildvrt=$(which gdalbuildvrt)
gdal2tiles=$(which gdal2tiles.py)
gdalsrsinfo=$(which gdalsrsinfo)
gdalinfo=$(which gdalinfo)
gdal_translate=$(which gdal_translate)
gdal_warp=$(which gdalwarp)
gdaltransform=$(which gdaltransform)
gdal_contour=$(which gdal_contour)
gdaldem=$(which gdaldem)
nik2img=$(which nik2img.py)
pileRange="$SCRIPT_PATH/pileRange.js"
cropMap="$SCRIPT_PATH/cropMap.js"

function gdal_extent() {
    EXTENT=$($gdalinfo $1 |\
        grep "Upper Left\|Lower Right" |\
        sed "s/Upper Left  //g;s/Lower Right //g;s/).*//g" |\
        tr "\n" " " |\
        sed 's/ *$//g' |\
        tr -d "[(,]")
    echo -n "$EXTENT"
}

function nodata_value() {
  NODATA=$($gdalinfo $1 |\
    grep "NoData Value=" |\
    sed "s/NoData Value=//g" |\
    xargs)
  echo -n "$NODATA"  
}

function get_range() {
  RANGE=$($gdalinfo -mm $1 |\
    grep "Computed Min\/Max=" |\
    sed "s/Computed Min\/Max=//g" |\
    xargs)

  echo -n "$RANGE"
}

function min_value() {
  RANGE=$(get_range $1)
  aRange=(${RANGE//,/ })
  echo -n "${aRange[0]}"
}

function max_value() {
  RANGE=$(get_range $1)
  aRange=(${RANGE//,/ })
  echo -n "${aRange[1]}"
}

function dimensions_value() {
  DIMENSIONS=$($gdalinfo $1 |\
    grep "Size is" |\
    sed "s/Size is//g" |\
    sed "s/,//g" |\
    xargs)
  DIMARRAY=($DIMENSIONS)
  echo -n "${DIMARRAY[0]} ${DIMARRAY[1]}"
}

base_style=$(cat $style)
base_color_slope=$(cat $color_slope)
srs=$(gdalsrsinfo -o wkt $dsm)
proj4=$(gdalsrsinfo -o proj4 $dsm | tr "'" " " | xargs)
style=${base_style/\$proj4/$proj4} 
outputShp="$outputDir/contours.shp"
style=${style/\$shapefile/$outputShp}

destSlopeShadeTif="$outputDir/$outputSlopeShadeTif"
destHillShadeTif="$outputDir/$outputHillShadeTif"

style=${style/\$destSlopeShadeTif/$destSlopeShadeTif}
style=${style/\$destHillShadeTif/$destHillShadeTif}

destStyle="$outputDir/style.xml"
pileStyle="$outputDir/piles.xml"
destColorSlope="$outputDir/color_slope.txt"

extent=$(gdal_extent $dsm)
nodata=$(nodata_value $dsm)
dimensions=$(dimensions_value $dsm)
mercator="EPSG:3857"

# these commands will be run
warp="$gdal_warp $dsm -t_srs $mercator -r bilinear $outputDir/mercator_dsm.tif"

# scale to meters and preserve nodata
warpToMeters1="$gdal_warp -dstnodata -10000 $outputDir/mercator_dsm.tif $outputDir/mercator_dsm_meters1.tif"
warpToMeters2="$gdal_translate -scale 0 100000 0 30480 -a_nodata -3048 $outputDir/mercator_dsm_meters1.tif $outputDir/mercator_dsm_meters2.tif"

# scale to imperial (US-FT) and preserve nodata
warpToImperial1="$gdal_warp -dstnodata -3048 $outputDir/mercator_dsm.tif $outputDir/mercator_dsm_imperial1.tif"
warpToImperial2="$gdal_translate -scale 0 30480 0 100000 -a_nodata -10000 $outputDir/mercator_dsm_imperial1.tif $outputDir/mercator_dsm_imperial2.tif"

contour="$gdal_contour -a height $dsm -i $interval $outputDir/contours.shp"
hillshadeTif="$gdaldem hillshade $dsm $destHillShadeTif"
pileShades="$pileRange $piles $dsm \"$colors\" $destStyle $pileStyle $outputDir/markerContours.json $outputDir"
slopeTif="$gdaldem slope $dsm $outputDir/$outputSlopeTif"
slopeShadeTif="$gdaldem color-relief $outputDir/$outputSlopeTif $destColorSlope $destSlopeShadeTif"

translate="$gdal_translate -of VRT -a_ullr $extent -a_srs '$srs' $outputDir/$outputPng $outputDir/contours.vrt"
#warp="$gdal_warp -of VRT -s_srs '$srs' -t_srs EPSG:3857 $outputDir/contours.vrt $outputDir/contours_mercator.vrt"

map="$nik2img $pileStyle $outputDir/$outputPng -d $dimensions -e $extent"
crop="$cropMap $piles $outputDir/contours.vrt \"$proj4\" $outputDir $outputDir/markerContours.json"
tile="$gdal2tiles -p mercator -z $zoom $outputDir/contours_mercator.vrt"

mkdir -p $outputDir
echo "$style" >> "$destStyle"
echo -e "$base_color_slope" >> "$destColorSlope"
echo $contour
echo $hillshadeTif
echo $reliefTif
echo $slopeTif
echo $slopeShadeTif
echo $pileShades
echo $map
echo $translate
echo $crop
#echo $warp
#cd $outputDir
#echo $tile
echo -n "Contour tiles generated to: " $outputDir
