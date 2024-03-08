################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWM_Module/Pwm.c \
../PWM_Module/Pwm_PBcfg.c 

OBJS += \
./PWM_Module/Pwm.o \
./PWM_Module/Pwm_PBcfg.o 

C_DEPS += \
./PWM_Module/Pwm.d \
./PWM_Module/Pwm_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
PWM_Module/Pwm.o: ../PWM_Module/Pwm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PWM_Module/Pwm.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
PWM_Module/Pwm_PBcfg.o: ../PWM_Module/Pwm_PBcfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"PWM_Module/Pwm_PBcfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

