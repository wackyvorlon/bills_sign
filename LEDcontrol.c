#include <xc.h>
#include "LEDcontrol.h"
#include <string.h>
#include <math.h>
//@TODO  static pointer array to framedata for faster access ?
static unsigned char framedata[LED_WID][LED_HGT];

void ploty(unsigned y)
{
    //LATC = y & 0x3F;
    //LATA = (y & 0xC0) >> 6;
    //LATD = y >> 8;
}
void refreshScreen(){
    unsigned char *pFrame;
    /*for ( unsigned z = 0; z < BIT_DEPTH; ++z ){
        pFrame = &framedata[0];
        for (unsigned x=0; x < LED_WID; x++){
            unsigned ybits = 0;
            for ( unsigned char y = 0; y < LED_HGT; y ++)
                
            {
                ybits >>= 1;
                if (*pFrame > z)
                    ybits |= 0x8000;
                pFrame++;
            }

            //LATC = 0 & 0x3F;
            //LATA = (0 & 0xC0) >> 6;
            //LATD = 0;
            //LATEbits.LE0 = (x < 24);
            LATB = x;

            LATC = ybits & 0x3F;
            LATA = (ybits & 0xC0) >> 6;
            LATD = ybits >> 8;
        //}
    }*/
}


void shiftRowLeft(unsigned char hight){
    unsigned char temp;
    unsigned char x;
    temp = framedata[0][hight];
    for (x = 0; x< LED_WID -1; ++x){
        framedata[x][hight] = framedata[x+1][hight];
    }
    framedata[LED_WID-1][hight] = temp;

}
void shiftRowRight(unsigned char hight){
    unsigned char temp;
    unsigned char x;
    temp = framedata[LED_WID-1][hight];
    for ( x= LED_WID; x> 0 ; --x){
        framedata[x][hight] = framedata[x-1][hight];
    }
    framedata[0][hight] = temp;
}
void getFrame(){
    ploty(0x0000);
      //unsigned * frameptr;
    //frameptr = &framedata;
    //for (unsigned i = 0; i < 112; ++i){
    //    getsUSART(frameptr,4);
    //    ++frameptr;
        
    //}
    //getsUSART(&framedata[0][0],112);
   // getsUSART(&framedata[7][0],112);
    //getsUSART(&framedata[14][0],112);
   //getsUSART(&framedata[21][0],112);
}

void clear(){
    ploty(0x0000);
}
