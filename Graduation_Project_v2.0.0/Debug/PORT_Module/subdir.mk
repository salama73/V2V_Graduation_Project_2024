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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/ICU_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Can_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers" -I"F:/Graduation_Project_v1.0.1_doxygen/DIO_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/CMSIS_V5" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/PORT_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/PWM_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/RTE" -I"F:/Graduation_Project_v1.0.1_doxygen/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PORT_Module/Port.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
PORT_Module/Port_PBcfg.o: ../PORT_Module/Port_PBcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/ICU_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Can_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers" -I"F:/Graduation_Project_v1.0.1_doxygen/DIO_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/CMSIS_V5" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/PORT_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/PWM_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/RTE" -I"F:/Graduation_Project_v1.0.1_doxygen/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PORT_Module/Port_PBcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

