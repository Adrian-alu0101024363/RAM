//#include "instructions.h"
#include "Method.h"

using namespace std;

class HALT : public Method {
  
  
  public:
  string print() { return "HALT";}
  int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
    return -1;
  }
};