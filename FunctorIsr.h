// ----------------------------------------------------------------------------
// FunctorIsr.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef FUNCTOR_ISR_H
#define FUNCTOR_ISR_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Array.h"
#include "Functor.h"
#include "Streaming.h"


enum{FUNCTOR_ISR_COUNT_MAX=10};

class FunctorIsr
{
public:
  void attachCallback(const Functor0 & callback);
  void callback();
private:
  Functor0 callback_;
};

extern FunctorIsr g_functor_isr;

#endif
