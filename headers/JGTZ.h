#include "Method.h"

class JGTZ : public Method {

  private: 
  string tag_;

  public:

  JGTZ(string tag) {
    tag_ = tag;
  }

  string print() {
    return "JGTZ " + tag_;
  }

    int execute(std::vector<int>* registros,vector<string> tags,int IP,int inputindex,vector<int> input,vector<int>* output ) {
      bool fin = false;
      if(registros->at(0) > 0) {
        for(int i = 0;((i < tags.size()) && (!fin)); i++) {
          if(tags[i] != "") {
            if(tags[i] == tag_) {
              fin = true;
              IP = i;
            }
          }
        }
      } else {
        IP++;
      }
      return IP;
    }
};