#include "MidiHandler.h"

MidiHandler::MidiHandler(const string& filename):
    midifile{filename}
{
    if (midifile.status()){
        std::cout<<"Midi OK!"<<std::endl;
        std::cout<<midifile.getEventCount(0)<<std::endl;
        midifile.joinTracks();
        std::cout<<midifile.getEventCount(0)<<std::endl;
        
    }
}

MidiHandler::~MidiHandler()
{
}