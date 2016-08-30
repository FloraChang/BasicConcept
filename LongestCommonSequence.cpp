#include <iostream>
#include <vector>

using namespace std;

int getLCSlength( vector<int> s1, vector<int> s2 )
{
    // Insert 0 to the begginig of the vector
    // s1 = {0} + {s1}
    // s2 = {0} + {s2}
    s1.insert( s1.begin(), 0 );
    s2.insert( s2.begin(), 0 );
    
    // Table for dynamic programming, set array[i][0] and array[0][j] to zero
    int LCS[s1.size()][s2.size()];
    for( int i = 0; i < s1.size(); i++ )
    {
        for( int j = 0; j < s2.size(); j++ )
        {
            LCS[i][j] = 0;
        }
    }
    
    // Caculate LCS
    for ( int i = 1; i < s1.size(); i++ )
    {
        for ( int j = 1; j < s2.size(); j++ )
        {
            if ( s1[i] == s2[j] )
            {
                // lenght + 1
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1] );
            }
        }
    }
    
    return LCS[s1.size()-1][s2.size()-1];
}


int main()
{
    vector<int> s1 = { 3, 5, 2 };
    vector<int> s2 = { 3, 5, 3, 2, 8 };
    
    cout << "The length of LCS is " << getLCSlength( s1, s2 ) << endl;
    return 0;
}
