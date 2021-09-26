#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include "figure.h"

class Hexagon : public Figure{
    
public:
    Hexagon(std::istream &is);
    friend std::istream &operator>>(std::istream &is, Hexagon &p);
    void Print (std::ostream &os);
    size_t VerticesNumber();
    double Area();
//    ~Hexagon();
    
private:
    std::pair <double, double> p[6];
};


#endif
