#include "potts.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){
  options p(argc,argv,true);
  if(!p.valid){
    p.usage(true);
    exit(127);
  }
  potts mc_simulation(p);
  for(int i = 0; i < 100; ++i){
    mc_simulation.update(0);
  }
  return 0;
}
