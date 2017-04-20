################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphic/Shader2.cpp \
../src/graphic/mesh.cpp \
../src/graphic/shader.cpp \
../src/graphic/textu.cpp \
../src/graphic/window.cpp 

C_SRCS += \
../src/graphic/stb_image.c 

C_DEPS += \
./src/graphic/stb_image.d 

OBJS += \
./src/graphic/Shader2.o \
./src/graphic/mesh.o \
./src/graphic/shader.o \
./src/graphic/stb_image.o \
./src/graphic/textu.o \
./src/graphic/window.o 

CPP_DEPS += \
./src/graphic/Shader2.d \
./src/graphic/mesh.d \
./src/graphic/shader.d \
./src/graphic/textu.d \
./src/graphic/window.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphic/%.o: ../src/graphic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/graphic/%.o: ../src/graphic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


