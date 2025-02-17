#include <iostream>
#include <string>
/**
 * Solution to problem 5 of euler project 
 * https://projecteuler.net/problem=5 
 */
bool is_evenly_divisible(int num, int lower=1, int upper = 11)
{
    // Check if a number is divisible by the numbers between lower and upper 
    bool is = true; 
    for(int i=lower;i<upper;i++)
    {
        if(num % i != 0)
        {
            is=false;
        }
    }
    return is; 
}

// int smallest_evenly_divisible()
// {
//     int start_num = 1; // We start with 1

// }

int main(int argc, char**argv)
{
    int num = 2520;
    for(int i =1;i<argc;i++)
    {
        if(std::string(argv[i]) == "-n" && i+1 <argc)
        {
            num = std::atoi(argv[++i]);
        }
    }
    std::cout<<is_evenly_divisible(2520)<<"\n";
    return 0;
}