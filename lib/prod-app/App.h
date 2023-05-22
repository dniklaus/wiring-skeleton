/*
 * App.h
 *
 *  Created on: 18.05.2023
 *      Author: didi
 */

#ifndef APP_H_
#define APP_H_

class SerialCommand;
class Indicator;

class App
{
public:
  App();
  virtual ~App();

  void setup();

  void loop();

private:
  SerialCommand* m_sCmd;
  Indicator* m_led;

private:
  static const char s_termChar;
};

#endif /* APP_H_ */
