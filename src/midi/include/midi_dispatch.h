// ------------------------------------------------------
// Protrekkr
// Based on Juan Antonio Arguelles Rius's NoiseTrekker.
//
// Copyright (C) 2008-2010 Franck Charlet.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  1. Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL FRANCK CHARLET OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.
// ------------------------------------------------------

#ifndef _MIDI_DISPATCH_H_
#define _MIDI_DISPATCH_H_

#if !defined(__NO_MIDI__)

// ------------------------------------------------------
// Constants
enum MIDI_AUTOMATION
{
    MIDI_AUTOMATION_NONE = 0,
    MIDI_AUTOMATION_TRANSPORT_PLAY,
    MIDI_AUTOMATION_TRANSPORT_STOP,
    MIDI_AUTOMATION_TRANSPORT_EDIT,
    MIDI_AUTOMATION_TRANSPORT_RECORD,
    MIDI_AUTOMATION_TRANSPORT_FORWARD,
    MIDI_AUTOMATION_TRANSPORT_REWIND,
    MIDI_AUTOMATION_EDIT_SET_ROW,
    MIDI_AUTOMATION_EDIT_SET_TRACK,
    MIDI_AUTOMATION_EDIT_SET_INSTRUMENT,
    MIDI_AUTOMATION_EDIT_PREVIOUS_TRACK,
    MIDI_AUTOMATION_EDIT_NEXT_TRACK,
    MIDI_AUTOMATION_EDIT_PREVIOUS_ROW,
    MIDI_AUTOMATION_EDIT_NEXT_ROW,
    MIDI_AUTOMATION_EDIT_SET_VOLUME,
    MIDI_AUTOMATION_EDIT_SET_BPM,
    MIDI_AUTOMATION_TRACK_ONOFF,
    MIDI_AUTOMATION_TRACK_SET_PANNING,
    MIDI_AUTOMATION_TRACK_SET_VOLUME,
    MIDI_AUTOMATION_TRACK_SET_LFO_CARRIER,
    MIDI_AUTOMATION_TRACK_SET_CUTOFF,
    MIDI_AUTOMATION_TRACK_SET_RESONANCE,
    MIDI_AUTOMATION_TRACK_SET_REVERB,
    MIDI_AUTOMATION_TRACK_SET_DISTO_THRESHOLD,
    MIDI_AUTOMATION_TRACK_SET_DISTO_CLAMP,
    MIDI_AUTOMATION_303_SET_1_TUNE,
    MIDI_AUTOMATION_303_SET_2_TUNE,
    MIDI_AUTOMATION_303_SET_CURR_TUNE,
    MIDI_AUTOMATION_303_SET_1_CUTOFF,
    MIDI_AUTOMATION_303_SET_2_CUTOFF,
    MIDI_AUTOMATION_303_SET_CURR_CUTOFF,
    MIDI_AUTOMATION_303_SET_1_RESONANCE,
    MIDI_AUTOMATION_303_SET_2_RESONANCE,
    MIDI_AUTOMATION_303_SET_CURR_RESONANCE,
    MIDI_AUTOMATION_303_SET_1_ENVMOD,
    MIDI_AUTOMATION_303_SET_2_ENVMOD,
    MIDI_AUTOMATION_303_SET_CURR_ENVMOD,
    MIDI_AUTOMATION_303_SET_1_DECAY,
    MIDI_AUTOMATION_303_SET_2_DECAY,
    MIDI_AUTOMATION_303_SET_CURR_DECAY,
    MIDI_AUTOMATION_303_SET_1_ACCENT,
    MIDI_AUTOMATION_303_SET_2_ACCENT,
    MIDI_AUTOMATION_303_SET_CURR_ACCENT,
    MIDI_AUTOMATION_303_SET_1_VOLUME,
    MIDI_AUTOMATION_303_SET_2_VOLUME,
    MIDI_AUTOMATION_303_SET_CURR_VOLUME,
    MIDI_AUTOMATION_303_SWITCH,
};

// ------------------------------------------------------
// Structure
typedef struct
{
    MIDI_AUTOMATION Automation;
    int CC;
} MIDI_DISPATCH, *LPMIDI_DISPATCH;

typedef struct
{
    char *Name;
    void (*routine)(int Data);
} MIDI_PTK_CMD, *LPMIDI_PTK_CMD;

typedef struct
{
    int CC;
    int Data;
} MIDI_MESSAGE, *LPMIDI_MESSAGE;

// ------------------------------------------------------
// Variables
MIDI_DISPATCH Midi_Dispatch_Table[];
MIDI_PTK_CMD Str_Midi_Commands[];

// ------------------------------------------------------
// Functions
void Dispatch_Midi_Msg(int CC, int Data);

#endif

#endif
