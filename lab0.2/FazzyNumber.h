#ifndef HEXAGON_H
#define HEXAGON_H
#include<iostream>
#include<stdexcept>

class FazzyNumber{

public:
    FazzyNumber() {this->x = 0, this->e = 0; };
    FazzyNumber(double a, double b);
    friend std::istream &operator >> (std::istream &is, FazzyNumber &p);
    friend std::ostream &operator << (std::ostream &os, const FazzyNumber &p);
    FazzyNumber &operator = (const FazzyNumber &right);
    bool operator == (const FazzyNumber &t);
    FazzyNumber operator + (const FazzyNumber &t);
    FazzyNumber operator - (const FazzyNumber &t);
    FazzyNumber operator * (const FazzyNumber &t);
    FazzyNumber operator / (const FazzyNumber &t);
    //reverse
    FazzyNumber operator-() const;
    //compare by x
    bool operator |= (const FazzyNumber &t);
    
    double x, e;
    
};


#endif
