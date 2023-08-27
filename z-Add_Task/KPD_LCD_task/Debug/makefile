################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Driver_DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD_Handler/subdir.mk
-include HAL/7Seg/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
KPD_LCD_task.lss \

FLASH_IMAGE += \
KPD_LCD_task.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KPD_LCD_task.elf secondary-outputs

# Tool invocations
KPD_LCD_task.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KPD_LCD_task.map -mmcu=atmega32 -o "KPD_LCD_task.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KPD_LCD_task.lss: KPD_LCD_task.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KPD_LCD_task.elf  >"KPD_LCD_task.lss"
	@echo 'Finished building: $@'
	@echo ' '

KPD_LCD_task.hex: KPD_LCD_task.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KPD_LCD_task.elf  "KPD_LCD_task.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KPD_LCD_task.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KPD_LCD_task.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KPD_LCD_task.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
