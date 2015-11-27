// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_UNIXINPUTSTREAM_P_H
#define _GIOMM_UNIXINPUTSTREAM_P_H


#include <giomm/private/inputstream_p.h>

#include <glibmm/class.h>

namespace Gio
{

class UnixInputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef UnixInputStream CppObjectType;
  typedef GUnixInputStream BaseObjectType;
  typedef GUnixInputStreamClass BaseClassType;
  typedef Gio::InputStream_Class CppClassParent;
  typedef GInputStreamClass BaseClassParent;

  friend class UnixInputStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_UNIXINPUTSTREAM_P_H */

