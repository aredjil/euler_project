#ifndef GATHER_H
#define GATHER_H
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <omp.h>
std::random_device dv;
std::mt19937 gen(dv());

void step(std::vector<int> &balls, std::vector<int> &bowls);

void init(std::vector<int> &balls, std::vector<int> &bowls);

int get_max(const std::vector<int> &bowls);


#include "gather.hpp" 
#endif // GATHER_H