#include "gather.hpp"

int main(int argc, char **argv)
{
    // int n{2};         // Number of bowls
    // int m{2};         //  Number of balls
    int n_steps{100}; // Number of steps
    int N{3};
    int M{3};
    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-n" && i + 1 < argc)
        {
            N = std::atoi(argv[++i]);
        }
        if (std::string(argv[i]) == "-m" && i + 1 < argc)
        {
             = std::atoi(argv[++i]);
        }
        if (std::string(argv[i]) == "--steps" && i + 1 < argc)
        {
            n_steps = std::atoi(argv[++i]);
        }
    }
    // std::cout << "Number of balls: " << m << "\n";
    // std::cout << "Number of bowls: " << n << "\n\n";
    // std::vector<int> bowls; // Vector to track the size of the bowls
    // std::vector<int> balls; // Vector to track the size of the bowls
    double total_sum = 0.0;
    int count = 0;

// Iterate over all combinations of n and m from 2 to 6
    #pragma omp parallel for collapse(2) reduction(+:total_sum) reduction(+:count)
    for (int n = 2; n <= 3; ++n)
    {
        for (int m = 2; m <= 3; ++m)
        {
            std::vector<int> bowls(n, 0);
            std::vector<int> balls(m, 0);
            double expected_steps = get_expected_steps(bowls, balls, n_steps);
            #pragma omp atomic
            total_sum += expected_steps;
            #pragma omp atomic
            count++;
            std::cout << "n = " << n << ", m = " << m << ", Expected Steps = " << expected_steps << std::endl;
        }
    }
    std::cout << std::fixed << std::setprecision(12) << std::endl;
    std::cout << "Average Expected Steps: " << total_sum << std::endl;

    // double avg = get_expected_steps(bowls, balls, n_steps);
    return 0;
}