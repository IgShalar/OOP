#include"octagon.h"
#include<iostream>
#include<math.h>

using namespace std;

double oct_distance(pair <double, double> a, pair<double, double> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double oct_S_triangle (double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Octagon::Octagon(istream &is){
    for (int i = 0; i < 8; i++) is >> this->p[i].first >> this->p[i].second;
}

void Octagon::Print (ostream &os){
    os << fixed;
    os.precision(1);
    os << "Octagon:";
    for (int i = 0; i < 8; i++) os << " (" << this->p[i].first << ", " << this->p[i].second << ")";
    os << endl;
}

size_t Octagon::VerticesNumber(){
    return 8;
}

double Octagon::Area(){
    double res = 0, a, b, c;
    for (int i = 1; i < 7; i++){
        a = oct_distance(this->p[0], this->p[i]);
        b = oct_distance(this->p[i], this->p[i + 1]);
        c = oct_distance(this->p[0], this->p[i + 1]);
        res += oct_S_triangle(a, b, c);
    }
    return res;
}

//Octagon::~Octagon(){
//    cout << "Deleted" << endl;
//}
