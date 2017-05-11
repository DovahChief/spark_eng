################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/math/mat4.cpp \
../src/math/vec2.cpp \
../src/math/vec3.cpp \
../src/math/vec4.cpp 

OBJS += \
./src/math/mat4.o \
./src/math/vec2.o \
./src/math/vec3.o \
./src/math/vec4.o 

CPP_DEPS += \
./src/math/mat4.d \
./src/math/vec2.d \
./src/math/vec3.d \
./src/math/vec4.d 


# Each subdirectory must supply rules for building sources it contributes
src/math/%.o: ../src/math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


