#include <iostream>

using namespace std;

int fibonacci( int num )
{
    if( num < 0 )
        return -1;
    if( num == 0 || num == 1 )
        return num;
    return fibonacci( num-1 ) + fibonacci( num -2 );
    
}

int fibonacci_it( int num )
{
    if( num < 0 )
        return -1;
    if( num == 0 || num == 1 )
        return num;
    
    int n1 = 0; // f(0)
    int n2 = 1; // f(1)
    int sum = 0;
    // cout<< n1 << " " << n2 << " ";
    for( int i = 0; i <= num - 2 ; i++ )
    {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        // cout << sum << " ";
    }
    // cout << endl;
    return sum;
}

int main(){

    cout << fibonacci(10) << endl;
    cout << fibonacci_it(10) << endl;
    return 1;
}
