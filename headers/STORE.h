#include "Method.h"

class STORE : public Method {
  
  private:

  char op_;
  int value_;

  public:

  STORE(char op,int value) {
    op_ = op;
    value_ = value;
  }

  string print() {
    return "STORE";
  }
   int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
       switch(op_) {
        case '*':
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          for(int i = registros->size() - 1; i < registros->at(value_); i++) {
            registros->push_back(0);
          }
          registros->at(registros->at(value_)) = registros->at(0);
        break;
        case ' ':
          if(value_ != 0) {
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          registros->at(value_) = registros->at(0);
          }
          break;
      }
      IP++;
      return IP;
   }
};