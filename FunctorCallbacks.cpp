// ----------------------------------------------------------------------------
// FunctorCallbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "FunctorCallbacks.h"


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

FunctorCallbacks::FunctorCallbacks()
{
  functor_callbacks_.fill(FunctorCallback());
}

void FunctorCallbacks::attachCallback(const size_t index, const Functor0 & callback)
{
  if (index >= FUNCTOR_CALLBACKS_COUNT)
  {
    return;
  }
  functor_callbacks_[index].attachCallback(callback);
}

void FunctorCallbacks::detachCallback(const size_t index)
{
  if (index >= FUNCTOR_CALLBACKS_COUNT)
  {
    return;
  }
  functor_callbacks_[index] = FunctorCallback();
}

boolean FunctorCallbacks::callbackIsAttached(const size_t index)
{
  if (index >= FUNCTOR_CALLBACKS_COUNT)
  {
    return false;
  }
  return functor_callbacks_[index].callbackIsAttached();
}

void FunctorCallbacks::callback(const size_t index)
{
  if (index >= FUNCTOR_CALLBACKS_COUNT)
  {
    return;
  }
  functor_callbacks_[index].callback();
}

FunctorCallbacks g_functor_callbacks;

void gFunctorCallback0()
{
  g_functor_callbacks.callback(0);
}

