// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_POLLABLEOUTPUTSTREAM_H
#define _GIOMM_POLLABLEOUTPUTSTREAM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2012 The giomm Development Team
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

#include <glibmm/interface.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableOutputStreamInterface GPollableOutputStreamInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableOutputStream GPollableOutputStream;
typedef struct _GPollableOutputStreamClass GPollableOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class PollableOutputStream_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class Cancellable;

//TODO: Instead derive from OutputStream, when we can break ABI,
//because the GPollableOutputStream interface requires the GOutputStream interface.
//LoadableIcon does a similar thing correctly, for instance.

/** PollableOutputStream - Interface for pollable output streams.
 * PollableOutputStream is implemented by OutputStreams that can be polled for
 * readiness to write. This can be used when interfacing with a non-GIO API
 * that expects UNIX-file-descriptor-style asynchronous I/O rather than
 * GIO-style.
 * @newin{2,34}
 */

class PollableOutputStream : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef PollableOutputStream CppObjectType;
  typedef PollableOutputStream_Class CppClassType;
  typedef GPollableOutputStream BaseObjectType;
  typedef GPollableOutputStreamInterface BaseClassType;

  // noncopyable
  PollableOutputStream(const PollableOutputStream&) = delete;
  PollableOutputStream& operator=(const PollableOutputStream&) = delete;

private:
  friend class PollableOutputStream_Class;
  static CppClassType pollableoutputstream_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  PollableOutputStream();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit PollableOutputStream(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit PollableOutputStream(GPollableOutputStream* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PollableOutputStream(PollableOutputStream&& src) noexcept;
  PollableOutputStream& operator=(PollableOutputStream&& src) noexcept;

  virtual ~PollableOutputStream() noexcept;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GPollableOutputStream*       gobj()       { return reinterpret_cast<GPollableOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GPollableOutputStream* gobj() const { return reinterpret_cast<GPollableOutputStream*>(gobject_); }

private:


public:
  
  /** Checks if @a stream is actually pollable. Some classes may implement
   * PollableOutputStream but have only certain instances of that
   * class be pollable. If this method returns <tt>false</tt>, then the behavior
   * of other PollableOutputStream methods is undefined.
   * 
   * For any given stream, the value returned by this method is constant;
   * a stream cannot switch from pollable to non-pollable or vice versa.
   * 
   * @newin{2,28}
   * 
   * @return <tt>true</tt> if @a stream is pollable, <tt>false</tt> if not.
   */
  bool can_poll() const;
  
  /** Checks if @a stream can be written.
   * 
   * Note that some stream types may not be able to implement this 100%
   * reliably, and it is possible that a call to g_output_stream_write()
   * after this returns <tt>true</tt> would still block. To guarantee
   * non-blocking behavior, you should always use
   * g_pollable_output_stream_write_nonblocking(), which will return a
   * IO_ERROR_WOULD_BLOCK error rather than blocking.
   * 
   * @newin{2,28}
   * 
   * @return <tt>true</tt> if @a stream is writable, <tt>false</tt> if not. If an error
   * has occurred on @a stream, this will result in
   * g_pollable_output_stream_is_writable() returning <tt>true</tt>, and the
   * next attempt to write will return the error.
   */
  bool is_writable() const;

  //TODO: _WRAP_METHOD(Glib::RefPtr<Source> create_source(const Glib::RefPtr<Cancellable>& cancellable), g_pollable_output_stream_create_source)

  
  /** Attempts to write up to @a count bytes from @a buffer to @a stream, as
   * with g_output_stream_write(). If @a stream is not currently writable,
   * this will immediately return IO_ERROR_WOULD_BLOCK, and you can
   * use g_pollable_output_stream_create_source() to create a Source
   * that will be triggered when @a stream is writable.
   * 
   * Note that since this method never blocks, you cannot actually
   * use @a cancellable to cancel it. However, it will return an error
   * if @a cancellable has already been cancelled when you call, which
   * may happen if you call this method after a source triggers due
   * to having been cancelled.
   * 
   * Virtual: write_nonblocking
   * 
   * @param buffer A buffer to write
   * data from.
   * @param count The number of bytes you want to write.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return The number of bytes written, or -1 on error (including
   * IO_ERROR_WOULD_BLOCK).
   */
  gssize write_nonblocking(const void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable);

  /// A write_nonblocking() convenience overload.
  gssize write_nonblocking(const void* buffer, gsize count);

    virtual bool can_poll_vfunc() const;

    virtual bool is_writable_vfunc() const;


  //TODO:_WRAP_VFUNC(Glib::RefPtr<Source> create_source(const Glib::RefPtr<Cancellable>& cancellable), "create_source")

  /// @throws Glib::Error.
  virtual gssize write_nonblocking_vfunc(const void* buffer, gsize count);


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
   * @relates Gio::PollableOutputStream
   */
  Glib::RefPtr<Gio::PollableOutputStream> wrap(GPollableOutputStream* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_POLLABLEOUTPUTSTREAM_H */

