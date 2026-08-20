#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int i = 0,n, j, k;
    
    std::cin >> n >> k;  
    std::vector < std::vector<int> > arr (n);
    
    for ( i ; i < n; i++)
    {
        std::cin >> j;
        
        for ( ; j > 0;  )
        {
            int i32LocValue;
            std::cin >> i32LocValue;
            arr[i].push_back ( i32LocValue );
            j--;
        }
        
        //std::cout << "push Back Complete" << endl;
    }
    
    for ( ; k > 0;  )
    {
        std::cin >> i >> j;
        std::cout << arr[i][j] << endl;
        k--;
    }
    
    return 0;
}