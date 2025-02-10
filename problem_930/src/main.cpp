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
    auto start = std::chrono::high_resolution_clock::now();
    double total_sum = 0.0;
    // Iterate over all combinations of n and m from 2 to 6
#pragma omp parallel for collapse(2) reduction(+ : total_sum) 
    for (int n = 2; n <= N; ++n)
    {
        for (int m = 2; m <= M; ++m)
        {
            std::vector<int> bowls(n, 0);
            std::vector<int> balls(m, 0);
            std::cout<<"Computing F("<<n<<","<<m<<")\n";
            double expected_steps = get_expected_steps(bowls, balls, n_steps);
#pragma omp atomic
            total_sum += expected_steps;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nElapsed time: " << elapsed.count() << " seconds\n";
    std::cout << std::scientific << std::setprecision(12) << std::endl;
    std::cout << "Average Expected Steps: " << total_sum << std::endl;

    return 0;
}