#include"hexagon.h"
#include<iostream>
#include<math.h>

using namespace std;

double hex_distance(pair <double, double> a, pair<double, double> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double hex_S_triangle (double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Hexagon::Hexagon(istream &is){
    for (int i = 0; i < 6; i++) is >> this->p[i].first >> this->p[i].second;
}

void Hexagon::Print (ostream &os){
    os << fixed;
    os.precision(1);
    os << "Hexagon:";
    for (int i = 0; i < 6; i++) os << " (" << this->p[i].first << ", " << this->p[i].second << ")";
    os << endl;
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

//Hexagon::~Hexagon(){
//    cout << "Deleted" << endl;
//}
