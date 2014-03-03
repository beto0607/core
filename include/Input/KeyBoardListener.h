/* 
 * File:   KeyBoardListener.h
 * Author: francisco
 *
 * Created on 30 de enero de 2014, 18:10
 */

#ifndef KEYBOARDLISTENER_H
#define	KEYBOARDLISTENER_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class KeyBoardListener {
    public:
        KeyBoardListener();
        virtual ~KeyBoardListener();

        // Down Event
        // Alphabetical Keys
        
        virtual GLvoid keyQdown();
        virtual GLvoid keyWdown();
        virtual GLvoid keyEdown();
        virtual GLvoid keyRdown();
        virtual GLvoid keyTdown();
        virtual GLvoid keyYdown();
        virtual GLvoid keyUdown();
        virtual GLvoid keyIdown();
        virtual GLvoid keyOdown();
        virtual GLvoid keyPdown();
        virtual GLvoid keyAdown();
        virtual GLvoid keySdown();
        virtual GLvoid keyDdown();
        virtual GLvoid keyFdown();
        virtual GLvoid keyGdown();
        virtual GLvoid keyHdown();
        virtual GLvoid keyJdown();
        virtual GLvoid keyKdown();
        virtual GLvoid keyLdown();
        virtual GLvoid keyZdown();
        virtual GLvoid keyXdown();
        virtual GLvoid keyCdown();
        virtual GLvoid keyVdown();
        virtual GLvoid keyBdown();
        virtual GLvoid keyNdown();
        virtual GLvoid keyMdown();
        
        // Up Numerical Keys
        
        virtual GLvoid key1down();
        virtual GLvoid key2down();
        virtual GLvoid key3down();
        virtual GLvoid key4down();
        virtual GLvoid key5down();
        virtual GLvoid key6down();
        virtual GLvoid key7down();
        virtual GLvoid key8down();
        virtual GLvoid key9down();
        virtual GLvoid key0down();
        
        // Functions number keys
        
        virtual GLvoid keyF1down();
        virtual GLvoid keyF2down();
        virtual GLvoid keyF3down();
        virtual GLvoid keyF4down();
        virtual GLvoid keyF5down();
        virtual GLvoid keyF6down();
        virtual GLvoid keyF7down();
        virtual GLvoid keyF8down();
        virtual GLvoid keyF9down();
        virtual GLvoid keyF10down();
        virtual GLvoid keyF11down();
        virtual GLvoid keyF12down();
        
        // Common System Keys
        
        virtual GLvoid keyENTERdown();
        virtual GLvoid keyESCAPEdown();
        virtual GLvoid keySPACEdown();
        virtual GLvoid keyTABdown();
        virtual GLvoid keyBLOCKMAYdown();
        virtual GLvoid keyLEFTSHIFTdown();
        virtual GLvoid keyLEFTCTRdown();
        virtual GLvoid keyLEFTALTdown();
        virtual GLvoid keyRIGTHSHIFTdown();
        virtual GLvoid keyRIGTHCTRdown();
        virtual GLvoid keyRIGTHALTdown();
        virtual GLvoid keyBACKSPACEdown();
        virtual GLvoid keyARROWUPdown();
        virtual GLvoid keyARROWDOWNdown();
        virtual GLvoid keyARROWLEFTdown();
        virtual GLvoid keyARROWRIGHTdown();
        
        // Numpad Keys
        
        virtual GLvoid keyNUMPAD1down();
        virtual GLvoid keyNUMPAD2down();
        virtual GLvoid keyNUMPAD3down();
        virtual GLvoid keyNUMPAD4down();
        virtual GLvoid keyNUMPAD5down();
        virtual GLvoid keyNUMPAD6down();
        virtual GLvoid keyNUMPAD7down();
        virtual GLvoid keyNUMPAD8down();
        virtual GLvoid keyNUMPAD9down();
        virtual GLvoid keyNUMPAD0down();
        virtual GLvoid keyNUMPADPLUSdown();
        virtual GLvoid keyNUMPADMINUSdown();
        virtual GLvoid keyNUMPADSUBdown();
        virtual GLvoid keyNUMPADMULdown();
        virtual GLvoid keyNUMPADENTERdown();
        virtual GLvoid keyNUMPADDOTdown();
        
        // Finish Down Events
        
        
        // UP Event
        // Alphabetical Keys
        
        virtual GLvoid keyQup();
        virtual GLvoid keyWup();
        virtual GLvoid keyEup();
        virtual GLvoid keyRup();
        virtual GLvoid keyTup();
        virtual GLvoid keyYup();
        virtual GLvoid keyUup();
        virtual GLvoid keyIup();
        virtual GLvoid keyOup();
        virtual GLvoid keyPup();
        virtual GLvoid keyAup();
        virtual GLvoid keySup();
        virtual GLvoid keyDup();
        virtual GLvoid keyFup();
        virtual GLvoid keyGup();
        virtual GLvoid keyHup();
        virtual GLvoid keyJup();
        virtual GLvoid keyKup();
        virtual GLvoid keyLup();
        virtual GLvoid keyZup();
        virtual GLvoid keyXup();
        virtual GLvoid keyCup();
        virtual GLvoid keyVup();
        virtual GLvoid keyBup();
        virtual GLvoid keyNup();
        virtual GLvoid keyMup();
        
        // Up Numerical Keys
        
        virtual GLvoid key1up();
        virtual GLvoid key2up();
        virtual GLvoid key3up();
        virtual GLvoid key4up();
        virtual GLvoid key5up();
        virtual GLvoid key6up();
        virtual GLvoid key7up();
        virtual GLvoid key8up();
        virtual GLvoid key9up();
        virtual GLvoid key0up();
        
        // Functions number keys
        
        virtual GLvoid keyF1up();
        virtual GLvoid keyF2up();
        virtual GLvoid keyF3up();
        virtual GLvoid keyF4up();
        virtual GLvoid keyF5up();
        virtual GLvoid keyF6up();
        virtual GLvoid keyF7up();
        virtual GLvoid keyF8up();
        virtual GLvoid keyF9up();
        virtual GLvoid keyF10up();
        virtual GLvoid keyF11up();
        virtual GLvoid keyF12up();
        
        // Common System Keys
        
        virtual GLvoid keyENTERup();
        virtual GLvoid keyESCAPEup();
        virtual GLvoid keySPACEup();
        virtual GLvoid keyTABup();
        virtual GLvoid keyBLOCKMAYup();
        virtual GLvoid keyLEFTSHIFTup();
        virtual GLvoid keyLEFTCTRup();
        virtual GLvoid keyLEFTALTup();
        virtual GLvoid keyRIGTHSHIFTup();
        virtual GLvoid keyRIGTHCTRup();
        virtual GLvoid keyRIGTHALTup();
        virtual GLvoid keyBACKSPACEup();
        virtual GLvoid keyARROWUPup();
        virtual GLvoid keyARROWDOWNup();
        virtual GLvoid keyARROWLEFTup();
        virtual GLvoid keyARROWRIGHTup();
        
        // Numpad Keys
        
        virtual GLvoid keyNUMPAD1up();
        virtual GLvoid keyNUMPAD2up();
        virtual GLvoid keyNUMPAD3up();
        virtual GLvoid keyNUMPAD4up();
        virtual GLvoid keyNUMPAD5up();
        virtual GLvoid keyNUMPAD6up();
        virtual GLvoid keyNUMPAD7up();
        virtual GLvoid keyNUMPAD8up();
        virtual GLvoid keyNUMPAD9up();
        virtual GLvoid keyNUMPAD0up();
        virtual GLvoid keyNUMPADPLUSup();
        virtual GLvoid keyNUMPADMINUSup();
        virtual GLvoid keyNUMPADSUBup();
        virtual GLvoid keyNUMPADMULup();
        virtual GLvoid keyNUMPADENTERup();
        virtual GLvoid keyNUMPADDOTup();
        
        // Finish UP Events
        
        // Pressed Event
        // Alphabetical Keys
        
        virtual GLvoid keyQpressed();
        virtual GLvoid keyWpressed();
        virtual GLvoid keyEpressed();
        virtual GLvoid keyRpressed();
        virtual GLvoid keyTpressed();
        virtual GLvoid keyYpressed();
        virtual GLvoid keyUpressed();
        virtual GLvoid keyIpressed();
        virtual GLvoid keyOpressed();
        virtual GLvoid keyPpressed();
        virtual GLvoid keyApressed();
        virtual GLvoid keySpressed();
        virtual GLvoid keyDpressed();
        virtual GLvoid keyFpressed();
        virtual GLvoid keyGpressed();
        virtual GLvoid keyHpressed();
        virtual GLvoid keyJpressed();
        virtual GLvoid keyKpressed();
        virtual GLvoid keyLpressed();
        virtual GLvoid keyZpressed();
        virtual GLvoid keyXpressed();
        virtual GLvoid keyCpressed();
        virtual GLvoid keyVpressed();
        virtual GLvoid keyBpressed();
        virtual GLvoid keyNpressed();
        virtual GLvoid keyMpressed();
        
        // Up Numerical Keys
        
        virtual GLvoid key1pressed();
        virtual GLvoid key2pressed();
        virtual GLvoid key3pressed();
        virtual GLvoid key4pressed();
        virtual GLvoid key5pressed();
        virtual GLvoid key6pressed();
        virtual GLvoid key7pressed();
        virtual GLvoid key8pressed();
        virtual GLvoid key9pressed();
        virtual GLvoid key0pressed();
        
        // Functions number keys
        
        virtual GLvoid keyF1pressed();
        virtual GLvoid keyF2pressed();
        virtual GLvoid keyF3pressed();
        virtual GLvoid keyF4pressed();
        virtual GLvoid keyF5pressed();
        virtual GLvoid keyF6pressed();
        virtual GLvoid keyF7pressed();
        virtual GLvoid keyF8pressed();
        virtual GLvoid keyF9pressed();
        virtual GLvoid keyF10pressed();
        virtual GLvoid keyF11pressed();
        virtual GLvoid keyF12pressed();
        
        // Common System Keys
        
        virtual GLvoid keyENTERpressed();
        virtual GLvoid keyESCAPEpressed();
        virtual GLvoid keySPACEpressed();
        virtual GLvoid keyTABpressed();
        virtual GLvoid keyBLOCKMAYpressed();
        virtual GLvoid keyLEFTSHIFTpressed();
        virtual GLvoid keyLEFTCTRpressed();
        virtual GLvoid keyLEFTALTpressed();
        virtual GLvoid keyRIGTHSHIFTpressed();
        virtual GLvoid keyRIGTHCTRpressed();
        virtual GLvoid keyRIGTHALTpressed();
        virtual GLvoid keyBACKSPACEpressed();
        virtual GLvoid keyARROWUPpressed();
        virtual GLvoid keyARROWDOWNpressed();
        virtual GLvoid keyARROWLEFTpressed();
        virtual GLvoid keyARROWRIGHTpressed();
        
        // Numpad Keys
        
        virtual GLvoid keyNUMPAD1pressed();
        virtual GLvoid keyNUMPAD2pressed();
        virtual GLvoid keyNUMPAD3pressed();
        virtual GLvoid keyNUMPAD4pressed();
        virtual GLvoid keyNUMPAD5pressed();
        virtual GLvoid keyNUMPAD6pressed();
        virtual GLvoid keyNUMPAD7pressed();
        virtual GLvoid keyNUMPAD8pressed();
        virtual GLvoid keyNUMPAD9pressed();
        virtual GLvoid keyNUMPAD0pressed();
        virtual GLvoid keyNUMPADPLUSpressed();
        virtual GLvoid keyNUMPADMINUSpressed();
        virtual GLvoid keyNUMPADSUBpressed();
        virtual GLvoid keyNUMPADMULpressed();
        virtual GLvoid keyNUMPADENTERpressed();
        virtual GLvoid keyNUMPADDOTpressed();
        
        // Finish Pressed Events
        
    private:
        
    };
}
#endif	/* KEYBOARDLISTENER_H */

