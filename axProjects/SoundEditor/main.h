#ifndef __MIDI_SEUENCER__
#define __MIDI_SEUENCER__

#include "axLib.h"

class axWaveform;
class axWaveformNavigator;

class SoundEditor: public axPanel
{
public:
	SoundEditor(axApp* app,
                axWindow* parent,
                const axRect& rect);
    
    void SetPlayAudioEvent(axEvtFunction(int) fct);
    void SetChangePathAudioEvent(axEvtFunction(std::string) fct);
    
    axEVENT(axButtonMsg, OnPlayButton);
    axEVENT(axButtonMsg, OnOpenDialog);
    axEVENT(axSliderMsg, OnZoomValue);
    axEVENT(axSliderMsg, OnSamplePosition);
    axEVENT(double, OnWaveformNavigator);
    
private:
    axWaveform* _waveform;
    axWaveformNavigator* _waveformNavig;
	// Events.
	virtual void OnPaint();
    void OnPlayButton(const axButtonMsg& msg);
    void OnOpenDialog(const axButtonMsg& msg);
    void OnZoomValue(const axSliderMsg& msg);
    void OnSamplePosition(const axSliderMsg& msg);
    void OnWaveformNavigator(const double&  left_border);
    
    axEvtFunction(int) _evtPlayAudio;
    axEvtFunction(std::string) _evtChangePathAudio;
};


class axMain
{
public:
    axMain();
    static void MainEntryPoint(axApp* app);
};


#endif // __MIDI_SEUENCER__