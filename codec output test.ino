#include <I2S.h>
#include <Wire.h>

const uint8_t WM8731_ADDRESS             = 0x1A;       // WM8731 chip address on I2C bus
const uint8_t WM8731_REG_LHPHONE_OUT     = 0x02;       // Left Channel Headphone Output Volume Control
const uint8_t WM8731_REG_RHPHONE_OUT     = 0x03;       // Right Channel Headphone Output Volume Control
const uint8_t WM8731_REG_ANALOG_PATH     = 0x04;       // Analog Audio Path Control
const uint8_t WM8731_REG_DIGITAL_PATH    = 0x05;       // Digital Audio Path 
const uint8_t WM8731_REG_PDOWN_CTRL      = 0x06;       // Power Down Control Register
const uint8_t WM8731_REG_DIGITAL_IF      = 0x07;       // Digital Audio Interface Format
const uint8_t WM8731_REG_SAMPLING_CTRL   = 0x08;       // Sampling Control Register
const uint8_t WM8731_REG_ACTIVE_CTRL     = 0x09;       // Active Control
const uint8_t WM8731_REG_RESET           = 0x0F;       // Reset register

const uint16_t _WM8731_Left_hp            = 0x00F4;     // Headphone settings : -10dB output
const uint16_t _WM8731_Right_hp           = 0x00F4;     // Headphone settings : -10dB output
const uint16_t _WM8731_AnalogAudio        = 0x00D0;       // DAC Select
const uint16_t _WM8731_DigitalAudio       = 0x0004;       // 44.1kHz de-emphasis
const uint16_t _WM8731_power              = 0x0000;       // Disable Power down
const uint16_t _WM8731_DAIF               = 0x0002;       // 16bit data
const uint16_t _WM8731_Sampling           = 0x0023;       // 44100Hz
const uint16_t _WM8731_Activate           = 0x0001;       // Module is ON
const uint16_t _WM8731_Reset              = 0x0000;       // Reset value

short sample = 5000; // current sample value
int count = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  I2CCommand(WM8731_REG_RESET, _WM8731_Reset);
  I2CCommand(WM8731_REG_LHPHONE_OUT, _WM8731_Left_hp);
  I2CCommand(WM8731_REG_RHPHONE_OUT, _WM8731_Right_hp);
  I2CCommand(WM8731_REG_ANALOG_PATH, _WM8731_AnalogAudio);
  I2CCommand(WM8731_REG_DIGITAL_PATH, _WM8731_DigitalAudio);
  I2CCommand(WM8731_REG_PDOWN_CTRL, _WM8731_power);
  I2CCommand(WM8731_REG_DIGITAL_IF, _WM8731_DAIF);
  I2CCommand(WM8731_REG_SAMPLING_CTRL, _WM8731_Sampling);
  I2CCommand(WM8731_REG_ACTIVE_CTRL, _WM8731_Activate);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start I2S at 8 kHz with 16-bits per sample
  if (!I2S.begin(I2S_PHILIPS_MODE, 44100, 16)) {
    Serial.println("Failed to initialize I2S!");

    while (1); // do nothing
  }
}

void I2CCommand(uint8_t address, uint16_t cmd) {
  //addresses are 7 bits, but 8 bits are transmitted each time in I2C, so shift address left. LSB should be MSB of register value
  uint8_t addr = (address << 1) | (cmd >> 8);

  Wire.beginTransmission(byte(WM8731_ADDRESS));

  Wire.write(byte(addr));
  Wire.write(byte(cmd));

  Wire.endTransmission();
}

void loop() {
  if (count % 100 == 0) {
    // invert the sample every half wavelength count multiple to generate square wave
    sample = -1 * sample;
  }

  // write the same sample twice, once for left and once for the right channel
  I2S.write(sample);
  I2S.write(sample);

  // increment the counter for the next sample
  count++;
}