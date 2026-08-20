#include <iostream>
#include <vector>

int findMissingNumber ( std::vector<int>& vcPassedArray , int i32PassedSize )
{

    // Find the sum of all number based on the provided length value with below formula.
    int i32TotalValueByLength  = i32PassedSize * (i32PassedSize + 1) / 2;

    int i32SumOfVectorElement = 0;

    for ( int i32VectorElement : vcPassedArray )
    {
        i32SumOfVectorElement += i32VectorElement;
    }

    return i32TotalValueByLength - i32SumOfVectorElement;
}

int main ()
{
    std::vector <int> vcArray = {1,2,3,5,4};
    
    std::cout << "Missing number is : " << findMissingNumber ( vcArray, vcArray.size() + 1) << std::endl;

    return 0;
}