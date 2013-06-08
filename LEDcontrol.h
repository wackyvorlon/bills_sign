/* 
 * File:   LEDcontrol.h
 * Author: I7
 * Project: USB LED Matrix 22x44
 * Created on March 9, 2013, 8:03 PM
 */
#ifndef LEDCONTROL_H
#define	LEDCONTROL_H


#define BIT_DEPTH 16         // brightness level
#define LED_WID 44
#define LED_HGT 22
// commands
#define SET_HGT 0x10         // (0x10, hex y column) header, followed by 16 bytes for column
#define SET_WID 0x20         // (0x20, hex x row) header, follwed by 28 bytes for row
#define SET_FRAME 0x08       // (0x08) header, followed by 448 bits for whole frame (top row 28 bytes, 2nd row 28 bytes, ... )
#define SHIFT_ROW_LEFT 0x80  // (0x80, hex y column) which row to shift left
#define SHIFT_ROW_RIGHT 0x40 // (0x40, hex y column) which row to shift right

void ploty(unsigned y);
void plotx(unsigned x);
void fillFrame();
void clear();
void refreshScreen();
void shiftRowLeft(unsigned char hight);
void shiftRowRight(unsigned char hight);
void getFrame();


#endif	/* LEDCONTROL_H */

