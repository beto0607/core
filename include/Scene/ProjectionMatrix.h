/* 
 * File:   ProjectionMatrix.h
 * Author: francisco
 *
 * Created on 12 de diciembre de 2013, 17:48
 */

#ifndef PROJECTIONMATRIX_H
#define	PROJECTIONMATRIX_H

#include "../Unnivelmas_conf.h"

namespace unnivelmas{
    
    class ProjectionMatrix {
    public:
        ProjectionMatrix();
        ProjectionMatrix(const ProjectionMatrix& orig);
        virtual ~ProjectionMatrix();
    private:
        glm::mat4 matrix;
    };
}
#endif	/* PROJECTIONMATRIX_H */

