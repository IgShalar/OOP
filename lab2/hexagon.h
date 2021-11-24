#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include "figure.h"


class Hexagon : public Figure{
    
public:
    friend std::istream &operator >> (std::istream &is, Hexagon &p);
    friend std::ostream &operator << (std::ostream &os, Hexagon &p);
    Hexagon &operator = (const Hexagon &right);
    bool operator == (const Hexagon &right);
    size_t VerticesNumber();
    double Area();
    
private:
    std::pair <double, double> p[6];
};


#endif
