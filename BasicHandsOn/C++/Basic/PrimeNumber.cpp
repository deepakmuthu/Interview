#include <iostream>
#include <string>

#include <cmath>

bool isPrimeNumber ( int i32ParamNumber )
{
    unsigned int ui32LoopIndex = 0;


    if (i32ParamNumber <= 1) return false;

    for ( ui32LoopIndex = 2; ui32LoopIndex <= std::sqrt(i32ParamNumber); ++ui32LoopIndex )
    {
        if ( ( i32ParamNumber % ui32LoopIndex ) == 0 ) return false;
    }    

    return true;
}

int main ( int ui32ArgCount, char* pcArgumernts[] )
{
    int i32Number       = 0;

    while ( 1 )
    {

        std::cout << "Enter a number for check its prime or not : ";
        std::cin >> i32Number ;

        if ( i32Number == 0)
        {
            std::cout << "Done Quit" << std::endl;
            return 0;
        }

        std::cout << std::boolalpha << isPrimeNumber (i32Number) << std::endl;
        
    }

    return 0;
}