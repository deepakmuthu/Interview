#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main ()
{
    string strSourceBuffer ( "I am deepak m" );

    vector<string> vCollectionofString;

    cout << "Enter a buffer : ";

    // strSourceBuffer.clear();
    
    //cin >> strSourceBuffer;
    std::getline ( cin, strSourceBuffer );
    cout << "Use the provided input is : " << strSourceBuffer << endl;

    stringstream StreamString ( strSourceBuffer );

    //vCollectionofString = strSourceBuffer.split( " " );

    while ( StreamString >> strSourceBuffer )
    {
        vCollectionofString.push_back(strSourceBuffer);
        //cout << vCollectionofString [ i32TotalWordCount ] << " ";
    }

    int i32TotalWordCount = vCollectionofString.size();
    
    while ( 0 !=  i32TotalWordCount )
    {
        i32TotalWordCount--;
        cout << vCollectionofString [ i32TotalWordCount ] << " ";
    }


    cout << endl;
}
