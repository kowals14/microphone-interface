# USB Microphone Interface
This repository holds all the necessary files for [team 12's ECE 477 project](https://engineering.purdue.edu/477grp12/).

## Project Description
Microphone Interface is a microphone interface intended to be used with analog audio microphones. This interface would apply various DSP effects to the audio and pass it to an analog output. Specifically, our device will implement the following functionality:
* Be powered via micro-USB.
* Receive an analog audio input via 3.5mm TRS jack.
* Apply the following user selectable and user controllable DSP effects:
    * Five band equalization
    * Distortion
    * Delay
*  Allow the user to navigate backwards and formwards via two push buttons.
*   Allow the user to manipulate the following DSP parameters via three rotary encoders:
    * Equalization (for each band):
      * Frequency
      * Width
      * Gain
    * Distortion:
      * Pre-Amp
      * Gain
      * Mix
    * Delay:
      * Time
      * Feedback
      * Mix
* Display the states of each DSP parameter (with a separate page for each effect) via a graphical user interface.
* Output the modified audio signal via a 3.5mm TRS jack.
  
## PROJECT SPECIFIC DESIGN REQUIREMENTS (PSDRS):
* PSDR #1 (Hardware): An ability to send and receive an audio signal to and from a codec and a microcontroller via I2S.
* PSDR #2 (Software): An ability to apply five band EQ, distortion, and delay effects via DSP on an input audio.
* PSDR #3 (Hardware): An ability to control DSP parameters using input to a microcontroller from a set of rotary encoders and buttons.
* PSDR #4 (Hardware): An ability for the microcontroller to interface with an LCD display via SPI.
* PSDR #5 (Software): An ability to provide a GUI to display DSP parameters and corresponding audio effects.

## STRETCH PSDRS:
* PSDR #6 (hardware): An ability to control parameters and interact with the user interface via capacitive touch screen.
