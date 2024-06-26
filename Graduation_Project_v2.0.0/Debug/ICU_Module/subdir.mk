################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ICU_Module/Icu.c \
../ICU_Module/Icu_PBcfg.c 

OBJS += \
./ICU_Module/Icu.o \
./ICU_Module/Icu_PBcfg.o 

C_DEPS += \
./ICU_Module/Icu.d \
./ICU_Module/Icu_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
ICU_Module/Icu.o: ../ICU_Module/Icu.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/ICU_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Can_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers" -I"F:/Graduation_Project_v1.0.1_doxygen/DIO_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/CMSIS_V5" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/PORT_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/PWM_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/RTE" -I"F:/Graduation_Project_v1.0.1_doxygen/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ICU_Module/Icu.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
ICU_Module/Icu_PBcfg.o: ../ICU_Module/Icu_PBcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/ICU_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Can_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/Common" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/Complex_Drivers" -I"F:/Graduation_Project_v1.0.1_doxygen/DIO_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/CMSIS_V5" -I"F:/Graduation_Project_v1.0.1_doxygen/OSEK_VDX/Inc" -I"F:/Graduation_Project_v1.0.1_doxygen/PORT_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/PWM_Module" -I"F:/Graduation_Project_v1.0.1_doxygen/RTE" -I"F:/Graduation_Project_v1.0.1_doxygen/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ICU_Module/Icu_PBcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

