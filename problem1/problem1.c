#include<stdio.h>

int multiples(int a, int b, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % a == 0|| i % b == 0)
        {
            sum+=i;
        }
        
    }
    return sum;
    
}
int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 5;
    int n = 1000;
    int result = multiples(a, b, n);
    printf("%d\n", result);
    return 0;
}
