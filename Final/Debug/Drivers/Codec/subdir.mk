################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Codec/wm8731.c 

C_DEPS += \
./Drivers/Codec/wm8731.d 

OBJS += \
./Drivers/Codec/wm8731.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Codec/%.o Drivers/Codec/%.su Drivers/Codec/%.cyclo: ../Drivers/Codec/%.c Drivers/Codec/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/TouchScreenLCD" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/BSP" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/Codec" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/ParamEQ" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/LUTs" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Middlewares/ST/touchgfx/framework/include/touchgfx" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Delay" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Distort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Codec

clean-Drivers-2f-Codec:
	-$(RM) ./Drivers/Codec/wm8731.cyclo ./Drivers/Codec/wm8731.d ./Drivers/Codec/wm8731.o ./Drivers/Codec/wm8731.su

.PHONY: clean-Drivers-2f-Codec

