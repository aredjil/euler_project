#include <iostream>
#include <vector>
#include <algorithm>

int count_digits(int number)
{
    if (number == 0)
    {
        return 0;
    }
    return 1 + count_digits(number / 10);
}

int get_number(const int &a, const int &b)
{
    int num_digits_a = count_digits(a);
    int num_digits_b = count_digits(b);
    if (num_digits_a != 3 || num_digits_b != 3)
    {
        std::cerr << "a and b must be three digit numbers" << std::endl;
    }
    return a * b;
}

void check_palindromic(int number){
    int num_digits = count_digits(number); 
    if(num_digits % 2 != 0){
        std::cout<<"The number cannot be"<<std::endl;
    }   
}
int main(int argc, char **argv)
{

    int a = 111; 
    int b = 540; 
    int c = get_number(a, b); 
    check_palindromic(c); 
    return 0;
}