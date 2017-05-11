################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphic/buffers/buffer.cpp \
../src/graphic/buffers/indexBuffer.cpp \
../src/graphic/buffers/vertexArray.cpp 

OBJS += \
./src/graphic/buffers/buffer.o \
./src/graphic/buffers/indexBuffer.o \
./src/graphic/buffers/vertexArray.o 

CPP_DEPS += \
./src/graphic/buffers/buffer.d \
./src/graphic/buffers/indexBuffer.d \
./src/graphic/buffers/vertexArray.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphic/buffers/%.o: ../src/graphic/buffers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


