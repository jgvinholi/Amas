################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-385781137:
	@$(MAKE) -Onone -f subdir_rules.mk build-385781137-inproc

build-385781137-inproc: ../AMAS.ino
	@echo 'Building file: $<'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: $<'
	@echo ' '

AMAS.cpp: build-385781137 ../AMAS.ino
main.cpp: build-385781137
AMAS.cpp: build-385781137

%.o: ./%.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"/opt/ti/energia-0101E0017/hardware/tools/lm4f/bin/arm-none-eabi-gcc" -c @"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432/compiler.opt"  -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-exceptions -DBOARD_MSP_EXP432P401R -D__MSP432P401R__ -DTARGET_IS_MSP432P4XX -Dxdc__nolocalstring=1 -DENERGIA=17 -DARDUINO=101 -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/inc/CMSIS" -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/driverlib/MSP432P4xx" -I"/opt/ti/energia-0101E0017/hardware/msp432/variants/MSP_EXP432P401R" -I"/opt/ti/energia-0101E0017/hardware/emt" -I"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432" -I"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring" -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432" -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/driverlib" -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/inc" -I"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/lib" -I"/home/vinholi/workspace_v7/AMAS" -I"/opt/ti/energia-0101E0017/hardware/msp432/libraries/OneWire" -I"/opt/ti/energia-0101E0017/hardware/tools/lm4f/arm-none-eabi/include" -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -fno-rtti -o"$@" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


