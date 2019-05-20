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

    //matriz 3D
    Voxel ***v;
    //Dimensões
    int nx, ny, nz;
    //Cores
    float r, g, b, a;

public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float vermelho, float verde, float azul, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(string filename);
    void writeVECT(string filename);

};

#endif // SCULPTOR_H
