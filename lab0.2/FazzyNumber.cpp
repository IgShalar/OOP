#include"FazzyNumber.h"
#include<iostream>


using namespace std;

FazzyNumber::FazzyNumber(double a, double b){
    this->x = a;
    this->e = b;
}

istream &operator >> (istream &is, FazzyNumber &h){
    cin >> h.x >> h.e;
    return is;
}

ostream &operator << (ostream &os, const FazzyNumber &h){
    os << "<" << h.x << ", " << h.e << ">";
    return os;
}

FazzyNumber & FazzyNumber::operator = (const FazzyNumber &t){
    this->x = t.x;
    this->e = t.e;
    return *this;
}

FazzyNumber FazzyNumber::operator + (const FazzyNumber &t) {
    FazzyNumber c;
    c.x = this->x + t.x;
    c.e = this->x + t.x + this->e + t.e;
    return c;
}

FazzyNumber FazzyNumber::operator - (const FazzyNumber &t){
    FazzyNumber c;
    c.x = this->x - t.x;
    c.e = this->x - t.x + this->e + t.e;
    return c;
}

FazzyNumber FazzyNumber::operator * (const FazzyNumber &t) {
    FazzyNumber c;
    c.x = this->x * t.x;
    c.e = this->x * t.x + t.x * this->e + this->x * t.e + this->e * t.e;
    return c;
}

FazzyNumber FazzyNumber::operator / (const FazzyNumber &t){
    if (t.x <= 0){
        throw invalid_argument( "right.x must be > 0" );
        exit(-1);
    }
    if (t.x == t.e){
        throw invalid_argument( "division by zero in /" );
        exit(-1);
    }
    FazzyNumber c;
    c.x = this->x / t.x;
    c.e = (this->x + this->e) / (t.x - t.e);
    return c;
}

bool FazzyNumber::operator == (const FazzyNumber &t){
    return (this->x == t.x && this->e == t.e);
}

bool x_comp (const FazzyNumber &a, const FazzyNumber &b){
    return a.x == b.x;
}

FazzyNumber FazzyNumber::operator-() const {
    if (this->x <= 0){
        throw invalid_argument( "x must be > 0" );
        exit(-1);
    }
    if (this->x == this->e){
        throw invalid_argument( "division by zero in reverse" );
        exit(-1);
    }
    FazzyNumber c;
    c.x = 1 / this->x;
    c.e = 1 / (this->x - this->e);
    return c;
}

bool FazzyNumber::operator |= (const FazzyNumber &t){
    return (this->x == t.x);
}
