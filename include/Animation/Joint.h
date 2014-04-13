/* 
 * File:   Joint.h
 * Author: francisco
 *
 * Created on 2 de abril de 2014, 14:12
 */

#ifndef JOINT_H
#define	JOINT_H

#include "../Unnivelmas_conf.h"
#include <string>
#include <list>

namespace kaikai
{
    class Joint {
    public:
        Joint();
        virtual ~Joint();
        
    private:
        std::string name;
        GLint bone_array_index;
        Joint* faher;
        std::list<Joint*> childs;
    };
}
#endif	/* JOINT_H */

