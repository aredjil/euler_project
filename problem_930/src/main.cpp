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
    // auto start = std::chrono::high_resolution_clock::now();
    // double total_sum = 0.0;
    // int count = 1;
    // Iterate over all combinations of n and m from 2 to 6
    // #pragma omp parallel for collapse(2) reduction(+ : total_sum)
    //     for (int n = 2; n <= N; ++n)
    //     {
    //         for (int m = 2; m <= M; ++m)
    //         {
    //             double expected_steps = get_expected_steps(n, m, n_steps);
    // #pragma omp atomic
    //             total_sum += expected_steps;
    //         }
    //     }
    double local_sum = 0.0;
    double total_sum = 0.0;

// Distribute 'n' iterations among processes
#pragma omp parallel for collapse(2) reduction(+ : total_sum)
    for (int n = 2 + rank; n <= N; n += size)
    {
        for (int m = 2; m <= M; ++m)
        {
            #pragma omp atomic
            local_sum += get_expected_steps(n, m, n_steps);
        }
    }

    // Reduce all local sums into total_sum on rank 0
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        std::cout << std::scientific << std::setprecision(12) << std::endl;
        std::cout << "Total sum: " << total_sum << std::endl;
    }

    MPI_Finalize();

    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "\nElapsed time: " << elapsed.count() << " seconds\n";
    // std::cout << std::scientific << std::setprecision(12) << std::endl;
    // std::cout << "Average Expected Steps: " << total_sum << std::endl;

    return 0;
}