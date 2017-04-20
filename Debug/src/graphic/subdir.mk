################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphic/display.cpp \
../src/graphic/window.cpp 

OBJS += \
./src/graphic/display.o \
./src/graphic/window.o 

CPP_DEPS += \
./src/graphic/display.d \
./src/graphic/window.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphic/%.o: ../src/graphic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


