#include "Method.h"

class DIV : public Method {

  private:

  char op_;
  int value_;
  
  public:

  DIV(char op,int value) {
    op_ = op;
    value_ = value;
  }

  string print() {
    return "DIV";
  }

  int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {

      switch(op_) {
        case '=':
          if (value_ = 0) {
            cout << "Error division por cero usando el registro 0" << endl;
            return -1;

          } else { 
            registros->at(0) = registros->at(0) / value_;
          }
          break;
        case '*':
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          for(int i = registros->size() - 1; i < registros->at(value_); i++) {
            registros->push_back(0);
          }
          if (registros->at(registros->at(value_) == 0)) {
            cout << "Error division por cero usando el registro: " << value_ << endl;
            return -1;
          } else {
          registros->at(0) = registros->at(0) / registros->at(registros->at(value_));
          }
        break;
        case ' ':
          for(int i = registros->size() - 1; i < value_; i++) {
            registros->push_back(0);
          }
          registros->at(0) = registros->at(0) / registros->at(value_);
          break;
      }
      IP++;
      return IP;
    }    
};