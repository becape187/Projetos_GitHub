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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1188221400/Main.p1 ${OBJECTDIR}/_ext/1188221400/Serial.p1 ${OBJECTDIR}/_ext/1188221400/PPS.p1 ${OBJECTDIR}/_ext/1188221400/Wifi.p1 ${OBJECTDIR}/_ext/1188221400/3G.p1 ${OBJECTDIR}/_ext/1188221400/COMM.p1 ${OBJECTDIR}/_ext/1188221400/GERREX.p1 ${OBJECTDIR}/_ext/1188221400/Modbus.p1 ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1188221400/Main.p1.d ${OBJECTDIR}/_ext/1188221400/Serial.p1.d ${OBJECTDIR}/_ext/1188221400/PPS.p1.d ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d ${OBJECTDIR}/_ext/1188221400/3G.p1.d ${OBJECTDIR}/_ext/1188221400/COMM.p1.d ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1188221400/Main.p1 ${OBJECTDIR}/_ext/1188221400/Serial.p1 ${OBJECTDIR}/_ext/1188221400/PPS.p1 ${OBJECTDIR}/_ext/1188221400/Wifi.p1 ${OBJECTDIR}/_ext/1188221400/3G.p1 ${OBJECTDIR}/_ext/1188221400/COMM.p1 ${OBJECTDIR}/_ext/1188221400/GERREX.p1 ${OBJECTDIR}/_ext/1188221400/Modbus.p1 ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1

# Source Files
SOURCEFILES=I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F56K42
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1188221400/Main.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Main.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Main.d ${OBJECTDIR}/_ext/1188221400/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Serial.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Serial.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Serial.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Serial.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Serial.d ${OBJECTDIR}/_ext/1188221400/Serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/PPS.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/PPS.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/PPS.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/PPS.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/PPS.d ${OBJECTDIR}/_ext/1188221400/PPS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/PPS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Wifi.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Wifi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Wifi.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Wifi.d ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/3G.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/3G.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/3G.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/3G.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/3G.d ${OBJECTDIR}/_ext/1188221400/3G.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/3G.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/COMM.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/COMM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/COMM.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/COMM.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/COMM.d ${OBJECTDIR}/_ext/1188221400/COMM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/COMM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/GERREX.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/GERREX.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/GERREX.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/GERREX.d ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Modbus.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Modbus.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Modbus.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Modbus.d ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.d ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1188221400/Main.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Main.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Main.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Main.d ${OBJECTDIR}/_ext/1188221400/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Serial.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Serial.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Serial.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Serial.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Serial.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Serial.d ${OBJECTDIR}/_ext/1188221400/Serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/PPS.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/PPS.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/PPS.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/PPS.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/PPS.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/PPS.d ${OBJECTDIR}/_ext/1188221400/PPS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/PPS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Wifi.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Wifi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Wifi.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Wifi.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Wifi.d ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Wifi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/3G.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/3G.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/3G.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/3G.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/3G.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/3G.d ${OBJECTDIR}/_ext/1188221400/3G.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/3G.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/COMM.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/COMM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/COMM.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/COMM.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/COMM.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/COMM.d ${OBJECTDIR}/_ext/1188221400/COMM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/COMM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/GERREX.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/GERREX.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/GERREX.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/GERREX.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/GERREX.d ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/GERREX.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Modbus.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Modbus.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Modbus.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Modbus.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Modbus.d ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Modbus.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1: I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1188221400" 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1  I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X/Conversor_Escalas.c 
	@-${MV} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.d ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1188221400/Conversor_Escalas.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"I:/Projetos_Servidor/MIB_Iot_100/MIB_IOT_SW/MIB_IOT.X" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/MIB_IOT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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
