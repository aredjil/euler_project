#include "gather.hpp"


Bowls::Bowls(int num_bowls, int num_balls)
: n(num_bowls)
, m(num_balls)
{
   std::mt19937 gen(dv());
   this->bowls.resize(n, 0);
}
void
Bowls::init(){
    
}