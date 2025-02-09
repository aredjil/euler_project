#include "gather.hpp"

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