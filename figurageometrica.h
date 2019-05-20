#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief Classe abstrata FiguraGeometrica. Serve como base para
 * todas as outras classes definidas que têm como objetivo desenhar
 * figuras.
 */

class FiguraGeometrica

{

public:

  FiguraGeometrica();
  virtual ~FiguraGeometrica();
  virtual void draw(Sculptor &t)=0;

};

#endif // FIGURAGEOMETRICA_H
