#pragma once

#include "config.h"
#include "EncoderBase.h"

namespace EncoderTool
{
    class EncPlexBase
    {
     public:
        void attachCallback(encAllCallback_t callback);
        EncoderBase& operator[](size_t idx);

     protected:
        EncPlexBase(unsigned EncoderCount);
        ~EncPlexBase();

        void begin(CountMode mode = CountMode::quarter);
        void begin(encAllCallback_t, CountMode mode = CountMode::quarter);

        const uint32_t encoderCount;
        EncoderBase* encoders;

        encAllCallback_t callback = nullptr;
    };
}
