/*
 * ButtonEdgeDetector.cpp
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */

#include <DbgTracePort.h>
#include <DbgTraceLevel.h>
#include <Button.h>
#include <ButtonEdgeDetector.h>

ButtonEdgeDetector::ButtonEdgeDetector()
: m_trPort(new DbgTrace_Port("btn", DbgTrace_Level::info))
, m_count(0)
{ }

ButtonEdgeDetector::~ButtonEdgeDetector()
{
  delete m_trPort;
  m_trPort = 0;
}

void ButtonEdgeDetector::onEdge(bool newState)
{
  if (newState)
  {
    m_count++;
    TR_PRINTF(m_trPort, DbgTrace_Level::info, "Count: %d", m_count);
  }
  TR_PRINTF(m_trPort, DbgTrace_Level::debug, "Button %s", newState ? "pressed" : "released");
  if (0 != button())
  {
    if (0 != button()->adapter())
    {
      button()->adapter()->notifyStatusChanged(newState);
    }
  }
}
