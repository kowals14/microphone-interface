#include <I2S.h>
#include <Wire.h>

const uint8_t WM8731_ADDRESS             = 0x1A;       // WM8731 chip address on I2C bus
const uint8_t WM8731_REG_PDOWN_CTRL      = 0x06;       // Power Down Control Register
const uint8_t WM8731_REG_ACTIVE_CTRL     = 0x09;       // Active Control
const uint8_t WM8731_REG_RESET           = 0x0F;       // Reset register
const uint8_t WM8731_REG_ANALOG_PATH     = 0x04;       // Analog Audio Path Control
const uint8_t WM8731_REG_DIGITAL_PATH    = 0x05;       // Digital Audio Path 

const uint16_t _WM8731_AnalogAudio        = 0x0004;       // Setup Audio Path (select and unmute mic)
const uint16_t _WM8731_power              = 0x0000;       // Disable Power down
const uint16_t _WM8731_Activate           = 0x0001;       // Module is ON
const uint16_t _WM8731_Reset              = 0x0000;       // Reset value

void setup() {
  Serial.begin(115200);
  Wire.begin();

  I2CCommand(WM8731_REG_RESET, _WM8731_Reset);
  I2CCommand(WM8731_REG_ANALOG_PATH, _WM8731_AnalogAudio);
  I2CCommand(WM8731_REG_PDOWN_CTRL, _WM8731_power);
  I2CCommand(WM8731_REG_ACTIVE_CTRL, _WM8731_Activate);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start I2S at 8 kHz with 32-bits per sample
  if (!I2S.begin(I2S_PHILIPS_MODE, 8000, 32)) {
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
  // read a sample
  int sample = I2S.read();

  if (sample) {
    // if it's non-zero print value to serial
    Serial.println(sample);
  }
}

