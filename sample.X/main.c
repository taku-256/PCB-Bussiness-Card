/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26Q84
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
        
struct bits {
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    unsigned char b8 : 1;
};
        
typedef union{
    uint8_t chr;
    struct bits b;
}iro;
        
iro r,g,b;
        
int RGB[3][160],MODE,MOVE;
        
int nanntoka;
        
int port1_zero(){
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
}
        
int port1_one(){//400ns
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 1;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC6 = 0;
}
        
int port2_zero(){
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
}
        
int port2_one(){//400ns
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 1;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
    LATCbits.LATC5 = 0;
}
        
int (*port1_send1bit[2])() = {port1_zero,port1_one};
        
int (*port2_send1bit[2])() = {port2_zero,port2_one};
        
int port1_send3byte(int R,int G,int B){
    g.chr = G;r.chr = R;b.chr = B;
    
    port1_send1bit[g.b.b1]();
    port1_send1bit[g.b.b2]();
    port1_send1bit[g.b.b3]();
    port1_send1bit[g.b.b4]();
    port1_send1bit[g.b.b5]();
    port1_send1bit[g.b.b6]();
    port1_send1bit[g.b.b7]();
    port1_send1bit[g.b.b8]();
    port1_send1bit[r.b.b1]();
    port1_send1bit[r.b.b2]();
    port1_send1bit[r.b.b3]();
    port1_send1bit[r.b.b4]();
    port1_send1bit[r.b.b5]();
    port1_send1bit[r.b.b6]();
    port1_send1bit[r.b.b7]();
    port1_send1bit[r.b.b8]();
    port1_send1bit[b.b.b1]();
    port1_send1bit[b.b.b2]();
    port1_send1bit[b.b.b3]();
    port1_send1bit[b.b.b4]();
    port1_send1bit[b.b.b5]();
    port1_send1bit[b.b.b6]();
    port1_send1bit[b.b.b7]();
    port1_send1bit[b.b.b8]();
}
        
int port2_send3byte(int R,int G,int B){
    g.chr = G;r.chr = R;b.chr = B;
    
    port2_send1bit[g.b.b1]();
    port2_send1bit[g.b.b2]();
    port2_send1bit[g.b.b3]();
    port2_send1bit[g.b.b4]();
    port2_send1bit[g.b.b5]();
    port2_send1bit[g.b.b6]();
    port2_send1bit[g.b.b7]();
    port2_send1bit[g.b.b8]();
    port2_send1bit[r.b.b1]();
    port2_send1bit[r.b.b2]();
    port2_send1bit[r.b.b3]();
    port2_send1bit[r.b.b4]();
    port2_send1bit[r.b.b5]();
    port2_send1bit[r.b.b6]();
    port2_send1bit[r.b.b7]();
    port2_send1bit[r.b.b8]();
    port2_send1bit[b.b.b1]();
    port2_send1bit[b.b.b2]();
    port2_send1bit[b.b.b3]();
    port2_send1bit[b.b.b4]();
    port2_send1bit[b.b.b5]();
    port2_send1bit[b.b.b6]();
    port2_send1bit[b.b.b7]();
    port2_send1bit[b.b.b8]();
}
        
int Red(){
    while(1){
        if(MODEIN_PORT != nanntoka){break;}
        
        for(int i = 0;i < 10;i++){
            port1_send3byte(255,0,0);
            port1_send3byte(255,0,0);
            port1_send3byte(255,0,0);
            port1_send3byte(255,255,0);
            port1_send3byte(255,255,0);
            port1_send3byte(255,255,0);
        }
        
        for(int i = 0;i < 10;i++){
            port2_send3byte(255,255,0);
            port2_send3byte(255,255,0);
            port2_send3byte(255,255,0);
            port2_send3byte(255,0,0);
            port2_send3byte(255,0,0);
            port2_send3byte(255,0,0);
        }
        
        __delay_ms(150);
        
        if(MODEIN_PORT != nanntoka){break;}
        
        for(int i = 0;i < 10;i++){
            port1_send3byte(255,255,0);
            port1_send3byte(255,255,0);
            port1_send3byte(255,255,0);
            port1_send3byte(255,0,0);
            port1_send3byte(255,0,0);
            port1_send3byte(255,0,0);
        }
        
        for(int i = 0;i < 10;i++){
            port2_send3byte(255,0,0);
            port2_send3byte(255,0,0);
            port2_send3byte(255,0,0);
            port2_send3byte(255,255,0);
            port2_send3byte(255,255,0);
            port2_send3byte(255,255,0);
        }
        
        __delay_ms(150);
        
    }
}
        
int Blue(){
    while(1){
        if(MODEIN_PORT != nanntoka){break;}
        
        for(int i = 0;i < 35;i++){
            port1_send3byte(0,0,255);
            port1_send3byte(0,0,255);
            port1_send3byte(0,0,255);
            port1_send3byte(186,255,255);
            port1_send3byte(186,255,255);
            port1_send3byte(186,255,255);
        }
        
        for(int i = 0;i < 10;i++){
            port2_send3byte(186,255,255);
            port2_send3byte(186,255,255);
            port2_send3byte(186,255,255);
            port2_send3byte(0,0,255);
            port2_send3byte(0,0,255);
            port2_send3byte(0,0,255);
        }
        
        __delay_ms(150);
        
        if(MODEIN_PORT != nanntoka){break;}
        
        for(int i = 0;i < 10;i++){
            port1_send3byte(186,255,255);
            port1_send3byte(186,255,255);
            port1_send3byte(186,255,255);
            port1_send3byte(0,0,255);     
            port1_send3byte(0,0,255);
            port1_send3byte(0,0,255);     
        }
        
        for(int i = 0;i < 10;i++){
            port2_send3byte(0,0,255);
            port2_send3byte(0,0,255);
            port2_send3byte(0,0,255);
            port2_send3byte(186,255,255);
            port2_send3byte(186,255,255);
            port2_send3byte(186,255,255);
        }
        
        __delay_ms(150);
        
    }
}

void Gaming(){
    for(int i = 0;i < 10;i++){
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(0,0,255);
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(0,0,255);
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
    }
    
    __delay_ms(50);
    
    for(int i = 0;i < 10;i++){
        port1_send3byte(255,0,255);
        port1_send3byte(255,0,0);
        port1_send3byte(255,165,0);
        port1_send3byte(255,255,0);
        port1_send3byte(0,255,0);
        port1_send3byte(0,255,255);
        port1_send3byte(0,0,255);
    }
    
    for(int i = 0;i < 10;i++){
        port2_send3byte(255,0,255);
        port2_send3byte(255,0,0);
        port2_send3byte(255,165,0);
        port2_send3byte(255,255,0);
        port2_send3byte(0,255,0);
        port2_send3byte(0,255,255);
        port2_send3byte(0,0,255);
    }
    
    __delay_ms(50);
}

void main(void){
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
//    INTERRUPT_GlobalInterruptEnable();
    
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC5 = 0;
    TRISAbits.TRISA0 = 1;
    
    nanntoka = PORTAbits.RA0;
 
    while (1){
        
        // Add your application code
        
        while(nanntoka == PORTAbits.RA0){Gaming();}
        nanntoka = PORTAbits.RA0;
        
        while(nanntoka == PORTAbits.RA0){Red();}
        nanntoka = PORTAbits.RA0;
        
        while(nanntoka == PORTAbits.RA0){Blue();}
        nanntoka = PORTAbits.RA0;

    }
}
/**
 End of File
*/