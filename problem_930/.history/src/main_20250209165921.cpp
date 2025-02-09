#include"gather.hpp"

int main(int argc, char **argv)
{
    int n{5}; // Number of bowls
    int m{10}; //  Number of balls
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
    std::vector<ball> balls(m);
    
    return 0;
}