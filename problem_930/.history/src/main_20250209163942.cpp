#include"gather.hpp"

int main(int argc, char **argv)
{
    int n{2}; // Number of bowls
    int m{2}; //  Number of balls
    int random_idx;

    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-n" && i + 1 < argc)
        {
            n = std::atoi(argv[++i]);
        }
        if (std::string(argv[i]) == "-m" && i + 1 < argc)
        {
            m = std::atoi(argv[++i]);
        }
    }

    std::vector<int> bowls(n, 0);
    std::vector<int> balls(m, 1);
    std::uniform_int_distribution<int> dist(0, n);


    // for (size_t i = 0; i < n; i++)
    // {
    //     std::cout << "Bowl number: " << i << "\n\n";
    //     std::cout << "Has: " << bowls[i] << " balls\n\n";
    // }
    return 0;
}