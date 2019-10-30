/*
 * wiring-skeleton.cpp
 *
 *  Created on: 15.03.2017
 *      Author: niklausd
 */

#include <Arduino.h>

// PlatformIO libraries
#include <SerialCommand.h>  // pio lib install 173, lib details see https://github.com/kroimon/Arduino-SerialCommand
#include <Timer.h>          // pio lib install 1699, lib details see https://github.com/dniklaus/wiring-timer

// private libraries
#include <DbgCliNode.h>
#include <DbgCliTopic.h>
#include <DbgCliCommand.h>
#include <DbgTracePort.h>
#include <DbgTraceContext.h>
#include <DbgTraceOut.h>
#include <DbgPrintConsole.h>
#include <DbgTraceLevel.h>
#include <AppDebug.h>
#include <ProductDebug.h>
#include <RamUtils.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

SerialCommand* sCmd = 0;

//-----------------------------------------------------------------------------
// fun built in LED control CLI command implementation
//-----------------------------------------------------------------------------
void toggleLed()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void setLed(bool isOn)
{
#ifdef ESP8266
  // the LED logic on ESP8266 module is inverted!
  isOn = !isOn;
#endif
  digitalWrite(LED_BUILTIN, isOn);
}

class MyLedBlinkTimerAdapter : public TimerAdapter
{
  void timeExpired()
  {
    toggleLed();
  }
};

class DbgCliCmd_LedSet : public DbgCli_Command
{
private:
  const unsigned long c_ledBlinkTimeMillis = 200;
  DbgTrace_Port* m_trPort;
  Timer* m_ledBlinkTimer;

  enum class ELedState
  {
    off   = 0,
    on    = 1,
    blink = 2
  };

public:
  DbgCliCmd_LedSet()
  : DbgCli_Command(new DbgCli_Topic(DbgCli_Node::RootNode(), "led", "Built in LED."), "set", "Set LED state")
  , m_trPort(new DbgTrace_Port("led", DbgTrace_Level::notice))
  , m_ledBlinkTimer(new Timer(new MyLedBlinkTimerAdapter(), Timer::IS_RECURRING, c_ledBlinkTimeMillis))
  { }

  void printUsage()
  {
    TR_PRINTF(m_trPort, DbgTrace_Level::alert, "%s", getHelpText());
    TR_PRINTF(m_trPort, DbgTrace_Level::alert, "Usage: dbg led set [blink|on|off].");
  }

  void printReport()
  {
    TR_PRINTF(m_trPort, DbgTrace_Level::alert, "%s : %s", getHelpText(), getLedStateText(getLedState()));
  }

  ELedState getLedState()
  {
    ELedState ledState = m_ledBlinkTimer->isRunning()     ? ELedState::blink  :
                         (digitalRead(LED_BUILTIN) == 1)  ? ELedState::on     :
                                                            ELedState::off    ;
    return ledState;
  }

  static const char* getLedStateText(ELedState ledState)
  {
    return  ledState == ELedState::blink  ? "blink" :
            ledState == ELedState::on     ? "on"    :
            ledState == ELedState::off    ? "off"   : "unknown";
  }

  void execute(unsigned int argc, const char** args, unsigned int idxToFirstArgToHandle)
  {
    if (argc - idxToFirstArgToHandle == 0)
    {
      printReport();
    }
    else
    {
      if (strncmp(args[idxToFirstArgToHandle], "on", strlen("on")) == 0)
      {
        m_ledBlinkTimer->cancelTimer();
        setLed(1);
        printReport();
      }
      else if (strncmp(args[idxToFirstArgToHandle], "off", strlen("off")) == 0)
      {
        m_ledBlinkTimer->cancelTimer();
        setLed(0);
        printReport();
      }
      else if (strncmp(args[idxToFirstArgToHandle], "blink", strlen("blink")) == 0)
      {
        if (!m_ledBlinkTimer->isRunning())
        {
          m_ledBlinkTimer->startTimer();
          toggleLed();
        }
        printReport();
      }
      else
      {
        printUsage();
      }
    }
  }
};

//-----------------------------------------------------------------------------

void setup()
{
  // initialize built in LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);
  // switch the LED off
  digitalWrite(LED_BUILTIN, 0);

  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  //---------------------------------------------------------------------------
  // fun LED control cli command
  //---------------------------------------------------------------------------
  new DbgCliCmd_LedSet();
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
