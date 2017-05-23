################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /opt/ti/energia-0101E0017/hardware/tools/lm4f

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./AMAS.o" \
"./classes/Ph.o" \
"./classes/SecureDigitalCard.o" \
"./classes/Sensor.o" \
"./classes/Temperature.o" \
"./main.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-Wl,-T"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432/linker.cmd" \
-lMSP-EXP432P401R_core \
-ldriverlib \
-lstdc++ \
-lm \
-lc \
-lgcc \
-lnosys \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include classes/subdir_vars.mk
-include subdir_rules.mk
-include classes/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
AMAS.out \

EXE_OUTPUTS__QUOTED += \
"AMAS.out" \

BIN_OUTPUTS += \
AMAS.hex \

BIN_OUTPUTS__QUOTED += \
"AMAS.hex" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "AMAS.out"

dependents:
	-cd /home/vinholi/workspace_v7/MSP-EXP432P401R_core/Debug && $(MAKE) all

# Tool invocations
AMAS.out: $(OBJS) $(GEN_CMDS) /home/vinholi/workspace_v7/MSP-EXP432P401R_core/Debug/libMSP-EXP432P401R_core.a
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Linker'
	"/opt/ti/energia-0101E0017/hardware/tools/lm4f/bin/arm-none-eabi-gcc" @"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432/compiler.opt"  -fno-exceptions -DBOARD_MSP_EXP432P401R -D__MSP432P401R__ -DTARGET_IS_MSP432P4XX -Dxdc__nolocalstring=1 -DENERGIA=17 -DARDUINO=101 -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gdwarf-3 -gstrict-dwarf -Wall -mfloat-abi=hard -Wl,-Map,"AMAS.map" -nostartfiles -static -Wl,--gc-sections -L"/home/vinholi/workspace_v7/MSP-EXP432P401R_core/Debug" -L"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432" -L"/opt/ti/energia-0101E0017/hardware/emt/ti/runtime/wiring/msp432/variants/MSP_EXP432P401R" -L"/opt/ti/energia-0101E0017/hardware/emt" -L"/opt/ti/energia-0101E0017/hardware/msp432/variants/MSP_EXP432P401R" -L"/opt/ti/energia-0101E0017/hardware/msp432/cores/msp432/driverlib" -Wl,--no-wchar-size-warning -o"AMAS.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

AMAS.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: GNU Objcopy Utility'
	"/opt/ti/energia-0101E0017/hardware/tools/lm4f/bin/arm-none-eabi-objcopy"  $(EXE_OUTPUTS__QUOTED) "AMAS.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "AMAS.o" "main.o" "classes/Ph.o" "classes/SecureDigitalCard.o" "classes/Sensor.o" "classes/Temperature.o" 
	-$(RM) "AMAS.d" "main.d" "AMAS.d" "classes/Ph.d" "classes/SecureDigitalCard.d" "classes/Sensor.d" "classes/Temperature.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/vinholi/workspace_v7/MSP-EXP432P401R_core/Debug/libMSP-EXP432P401R_core.a:

-include ../makefile.targets

