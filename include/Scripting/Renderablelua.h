/* 
 * File:   Renderablelua.h
 * Author: francisco
 *
 * Created on 21 de febrero de 2014, 19:06
 */

#ifndef RENDERABLELUA_H
#define	RENDERABLELUA_H

#include "../Unnivelmas_conf.h"

namespace kaikai
{
    class Renderable;
    
    class Renderablelua {
    public:
        Renderablelua(Renderable*);
        virtual ~Renderablelua();
        
        lua_CFunction getX(lua_State* L);
        lua_CFunction getY(lua_State* L);
        
        GLvoid openLUAFile(const GLchar*);
        GLvoid mouseMoved(GLfloat,GLfloat);
        GLvoid keyPressed();
        GLvoid keyRelease();
        GLvoid buttonDown(GLint);
        GLvoid buttonUp(GLint);
        GLvoid axisMove(GLint,GLint);
        GLvoid keyQdown();
        GLvoid keyWdown();
        GLvoid keyEdown();
        GLvoid keyRdown();
        GLvoid keyTdown();
        GLvoid keyYdown();
        GLvoid keyUdown();
        GLvoid keyIdown();
        GLvoid keyOdown();
        GLvoid keyPdown();
        GLvoid keyAdown();
        GLvoid keySdown();
        GLvoid keyDdown();
        GLvoid keyFdown();
        GLvoid keyGdown();
        GLvoid keyHdown();
        GLvoid keyJdown();
        GLvoid keyKdown();
        GLvoid keyLdown();
        GLvoid keyZdown();
        GLvoid keyXdown();
        GLvoid keyCdown();
        GLvoid keyVdown();
        GLvoid keyBdown();
        GLvoid keyNdown();
        GLvoid keyMdown();
        GLvoid key1down();
        GLvoid key2down();
        GLvoid key3down();
        GLvoid key4down();
        GLvoid key5down();
        GLvoid key6down();
        GLvoid key7down();
        GLvoid key8down();
        GLvoid key9down();
        GLvoid key0down();
        GLvoid keyF1down();
        GLvoid keyF2down();
        GLvoid keyF3down();
        GLvoid keyF4down();
        GLvoid keyF5down();
        GLvoid keyF6down();
        GLvoid keyF7down();
        GLvoid keyF8down();
        GLvoid keyF9down();
        GLvoid keyF10down();
        GLvoid keyF11down();
        GLvoid keyF12down();
        GLvoid keyENTERdown();
        GLvoid keyESCAPEdown();
        GLvoid keySPACEdown();
        GLvoid keyTABdown();
        GLvoid keyBLOCKMAYdown();
        GLvoid keyLEFTSHIFTdown();
        GLvoid keyLEFTCTRdown();
        GLvoid keyLEFTALTdown();
        GLvoid keyRIGTHSHIFTdown();
        GLvoid keyRIGTHCTRdown();
        GLvoid keyRIGTHALTdown();
        GLvoid keyBACKSPACEdown();
        GLvoid keyARROWUPdown();
        GLvoid keyARROWDOWNdown();
        GLvoid keyARROWLEFTdown();
        GLvoid keyARROWRIGHTdown();
        GLvoid keyNUMPAD1down();
        GLvoid keyNUMPAD2down();
        GLvoid keyNUMPAD3down();
        GLvoid keyNUMPAD4down();
        GLvoid keyNUMPAD5down();
        GLvoid keyNUMPAD6down();
        GLvoid keyNUMPAD7down();
        GLvoid keyNUMPAD8down();
        GLvoid keyNUMPAD9down();
        GLvoid keyNUMPAD0down();
        GLvoid keyNUMPADPLUSdown();
        GLvoid keyNUMPADMINUSdown();
        GLvoid keyNUMPADSUBdown();
        GLvoid keyNUMPADMULdown();
        GLvoid keyNUMPADENTERdown();
        GLvoid keyNUMPADDOTdown();
        GLvoid keyQup();
        GLvoid keyWup();
        GLvoid keyEup();
        GLvoid keyRup();
        GLvoid keyTup();
        GLvoid keyYup();
        GLvoid keyUup();
        GLvoid keyIup();
        GLvoid keyOup();
        GLvoid keyPup();
        GLvoid keyAup();
        GLvoid keySup();
        GLvoid keyDup();
        GLvoid keyFup();
        GLvoid keyGup();
        GLvoid keyHup();
        GLvoid keyJup();
        GLvoid keyKup();
        GLvoid keyLup();
        GLvoid keyZup();
        GLvoid keyXup();
        GLvoid keyCup();
        GLvoid keyVup();
        GLvoid keyBup();
        GLvoid keyNup();
        GLvoid keyMup();
        GLvoid key1up();
        GLvoid key2up();
        GLvoid key3up();
        GLvoid key4up();
        GLvoid key5up();
        GLvoid key6up();
        GLvoid key7up();
        GLvoid key8up();
        GLvoid key9up();
        GLvoid key0up();
        GLvoid keyF1up();
        GLvoid keyF2up();
        GLvoid keyF3up();
        GLvoid keyF4up();
        GLvoid keyF5up();
        GLvoid keyF6up();
        GLvoid keyF7up();
        GLvoid keyF8up();
        GLvoid keyF9up();
        GLvoid keyF10up();
        GLvoid keyF11up();
        GLvoid keyF12up();
        GLvoid keyENTERup();
        GLvoid keyESCAPEup();
        GLvoid keySPACEup();
        GLvoid keyTABup();
        GLvoid keyBLOCKMAYup();
        GLvoid keyLEFTSHIFTup();
        GLvoid keyLEFTCTRup();
        GLvoid keyLEFTALTup();
        GLvoid keyRIGTHSHIFTup();
        GLvoid keyRIGTHCTRup();
        GLvoid keyRIGTHALTup();
        GLvoid keyBACKSPACEup();
        GLvoid keyARROWUPup();
        GLvoid keyARROWDOWNup();
        GLvoid keyARROWLEFTup();
        GLvoid keyARROWRIGHTup();
        GLvoid keyNUMPAD1up();
        GLvoid keyNUMPAD2up();
        GLvoid keyNUMPAD3up();
        GLvoid keyNUMPAD4up();
        GLvoid keyNUMPAD5up();
        GLvoid keyNUMPAD6up();
        GLvoid keyNUMPAD7up();
        GLvoid keyNUMPAD8up();
        GLvoid keyNUMPAD9up();
        GLvoid keyNUMPAD0up();
        GLvoid keyNUMPADPLUSup();
        GLvoid keyNUMPADMINUSup();
        GLvoid keyNUMPADSUBup();
        GLvoid keyNUMPADMULup();
        GLvoid keyNUMPADENTERup();
        GLvoid keyNUMPADDOTup();
        GLvoid keyQpressed();
        GLvoid keyWpressed();
        GLvoid keyEpressed();
        GLvoid keyRpressed();
        GLvoid keyTpressed();
        GLvoid keyYpressed();
        GLvoid keyUpressed();
        GLvoid keyIpressed();
        GLvoid keyOpressed();
        GLvoid keyPpressed();
        GLvoid keyApressed();
        GLvoid keySpressed();
        GLvoid keyDpressed();
        GLvoid keyFpressed();
        GLvoid keyGpressed();
        GLvoid keyHpressed();
        GLvoid keyJpressed();
        GLvoid keyKpressed();
        GLvoid keyLpressed();
        GLvoid keyZpressed();
        GLvoid keyXpressed();
        GLvoid keyCpressed();
        GLvoid keyVpressed();
        GLvoid keyBpressed();
        GLvoid keyNpressed();
        GLvoid keyMpressed();
        GLvoid key1pressed();
        GLvoid key2pressed();
        GLvoid key3pressed();
        GLvoid key4pressed();
        GLvoid key5pressed();
        GLvoid key6pressed();
        GLvoid key7pressed();
        GLvoid key8pressed();
        GLvoid key9pressed();
        GLvoid key0pressed();
        GLvoid keyF1pressed();
        GLvoid keyF2pressed();
        GLvoid keyF3pressed();
        GLvoid keyF4pressed();
        GLvoid keyF5pressed();
        GLvoid keyF6pressed();
        GLvoid keyF7pressed();
        GLvoid keyF8pressed();
        GLvoid keyF9pressed();
        GLvoid keyF10pressed();
        GLvoid keyF11pressed();
        GLvoid keyF12pressed();
        GLvoid keyENTERpressed();
        GLvoid keyESCAPEpressed();
        GLvoid keySPACEpressed();
        GLvoid keyTABpressed();
        GLvoid keyBLOCKMAYpressed();
        GLvoid keyLEFTSHIFTpressed();
        GLvoid keyLEFTCTRpressed();
        GLvoid keyLEFTALTpressed();
        GLvoid keyRIGTHSHIFTpressed();
        GLvoid keyRIGTHCTRpressed();
        GLvoid keyRIGTHALTpressed();
        GLvoid keyBACKSPACEpressed();
        GLvoid keyARROWUPpressed();
        GLvoid keyARROWDOWNpressed();
        GLvoid keyARROWLEFTpressed();
        GLvoid keyARROWRIGHTpressed();
        GLvoid keyNUMPAD1pressed();
        GLvoid keyNUMPAD2pressed();
        GLvoid keyNUMPAD3pressed();
        GLvoid keyNUMPAD4pressed();
        GLvoid keyNUMPAD5pressed();
        GLvoid keyNUMPAD6pressed();
        GLvoid keyNUMPAD7pressed();
        GLvoid keyNUMPAD8pressed();
        GLvoid keyNUMPAD9pressed();
        GLvoid keyNUMPAD0pressed();
        GLvoid keyNUMPADPLUSpressed();
        GLvoid keyNUMPADMINUSpressed();
        GLvoid keyNUMPADSUBpressed();
        GLvoid keyNUMPADMULpressed();
        GLvoid keyNUMPADENTERpressed();
        GLvoid keyNUMPADDOTpressed();
        
        GLvoid update(GLfloat);
    private:
        Renderable* renderable;
        lua_State* L;
    };
}
#endif	/* RENDERABLELUA_H */

