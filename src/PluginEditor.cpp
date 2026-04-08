#include "PluginProcessor.hpp"
#include "PluginEditor.hpp"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p),
    numCoefficientsSliderAttachment(p.parameters, "numCoefficients", numCoefficientsSlider),
    whisperButtonAttachment(p.parameters, "whisperFlag", whisperButton)
{
    juce::ignoreUnused (processorRef);

    lookAndFeel.setColour(juce::Slider::thumbColourId, juce::Colours::antiquewhite);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    addAndMakeVisible(numCoefficientsSlider);
    numCoefficientsSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    numCoefficientsSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 40, 15);
    numCoefficientsSlider.addListener(this);
    numCoefficientsSlider.setLookAndFeel(&lookAndFeel);

    addAndMakeVisible (numCoefficientsSliderLabel);
    numCoefficientsSliderLabel.setText ("Order", juce::dontSendNotification);
    numCoefficientsSliderLabel.attachToComponent (&numCoefficientsSlider, true); 

    addAndMakeVisible(whisperButton);
    whisperButton.setButtonText("Whisper");
    whisperButton.addListener(this);
    whisperButton.setLookAndFeel(&lookAndFeel);

    setSize (400, 300);

    startTimerHz(30);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

void AudioPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
}

void AudioPluginAudioProcessorEditor::buttonClicked(juce::Button* button)
{

}

void AudioPluginAudioProcessorEditor::buttonStateChanged(juce::Button *button)
{

}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::cornflowerblue);

    processorRef.createAnalyserPlot(spectrogramPath, spectrogramBounds.reduced(4), 20.0f);
    g.drawRect(spectrogramBounds.reduced(3));
    g.setColour (juce::Colours::antiquewhite);
    g.drawFittedText ("Output", spectrogramBounds.reduced (8), juce::Justification::topRight, 1);
    g.strokePath (spectrogramPath, juce::PathStrokeType (1.0));
}

void AudioPluginAudioProcessorEditor::resized()
{
    spectrogramBounds.setBounds(10, 10, getWidth() - 20, 100);

    int sliderBuffer = 20;
    int labelBuffer = 50;
    numCoefficientsSlider.setBounds(labelBuffer, spectrogramBounds.getBottom() + sliderBuffer, getWidth() - sliderBuffer - labelBuffer, 50);

    whisperButton.setBounds(labelBuffer, numCoefficientsSlider.getBottom() + sliderBuffer, 100, 100);

}

void AudioPluginAudioProcessorEditor::timerCallback()
{
    if (processorRef.checkForNewAnalyserData())
    {
        repaint (spectrogramBounds);
    }
}
