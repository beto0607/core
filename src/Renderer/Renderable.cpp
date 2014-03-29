
#include <Renderer/Renderable.h>
#include <Animation/Animation.h>
#include <Core/Core.h>
#include <Log/Logger.h>
#include <Scripting/Renderablelua.h>
#include <Scene/Scene.h>
#include <sstream>

using namespace kaikai;

Renderable::Renderable():MouseEventListener(),TimeEventListener(),JoystickListener(), KeyBoardListener(){
    animation = new Animation();
    scale_matrix = glm::mat4(1.0f);
    position_matrix = glm::mat4(1.0f);
    lua = new Renderablelua(this);
    width = 0;
    heigth = 0;
    radius = 0;
}

Renderable::~Renderable() {
    lua->~Renderablelua();
}

GLvoid Renderable::move(GLfloat x, GLfloat y)
{
    position_matrix = glm::mat4(1.0,0.0,0.0,x,
                                0.0,1.0,0.0,y,
                                0.0,0.0,1.0,0.0,
                                0.0,0.0,0.0,1.0);
}

GLvoid Renderable::move(GLfloat x, GLfloat y, GLfloat z)
{
    position_matrix = glm::mat4(1.0,0.0,0.0,x,
                                0.0,1.0,0.0,y,
                                0.0,0.0,1.0,z,
                                0.0,0.0,0.0,1.0);
}
            
GLfloat Renderable::getX()
{
    return position_matrix[0][3];
}

GLvoid Renderable::setX(GLfloat x)
{
    position_matrix[0][3] = x;
}
            
GLfloat Renderable::getY()
{
    return position_matrix[1][3];
}

GLvoid Renderable::setY(GLfloat y)
{
    position_matrix[1][3] = y;
}

GLfloat Renderable::getZ()
{
    return position_matrix[2][3];
}

GLvoid Renderable::setZ(GLfloat z)
{
    position_matrix[2][3] = z;
}

GLvoid Renderable::scale(GLfloat _scale)
{
    this->scale_matrix = glm::mat4(_scale,0.0,0.0,0.0,
                                   0.0,_scale,0.0,0.0,
                                   0.0,0.0,_scale,0.0,
                                   0.0,0.0,0.0,1);
}

GLfloat* Renderable::getScale()
{
    return glm::value_ptr(this->scale_matrix);
}

GLfloat* Renderable::getRotation()
{
    return glm::value_ptr(this->angle_matrix);
}

GLfloat* Renderable::getPosition()
{
    return glm::value_ptr(this->position_matrix);
}

GLfloat* Renderable::getProjectionMatrix()
{
    return glm::value_ptr(projection_matrix);
}

glm::vec2 Renderable::getTopRigth()
{
    return glm::vec2(position_matrix[0][2] + width,position_matrix[1][2] - heigth);
}
                        
glm::vec2 Renderable::getTopLeft()
{
    return glm::vec2(position_matrix[0][2] - width,position_matrix[1][2] - heigth);
}

glm::vec2 Renderable::getBottomRigth()
{
    return glm::vec2(position_matrix[0][2] + width,position_matrix[1][2] + heigth);
}

glm::vec2 Renderable::getBottomLeft()
{
    return glm::vec2(position_matrix[0][2] - width,position_matrix[1][2] + heigth);
}

GLfloat Renderable::getRadius()
{
    return radius;
}

GLfloat Renderable::getHeight()
{
        return heigth;
}
                        
GLfloat Renderable::getWidth()
{
        return width;
}

GLuint Renderable::getVertexBufferID()
{
    return vertex_id;
}

GLuint Renderable::getUVBufferID()
{
    return uv_id;
}

GLvoid Renderable::setName(std::string _name)
{
    name = _name;
}

std::string Renderable::getName()
{
    return name;
}

Shape* Renderable::getShape()
{
    return shape;
}

GLfloat Renderable::getTop()
{
    return position_matrix[1][2] - heigth;
}

GLfloat Renderable::getBottom()
{
    return position_matrix[1][2] + heigth;
}

