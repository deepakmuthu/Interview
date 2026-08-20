#include <iostream>
#include <string>

int main ( int i32ArgCount, char *pcArgValue[] )
{
    unsigned int ui32Start = 0
            , ui32End;

    std::string strInputString;
    
    std::cout << "Enter a string : " ;
    std::cin >> strInputString;

    if ( strInputString.length() == 1 )
    {
        std::cout << strInputString << " is palindrome" << std::endl;
        return 0 ;
    }
    else
    {
        ui32End = strInputString.length () - 1;
    }

    for ( ; ui32Start < ui32End /* strInputString.length () / 2 */ ;  )
    {
        if ( strInputString [ ui32Start ] != strInputString [ ui32End ] )
        {
            std::cout << strInputString << " is not palindrome" << std::endl;
            return 0 ;
        }

        ++ui32Start;
        --ui32End;
    }

    std::cout << strInputString << " is palindrome" << std::endl;
    return 0 ;
}
