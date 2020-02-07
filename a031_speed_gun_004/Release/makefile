################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include z_bak_200203/subdir.mk
-include libraries/makeblock/src/utility/avr/subdir.mk
-include libraries/makeblock/src/subdir.mk
-include libraries/aapMbot/src/subdir.mk
-include libraries/Wire/src/utility/subdir.mk
-include libraries/Wire/src/subdir.mk
-include libraries/TimerFreeTone/subdir.mk
-include libraries/SoftwareSerial/src/subdir.mk
-include libraries/SPI/src/subdir.mk
-include libraries/Grove_RGB_Backlight_LCD/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/arduino.ar \

ELF += \
a031_speed_gun_004.elf \

HEX += \
a031_speed_gun_004.hex \


# All Target
all: a031_speed_gun_004

# Tool invocations
a031_speed_gun_004: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/opt/Sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-size" -A "/media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/a031_speed_gun_004.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/opt/Sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs     /media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

a031_speed_gun_004.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/opt/Sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -Wall -Wextra -Os -Wl,--gc-sections,--relax -mmcu=atmega2560  -o "/media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/a031_speed_gun_004.elf"   $(LINK_OBJ)   /media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release/arduino.ar  "-L/media/tom/Silo_002/TechWork/arduino_sloeber/a031_speed_gun_004/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

a031_speed_gun_004.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
