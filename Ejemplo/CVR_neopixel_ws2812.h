#ifndef __CVR_neopixel_ws2812_H
#define __CVR_neopixel_ws2812_H

#define neopixel_dataPin PORTBbits.RB0
#define neopixel_dataPin_config TRISBbits.RB0

#define neopixel_lenght 8
#define neopixel_show_changes 1
#define neopixel_noshow_changes 0

void neopixel_init();
void neopixel_setColor(char r, char g, char b, char numberOfLeds,char showChanges); 
void neopixel_reset();
void neopixel_turnOneLed(char index,char r, char g, char b);
void neopixel_turnFromTo(char indexF,char indexT,char r, char g, char b);
void neopixel_offLeds(char index, char reset);


void neopixel_init(){
    neopixel_dataPin_config = 0;
    neopixel_dataPin = 0;
    __delay_us(50);
}

void neopixel_turnOneLed(char index,char r, char g, char b){
    neopixel_offLeds(neopixel_lenght,neopixel_show_changes);
    neopixel_offLeds(index-1,neopixel_noshow_changes);
    neopixel_setColor(r,g,b,1,neopixel_show_changes);
}
void neopixel_turnFromTo(char indexF,char indexT,char r, char g, char b){
    neopixel_offLeds(indexF - 1, neopixel_noshow_changes);
    neopixel_setColor(r,g,b,indexT,neopixel_show_changes);
}
void neopixel_offLeds(char index,char reset){
    neopixel_setColor(0,0,0,index,reset);
}
void neopixel_setColor(char r, char g, char b,char numberOfLeds, char showChanges){
    for(char i =0; i < numberOfLeds; i++){
        char val = g;
        for(char x =0; x<8; x++){
            if((val & 0x80) == 0){
                neopixel_dataPin = 1;
                __delay_us(0.35);
                neopixel_dataPin = 0;
                __delay_us(0.8);
            }else{
                neopixel_dataPin = 1;
                __delay_us(0.7);
                neopixel_dataPin = 0;
                __delay_us(0.6);
            }
            val = val << 1;
        }
        val = r;
        for(char x =0; x<8; x++){
            if((val & 0x80) == 0){
                neopixel_dataPin = 1;
                __delay_us(0.35);
                neopixel_dataPin = 0;
                __delay_us(0.8);
            }else{
                neopixel_dataPin = 1;
                __delay_us(0.7);
                neopixel_dataPin = 0;
                __delay_us(0.6);
            }
            val = val << 1;
        }
        val = b;
        for(char x =0; x<8; x++){
            if((val & 0x80) == 0){
                neopixel_dataPin = 1;
                __delay_us(0.35);
                neopixel_dataPin = 0;
                __delay_us(0.8);
            }else{
                neopixel_dataPin = 1;
                __delay_us(0.7);
                neopixel_dataPin = 0;
                __delay_us(0.6);
            }
            val = val << 1;
        }
    }
    if(showChanges == neopixel_show_changes){
        neopixel_reset();
    }
}

void neopixel_reset(){
    neopixel_dataPin = 0;
    __delay_ms(1);
}

#endif