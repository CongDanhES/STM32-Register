################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/myLib/GPIO.c \
../Core/myLib/RCC.c \
../Core/myLib/Timer.c 

OBJS += \
./Core/myLib/GPIO.o \
./Core/myLib/RCC.o \
./Core/myLib/Timer.o 

C_DEPS += \
./Core/myLib/GPIO.d \
./Core/myLib/RCC.d \
./Core/myLib/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/myLib/%.o Core/myLib/%.su: ../Core/myLib/%.c Core/myLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/NCPC/Desktop/Danh/STM32-Register/Timer/Core/myLib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-myLib

clean-Core-2f-myLib:
	-$(RM) ./Core/myLib/GPIO.d ./Core/myLib/GPIO.o ./Core/myLib/GPIO.su ./Core/myLib/RCC.d ./Core/myLib/RCC.o ./Core/myLib/RCC.su ./Core/myLib/Timer.d ./Core/myLib/Timer.o ./Core/myLib/Timer.su

.PHONY: clean-Core-2f-myLib

