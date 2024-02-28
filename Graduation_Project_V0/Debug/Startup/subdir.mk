################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c8tx.o: ../Startup/startup_stm32f103c8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

