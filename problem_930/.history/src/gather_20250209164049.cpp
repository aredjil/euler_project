#include "gather.hpp"


Bowls::Bowls(int num_bowls, int num_balls)
: n(num_bowls)
, m(num_balls)
{
   gen(dv());
   this->bowls.resize(n, 0);
}
void
Bowls::init(){
    int count = this->m;
    while (count != 0)
    {
            std::uniform_int_distribution<int> dist(0, n);

        random_idx = dist(gen);
        bowls[random_idx] += 1;
        count--;
    }

}