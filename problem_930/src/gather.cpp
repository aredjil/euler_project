#include "gather.hpp"

int get_rd(const int &lower, const int &upper)
{
    thread_local std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(gen);
}

void step(std::vector<int> &balls, std::vector<int> &bowls, const int &n, const int &m)
{
    const int rd_ball = get_rd(0, m - 1);
    const int rd_dir = get_rd(0, 1) * 2 - 1;

    bowls[balls[rd_ball]] -= 1; // Removing the randomly chosen ball from its currrent location
    const int new_position = (balls[rd_ball] + rd_dir + n) % n;
    bowls[new_position] += 1;      // Updating the bowls
    balls[rd_ball] = new_position; // Updating the location of the ball
}

void init(std::vector<int> &balls, std::vector<int> &bowls, const int &n, const int &m)
{

    std::fill(balls.begin(), balls.end(), 0);
    std::fill(bowls.begin(), bowls.end(), 0);

    int rd_idx;

    // #pragma omp parallel
    for (int i = 0; i < m; ++i)
    {
        rd_idx = get_rd(0, n - 1);
        balls[i] = rd_idx;
        bowls[rd_idx] += 1;
    }
}

int get_max(const std::vector<int> &bowls)
{
    auto max_it = std::max_element(bowls.begin(), bowls.end());

    return *max_it;
}

double
get_expected_steps(const int &n, const int &m, const int &n_steps)
{
    std::vector<int> bowls(n, 0);
    std::vector<int> balls(m, 0);
    double sum = 0.0;
    double local_sum = 0.0;
#pragma omp parallel for reduction(+ : local_sum)
    for (int i = 0; i < n_steps; ++i)
    {
        int local_count = 0;
        init(balls, bowls, n, m);
        int max = get_max(bowls);
        while (max != m)
        {
            step(balls, bowls, n, m);
            local_count++;
            max = get_max(bowls);
        }
        local_sum += local_count;
    }
    sum += local_sum;
    return sum / n_steps;
}
