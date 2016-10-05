// ----------------------------------------------------------------------------
// FunctorCallbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "FunctorCallbacks.h"


void FunctorCallbacks::setup()
{
  event_array_.fill(Event());
  removeAllEvents();
  startTimer();
}

FunctorCallbacks functor_isr;

