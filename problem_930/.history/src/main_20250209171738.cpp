#include "gather.hpp"

std::random_device dv;
std::mt19937 gen(dv());
int main(int argc, char **argv)
{
    int n{5};  // Number of bowls
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
    std::cout<<"Number of balls: "<<m<<"\n";
    std::cout<<"Number of bowls: "<<n<<"\n\n";
    std::vector<ball> balls(m);
    std::vector<bowl> bowls(n);

    for (size_t i = 0; i < m; i++)
    {
        balls[i].id = i;
    }
    for (size_t i = 0; i < n; i++)
    {
        bowls[i].id = i;
    }

    std::uniform_int_distribution<int> dist(0, n - 1);
    for (int i = 0; i < m; i++)
    {
        random_idx = dist(gen);
        bowls[random_idx].size += 1;
        balls[i].loc = random_idx;
    }

    for (auto ball : balls)
    {
        std::cout << "ball " << ball.id << " -> " << ball.loc << "\n";
    }
    std::cout<<"\n";
    for (auto bowl : bowls)
    {
        std::cout << "Bowl:" << bowl.id << " -> " << bowl.size << "\n";
    }

    std::uniform_int_distribution<int> choose_ball(0, m-1);
    std::uniform_int_distribution<int> direction(0, 1);

    int random_ball = choose_ball(gen);
    std::cout<<"The random chosen ball is: "<<random_ball<<"\n";
    std::cout<<"The direction is: "<< direction(gen) * 2 -1<<"\n";

    balls[choose_ball].loc = balls[choose_ball].loc + 
    return 0;
}