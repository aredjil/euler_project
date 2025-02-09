#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

#include "gather.hpp"

// Pseudo random number generator 
std::random_device dv;
std::mt19937 gen(dv());

int main(int argc, char**argv){
    int n{2}; // Number of bowls 
    int m{2}; //  Number of balls 
    int random_idx; 
    std::vector <int> bowls(0, n);
    
    std::uniform_int_distribution<int> dist(0, n-1);
    for (int i = 0; i < m; i++)
    {
        
        random_idx = dist(gen);

    }
    

    return 0;
}