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

    Bowls bowl(m, n);
    bowl.init();
    for(int i=0;i<n;++i){
        std::cout<<"Bowl  "<<i<<"->"<<bowl.bowls[i]<<"\n\n";
    }

    return 0;
}