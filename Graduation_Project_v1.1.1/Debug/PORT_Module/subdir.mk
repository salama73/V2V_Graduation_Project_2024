################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PORT_Module/Port.c \
../PORT_Module/Port_PBcfg.c 

OBJS += \
./PORT_Module/Port.o \
./PORT_Module/Port_PBcfg.o 

C_DEPS += \
./PORT_Module/Port.d \
./PORT_Module/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
PORT_Module/Port.o: ../PORT_Module/Port.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PORT_Module/Port.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
PORT_Module/Port_PBcfg.o: ../PORT_Module/Port_PBcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PORT_Module/Port_PBcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

