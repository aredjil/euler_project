#include "gather.hpp"


Bowls::Bowls(int num_bowls, int num_balls)
: n(num_bowls)
, m(num_balls)
, gen(std::random_device{}())
{
   this->bowls.resize(n, 0);
}
void
Bowls::init(){
    int count = this->m;
    std::uniform_int_distribution<int> dist(0, n);
    for(int i=0;i<count;++i){
        int random_idx = dist(gen);
        bowls[random_idx] +=1;
    }
}