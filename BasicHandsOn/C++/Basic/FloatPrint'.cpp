#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i32Integer;
    long long i64Integer;
    char cChar;
    float fFloat;
    double dDouble;

    cin >> i32Integer
        >> i64Integer
        >> cChar
        >> fFloat
        >> dDouble;

    cout << i32Integer << endl;
    cout << i64Integer << endl;
    cout << cChar << endl;

    cout << fixed << setprecision(3) << fFloat << endl;
    cout << fixed << setprecision(15) << dDouble << endl;

    return 0;
}