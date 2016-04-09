#include "MidiHandler.h"

MidiHandler::MidiHandler(const string& filename):
    midifile{filename}
{
    if (midifile.status()){
        std::cout<<"Midi OK!"<<std::endl;
        std::cout<<midifile.getEventCount(0)<<std::endl;
        //midifile.joinTracks();
        std::cout<<midifile.getEventCount(0)<<std::endl;
        
        int high = 0, low = 100;
        int track = 1;
        for (int i=0; i<midifile[track].size(); i++) {
            if (!midifile[track][i].isNoteOn()) {
                continue;
            }
            int tmp = (int) midifile[track][i][1];
            if(tmp > high) high = tmp;
            if(tmp < low) low = tmp;
            std::cout << midifile[track][i].getDurationInSeconds() 
                << '\t' << tmp << '\t' << midifile[track][i].tick
                << std::endl;
        }
        std::cout << "high: " << high << "\t low: " << low << std::endl; 
    }
}

MidiHandler::~MidiHandler()
{
}