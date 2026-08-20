#include <iostream>
#include <string>

int main()
{
    unsigned int ui32UptoNumber = 0
            , ui32StartNumber   = 0
            , ui32Endnumber     = 1
            , ui32tempNumber    = 0;

    std::cout << "Enter a Number in positive only" << std::endl;
    std::cin >> ui32UptoNumber ;

    std::cout << "Number is :";
    for ( ; ui32UptoNumber-- ; )
    {
        std::cout << " " << ui32StartNumber;

        ui32tempNumber = ui32StartNumber + ui32Endnumber;

        ui32StartNumber = ui32Endnumber;

        ui32Endnumber = ui32tempNumber;

    }

    std::cout << std::endl;
    return 0;
}