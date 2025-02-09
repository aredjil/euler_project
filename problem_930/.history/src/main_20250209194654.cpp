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

    std::fill(balls.begin(), balls.end(), 0);
    std::fill(bowls.begin(), bowls.end(), 0);

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

int get_max(const std::vector<int> &bowls)
{
    if (!bowls.empty())
    {
        auto max_it = std::max_element(bowls.begin(), bowls.end());

        int max_value = *max_it;

        int max_index = std::distance(bowls.begin(), max_it);

        return max_value;
    }
    else
    {
        std::cout << "The vector is empty.\n";
        return -1;
    }
}

double
get_expected_steps(std::vector<int> &bowls, std::vector<int> &balls, const int &n_steps)
{

    int n = bowls.size();
    int m = balls.size();

    std::vector<double> counts(n_steps, 0.0);

    for (int i = 0; i < n_steps; ++i)
    {
        init(balls, bowls);
        int max = get_max(bowls);
        int count = 0;
        while (max != m)
        {
            step(balls, bowls);
            max = get_max(bowls);
            count++;
            counts[i] += 1;
        }
    }

    double sum = std::accumulate(counts.begin(), counts.end(), 0);

    double avg = sum / counts.size();
    return avg;
}

int main(int argc, char **argv)
{
    // int n{2};         // Number of bowls
    // int m{2};         //  Number of balls
    int n_steps{100}; // Number of steps
    int N{3};
    int M{3};
    for (int i = 1; i < argc; ++i)
    {
        // if (std::string(argv[i]) == "-n" && i + 1 < argc)
        // {
        //     n = std::atoi(argv[++i]);
        // }
        // if (std::string(argv[i]) == "-m" && i + 1 < argc)
        // {
        //     m = std::atoi(argv[++i]);
        // }
        if (std::string(argv[i]) == "--steps" && i + 1 < argc)
        {
            n_steps = std::atoi(argv[++i]);
        }
    }
    // std::cout << "Number of balls: " << m << "\n";
    // std::cout << "Number of bowls: " << n << "\n\n";
    // std::vector<int> bowls; // Vector to track the size of the bowls
    // std::vector<int> balls; // Vector to track the size of the bowls
    double total_sum = 0.0;
    int count = 0;

    // Iterate over all combinations of n and m from 2 to 6
    for (int n = 2; n <= 3; ++n)
    {
        for (int m = 2; m <= 3; ++m)
        {
            std::vector<int> bowls(n, 0);
            std::vector<int> balls(m, 0);
            double expected_steps = get_expected_steps(bowls, balls, n_steps);
            total_sum += expected_steps;
            count++;
            std::cout << "n = " << n << ", m = " << m << ", Expected Steps = " << expected_steps << std::endl;
        }
    }

    double average = total_sum / count;
    std::cout << "Average Expected Steps: " << average << std::endl;

    // double avg = get_expected_steps(bowls, balls, n_steps);
    return 0;
}