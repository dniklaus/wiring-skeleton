#pragma once

class Indicator;

class IndicatorFactory
{
public:
  IndicatorFactory() {}
  virtual ~IndicatorFactory() {}

  static Indicator* createIndicator(const char* name, const char* description);
};
