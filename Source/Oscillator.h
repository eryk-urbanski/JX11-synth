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
    float freq;
    float sampleRate;
    float phaseOffset;
    int sampleIndex;

    void reset()
    {
        sampleIndex = 0;
    }

    float nextSample()
    {
        float output = amplitude * std::sin(
            TWO_PI * sampleIndex * freq / sampleRate + phaseOffset);
        sampleIndex += 1;
        return output;
    }
};