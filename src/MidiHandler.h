#ifndef MIDIHANDLER_H
#define MIDIHANDLER_H

#include <midifile/MidiFile.h>
#include <iostream>

class MidiHandler
{
public:
    MidiHandler(const string&);
    ~MidiHandler();
private:
    MidiFile midifile;

};

#endif // MIDIHANDLER_H
