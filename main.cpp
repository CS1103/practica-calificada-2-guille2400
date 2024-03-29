#include <iostream>

#include "heap.h"
using namespace std;

int main()
{
    heap<int> h;
    h.load_from("data.txt");
    cout << "heap" << endl;
    cout << h;
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.insert(10);
    cout << "heap" << endl;
    cout << h;
    cout << "heap" << endl;
    cout << h;
    cin >> h;
    cout << "heap" << endl;
    cout << h;
    h.insert(100, 200);
    cout << "heap" << endl;
    cout << h;
    h.load_from("data.txt");
    cout << h;
    return 0;
}