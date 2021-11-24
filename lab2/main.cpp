#include<iostream>
#include"hexagon.h"
#include"tnarytree.h"

using namespace std;

int main(){
    cout << endl << "USAGE:" << endl;
    cout << "Add element:" << endl;
    cout << "a [x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4] [x5] [y5] [x6] [y6]" << endl << "[route]" << endl;
    cout << "example:" << endl << "a 0 2 1 1 1 -1 0 -2 -1 -1 -1 1" << endl << "cbb" << endl;
    cout << "Print: p" << endl;
    cout << "Delete:" << endl << "d" << endl << "[path]" << endl;
    cout << "Area:" << endl << "s" << endl << "[path]" << endl;
    cout << "Stop: q" << endl;
    cout << "___________________________________________________________________________" << endl;
    int n;
    cout << "Enter tree size:" << endl;
    cin >> n;
    TNaryTree t(n);
    char ch;
    string s;
    Hexagon h;
    while (1){
        cin >> ch;
        switch (ch){
            case 'a': {
                cin >> h;
                getline(cin, s);
                getline(cin, s);
                t.Update(h, s);
                cout << "added" << endl;
                break;
            }
            case 'p': {
                cout << t << endl;
                break;
            }
            case 'd': {
                getline(cin, s);
                getline(cin, s);
                t.Clear(s);
                cout << "deleted"  << endl;
                break;
            }
            case 's': {
                getline(cin, s);
                getline(cin, s);
                cout << t.Area(s) << endl;
                break;
            }
            case 'q': {
                s = "";
                t.Clear(s);
                return 0;
            }
        }
    }
    return 0;
}
