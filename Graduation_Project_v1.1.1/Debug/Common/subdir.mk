################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common/Det.c 

OBJS += \
./Common/Det.o 

C_DEPS += \
./Common/Det.d 


# Each subdirectory must supply rules for building sources it contributes
Common/Det.o: ../Common/Det.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Common/Det.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

