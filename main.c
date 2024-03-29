#include "USB/usb.h"
#include "USB/usb_function_generic.h"
#include "HardwareProfile.h"
#include "LEDcontrol.h"
#include <stdbool.h>


USB_VOLATILE BYTE EP1OUTEvenBuffer[64]; //User buffer for receiving OUT packets sent from the host
USB_VOLATILE BYTE EP1OUTOddBuffer[64]; //User buffer for receiving OUT packets sent from the host
USB_VOLATILE BYTE EP2OUTEvenBuffer[64]; //User buffer for receiving OUT packets sent from the host
USB_VOLATILE BYTE EP2OUTOddBuffer[64]; //User buffer for receiving OUT packets sent from the host
USB_VOLATILE BYTE EP3OUTEvenBuffer[64]; //User buffer for receiving OUT packets sent from the host
USB_VOLATILE BYTE EP3OUTOddBuffer[64]; //User buffer for receiving OUT packets sent from the host

USB_HANDLE EP1OUTEvenHandle;
USB_HANDLE EP2OUTEvenHandle;
USB_HANDLE EP3OUTEvenHandle;
USB_HANDLE EP4OUTEvenHandle;
USB_HANDLE EP1OUTOddHandle;
USB_HANDLE EP2OUTOddHandle;
USB_HANDLE EP3OUTOddHandle;

BOOL EP1OUTEvenNeedsServicingNext; //TRUE means even need servicing next, FALSE means odd needs servicing next
BOOL EP2OUTEvenNeedsServicingNext; //TRUE means even need servicing next, FALSE means odd needs servicing next
BOOL EP3OUTEvenNeedsServicingNext; //TRUE means even need servicing next, FALSE means odd needs servicing next
WORD led_count; //Counter for blinking the LEDs on the demo board

/** PRIVATE PROTOTYPES *********************************************/
USB_VOLATILE BYTE framedata[30][15][64];
static void InitializeSystem(void);
void USBDeviceTasks(void);
void YourHighPriorityISRCode(void);
void YourLowPriorityISRCode(void);
void USBCBSendResume(void);
void UserInit(void);
void ProcessIO(void);
void BlinkUSBStatus(void);
static volatile unsigned char i;
static volatile unsigned char frame;
//static volatile bool *xAxis[] = {           PORTDbits.RD0, PORTDbits.RD1, PORTDbits.RD2, PORTDbits.RD3,
//                                            PORTDbits.RD4, PORTDbits.RD5, PORTDbits.RD6, PORTDbits.RD7,
//                                            PORTDbits.RD8, PORTDbits.RD9, PORTDbits.RD10,PORTDbits.RD11,
//                                            PORTDbits.RD12,PORTDbits.RD13,PORTDbits.RD14,PORTDbits.RD15,
//                                            PORTEbits.RE0, PORTEbits.RE1, PORTEbits.RE2, PORTEbits.RE3,
//                                            PORTEbits.RE4, PORTEbits.RE5, PORTEbits.RE6, PORTEbits.RE7,
//                                            PORTEbits.RE8, PORTEbits.RE9, PORTAbits.RA0, PORTAbits.RA1,
//                                            PORTAbits.RA2, PORTAbits.RA3, PORTAbits.RA4, PORTAbits.RA5,
//                                            PORTAbits.RA6, PORTAbits.RA7, PORTAbits.RA9, PORTAbits.RA10,
//                                            PORTBbits.RB0, PORTBbits.RB1, PORTBbits.RB2, PORTBbits.RB3,
//                                            PORTBbits.RB4, PORTBbits.RB8, PORTBbits.RB9, PORTBbits.RB10,
//                                            PORTFbits.RF0, PORTFbits.RF1};

