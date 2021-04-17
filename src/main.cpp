#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
#include "keypad.h"

bool execute(Keypad k){
    std::string message;
    std::cout << "Message to encrypt (\"stop\" to exit): ";
    std::cin >> message;
    
    std::string cip = k.encrypt(message);
    std::cout << cip << std::flush;
    std::cout << std::endl;

    return (message == "stop");
}

int main(){
    int size = 1000;
    // std::cout << "What size keypad do you want? ";
    // std::cin >> size;

    // bool stop = false;
    // while(!stop){
    //     stop = execute(k);
    // }

    // for(int i = 0; i < 100; i++){
    //     Keypad k(size, 0, 100);
    //     k.printPad();
    // }


    Keypad k(size, 0, 100);
    k.toFile("printFile.txt");

    return 0;
}