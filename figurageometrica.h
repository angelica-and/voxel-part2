#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief The GeometricFigure class is an abstract class that serves as a template to all other geometric figures classes defined.
 */

class FiguraGeometrica

{

public:

  FiguraGeometrica();
  virtual ~FiguraGeometrica(); // virtual destructor
  virtual void draw(Sculptor &t)=0; //pure virtual class (has to be implemented by all derived classes)

};

#endif // FIGURAGEOMETRICA_H
