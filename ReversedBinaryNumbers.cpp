/*
 Task
 Your task will be to write a program for reversing numbers in binary. For instance, the binary representation of 13 is 1101, and reversing it gives 1011, which corresponds to number 11.
 
 Input
 The input contains a single line with an integer N, 1 ≤ N ≤ 1000000000.
 
 Output
 Output one line with one integer, the number we get by reversing the binary representation of N.
 */

#include <iostream>
#include <bitset>

using namespace std;

int reverseBinary( int number )
{
    // debug: print binary format of original number
    // std::bitset<sizeof(int)*8> num_before( number );
    // cout << num_before << endl;
    
    int reverse = 0;
    
    while( number > 0 )
    {
        if( ( number & 1 ) == 1 )
        {
            reverse = ( reverse << 1 ) + 1;
        }
        else
        {
            reverse = (reverse << 1 );
        }
        
        number = number >> 1;
    }
    return reverse;
}

int main()
{
    int input_num, ouput;
    cin >> input_num;
    
    ouput = reverseBinary( input_num );
    
    cout << "input:" << input_num << ", output:" << ouput << endl;
    return 0;
}
