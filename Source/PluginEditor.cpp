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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AwesomeizerJuceAudioProcessorEditor::AwesomeizerJuceAudioProcessorEditor (AwesomeizerJuceAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (m_fAwesomeLevelSld = new Slider ("Awesome Level"));
    m_fAwesomeLevelSld->setTooltip ("Ammount of stereo spread remixed in");
    m_fAwesomeLevelSld->setRange (0.01, 0.5, 0.01);
    m_fAwesomeLevelSld->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_fAwesomeLevelSld->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    m_fAwesomeLevelSld->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    m_fAwesomeLevelSld->setColour (Slider::textBoxTextColourId, Colours::white);
    m_fAwesomeLevelSld->setColour (Slider::textBoxBackgroundColourId, Colours::black);
    m_fAwesomeLevelSld->addListener (this);

    addAndMakeVisible (m_fMonitorAwesomeBtn = new TextButton ("Monitor Only Awesomeness"));
    m_fMonitorAwesomeBtn->setButtonText ("Only Awesomeness");
    m_fMonitorAwesomeBtn->addListener (this);

    addAndMakeVisible (awesome = new Label ("Awesome",
                                            "Awesome"));
    awesome->setFont (Font (15.00f, Font::plain));
    awesome->setJustificationType (Justification::centredTop);
    awesome->setEditable (false, false, false);
    awesome->setColour (Label::textColourId, Colours::white);
    awesome->setColour (TextEditor::textColourId, Colours::black);
    awesome->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	startTimer(200);
	m_fMonitorAwesomeBtn->setClickingTogglesState(true);
    //[/Constructor]
}

AwesomeizerJuceAudioProcessorEditor::~AwesomeizerJuceAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_fAwesomeLevelSld = nullptr;
    m_fMonitorAwesomeBtn = nullptr;
    awesome = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AwesomeizerJuceAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    g.setColour (Colours::white);
    g.setFont (Font (30.70f, Font::bold | Font::italic));
    g.drawText ("Awesome-izer",
                84, 20, 212, 62,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AwesomeizerJuceAudioProcessorEditor::resized()
{
    m_fAwesomeLevelSld->setBounds (24, 112, 208, 72);
    m_fMonitorAwesomeBtn->setBounds (184, 112, 112, 16);
    awesome->setBounds (48, 88, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AwesomeizerJuceAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	AwesomeizerJuceAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_fAwesomeLevelSld)
    {
        //[UserSliderCode_m_fAwesomeLevelSld] -- add your slider handling code here..
        ourProcessor->setParameter(AwesomeizerJuceAudioProcessor::m_fAwesomeLevel, (float)m_fAwesomeLevelSld->getValue());
        //[/UserSliderCode_m_fAwesomeLevelSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AwesomeizerJuceAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	AwesomeizerJuceAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_fMonitorAwesomeBtn)
    {
        //[UserButtonCode_m_fMonitorAwesomeBtn] -- add your button handler code here..
        ourProcessor->setParameter(AwesomeizerJuceAudioProcessor::m_fMonitorAwesome, (float)m_fMonitorAwesomeBtn->getToggleState());
        //[/UserButtonCode_m_fMonitorAwesomeBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AwesomeizerJuceAudioProcessorEditor::timerCallback()
{
     AwesomeizerJuceAudioProcessor* ourProcessor = getProcessor();
     //exchange any data you want between UI elements and the Plugin "ourProcessor"

	if(ourProcessor->NeedsUIUpdate())
	{
		m_fMonitorAwesomeBtn->setToggleState(1.0f == ourProcessor->getParameter(AwesomeizerJuceAudioProcessor::m_fMonitorAwesome), false);
		m_fAwesomeLevelSld->setValue(ourProcessor->getParameter(AwesomeizerJuceAudioProcessor::m_fAwesomeLevel), juce::dontSendNotification);
		ourProcessor->ClearUIUpdateFlag();
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AwesomeizerJuceAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AwesomeizerJuceAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000">
    <TEXT pos="84 20 212 62" fill="solid: ffffffff" hasStroke="0" text="Awesome-izer"
          fontname="Default font" fontsize="30.699999999999999" bold="1"
          italic="1" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Awesome Level" id="c7ac08ecbf827be7" memberName="m_fAwesomeLevelSld"
          virtualName="" explicitFocusOrder="0" pos="24 112 208 72" tooltip="Ammount of stereo spread remixed in"
          rotaryslideroutline="66ffffff" textboxtext="ffffffff" textboxbkgd="ff000000"
          min="0.01" max="0.5" int="0.01" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Monitor Only Awesomeness" id="27b717b6dc2e6a0f" memberName="m_fMonitorAwesomeBtn"
              virtualName="" explicitFocusOrder="0" pos="184 112 112 16" buttonText="Only Awesomeness"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Awesome" id="c77cf71c666d6e2f" memberName="awesome" virtualName=""
         explicitFocusOrder="0" pos="48 88 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Awesome" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
