#include "MidiHandler.h"

MidiHandler::MidiHandler(const string& filename):
    midifile{filename}
{
    if (midifile.status()){
        std::cout<<"Midi OK!"<<std::endl;
        std::cout<<midifile.getEventCount(0)<<std::endl;
        //midifile.joinTracks();
        std::cout<<midifile.getEventCount(0)<<std::endl;
        midifile.linkNotePairs(); // A little wonky, but seems to be useful
        
        int high = 0; 
        int low = 255; // Keeping track of the range of the midi sequence. Ugly magic numbers atm.
        int track = 1;
        for (int i=0; i<midifile[track].size(); i++) {
            if (!midifile[track][i].isNoteOn()) { // Only check messages that are "note-ons"
                continue;
            }
            int tmp = (int) midifile[track][i][1]; //current note
            if(tmp > high) high = tmp;
            if(tmp < low) low = tmp;
            std::cout << midifile[track][i].getDurationInSeconds() // Not very useful in this case, but can be made interesting.
                << '\t' << tmp << '\t' << midifile.getTimeInSeconds(track, i) // To be adjusted to make use of frames? // obs: 1 gameframe = 10 ms
                << std::endl;
        }
        std::cout << "high: " << high << "\t low: " << low << std::endl; 
    }
}
/*TODO for it to be interesting:
 * Check high - low to get interval size
 * Check speed to adjust to number of frames
 * Make something happen per event?
 * Send list of event timestamps to scene
 * 
 * */
MidiHandler::~MidiHandler()
{
}