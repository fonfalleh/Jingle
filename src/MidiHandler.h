#ifndef MIDIHANDLER_H
#define MIDIHANDLER_H

#include <midifile/MidiFile.h>
#include <midifile/MidiEvent.h>
#include <iostream>
#include <list>

class MidiHandler
{
public:
    MidiHandler(const string&);
    ~MidiHandler();
private:
    MidiFile midifile;
    std::list<int> frameList; // List of interesting midievents

};

#endif // MIDIHANDLER_H
