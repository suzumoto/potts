#include "potts.hpp"
#include <omp.h>

potts::potts(options p) :
  dim(p.dim),
  size(p.size),
  num_states(p.num_states),
  J(p.J),
  parallel(p.parallel),
  temperature(p.temperature),
  SWEEP(p.SWEEP),
  THERMALIZATION(p.THERMALIZATION),
  seed(p.seed),
  cnfg_set(parallel,std::vector<unsigned int>(pow(size,dim),0))
{
  for(int i = 0; i < parallel; ++i){
    eng_set.push_back(boost::mt19937(seed + 94 * i));
    random_set.push_back(boost::variate_generator<boost::mt19937&, boost::uniform_real<> >(eng_set[i],boost::uniform_real<>()));
  }
}

unsigned int potts::random_N(int para){
  return floor((random_set[para])() * (cnfg_set[para]).size());
}
potts::~potts(){};
void potts::update(int para){
  std::cout << random_N(para) << std::endl;
}
