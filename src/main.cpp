#include <iostream>
#include "keypad.h"

bool execute(Keypad k){
    std::string message;
    std::cout << "Message to encrypt (\"stop\" to exit): ";
    std::cin >> message;
    
    std::string cip = k.encrypt(message);
    std::cout << cip << std::endl;

    return (message == "stop");
}

int main(){
    int size = 0;
    std::cout << "What size keypad do you want? ";
    std::cin >> size;

    Keypad k(size, 0, 100);

    
    bool stop = false;
    while(!stop){
        stop = execute(k);
    }

    return 0;
}