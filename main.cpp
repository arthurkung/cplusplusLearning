#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main(int argc, char** argv) {
    int a;
    a=1;

    std::cout << "IF clause\n";
    if(a==0){
        std::cout << 2;
    } else {
        std::cout << 3;
    }
    std::cout << "\nloop\n";
    for(int counter=1; counter<11;counter++){
        std::cout << counter;
    }

    return (EXIT_SUCCESS);
}
