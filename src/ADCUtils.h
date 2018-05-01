/*
 * ADCUtils.h
 *
 *  Created on: 23.02.2018
 *      Author: Armin
 */

#ifndef SRC_ADCUTILS_H_
#define SRC_ADCUTILS_H_

#include <Arduino.h>

// PRESCALE4 => 13 * 4 = 52 microseconds per ADC conversion at 1 Mhz Clock => 19,2kHz
#define ADC_PRESCALE2    1 // 26 microseconds per ADC conversion at 1 MHz
#define ADC_PRESCALE4    2 // 52 microseconds per ADC conversion at 1 MHz
// PRESCALE8 => 13 * 8 = 104 microseconds per ADC sample at 1 Mhz Clock => 9,6kHz
#define ADC_PRESCALE8    3 // 104 microseconds per ADC conversion at 1 MHz
#define ADC_PRESCALE16   4 // 208 microseconds per ADC conversion at 1 MHz
#define ADC_PRESCALE32   5 // 416 microseconds per ADC conversion at 1 MHz
#define ADC_PRESCALE64   6 // 52 microseconds per ADC conversion at 16 MHz
#define ADC_PRESCALE128  7 // 104 microseconds per ADC conversion at 16 MHz

// definitions for 0.1 ms conversion time
#if (F_CPU == 1000000)
#define ADC_PRESCALE ADC_PRESCALE8
#elif (F_CPU == 8000000)
#define ADC_PRESCALE ADC_PRESCALE64
#elif (F_CPU == 16000000)
#define ADC_PRESCALE ADC_PRESCALE128
#endif

// Temperature channel definitions - 1 LSB / 1 degree Celsius
#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define ADC_TEMPERATURE_CHANNEL_MUX 15
#define ADC_1_1_VOLT_CHANNEL_MUX 12
#endif
#if defined (__AVR_ATmega328P__)
#define ADC_TEMPERATURE_CHANNEL_MUX 8
#define ADC_1_1_VOLT_CHANNEL_MUX 14
#endif

uint16_t readADCChannel(uint8_t aChannelNumber);
uint16_t readADCChannelWithReference(uint8_t aChannelNumber, uint8_t aVoltageReference);
uint16_t readADCChannelWithOversample(uint8_t aChannelNumber, uint8_t aOversampleExponent);
uint16_t readADCChannelWithReferenceOversample(uint8_t aChannelNumber, uint8_t aVoltageReference, uint8_t aOversampleExponent);

#endif /* SRC_ADCUTILS_H_ */
