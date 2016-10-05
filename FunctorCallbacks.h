// ----------------------------------------------------------------------------
// FunctorCallbacks.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef FUNCTOR_CALLBACKS_H
#define FUNCTOR_CALLBACKS_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Array.h"
#include "Functor.h"
#include "Streaming.h"


enum{FUNCTOR_CALLBACKS_COUNT_MAX=10};

class FunctorCallbacks
{
public:
  void attachCallback(const Functor0 & callback);
  void callback();
private:
  Functor0 callback_;
};

extern FunctorCallbacks g_functor_callbacks;

#endif
