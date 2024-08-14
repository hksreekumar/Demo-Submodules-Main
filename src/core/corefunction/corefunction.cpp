#include "corefunction.h"
#include <iostream>

corefunction::corefunction(/* args */)
{
}
corefunction::~corefunction()
{
}

int corefunction::add(int a, int b)
{
    std::cout<<">> corefunction called\n";
    return a+b;
}
