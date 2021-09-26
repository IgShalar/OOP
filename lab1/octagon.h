#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include "figure.h"

class Octagon : public Figure{
    
public:
    Octagon(std::istream &is);
    friend std::istream &operator>>(std::istream &is, Octagon &p);
    void Print (std::ostream &os);
    size_t VerticesNumber();
    double Area();
//    ~Octagon();
    
private:
    std::pair <double, double> p[8];
};


#endif
