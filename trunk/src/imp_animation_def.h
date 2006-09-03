/** $Id: imp_animation_def.h 17 2005-10-09 11:22:59Z trondd $ 
 *
 * Copyright 2005 Omega Verksted.
 *
 * This file is part of Imponator 2005.  Imponator 2005 is free
 * software; you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version. 
 *
 * Imponator 2005 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Imponator 2005; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA 
 * 
 */

#ifndef _IMP_ANIMATION_DEF_H_
#define _IMP_ANIMATION_DEF_H_

#include <avr/pgmspace.h>

/* -------------------- 
 * Typedefs and structs
 * --------------------
 */
typedef uint8_t Frame_data[8];
typedef uint8_t Frame_control;

typedef struct
{
  Frame_data frame;
  Frame_control control_byte;
} Frame;


#endif
