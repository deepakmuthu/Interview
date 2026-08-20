#include <iostream>
#include <limits>

using namespace std;

int main ()
{
    cout << "Numeric max of int : " << std::numeric_limits<int>::max() << endl;
    cout << "numeric min of int : " << std::numeric_limits<int>::min() << endl;
    cout << "numeric min of int : " << std::numeric_limits<int>::infinity() << endl; // returm is zero. infinity is not valid for int.

    cout << "Numeric max of double : " << std::numeric_limits<double>::max() << endl;
    cout << "numeric min of double : " << std::numeric_limits<double>::min() << endl;
    cout << "numeric min of double : " << std::numeric_limits<double>::infinity() << endl; // infinity is only for double and float, not for int
}