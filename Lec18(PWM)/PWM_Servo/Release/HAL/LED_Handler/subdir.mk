################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED_Handler/LED_prog.c 

OBJS += \
./HAL/LED_Handler/LED_prog.o 

C_DEPS += \
./HAL/LED_Handler/LED_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED_Handler/%.o: ../HAL/LED_Handler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


