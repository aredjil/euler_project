#ifndef GATHER_H
#define GATHER_H
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include "gather.hpp"
// Pseudo random number generator
std::random_device dv;
std::mt19937 gen(dv());

class Bowls{
    public:
    int n; // Number of bowls  
    int m; // Number of balls

    std::vector<int> bowls; 

    Bowls(int number_bowls, int number_);

};

#endif // GATHER_H