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
    #ifdef INPUT_PULLDOWN
      pinMode(m_arduinoPin, isButtonNegativeLogic() ? INPUT_PULLUP : INPUT_PULLDOWN);
    #else
      pinMode(m_arduinoPin, isButtonNegativeLogic() ? INPUT_PULLUP : INPUT);
    #endif
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
