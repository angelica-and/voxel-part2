#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Voxel {
    //cores
    float r,g,b;
    //transparência
    float a;
    //incluído ou não
    bool isOn;
};


//definition of our sculptor class
class Sculptor {

public:
    //matriz 3D
    Voxel ***v;
    //Dimensões
    int nx, ny, nz;
    //Cores
    float r, g, b, a;
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float vermelho, float verde, float azul, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  //void writeOFF(string filename);
  //void writeVECT(string filename);

};

#endif // SCULPTOR_H
