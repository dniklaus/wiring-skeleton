/*
 * App.h
 *
 *  Created on: 18.05.2023
 *      Author: didi
 */

#ifndef APP_H_
#define APP_H_

class Indicator;

class App
{
public:
  App();
  virtual ~App();

  void setup();

  void loop();

private:
  Indicator* m_led;
};

#endif /* APP_H_ */
