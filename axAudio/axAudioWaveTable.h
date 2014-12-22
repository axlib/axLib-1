//
//  axBufferPlayer.h
//  MidiSequencer
//
//  Created by Alexandre Arsenault on 2014-11-14.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//

#ifndef __AX_AUDIO_WAVE_TABLE__
#define __AX_AUDIO_WAVE_TABLE__

#include "axAudioUtils.h"

#define axBUFFER_SIZE 2048

class axAudioBuffer;

class axAudioWaveTable
{
public:
    axAudioWaveTable();
//    axAudioWaveTable(axAudioBuffer* buffer);
    
    enum axWaveformType
    {
        axWAVE_TYPE_SINE,
        axWAVE_TYPE_TRIANGLE,
        axWAVE_TYPE_SQUARE,
        axWAVE_TYPE_SAW
    };
    
    void SetWaveformType(const axWaveformType& type);
    
    void ProcessSample(float* out);
    void ProcessBlock(float* out, unsigned long frameCount);
    
    void SetFreq(const double& freq);
    
private:
    
    double _freq = { 200.0 };
    float _data[axBUFFER_SIZE + 1];
    double _cPhase;

    double WaveInterpole(const double& freq,
                         const unsigned int& len,
                         const double& phase);
};

#endif // __AX_AUDIO_WAVE_TABLE__