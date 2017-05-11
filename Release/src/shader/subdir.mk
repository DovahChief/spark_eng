################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
FRAG_SRCS += \
../src/shader/basicShader.frag 

VERT_SRCS += \
../src/shader/basicShader.vert 

VERT_DEPS += \
./src/shader/basicShader.d 

OBJS += \
./src/shader/basicShader.o 

FRAG_DEPS += \
./src/shader/basicShader.d 


# Each subdirectory must supply rules for building sources it contributes
src/shader/%.o: ../src/shader/%.frag
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/shader/%.o: ../src/shader/%.vert
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


