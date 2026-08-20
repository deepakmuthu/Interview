#include <iostream>
#include <string>

#include <cctype>
#include <algorithm>

int main()
{
    std::string strMainBuffer ("       Hellow World         ");

    strMainBuffer. erase ( 
                        strMainBuffer.begin()
                        , std::find_if ( 
                                strMainBuffer.begin()
                                , strMainBuffer.end()
                                , []( unsigned char c )
                                    {
                                        return !std::isspace ( c );
                                    } 
                        )
                );

    std::cout << "Final string is after trim in beginning : " << strMainBuffer << "<-" << std::endl;


    strMainBuffer.erase (
            std::find_if ( 
                    strMainBuffer.rbegin()
                    , strMainBuffer.rend()
                    , [] ( unsigned char c )
                    {
                        return !std::isspace ( c );
                    } 
            ).base()
            , strMainBuffer.end()
    );

    std::cout << "After trim the last white space : " << strMainBuffer << "<-" << std::endl;

    return 0;
}