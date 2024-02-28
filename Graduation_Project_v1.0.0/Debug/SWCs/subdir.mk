################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SWCs/BSW_SWC.c \
../SWCs/LED_SWC.c \
../SWCs/Main_SWC.c \
../SWCs/Motor_SWC.c 

OBJS += \
./SWCs/BSW_SWC.o \
./SWCs/LED_SWC.o \
./SWCs/Main_SWC.o \
./SWCs/Motor_SWC.o 

C_DEPS += \
./SWCs/BSW_SWC.d \
./SWCs/LED_SWC.d \
./SWCs/Main_SWC.d \
./SWCs/Motor_SWC.d 


# Each subdirectory must supply rules for building sources it contributes
SWCs/BSW_SWC.o: ../SWCs/BSW_SWC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SWCs/BSW_SWC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
SWCs/LED_SWC.o: ../SWCs/LED_SWC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SWCs/LED_SWC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
SWCs/Main_SWC.o: ../SWCs/Main_SWC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SWCs/Main_SWC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
SWCs/Motor_SWC.o: ../SWCs/Motor_SWC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Autosar_Project/Graduation_Project_V0/Can_Module" -I"F:/Autosar_Project/Graduation_Project_V0/Common" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/Complex_Drivers" -I"F:/Autosar_Project/Graduation_Project_V0/DIO_Module" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/CMSIS_V5" -I"F:/Autosar_Project/Graduation_Project_V0/OSEK_VDX/Inc" -I"F:/Autosar_Project/Graduation_Project_V0/PORT_Module" -I"F:/Autosar_Project/Graduation_Project_V0/PWM_Module" -I"F:/Autosar_Project/Graduation_Project_V0/RTE" -I"F:/Autosar_Project/Graduation_Project_V0/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SWCs/Motor_SWC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

