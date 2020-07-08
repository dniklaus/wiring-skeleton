/*
 * MyButtonAdapter.cpp
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */
#include <Arduino.h>
#include <Indicator.h>
#include <MyButtonAdapter.h>

MyButtonAdapter::MyButtonAdapter(Indicator* indicator)
: m_indicator(indicator)
{ }

MyButtonAdapter::~MyButtonAdapter()
{ }

void MyButtonAdapter::notifyStatusChanged(bool isActive)
{
  if (0 != m_indicator)
  {
    if (isActive)
    {
      switch (m_indicator->getLedState())
      {
        case Indicator::ELedState::blink:
          m_indicator->clear();
          break;
        case Indicator::ELedState::off:
          m_indicator->set();
          break;
        case Indicator::ELedState::on:
          m_indicator->blink();
          break;
        default:
          m_indicator->clear();
          break;
      }
    }
  }

}
