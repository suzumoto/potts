#include "graph.hpp"

enum lattice_type{
  square,
  simple_cubic,
  triangle,
  kagome,
  hyper_kagome,
  error
};

graph::graph(int size, std::string type, unsigned int id, int state){
  lattice_type type_number = error;
  if(type == "square"){
    type_number = square;
  }else if (type == "simple_cubic"){
    type_number = simple_cubic;
  }else if (type == "triangle"){
    type_number = triangle;
  }else if (type == "kagome"){
    type_number = kagome;
  }else if (type == "hyper_kagome"){
    type_number == hyper_kagome;
  }
  id_ = id;
  state_ = state;
  switch(type_number){
  case square :
    if(id >= size) connected_.push_back(id - size);
    else connected_.push_back(size*(size-1) + id);
    if(id % size != 0) connected_.push_back(id-1);
    else connected_.push_back(id + size - 1);
    if(id%size != size - 1) connected_.push_back(id + 1);
    else connected_.push_back(id - size + 1);
    if(id + size < size*size) connected_.push_back(id + size);
    else connected_.push_back(id % size);
    break;
  case simple_cubic:
    break;
  case triangle:
    break;
  case kagome:
    break;
  case hyper_kagome:
    break;
  default:
    std::cerr << "invalid lattice type" << std::endl;
    std::cout << "square, simple_cubic, triangle, kagome and hyper_kagome are supported" << std::endl;
    break;
  }
};
