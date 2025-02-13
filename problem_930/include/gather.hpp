#ifndef GATHER_H
#define GATHER_H
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <omp.h>
#include<chrono>

#ifdef _OPENACC
#include <openacc.h>
#endif
void 
step(std::vector<int> &balls, std::vector<int> &bowls, const int &n,const int &m);

void 
init(std::vector<int> &balls, std::vector<int> &bowls, const int &n,const int &m);

int 
get_max(const std::vector<int> &bowls);

double
get_expected_steps(const int &n,const int &m, const int &n_steps);

#include "gather.hpp" 
#endif // GATHER_H