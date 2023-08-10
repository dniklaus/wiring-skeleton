/*
 * App.cpp
 *
 *  Created on: 18.05.2023
 *      Author: didi
 */
#include <Arduino.h>
#include <SerialCommand.h>
#include <SpinTimer.h>
#include <Indicator.h>
#include <IndicatorFactory.h>
#include <MyBuiltinLedIndicatorAdapter.h>
#include <Button.h>
#include <ButtonEdgeDetector.h>
#include <MyButtonAdapter.h>
#include <ArduinoDigitalInPinSupervisor.h>
#include <ProductDebug.h>
#include "App.h"

const char App::s_termChar = '\n';

App::App()
: m_sCmd(new SerialCommand(s_termChar))
, m_led(0)
{ }

App::~App()
{ 
  // delete m_led->adapter();  // TODO: this needs the Indicator dtor to provice public CCSS
  // m_led->assignAdapter(0);

  // delete m_led;
  // m_led = 0;

  // delete m_sCmd;
  // m_sCmd = 0;
}

void App::setup()
{

  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  ProductDebug::setupProdDebugEnv(m_sCmd);

  // indicator LED
  m_led = IndicatorFactory::createIndicator("led", "Built in LED.");
  m_led->assignAdapter(new MyBuiltinLedIndicatorAdapter());

  #ifdef USER_BTN
    new Button(new ArduinoDigitalInPinSupervisor(USER_BTN), new ButtonEdgeDetector(), new MyButtonAdapter(m_led));
  #endif
}

void App::loop()
{
  if (0 != m_sCmd)
  {
    m_sCmd->readSerial();     // process serial commands
  }
  // scheduleTimers();

  delayAndSchedule(1000);
  printBatteryVoltage();
}

void App::printBatteryVoltage()
{
  uint16_t rawBat = analogRead(35);
  float vBat = rawBat / 4096.0 * (2.225 * 3.3);
  // uint16_t rawBat = analogRead(34);
  // float vBat = rawBat / 4096.0 * (3.3);
  char printString[100];
  sprintf(printString, "Vbat: %2.3f [V] (raw: %u)", vBat, rawBat);
  Serial.println(printString);
} 
