//
//  SoundEditorAudio.cpp
//  MidiSequencer
//
//  Created by Alexandre Arsenault on 2014-11-14.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//

#include "SoundEditorAudio.h"
#include "axAudioBuffer.h"
#include "axAudioBufferPlayer.h"

const double SoundEditorAudio::PLAYING_POSITION_TIME_INTERVAL = 0.2;

SoundEditorAudio* SoundEditorAudio::_instance = nullptr;

SoundEditorAudio* SoundEditorAudio::GetInstance()
{
    return _instance == nullptr ? _instance = new SoundEditorAudio() : _instance;
}

SoundEditorAudio::SoundEditorAudio():
    axAudio()
{
    std::string app_path("/Users/alexarse/Project/axLib/axProjects/SoundEditor/");
    std::string snd_path = app_path + ("808 Samples/snare (41).wav");
    
    _sndBuffer = new axAudioBuffer(snd_path);
    _bufferPlayer = new axAudioBufferPlayer(_sndBuffer);
    _secToSendPlayingEvt = PLAYING_POSITION_TIME_INTERVAL;
}

void SoundEditorAudio::SetPlayingPositionEvent(axEvtFunction(double) fct)
{
    _playingPositionEvt = fct;
}

void SoundEditorAudio::OnPlay(const int& msg)
{
    _bufferPlayer->Play();
}

void SoundEditorAudio::OnChangeFilePath(const std::string& msg)
{
    SetSoundFilePath(msg);
}

void SoundEditorAudio::SetSoundFilePath(const std::string& path)
{
    _sndBuffer->OpenSoundFile(path);
    _bufferPlayer->SetBuffer(_sndBuffer);
}

axAudioBuffer* SoundEditorAudio::GetSoundBuffer()
{
    return _sndBuffer;
}

int SoundEditorAudio::CallbackAudio(const float* input,
                                    float* output,
                                    unsigned long frameCount)
{
    bool was_playing = _bufferPlayer->IsPlaying();
    
    _bufferPlayer->ProcessBlock(output, frameCount);

    bool is_playing = _bufferPlayer->IsPlaying();
    
    if(is_playing || was_playing != is_playing)
    {
        _secToSendPlayingEvt -= (frameCount / 44100.0);
        
        if(_secToSendPlayingEvt)
        {
            if(_playingPositionEvt)
            {
                _playingPositionEvt(_bufferPlayer->GetCursorPercentPosition());
            }
            
            _secToSendPlayingEvt = PLAYING_POSITION_TIME_INTERVAL;
        }
    }
    
    return 0;
}
