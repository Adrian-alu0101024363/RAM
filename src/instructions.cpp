#include "../headers/instructions.h"

using namespace std;

Instruction_t::Instruction_t(Method* method,char op, int value) {
  operator_ = op;
  value_ = value;
  method_ = method;
}
Instruction_t::Instruction_t(Method* method) {
  method_ = method;
}

Instruction_t::~Instruction_t() {}

char Instruction_t::get_op() {
  return operator_;
}

int Instruction_t::get_value() {
  return value_;
}

void Instruction_t::set_op(char op) {
  operator_ = op;
}

void Instruction_t::set_value(int value) {
  value_ = value;
}

Method* Instruction_t::get_method() {
  return method_;
}