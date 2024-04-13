/*
 * wm8731.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Liam Roach
 */

#include <wm8731.h>
#include "main.h" // Hardware setting

extern I2C_HandleTypeDef hi2c2;
extern SAI_HandleTypeDef hsai_BlockA1;
extern SAI_HandleTypeDef hsai_BlockB1;
extern void MX_SAI1_Init();

static void I2Cx_Error(I2C_HandleTypeDef* i2c_handler, uint8_t Addr)
{
	  HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_14);
//    HAL_I2C_DeInit(i2c_handler);
//    HAL_I2C_Init(i2c_handler);
}

void WM8731I2CCommand(uint8_t reg, uint16_t cmd) {
  //addresses are 7 bits, but 8 bits are transmitted each time in I2C, so shift address left. LSB should be MSB of register value
  uint8_t buff[2];
  buff[0] = (reg << 1) | (cmd >> 8);
  buff[1] = (uint8_t) cmd;

  if (HAL_I2C_Master_Transmit(&hi2c2, WM8731_ADDRESS, buff, 2, HAL_MAX_DELAY) != HAL_OK) {
	  I2Cx_Error(&hi2c2, WM8731_ADDRESS);
  }
}

void WM8731_Init() {
	  WM8731I2CCommand(WM8731_REG_PDOWN_CTRL, _WM8731_power_off);
	  WM8731I2CCommand(WM8731_REG_RESET, _WM8731_Reset);
	   WM8731I2CCommand(WM8731_REG_LLINE, _WM8731_Left_line);
	   WM8731I2CCommand(WM8731_REG_RLINE, _WM8731_Right_line);
	   WM8731I2CCommand(WM8731_REG_LHPHONE_OUT, _WM8731_Left_hp);
	   WM8731I2CCommand(WM8731_REG_RHPHONE_OUT, _WM8731_Right_hp);
	//   //WM8731I2CCommand(WM8731_REG_ANALOG_PATH, _WM8731_AnalogAudio_Mic);
	  WM8731I2CCommand(WM8731_REG_ANALOG_PATH, _WM8731_AnalogAudio_Line);
	   WM8731I2CCommand(WM8731_REG_DIGITAL_PATH, _WM8731_DigitalAudio);
	   WM8731I2CCommand(WM8731_REG_PDOWN_CTRL, _WM8731_power | WM8731_MICPD);
	   WM8731I2CCommand(WM8731_REG_DIGITAL_IF, _WM8731_DAIF);
	//   //WM8731I2CCommand(WM8731_REG_SAMPLING_CTRL, _WM8731_Sampling);
	  WM8731I2CCommand(WM8731_REG_ACTIVE_CTRL, _WM8731_Activate);
//	  WM8731_In_Mute();


}

void WM8731_In_Vol(double dBvol) {
	WM8731I2CCommand(WM8731_REG_RLINE, WM8731_INBOTH | WM8731_INVOL(dBvol));
}

void WM8731_In_Mute(){
	WM8731I2CCommand(WM8731_REG_RLINE, WM8731_INBOTH | WM8731_INMUTE);
}

void WM8731_Out_Vol(double dBvol) {

}

