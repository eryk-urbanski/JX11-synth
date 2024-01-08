/*
  ==============================================================================

    This file contains a helper object Voice for handling a single sound played info.

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"
#include "Envelope.h"

struct Voice
{
    int note;
    float saw;
    float period;
    Oscillator osc1;
    Oscillator osc2;
    Envelope env;

    void reset()
    {
        note = 0;
        saw = 0.0f;
        osc1.reset();
        osc2.reset();
        env.reset();
    }

    float render(float input)
    {
        float sample1 = osc1.nextSample();
        float sample2 = osc2.nextSample();
        saw = saw * 0.997f + sample1 - sample2;
        
        float output = saw + input;
        float envelope = env.nextValue();
        return output * envelope;
    }

    void release()
    {
        env.release();
    }
};