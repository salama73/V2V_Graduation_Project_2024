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
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"F:/Graduation_Project_v1.0.1_doxygen/Can_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/DIO_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/CMSIS_V5" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX" -I"F:/Graduation_Project_v1.0.1_doxygen/PORT_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/PWM_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/RTE" -I"F:/Graduation_Project_v1.0.1_doxygen/SWCs" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

