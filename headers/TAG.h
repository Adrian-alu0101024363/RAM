#include "Method.h"

class TAG : public Method {
  
  private: 
  string tag_;

  public:

  TAG(string tag) {
    tag_ = tag;
  }
  string get_tag() { return tag_;};

  void set_tag(string tag) { tag_ = tag;}

  string print() {
    return "TAG"; //+ tag_;
  }
int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
  IP++;
  return IP;
}

};