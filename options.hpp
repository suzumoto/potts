#ifndef OPTIONS_
#define OPTIONS_

#include <boost/lexical_cast.hpp>
#include <iostream>

struct options {
  int dim;
  int size;
  unsigned int num_states;
  double J;
  unsigned int seed;
  double temperature;
  int SWEEP;
  int THERMALIZATION;
  bool valid;
  unsigned long long int MCS;
  unsigned int parallel;
  double step;
  
  options(unsigned int argc, char *argv[], bool print = true) :
    // default parameters
    seed(29833), temperature(1.0), SWEEP(1000), THERMALIZATION(100000), MCS(100000), parallel(1), step(0.01), dim(3), size(10), J(1.0), num_states(3),
    valid(true) {
    for (unsigned int i = 1; i < argc; ++i) {
      switch (argv[i][0]) {
      case '-' :
        switch (argv[i][1]) {
	case 'D':
	  if (++i == argc) { usage(print); return; }
	  dim = boost::lexical_cast<int>(argv[i]); break;
	case 'z':
	  if (++i == argc) { usage(print); return; }
	  size = boost::lexical_cast<int>(argv[i]); break;
	case 'q':
	  if( ++i == argc) { usage(print); return; }
	  num_states = boost::lexical_cast<unsigned int>(argv[i]); break;
	case 'J':
	  if( ++i == argc) { usage(print); return; }
	  J = boost::lexical_cast<double>(argv[i]); break;
        case 's' :
          if (++i == argc) { usage(print); return; }
          seed = boost::lexical_cast<unsigned int>(argv[i]); break;
        case 't' :
          if (++i == argc) { usage(print); return; }
          temperature = boost::lexical_cast<double>(argv[i]); break;
        case 'S' :
          if (++i == argc) { usage(print); return; }
          SWEEP = boost::lexical_cast<int>(argv[i]); break;
	case 'T':
	  if (++i == argc) { usage(print); return; }
          THERMALIZATION = boost::lexical_cast<int>(argv[i]); break;
	case 'M' :
	  if (++i == argc) { usage(print); return; }
	  MCS = boost::lexical_cast<unsigned long long int>(argv[i]); break; 
	case 'r' :
	  if (++i == argc) { usage(print); return; }
	  parallel = boost::lexical_cast<unsigned int>(argv[i]); break;
	case 'd' :
	  if (++i == argc) { usage(print); return; }
	  step = boost::lexical_cast<double>(argv[i]); break;
        case 'h' :
          usage(print, std::cout); return;
        default :
          usage(print); return;
        }
        break;
      default :
        usage(print); return;
      }
    }
    if (temperature <= 0. || SWEEP <= 0.) {
      std::cerr << "invalid parameter(s)\n"; usage(print); return;
    }
    if (print) {
      std::cout << "Seed of RNG                 = " << seed << std::endl
                << "Temperature (Atomic Unit)   = " << temperature << std::endl
                << "MCS for Thermalization      = " << THERMALIZATION << std::endl
                << "MCS for Measurement         = " << SWEEP << std::endl
		<< "MCS                         = " << MCS << std::endl
		<< "Number of parallels         = " << parallel << std::endl
		<< "Temperature step            = " << step << std::endl;
    }
  }
  void usage(bool print, std::ostream& os = std::cerr) {
    if (print)
      os << "[command line options]\n"
         << "  -s int    Seed of RNG\n"
         << "  -t double Temperature\n"
         << "  -S int    MCS for Measurement\n"
	 << "  -T double MCS for Thermalization\n"
	 << "  -M int    # of updates\n"
	 << "  -d double temperature step\n"
	 << "  -r int    parallel threads\n"
         << "  -h        this help\n";
    valid = false;
  }
};

#endif
