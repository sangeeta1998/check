#include <iostream>
//#include<emscripten.h>
using namespace std;

//EMSCRIPTEN_KEEPALIVE
struct AddQueue{
    double sum;
    AddQueue(double _sum=0)
    {
        sum= _sum;
    }
    void push1(double value)
    {
         sum += value * (double) 0.222222;
    }
    void push2(double value)
    {
        sum+= value * (double) 0.161616;
    }
    void push3(double value)
    {
        sum +=((value *2)/(double) 5.0) * (double) 0.123456;
    }
    void pushall(double value)
    {
        push1(value);
        push2(value);
        push3(value);
    }
};

int main()
{
    AddQueue test_Object {0.0f};

    for(int i=0; i< 1000000000; i++)
    {
        test_Object.pushall((double)i);
    }
    cout << (uint64_t) test_Object.sum<<endl;
}