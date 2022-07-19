#pragma once

#include "../EncoderBase.h"
//#include "../HAL/iPin_t.h"
#include "../HAL/directReadWrite.h"
#include "../HAL/pinInterruptHelper.h"

namespace EncoderTool
{
    /***********************************************************************
     *  Simple interupt based encoder implementation which reads
     *  phase A and B from two interupt capable pins
     ************************************************************************/
    class Encoder : public EncoderBase
    {
     public:
        Encoder();
        ~Encoder();

        bool begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        bool begin(int pinA, int pinB, encCallback_t cb, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        void doUpdate();

     protected:
        HAL::pinRegInfo_t A, B;

        using iHelper = HAL::PinInterruptHelper<Encoder, &Encoder::doUpdate>;
    };
} // namespace EncoderTool