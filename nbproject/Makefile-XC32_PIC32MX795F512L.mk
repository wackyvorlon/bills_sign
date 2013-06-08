#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-XC32_PIC32MX795F512L.mk)" "nbproject/Makefile-local-XC32_PIC32MX795F512L.mk"
include nbproject/Makefile-local-XC32_PIC32MX795F512L.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC32_PIC32MX795F512L
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o ${OBJECTDIR}/usb_device.o ${OBJECTDIR}/usb_function_generic.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/LEDcontrol.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuration_bits.o.d ${OBJECTDIR}/exceptions.o.d ${OBJECTDIR}/interrupts.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/user.o.d ${OBJECTDIR}/usb_device.o.d ${OBJECTDIR}/usb_function_generic.o.d ${OBJECTDIR}/usb_descriptors.o.d ${OBJECTDIR}/LEDcontrol.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o ${OBJECTDIR}/usb_device.o ${OBJECTDIR}/usb_function_generic.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/LEDcontrol.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-XC32_PIC32MX795F512L.mk dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c   
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c   
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c   
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c   
	
${OBJECTDIR}/usb_device.o: usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_device.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_device.o.d" -o ${OBJECTDIR}/usb_device.o usb_device.c   
	
${OBJECTDIR}/usb_function_generic.o: usb_function_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_function_generic.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_function_generic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_function_generic.o.d" -o ${OBJECTDIR}/usb_function_generic.o usb_function_generic.c   
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d" -o ${OBJECTDIR}/usb_descriptors.o usb_descriptors.c   
	
${OBJECTDIR}/LEDcontrol.o: LEDcontrol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LEDcontrol.o.d 
	@${FIXDEPS} "${OBJECTDIR}/LEDcontrol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/LEDcontrol.o.d" -o ${OBJECTDIR}/LEDcontrol.o LEDcontrol.c   
	
else
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c   
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c   
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c   
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c   
	
${OBJECTDIR}/usb_device.o: usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_device.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_device.o.d" -o ${OBJECTDIR}/usb_device.o usb_device.c   
	
${OBJECTDIR}/usb_function_generic.o: usb_function_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_function_generic.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_function_generic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_function_generic.o.d" -o ${OBJECTDIR}/usb_function_generic.o usb_function_generic.c   
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d" -o ${OBJECTDIR}/usb_descriptors.o usb_descriptors.c   
	
${OBJECTDIR}/LEDcontrol.o: LEDcontrol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LEDcontrol.o.d 
	@${FIXDEPS} "${OBJECTDIR}/LEDcontrol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"C:/Bill/USB LED Matrix 22x44.X/Include" -I"C:/Program Files (x86)/Microchip/xc32/v1.21/pic32mx/include" -I"C:/Bill/USB LED Matrix 22x44.X/Include/USB" -I"C:/Bill/USB LED Matrix 22x44.X/USB" -I"C:/Bill/USB LED Matrix 22x44.X" -O3 -MMD -MF "${OBJECTDIR}/LEDcontrol.o.d" -o ${OBJECTDIR}/LEDcontrol.o LEDcontrol.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/USB_LED_Matrix_22x44.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/XC32_PIC32MX795F512L
	${RM} -r dist/XC32_PIC32MX795F512L

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
