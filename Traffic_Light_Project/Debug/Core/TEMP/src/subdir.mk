################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/TEMP/src/button.c \
../Core/TEMP/src/fsm_automatic.c \
../Core/TEMP/src/fsm_manual.c \
../Core/TEMP/src/global.c \
../Core/TEMP/src/led7_segment.c \
../Core/TEMP/src/scheduler.c \
../Core/TEMP/src/software_timer.c \
../Core/TEMP/src/traffic_light.c 

OBJS += \
./Core/TEMP/src/button.o \
./Core/TEMP/src/fsm_automatic.o \
./Core/TEMP/src/fsm_manual.o \
./Core/TEMP/src/global.o \
./Core/TEMP/src/led7_segment.o \
./Core/TEMP/src/scheduler.o \
./Core/TEMP/src/software_timer.o \
./Core/TEMP/src/traffic_light.o 

C_DEPS += \
./Core/TEMP/src/button.d \
./Core/TEMP/src/fsm_automatic.d \
./Core/TEMP/src/fsm_manual.d \
./Core/TEMP/src/global.d \
./Core/TEMP/src/led7_segment.d \
./Core/TEMP/src/scheduler.d \
./Core/TEMP/src/software_timer.d \
./Core/TEMP/src/traffic_light.d 


# Each subdirectory must supply rules for building sources it contributes
Core/TEMP/src/%.o: ../Core/TEMP/src/%.c Core/TEMP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

