################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/Driver_DIO_V1/subdir.mk
-include HAL/LED_Handler/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
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
Lec12_LayeredStructure.lss \

FLASH_IMAGE += \
Lec12_LayeredStructure.hex \

EEPROM_IMAGE += \
Lec12_LayeredStructure.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Lec12_LayeredStructure.elf secondary-outputs

# Tool invocations
Lec12_LayeredStructure.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Lec12_LayeredStructure.map -mmcu=atmega32 -o "Lec12_LayeredStructure.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Lec12_LayeredStructure.lss: Lec12_LayeredStructure.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Lec12_LayeredStructure.elf  >"Lec12_LayeredStructure.lss"
	@echo 'Finished building: $@'
	@echo ' '

Lec12_LayeredStructure.hex: Lec12_LayeredStructure.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Lec12_LayeredStructure.elf  "Lec12_LayeredStructure.hex"
	@echo 'Finished building: $@'
	@echo ' '

Lec12_LayeredStructure.eep: Lec12_LayeredStructure.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Lec12_LayeredStructure.elf  "Lec12_LayeredStructure.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Lec12_LayeredStructure.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Lec12_LayeredStructure.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Lec12_LayeredStructure.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
