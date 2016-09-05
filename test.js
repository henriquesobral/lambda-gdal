var child_process = require('child_process'),
    path = require('path'),
    cwd  = path.dirname(require.main.filename);

var currentPath = process.env['PATH'];
var worker = child_process.fork('./worker.js', { env: { TASK_ROOT: cwd, PATH: currentPath + ':' + path.resolve(cwd, 'local', 'bin'), LD_LIBRARY_PATH: path.resolve(cwd, 'local', 'lib') }});
worker.on('message', function(m) {
	if(m.error !== undefined) {
			console.log('Error occured!');
			console.log(JSON.stringify(m));
	} else {
	    console.log('Done');
			console.log(JSON.stringify(m));
	}
  worker.kill();
});

worker.send({
  dsm: {
    bucket: 'aeroscan-dev',
    key: 'orthomosaics/data/62c/466/a9-/original/ortho.tif'
  },
  zoom: '18-22'
});
