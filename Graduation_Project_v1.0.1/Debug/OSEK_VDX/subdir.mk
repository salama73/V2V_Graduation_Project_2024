################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OSEK_VDX/Cortex_Mx_Porting.c \
../OSEK_VDX/Event.c \
../OSEK_VDX/MY_RTOS_FIFO.c \
../OSEK_VDX/Scheduler.c \
../OSEK_VDX/Task.c \
../OSEK_VDX/Task_Config.c 

OBJS += \
./OSEK_VDX/Cortex_Mx_Porting.o \
./OSEK_VDX/Event.o \
./OSEK_VDX/MY_RTOS_FIFO.o \
./OSEK_VDX/Scheduler.o \
./OSEK_VDX/Task.o \
./OSEK_VDX/Task_Config.o 

C_DEPS += \
./OSEK_VDX/Cortex_Mx_Porting.d \
./OSEK_VDX/Event.d \
./OSEK_VDX/MY_RTOS_FIFO.d \
./OSEK_VDX/Scheduler.d \
./OSEK_VDX/Task.d \
./OSEK_VDX/Task_Config.d 


# Each subdirectory must supply rules for building sources it contributes
OSEK_VDX/Cortex_Mx_Porting.o: ../OSEK_VDX/Cortex_Mx_Porting.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/Cortex_Mx_Porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
OSEK_VDX/Event.o: ../OSEK_VDX/Event.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/Event.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
OSEK_VDX/MY_RTOS_FIFO.o: ../OSEK_VDX/MY_RTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/MY_RTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
OSEK_VDX/Scheduler.o: ../OSEK_VDX/Scheduler.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
OSEK_VDX/Task.o: ../OSEK_VDX/Task.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/Task.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
OSEK_VDX/Task_Config.o: ../OSEK_VDX/Task_Config.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Can_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Common" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/Complex_Drivers" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/DIO_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/CMSIS_V5" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/OSEK_VDX/Inc" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PORT_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/PWM_Module" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/RTE" -I"C:/Users/ELBOSTAN/Desktop/Graduation_Project_v1.0.1/SWCs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"OSEK_VDX/Task_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

