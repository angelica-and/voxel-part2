#include "putsphere.h"

/**
 * @brief Classe PutSphere
 */

/**
 * @brief Construtor da classe PutSphere
 */
PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

/**
 * @brief Destrutor da classe PutSphere
 */
PutSphere::~PutSphere()
{

}

/**
 * @brief Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
 */
void PutSphere::draw(Sculptor &t)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
        for(int j = ycenter-radius; j<=ycenter+radius; j++){
            for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if(((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius
){
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
