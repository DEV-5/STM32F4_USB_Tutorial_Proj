################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/Helpers/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := usb_behind_the_scenes_stm32f407_disc1_tutorial
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
usb_behind_the_scenes_stm32f407_disc1_tutorial.elf \

MAP_FILES += \
usb_behind_the_scenes_stm32f407_disc1_tutorial.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
usb_behind_the_scenes_stm32f407_disc1_tutorial.list \


# All Target
all: main-build

# Main-build Target
main-build: usb_behind_the_scenes_stm32f407_disc1_tutorial.elf secondary-outputs

# Tool invocations
usb_behind_the_scenes_stm32f407_disc1_tutorial.elf usb_behind_the_scenes_stm32f407_disc1_tutorial.map: $(OBJS) $(USER_OBJS) /home/vdev/programming/usb/STM32F4_USB_Tutorial_Proj/usb_behind_the_scenes_stm32f407_disc1_tutorial/STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "usb_behind_the_scenes_stm32f407_disc1_tutorial.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/vdev/programming/usb/STM32F4_USB_Tutorial_Proj/usb_behind_the_scenes_stm32f407_disc1_tutorial/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="usb_behind_the_scenes_stm32f407_disc1_tutorial.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

usb_behind_the_scenes_stm32f407_disc1_tutorial.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "usb_behind_the_scenes_stm32f407_disc1_tutorial.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout usb_behind_the_scenes_stm32f407_disc1_tutorial.elf usb_behind_the_scenes_stm32f407_disc1_tutorial.list usb_behind_the_scenes_stm32f407_disc1_tutorial.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
