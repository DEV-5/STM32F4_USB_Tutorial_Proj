################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Helpers/logger.c 

OBJS += \
./Src/Helpers/logger.o 

C_DEPS += \
./Src/Helpers/logger.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Helpers/%.o Src/Helpers/%.su Src/Helpers/%.cyclo: ../Src/Helpers/%.c Src/Helpers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -c -I../Inc -I"/home/vdev/programming/usb/STM32F4_USB_Tutorial_Proj/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Include" -I"/home/vdev/programming/usb/STM32F4_USB_Tutorial_Proj/usb_behind_the_scenes_stm32f407_disc1_tutorial/Inc/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Helpers

clean-Src-2f-Helpers:
	-$(RM) ./Src/Helpers/logger.cyclo ./Src/Helpers/logger.d ./Src/Helpers/logger.o ./Src/Helpers/logger.su

.PHONY: clean-Src-2f-Helpers

