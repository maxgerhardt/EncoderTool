#pragma once

// un-comment the following line if you prefer plain function pointers for callbacks
//#define PLAIN_ENC_CALLBACK

//================================================================================================================

#include <stdint.h>

#if not defined(PLAIN_ENC_CALLBACK)
#    include <functional>
#endif

namespace EncoderTool
{

    // typedefs for the used callbacks

#if defined(PLAIN_ENC_CALLBACK)
    using encPlainCB_t       = void(int value, int delta);
    using encStatefulCB_t    = void(int value, int delta, void* obj);
    using btnPlainCallback_t = void(int_fast8_t btnState);
    using btnStatefulCB_t    = void(int_fast8_t btnState, void* obj);

    using encAllCallback_t   = void(uint_fast8_t channel, int value, int delta);
    using encAllStateCB_t    = void(uint_fast8_t channel, int value, int delta, void* obj);
    using btnAllPlainCB_t    = void(uint_fast8_t channel, int_fast8_t btnState);
    using btnAllStatefulCB_t = void(uint_fast8_t channel, int_fast8_t btnState, void* obj);
#else
    using encPlainCB_t       = std::function<void(int value, int delta)>;                               // encoder value
    using btnPlainCallback_t = std::function<void(int_fast8_t btnState)>;                               // encoder button
    using encAllCallback_t   = std::function<void(uint_fast8_t channel, int32_t value, int32_t delta)>; // all encoder values
    using btnAllCallback_t   = std::function<void(uint_fast8_t channel, int32_t state)>;                // all encoder buttons
#endif
}