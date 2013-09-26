/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class AwesomeizerJuceAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AwesomeizerJuceAudioProcessor();
    ~AwesomeizerJuceAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

	//===========================Processing Variables============================
	float m_fAwesomeGain;
	float m_fWarmthGain;
	float m_fMonitorAwesomeStatus;

	float m_fXnLAwesome;
	float m_fXnRAwesome;

	float m_fXnL;
	float m_fXnR;

	float* m_fLeftBuffer;
	float* m_fRightBuffer;

	//===========================UI============================
	enum Parameters{m_fMonitorAwesome, m_fAwesomeLevel, m_fWarmthLevel, totalNumParam};
	bool NeedsUIUpdate(){return UIUpdateFlag;};
	void ClearUIUpdateFlag(){UIUpdateFlag=false;};

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AwesomeizerJuceAudioProcessor)

	float UserParams[totalNumParam];
	bool UIUpdateFlag;  
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
