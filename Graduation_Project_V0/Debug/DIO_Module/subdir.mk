################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Module/Dio.c 

OBJS += \
./DIO_Module/Dio.o 

C_DEPS += \
./DIO_Module/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
DIO_Module/Dio.o: ../DIO_Module/Dio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DIO_Module/Dio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

