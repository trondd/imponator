/** $Id: imp_animation.h 17 2005-10-09 11:22:59Z trondd $
 *
 * Header file containing the animation
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

#ifndef IMP_ANIMATION_H
#define IMP_ANIMATION_H


#include "imp_animation_def.h"
#include "imp_animation_macros.h"

/* The animation sequence */
PROGMEM Frame animation[] = {
  SHIFT_ONE_CW,
  SHIFT_ONE_CCW,
  SHIFT_ONE_CW,
  SHIFT_ONE_CCW,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  FADE_IN,
  FLASH,
  FLASH,
  FLASH,
  FADE_OUT,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  FILL_FROM_RIGHT,
  FADE_OUT,
  ALL_BLACK,
  ALL_BLACK,
  FILL_FROM_LEFT,
  FADE_OUT,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  FILL_FROM_RIGHT,
  CLEAR_FROM_LEFT,
  FILL_FROM_RIGHT,
  CLEAR_FROM_LEFT,
  FILL_FROM_RIGHT,
  CLEAR_FROM_LEFT,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  FADE_IN,
  FLASH,
  FLASH,
  FADE_OUT,
  ALL_BLACK,
  ALL_BLACK,
  ALL_BLACK,
  EO_ANIM,
};


#endif
