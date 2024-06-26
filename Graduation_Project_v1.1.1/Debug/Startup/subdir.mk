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
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

