#include "config.h"
#include <proc/pic18f4520.h>
#include "delay.h"
#define LED 0xF83

void configuraLed(){
    (*(volatile __near unsigned char*) 0xF95) = 0x00;
}

void ligarLed(char num){
    switch(num){
        case 0: PORTD = 0b00000000; break;
        case 1: PORTD = 0b00000001; break;
        case 2: PORTD = 0b00000011; break;
        case 3: PORTD = 0b00000111; break;
        case 4: PORTD = 0b00001111; break;
        case 5: PORTD = 0b00011111; break;
        case 6: PORTD = 0b00111111; break;
        case 7: PORTD = 0b01111111; break;
        case 8: PORTD = 0b11111111; break;
    }
}

void desligarLed(char num){
    switch(num){
        case 0: PORTD = 0b00000000; break;
        case 1: PORTD = 0b00000001; break;
        case 2: PORTD = 0b00000011; break;
        case 3: PORTD = 0b00000111; break;
        case 4: PORTD = 0b00001111; break;
        case 5: PORTD = 0b00011111; break;
        case 6: PORTD = 0b00111111; break;
        case 7: PORTD = 0b01111111; break;
        case 8: PORTD = 0b11111111; break;
    }
}
