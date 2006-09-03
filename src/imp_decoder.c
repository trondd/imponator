/** $Id: imp_decoder.c 17 2005-10-09 11:22:59Z trondd $
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

#include "imp_decoder.h"
#include "imp_animation.h"

volatile uint8_t current_frame;

void
imp_anim_decode_frame (volatile uint16_t * framepointer)
{
  /*  */
  uint8_t i = 0;
  int8_t j = 0;
  /* */
  uint8_t tmp = 0;
  uint8_t left_side = 0;
  uint8_t right_side = 0;

  /* Clear buffer */
  for (i = 0; i < 16; i++)
    {
      *(framepointer + i) = 0x0000;
    }

  for (i = 0; i < 8; i++)
    {
      tmp =
        (uint8_t) pgm_read_byte_near ((uint16_t) (animation) +
                                      sizeof (Frame) * current_frame + i);

      left_side = tmp & 0x0f;
      right_side = tmp >> 4;

      j = 0;
      while (right_side)
        {
          *(framepointer + (uint16_t) j) |= (1 << i);
          j++;
          right_side--;
        }

      j = 0;
      while (left_side)
        {
          *(framepointer + (uint16_t) j) |= (1 << (i + 8));
          j++;
          left_side--;
        }

    }
}

void
imp_anim_next_frame (void)
{
  current_frame++;

  // If next frame is EO_ANIM, rewind the animation
  if ((uint8_t)
      pgm_read_byte_near ((uint16_t) (animation) +
                          sizeof (Frame) * current_frame + 8) == 0xff)
    {
      current_frame = 0;
    }
}
