#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <regex>
#include "instructions.h"
#include "headers.h"


using namespace std;

class Ram_t {

  private:
  
  vector<Instruction_t> instructions_;
  vector<int> input_;
  vector<int> output_;
  vector<string> tags_;
  vector<int> registros_;
  int IP_;

  public: 

  Ram_t();

  ~Ram_t();

  void readInstructions(string inst);

  void readInput(string input);

  void write();

  void writeInput();

  void writeRegistros();

  void writeTags();

  void writeOutputs();

  void writenumber() {cout << instructions_.size();};

  void writeToFile(string file);

  bool deleteComent(string& line);

  bool trimTag(string& line);

  void valid(string line,int atline);
  
  void exe(string debug); 

};
