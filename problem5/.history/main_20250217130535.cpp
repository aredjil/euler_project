#include <iostream>
/**
 * Solution to problem 5 of euler project 
 * https://projecteuler.net/problem=5 
 */
bool is_evenly_divisible(int num, int lower=1, int upper = 10)
{
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
int smallest_evenly_divisible()
{
    int start_num = 1; // We start with 1

}

int main(int argc, char**argv)
{

    return 0;
}