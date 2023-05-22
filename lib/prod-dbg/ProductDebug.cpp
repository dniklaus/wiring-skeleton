/*
 * ProductDebug.cpp
 *
 *  Created on: 14.06.2016
 *      Author: nid
 */

#include <Arduino.h>
#include <SerialCommand.h>
#include <AppDebug.h>
#include "ProductDebug.h"

class SerialCommand;

void ProductDebug::setupProdDebugEnv(SerialCommand* sCmd)
{
  AppDebug appDebug(sCmd);
  appDebug.setupDebugEnv();

  Serial.println();
  Serial.println("---------------------------------------------");
  Serial.println("Hello from Wiring Controller!");
  Serial.println("---------------------------------------------");
  Serial.println();
}
