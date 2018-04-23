#ifndef POTTS_MONTE_CARLO_
#define POTTS_MONTE_CARLO_

#include <iostream>
#include <vector>
#include <cmath>
#include <boost/random.hpp>
#include <alps/accumulators.hpp>
#include "options.hpp"
#include "graph.hpp"
class potts
{
private:
  const int dim;
  const int size;
  const unsigned int num_states; // num_states Potts model
  const double J; // Coupling constant
  const unsigned int parallel;
  const double temperature;
  const unsigned int SWEEP;
  const unsigned int THERMALIZATION;
  const unsigned int seed;

  std::vector<boost::mt19937> eng_set;
  std::vector<boost::variate_generator<boost::mt19937&, boost::uniform_real<> > >random_set;
  
  std::vector<std::vector<graph> > cnfg_set;
  
  
  unsigned int random_N(int para);
  
public:
  potts(options);
  ~potts();
  void update(int para);
  
};



#endif
