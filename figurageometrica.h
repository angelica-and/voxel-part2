#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica

{

public:

  FiguraGeometrica();
  virtual ~FiguraGeometrica(); // virtual destructor
  virtual void draw(Sculptor &t)=0; //pure virtual class (has to be implemented by all derived classes)

};

#endif // FIGURAGEOMETRICA_H
