#include "Method.h"

class ADD : public Method {

  private: 

  char op_;
  int value_;
  
  public:

  ADD(char op,int value) {
    op_ = op;
    value_ = value; 
  }

  string print() {
    return "ADD";
  }
    int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {

      switch(op_) {
        case '=':
          registros->at(0) = registros->at(0) + value_;
          break;
        case '*':
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          for(int i = registros->size() - 1; i < registros->at(value_); i++) {
            registros->push_back(0);
          }
          registros->at(0) = registros->at(0) + registros->at(registros->at(value_));
        break;
        case ' ':
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          registros->at(0) = registros->at(0) + registros->at(value_);
          break;
      }
      IP++;
      return IP;
    }
};