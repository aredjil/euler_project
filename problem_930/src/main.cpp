#include "gather.hpp"

int main(int argc, char **argv)
{

    int n_steps{1000}; // Number of steps
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
            M = std::atoi(argv[++i]);
        }
        if (std::string(argv[i]) == "--steps" && i + 1 < argc)
        {
            n_steps = std::atoi(argv[++i]);
        }
    }

    double total_sum = 0.0;
    int count = 0;
    // Iterate over all combinations of n and m from 2 to 6
#pragma omp parallel for collapse(2) reduction(+ : total_sum) reduction(+ : count)
    for (int n = 2; n <= N; ++n)
    {
        for (int m = 2; m <= M; ++m)
        {
            std::vector<int> bowls(n, 0);
            std::vector<int> balls(m, 0);
            double expected_steps = get_expected_steps(bowls, balls, n_steps);
#pragma omp atomic
            total_sum += expected_steps;
#pragma omp atomic
            count++;
        }
    }
    std::cout << std::scientific << std::setprecision(12) << std::endl;
    std::cout << "Average Expected Steps: " << total_sum << std::endl;

    // double avg = get_expected_steps(bowls, balls, n_steps);
    return 0;
}