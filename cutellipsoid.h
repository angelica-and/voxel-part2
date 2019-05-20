#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica
{

protected:

    int xcenter, ycenter,  zcenter,  rx,  ry, rz;

public:

    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    ~CutEllipsoid();
    /**
     * @brief Desativa todos os voxels que satisfazem à equação do elipsóide.
     */
    void draw(Sculptor &t);

};

#endif // CUTELLIPSOID_H
