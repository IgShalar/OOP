#include"hexagon.h"
#include<iostream>
#include<math.h>

using namespace std;

std::istream &operator >> (std::istream &is, Hexagon &h){
    for (int i = 0; i < 6; i++) is >> h.p[i].first >> h.p[i].second;
    return is;
}

std::ostream &operator << (std::ostream &os, Hexagon &h){
    os << "Hexagon:";
    for (int i = 0; i < 6; i++) os << " (" << h.p[i].first << ", " << h.p[i].second << ")";
    return os;
}

double hex_distance(pair <double, double> a, pair<double, double> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double hex_S_triangle (double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

size_t Hexagon::VerticesNumber(){
    return 6;
}

double Hexagon::Area(){
    double res = 0, a, b, c;
    for (int i = 1; i < 5; i++){
        a = hex_distance(this->p[0], this->p[i]);
        b = hex_distance(this->p[i], this->p[i + 1]);
        c = hex_distance(this->p[0], this->p[i + 1]);
        res += hex_S_triangle(a, b, c);
    }
    return res;
}

Hexagon & Hexagon::operator = (const Hexagon &right){
    if (this == &right) return *this;
    for (int i = 0; i < 6; i++) this->p[i] = right.p[i];
    return *this;
}

double find_eps(){
    double eps = 1;
    while (eps + 1 != 1){
        eps /= 2;
    }
    return eps;
}

double eps = find_eps();

bool Hexagon::operator == (const Hexagon &right){
    bool p = 1;
    for (int i = 0; i < 6; i++){
        if (abs(this->p[i].first - right.p[i].first) >= eps || abs(this->p[i].second - right.p[i].second) >= eps)
            p = 0;
    }
    return p;
}
