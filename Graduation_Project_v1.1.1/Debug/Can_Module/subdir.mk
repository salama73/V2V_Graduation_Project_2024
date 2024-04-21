################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Can_Module/Can.c \
../Can_Module/CanIf.c \
../Can_Module/Can_PBcfg.c \
../Can_Module/stm32_f103c6_CAN.c 

OBJS += \
./Can_Module/Can.o \
./Can_Module/CanIf.o \
./Can_Module/Can_PBcfg.o \
./Can_Module/stm32_f103c6_CAN.o 

C_DEPS += \
./Can_Module/Can.d \
./Can_Module/CanIf.d \
./Can_Module/Can_PBcfg.d \
./Can_Module/stm32_f103c6_CAN.d 


# Each subdirectory must supply rules for building sources it contributes
Can_Module/Can.o: ../Can_Module/Can.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Can_Module/Can.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Can_Module/CanIf.o: ../Can_Module/CanIf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Can_Module/CanIf.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Can_Module/Can_PBcfg.o: ../Can_Module/Can_PBcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Can_Module/Can_PBcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Can_Module/stm32_f103c6_CAN.o: ../Can_Module/stm32_f103c6_CAN.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Can_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Common" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/Complex_Drivers" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/DIO_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PORT_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/PWM_Module" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/RTE" -I"D:/V2V_Graduation_Project_2024-main/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Can_Module/stm32_f103c6_CAN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

