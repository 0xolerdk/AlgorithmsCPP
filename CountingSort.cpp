#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string sorted[100][10];
    string name;
    int crabs;
    int traps;
    
    while (n--) {
        cin>>name>>crabs>>traps;
        name+=" ";
        sorted[crabs][traps]+=name;
    }
    
    for (int i = 99; i>=0; i--) {
        for (int j = 0; j<=9; j++) {
            cout<<sorted[i][j];
        }
    }
    
    return 0;
}