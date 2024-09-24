################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/SystemInit.c \
../Src/main.c 

OBJS += \
./Src/SystemInit.o \
./Src/main.o 

C_DEPS += \
./Src/SystemInit.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c -I../Inc -I"/home/vdev/STM32CubeIDE/workspace_1.16.1/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Include" -I"/home/vdev/STM32CubeIDE/workspace_1.16.1/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c -I../Inc -I"/home/vdev/STM32CubeIDE/workspace_1.16.1/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Include" -I"/home/vdev/STM32CubeIDE/workspace_1.16.1/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/SystemInit.cyclo ./Src/SystemInit.d ./Src/SystemInit.o ./Src/SystemInit.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

