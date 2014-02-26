/* 
 * File:   MaterialNull.h
 * Author: francisco
 *
 * Created on 8 de enero de 2014, 19:51
 */

#ifndef MATERIALNULL_H
#define	MATERIALNULL_H

#include <Scene/Material.h>

namespace kaikai
{
    class MaterialNull : public Material{
    public:
        MaterialNull();
        virtual ~MaterialNull();
        
    private:

    };
}
#endif	/* MATERIALNULL_H */

