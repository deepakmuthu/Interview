#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    std::vector <int> vArray;
    int VectorSize = 0;
    int i32LocMember = 0;
    
    std::cin >> VectorSize;
    
    while ( VectorSize > 0 )
    {
        std::cin >> i32LocMember;
        vArray.insert ( vArray.begin(), i32LocMember );
        //std::cout << i32LocMember << endl;
        --VectorSize;
    } 
    
    for ( auto it  : vArray) 
    {
        std::cout << it << " ";
    }
    return 0;
}
