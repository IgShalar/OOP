#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "figure.h"

class Triangle : public Figure{
    
public:
    Triangle(std::istream &is);
    friend std::istream &operator>>(std::istream &is, Triangle &p);
    void Print (std::ostream &os);
    size_t VerticesNumber();
    double Area();
//    ~Triangle();
    
private:
    std::pair <double, double> p[3];
};


#endif
