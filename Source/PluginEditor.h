/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_5F2681BD1F264A8D__
#define __JUCE_HEADER_5F2681BD1F264A8D__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AwesomeizerJuceAudioProcessorEditor  : public AudioProcessorEditor,
                                             public Timer,
                                             public SliderListener,
                                             public ButtonListener
{
public:
    //==============================================================================
    AwesomeizerJuceAudioProcessorEditor (AwesomeizerJuceAudioProcessor* ownerFilter);
    ~AwesomeizerJuceAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
	AwesomeizerJuceAudioProcessor* getProcessor() const
    {
		return static_cast <AwesomeizerJuceAudioProcessor*>(getAudioProcessor());
	}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> m_fAwesomeLevelSld;
    ScopedPointer<TextButton> m_fMonitorAwesomeBtn;
    ScopedPointer<Label> awesome;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AwesomeizerJuceAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_5F2681BD1F264A8D__
