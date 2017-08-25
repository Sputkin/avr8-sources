/* 
 * This file is part of the avr8-usart .
 * Copyright (c) 2016 Sputkin .
 * 
 * avr8-usart is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * avr8-usart is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#include <util/delay.h>
#include <avr/io.h>

#define FOSC 16000000UL                                  //16Mhz
#define BAUD_RATE 9600                                   // 9600 baud
#define UCBR_BAUD ( ( FOSC / (16UL * BAUD_RATE) )  -1 )  // 103



void _USART_init();                           //Initializes the serial
void _USART_send_byte(unsigned char value);   //Sends 1 byte
void _USART_println(char *str);               //Sends a string

void _USART_init(){

    //set baudrate
    UBRR1H = (unsigned int) (UCBR_BAUD >>8);   //high  register
    UBRR1L = (unsigned int) UCBR_BAUD;         //lower register

    //set RXEN and TXEN for enable usart
    UCSR1B = (3<<3);

    //set 8bit character size and 1 bits of stop
    UCSR1C =  (1<<1) | (1<<2);

}

int main(){
  _USART_init();

  while(1){
    _USART_println("hello world!");
    _delay_ms(500);
  }
}


void _USART_println(char *str){
   while(*str){
     _USART_send_byte(*str);
     str++;
   }
   _USART_send_byte('\r');
   _USART_send_byte('\n');
}


void _USART_send_byte(unsigned char value){

    //wait transmit buffer when it is ready
    while(!(UCSR1A & (1<<UDRE1))){ 
    }

    //send data
    UDR1 = value;
}
