#include "Arduino.h"
#include "Array.h"
#include "Functor.h"
#include "FunctorCallbacks.h"

#include "Streaming.h"
#include "TimerOne.h"


const int LED_PIN = LED_BUILTIN;

int led_state = LOW;
volatile unsigned long blink_count = 0;

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


void setup()
{
  pinMode(LED_PIN, OUTPUT);

  g_functor_callbacks.attachCallback(0,makeFunctor((Functor0 *)0,blinkLED));

  Timer1.initialize(150000);
  Timer1.attachInterrupt(gFunctorCallback0);

  Serial.begin(9600);
}

void loop()
{
  unsigned long blink_copy;

  noInterrupts();
  blink_copy = blink_count;
  interrupts();

  Serial.print("blink_count = ");
  Serial.println(blink_copy);
  delay(500);
}
