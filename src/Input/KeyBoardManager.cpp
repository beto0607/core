/* 
 * File:   KeyBoardManager.cpp
 * Author: francisco
 * 
 * Created on 27 de enero de 2014, 18:53
 */

#include <Input/KeyBoardManager.h>
#include <Input/KeyBoardListener.h>
#include <iostream>
#include <map>

using namespace kaikai;

KeyBoardManager::KeyBoardManager() {
    keys_quewe_sem = SDL_CreateSemaphore(1);
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_q,&KeyBoardListener::keyQdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_w,&KeyBoardListener::keyWdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_e,&KeyBoardListener::keyEdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_r,&KeyBoardListener::keyRdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_t,&KeyBoardListener::keyTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_y,&KeyBoardListener::keyYdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_u,&KeyBoardListener::keyUdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_i,&KeyBoardListener::keyIdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_o,&KeyBoardListener::keyOdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_p,&KeyBoardListener::keyPdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_a,&KeyBoardListener::keyAdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_s,&KeyBoardListener::keySdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_d,&KeyBoardListener::keyDdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_f,&KeyBoardListener::keyFdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_g,&KeyBoardListener::keyGdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_h,&KeyBoardListener::keyHdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_j,&KeyBoardListener::keyJdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_k,&KeyBoardListener::keyKdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_l,&KeyBoardListener::keyLdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_z,&KeyBoardListener::keyZdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_x,&KeyBoardListener::keyXdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_c,&KeyBoardListener::keyCdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_v,&KeyBoardListener::keyVdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_b,&KeyBoardListener::keyBdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_n,&KeyBoardListener::keyNdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_m,&KeyBoardListener::keyMdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_1,&KeyBoardListener::key1down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_2,&KeyBoardListener::key2down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_3,&KeyBoardListener::key3down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_4,&KeyBoardListener::key4down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_5,&KeyBoardListener::key5down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_6,&KeyBoardListener::key6down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_7,&KeyBoardListener::key7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_8,&KeyBoardListener::key7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_9,&KeyBoardListener::key7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_0,&KeyBoardListener::key7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F1,&KeyBoardListener::keyF1down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F2,&KeyBoardListener::keyF2down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F3,&KeyBoardListener::keyF3down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F4,&KeyBoardListener::keyF4down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F5,&KeyBoardListener::keyF5down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F6,&KeyBoardListener::keyF6down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F7,&KeyBoardListener::keyF7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F8,&KeyBoardListener::keyF8down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F9,&KeyBoardListener::keyF9down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F10,&KeyBoardListener::keyF10down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F11,&KeyBoardListener::keyF11down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F12,&KeyBoardListener::keyF12down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyENTERdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_ESCAPE,&KeyBoardListener::keyESCAPEdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_SPACE,&KeyBoardListener::keySPACEdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_TAB,&KeyBoardListener::keyTABdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LSHIFT,&KeyBoardListener::keyLEFTSHIFTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LCTRL,&KeyBoardListener::keyLEFTCTRdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LALT,&KeyBoardListener::keyLEFTALTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RSHIFT,&KeyBoardListener::keyRIGTHSHIFTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RCTRL,&KeyBoardListener::keyRIGTHCTRdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RALT,&KeyBoardListener::keyRIGTHALTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_UP,&KeyBoardListener::keyARROWUPdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_DOWN,&KeyBoardListener::keyARROWDOWNdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LEFT,&KeyBoardListener::keyARROWLEFTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RIGHT,&KeyBoardListener::keyARROWRIGHTdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_0,&KeyBoardListener::keyNUMPAD0down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_1,&KeyBoardListener::keyNUMPAD1down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_2,&KeyBoardListener::keyNUMPAD2down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_3,&KeyBoardListener::keyNUMPAD3down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_4,&KeyBoardListener::keyNUMPAD4down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_5,&KeyBoardListener::keyNUMPAD5down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_6,&KeyBoardListener::keyNUMPAD6down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_7,&KeyBoardListener::keyNUMPAD7down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_8,&KeyBoardListener::keyNUMPAD8down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_9,&KeyBoardListener::keyNUMPAD9down));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_DIVIDE,&KeyBoardListener::keyNUMPADSUBdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MULTIPLY,&KeyBoardListener::keyNUMPADMULdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_PLUS,&KeyBoardListener::keyNUMPADPLUSdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MINUS,&KeyBoardListener::keyNUMPADMINUSdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyNUMPADENTERdown));
    function_down_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_SPACE,&KeyBoardListener::keyNUMPADDOTdown));
    
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_q,&KeyBoardListener::keyQup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_w,&KeyBoardListener::keyWup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_e,&KeyBoardListener::keyEup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_r,&KeyBoardListener::keyRup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_t,&KeyBoardListener::keyTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_y,&KeyBoardListener::keyYup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_u,&KeyBoardListener::keyUup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_i,&KeyBoardListener::keyIup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_o,&KeyBoardListener::keyOup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_p,&KeyBoardListener::keyPup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_a,&KeyBoardListener::keyAup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_s,&KeyBoardListener::keySup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_d,&KeyBoardListener::keyDup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_f,&KeyBoardListener::keyFup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_g,&KeyBoardListener::keyGup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_h,&KeyBoardListener::keyHup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_j,&KeyBoardListener::keyJup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_k,&KeyBoardListener::keyKup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_l,&KeyBoardListener::keyLup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_z,&KeyBoardListener::keyZup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_x,&KeyBoardListener::keyXup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_c,&KeyBoardListener::keyCup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_v,&KeyBoardListener::keyVup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_b,&KeyBoardListener::keyBup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_n,&KeyBoardListener::keyNup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_m,&KeyBoardListener::keyMup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_1,&KeyBoardListener::key1up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_2,&KeyBoardListener::key2up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_3,&KeyBoardListener::key3up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_4,&KeyBoardListener::key4up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_5,&KeyBoardListener::key5up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_6,&KeyBoardListener::key6up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_7,&KeyBoardListener::key7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_8,&KeyBoardListener::key7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_9,&KeyBoardListener::key7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_0,&KeyBoardListener::key7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F1,&KeyBoardListener::keyF1up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F2,&KeyBoardListener::keyF2up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F3,&KeyBoardListener::keyF3up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F4,&KeyBoardListener::keyF4up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F5,&KeyBoardListener::keyF5up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F6,&KeyBoardListener::keyF6up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F7,&KeyBoardListener::keyF7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F8,&KeyBoardListener::keyF8up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F9,&KeyBoardListener::keyF9up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F10,&KeyBoardListener::keyF10up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F11,&KeyBoardListener::keyF11up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F12,&KeyBoardListener::keyF12up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyENTERup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_ESCAPE,&KeyBoardListener::keyESCAPEup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_SPACE,&KeyBoardListener::keySPACEup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_TAB,&KeyBoardListener::keyTABup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LSHIFT,&KeyBoardListener::keyLEFTSHIFTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LCTRL,&KeyBoardListener::keyLEFTCTRup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LALT,&KeyBoardListener::keyLEFTALTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RSHIFT,&KeyBoardListener::keyRIGTHSHIFTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RCTRL,&KeyBoardListener::keyRIGTHCTRup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RALT,&KeyBoardListener::keyRIGTHALTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_UP,&KeyBoardListener::keyARROWUPup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_DOWN,&KeyBoardListener::keyARROWDOWNup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LEFT,&KeyBoardListener::keyARROWLEFTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RIGHT,&KeyBoardListener::keyARROWRIGHTup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_0,&KeyBoardListener::keyNUMPAD0up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_1,&KeyBoardListener::keyNUMPAD1up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_2,&KeyBoardListener::keyNUMPAD2up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_3,&KeyBoardListener::keyNUMPAD3up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_4,&KeyBoardListener::keyNUMPAD4up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_5,&KeyBoardListener::keyNUMPAD5up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_6,&KeyBoardListener::keyNUMPAD6up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_7,&KeyBoardListener::keyNUMPAD7up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_8,&KeyBoardListener::keyNUMPAD8up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_9,&KeyBoardListener::keyNUMPAD9up));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_DIVIDE,&KeyBoardListener::keyNUMPADSUBup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MULTIPLY,&KeyBoardListener::keyNUMPADMULup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_PLUS,&KeyBoardListener::keyNUMPADPLUSup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MINUS,&KeyBoardListener::keyNUMPADMINUSup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyNUMPADENTERup));
    function_up_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_SPACE,&KeyBoardListener::keyNUMPADDOTup));
    
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_q,&KeyBoardListener::keyQpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_w,&KeyBoardListener::keyWpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_e,&KeyBoardListener::keyEpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_r,&KeyBoardListener::keyRpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_t,&KeyBoardListener::keyTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_y,&KeyBoardListener::keyYpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_u,&KeyBoardListener::keyUpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_i,&KeyBoardListener::keyIpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_o,&KeyBoardListener::keyOpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_p,&KeyBoardListener::keyPpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_a,&KeyBoardListener::keyApressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_s,&KeyBoardListener::keySpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_d,&KeyBoardListener::keyDpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_f,&KeyBoardListener::keyFpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_g,&KeyBoardListener::keyGpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_h,&KeyBoardListener::keyHpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_j,&KeyBoardListener::keyJpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_k,&KeyBoardListener::keyKpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_l,&KeyBoardListener::keyLpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_z,&KeyBoardListener::keyZpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_x,&KeyBoardListener::keyXpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_c,&KeyBoardListener::keyCpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_v,&KeyBoardListener::keyVpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_b,&KeyBoardListener::keyBpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_n,&KeyBoardListener::keyNpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_m,&KeyBoardListener::keyMpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_1,&KeyBoardListener::key1pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_2,&KeyBoardListener::key2pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_3,&KeyBoardListener::key3pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_4,&KeyBoardListener::key4pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_5,&KeyBoardListener::key5pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_6,&KeyBoardListener::key6pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_7,&KeyBoardListener::key7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_8,&KeyBoardListener::key7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_9,&KeyBoardListener::key7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_0,&KeyBoardListener::key7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F1,&KeyBoardListener::keyF1pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F2,&KeyBoardListener::keyF2pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F3,&KeyBoardListener::keyF3pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F4,&KeyBoardListener::keyF4pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F5,&KeyBoardListener::keyF5pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F6,&KeyBoardListener::keyF6pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F7,&KeyBoardListener::keyF7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F8,&KeyBoardListener::keyF8pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F9,&KeyBoardListener::keyF9pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F10,&KeyBoardListener::keyF10pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F11,&KeyBoardListener::keyF11pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_F12,&KeyBoardListener::keyF12pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyENTERpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_ESCAPE,&KeyBoardListener::keyESCAPEpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_SPACE,&KeyBoardListener::keySPACEpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_TAB,&KeyBoardListener::keyTABpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LSHIFT,&KeyBoardListener::keyLEFTSHIFTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LCTRL,&KeyBoardListener::keyLEFTCTRpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LALT,&KeyBoardListener::keyLEFTALTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RSHIFT,&KeyBoardListener::keyRIGTHSHIFTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RCTRL,&KeyBoardListener::keyRIGTHCTRpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RALT,&KeyBoardListener::keyRIGTHALTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_UP,&KeyBoardListener::keyARROWUPpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_DOWN,&KeyBoardListener::keyARROWDOWNpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_LEFT,&KeyBoardListener::keyARROWLEFTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_RIGHT,&KeyBoardListener::keyARROWRIGHTpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_0,&KeyBoardListener::keyNUMPAD0pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_1,&KeyBoardListener::keyNUMPAD1pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_2,&KeyBoardListener::keyNUMPAD2pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_3,&KeyBoardListener::keyNUMPAD3pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_4,&KeyBoardListener::keyNUMPAD4pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_5,&KeyBoardListener::keyNUMPAD5pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_6,&KeyBoardListener::keyNUMPAD6pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_7,&KeyBoardListener::keyNUMPAD7pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_8,&KeyBoardListener::keyNUMPAD8pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_9,&KeyBoardListener::keyNUMPAD9pressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_DIVIDE,&KeyBoardListener::keyNUMPADSUBpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MULTIPLY,&KeyBoardListener::keyNUMPADMULpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_PLUS,&KeyBoardListener::keyNUMPADPLUSpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_MINUS,&KeyBoardListener::keyNUMPADMINUSpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_ENTER,&KeyBoardListener::keyNUMPADENTERpressed));
    function_pressed_pointer.insert(std::pair<GLint,KeyBoardListenerFunctionPointer>(SDLK_KP_SPACE,&KeyBoardListener::keyNUMPADDOTpressed));
}

