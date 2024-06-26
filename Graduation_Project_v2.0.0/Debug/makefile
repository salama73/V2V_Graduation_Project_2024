################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include SWCs/subdir.mk
-include RTE/subdir.mk
-include PWM_Module/subdir.mk
-include PORT_Module/subdir.mk
-include OSEK_VDX/subdir.mk
-include ICU_Module/subdir.mk
-include DIO_Module/subdir.mk
-include Complex_Drivers/subdir.mk
-include Common/subdir.mk
-include Can_Module/subdir.mk
-include CanIf_Module/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Graduation_Project_V0.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Graduation_Project_V0.list \

OBJCOPY_BIN += \
Graduation_Project_V0.bin \


# All Target
all: Graduation_Project_V0.axf secondary-outputs

# Tool invocations
Graduation_Project_V0.axf: $(OBJS) $(USER_OBJS) F:\Graduation_Project_v1.0.1_doxygen\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Graduation_Project_V0.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Graduation_Project_v1.0.1_doxygen\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Graduation_Project_V0.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Graduation_Project_V0.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Graduation_Project_V0.list"
	@echo 'Finished building: $@'
	@echo ' '

Graduation_Project_V0.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Graduation_Project_V0.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
