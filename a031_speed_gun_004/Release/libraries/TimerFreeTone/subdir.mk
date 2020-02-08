################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/tom/Arduino/libraries/TimerFreeTone/TimerFreeTone.cpp 

LINK_OBJ += \
./libraries/TimerFreeTone/TimerFreeTone.cpp.o 

CPP_DEPS += \
./libraries/TimerFreeTone/TimerFreeTone.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/TimerFreeTone/TimerFreeTone.cpp.o: /home/tom/Arduino/libraries/TimerFreeTone/TimerFreeTone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/Sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/mega" -I"/home/tom/Arduino/libraries/Grove_RGB_Backlight_LCD" -I"/home/tom/Arduino/libraries/makeblock/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SoftwareSerial/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SPI/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/Wire/src" -I"/home/tom/Arduino/libraries/aapUtility/src" -I"/home/tom/Arduino/libraries/TimerFreeTone" -I"/home/tom/Arduino/libraries/aapMbot/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/mega" -I"/home/tom/Arduino/libraries/aapMbot/src" -I"/home/tom/Arduino/libraries/aapUtility/src" -I"/home/tom/Arduino/libraries/Grove_RGB_Backlight_LCD" -I"/home/tom/Arduino/libraries/makeblock/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SoftwareSerial/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SPI/src" -I"/home/tom/Arduino/libraries/TimerFreeTone" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/Wire/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/mega" -I"/home/tom/Arduino/libraries/aapMbot/src" -I"/home/tom/Arduino/libraries/aapUtility/src" -I"/home/tom/Arduino/libraries/Grove_RGB_Backlight_LCD" -I"/home/tom/Arduino/libraries/makeblock/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SoftwareSerial/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SPI/src" -I"/home/tom/Arduino/libraries/TimerFreeTone" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/Wire/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/mega" -I"/home/tom/Arduino/libraries/aapMbot/src" -I"/home/tom/Arduino/libraries/Grove_RGB_Backlight_LCD" -I"/home/tom/Arduino/libraries/makeblock/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SoftwareSerial/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SPI/src" -I"/home/tom/Arduino/libraries/TimerFreeTone" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/Wire/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/mega" -I"/home/tom/Arduino/libraries/aapMbot/src" -I"/home/tom/Arduino/libraries/Grove_RGB_Backlight_LCD" -I"/home/tom/Arduino/libraries/makeblock/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SoftwareSerial/src" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/SPI/src" -I"/home/tom/Arduino/libraries/TimerFreeTone" -I"/opt/Sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


