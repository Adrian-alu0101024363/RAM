#include "Method.h"

class WRITE : public Method {

  private: 

  char op_;
  int value_;
  
  public:

  WRITE(char op,int value) {
    op_ = op;
    value_ = value;
  }

  string print() {
    return "WRITE";
  }
   int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
       switch(op_) {
        case '=':
          output->push_back(value_);
          break;
        case '*':
          output->push_back(registros->at(registros->at(value_)));
          break;
        case ' ':
          if(value_ != 0) {
            output->push_back(registros->at(value_));
          }
          break;
      }
      IP++;
      return IP;
   }
};
   