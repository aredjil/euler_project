#include "gather.hpp"

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

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

    double local_sum = 0.0;
    double total_sum = 0.0;

    for (int n = 2; n <= N; ++n) // Don't distribute n across ranks
    {
        for (int m = 2; m <= M; ++m)
        {
            double local_result = get_expected_steps(n, m, n_steps, rank, size);
            double global_result = 0.0;

            MPI_Reduce(&local_result, &global_result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            if (rank == 0)
            {
                local_sum += global_result;
            }
        }
    }

    if (rank == 0)
    {
        std::cout << std::scientific << std::setprecision(12) << std::endl;
        std::cout << "Total sum: " << local_sum << std::endl;
    }

    MPI_Finalize();

    return 0;
}