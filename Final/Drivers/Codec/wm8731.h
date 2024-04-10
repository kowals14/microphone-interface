/*
 * wm8731.h
 *
 *  Created on: Mar 15, 2024
 *      Author: Liam Roach
 */

#ifndef INC_WM8731_H_
#define INC_WM8731_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h" // Hardware setting

#define WM8731_ADDRESS              (uint8_t) 0x1B << 1 // WM8731 chip address on I2C bus

#define WM8731_REG_LLINE            (uint8_t) 0x00  // Left line input
#define WM8731_REG_RLINE            (uint8_t) 0x01  // Right line input
#define WM8731_REG_LHPHONE_OUT      (uint8_t) 0x02  // Left Channel Headphone Output Volume Control
#define WM8731_REG_RHPHONE_OUT      (uint8_t) 0x03  // Right Channel Headphone Output Volume Control
#define WM8731_REG_ANALOG_PATH      (uint8_t) 0x04  // Analog Audio Path Control
#define WM8731_REG_DIGITAL_PATH     (uint8_t) 0x05  // Digital Audio Path
#define WM8731_REG_PDOWN_CTRL       (uint8_t) 0x06  // Power Down Control Register
#define WM8731_REG_DIGITAL_IF       (uint8_t) 0x07  // Digital Audio Interface Format
#define WM8731_REG_SAMPLING_CTRL    (uint8_t) 0x08  // Sampling Control Register
#define WM8731_REG_ACTIVE_CTRL      (uint8_t) 0x09  // Active Control
#define WM8731_REG_RESET            (uint8_t) 0x0F  // Reset register

#define WM8731_INVOL(dbVol)         (uint16_t) ((dbVol/1.5) + 23) // Line input volume
#define WM8731_INMUTE		        (uint16_t) 0b010000000  // Mute line input
#define WM8731_INBOTH		        (uint16_t) 0b100000000  // Simultaenous volume and mute load for both lines

#define WM8731_HPVOL(dbVol)         (uint16_t) ((dbVol + 121) * (dbVol >= -73))  // Headphone input volume
#define WM8731_ZCEN		            (uint16_t) 0b010000000  // Channel zero cross detect enable
#define WM8731_HPBOTH		        (uint16_t) 0b100000000  // Simultaenous volume and mute load for both headphones

#define WM8731_MICBOOST             (uint16_t) 0b000000001  // Boost mic
#define WM8731_MUTEMIC              (uint16_t) 0b000000010  // Mute mic
#define WM8731_INSEL                (uint16_t) 0b000000100  // Microphone input select
#define WM8731_BYPASS               (uint16_t) 0b000001000  // Bypass mode
#define WM8731_DACSEL               (uint16_t) 0b000010000  // DAC select
#define WM8731_SIDETONE             (uint16_t) 0b000100000  // Side tone switch
#define WM8731_SIDEATT_15dB         (uint16_t) 0b011000000  // Side tone attenuation -15dB
#define WM8731_SIDEATT_12dB         (uint16_t) 0b010000000  // Side tone attenuation -12dB
#define WM8731_SIDEATT_9dB          (uint16_t) 0b001000000  // Side tone attenuation -9dB
#define WM8731_SIDEATT_6dB          (uint16_t) 0b000000000  // Side tone attenuation -6dB

#define WM8731_ADCHPD               (uint16_t) 0b000000001  // Disable highpass filter
#define WM8731_DEEMP                (uint16_t) 0b000000110  // De-emphasis control 48kHz
#define WM8731_DACMU                (uint16_t) 0b000001000  // Enable soft mute
#define WM8731_HPOR                 (uint16_t) 0b000010000  // Store dc offset when High Pass Filter disabled

#define WM8731_LINEINPD             (uint16_t) 0b000000001  // Line Input Power Down
#define WM8731_MICPD                (uint16_t) 0b000000010  // Microphone Input an Bias PowerDown
#define WM8731_ADCPD                (uint16_t) 0b000000100  // ADC Power Down
#define WM8731_DACPD                (uint16_t) 0b000001000  // DAC Power Down
#define WM8731_OUTPD                (uint16_t) 0b000010000  // Outputs Power Down
#define WM8731_OSCPD                (uint16_t) 0b000100000  // Oscillator Power Down
#define WM8731_CLKOUTPD             (uint16_t) 0b001000000  // CLKOUT power down
#define WM8731_POWEROFF             (uint16_t) 0b010000000  // POWEROFF mode

