/** $Id: imp2005.c 17 2005-10-09 11:22:59Z trondd $
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

#include "imp2005.h"


int
main (void)
{
  init_avr ();
  fb_index = 0;
  select_ground = LEFT;
  frame_pointer = frame_buffer;
  imp_anim_decode_frame (frame_pointer);

  /* Main loop, will run for ever */
  sei ();
  for (;;)
    {
    }
}


/** Timer0 (8 bit)
 * Controls software pwm of diode intensivity
 */
SIGNAL (SIG_OVERFLOW0)
{
  SET_PWM_RATE;
  frame_pointer++;
  fb_index++;
  if (fb_index == 16)           // Restart at the end of the fb
    {
      frame_pointer = frame_buffer;
      fb_index = 0;
    }
}

/** Timer2 (8 bit)
 * Toggles ground.
 */
SIGNAL (SIG_OVERFLOW2)
{
  LEDS = 0x00;

  switch (select_ground)
    {
    case LEFT:
      GROUND = 0x04;
      LEDS = ((*frame_pointer) & 0x00ff);
      select_ground = RIGHT;
      break;
    case RIGHT:
      GROUND = 0x08;
      LEDS = ((*frame_pointer) >> 8);
      select_ground = LEFT;
      break;
    }

}

/** Timer1 (16 bit)
 * Frames
 */
SIGNAL (SIG_OVERFLOW1)
{
  /* Set timer 1 to get timing right */
  SET_FRAMERATE;

  /* Reset the frame_pointer */
  frame_pointer = frame_buffer;

  /* Decode frame to the frame_buffer */
  imp_anim_decode_frame (frame_pointer);

  /* Select next frame in sequence */
  imp_anim_next_frame ();
}

void
init_avr (void)
{
  /* Disable interrupt durin init, will be enabled by decode_frame()
   * after the first frame is decoded */
  cli ();

  /* Set direction of ports */
  DDRC = 0xff;
  DDRB = 0xff;

  /* Enables timer0 overflow interrupt enable. */
  TIMSK0 |= (1 << TOIE0);
  //SET_PWM_RATE;

  /* Enables timer1 overflow interrupt enable. */
  TIMSK1 |= (1 << TOIE1);
  SET_FRAMERATE;

  TIMSK2 |= (1 << TOIE2);

  /* Clears pending interrupts */
  TIFR0 = (1 << TOV0);
  TIFR1 = (1 << TOV1);
  TIFR2 = (1 << TOV2);

  /* Sets timer0 CK-scaling to 1/8.  */
  TCCR0B |= (1 << CS01);

  /* Sets timer1 CK-scaling to 1/8.  */
  TCCR1B |= (1 << CS11);

  /* Set timer2 CK-scaling to 1/8. */
  TCCR2B |= (1 << CS21);

}
