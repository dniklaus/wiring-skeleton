#include <DbgCliTopic.h>
#include <DbgCliCmdIndPulse.h>
#include <DbgCliCmdIndSet.h>
#include <Indicator.h>
#include "IndicatorFactory.h"

Indicator* IndicatorFactory::createIndicator(const char* name, const char* description)
{ 
  Indicator* indicator = new Indicator(name, description);

  new DbgCli_Topic(DbgCli_Node::RootNode(), name, description);
  new DbgCliCmd_IndPulse(*indicator);
  new DbgCliCmd_IndSet(*indicator);

  return indicator;
}
