#include "sculptor.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

/**
 * @brief Construtor da classe sculptor.
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //atribui valores aos argumentos
    nx = _nx; ny = _ny; nz = _nz;

    //aloca x, ponteiro para ponteiro
    v = new Voxel**[nx];

    //verifica se foi alocado
    if(v == nullptr)
    {
        exit(0);
    }

    //aloca as colunas
    v[0] = new Voxel*[nx*ny];

    //verifica se foi alocado
    if(v[0] == nullptr)
    {
        exit(0);
    }

    //aloca os planos
    v[0][0] = new Voxel[nx*ny*nz];

    //verifica se foi alocado
    if(v[0][0] == nullptr)
    {
        exit(0);
    }

    //ajusta os endereços das linhas da matriz
    for(int i = 1; i<nx; i++){
        v[i] = v[i-1] + ny;
    }

    //ajusta os endereços dos planos da matriz
    for(int i = 1; i<ny*nz; i++){
        v[0][i] = v[0][i-1] + nz;
    }
}

/**
 * @brief Destrutor da classe sculptor.
 */
Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

/**
 * @brief Define a cor atual de desenho.
 */
void Sculptor::setColor(float vermelho, float verde, float azul, float alpha)
{
    r = vermelho; g = verde; b = azul; a = alpha;
}

/**
 * @brief Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho.
 */
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    //faz o voxel aparecer
    v[x][y][z].isOn = true;

}

/**
 * @brief Desativa o voxel na posição (x,y,z) (fazendo isOn = false).
 */
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;

}

/**
 * @brief Gera um arquivo .OFF
 */
//OFF
void Sculptor::writeOFF(string filename)
{

    int n_voxel = 0;
    ofstream outfile (filename);
    outfile<<"OFF"<<endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    n_voxel++;
                }}}}


    outfile << 8*n_voxel << " " << 6*n_voxel << " " << 0 << std::endl;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    outfile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    outfile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    outfile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    outfile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    outfile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    outfile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    outfile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    outfile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }}}}

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    outfile << 4 << " " << 0 + 8*i << " " << 3 + 8*i << " " << 2 + 8*i << " " << 1 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 4 + 8*i << " " << 5 + 8*i << " " << 6 + 8*i << " " << 7 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 0 + 8*i << " " << 1 + 8*i << " " << 5 + 8*i << " " << 4 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 0 + 8*i << " " << 4 + 8*i << " " << 7 + 8*i << " " << 3 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 3 + 8*i << " " << 7 + 8*i << " " << 6 + 8*i << " " << 2 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 1 + 8*i << " " << 2 + 8*i << " " << 6 + 8*i << " " << 5 + 8*i << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << " " << endl;
                }}}}

    outfile.close();
}

/**
 * @brief Gera um arquivo .VECT
 */
//VECT
void Sculptor::writeVECT(string filename)
{
    int nvox = 0;
    ofstream outfile (filename);
    outfile << "VECT" << endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    nvox++;
                }
            }
        }
    }

    outfile << nvox << " " << nvox << " " << nvox << endl;
    for (int i =0;i<nvox; i++) {
        outfile << "1" <<" ";
    }
    outfile << endl;
    for (int i =0;i<nvox; i++) {
        outfile << "1" <<" ";
    }
    outfile << endl;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    outfile << i <<" "<< j <<" "<< k << endl;
                }
            }
        }
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    outfile << v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                }
            }
        }
    }

    outfile.close();
}


//DIM
/*void Sculptor::writeDIM(string filename)
{
    int nvoxel = 0;
    int d[nx][ny][nz];
    bool x_teste = false, y_teste = false, z_teste = false;
    int i,j,k;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                d[i][j][k] = 0;
            }
        }
    }
    ofstream outfile(filename);
    outfile<< "DIM " << " " << nx << " " << ny << " " << nz << endl;
    for(i=0;i<nx-2;i++){
        for(j=0;j<ny-2;j++){
            for(k=0;k<nz-2;k++){
                x_teste = false; y_teste = false; z_teste = false;
                if(v[i][j][k].isOn && v[i+2][j][k].isOn){
                    x_teste = true;
                }
                if(v[i][j][k].isOn && v[i][j+2][k].isOn){
                    x_teste = true;
                }
                if(v[i][j][k].isOn && v[i][j][k+2].isOn){
                    z_teste = true;
                }
                if(x_teste || x_teste || z_teste){
                    d[i+1][j+1][k+1] = 1;
                }}}}


    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if (v[i][j][k].isOn && d[i][j][k] == 0){
                    nvoxel++;
                }}}}

    outfile << nvoxel << " " << nvoxel << " " << nvoxel << endl;

*/

