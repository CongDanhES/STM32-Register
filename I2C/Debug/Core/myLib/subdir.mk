################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/myLib/GPIO.c \
../Core/myLib/I2C.c \
../Core/myLib/RCC.c 

OBJS += \
./Core/myLib/GPIO.o \
./Core/myLib/I2C.o \
./Core/myLib/RCC.o 

C_DEPS += \
./Core/myLib/GPIO.d \
./Core/myLib/I2C.d \
./Core/myLib/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Core/myLib/%.o Core/myLib/%.su Core/myLib/%.cyclo: ../Core/myLib/%.c Core/myLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/NCPC/Desktop/Danh/STM32-BareMetal/STM32-Register/I2C/Core/myLib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-myLib

clean-Core-2f-myLib:
	-$(RM) ./Core/myLib/GPIO.cyclo ./Core/myLib/GPIO.d ./Core/myLib/GPIO.o ./Core/myLib/GPIO.su ./Core/myLib/I2C.cyclo ./Core/myLib/I2C.d ./Core/myLib/I2C.o ./Core/myLib/I2C.su ./Core/myLib/RCC.cyclo ./Core/myLib/RCC.d ./Core/myLib/RCC.o ./Core/myLib/RCC.su

.PHONY: clean-Core-2f-myLib

