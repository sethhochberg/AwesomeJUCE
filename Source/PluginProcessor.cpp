/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AudioUtil.h"


//==============================================================================
AwesomeizerJuceAudioProcessor::AwesomeizerJuceAudioProcessor()
{
	UserParams[m_fAwesomeLevel] = 0.25f; 
	UserParams[m_fWarmthLevel] = 1.0f;
	UserParams[m_fMonitorAwesome] = 0.0f;

	m_fAwesomeGain = UserParams[m_fAwesomeLevel];
	m_fWarmthGain = calcLogControl(UserParams[m_fWarmthLevel]);
	m_fMonitorAwesomeStatus = UserParams[m_fMonitorAwesome];

	UIUpdateFlag = true; 
}

AwesomeizerJuceAudioProcessor::~AwesomeizerJuceAudioProcessor()
{
}

//==============================================================================
const String AwesomeizerJuceAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int AwesomeizerJuceAudioProcessor::getNumParameters()
{
	return totalNumParam;
}

float AwesomeizerJuceAudioProcessor::getParameter (int index)
{
    switch(index)
	 {
		case m_fMonitorAwesome:
			return UserParams[m_fMonitorAwesome];
		case m_fAwesomeLevel:
			UserParams[m_fAwesomeLevel] = m_fAwesomeGain;
			return UserParams[m_fAwesomeLevel];
		case m_fWarmthLevel:
			UserParams[m_fWarmthLevel] = m_fWarmthGain;
			return UserParams[m_fWarmthLevel];
		default: return 0.0f;//invalid index
	}
}

void AwesomeizerJuceAudioProcessor::setParameter (int index, float newValue)
{
	switch(index)
	 {
		case m_fMonitorAwesome:
			UserParams[m_fMonitorAwesome] = newValue;
			break;
		case m_fAwesomeLevel:
			UserParams[m_fAwesomeLevel] = newValue;
			break;
		case m_fWarmthLevel:
			UserParams[m_fWarmthLevel] = newValue;
			break;
		default: return;
	}
}

const String AwesomeizerJuceAudioProcessor::getParameterName (int index)
{
    switch(index)
	{
		case m_fAwesomeLevel: return "Awesome Level";
		case m_fWarmthLevel: return "Warmth Level";
		case m_fMonitorAwesome: return "Monitor Only Awesomeness";
		default: return String::empty;
	}
}

const String AwesomeizerJuceAudioProcessor::getParameterText (int index)
{
    if(index>=0 && index<totalNumParam)
		return String(UserParams[index]);
	else 
		return String::empty;
}

const String AwesomeizerJuceAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String AwesomeizerJuceAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool AwesomeizerJuceAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool AwesomeizerJuceAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool AwesomeizerJuceAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AwesomeizerJuceAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AwesomeizerJuceAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double AwesomeizerJuceAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AwesomeizerJuceAudioProcessor::getNumPrograms()
{
    return 0;
}

int AwesomeizerJuceAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AwesomeizerJuceAudioProcessor::setCurrentProgram (int index)
{
}

const String AwesomeizerJuceAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void AwesomeizerJuceAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AwesomeizerJuceAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AwesomeizerJuceAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void AwesomeizerJuceAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
	m_fAwesomeGain = UserParams[m_fAwesomeLevel];
	m_fMonitorAwesomeStatus = UserParams[m_fMonitorAwesome];

    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
		const int iNumSamples = buffer.getNumSamples();
		m_fLeftBuffer = buffer.getSampleData(0);
		m_fRightBuffer = buffer.getSampleData(1);
		
		for (int i = 0; i < iNumSamples; i++)
		{
			//grab single samples
			m_fXnL = m_fLeftBuffer[i];
			m_fXnR = m_fRightBuffer[i];

			//isolate difference between channels
			m_fXnLAwesome = (m_fXnL + (m_fXnR * -1.0)) * m_fAwesomeGain;
			m_fXnL += m_fXnLAwesome;

			m_fXnRAwesome = (m_fXnR + (m_fXnL * -1.0)) * m_fAwesomeGain;
			m_fXnR += m_fXnRAwesome;

			//route output to buffers 
			if(m_fMonitorAwesomeStatus == 1.0f)
			{
				m_fLeftBuffer[i] = m_fXnLAwesome;
				m_fRightBuffer[i] = m_fXnRAwesome; 
			}
			else
			{
				m_fLeftBuffer[i] = m_fXnL;
				m_fRightBuffer[i] = m_fXnR;
			}
		}
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool AwesomeizerJuceAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AwesomeizerJuceAudioProcessor::createEditor()
{
    return new AwesomeizerJuceAudioProcessorEditor (this);
}

//==============================================================================
void AwesomeizerJuceAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	//Make sure public data is current (through any param conversions)

	XmlElement root("Root");
	XmlElement *el;
	el = root.createNewChildElement("AwesomeLevel");
	el->addTextElement(String(UserParams[m_fAwesomeLevel]));
	el = root.createNewChildElement("MonitorAwesome");
	el->addTextElement(String(UserParams[m_fMonitorAwesome]));
	el = root.createNewChildElement("WarmthLevel");
	el->addTextElement(String(UserParams[m_fWarmthLevel]));
	copyXmlToBinary(root,destData);
}

void AwesomeizerJuceAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.

	XmlElement* pRoot = getXmlFromBinary(data,sizeInBytes);

	if(pRoot!=NULL)
	{
		forEachXmlChildElement((*pRoot),pChild)
		{
			if(pChild->hasTagName("AwesomeLevel"))
			{
				String text = pChild->getAllSubText();
				setParameter(m_fAwesomeLevel,text.getFloatValue());
			}
			else if(pChild->hasTagName("MonitorAwesome"))
			{
				String text = pChild->getAllSubText();
				setParameter(m_fMonitorAwesome,text.getFloatValue());
			}
			else if(pChild->hasTagName("WarmthLevel"))
			{
				String text = pChild->getAllSubText();
				setParameter(m_fWarmthLevel,text.getFloatValue());
			}
		}
		delete pRoot;
		UIUpdateFlag = true; //Request UI update
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AwesomeizerJuceAudioProcessor();
}