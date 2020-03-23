/*
 * File:   neopixel_ws2812.c
 * Author: CVR ELECTRONICA
 *
 * Created on 22 de marzo de 2020, 10:23 AM
 * 
 * Ejemplo para la librería Neopixel ws2812 de CVR ELECTRONICA 
 * EN ESTE EJEMPLO SE USA EL PIC18F4550 PERO PUEDE DER USADA EN CUALQUIER OTRO MICROCONTROLADOR
 * QUE FUNCIONE CON EL COMPILADOR XC8
 * 
 * CONTACTO:
 * WEB: www.cvrelectronica.com
 * Email: develop@cvrelectronica.com
 * WhatsApp: +57 301 546 8124
 * 
 * Esta librería puede ser usada libremente por cualquier persona!
 */

// CONFIG1L
#pragma config PLLDIV = 5       // PLL Prescaler Selection bits (Divide by 5 (20 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HSPLL_HS  // Oscillator Selection bits (HS oscillator, PLL enabled (HSPLL))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include <pic18f4550.h>

#define _XTAL_FREQ 48000000

#include <xc.h>
#include "CVR_neopixel_ws2812.h"

char rv = 0; char gv =255; char bv =0;

void main(void) {
    while(1){
        // SECUENCIA 1
        neopixel_init();
        neopixel_offLeds(8,1);
        neopixel_turnFromTo(5,8,255,0,0);
        __delay_ms(250);
        neopixel_offLeds(8,1);
        neopixel_turnFromTo(1,4,255,0,0);
        __delay_ms(250);
        neopixel_offLeds(8,1);
        
        // SECUENCIA 2 -> SUBE
        for(char c =0; c<8;c++){
            neopixel_turnOneLed(c+1,rv,gv,bv);
            __delay_ms(100);
        }
        // SECUENCIA 2 -> BAJA
        for(char c =7; c>1;c--){
            neopixel_offLeds(8,1);
            neopixel_offLeds(c-1,0);
            neopixel_setColor(rv,gv,bv,1,neopixel_show_changes);
            __delay_ms(100);
        }
        //SECUENCIA 3 -> SUBEN TODOS LOS LEDS
        for(char c = 1; c<9; c++){
            neopixel_turnFromTo(1,c,255,0,0);
            __delay_ms(100);
            neopixel_offLeds(8,1);
        }
        // SECUENCIA 3 -> BAJAN TODOS LOS LEDS
        for(char c = 1; c<9; c++){
            neopixel_turnFromTo(9-c,8,255,0,0);
            __delay_ms(100);
            neopixel_offLeds(8,1);
        }
        //SECUENCIA 4 LEDS DEL 1 AL 3 ROJOS, LEDS 4 Y 5 VIOLETA LED 6 AL 8 ROJOS 
        for(char z=0; z<4;z++){
        neopixel_setColor(255,0,0,3,neopixel_noshow_changes);
        neopixel_setColor(133,44,121,2,neopixel_noshow_changes);
        neopixel_setColor(255,0,0,3,neopixel_show_changes);
        __delay_ms(200);
        //SECUENCIA 4 LEDS DEL 1 AL 3 ROJOS, LEDS 4 Y 5 APAGADOS LED 6 AL 8 ROJOS 
        neopixel_setColor(255,0,0,3,neopixel_noshow_changes);
        neopixel_setColor(0,0,0,2,neopixel_noshow_changes);
        neopixel_setColor(255,0,0,3,neopixel_show_changes);
        __delay_ms(200);
        }
        //CAMBIO DE COLORES ( SOLO PARA NO VER LOS MISMOS SIEMPRE)
        if(rv > 0){
            rv = 0; 
            gv = 255; 
            bv =0;
        }else if(gv > 0){
            rv =0; 
            gv =0; 
            bv = 255;
        }else if(bv > 0){
            rv = 255; 
            gv =0; 
            bv =0;
        }
    }
    return;
}
