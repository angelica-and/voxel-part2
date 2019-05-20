#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica
{

protected:

    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

public:

    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    ~PutSphere();
    /**
     * @brief Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
     */
    void draw(Sculptor &t);

};

#endif // PUTSPHERE_H
