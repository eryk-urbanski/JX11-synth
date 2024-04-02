/*
  ==============================================================================

    This file contains the basic code for the synthesizer.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();

    float noiseMix;
    float oscMix;
    float envAttack, envDecay, envSustain, envRelease;
    float detune;
    float tune;

    void allocateResources(double sampleRate, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);

private:
    void noteOn(int note, int velocity);
    void noteOff(int note);

    float calcPeriod(int note) const;

    float sampleRate;
    Voice voice;
    NoiseGenerator noiseGen;
};