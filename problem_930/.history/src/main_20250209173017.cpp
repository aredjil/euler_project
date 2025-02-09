#include "gather.hpp"

std::random_device dv;
std::mt19937 gen(dv());
int main(int argc, char **argv)
{
    int n{5};  // Number of bowls
    int m{10}; //  Number of balls
    int rd_idx;

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
    std::cout << "Number of balls: " << m << "\n";
    std::cout << "Number of bowls: " << n << "\n\n";
    std::vector<int> balls(m); // Vector to hold track the location of the balls 
    std::vector<int> bowls(n); // Vector to track the size of the bowls 
    // Intilizing the balls randomly in bowls 
    std::uniform_int_distribution<int> dist(0, n - 1);

    for (int i = 0; i < m; i++)
    {
        rd_idx = dist(gen);
        balls[i] = rd_idx; 
        bowls[rd_idx] +=1;
    }
    for(int i =0;i<m;++i){
        std::cout<<"ball "<<i<<" -> "<<balls[i]<<"\n\n";
    }
    
    // choosing a random ball
    std::uniform_int_distribution<int> rd_ball(0, m-1);

    rd_idx = rd_ball(gen);
    std::cout<<"Random ball<< ->"<<<<"\n";

   
    
    return 0;
}