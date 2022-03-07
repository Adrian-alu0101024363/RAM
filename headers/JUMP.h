#include "Method.h"

class JUMP : public Method {
  
  private: 
  string tag_;

  public:

  JUMP(string tag) {
    tag_ = tag;
  }
  string print() {
    return "JUMP " + tag_;
  }
    int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
      bool fin = false;

        for(int i = 0;((i < tags.size()) && (!fin)); i++) {
          if(tags[i] != " ") {
            if(tags[i] == tag_) {
              fin = true;
              IP = i;
            }
        }
    }
    return IP;
  }
};