int main(void)
 {
    DDPCONbits.JTAGEN = 0;
    SYSTEMConfigPerformance(80000000L);
    SYSTEMConfig(80000000L, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    InitializeSystem();

    USBDeviceAttach();
    unsigned int count = 0;
    signed int dir = 1;
    //LATF=0xFFFF;
    //LATE=0x03FF;
    //LATA=0x06FF;
    //LATB=0x0E1F;
    LATF = 0x0000;
    LATE = 0x0000;
    LATA = 0x0000;
    LATB = 0x0000;
    LATD = 0x0000;
    while (!((USBDeviceState < CONFIGURED_STATE) || (USBSuspendControl == 1)));
    while (1) {
        DelayMs(1000);
        //refreshScreen();
        count+= dir;
        if (count == 22) dir = -1;//count = 0;
        if (count == 0) dir = 1;//count = 0;
        ProcessIO();

        //count = 0x5555;
        //&xAxis[count] = !(&xAxis[count]);
        //if (dir == 1){
        LATB = (count<<11);//+0x0E1F;
        //dir = 0;
        //}else{
        //LATB = (count<<12);//+0x0E1F;
        //dir = 1;
        //}
        

    }
}


static void InitializeSystem(void) {

    AD1PCFG = 0xFFFF;
    
    EP1OUTEvenHandle = 0;
    EP2OUTEvenHandle = 0;
    EP3OUTEvenHandle = 0;
    EP1OUTOddHandle = 0;
    EP2OUTOddHandle = 0;
    EP3OUTOddHandle = 0;
    i=0;
    frame = 0;
    UserInit(); //Application related initialization.  See user.c
    USBDeviceInit(); //usb_device.c.  Initializes USB module SFRs and firmware
 
}

void UserInit(void) {
    led_count = 0;
    TRISD = 0x00;
    TRISE = 0x00;
    TRISA = 0x00;
    PORTSetPinsDigitalOut(IOPORT_F, BIT_0 | BIT_1);
    PORTSetPinsDigitalOut(IOPORT_B, BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4 | BIT_8 | BIT_9 | BIT_10 | BIT_11 | BIT_12 | BIT_13 | BIT_14 | BIT_15);
}

void ProcessIO(void) {
    /*if(i>14)
    {
        i= 0;
        if (frame<30) ++frame;
        else frame = 0;
    }*/
    if (EP2OUTEvenNeedsServicingNext == TRUE) {
        if (!USBHandleBusy(EP2OUTEvenHandle)) //Check if the endpoint has received any data from the host.
        {
            //Re-arm the OUT endpoint for the next packet:
            //EP2OUTEvenHandle = USBTransferOnePacket(2, OUT_FROM_HOST, (BYTE*) & EP2OUTEvenBuffer, 64);
            EP2OUTEvenHandle = USBTransferOnePacket(2, OUT_FROM_HOST, (BYTE*) & EP2OUTEvenBuffer[64], 64);
            EP2OUTEvenNeedsServicingNext = FALSE;
            frame = 0;
            i = 0;
        }
    } else //else EP2OUTOdd needs servicing next
    {
        if (!USBHandleBusy(EP2OUTOddHandle)) //Check if the endpoint has received any data from the host.
        {
            //Re-arm the OUT endpoint for the next packet:
            EP2OUTOddHandle = USBTransferOnePacket(2, OUT_FROM_HOST, (BYTE*) & EP2OUTOddBuffer[64], 64);
            EP2OUTEvenNeedsServicingNext = TRUE;
            frame = 0;
            i = 0;
        }
    }
      if (EP1OUTEvenNeedsServicingNext == TRUE) //Check which buffer (even/odd) the next set of data is going to arrive in
    {
        if (!USBHandleBusy(EP1OUTEvenHandle)) //Check if the endpoint has received any data from the host.
        {
            EP1OUTEvenHandle = USBTransferOnePacket(1, OUT_FROM_HOST, (BYTE*) & framedata[frame][i], 64);
            EP1OUTEvenNeedsServicingNext = FALSE;
            i+=1;
        }
    } else //else EP1OUTOdd needs servicing next
    {
        if (!USBHandleBusy(EP1OUTOddHandle)) //Check if the endpoint has received any data from the host.
        {

            //EP1OUTOddHandle = USBTransferOnePacket(1, OUT_FROM_HOST, (BYTE*) & EP1OUTOddBuffer, 64);
            EP1OUTOddHandle = USBTransferOnePacket(1, OUT_FROM_HOST, (BYTE*) & framedata[frame][i], 64);
            EP1OUTEvenNeedsServicingNext = TRUE;
            i+=1;
        }
    }

    /*
    if (EP3OUTEvenNeedsServicingNext == TRUE) {
        if (!USBHandleBusy(EP3OUTEvenHandle)) //Check if the endpoint has received any data from the host.
        {
            //Re-arm the OUT endpoint for the next packet:
            EP3OUTEvenHandle = USBTransferOnePacket(3, OUT_FROM_HOST, (BYTE*) & framedata[4], 44);
            EP3OUTEvenNeedsServicingNext = FALSE;
        }
    } else //else EP3OUTOdd needs servicing next
    {
        if (!USBHandleBusy(EP3OUTOddHandle)) //Check if the endpoint has received any data from the host.
        {
            //Re-arm the OUT endpoint for the next packet:
            EP3OUTOddHandle = USBTransferOnePacket(3, OUT_FROM_HOST, (BYTE*) & framedata[5], 44);
            EP3OUTEvenNeedsServicingNext = TRUE;
        }
    }*/
}

/********************************************************************
 * Function:        void BlinkUSBStatus(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        BlinkUSBStatus turns on and off LEDs 
 *                  corresponding to the USB device state.
 *
 * Note:            mLED macros can be found in HardwareProfile.h
 *                  USBDeviceState is declared and updated in
 *                  usb_device.c.
 *******************************************************************/





// ******************************************************************************************************
// ************** USB Callback Functions ****************************************************************
// ******************************************************************************************************
// The USB firmware stack will call the callback functions USBCBxxx() in response to certain USB related
// events.  For example, if the host PC is powering down, it will stop sending out Start of Frame (SOF)
// packets to your device.  In response to this, all USB devices are supposed to decrease their power
// consumption from the USB Vbus to <2.5mA each.  The USB module detects this condition (which according
// to the USB specifications is 3+ms of no bus activity/SOF packets) and then calls the USBCBSuspend()
// function.  You should modify these callback functions to take appropriate actions for each of these
// conditions.  For example, in the USBCBSuspend(), you may wish to add code that will decrease power
// consumption from Vbus to <2.5mA (such as by clock switching, turning off LEDs, putting the
// microcontroller to sleep, etc.).  Then, in the USBCBWakeFromSuspend() function, you may then wish to
// add code that undoes the power saving things done in the USBCBSuspend() function.

// The USBCBSendResume() function is special, in that the USB stack will not automatically call this
// function.  This function is meant to be called from the application firmware instead.  See the
// additional comments near the function.

// Note *: The "usb_20.pdf" specs indicate 500uA or 2.5mA, depending upon device classification. However,
// the USB-IF has officially issued an ECN (engineering change notice) changing this to 2.5mA for all 
// devices.  Make sure to re-download the latest specifications to get all of the newest ECNs.

/******************************************************************************
 * Function:        void USBCBSuspend(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Call back that is invoked when a USB suspend is detected
 *
 * Note:            None
 *****************************************************************************/
void USBCBSuspend(void) {
    //Example power saving code.  Insert appropriate code here for the desired
    //application behavior.  If the microcontroller will be put to sleep, a
    //process similar to that shown below may be used:

    //ConfigureIOPinsForLowPower();
    //SaveStateOfAllInterruptEnableBits();
    //DisableAllInterruptEnableBits();
    //EnableOnlyTheInterruptsWhichWillBeUsedToWakeTheMicro();	//should enable at least USBActivityIF as a wake source
    //Sleep();
    //RestoreStateOfAllPreviouslySavedInterruptEnableBits();	//Preferrably, this should be done in the USBCBWakeFromSuspend() function instead.
    //RestoreIOPinsToNormal();									//Preferrably, this should be done in the USBCBWakeFromSuspend() function instead.


}

/******************************************************************************
 * Function:        void USBCBWakeFromSuspend(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The host may put USB peripheral devices in low power
 *					suspend mode (by "sending" 3+ms of idle).  Once in suspend
 *					mode, the host may wake the device back up by sending non-
 *					idle state signalling.
 *					
 *					This call back is invoked when a wakeup from USB suspend 
 *					is detected.
 *
 * Note:            None
 *****************************************************************************/
void USBCBWakeFromSuspend(void) {
    // If clock switching or other power savings measures were taken when
    // executing the USBCBSuspend() function, now would be a good time to
    // switch back to normal full power run mode conditions.  The host allows
    // 10+ milliseconds of wakeup time, after which the device must be
    // fully back to normal, and capable of receiving and processing USB
    // packets.  In order to do this, the USB module must receive proper
    // clocking (IE: 48MHz clock must be available to SIE for full speed USB
    // operation).
    // Make sure the selected oscillator settings are consistent with USB
    // operation before returning from this function.

    //Switch clock back to main clock source necessary for USB operation
    //Previous clock source was something low frequency as set in the
    //USBCBSuspend() function.
	
}

/********************************************************************
 * Function:        void USBCB_SOF_Handler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USB host sends out a SOF packet to full-speed
 *                  devices every 1 ms. This interrupt may be useful
 *                  for isochronous pipes. End designers should
 *                  implement callback routine as necessary.
 *
 * Note:            None
 *******************************************************************/
void USBCB_SOF_Handler(void) {
    // No need to clear UIRbits.SOFIF to 0 here.
    // Callback caller is already doing that.
}

/*******************************************************************
 * Function:        void USBCBErrorHandler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The purpose of this callback is mainly for
 *                  debugging during development. Check UEIR to see
 *                  which error causes the interrupt.
 *
 * Note:            None
 *******************************************************************/
void USBCBErrorHandler(void) {
    // No need to clear UEIR to 0 here.
    // Callback caller is already doing that.

    // Typically, user firmware does not need to do anything special
    // if a USB error occurs.  For example, if the host sends an OUT
    // packet to your device, but the packet gets corrupted (ex:
    // because of a bad connection, or the user unplugs the
    // USB cable during the transmission) this will typically set
    // one or more USB error interrupt flags.  Nothing specific
    // needs to be done however, since the SIE will automatically
    // send a "NAK" packet to the host.  In response to this, the
    // host will normally retry to send the packet again, and no
    // data loss occurs.  The system will typically recover
    // automatically, without the need for application firmware
    // intervention.

    // Nevertheless, this callback function is provided, such as
    // for debugging purposes.
}

/*******************************************************************
 * Function:        void USBCBCheckOtherReq(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        When SETUP packets arrive from the host, some
 * 					firmware must process the request and respond
 *					appropriately to fulfill the request.  Some of
 *					the SETUP packets will be for standard
 *					USB "chapter 9" (as in, fulfilling chapter 9 of
 *					the official USB specifications) requests, while
 *					others may be specific to the USB device class
 *					that is being implemented.  For example, a HID
 *					class device needs to be able to respond to
 *					"GET REPORT" type of requests.  This
 *					is not a standard USB chapter 9 request, and 
 *					therefore not handled by usb_device.c.  Instead
 *					this request should be handled by class specific 
 *					firmware, such as that contained in usb_function_hid.c.
 *
 * Note:            None
 *****************************************************************************/
void USBCBCheckOtherReq(void) {
    //Check for class specific requests, and if necessary, handle it.
    USBCheckVendorRequest();
}//end

/*******************************************************************
 * Function:        void USBCBStdSetDscHandler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USBCBStdSetDscHandler() callback function is
 *					called when a SETUP, bRequest: SET_DESCRIPTOR request
 *					arrives.  Typically SET_DESCRIPTOR requests are
 *					not used in most applications, and it is
 *					optional to support this type of request.
 *
 * Note:            None
 *****************************************************************************/
void USBCBStdSetDscHandler(void) {
    // Must claim session ownership if supporting this request
}//end

/******************************************************************************
 * Function:        void USBCBInitEP(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is called when the device becomes
 *                  initialized, which occurs after the host sends a
 * 					SET_CONFIGURATION (wValue not = 0) request.  This 
 *					callback function should initialize the endpoints 
 *					for the device's usage according to the current 
 *					configuration.
 *
 * Note:            None
 *****************************************************************************/
void USBCBInitEP(void) {
    USBEnableEndpoint(1, USB_OUT_ENABLED | USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
    USBEnableEndpoint(2, USB_OUT_ENABLED | USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
    USBEnableEndpoint(3, USB_OUT_ENABLED | USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);

    //Prepare the OUT endpoints to receive the first packets from the host.
    EP1OUTEvenHandle = USBTransferOnePacket(1, OUT_FROM_HOST, (BYTE*) & framedata[frame][i], 64); //First 64-bytes of data sent to EP1 OUT will arrive in the even buffer.
    EP1OUTOddHandle = USBTransferOnePacket(1, OUT_FROM_HOST, (BYTE*) & framedata[frame][i+1], 64); //Second 64-bytes of data sent to EP1 OUT will arrive in the odd buffer.
    EP1OUTEvenNeedsServicingNext = TRUE; //Used to keep track of which buffer will contain the next sequential data packet.

    EP2OUTEvenHandle = USBTransferOnePacket(2, OUT_FROM_HOST, (BYTE*) & EP2OUTEvenBuffer, 64);
    EP2OUTOddHandle = USBTransferOnePacket(2, OUT_FROM_HOST, (BYTE*) & EP2OUTOddBuffer, 64);
    EP2OUTEvenNeedsServicingNext = TRUE; //Used to keep track of which buffer will contain the next sequential data packet.

    EP3OUTEvenHandle = USBTransferOnePacket(3, OUT_FROM_HOST, (BYTE*) & EP3OUTEvenBuffer, 64);
    EP3OUTOddHandle = USBTransferOnePacket(3, OUT_FROM_HOST, (BYTE*) & EP3OUTOddBuffer, 64);
    EP3OUTEvenNeedsServicingNext = TRUE; //Used to keep track of which buffer will contain the next sequential data packet.

}

/********************************************************************
 * Function:        void USBCBSendResume(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USB specifications allow some types of USB
 * 					peripheral devices to wake up a host PC (such
 *					as if it is in a low power suspend to RAM state).
 *					This can be a very useful feature in some
 *					USB applications, such as an Infrared remote
 *					control	receiver.  If a user presses the "power"
 *					button on a remote control, it is nice that the
 *					IR receiver can detect this signalling, and then
 *					send a USB "command" to the PC to wake up.
 *					
 *					The USBCBSendResume() "callback" function is used
 *					to send this special USB signalling which wakes 
 *					up the PC.  This function may be called by
 *					application firmware to wake up the PC.  This
 *					function will only be able to wake up the host if
 *                  all of the below are true:
 *					
 *					1.  The USB driver used on the host PC supports
 *						the remote wakeup capability.
 *					2.  The USB configuration descriptor indicates
 *						the device is remote wakeup capable in the
 *						bmAttributes field.
 *					3.  The USB host PC is currently sleeping,
 *						and has previously sent your device a SET 
 *						FEATURE setup packet which "armed" the
 *						remote wakeup capability.   
 *
 *                  If the host has not armed the device to perform remote wakeup,
 *                  then this function will return without actually performing a
 *                  remote wakeup sequence.  This is the required behavior, 
 *                  as a USB device that has not been armed to perform remote 
 *                  wakeup must not drive remote wakeup signalling onto the bus;
 *                  doing so will cause USB compliance testing failure.
 *                  
 *					This callback should send a RESUME signal that
 *                  has the period of 1-15ms.
 *
 * Note:            This function does nothing and returns quickly, if the USB
 *                  bus and host are not in a suspended condition, or are 
 *                  otherwise not in a remote wakeup ready state.  Therefore, it
 *                  is safe to optionally call this function regularly, ex: 
 *                  anytime application stimulus occurs, as the function will
 *                  have no effect, until the bus really is in a state ready
 *                  to accept remote wakeup. 
 *
 *                  When this function executes, it may perform clock switching,
 *                  depending upon the application specific code in 
 *                  USBCBWakeFromSuspend().  This is needed, since the USB
 *                  bus will no longer be suspended by the time this function
 *                  returns.  Therefore, the USB module will need to be ready
 *                  to receive traffic from the host.
 *
 *                  The modifiable section in this routine may be changed
 *                  to meet the application needs. Current implementation
 *                  temporary blocks other functions from executing for a
 *                  period of ~3-15 ms depending on the core frequency.
 *
 *                  According to USB 2.0 specification section 7.1.7.7,
 *                  "The remote wakeup device must hold the resume signaling
 *                  for at least 1 ms but for no more than 15 ms."
 *                  The idea here is to use a delay counter loop, using a
 *                  common value that would work over a wide range of core
 *                  frequencies.
 *                  That value selected is 1800. See table below:
 *                  ==========================================================
 *                  Core Freq(MHz)      MIP         RESUME Signal Period (ms)
 *                  ==========================================================
 *                      48              12          1.05
 *                       4              1           12.6
 *                  ==========================================================
 *                  * These timing could be incorrect when using code
 *                    optimization or extended instruction mode,
 *                    or when having other interrupts enabled.
 *                    Make sure to verify using the MPLAB SIM's Stopwatch
 *                    and verify the actual signal on an oscilloscope.
 *******************************************************************/
void USBCBSendResume(void) {
    static WORD delay_count;

    //First verify that the host has armed us to perform remote wakeup.
    //It does this by sending a SET_FEATURE request to enable remote wakeup,
    //usually just before the host goes to standby mode (note: it will only
    //send this SET_FEATURE request if the configuration descriptor declares
    //the device as remote wakeup capable, AND, if the feature is enabled
    //on the host (ex: on Windows based hosts, in the device manager 
    //properties page for the USB device, power management tab, the 
    //"Allow this device to bring the computer out of standby." checkbox 
    //should be checked).
    if (USBGetRemoteWakeupStatus() == TRUE) {
        //Verify that the USB bus is in fact suspended, before we send
        //remote wakeup signalling.
        if (USBIsBusSuspended() == TRUE) {
            USBMaskInterrupts();

            //Clock switch to settings consistent with normal USB operation.
            USBCBWakeFromSuspend();
            USBSuspendControl = 0;
            USBBusIsSuspended = FALSE; //So we don't execute this code again,
            //until a new suspend condition is detected.

            //Section 7.1.7.7 of the USB 2.0 specifications indicates a USB
            //device must continuously see 5ms+ of idle on the bus, before it sends
            //remote wakeup signalling.  One way to be certain that this parameter
            //gets met, is to add a 2ms+ blocking delay here (2ms plus at 
            //least 3ms from bus idle to USBIsBusSuspended() == TRUE, yeilds
            //5ms+ total delay since start of idle).
            delay_count = 3600U;
            do {
                delay_count--;
            } while (delay_count);

            //Now drive the resume K-state signalling onto the USB bus.
            USBResumeControl = 1; // Start RESUME signaling
            delay_count = 1800U; // Set RESUME line for 1-13 ms
            do {
                delay_count--;
            } while (delay_count);
            USBResumeControl = 0; //Finished driving resume signalling

            USBUnmaskInterrupts();
        }
    }
}

/*******************************************************************
 * Function:        BOOL USER_USB_CALLBACK_EVENT_HANDLER(
 *                        int event, void *pdata, WORD size)
 *
 * PreCondition:    None
 *
 * Input:           int event - the type of event
 *                  void *pdata - pointer to the event data
 *                  WORD size - size of the event data
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is called from the USB stack to
 *                  notify a user application that a USB event
 *                  occured.  This callback is in interrupt context
 *                  when the USB_INTERRUPT option is selected.
 *
 * Note:            None
 *******************************************************************/
BOOL USER_USB_CALLBACK_EVENT_HANDLER(int event, void *pdata, WORD size) {
    switch (event) {
        case EVENT_TRANSFER:
            //Add application specific callback task or callback function here if desired.
            break;
        case EVENT_SOF:
            USBCB_SOF_Handler();
            break;
        case EVENT_SUSPEND:
            USBCBSuspend();
            break;
        case EVENT_RESUME:
            USBCBWakeFromSuspend();
            break;
        case EVENT_CONFIGURED:
            USBCBInitEP();
            break;
        case EVENT_SET_DESCRIPTOR:
            USBCBStdSetDscHandler();
            break;
        case EVENT_EP0_REQUEST:
            USBCBCheckOtherReq();
            break;
        case EVENT_BUS_ERROR:
            USBCBErrorHandler();
            break;
        case EVENT_TRANSFER_TERMINATED:
            //Add application specific callback task or callback function here if desired.
            //The EVENT_TRANSFER_TERMINATED event occurs when the host performs a CLEAR
            //FEATURE (endpoint halt) request on an application endpoint which was 
            //previously armed (UOWN was = 1).  Here would be a good place to:
            //1.  Determine which endpoint the transaction that just got terminated was 
            //      on, by checking the handle value in the *pdata.
            //2.  Re-arm the endpoint if desired (typically would be the case for OUT 
            //      endpoints).
            break;
        default:
            break;
    }
    return TRUE;
}
static enum {
    EXCEP_IRQ = 0,           /* interrupt */
    EXCEP_AdEL = 4,          /* address error exception (load or ifetch) */
    EXCEP_AdES,              /* address error exception (store) */
    EXCEP_IBE,               /* bus error (ifetch) */
    EXCEP_DBE,               /* bus error (load/store) */
    EXCEP_Sys,               /* syscall */
    EXCEP_Bp,                /* breakpoint */
    EXCEP_RI,                /* reserved instruction */
    EXCEP_CpU,               /* coprocessor unusable */
    EXCEP_Overflow,          /* arithmetic overflow */
    EXCEP_Trap,              /* trap (possible divide by zero) */
    EXCEP_IS1 = 16,          /* implementation specfic 1 */
    EXCEP_CEU,               /* CorExtend Unuseable */
    EXCEP_C2E                /* coprocessor 2 */
} _excep_code;

