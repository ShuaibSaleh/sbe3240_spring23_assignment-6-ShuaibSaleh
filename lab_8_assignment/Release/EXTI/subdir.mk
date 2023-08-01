################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI/EXTI.c 

OBJS += \
./EXTI/EXTI.o 

C_DEPS += \
./EXTI/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
EXTI/%.o: ../EXTI/%.c EXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"S:\Eclipse\lab_8_assignment\EXTI" -I"S:\Eclipse\lab_8_assignment\Gpio" -I"S:\Eclipse\lab_8_assignment\Lib" -I"S:\Eclipse\lab_8_assignment\Rcc" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


