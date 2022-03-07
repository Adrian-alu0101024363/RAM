#ifndef METHOD
#define METHOD
#include "instructions.h"
#include <string>
#include <vector>
using namespace std;

class Method {
  public:
  virtual std::string print() = 0;
  virtual int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) = 0;
};
#endif