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


enum{FUNCTOR_CALLBACKS_COUNT=10};

void gFunctorCallback0();
void gFunctorCallback1();
void gFunctorCallback2();
void gFunctorCallback3();
void gFunctorCallback4();
void gFunctorCallback5();
void gFunctorCallback6();
void gFunctorCallback7();
void gFunctorCallback8();
void gFunctorCallback9();

class FunctorCallback
{
public:
  void attachCallback(const Functor0 & callback);
  void callback();
  boolean callbackIsAttached();
private:
  Functor0 callback_;
};

class FunctorCallbacks
{
public:
  FunctorCallbacks();
  void attachCallback(const size_t index, const Functor0 & callback);
  void detachCallback(const size_t index);
  boolean callbackIsAttached(const size_t index);
  void callback(const size_t index);
private:
  Array<FunctorCallback,FUNCTOR_CALLBACKS_COUNT> functor_callbacks_;
};

extern FunctorCallbacks g_functor_callbacks;

#endif
