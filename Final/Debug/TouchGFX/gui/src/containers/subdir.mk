################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/containers/DelayParams.cpp \
../TouchGFX/gui/src/containers/DistoritonLowpass.cpp \
../TouchGFX/gui/src/containers/DistortParams.cpp \
../TouchGFX/gui/src/containers/FilterParams.cpp \
../TouchGFX/gui/src/containers/NextPageDelay.cpp \
../TouchGFX/gui/src/containers/NextPageEQ.cpp \
../TouchGFX/gui/src/containers/TitleBoxDelay.cpp \
../TouchGFX/gui/src/containers/TitleBoxDistort.cpp \
../TouchGFX/gui/src/containers/TitleBoxParamEQ.cpp 

OBJS += \
./TouchGFX/gui/src/containers/DelayParams.o \
./TouchGFX/gui/src/containers/DistoritonLowpass.o \
./TouchGFX/gui/src/containers/DistortParams.o \
./TouchGFX/gui/src/containers/FilterParams.o \
./TouchGFX/gui/src/containers/NextPageDelay.o \
./TouchGFX/gui/src/containers/NextPageEQ.o \
./TouchGFX/gui/src/containers/TitleBoxDelay.o \
./TouchGFX/gui/src/containers/TitleBoxDistort.o \
./TouchGFX/gui/src/containers/TitleBoxParamEQ.o 

CPP_DEPS += \
./TouchGFX/gui/src/containers/DelayParams.d \
./TouchGFX/gui/src/containers/DistoritonLowpass.d \
./TouchGFX/gui/src/containers/DistortParams.d \
./TouchGFX/gui/src/containers/FilterParams.d \
./TouchGFX/gui/src/containers/NextPageDelay.d \
./TouchGFX/gui/src/containers/NextPageEQ.d \
./TouchGFX/gui/src/containers/TitleBoxDelay.d \
./TouchGFX/gui/src/containers/TitleBoxDistort.d \
./TouchGFX/gui/src/containers/TitleBoxParamEQ.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/containers/%.o TouchGFX/gui/src/containers/%.su TouchGFX/gui/src/containers/%.cyclo: ../TouchGFX/gui/src/containers/%.cpp TouchGFX/gui/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/TouchScreenLCD" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/BSP" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Drivers/Codec" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/ParamEQ" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/LUTs" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/Middlewares/ST/touchgfx/framework/include/touchgfx" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Delay" -I"C:/Users/Kuba/STM32CubeIDE/workspace_1.14.0/Final/AudioFX/Distort" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-containers

clean-TouchGFX-2f-gui-2f-src-2f-containers:
	-$(RM) ./TouchGFX/gui/src/containers/DelayParams.cyclo ./TouchGFX/gui/src/containers/DelayParams.d ./TouchGFX/gui/src/containers/DelayParams.o ./TouchGFX/gui/src/containers/DelayParams.su ./TouchGFX/gui/src/containers/DistoritonLowpass.cyclo ./TouchGFX/gui/src/containers/DistoritonLowpass.d ./TouchGFX/gui/src/containers/DistoritonLowpass.o ./TouchGFX/gui/src/containers/DistoritonLowpass.su ./TouchGFX/gui/src/containers/DistortParams.cyclo ./TouchGFX/gui/src/containers/DistortParams.d ./TouchGFX/gui/src/containers/DistortParams.o ./TouchGFX/gui/src/containers/DistortParams.su ./TouchGFX/gui/src/containers/FilterParams.cyclo ./TouchGFX/gui/src/containers/FilterParams.d ./TouchGFX/gui/src/containers/FilterParams.o ./TouchGFX/gui/src/containers/FilterParams.su ./TouchGFX/gui/src/containers/NextPageDelay.cyclo ./TouchGFX/gui/src/containers/NextPageDelay.d ./TouchGFX/gui/src/containers/NextPageDelay.o ./TouchGFX/gui/src/containers/NextPageDelay.su ./TouchGFX/gui/src/containers/NextPageEQ.cyclo ./TouchGFX/gui/src/containers/NextPageEQ.d ./TouchGFX/gui/src/containers/NextPageEQ.o ./TouchGFX/gui/src/containers/NextPageEQ.su ./TouchGFX/gui/src/containers/TitleBoxDelay.cyclo ./TouchGFX/gui/src/containers/TitleBoxDelay.d ./TouchGFX/gui/src/containers/TitleBoxDelay.o ./TouchGFX/gui/src/containers/TitleBoxDelay.su ./TouchGFX/gui/src/containers/TitleBoxDistort.cyclo ./TouchGFX/gui/src/containers/TitleBoxDistort.d ./TouchGFX/gui/src/containers/TitleBoxDistort.o ./TouchGFX/gui/src/containers/TitleBoxDistort.su ./TouchGFX/gui/src/containers/TitleBoxParamEQ.cyclo ./TouchGFX/gui/src/containers/TitleBoxParamEQ.d ./TouchGFX/gui/src/containers/TitleBoxParamEQ.o ./TouchGFX/gui/src/containers/TitleBoxParamEQ.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-containers

