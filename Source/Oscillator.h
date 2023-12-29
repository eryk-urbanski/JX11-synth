/*
  ==============================================================================

    This file contains the basic code for the oscillator.

  ==============================================================================
*/

#pragma once

const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
public:
    float amplitude;
    float inc;
    float phase;

    void reset()
    {
        phase = 0;
    }

    float nextSample()
    {
        phase += inc;
        if (phase >= 1.0f) {
            phase -= 1.0f;
        }

        return amplitude * std::sin(TWO_PI * phase);
    }
};