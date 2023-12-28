/*
  ==============================================================================

    Voice.h
    Created: 28 Dec 2023 5:31:14pm
    Author:  User

  ==============================================================================
*/

#pragma once

struct Voice
{
    int note;
    int velocity;

    void reset()
    {
        note = 0;
        velocity = 0;
    }
};