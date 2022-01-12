#include"hexagon.h"
#include"octagon.h"
#include"triangle.h"
#include"figure.h"
#include<iostream>
#include<vector>

using namespace std;

int main(){
    cout << "Add triangle: t [x1] [y1] [x2] [y2] [x3] [y3]" << endl;
    cout << "Example: t 1 2 3 4 5 6" << endl;
    cout << "Add hexagon: h [x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4] [x5] [y5] [x6] [y6]" << endl;
    cout << "Add octagon: o [x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4] [x5] [y5] [x6] [y6] [x7] [y7] [x8] [y8]" << endl;
    cout << "Print: p" << endl;
    cout << "Stop: q" << endl;
    cout << "___________________________________________________________________________________________________" << endl << endl;
    char ch;
    vector <Figure *> v;
    cin >> ch;
    while (ch != 'q'){
        if (ch == 't'){
            Figure * f = new Triangle(cin);
            v.push_back(f);
        }
        if (ch == 'h'){
            Figure * f = new Hexagon(cin);
            v.push_back(f);
        }
        if (ch == 'o'){
            Figure * f = new Octagon(cin);
            v.push_back(f);
        }
        if (ch == 'p'){
            for (int i = 0; i < v.size(); i++) v[i]->Print(cout);
        }
        cin >> ch;
    }
    return 0;
}
