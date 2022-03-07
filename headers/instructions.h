#ifndef INSTRUCTIONS
#define INSTRUCTIONS
#include <iostream>
#include <string>
#include "Method.h"

using namespace std;


class Instruction_t {
  
  protected:
    Method* method_;
    char operator_;
    int value_;
    string tag_;
  public:
    Instruction_t(Method* method);
    Instruction_t(Method* method,char op, int value);
    ~Instruction_t();
    char get_op();
    void set_op(char op);
    int get_value();
    void set_value(int value);
    Method* get_method();
    string get_tag() {return tag_;};
    void set_tag(string tag) {tag_ = tag;};
};
#endif