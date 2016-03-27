#include "MidiHandler.h"

MidiHandler::MidiHandler(const string& filename):
    midifile{filename}
{
    if (midifile.status())
        std::cout<<"Midi OK!"<<std::endl;
}

MidiHandler::~MidiHandler()
{
}