GLfloat Renderable::getRigth()
{
    return position_matrix[0][2] + width;
}

GLfloat Renderable::getLeft()
{
    return position_matrix[0][2] - width;
}

GLvoid Renderable::topCollision(Renderable* _collider)
{

}

GLvoid Renderable::bottomCollision(Renderable* _collider)
{

}

GLvoid Renderable::leftCollision(Renderable* _collider)
{

}

GLvoid Renderable::rightCollision(Renderable* _collider)
{

}

GLvoid Renderable::setAnimation(Animation* _animation)
{
    animation = _animation;
}
                        
GLvoid Renderable::drawRenderable(Scene* _scene)
{
    animation->next(this);
    this->draw(_scene);
}

GLvoid Renderable::setUVCoordinates(GLfloat* new_uv_coordinates)
{
    glBindBuffer(GL_ARRAY_BUFFER,uv_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*8, new_uv_coordinates, GL_STATIC_DRAW);
}

GLvoid Renderable::play(const GLchar* _name)
{
    animation->play(_name);
}

GLvoid Renderable::openLUAfile(const GLchar* _filename)
{
    lua->openLUAFile(_filename);
}

GLvoid Renderable::setMaterial(Material* _mat)
{
    this->material = _mat;
}

GLvoid Renderable::mouseMoved(GLfloat x, GLfloat y)
{
    lua->mouseMoved(x,y);
}

GLvoid Renderable::keyPressed()
{
    lua->keyPressed();
}

GLvoid Renderable::keyRelease()
{
    lua->keyRelease();
}

GLvoid Renderable::buttonDown(GLint)
{
    //lua->buttonDown
}
GLvoid Renderable::buttonUp(GLint){ }
GLvoid Renderable::axisMove(GLint,GLint){ }

GLvoid Renderable::keyQdown()
{
    lua->keyQdown();
}

GLvoid Renderable::keyWdown()
{
    lua->keyWdown();
}

GLvoid Renderable::keyEdown()
{
    lua->keyEdown();
}

GLvoid Renderable::keyRdown()
{
    lua->keyRdown();
}

GLvoid Renderable::keyTdown()
{
    lua->keyTdown();
}

GLvoid Renderable::keyYdown()
{
    lua->keyYdown();
}

GLvoid Renderable::keyUdown()
{
    lua->keyUdown();
}

GLvoid Renderable::keyIdown()
{
    lua->keyIdown();
}

GLvoid Renderable::keyOdown()
{
    lua->keyOdown();
}

GLvoid Renderable::keyPdown()
{
    lua->keyPdown();
}

GLvoid Renderable::keyAdown()
{
    lua->keyAdown();
}

GLvoid Renderable::keySdown()
{
    lua->keySdown();
}

GLvoid Renderable::keyDdown()
{
    lua->keyDdown();
}

GLvoid Renderable::keyFdown()
{
    lua->keyFdown();
}

GLvoid Renderable::keyGdown()
{
    lua->keyGdown();
}

GLvoid Renderable::keyHdown()
{
    lua->keyHdown();
}

GLvoid Renderable::keyJdown()
{
    lua->keyJdown();
}

GLvoid Renderable::keyKdown()
{
    lua->keyKdown();
}

GLvoid Renderable::keyLdown()
{
    lua->keyLdown();
}

GLvoid Renderable::keyZdown()
{
    lua->keyZdown();
}

GLvoid Renderable::keyXdown()
{
    lua->keyXdown();
}

GLvoid Renderable::keyCdown()
{
    lua->keyCdown();
}

GLvoid Renderable::keyVdown()
{
    lua->keyVdown();
}

GLvoid Renderable::keyBdown()
{
    lua->keyBdown();
}

GLvoid Renderable::keyNdown()
{
    lua->keyNdown();
}

GLvoid Renderable::keyMdown()
{
    lua->keyMdown();
}

GLvoid Renderable::key1down()
{
    lua->key1down();
}

