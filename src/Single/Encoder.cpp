#include "Encoder.h"

namespace EncoderTool
{
    // Inline implementation ===============================================

    Encoder::Encoder()
    {
        // Pin::setCallbackMember(&Encoder::doUpdate);
    }

    bool Encoder::begin(int pinA, int pinB, encCallback_t cb, CountMode countMode, int inputMode)
    {
        bool ret = begin(pinA, pinB, countMode, inputMode);
        attachCallback(cb);
        return ret;
    }

    bool Encoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        using namespace HAL;

        if (!iHelper::hasInterrupt(pinA) || !iHelper::hasInterrupt(pinB))
            return false;

        A = pinRegInfo_t(pinA);
        B = pinRegInfo_t(pinB);

        pinMode(A.pin, inputMode);
        pinMode(B.pin, inputMode);

        setCountMode(countMode);
        EncoderBase::begin(directRead(A), directRead(B)); // set start state

        iHelper::attachInterrupt(A.pin, this, CHANGE);
        iHelper::attachInterrupt(B.pin, this, CHANGE);
        return true;
    }

    Encoder::~Encoder()
    {
        iHelper::detachInterrupt(A.pin);
        iHelper::detachInterrupt(B.pin);
    }
 
    void Encoder::doUpdate() { update(HAL::directRead(A), HAL::directRead(B)); }

}