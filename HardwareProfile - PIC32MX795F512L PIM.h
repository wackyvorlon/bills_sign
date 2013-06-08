
#ifndef HARDWARE_PROFILE_PIC32MX795F512L_PIM_H
#define HARDWARE_PROFILE_PIC32MX795F512L_PIM_H


    //#define USE_SELF_POWER_SENSE_IO
    //#define tris_self_power     TRISAbits.TRISA4    // Input
    #define self_power          1

    //#define USE_USB_BUS_SENSE_IO
    //#define tris_usb_bus_sense  TRISBbits.TRISB5    // Input
    #define USB_BUS_SENSE       0

    #define mInitPorts()        TRISD = 0x00; TRISE = 0x00; TRISA = 0x00;

    #define mLED_1              LATDbits.LATD4
    #define mLED_2              LATDbits.LATD5
    #define mLED_3              LATDbits.LATD6
    #define mLED_4              LATDbits.LATD7
    
    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4

    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitSwitch2()      TRISAbits.TRISA2=1;
    #define mInitSwitch3()      TRISAbits.TRISA3=1;
    #define mInitAllSwitches()  mInitSwitch2();mInitSwitch3();
    #define sw2                 PORTAbits.RA2
    #define sw3                 PORTAbits.RA3

    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0
#endif  //HARDWARE_PROFILE_PIC32MX795F512L_PIM_H
