#include <iostream>
#include <string>

#include <algorithm>

int main ()
{
    std::string strInputString ( "ase234dfe5gfh679jgt686hu7" );
    std::string strDuptring ( strInputString );

    auto isNumericChar = [](unsigned char c)
    {
        return ( ( c >= 48 ) && c <= 57 );
    };

    for ( auto it = strInputString.begin(); it != strInputString.end() ; )
    {
        
        if (isNumericChar ( *it ))
        {
            it = strInputString.erase ( it );
        }
        else
        {
            ++it;
        }
    }

    std::cout << "\n" << strInputString << std::endl << strDuptring << std::endl; 

    return 0;
}