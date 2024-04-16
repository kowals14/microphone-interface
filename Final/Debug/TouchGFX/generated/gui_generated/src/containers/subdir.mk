################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.o \
./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.o \
./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.o \
./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.o \
./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.o \
./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.o \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.o \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.o \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.d \
./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.d \
./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.d \
./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.d \
./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.d \
./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.d \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.d \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.d \
./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/containers/%.o TouchGFX/generated/gui_generated/src/containers/%.su TouchGFX/generated/gui_generated/src/containers/%.cyclo: ../TouchGFX/generated/gui_generated/src/containers/%.cpp TouchGFX/generated/gui_generated/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/TouchScreenLCD" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/BSP" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/Codec" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/ParamEQ" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/LUTs" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Middlewares/ST/touchgfx/framework/include/touchgfx" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Delay" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Distort" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers:
	-$(RM) ./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.d ./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.o ./TouchGFX/generated/gui_generated/src/containers/DelayParamsBase.su ./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.d ./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.o ./TouchGFX/generated/gui_generated/src/containers/DistoritonLowpassBase.su ./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.d ./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.o ./TouchGFX/generated/gui_generated/src/containers/DistortParamsBase.su ./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.d ./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.o ./TouchGFX/generated/gui_generated/src/containers/FilterParamsBase.su ./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.d ./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.o ./TouchGFX/generated/gui_generated/src/containers/NextPageDelayBase.su ./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.d ./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.o ./TouchGFX/generated/gui_generated/src/containers/NextPageEQBase.su ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.d ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.o ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDelayBase.su ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.d ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.o ./TouchGFX/generated/gui_generated/src/containers/TitleBoxDistortBase.su ./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.cyclo ./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.d ./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.o ./TouchGFX/generated/gui_generated/src/containers/TitleBoxParamEQBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

