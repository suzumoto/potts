#include "potts.hpp"
#include <boost/lexical_cast.hpp>
#include <cstdlib>

int main(int argc, char* argv[]){
  if(argc < 2){
    std::cerr << "反復回数Nを引数にせよ" << std::endl;
    exit(127);
  }
  alps::alea::autocorr_acc<double> measurement;
  boost::mt19937 eng(3781);
  boost::variate_generator<boost::mt19937&,boost::uniform_real<> > random(eng,boost::uniform_real<>());
  
  int N = boost::lexical_cast<int>(argv[1]);
  for(int i = 0; i < N; ++i){
    measurement << random();
  }
  alps::alea::autocorr_result<double> result = measurement.finalize();
  std::cout << result.mean() << " " << result.count() << " " << result.var() << " " << result.stderror() << " " << result.tau() << std::endl;
  return 0;
}
