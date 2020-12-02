#include "EncoderTool.h"
using namespace EncoderTool;

constexpr unsigned encoderCount = 16; // number of attached encoders

constexpr unsigned S0 = 0;            //address pin 0
constexpr unsigned S1 = 1;            //...
constexpr unsigned S2 = 2;            //...
constexpr unsigned S3 = 3;            //address pin 3
constexpr unsigned SIG_A = 4;         //output pin SIG of multiplexer A
constexpr unsigned SIG_B = 5;         //output pin SIG of multiplexer B
                                      //breakout:  https://www.sparkfun.com/products/9056
                                      //datasheet: https://www.ti.com/lit/gpn/CD74HC4067

EncPlex4067 encoders(encoderCount, S0, S1, S2, S3, SIG_A, SIG_B);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    encoders.begin();
}

elapsedMillis stopwatch;

void loop()
{
    encoders.tick();
  
    if (stopwatch > 100)  // display encoder values every 100 ms
    {
        for (unsigned i = 0; i < encoderCount; i++)
        {
            Serial.printf("E%u:%3d ", i, encoders[i].getValue());
        }
        Serial.println();
        stopwatch = 0;
    } 
}
