#include<stdio.h>
int fibonacci_seq_term(int n){
    if(n ==1){
        return 1;
    }if(n == 0){
        return 1;
    }
    else{
        return fibonacci_seq_term(n-1) + fibonacci_seq_term(n-2);
    }
}
int sum_even(int n){
    int sum = 0;
    int j;
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = fibonacci_seq_term(i);
        if(temp % 2 == 0){
            sum += temp;
        }if(temp > 4E6){
            j = i;
            break;
        }
    }
    return sum;
    
}
int main(){
    int n = 4E6;
    int result = sum_even(n);
    printf("%d\n", result);
    return 0;
}