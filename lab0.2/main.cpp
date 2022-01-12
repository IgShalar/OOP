#include<iostream>
#include"FazzyNumber.h"

using namespace std;

FazzyNumber operator"" _x(unsigned long long x){
    FazzyNumber res;
    res.x = x;
    return res;
}

FazzyNumber operator"" _e(unsigned long long x){
    FazzyNumber res;
    res.e = x;
    return res;
}

int main(){
/*
    //Literals example:
    FazzyNumber q = 10_x;
    cout << q << endl;
    FazzyNumber w = 10_e;
    cout << w << endl;
    return 0;
 */
    FazzyNumber a, b, res;
    cout << "Enter values: [x1] [e1] [x2] [e2]" << endl;
    cout << "Example: 1 2 3 4" << endl;
    cin >> a >> b;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "Comparison by x: " << (a |= b) << endl;
    cout << "(A == B) = " << (a == b) << endl;
    res = a + b;
    cout << "A + B = " <<  res << endl;
    res = a - b;
    cout << "A - B = " <<  res << endl;
    res = a * b;
    cout << "A * B = " <<  res << endl;
    res = a / b;
    cout << "A / B = " <<  res << endl;
    a = -a;
    cout << "Reversed A = " << a << endl;
    return 0;
}
