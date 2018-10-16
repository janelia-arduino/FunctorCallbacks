// ----------------------------------------------------------------------------
// FunctorCallbacks.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef FUNCTOR_CALLBACKS_H
#define FUNCTOR_CALLBACKS_H
#include <Arduino.h>
#include <Functor.h>
#include <IndexedContainer.h>


class FunctorCallback
{
public:
  FunctorCallback();
  FunctorCallback(const Functor0 & callback);
  void attachCallback(const Functor0 & callback);
  void callback();
  boolean callbackIsAttached();
private:
  Functor0 callback_;
};

class FunctorCallbacks
{
public:
  enum{CALLBACKS_COUNT=10};
  typedef void (*Callback)();
  static Callback add(const Functor0 & callback);
  static bool remove(const Callback callback);
  static bool full();
private:
  static IndexedContainer<FunctorCallback,CALLBACKS_COUNT> functor_callbacks_;
  static void callback(int index);
  static void functorCallback0();
  static void functorCallback1();
  static void functorCallback2();
  static void functorCallback3();
  static void functorCallback4();
  static void functorCallback5();
  static void functorCallback6();
  static void functorCallback7();
  static void functorCallback8();
  static void functorCallback9();
};

#endif
