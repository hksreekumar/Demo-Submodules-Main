#include <iostream>

#include <Demo-Submodules-ModA/function.h>

int main() {
    std::cout << "> Hello from main module!\n";

    function MyFunction;
    MyFunction.print();

    return 0;
}