KeyBoardManager::~KeyBoardManager() {
}

GLvoid KeyBoardManager::keyDown(SDL_Event _event)
{
    SDL_SemWait(keys_quewe_sem);
    if((GLint)_event.key.repeat == 0)
    {
       keys_quewe.push_back((GLint)_event.key.keysym.sym);
       if(key_pressed.find(_event.key.keysym.sym) != key_pressed.end())
                (((KeyBoardListener*)((key_pressed.find(_event.key.keysym.sym))->second))->*function_down_pointer.find(_event.key.keysym.sym)->second)();
    }
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::keyKeppedPress(SDL_Event _event)
{

}

GLvoid KeyBoardManager::keyUp(SDL_Event _event)
{
    SDL_SemWait(keys_quewe_sem);
    keys_quewe.remove((GLint)_event.key.keysym.sym);
    if(key_release.find(_event.key.keysym.sym) != key_release.end())
        (((KeyBoardListener*)((key_release.find(_event.key.keysym.sym))->second))->*function_up_pointer.find(_event.key.keysym.sym)->second)();
    SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::update()
{
   SDL_SemWait(keys_quewe_sem);
   for(std::list<GLint>::iterator it = keys_quewe.begin();keys_quewe.size() > 0 && it != keys_quewe.end(); it++)
   {
       if(key_release.find(*it) != key_release.end())
          (((KeyBoardListener*)((key_pressed_yet.find(*it))->second))->*function_pressed_pointer.find(*it)->second)();
   }
   SDL_SemPost(keys_quewe_sem);
}

GLvoid KeyBoardManager::addAllKeyListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
    key_release.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
    key_pressed_yet.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addKeyPressedListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addKeyReleaseListener(GLint _key,KeyBoardListener* _listener)
{
    key_release.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}

GLvoid KeyBoardManager::addPressedKeyYetListener(GLint _key,KeyBoardListener* _listener)
{
    key_pressed_yet.insert(std::pair<GLint,KeyBoardListener*>(_key,_listener));
}