#define WM8731_FORMAT_DSP           (uint16_t) 0b000000011  // DSP Mode, frame sync + 2 data packed words
#define WM8731_FORMAT_I2S           (uint16_t) 0b000000010  // I2S Format, MSB-First left-1 justified
#define WM8731_FORMAT_LJ            (uint16_t) 0b000000001  // MSB-First, left justified
#define WM8731_FORMAT_RJ            (uint16_t) 0b000000000  // MSB-First, right justified
#define WM8731_IWL_32               (uint16_t) 0b000001100  // Input Audio Data Bit Length Select, 32 bits
#define WM8731_IWL_24               (uint16_t) 0b000001000  // Input Audio Data Bit Length Select, 24 bits
#define WM8731_IWL_20               (uint16_t) 0b000000100  // Input Audio Data Bit Length Select, 20 bits
#define WM8731_IWL_16               (uint16_t) 0b000000000  // Input Audio Data Bit Length Select, 16 bits
#define WM8731_I2S_LRP              (uint16_t) 0b000010000  // DACLRC phase control (in left, right or I2S modes), 
                                                            // 1 = Right Channel DAC data when DACLRC high
                                                            // 0 = Right Channel DAC data when DACLRC low
#define WM8731_DSP_LRP              (uint16_t) 0b000010000  // DSP mode A/B select (in DSP mode only)
                                                            // 1 = MSB is available on 2nd BCLK rising edge after DACLRC rising edge
                                                            // 0 = MSB is available on 1st BCLK rising edge after DACLRC rising edge
#define WM8731_LRSWAP               (uint16_t) 0b000100000  // DAC Left Right Clock Swap
                                                            // 1 = Right Channel DAC Data Left
                                                            // 0 = Right Channel DAC Data Right
#define WM8731_MS                   (uint16_t) 0b001000000  // Master Slave Mode Control, 1 = Master
#define WM8731_BCLKINV              (uint16_t) 0b010000000  // Bit Clock Invert

#define WM8731_USB                  (uint16_t) 0b000000001  // USB Mode Select
#define WM8731_NORMAL               (uint16_t) 0b000000000  // Normal Mode Select
#define WM8731_USB_BOSR_250fs       (uint16_t) 0b000000000  // USB Mode Base Over-Sampling Rate 250fs
#define WM8731_USB_BOSR_272fs       (uint16_t) 0b000000010  // USB Mode Base Over-Sampling Rate 272fs
#define WM8731_NORMAL_BOSR_256fs    (uint16_t) 0b000000000  // Normal Mode Base Over-Sampling Rate 256fs
#define WM8731_NORMAL_BOSR_384fs    (uint16_t) 0b000000010  // Normal Mode Base Over-Sampling Rate 384fs
#define WM8731_SR_44kHZ             (uint16_t) 0b000100000
#define WM8731_SR_48kHZ             (uint16_t) 0b000000000
#define WM8731_SR_96kHZ             (uint16_t) 0b000011100
#define WM8731_CLKIDIV2             (uint16_t) 0b001000000  // Core Clock = MCLK / 2
#define WM8731_CLKODIV2             (uint16_t) 0b010000000  // CLOCKOUT = Core Clock / 2

#define WM8731_ACTIVE               (uint16_t) 0b000000001  // Activate Interface

#define WM8731_RESET                (uint16_t) 0b000000000  // Reset Device

#define _WM8731_Left_line           (uint16_t) 0b000001111
#define _WM8731_Right_line          (uint16_t) 0b000001111
#define _WM8731_Left_hp             (uint16_t) 0b011111011     // Headphone settings : -10dB output
#define _WM8731_Right_hp            (uint16_t) 0b011111011     // Headphone settings : -10dB output
#define _WM8731_AnalogAudio_Line    (uint16_t) 0b000010010
#define _WM8731_AnalogAudio_Mic     (uint16_t) 0b000010101       // DAC Select
#define _WM8731_DigitalAudio        (uint16_t) 0b000000111       // disable high pass
#define _WM8731_power               (uint16_t) 0b000000010       // Disable Power down
#define _WM8731_power_off           (uint16_t) 0b111111111       // Power down
#define _WM8731_DAIF                (uint16_t) 0b001000010       // 16bit data
#define _WM8731_Sampling            (uint16_t) 0b000000000       // 44100Hz
#define _WM8731_Activate            (uint16_t) 0b000000001       // Module is ON
#define _WM8731_Reset               (uint16_t) 0b000000000       // Reset value

void WM8731I2CCommand(uint8_t, uint16_t);
void WM8731_Init(void);
void WM8731_In_Mute(void);
void WM8731_In_Vol(double dBvol);
void WM8731_Out_Vol(double dBvol);

#ifdef __cplusplus
}
#endif

#endif /* INC_WM8731_H_ */
