#include "cutsphere.h"

/**
 * @brief Classe CutSphere
 */


/**
 * @brief Construtor da classe CutSphere
 */
CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius )
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

/**
 * @brief Destrutor da classe CutSphere
 */
CutSphere::~CutSphere()
{

}

/**
 * @brief Desativa todos os voxels que satisfazem à equação da esfera.
 */
void CutSphere::draw(Sculptor &t)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
        for(int j = ycenter-radius; j<=ycenter+radius; j++){
            for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if( ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius ){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
