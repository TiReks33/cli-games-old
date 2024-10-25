################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../redspies_funcs.c \
../redspies_game.c 

C_DEPS += \
./redspies_funcs.d \
./redspies_game.d 

OBJS += \
./redspies_funcs.o \
./redspies_game.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./redspies_funcs.d ./redspies_funcs.o ./redspies_game.d ./redspies_game.o

.PHONY: clean--2e-

