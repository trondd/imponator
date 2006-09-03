/** $Id: imp2005.h 17 2005-10-09 11:22:59Z trondd $
 *
 * Copyright Omega Verksted.
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

#ifndef IMP2005_H
#define IMP2005_H

#include <avr/io.h>
#include <inttypes.h>
#include <avr/signal.h>
#include <avr/interrupt.h>

#include "imp_decoder.h"


#define GROUND PORTC
#define LEDS PORTB
#define LEFT 1
#define RIGHT 0

/**
 * Timer adjustment.
 * */
#define SET_FRAMERATE TCNT1=0x7000
#define SET_PWM_RATE TCNT0=0x7f



/* Indicates which side of the diode matrix is active */
volatile uint8_t select_ground;

/* Alloc. mem for double buffering of softpwm pattern */
volatile uint16_t frame_buffer[16];

/* Pointer to current int. in the softpwm pattern */
volatile uint16_t *frame_pointer;

/* Position in frame_buffer */
volatile uint8_t fb_index;


/* ----------
 * Prototypes 
 * ----------
 */

/** init_avr()
 *
 * Loads settings into different registers on the avr
 */
void init_avr (void);


/** delay_sycles()
 *
 * Wrapper for asm nop instruction
 */
void delay_cycles (uint16_t cycles);

#endif
