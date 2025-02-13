#include "gather.hpp"

int get_rd(const int &lower, const int &upper)
{
    thread_local std::mt19937 gen(1);
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(gen);
}

void step(int* balls, int* bowls, const int &n, const int &m)
{
    const int rd_ball = get_rd(0, m - 1);
    const int rd_dir = (get_rd(0, 1) << 1) - 1;
    int &pos = balls[rd_ball];
    bowls[pos] -= 1;
    pos = (pos + rd_dir + n) % n;
    bowls[pos] += 1;
}

void init(int* &balls, int* &bowls, const int &n, const int &m)
{
    int* new_balls = new int[m]();
    int* new_bowls = new int[n]();
    
    #ifdef _OPENACC
    #pragma acc parallel loop copyin(n) copyout(new_bowls[0:n])
    #endif 
    for (int i = 0; i < n; ++i) {
        new_bowls[i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int rd_idx = get_rd(0, n - 1);
        new_balls[i] = rd_idx;
        new_bowls[rd_idx]++;
    }
    
    delete[] bowls;  // Free old memory if needed
    delete[] balls;  // Free old memory if needed

    balls = new_balls;
    bowls = new_bowls;
}

int get_max(const int* bowls, const int size)
{
    int max_val = 0;
    #ifdef _OPENACC
    #pragma acc parallel loop reduction(max:max_val) copyin(bowls[0:size])
    #endif
    for (int i = 0; i < size; ++i) {
        if (bowls[i] > max_val) {
            max_val = bowls[i];
        }
    }
    return max_val;
}

double get_expected_steps(const int &n, const int &m, const int &n_steps)
{
    int* bowls = new int[n]();
    int* balls = new int[m]();
    double sum = 0.0;
    
    #ifdef _OPENACC
//    #pragma acc parallel loop reduction(+:sum) \
        private(bowls, balls) \
        copyin(n, m)
    #endif
    for (int i = 0; i < n_steps; ++i)
    {
        int local_count = 0;
        init(balls, bowls, n, m);
        int max = get_max(bowls, n);
        
        while (max != m)
        {
            step(balls, bowls, n, m);
            local_count++;
            max = get_max(bowls, n);
        }
        sum += local_count;
    }
    
    // Clean up dynamically allocated arrays
    delete[] bowls;
    delete[] balls;
    
    return sum / n_steps;
}

