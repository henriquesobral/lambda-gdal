// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_RESOURCE_H
#define _GIOMM_RESOURCE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm/error.h>
#include <glibmm/refptr.h>
#include <glibmm/bytes.h>
#include <giomm/inputstream.h>
#include <vector>
#include <string>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GResource GResource;
#endif

namespace Gio
{

/** Exception class for resource file handling errors.
 */
class ResourceError : public Glib::Error
{
public:
  /**  @var Code NOT_FOUND
   * No file was found at the requested path.
   * 
   *  @var Code INTERNAL
   * Unknown error.
   * 
   *  @enum Code
   * 
   * An error code used with RESOURCE_ERROR in a Error returned
   * from a Resource routine.
   * 
   * @newin{2,34}
   */
  enum Code
  {
    NOT_FOUND,
    INTERNAL
  };

  ResourceError(Code error_code, const Glib::ustring& error_message);
  explicit ResourceError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var ResourceFlags RESOURCE_FLAGS_NONE
 * No flags set.
 * 
 *  @var ResourceFlags RESOURCE_FLAGS_COMPRESSED
 * The file is compressed.
 * 
 *  @enum ResourceFlags
 * 
 * GResourceFlags give information about a particular file inside a resource
 * bundle.
 * 
 * @newin{2,44}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%ResourceFlags operator|(ResourceFlags, ResourceFlags)</tt><br>
 * <tt>%ResourceFlags operator&(ResourceFlags, ResourceFlags)</tt><br>
 * <tt>%ResourceFlags operator^(ResourceFlags, ResourceFlags)</tt><br>
 * <tt>%ResourceFlags operator~(ResourceFlags)</tt><br>
 * <tt>%ResourceFlags& operator|=(ResourceFlags&, ResourceFlags)</tt><br>
 * <tt>%ResourceFlags& operator&=(ResourceFlags&, ResourceFlags)</tt><br>
 * <tt>%ResourceFlags& operator^=(ResourceFlags&, ResourceFlags)</tt><br>
 */
enum ResourceFlags
{
  RESOURCE_FLAGS_NONE = 0x0,
  RESOURCE_FLAGS_COMPRESSED = (1<<0)
};

/** @ingroup giommEnums */
inline ResourceFlags operator|(ResourceFlags lhs, ResourceFlags rhs)
  { return static_cast<ResourceFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceFlags operator&(ResourceFlags lhs, ResourceFlags rhs)
  { return static_cast<ResourceFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceFlags operator^(ResourceFlags lhs, ResourceFlags rhs)
  { return static_cast<ResourceFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceFlags operator~(ResourceFlags flags)
  { return static_cast<ResourceFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline ResourceFlags& operator|=(ResourceFlags& lhs, ResourceFlags rhs)
  { return (lhs = static_cast<ResourceFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ResourceFlags& operator&=(ResourceFlags& lhs, ResourceFlags rhs)
  { return (lhs = static_cast<ResourceFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ResourceFlags& operator^=(ResourceFlags& lhs, ResourceFlags rhs)
  { return (lhs = static_cast<ResourceFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::ResourceFlags> : public Glib::Value_Flags<Gio::ResourceFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{

/** 
 *  @var ResourceLookupFlags RESOURCE_LOOKUP_FLAGS_NONE
 * No flags set.
 * 
 *  @enum ResourceLookupFlags
 * 
 * GResourceLookupFlags determine how resource path lookups are handled.
 * 
 * @newin{2,44}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%ResourceLookupFlags operator|(ResourceLookupFlags, ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags operator&(ResourceLookupFlags, ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags operator^(ResourceLookupFlags, ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags operator~(ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags& operator|=(ResourceLookupFlags&, ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags& operator&=(ResourceLookupFlags&, ResourceLookupFlags)</tt><br>
 * <tt>%ResourceLookupFlags& operator^=(ResourceLookupFlags&, ResourceLookupFlags)</tt><br>
 */
enum ResourceLookupFlags
{
  RESOURCE_LOOKUP_FLAGS_NONE = 0x0
};

/** @ingroup giommEnums */
inline ResourceLookupFlags operator|(ResourceLookupFlags lhs, ResourceLookupFlags rhs)
  { return static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceLookupFlags operator&(ResourceLookupFlags lhs, ResourceLookupFlags rhs)
  { return static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceLookupFlags operator^(ResourceLookupFlags lhs, ResourceLookupFlags rhs)
  { return static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ResourceLookupFlags operator~(ResourceLookupFlags flags)
  { return static_cast<ResourceLookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline ResourceLookupFlags& operator|=(ResourceLookupFlags& lhs, ResourceLookupFlags rhs)
  { return (lhs = static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ResourceLookupFlags& operator&=(ResourceLookupFlags& lhs, ResourceLookupFlags rhs)
  { return (lhs = static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ResourceLookupFlags& operator^=(ResourceLookupFlags& lhs, ResourceLookupFlags rhs)
  { return (lhs = static_cast<ResourceLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::ResourceLookupFlags> : public Glib::Value_Flags<Gio::ResourceLookupFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{


/** %Resource framework.
 *
 * Applications and libraries often contain binary or textual data that is
 * really part of the application, rather than user data. For instance
 * Gtk::Builder .ui files, splashscreen images, Gio::Menu markup xml, CSS files,
 * icons, etc. These are often shipped as files in `$datadir/appname`, or
 * manually included as literal strings in the code.
 *
 * The Gio::Resource API and the <tt>glib-compile-resources</tt> program
 * provide a convenient and efficient alternative to this which has some nice properties. You
 * maintain the files as normal files, so it's easy to edit them, but during the build the files
 * are combined into a binary bundle that is linked into the executable. This means that loading
 * the resource files is efficient (as they are already in memory, shared with other instances) and
 * simple (no need to check for things like I/O errors or locate the files in the filesystem). It
 * also makes it easier to create relocatable applications.
 *
 * %Resource files can also be marked as compressed. Such files will be included in the resource bundle
 * in a compressed form, but will be automatically uncompressed when the resource is used. This
 * is very useful e.g. for larger text files that are parsed once (or rarely) and then thrown away.
 *
 * %Resource files can also be marked to be preprocessed, by setting the value of the
 * `preprocess` attribute to a comma-separated list of preprocessing options.
 * The only options currently supported are:
 *
 * <dl>
 * <dt>xml-stripblanks</dt>
 *   <dd>which will use the <tt>xmllint</tt> command
 *   to strip ignorable whitespace from the xml file. For this to work,
 *   the `XMLLINT` environment variable must be set to the full path to
 *   the <tt>xmllint</tt> executable, or <tt>xmllint</tt> must be in the `PATH`; otherwise
 *   the preprocessing step is skipped.</dd>
 *
 * <dt>to-pixdata</dt>
 *   <dd>which will use the <tt>gdk-pixbuf-pixdata</tt> command to convert
 *   images to the GdkPixdata format, which allows you to create pixbufs directly using the data inside
 *   the resource file, rather than an (uncompressed) copy of it. For this, the <tt>gdk-pixbuf-pixdata</tt>
 *   program must be in the PATH, or the `GDK_PIXBUF_PIXDATA` environment variable must be
 *   set to the full path to the <tt>gdk-pixbuf-pixdata</tt> executable; otherwise the resource compiler will
 *   abort.</dd>
 * </dl>
 *
 * %Resource bundles are created by the <tt>glib-compile-resources</tt> program
 * which takes an xml file that describes the bundle, and a set of files that the xml references. These
 * are combined into a binary resource bundle.
 *
 * An example resource description:
 * @code
 * <?xml version="1.0" encoding="UTF-8"?>
 * <gresources>
 *   <gresource prefix="/org/gtk/Example">
 *     <file>data/splashscreen.png</file>
 *     <file compressed="true">dialog.ui</file>
 *     <file preprocess="xml-stripblanks">menumarkup.xml</file>
 *   </gresource>
 * </gresources>
 * @endcode
 *
 * This will create a resource bundle with the following files:
 * @code
 * /org/gtk/Example/data/splashscreen.png
 * /org/gtk/Example/dialog.ui
 * /org/gtk/Example/menumarkup.xml
 * @endcode
 *
 * Note that all resources in the process share the same namespace, so use java-style
 * path prefixes (like in the above example) to avoid conflicts.
 *
 * You can then use <tt>glib-compile-resources</tt> to compile the xml to a binary bundle
 * that you can load with Gio::Resource::create_from_file(). However, it's more common to use the --generate-source and
 * --generate-header arguments to create a source file and header to link directly into your application.
 *
 * Once a Gio::Resource has been created and registered all the data in it can be accessed globally in the process by
 * using API calls like Gio::Resource::open_stream_from_global_resources() to stream the data
 * or Gio::Resource::lookup_data_in_global_resources() to get a direct pointer
 * to the data. You can also use uris like "resource:///org/gtk/Example/data/splashscreen.png" with Gio::File to access
 * the resource data.
 *
 * There are two forms of the generated source, the default version uses the compiler support for constructor
 * and destructor functions (where available) to automatically create and register the Gio::Resource on startup
 * or library load time. If you pass --manual-register, two functions to register/unregister the resource is instead
 * created. This requires an explicit initialization call in your application/library, but it works on all platforms,
 * even on the minor ones where this is not available. (Constructor support is available for at least Win32, MacOS and Linux.)
 *
 * Note that resource data can point directly into the data segment of e.g. a library, so if you are unloading libraries
 * during runtime you need to be very careful with keeping around pointers to data from a resource, as this goes away
 * when the library is unloaded. However, in practice this is not generally a problem, since most resource accesses
 * is for your own resources, and resource data is often used once, during parsing, and then released.
 *
 * @newin{2,44}
 */
class Resource final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Resource CppObjectType;
  typedef GResource BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  GResource*       gobj();

  ///Provides access to the underlying C instance.
  const GResource* gobj() const;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GResource* gobj_copy() const;

  Resource() = delete;

  // noncopyable
  Resource(const Resource&) = delete;
  Resource& operator=(const Resource&) = delete;

protected:
  // Do not derive this.  Gio::Resource can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:

  
public:
  
  /** Creates a GResource from a reference to the binary resource bundle.
   * This will keep a reference to @a data while the resource lives, so
   * the data should not be modified or freed.
   * 
   * If you want to use this resource in the global resource namespace you need
   * to register it with g_resources_register().
   * 
   * @newin{2,44}
   * 
   * @param data A Bytes.
   * @return A new Resource, or <tt>0</tt> on error.
   */
  static Glib::RefPtr<Resource> create_from_data(const Glib::RefPtr<const Glib::Bytes>& data);
  
  /** Loads a binary resource bundle and creates a Resource representation of it, allowing
   * you to query it for data.
   * 
   * If you want to use this resource in the global resource namespace you need
   * to register it with g_resources_register().
   * 
   * @newin{2,44}
   * 
   * @param filename The path of a filename to load, in the GLib filename encoding.
   * @return A new Resource, or <tt>0</tt> on error.
   */
  static Glib::RefPtr<Resource> create_from_file(const std::string& filename);
  
  /** Looks for a file at the specified @a path in the resource and
   * returns a InputStream that lets you read the data.
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return InputStream or <tt>0</tt> on error.
   * Free the returned object with Glib::object_unref().
   */
  Glib::RefPtr<InputStream> open_stream(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE) const;
  
  /** Looks for a file at the specified @a path in the resource and
   * returns a Bytes that lets you directly access the data in
   * memory.
   * 
   * The data is always followed by a zero byte, so you
   * can safely use the data as a C string. However, that byte
   * is not included in the size of the GBytes.
   * 
   * For uncompressed resource files this is a pointer directly into
   * the resource bundle, which is typically in some readonly data section
   * in the program binary. For compressed files we allocate memory on
   * the heap and automatically uncompress the data.
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return Bytes or <tt>0</tt> on error.
   * Free the returned object with Glib::bytes_unref().
   */
  Glib::RefPtr<const Glib::Bytes> lookup_data(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE) const;

 
  /** Returns all the names of children at the specified @a path in the resource.
   * The return result is a <tt>0</tt> terminated list of strings which should
   * be released with Glib::strfreev().
   * 
   * If @a path is invalid or does not exist in the Resource,
   * RESOURCE_ERROR_NOT_FOUND will be returned.
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return An array of constant strings.
   */
  std::vector<std::string> enumerate_children(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE) const;

  /** Looks for a file at the specified @a path in the resource and
   * if found returns information about it.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param[out] size A location to place the length of the contents of the file.
   * @param[out] flags A location to place the flags about the file.
   * @param lookup_flags A ResourceLookupFlags.
   * @throw Gio::ResourceError if the file was not found.
   */
  void get_info(const std::string& path, gsize& size, ResourceFlags& flags, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE) const;
  

  /** Looks for a file at the specified @a path in the resource.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @throw Gio::ResourceError if the file was not found.
   */
  void get_file_exists(const std::string& path, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE) const;

  /** Looks for a file at the specified @a path in the resource.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   * This method returns a <tt>bool</tt> instead of throwing in exception in case of errors.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return <tt>true</tt> if the file was found, <tt>false</tt> if there were errors.
   */
  bool get_file_exists_nothrow(const std::string& path, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE) const;

  // 'register' is a keyword. Can't be the name of a method.
  
  /** Registers the resource with the process-global set of resources.
   * Once a resource is registered the files in it can be accessed
   * with the global resource lookup functions like g_resources_lookup_data().
   * 
   * @newin{2,44}
   */
  void register_global();
  
  /** Unregisters the resource from the process-global set of resources.
   * 
   * @newin{2,44}
   */
  void unregister_global();
  
  /** Looks for a file at the specified @a path in the set of
   * globally registered resources and returns a InputStream
   * that lets you read the data.
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return InputStream or <tt>0</tt> on error.
   * Free the returned object with Glib::object_unref().
   */
  static Glib::RefPtr<InputStream> open_stream_global(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE);
  
  /** Looks for a file at the specified @a path in the set of
   * globally registered resources and returns a Bytes that
   * lets you directly access the data in memory.
   * 
   * The data is always followed by a zero byte, so you
   * can safely use the data as a C string. However, that byte
   * is not included in the size of the GBytes.
   * 
   * For uncompressed resource files this is a pointer directly into
   * the resource bundle, which is typically in some readonly data section
   * in the program binary. For compressed files we allocate memory on
   * the heap and automatically uncompress the data.
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return Bytes or <tt>0</tt> on error.
   * Free the returned object with Glib::bytes_unref().
   */
  static Glib::RefPtr<const Glib::Bytes> lookup_data_global(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE);
  
  /** Returns all the names of children at the specified @a path in the set of
   * globally registered resources.
   * The return result is a <tt>0</tt> terminated list of strings which should
   * be released with Glib::strfreev().
   * 
   *  @a lookup_flags controls the behaviour of the lookup.
   * 
   * @newin{2,44}
   * 
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return An array of constant strings.
   */
  static std::vector<std::string> enumerate_children_global(const std::string& path, ResourceLookupFlags lookup_flags =  RESOURCE_LOOKUP_FLAGS_NONE);

  /** Looks for a file at the specified @a path in the set of
   * globally registered resources and if found returns information about it.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param[out] size A location to place the length of the contents of the file.
   * @param[out] flags A location to place the flags about the file.
   * @param lookup_flags A ResourceLookupFlags.
   * @throw Gio::ResourceError if the file was not found.
   */
  static void get_info_global(const std::string& path, gsize& size, ResourceFlags& flags, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE);
  

  /** Looks for a file at the specified @a path in the set of
   * globally registered resources.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @throw Gio::ResourceError if the file was not found.
   */
  static void get_file_exists_global(const std::string& path, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE);

  /** Looks for a file at the specified @a path in the set of
   * globally registered resources.
   *
   * @a lookup_flags controls the behaviour of the lookup.
   * This method returns a <tt>bool</tt> instead of throwing in exception in case of errors.
   *
   * @newin{2,44}
   *
   * @param path A pathname inside the resource.
   * @param lookup_flags A ResourceLookupFlags.
   * @return <tt>true</tt> if the file was found, <tt>false</tt> if there were errors.
   */
  static bool get_file_exists_global_nothrow(const std::string& path, ResourceLookupFlags lookup_flags = RESOURCE_LOOKUP_FLAGS_NONE);

  
};

} // namespace Gio


namespace Glib
{

  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Resource
   */
  Glib::RefPtr<Gio::Resource> wrap(GResource* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_RESOURCE_H */

