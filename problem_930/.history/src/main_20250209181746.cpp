#include "gather.hpp"

std::random_device dv;
std::mt19937 gen(dv());

void step(std::vector<int> &balls, std::vector<int> &bowls)
{
    int m = balls.size();
    int n = bowls.size();

    int rd_ball;
    int rd_dir;
    // Choosing a random ball
    std::uniform_int_distribution<int> choose_ball(0, m - 1);

    // Printing the current location of the randomly choosen ball
    rd_ball = choose_ball(gen);
    // Generating a random direction (clockwise 1 or anticlockwise 0)

    std::uniform_int_distribution<int> rd_direction(0, 1);
    rd_dir = rd_direction(gen);

    bowls[balls[rd_ball]] -= 1; // Removing the randomly chosen ball from its currrent location

    if (rd_dir)
    {
        int new_position = (balls[rd_ball] + 1) % n;
        bowls[new_position] += 1;      // Updating the bowls
        balls[rd_ball] = new_position; // Updating the location of the ball
    }
    else
    {
        int new_position = (balls[rd_ball] - 1 + n) % n;
        bowls[new_position] += 1;      // Updating the bowls
        balls[rd_ball] = new_position; // Updating the location of the ball
    }
}

void init(std::vector<int> &balls, std::vector<int> &bowls)
{

    int n = bowls.size();
    int m = balls.size();
    int rd_idx;
    // Intilizing the balls randomly in bowls
    std::uniform_int_distribution<int> dist(0, n - 1);
    for (int i = 0; i < m; i++)
    {
        rd_idx = dist(gen);
        balls[i] = rd_idx;
        bowls[rd_idx] += 1;
    }
}

int get_max(std::vector<int> &bowls)
{
    if (!bowls.empty())
    {
        auto max_it = std::max_element(bowls.begin(), bowls.end());

        int max_value = *max_it;

        int max_index = std::distance(bowls.begin(), max_it);

        // std::cout << "The maximum element is " << max_value
        //           << " at index " << max_index << ".\n";
        return max_value;
    }
    else
    {
        std::cout << "The vector is empty.\n";
        return -1;
    }
}

int main(int argc, char **argv)
{
    int n{3}; // Number of bowls
    int m{2}; //  Number of balls
    int n_steps = 10;
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
    init(balls, bowls);

    int count = 0;
    int max = 0;
    std::vector<int> counts(n_steps);
    for (int i = 0; i < n_steps; ++i)
    {
        while (max != m)
        {
            step(balls, bowls);
            max = get_max(bowls);
            count++;
        }
        counts[i] = count;
    }
    for(auto element:counts){
        std::cout<<""
    }
    return 0;
}