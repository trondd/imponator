/** $Id: imp_decoder.h 17 2005-10-09 11:22:59Z trondd $
 *
 * Decoder lib
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

#ifndef IMP_DECODER_H
#define IMP_DECODER_H

#include <inttypes.h>


/** imp_anim_decode_frames()
 *
 * Will decode a single frame and load it into the framebuffer
 */
void imp_anim_decode_frame (volatile uint16_t * framepointer);

/** imp_anim_next_fram  ()
 * 
 * Select next frame in sequence */
void imp_anim_next_frame (void);

#endif
