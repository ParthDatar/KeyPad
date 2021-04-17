#include "keypad.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <time.h>

Keypad::Keypad(int size, int start, int end){
    this->size = size;
    pad = new int[size];
    
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dis(start,end);
    srand(time(NULL));
    uint64_t mSeed = rand();
    gen.seed(mSeed);

    for(int i = 0; i < size; i++){
        pad[i] = dis(gen);
    }
}

Keypad::Keypad(const Keypad& k){
    pad = new int[k.size];
    size = k.size;
    for(int i = 0; i < size; i++){
        pad[i] = k.pad[i];
    }
}


Keypad::~Keypad(){
    delete [] pad;
}

void Keypad::printPad(){
    int counter = 0;
    std::for_each(pad, pad+size, [&counter](int i){
        std::cout << i << "\t";
        counter++;
        if(counter % 10 == 0){
            std::cout << std::endl;
        }
    });
}

std::string Keypad::encrypt(std::string message){
    std::string cipher = message;
    for(int i = 0; i < message.size(); i++){
        cipher[i] = message[i] + pad[i];
    }
    return cipher;
}

std::string Keypad::decrypt(std::string cipher){
    std::string message = cipher;
    for(int i = 0; i < cipher.size(); i++){
        message[i] = cipher[i] - pad[i];
    }
    return message;
}

void Keypad::toFile(std::string filename){
    std::ofstream outFile("../outputFiles/" + filename);
    if(!outFile.is_open()){
        return;
    }

    for(int i = 0; i < size; i++){
        outFile << pad[i] << " ";
        if(i >= 10 && i % 10 == 0){
            outFile << std::endl;
        }
    }
}