GLvoid Renderable::key2down()
{
    lua->key2down();
}

GLvoid Renderable::key3down()
{
    lua->key3down();
}

GLvoid Renderable::key4down()
{
    lua->key4down();
}

GLvoid Renderable::key5down()
{
    lua->key5down();
}

GLvoid Renderable::key6down()
{
    lua->key6down();
}

GLvoid Renderable::key7down()
{
    lua->key7down();
}

GLvoid Renderable::key8down()
{
    lua->key8down();
}

GLvoid Renderable::key9down()
{
    lua->key9down();
}

GLvoid Renderable::key0down()
{
    lua->key0down();
}

GLvoid Renderable::keyF1down(){    lua->keyF1down();}
GLvoid Renderable::keyF2down(){    lua->keyF2down();}
GLvoid Renderable::keyF3down(){    lua->keyF3down();}
GLvoid Renderable::keyF4down(){    lua->keyF4down();}
GLvoid Renderable::keyF5down(){    lua->keyF5down();}
GLvoid Renderable::keyF6down(){    lua->keyF6down();}
GLvoid Renderable::keyF7down(){    lua->keyF7down();}
GLvoid Renderable::keyF8down(){    lua->keyF8down();}
GLvoid Renderable::keyF9down(){    lua->keyF9down();}
GLvoid Renderable::keyF10down(){    lua->keyF10down();}
GLvoid Renderable::keyF11down(){    lua->keyF11down();}
GLvoid Renderable::keyF12down(){    lua->keyF12down();}
GLvoid Renderable::keyENTERdown(){    lua->keyENTERdown();}
GLvoid Renderable::keyESCAPEdown(){    lua->keyESCAPEdown();}
GLvoid Renderable::keySPACEdown(){    lua->keySPACEdown();}
GLvoid Renderable::keyTABdown(){    lua->keyTABdown();}
GLvoid Renderable::keyBLOCKMAYdown(){    lua->keyBLOCKMAYdown();}
GLvoid Renderable::keyLEFTSHIFTdown(){    lua->keyLEFTSHIFTdown();}
GLvoid Renderable::keyLEFTCTRdown(){    lua->keyLEFTCTRdown();}
GLvoid Renderable::keyLEFTALTdown(){    lua->keyLEFTALTdown();}
GLvoid Renderable::keyRIGTHSHIFTdown(){    lua->keyRIGTHSHIFTdown();}
GLvoid Renderable::keyRIGTHCTRdown(){    lua->keyRIGTHCTRdown();}
GLvoid Renderable::keyRIGTHALTdown(){    lua->keyRIGTHALTdown();}
GLvoid Renderable::keyBACKSPACEdown(){    lua->keyBACKSPACEdown();}
GLvoid Renderable::keyARROWUPdown(){    lua->keyARROWUPdown();}
GLvoid Renderable::keyARROWDOWNdown(){    lua->keyARROWDOWNdown();}
GLvoid Renderable::keyARROWLEFTdown(){    lua->keyARROWLEFTdown();}
GLvoid Renderable::keyARROWRIGHTdown(){    lua->keyARROWRIGHTdown();}
GLvoid Renderable::keyNUMPAD1down(){    lua->keyNUMPAD1down();}
GLvoid Renderable::keyNUMPAD2down(){    lua->keyNUMPAD2down();}
GLvoid Renderable::keyNUMPAD3down(){    lua->keyNUMPAD3down();}
GLvoid Renderable::keyNUMPAD4down(){    lua->keyNUMPAD4down();}
GLvoid Renderable::keyNUMPAD5down(){    lua->keyNUMPAD5down();}
GLvoid Renderable::keyNUMPAD6down(){    lua->keyNUMPAD6down();}
GLvoid Renderable::keyNUMPAD7down(){    lua->keyNUMPAD7down();}
GLvoid Renderable::keyNUMPAD8down(){    lua->keyNUMPAD8down();}
GLvoid Renderable::keyNUMPAD9down(){    lua->keyNUMPAD9down();}
GLvoid Renderable::keyNUMPAD0down(){    lua->keyNUMPAD0down();}
GLvoid Renderable::keyNUMPADPLUSdown(){    lua->keyNUMPADPLUSdown();}
GLvoid Renderable::keyNUMPADMINUSdown(){    lua->keyNUMPADMINUSdown();}
GLvoid Renderable::keyNUMPADSUBdown(){    lua->keyNUMPADSUBdown();}
GLvoid Renderable::keyNUMPADMULdown(){    lua->keyNUMPADMULdown();}
GLvoid Renderable::keyNUMPADENTERdown(){    lua->keyNUMPADENTERdown();}
GLvoid Renderable::keyNUMPADDOTdown(){    lua->keyNUMPADDOTdown();}
GLvoid Renderable::keyQup(){    lua->keyQup();}
GLvoid Renderable::keyWup(){    lua->keyWup();}
GLvoid Renderable::keyEup(){    lua->keyEup();}
GLvoid Renderable::keyRup(){    lua->keyRup();}
GLvoid Renderable::keyTup(){    lua->keyTup();}
GLvoid Renderable::keyYup(){    lua->keyYup();}
GLvoid Renderable::keyUup(){    lua->keyUup();}
GLvoid Renderable::keyIup(){    lua->keyIup();}
GLvoid Renderable::keyOup(){    lua->keyOup();}
GLvoid Renderable::keyPup(){    lua->keyPup();}
GLvoid Renderable::keyAup(){    lua->keyAup();}
GLvoid Renderable::keySup(){    lua->keySup();}
GLvoid Renderable::keyDup(){    lua->keyDup();}
GLvoid Renderable::keyFup(){    lua->keyFup();}
GLvoid Renderable::keyGup(){    lua->keyGup();}
GLvoid Renderable::keyHup(){    lua->keyHup();}
GLvoid Renderable::keyJup(){    lua->keyJup();}
GLvoid Renderable::keyKup(){    lua->keyKup();}
GLvoid Renderable::keyLup(){    lua->keyLup();}
GLvoid Renderable::keyZup(){    lua->keyZup();}
GLvoid Renderable::keyXup(){    lua->keyXup();}
GLvoid Renderable::keyCup(){    lua->keyCup();}
GLvoid Renderable::keyVup(){    lua->keyVup();}
GLvoid Renderable::keyBup(){    lua->keyBup();}
GLvoid Renderable::keyNup(){    lua->keyNup();}
GLvoid Renderable::keyMup(){    lua->keyMup();}
GLvoid Renderable::key1up(){    lua->key1up();}
GLvoid Renderable::key2up(){    lua->key2up();}
GLvoid Renderable::key3up(){    lua->key3up();}
GLvoid Renderable::key4up(){    lua->key4up();}
GLvoid Renderable::key5up(){    lua->key5up();}
GLvoid Renderable::key6up(){    lua->key6up();}
GLvoid Renderable::key7up(){    lua->key7up();}
GLvoid Renderable::key8up(){    lua->key8up();}
GLvoid Renderable::key9up(){    lua->key9up();}
GLvoid Renderable::key0up(){    lua->key0up();}
GLvoid Renderable::keyF1up(){    lua->keyF1up();}
GLvoid Renderable::keyF2up(){    lua->keyF2up();}
GLvoid Renderable::keyF3up(){    lua->keyF3up();}
GLvoid Renderable::keyF4up(){    lua->keyF4up();}
GLvoid Renderable::keyF5up(){    lua->keyF5up();}
GLvoid Renderable::keyF6up(){    lua->keyF6up();}
GLvoid Renderable::keyF7up(){    lua->keyF7up();}
GLvoid Renderable::keyF8up(){    lua->keyF8up();}
GLvoid Renderable::keyF9up(){    lua->keyF9up();}
GLvoid Renderable::keyF10up(){    lua->keyF10up();}
GLvoid Renderable::keyF11up(){    lua->keyF11up();}
GLvoid Renderable::keyF12up(){    lua->keyF12up();}
GLvoid Renderable::keyENTERup(){    lua->keyENTERup();}
GLvoid Renderable::keyESCAPEup(){    lua->keyESCAPEup();}
GLvoid Renderable::keySPACEup(){    lua->keySPACEup();}
GLvoid Renderable::keyTABup(){    lua->keyTABup();}
GLvoid Renderable::keyBLOCKMAYup(){    lua->keyBLOCKMAYup();}
GLvoid Renderable::keyLEFTSHIFTup(){    lua->keyLEFTSHIFTup();}
GLvoid Renderable::keyLEFTCTRup(){    lua->keyLEFTCTRup();}
GLvoid Renderable::keyLEFTALTup(){    lua->keyLEFTALTup();}
GLvoid Renderable::keyRIGTHSHIFTup(){    lua->keyRIGTHSHIFTup();}
GLvoid Renderable::keyRIGTHCTRup(){    lua->keyRIGTHCTRup();}
GLvoid Renderable::keyRIGTHALTup(){    lua->keyRIGTHALTup();}
GLvoid Renderable::keyBACKSPACEup(){    lua->keyBACKSPACEup();}
GLvoid Renderable::keyARROWUPup(){    lua->keyARROWUPup();}
GLvoid Renderable::keyARROWDOWNup(){    lua->keyARROWDOWNup();}
GLvoid Renderable::keyARROWLEFTup(){    lua->keyARROWLEFTup();}
GLvoid Renderable::keyARROWRIGHTup(){    lua->keyARROWRIGHTup();}
GLvoid Renderable::keyNUMPAD1up(){    lua->keyNUMPAD1up();}
GLvoid Renderable::keyNUMPAD2up(){    lua->keyNUMPAD2up();}
GLvoid Renderable::keyNUMPAD3up(){    lua->keyNUMPAD3up();}
GLvoid Renderable::keyNUMPAD4up(){    lua->keyNUMPAD4up();}
GLvoid Renderable::keyNUMPAD5up(){    lua->keyNUMPAD5up();}
GLvoid Renderable::keyNUMPAD6up(){    lua->keyNUMPAD6up();}
GLvoid Renderable::keyNUMPAD7up(){    lua->keyNUMPAD7up();}
GLvoid Renderable::keyNUMPAD8up(){    lua->keyNUMPAD8up();}
GLvoid Renderable::keyNUMPAD9up(){    lua->keyNUMPAD9up();}
GLvoid Renderable::keyNUMPAD0up(){    lua->keyNUMPAD0up();}
GLvoid Renderable::keyNUMPADPLUSup(){    lua->keyNUMPADPLUSup();}
GLvoid Renderable::keyNUMPADMINUSup(){    lua->keyNUMPADMINUSup();}
GLvoid Renderable::keyNUMPADSUBup(){    lua->keyNUMPADSUBup();}
GLvoid Renderable::keyNUMPADMULup(){    lua->keyNUMPADMULup();}
GLvoid Renderable::keyNUMPADENTERup(){    lua->keyNUMPADENTERup();}
GLvoid Renderable::keyNUMPADDOTup(){    lua->keyNUMPADDOTup();}
GLvoid Renderable::keyQpressed(){ }
GLvoid Renderable::keyWpressed(){ }
GLvoid Renderable::keyEpressed(){ }
GLvoid Renderable::keyRpressed(){ }
GLvoid Renderable::keyTpressed(){ }
GLvoid Renderable::keyYpressed(){ }
GLvoid Renderable::keyUpressed(){ }
GLvoid Renderable::keyIpressed(){ }
GLvoid Renderable::keyOpressed(){ }
GLvoid Renderable::keyPpressed(){ }
GLvoid Renderable::keyApressed(){ }
GLvoid Renderable::keySpressed(){ }
GLvoid Renderable::keyDpressed(){ }
GLvoid Renderable::keyFpressed(){ }
GLvoid Renderable::keyGpressed(){ }
GLvoid Renderable::keyHpressed(){ }
GLvoid Renderable::keyJpressed(){ }
GLvoid Renderable::keyKpressed(){ }
GLvoid Renderable::keyLpressed(){ }
GLvoid Renderable::keyZpressed(){ }
GLvoid Renderable::keyXpressed(){ }
GLvoid Renderable::keyCpressed(){ }
GLvoid Renderable::keyVpressed(){ }
GLvoid Renderable::keyBpressed(){ }
GLvoid Renderable::keyNpressed(){ }
GLvoid Renderable::keyMpressed(){ }
GLvoid Renderable::key1pressed(){ }
GLvoid Renderable::key2pressed(){ }
GLvoid Renderable::key3pressed(){ }
GLvoid Renderable::key4pressed(){ }
GLvoid Renderable::key5pressed(){ }
GLvoid Renderable::key6pressed(){ }
GLvoid Renderable::key7pressed(){ }
GLvoid Renderable::key8pressed(){ }
GLvoid Renderable::key9pressed(){ }
GLvoid Renderable::key0pressed(){ }
GLvoid Renderable::keyF1pressed(){ }
GLvoid Renderable::keyF2pressed(){ }
GLvoid Renderable::keyF3pressed(){ }
GLvoid Renderable::keyF4pressed(){ }
GLvoid Renderable::keyF5pressed(){ }
GLvoid Renderable::keyF6pressed(){ }
GLvoid Renderable::keyF7pressed(){ }
GLvoid Renderable::keyF8pressed(){ }
GLvoid Renderable::keyF9pressed(){ }
GLvoid Renderable::keyF10pressed(){ }
GLvoid Renderable::keyF11pressed(){ }
GLvoid Renderable::keyF12pressed(){ }
GLvoid Renderable::keyENTERpressed(){ }
GLvoid Renderable::keyESCAPEpressed(){ }
GLvoid Renderable::keySPACEpressed(){ }
GLvoid Renderable::keyTABpressed(){ }
GLvoid Renderable::keyBLOCKMAYpressed(){ }
GLvoid Renderable::keyLEFTSHIFTpressed(){ }
GLvoid Renderable::keyLEFTCTRpressed(){ }
GLvoid Renderable::keyLEFTALTpressed(){ }
GLvoid Renderable::keyRIGTHSHIFTpressed(){ }
GLvoid Renderable::keyRIGTHCTRpressed(){ }
GLvoid Renderable::keyRIGTHALTpressed(){ }
GLvoid Renderable::keyBACKSPACEpressed(){ }
GLvoid Renderable::keyARROWUPpressed(){ }
GLvoid Renderable::keyARROWDOWNpressed(){ }
GLvoid Renderable::keyARROWLEFTpressed(){ }
GLvoid Renderable::keyARROWRIGHTpressed(){ }
GLvoid Renderable::keyNUMPAD1pressed(){ }
GLvoid Renderable::keyNUMPAD2pressed(){ }
GLvoid Renderable::keyNUMPAD3pressed(){ }
GLvoid Renderable::keyNUMPAD4pressed(){ }
GLvoid Renderable::keyNUMPAD5pressed(){ }
GLvoid Renderable::keyNUMPAD6pressed(){ }
GLvoid Renderable::keyNUMPAD7pressed(){ }
GLvoid Renderable::keyNUMPAD8pressed(){ }
GLvoid Renderable::keyNUMPAD9pressed(){ }
GLvoid Renderable::keyNUMPAD0pressed(){ }
GLvoid Renderable::keyNUMPADPLUSpressed(){ }
GLvoid Renderable::keyNUMPADMINUSpressed(){ }
GLvoid Renderable::keyNUMPADSUBpressed(){ }
GLvoid Renderable::keyNUMPADMULpressed(){ }
GLvoid Renderable::keyNUMPADENTERpressed(){ }
GLvoid Renderable::keyNUMPADDOTpressed(){ }

GLvoid Renderable::update(GLfloat _tick)
{
    lua->update(_tick);
}