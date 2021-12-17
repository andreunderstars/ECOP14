#include "config.h"
#include "bits.h"
#include "lcd.h"
#include "keypad.h"
#include "ssd.h"
#include "led.h"
#include "rgb.h"
#include <proc/pic18f4520.h>


void main(void){
    unsigned long int cont = 0, cont2 = 0, n=0, i=0, nled=0;
    unsigned int tecla = 16;
    unsigned char parado = 1, op = 0;
    kpInit();
    lcdInit();
    ssdInit();
    rgbInit();
    for(;;){
        ssdUpdate();
        switch(op){
            case 0:
                for(i=0;i<100;i++){
                    if(parado==0){
                        cont++;
                    }
                }
                lcdPosition(0, 0);
                lcdChar((((cont / 360000) % 24) / 10) + 48);
                lcdChar((((cont / 360000) % 24) % 10) + 48);
                lcdChar(':');
                lcdChar((cont / 60000) % 6 + 48);
                lcdChar((cont / 6000) % 10 + 48);
                lcdChar(':');
                lcdChar((cont / 1000) % 6 + 48);
                lcdChar((cont / 100) % 10 + 48);
                if(cont2!=0){
                    lcdPosition(1, 0);
                    lcdChar((((cont2 / 360000) % 24) / 10) + 48);
                    lcdChar((((cont2 / 360000) % 24) % 10) + 48);
                    lcdChar(':');
                    lcdChar((cont2 / 60000) % 6 + 48);
                    lcdChar((cont2 / 6000) % 10 + 48);
                    lcdChar(':');
                    lcdChar((cont2 / 1000) % 6 + 48);
                    lcdChar((cont2 / 100) % 10 + 48);
                }
            case 1:
                kpDebounce();
                op = 2;
                break;
            case 2:
                if (kpRead()!=tecla){
                    tecla = kpRead();
                    if(bitTst(tecla,0)){//pausa
                        if(parado == 0){
                            parado = 1;
                        }else{
                            parado = 0;
                        }
                    }
                    if(bitTst(tecla,1)){//reset
                        cont = 0;
                        parado = 1;
                    }
                    if(bitTst(tecla,2)){//grava tempo
                        if(cont!=0){
                            cont2 = cont;
                            n++;
                            switch(nled){
                                case 1: rgbColor(RED);
                                nled++;
                                break;
                                case 2: rgbColor(GREEN);
                                nled++;
                                break;                                    
                                case 3: rgbColor(BLUE);
                                nled++;
                                break;
                                case 4: rgbColor(YELLOW);
                                nled++;
                                break;                                    
                                case 5: rgbColor(CYAN);
                                nled++;
                                break;                                    
                                case 6: rgbColor(PURPLE);
                                nled=0;
                                break;                                    
                                default: rgbColor(WHITE);
                                nled=0;
                                break;
                            }
                        }
                    }
                    if(bitTst(tecla,3)){//limpa cont2;
                        cont2 = 0;
                        lcdPosition(1, 0);
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                        lcdChar(' ');
                    }
                }
                op = 3;
                break;
            case 3:
                ssdDigit(((n / 1000) %10), 0);
                ssdDigit(((n / 100) % 10), 1); 
                ssdDigit(((n / 10) % 10), 2); 
                ssdDigit((n % 10), 3);
                op = 0;
                break;
            default:
                op = 0;
                break;
        }
        //ssdUpdate();
    }
}