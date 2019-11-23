################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/2_HIL/FloorManager.c 

OBJS += \
./source/2_HIL/FloorManager.o 

C_DEPS += \
./source/2_HIL/FloorManager.d 


# Each subdirectory must supply rules for building sources it contributes
source/2_HIL/%.o: ../source/2_HIL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I"/Users/rebo/Documents/MCUXpressoIDE_11.0.0/workspace/Elevator_C/source/1_APP" -I"/Users/rebo/Documents/MCUXpressoIDE_11.0.0/workspace/Elevator_C/source/2_HIL" -I"/Users/rebo/Documents/MCUXpressoIDE_11.0.0/workspace/Elevator_C/source/3_HAL" -I"/Users/rebo/Documents/MCUXpressoIDE_11.0.0/workspace/Elevator_C/source/4_SL" -I../source -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


