/* 
 * This file is part of the avr8-blink .
 * Copyright (c) 2016 Sputkin .
 * 
 * avr8-blink is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * avr8-blink is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <util/delay.h>


int main(){

  DDRB = (1<<PB5);             // pin 9 as output on mega32u4-arduino-pro-micro
  PORTB = 1>>8;
    
  for(;;){
    PORTB = PORTB ^ (1<<PB5);  // 1 xor 1 = 0 and 0 xor 1 = 1 ..
    _delay_ms(400);            // 400ms delay
  }
}
