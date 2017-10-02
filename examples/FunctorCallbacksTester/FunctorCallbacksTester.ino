#include <Arduino.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>

#include <Streaming.h>
#include <TimerOne.h>


const int LED_PIN = LED_BUILTIN;

int led_state = LOW;
volatile unsigned long blink_count = 0;
unsigned long loop_count = 0;
FunctorCallbacks::Callback callback = NULL;

void blinkLED()
{
  if (led_state == LOW)
  {
    led_state = HIGH;
    blink_count = blink_count + 1;
  }
  else
  {
    led_state = LOW;
  }
  digitalWrite(LED_PIN,led_state);
}

void newCallback()
{
  Serial << "New callback!" << "\n";
}

void dummyCallback()
{
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  Serial << "FunctorCallbacks::full() = " << FunctorCallbacks::full() << "\n";

  // Fill up all available spots with dummy callback except one for testing
  for (size_t i=0; i<(FunctorCallbacks::CALLBACKS_COUNT-1); ++i)
  {
    FunctorCallbacks::Callback dummy_callback = FunctorCallbacks::add(makeFunctor((Functor0 *)0,dummyCallback));
  }

  Timer1.initialize(150000);
  callback = FunctorCallbacks::add(makeFunctor((Functor0 *)0,blinkLED));
  if (callback)
  {
    Timer1.attachInterrupt(callback);
  }

  Serial << "FunctorCallbacks::full() = " << FunctorCallbacks::full() << "\n";
}

void loop()
{
  unsigned long blink_copy;

  noInterrupts();
  blink_copy = blink_count;
  interrupts();

  Serial << "blink_count = " << blink_copy << "\n";

  Serial << "loop_count = " << loop_count << "\n";
  if (loop_count == 10)
  {
    FunctorCallbacks::Callback new_callback = FunctorCallbacks::add(makeFunctor((Functor0 *)0,newCallback));
    if (new_callback)
    {
      Timer1.attachInterrupt(new_callback);
    }
    else
    {
      Serial << "Could not add new callback, attempting to remove old callback.\n";
      bool removed = FunctorCallbacks::remove(callback);
      if (removed)
      {
        Serial << "Old callback removed, attempting to add new callback again.\n";
        FunctorCallbacks::Callback new_callback = FunctorCallbacks::add(makeFunctor((Functor0 *)0,newCallback));
        if (new_callback)
        {
          Timer1.attachInterrupt(new_callback);
        }
        else
        {
          Serial << "Failed to add new callback a second time. Giving up!\n";
        }
      }
      else
      {
        Serial << "Could not remove old callback. Giving up!\n";
      }
    }
  }
  ++loop_count;
  delay(500);
}
