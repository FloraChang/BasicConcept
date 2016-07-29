#include <iostream>

using namespace std;

bool larger( int a, int b )
{
    return a > b;
}

bool smaller( int a, int b )
{
    return a < b;
}

void swap( int &a, int &b )
{
    int temp = b;
    b = a;
    a = temp;
}

void buuble_sort( int num[], int size, bool (*compare)(int,int) )
{
    for( int i = 0; i < size; i++ )
    {
        bool swapped = false; // reset the flag
        
        for( int j = 0; j < size-1 ; j++ )
        {
            if( compare( num[j], num[j+1] ) )
            {
                swap( num[j], num[j+1] );
                swapped = true;
            }
        }
        
        if( !swapped )
            break;
    }
}

int main() {
    
    int number[] = { 3, 5, 2, 19 , 4, 52, 9, 1, 0, 1 };
    
    buuble_sort( number, 10, larger ); // increasing order
    for( int i = 0; i < 10; i++ )
    {
        cout<<number[i]<<" ";
    }
    cout<<endl;
    
    buuble_sort( number, 10, smaller ); // decreasing order
    for( int i = 0; i < 10; i++ )
    {
        cout<<number[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
