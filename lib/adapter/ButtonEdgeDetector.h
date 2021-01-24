/*
 * ButtonEdgeDetector.h
 *
 *  Created on: 17.02.2020
 *      Author: dev
 */

#ifndef LIB_ADAPTER_BUTTONEDGEDETECTOR_H_
#define LIB_ADAPTER_BUTTONEDGEDETECTOR_H_

#include <EdgeDetector.h>
#include <DetectorStrategy.h>

class DbgTrace_Port;

class ButtonEdgeDetector : public EdgeDetector
{
private:
  DbgTrace_Port* m_trPort;
  unsigned long int m_count;

public:
  ButtonEdgeDetector();
  virtual ~ButtonEdgeDetector();

  void onEdge(bool newState);

private:  // forbidden functions
  ButtonEdgeDetector(const ButtonEdgeDetector& src);              // copy constructor
  ButtonEdgeDetector& operator = (const ButtonEdgeDetector& src); // assignment operator
};

#endif /* LIB_ADAPTER_BUTTONEDGEDETECTOR_H_ */
