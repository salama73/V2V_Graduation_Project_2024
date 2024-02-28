################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Complex_Drivers/Cortex_M3_NVIC.c 

OBJS += \
./Complex_Drivers/Cortex_M3_NVIC.o 

C_DEPS += \
./Complex_Drivers/Cortex_M3_NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
Complex_Drivers/Cortex_M3_NVIC.o: ../Complex_Drivers/Cortex_M3_NVIC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Complex_Drivers/Cortex_M3_NVIC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

