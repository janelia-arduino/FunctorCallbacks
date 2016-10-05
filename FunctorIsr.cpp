// ----------------------------------------------------------------------------
// FunctorIsr.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "FunctorIsr.h"


void FunctorIsr::setup()
{
  event_array_.fill(Event());
  removeAllEvents();
  startTimer();
}

FunctorIsr functor_isr;

