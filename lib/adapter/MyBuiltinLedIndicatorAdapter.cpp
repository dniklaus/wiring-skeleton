/*
 * MyBuiltinLedIndicatorAdapter.cpp
 *
 *  Created on: 04.11.2019
 *      Author: nid
 */

#include "MyBuiltinLedIndicatorAdapter.h"

#include <Arduino.h>

MyBuiltinLedIndicatorAdapter::MyBuiltinLedIndicatorAdapter()
{
  // initialize built in LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);

  // switch LED off
  setLed(false);
}

MyBuiltinLedIndicatorAdapter::~MyBuiltinLedIndicatorAdapter()
{ }

void MyBuiltinLedIndicatorAdapter::notifyStatusChange(bool status)
{
  setLed(status);
}

void MyBuiltinLedIndicatorAdapter::setLed(bool isOn)
{
#if defined(ESP8266) || defined(BOARD_LOLIN_D32)
  // the built-in LED logic on ESP8266 modules and on LOLIN D2 boards is inverted!
  isOn = !isOn;
#endif
  digitalWrite(LED_BUILTIN, isOn);
}
