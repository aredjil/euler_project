#include "gather.hpp"

std::random_device dv;
std::mt19937 gen(dv());

void 
step(std::vector<int> &balls, std::vector<int> &bowls){
    int n = bowls.size();
    int m = balls.size();

    

}


int main(int argc, char **argv)
{
    int n{5};  // Number of bowls
    int m{10}; //  Number of balls
    int rd_idx;
    int rd_ball;
    int rd_dir;
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
        bowls[rd_idx] += 1;
    }
    for (int i = 0; i < m; ++i)
    {
        std::cout << "ball " << i << " -> " << balls[i] << "\n\n";
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << "bowl " << i << " -> " << bowls[i] << "\n\n";
    }

    // Choosing a random ball
    std::uniform_int_distribution<int> choose_ball(0, m - 1);

    // Printing the current location of the randomly choosen ball
    rd_ball = choose_ball(gen);
    std::cout << "Random ball " << rd_ball << "->" << balls[rd_ball] << "\n";

    // Generating a random direction (clockwise 1 or anticlockwise 0)

    std::uniform_int_distribution<int> rd_direction(0, 1);
    rd_dir = rd_direction(gen);

    bowls[balls[rd_ball]] -= 1; // Removing the randomly chosen ball from its currrent location

    if (rd_dir)
    {
        std::cout << "Moving the ball clockwise\n"; // If the direction is clockwise
        bowls[(balls[rd_ball] + 1) % n] += 1;       // Updating the bowls
        balls[rd_ball] = (balls[rd_ball] + 1) % n;  // Updating the location of the ball
    }
    else
    {
        std::cout << "Moving the ball anti-clockwise\n"; // If the direction is clockwise
        bowls[(balls[rd_ball] - 1) % n] += 1;            // Updating the bowls
        balls[rd_ball] = (balls[rd_ball] - 1) % n;       // Updating the location of the ball
    }
    for (int i = 0; i < m; ++i)
    {
        std::cout << "ball " << i << " -> " << balls[i] << "\n\n";
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << "bowl " << i << " -> " << bowls[i] << "\n\n";
    }

    return 0;
}