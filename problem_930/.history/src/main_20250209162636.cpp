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
    std::vector <int> bowls(n, 0);
    std::vector<int> balls(m, 1);
    std::uniform_int_distribution<int> dist(0, n);
    

    
    std::cout<<"idx: "<<random_idx<<"\n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout<<"Bowl number: "<<i<<"\n";
        std::cout<<"Has: "<<bowls[i]<<" balls\n";
    }
    return 0;
}