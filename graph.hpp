#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class graph
{
private:
  unsigned int id_;
  std::vector<unsigned int> connected_;
  int state_;
public:
  graph(int size, std::string type, unsigned int id, int state);
  ~graph(){};
  unsigned int get_id(){return id_;};
  int get_state(){return state_;};
  std::vector<unsigned int> get_connected(){return connected_;};
};

#endif
