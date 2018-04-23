#include "graph.hpp"
#include "potts.hpp"

int main(int argc, char* argv[]){
  options p(argc,argv,true);
  if(!p.valid){
    p.usage(true);
    exit(127);
  }
  potts mc_simulation(p);
  for(int i = 0; i < pow(p.size,p.dim); ++i){
    std::cout << i << " ";
    mc_simulation.get_vertex(i).show_connection();
    std::cout << std::endl;
  }
  return 0;
}
