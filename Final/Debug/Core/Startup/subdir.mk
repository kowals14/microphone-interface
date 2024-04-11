################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f746zgtx.s 

S_DEPS += \
./Core/Startup/startup_stm32f746zgtx.d 

OBJS += \
./Core/Startup/startup_stm32f746zgtx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/TouchScreenLCD" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/BSP" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/Codec" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/ParamEQ" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/LUTs" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Middlewares/ST/touchgfx/framework/include/touchgfx" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Delay" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f746zgtx.d ./Core/Startup/startup_stm32f746zgtx.o

.PHONY: clean-Core-2f-Startup

