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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c outils.c ../pic32ssd1306-master/ssd1306.c display/font_7x9.c display/polygons.c display/timer_display.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/outils.o ${OBJECTDIR}/_ext/925301123/ssd1306.o ${OBJECTDIR}/display/font_7x9.o ${OBJECTDIR}/display/polygons.o ${OBJECTDIR}/display/timer_display.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/outils.o.d ${OBJECTDIR}/_ext/925301123/ssd1306.o.d ${OBJECTDIR}/display/font_7x9.o.d ${OBJECTDIR}/display/polygons.o.d ${OBJECTDIR}/display/timer_display.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/outils.o ${OBJECTDIR}/_ext/925301123/ssd1306.o ${OBJECTDIR}/display/font_7x9.o ${OBJECTDIR}/display/polygons.o ${OBJECTDIR}/display/timer_display.o

# Source Files
SOURCEFILES=main.c outils.c ../pic32ssd1306-master/ssd1306.c display/font_7x9.c display/polygons.c display/timer_display.c


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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX340F512H
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
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/outils.o: outils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/outils.o.d 
	@${RM} ${OBJECTDIR}/outils.o 
	@${FIXDEPS} "${OBJECTDIR}/outils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/outils.o.d" -o ${OBJECTDIR}/outils.o outils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/925301123/ssd1306.o: ../pic32ssd1306-master/ssd1306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925301123" 
	@${RM} ${OBJECTDIR}/_ext/925301123/ssd1306.o.d 
	@${RM} ${OBJECTDIR}/_ext/925301123/ssd1306.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/925301123/ssd1306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/_ext/925301123/ssd1306.o.d" -o ${OBJECTDIR}/_ext/925301123/ssd1306.o ../pic32ssd1306-master/ssd1306.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/font_7x9.o: display/font_7x9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/font_7x9.o.d 
	@${RM} ${OBJECTDIR}/display/font_7x9.o 
	@${FIXDEPS} "${OBJECTDIR}/display/font_7x9.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/font_7x9.o.d" -o ${OBJECTDIR}/display/font_7x9.o display/font_7x9.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/polygons.o: display/polygons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/polygons.o.d 
	@${RM} ${OBJECTDIR}/display/polygons.o 
	@${FIXDEPS} "${OBJECTDIR}/display/polygons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/polygons.o.d" -o ${OBJECTDIR}/display/polygons.o display/polygons.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/timer_display.o: display/timer_display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/timer_display.o.d 
	@${RM} ${OBJECTDIR}/display/timer_display.o 
	@${FIXDEPS} "${OBJECTDIR}/display/timer_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/timer_display.o.d" -o ${OBJECTDIR}/display/timer_display.o display/timer_display.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/outils.o: outils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/outils.o.d 
	@${RM} ${OBJECTDIR}/outils.o 
	@${FIXDEPS} "${OBJECTDIR}/outils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/outils.o.d" -o ${OBJECTDIR}/outils.o outils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/925301123/ssd1306.o: ../pic32ssd1306-master/ssd1306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/925301123" 
	@${RM} ${OBJECTDIR}/_ext/925301123/ssd1306.o.d 
	@${RM} ${OBJECTDIR}/_ext/925301123/ssd1306.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/925301123/ssd1306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/_ext/925301123/ssd1306.o.d" -o ${OBJECTDIR}/_ext/925301123/ssd1306.o ../pic32ssd1306-master/ssd1306.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/font_7x9.o: display/font_7x9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/font_7x9.o.d 
	@${RM} ${OBJECTDIR}/display/font_7x9.o 
	@${FIXDEPS} "${OBJECTDIR}/display/font_7x9.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/font_7x9.o.d" -o ${OBJECTDIR}/display/font_7x9.o display/font_7x9.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/polygons.o: display/polygons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/polygons.o.d 
	@${RM} ${OBJECTDIR}/display/polygons.o 
	@${FIXDEPS} "${OBJECTDIR}/display/polygons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/polygons.o.d" -o ${OBJECTDIR}/display/polygons.o display/polygons.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/display/timer_display.o: display/timer_display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/display" 
	@${RM} ${OBJECTDIR}/display/timer_display.o.d 
	@${RM} ${OBJECTDIR}/display/timer_display.o 
	@${FIXDEPS} "${OBJECTDIR}/display/timer_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32-libs/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/lega-c" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v2.10/pic32mx/include/newlib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/lib" -I"C:/Program Files (x86)/Microchip/xc32/v1.40/pic32mx/include/peripheral" -MMD -MF "${OBJECTDIR}/display/timer_display.o.d" -o ${OBJECTDIR}/display/timer_display.o display/timer_display.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../Program\ Files\ (x86)/Microchip/xc32/v1.40/pic32mx/lib/libmchp_peripheral_32MX340F512H.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPICkit3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    "..\..\..\..\..\..\Program Files (x86)\Microchip\xc32\v1.40\pic32mx\lib\libmchp_peripheral_32MX340F512H.a"      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PICkit3PlatformTool=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../Program\ Files\ (x86)/Microchip/xc32/v1.40/pic32mx/lib/libmchp_peripheral_32MX340F512H.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    "..\..\..\..\..\..\Program Files (x86)\Microchip\xc32\v1.40\pic32mx\lib\libmchp_peripheral_32MX340F512H.a"      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/L_ASMR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
