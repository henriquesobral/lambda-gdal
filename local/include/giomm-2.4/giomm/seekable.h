// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_SEEKABLE_H
#define _GIOMM_SEEKABLE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <giomm/cancellable.h>
#include <glibmm/interface.h>
#include <glibmm/iochannel.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSeekableIface GSeekableIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSeekable GSeekable;
typedef struct _GSeekableClass GSeekableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class Seekable_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Stream seeking interface.
 * Seekable is implemented by streams (implementations of InputStream or OutputStream) that support seeking.
 * To find the position of a stream, use tell(). To find
 * out if a stream supports seeking, use can_seek(). To position a
 * stream, use seek(). To find out if a stream supports
 * truncating, use can_truncate(). To truncate a stream, use
 * truncate().
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class Seekable : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Seekable CppObjectType;
  typedef Seekable_Class CppClassType;
  typedef GSeekable BaseObjectType;
  typedef GSeekableIface BaseClassType;

  // noncopyable
  Seekable(const Seekable&) = delete;
  Seekable& operator=(const Seekable&) = delete;

private:
  friend class Seekable_Class;
  static CppClassType seekable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Seekable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit Seekable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit Seekable(GSeekable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Seekable(Seekable&& src) noexcept;
  Seekable& operator=(Seekable&& src) noexcept;

  virtual ~Seekable() noexcept;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GSeekable*       gobj()       { return reinterpret_cast<GSeekable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GSeekable* gobj() const { return reinterpret_cast<GSeekable*>(gobject_); }

private:


public:
  
  /** Tells the current position within the stream.
   * 
   * @return The offset from the beginning of the buffer.
   */
  goffset tell() const;
  
  /** Tests if the stream supports the SeekableIface.
   * 
   * @return <tt>true</tt> if @a seekable can be seeked. <tt>false</tt> otherwise.
   */
  bool can_seek() const;

  
  /** Seeks in the stream by the given @a offset, modified by @a type.
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * 
   * @param offset A #goffset.
   * @param type A SeekType.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if successful. If an error
   * has occurred, this function will return <tt>false</tt> and set @a error
   * appropriately if present.
   */
  bool seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable);

  /// A seek() convenience overload.
  bool seek(goffset offset, Glib::SeekType type);

  //TODO: Document the exception in the C API: https://bugzilla.gnome.org/show_bug.cgi?id=509990#c1

  
  /** Tests if the stream can be truncated.
   * 
   * @return <tt>true</tt> if the stream can be truncated, <tt>false</tt> otherwise.
   */
  bool can_truncate() const;

  
  /** Truncates a stream with a given #offset. 
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   * 
   * @param offset A #goffset.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if successful. If an error
   * has occurred, this function will return <tt>false</tt> and set @a error
   * appropriately if present.
   */
  bool truncate(goffset offset, const Glib::RefPtr<Cancellable>& cancellable);

  /// A truncate() convenience overload.
  bool truncate(goffset offset);

  //TODO: Document the exception in the C API: https://bugzilla.gnome.org/show_bug.cgi?id=509990#c1

  //_WRAP_VFUNC(goffset tell() const, tell)
  //_WRAP_VFUNC(goffset can_seek() const, can_seek)
  //_WRAP_VFUNC(goffset seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable, GError** error), seek)
  //_WRAP_VFUNC(goffset can_truncate() const, can_truncate)

  //Renamed to truncate() - we don't know why it's called truncate_fn in C.
  //_WRAP_VFUNC(goffset truncate(goffset offset, const Glib::RefPtr<Cancellable>& cancellable, GError** error), truncate_fn)

  //There are no properties or signals.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::Seekable
   */
  Glib::RefPtr<Gio::Seekable> wrap(GSeekable* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_SEEKABLE_H */

