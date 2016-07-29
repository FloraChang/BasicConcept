#include <iostream>

using namespace std;

int main()
{
    int array[3] = { 10, 20, 30 };
    
    int *p = array;
    cout << *p++ << endl;   // 10, same as *(p++): increment pointer, and dereference unincremented address.
    cout << *p << endl;     // 20

    p = array;
    cout << *++p << endl;   // 20, same as *(++p): increment pointer, and dereference incremented address.
    cout << *p << endl;     // 20
    
    p = array;
    cout << ++*p << endl;   // 11, same as ++(*p): dereference pointer, and increment the value it points to
    cout << *p << endl;     // 11

    cout << (*p)++ << endl; // 11, dereference pointer, and post-increment the value it points to
    cout << *p << endl;     // 12
    
    return 1;
}
