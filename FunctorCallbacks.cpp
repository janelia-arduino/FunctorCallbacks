// ----------------------------------------------------------------------------
// FunctorCallbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "FunctorCallbacks.h"


FunctorCallback::FunctorCallback()
{
}

FunctorCallback::FunctorCallback(const Functor0 & callback)
{
  attachCallback(callback);
}

void FunctorCallback::attachCallback(const Functor0 & callback)
{
  callback_ = callback;
}

void FunctorCallback::callback()
{
  if (callback_)
  {
    callback_();
  }
}

boolean FunctorCallback::callbackIsAttached()
{
  return callback_;
}

IndexedContainer<FunctorCallback,FUNCTOR_CALLBACKS_COUNT> FunctorCallbacks::functor_callbacks_;

Callback FunctorCallbacks::add(const Functor0 & callback)
{
  if (full())
  {
    return NULL;
  }
  FunctorCallback functor_callback(callback);
  int index = functor_callbacks_.add(functor_callback);
  if (index == 0)
  {
    return functorCallback0;
  }
  else if (index == 1)
  {
    return functorCallback1;
  }
  else if (index == 2)
  {
    return functorCallback2;
  }
  else if (index == 3)
  {
    return functorCallback3;
  }
  else if (index == 4)
  {
    return functorCallback4;
  }
  else if (index == 5)
  {
    return functorCallback5;
  }
  else if (index == 6)
  {
    return functorCallback6;
  }
  else if (index == 7)
  {
    return functorCallback7;
  }
  else if (index == 8)
  {
    return functorCallback8;
  }
  else if (index == 9)
  {
    return functorCallback9;
  }
  return NULL;
}

bool FunctorCallbacks::remove(const Callback callback)
{
  if (!callback)
  {
    return false;
  }
  bool removed = false;
  noInterrupts();
  if (callback == functorCallback0)
  {
    removed = functor_callbacks_.remove(0);
  }
  else if (callback == functorCallback1)
  {
    removed = functor_callbacks_.remove(1);
  }
  else if (callback == functorCallback2)
  {
    removed = functor_callbacks_.remove(2);
  }
  else if (callback == functorCallback3)
  {
    removed = functor_callbacks_.remove(3);
  }
  else if (callback == functorCallback4)
  {
    removed = functor_callbacks_.remove(4);
  }
  else if (callback == functorCallback5)
  {
    removed = functor_callbacks_.remove(5);
  }
  else if (callback == functorCallback6)
  {
    removed = functor_callbacks_.remove(6);
  }
  else if (callback == functorCallback7)
  {
    removed = functor_callbacks_.remove(7);
  }
  else if (callback == functorCallback8)
  {
    removed = functor_callbacks_.remove(8);
  }
  else if (callback == functorCallback9)
  {
    removed = functor_callbacks_.remove(9);
  }
  interrupts();
  return removed;
}

bool FunctorCallbacks::full()
{
  return functor_callbacks_.full();
}

void FunctorCallbacks::callback(const int index)
{
  if (functor_callbacks_.indexHasValue(index))
  {
    functor_callbacks_[index].callback();
  }
}

void FunctorCallbacks::functorCallback0()
{
  callback(0);
}

void FunctorCallbacks::functorCallback1()
{
  callback(1);
}

void FunctorCallbacks::functorCallback2()
{
  callback(2);
}

void FunctorCallbacks::functorCallback3()
{
  callback(3);
}

void FunctorCallbacks::functorCallback4()
{
  callback(4);
}

void FunctorCallbacks::functorCallback5()
{
  callback(5);
}

void FunctorCallbacks::functorCallback6()
{
  callback(6);
}

void FunctorCallbacks::functorCallback7()
{
  callback(7);
}

void FunctorCallbacks::functorCallback8()
{
  callback(8);
}

void FunctorCallbacks::functorCallback9()
{
  callback(9);
}
