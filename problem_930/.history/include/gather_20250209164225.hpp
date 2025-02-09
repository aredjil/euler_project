#ifndef GATHER_H
#define GATHER_H
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include "gather.hpp"
// Pseudo random number generator

class Bowls{
    public:
    int n; // Number of bowls  
    int m; // Number of balls
    // std::random_device dv;
    std::mt19937 gen;

    std::vector<int> bowls; 

    // Constructor 
    Bowls(int num_bowls, int num_balls);
    // Intilize 
    void init(); 

};

#endif // GATHER_H