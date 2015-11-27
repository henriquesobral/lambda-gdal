// -*- c++ -*-
#ifndef _GLIBMM_SARRAY_H
#define _GLIBMM_SARRAY_H

/* $Id$ */

/* array.h
 *
 * Copyright (C) 2002 The gtkmm Development Team
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

#ifndef GLIBMM_DISABLE_DEPRECATED
#include <glibmm/arrayhandle.h>
#include <glibmm/ustring.h>

namespace Glib {

/**
 * @deprecated Use a std::vector instead.
 */
typedef Glib::ArrayHandle<Glib::ustring> SArray;

}

#endif //GLIBMM_DISABLE_DEPRECATED

#endif // _GLIBMM_SARRAY_H

