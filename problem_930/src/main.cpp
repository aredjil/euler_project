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

    double sum = 0.0;

    for (int n = 2; n <= N; ++n) // Don't distribute n across ranks
    {
        for (int m = 2; m <= M; ++m)
        {
            double result = get_expected_steps(n, m, n_steps);
                sum += result;
        }
    }
    std::cout<<std::scientific<<std::setprecision(12);
    std::cout<<sum<<"\n";
    return 0;
}