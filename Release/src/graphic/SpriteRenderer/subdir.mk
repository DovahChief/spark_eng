################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphic/SpriteRenderer/batchRender.cpp \
../src/graphic/SpriteRenderer/simple2Drenderer.cpp \
../src/graphic/SpriteRenderer/sprite.cpp \
../src/graphic/SpriteRenderer/static_sprite.cpp 

OBJS += \
./src/graphic/SpriteRenderer/batchRender.o \
./src/graphic/SpriteRenderer/simple2Drenderer.o \
./src/graphic/SpriteRenderer/sprite.o \
./src/graphic/SpriteRenderer/static_sprite.o 

CPP_DEPS += \
./src/graphic/SpriteRenderer/batchRender.d \
./src/graphic/SpriteRenderer/simple2Drenderer.d \
./src/graphic/SpriteRenderer/sprite.d \
./src/graphic/SpriteRenderer/static_sprite.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphic/SpriteRenderer/%.o: ../src/graphic/SpriteRenderer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


