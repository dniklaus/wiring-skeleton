/*
 * ArduinoDigitalInPinSupervisor.cpp
 *
 *  Created on: 25.01.2018
 *      Author: niklaudi
 */


#include <Arduino.h>

#include <ArduinoDigitalInPinSupervisor.h>

ArduinoDigitalInPinSupervisor::ArduinoDigitalInPinSupervisor(int arduinoPin)
: PinSupervisor(PinSupervisor::IS_NEG_LOGIC)
, m_arduinoPin(arduinoPin)
{
  if (0 <= m_arduinoPin)
  {
    pinMode(m_arduinoPin, isButtonNegativeLogic() ? INPUT_PULLUP : INPUT_PULLDOWN);
  }
}

ArduinoDigitalInPinSupervisor::~ArduinoDigitalInPinSupervisor()
{ }


bool ArduinoDigitalInPinSupervisor::getPinState()
{
  bool state = false;
  if (0 <= m_arduinoPin)
  {
    state = digitalRead(m_arduinoPin);
  }
  return state;
}
