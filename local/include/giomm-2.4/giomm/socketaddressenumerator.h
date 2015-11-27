// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_SOCKETADDRESSENUMERATOR_H
#define _GIOMM_SOCKETADDRESSENUMERATOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The giomm Development Team
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
#include <giomm/cancellable.h>
#include <giomm/asyncresult.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSocketAddressEnumerator GSocketAddressEnumerator;
typedef struct _GSocketAddressEnumeratorClass GSocketAddressEnumeratorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class SocketAddressEnumerator_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class SocketAddress;

/** Enumerator type for objects that contain or generate SocketAddresses
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class SocketAddressEnumerator : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SocketAddressEnumerator CppObjectType;
  typedef SocketAddressEnumerator_Class CppClassType;
  typedef GSocketAddressEnumerator BaseObjectType;
  typedef GSocketAddressEnumeratorClass BaseClassType;

  // noncopyable
  SocketAddressEnumerator(const SocketAddressEnumerator&) = delete;
  SocketAddressEnumerator& operator=(const SocketAddressEnumerator&) = delete;

private:  friend class SocketAddressEnumerator_Class;
  static CppClassType socketaddressenumerator_class_;

protected:
  explicit SocketAddressEnumerator(const Glib::ConstructParams& construct_params);
  explicit SocketAddressEnumerator(GSocketAddressEnumerator* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketAddressEnumerator(SocketAddressEnumerator&& src) noexcept;
  SocketAddressEnumerator& operator=(SocketAddressEnumerator&& src) noexcept;

  virtual ~SocketAddressEnumerator() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GSocketAddressEnumerator*       gobj()       { return reinterpret_cast<GSocketAddressEnumerator*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GSocketAddressEnumerator* gobj() const { return reinterpret_cast<GSocketAddressEnumerator*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GSocketAddressEnumerator* gobj_copy();

private:


public:
  
  /** Retrieves the next SocketAddress from @a enumerator. Note that this
   * may block for some amount of time. (Eg, a NetworkAddress may need
   * to do a DNS lookup before it can return an address.) Use
   * g_socket_address_enumerator_next_async() if you need to avoid
   * blocking.
   * 
   * If @a enumerator is expected to yield addresses, but for some reason
   * is unable to (eg, because of a DNS error), then the first call to
   * g_socket_address_enumerator_next() will return an appropriate error
   * in * @a error. However, if the first call to
   * g_socket_address_enumerator_next() succeeds, then any further
   * internal errors (other than @a cancellable being triggered) will be
   * ignored.
   * 
   * @param cancellable Optional Cancellable object, <tt>0</tt> to ignore.
   * @return A SocketAddress (owned by the caller), or <tt>0</tt> on
   * error (in which case * @a error will be set) or if there are no
   * more addresses.
   */
  Glib::RefPtr<SocketAddress> next(const Glib::RefPtr<Cancellable>& cancellable);

  /// A next() convenience overload.
  Glib::RefPtr<SocketAddress> next();

  /** Asynchronously retrieves the next SocketAddress from the enumerator and then calls @a slot,
   * which must call next_finish() to get the result.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param slot A callback slot to call after the resolution completes.
   */
  void next_async(const Glib::RefPtr<Cancellable>& cancellable, const SlotAsyncReady& slot);

  /** Asynchronously retrieves the next SocketAddress from the enumerator and then calls @a slot,
   * which must call next_finish() to get the result.
   *
   * @param slot A callback slot to call after the resolution completes.
   */
  void next_async(const SlotAsyncReady& slot);
  

  /** Retrieves the result of a completed call to
   * g_socket_address_enumerator_next_async(). See
   * g_socket_address_enumerator_next() for more information about
   * error handling.
   * 
   * @param result A AsyncResult.
   * @return A SocketAddress (owned by the caller), or <tt>0</tt> on
   * error (in which case * @a error will be set) or if there are no
   * more addresses.
   */
  Glib::RefPtr<SocketAddress> next_finish(const Glib::RefPtr<AsyncResult>& result);


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
   * @relates Gio::SocketAddressEnumerator
   */
  Glib::RefPtr<Gio::SocketAddressEnumerator> wrap(GSocketAddressEnumerator* object, bool take_copy = false);
}


#endif /* _GIOMM_SOCKETADDRESSENUMERATOR_H */
