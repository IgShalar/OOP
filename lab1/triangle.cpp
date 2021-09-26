#include"triangle.h"
#include<iostream>
#include<math.h>

using namespace std;

double tr_distance(pair <double, double> a, pair<double, double> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double tr_S_triangle (double a, double b, double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle(istream &is){
    for (int i = 0; i < 3; i++) is >> this->p[i].first >> this->p[i].second;
}

void Triangle::Print (ostream &os){
    os << fixed;
    os.precision(1);
    os << "Triangle:";
    for (int i = 0; i < 3; i++) os << " (" << this->p[i].first << ", " << this->p[i].second << ")";
    os << endl;
}

size_t Triangle::VerticesNumber(){
    return 3;
}

double Triangle::Area(){
    double res = 0, a, b, c;
    a = tr_distance(this->p[0], this->p[1]);
    b = tr_distance(this->p[1], this->p[2]);
    c = tr_distance(this->p[0], this->p[2]);
    res += tr_S_triangle(a, b, c);
    return res;
}

//Triangle::~Triangle(){
//    cout << "Deleted" << endl;
//}
