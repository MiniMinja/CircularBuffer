#include "ring.hpp"


#include <iostream>
#include <cstring>

int main(){
    RingBufferS rb(7);

    char localBuffer[6];

    char word1[] = "Hello";
    char word2[] = "bye";

    rb.push(word1, std::strlen(word1));
    rb.pop(localBuffer, 4);
    for(int i = 0;i<4;i++){
        std::cout << localBuffer[i];
    }
    std::cout << std::endl;

    rb.push(word2, std::strlen(word2));
    rb.pop(localBuffer, 4);
    for(int i = 0;i<4;i++){
        std::cout << localBuffer[i];
    }
    std::cout << std::endl;
}