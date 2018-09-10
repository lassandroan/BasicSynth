#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

typedef AudioProcessorValueTreeState::SliderAttachment   SliderAttachment;
typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment   ButtonAttachment;

struct BasicSynthEditor : public AudioProcessorEditor
{
    BasicSynthEditor(BasicSynth&);

    void paint(Graphics&) override;
    void resized() override;

    BasicSynth& processor;

    ComboBox filterMode;
    Slider cutoff;
    Slider resonance;
    Slider drive;
    GroupComponent filterSection;

    Slider roomSize;
    Slider damping;
    Slider width;
    ToggleButton freeze;
    Slider dryLevel;
    Slider wetLevel;
    GroupComponent reverbSection;

    Slider outputGain;
    GroupComponent outputSection;

    MidiKeyboardState keyboardState;
    MidiKeyboardComponent keyboardComponent;

    ComboBox midiInputList;

    // =============================================================================================

    OwnedArray<SliderAttachment>   sliderAttachments;
    OwnedArray<ComboBoxAttachment> comboBoxAttachments;
    OwnedArray<ButtonAttachment>   buttonAttachments;

    SharedResourcePointer<TooltipWindow> tooltipWindow;
};