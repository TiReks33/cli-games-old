################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../balls20_funcs.cpp \
../balls20_game.cpp 

CPP_DEPS += \
./balls20_funcs.d \
./balls20_game.d 

OBJS += \
./balls20_funcs.o \
./balls20_game.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./balls20_funcs.d ./balls20_funcs.o ./balls20_game.d ./balls20_game.o

.PHONY: clean--2e-

