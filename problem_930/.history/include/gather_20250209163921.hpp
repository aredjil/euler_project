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
    std::random_device dv;

    std::vector<int> bowls; 

    // Constructor 
    Bowls(int num_bowls, int num_balls);
    // Intilize 
    

};

#endif // GATHER_H