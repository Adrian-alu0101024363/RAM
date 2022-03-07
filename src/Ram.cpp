#include "../headers/Ram.h"


using namespace std;

// Ram constructor initialize the instructions vector, the input tape, the output tape, 
// the registers with the R0, the tags and set the instruction pointer to 0
Ram_t::Ram_t():
  instructions_(),
  input_(),
  output_(),
  registros_(1),
  IP_(0),
  tags_() {
    
}
Ram_t::~Ram_t(){}

// Delete all the comments that start with # or ;
bool Ram_t::deleteComent(string& line) {
  bool iscomment = false;
  string::size_type pos = line.find(";");
  if (pos != string::npos) {
    line.erase(pos,line.length());
  }
  string::size_type pos2 = line.find("#");
  if (pos2 != string::npos) {
    line.erase(pos2,line.length());
  } 
  if (pos == 0 || pos2 == 0) {
    iscomment = true;
  }
  return iscomment;
}

// Extract the tag from a given line and push it to the tag vector
bool Ram_t::trimTag(string& line) {
  string::size_type pos = line.find(":");
  string tag = line;
  bool istag = false;
  if(pos != string::npos) {
    tag.erase(pos,tag.length());
    Instruction_t* inst = new Instruction_t(new TAG(tag),'h',0);
    inst->set_tag(tag);
    instructions_.push_back(*inst);
    line.erase(0,pos + 2);
    istag = true;
  }
  return istag;
}

// Check if an instructions is valid and if it's push it to the instructions vector
void Ram_t::valid (string line,int atline) {
  regex load("LOAD[0-9]");
  regex loada("LOAD(=|\\*)[0-9]");
  regex storei("STORE\\*[0-9]");
  regex store("STORE[0-9]");
  regex ad("ADD[0-9]");
  regex ada("ADD(=|\\*)[0-9]");
  regex sub("SUB[0-9]");
  regex suba("SUB(=|\\*)[0-9]");
  regex mult("(MUL|MULT)[0-9]");
  regex multa("(MUL|MULT)(=|\\*)[0-9]");
  regex div("DIV[0-9]");
  regex diva("DIV(=|\\*)[0-9]");
  regex readi("READ\\*[1-9]");
  regex read("READ[1-9]");
  regex write("WRITE[1-9]");
  regex writea("WRITE((\\*[1-9])|(=[0-9]))");
  regex jump("JUMP[A-Z]+[0-9]*");
  regex jgtz("JGTZ[A-Z]+[0-9]*");
  regex jzero("JZERO[A-Z]+[0-9]*");
  size_t i = 0;
for ( ; i < line.length(); i++ ){ if ( isdigit(line[i]) ) break; }
// remove the first chars, which aren't digits
string str = line.substr(i, line.length() - i );
// convert the remaining text to an integer
int number = atoi(str.c_str());
  if (regex_search(line,load)) {
    Instruction_t* inst = new Instruction_t(new LOAD(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,storei)) {
    Instruction_t* inst = new Instruction_t(new STORE(line[5],number),line[5],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,loada)) {
    Instruction_t* inst = new Instruction_t(new LOAD(line[4],number),line[4],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,ad)) {
    Instruction_t* inst = new Instruction_t(new ADD(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,ada)) {
    Instruction_t* inst = new Instruction_t(new ADD(line[3],number),line[3],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,store)) {
    Instruction_t* inst = new Instruction_t(new STORE(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,sub)) {
    Instruction_t* inst = new Instruction_t(new SUB(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,suba)) {
    Instruction_t* inst = new Instruction_t(new SUB(line[3],number),line[3],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,mult)) {
    Instruction_t* inst = new Instruction_t(new MUL(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,multa)) {
    if (line[3] == 'T') {
      Instruction_t* inst = new Instruction_t(new MUL(line[4],number),line[4],number);
      instructions_.push_back(*inst);
    } else {
      Instruction_t* inst = new Instruction_t(new MUL(line[3],number),line[3],number);
      instructions_.push_back(*inst);
    }
  } else if (regex_search(line,div)) {
    Instruction_t* inst = new Instruction_t(new DIV(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,diva)) {
    Instruction_t* inst = new Instruction_t(new DIV(line[3],number),line[3],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,readi)) {
    Instruction_t* inst = new Instruction_t(new READ(line[4],number),line[4],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,read)) {
    Instruction_t* inst = new Instruction_t(new READ(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,writea)) {
    Instruction_t* inst = new Instruction_t(new WRITE(line[5],number),line[5],number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,write)) {
    Instruction_t* inst = new Instruction_t(new WRITE(' ',number),' ',number);
    instructions_.push_back(*inst);
  } else if (regex_search(line,jump)) {
    std::size_t pos = line.find_first_of("P");
    string tag = line.substr(pos + 1,line.length());
    Instruction_t* inst = new Instruction_t(new JUMP(tag),'h',0);
    instructions_.push_back(*inst);
  } else if (regex_search(line,jgtz)) {
    std::size_t pos = line.find_first_of("Z");
    string tag = line.substr(pos + 1,line.length());
    Instruction_t* inst = new Instruction_t(new JGTZ(tag),'h',0);
    instructions_.push_back(*inst);    
  } else if (regex_search(line,jzero)) {
    std::size_t pos = line.find_first_of("O");
    string tag = line.substr(pos + 1,line.length());
    Instruction_t* inst = new Instruction_t(new JZERO(tag),'h',0);
    instructions_.push_back(*inst);
  } else {
    cout << "Instruction no valida en la linea " << atline << endl;
    cout << line;
    IP_ = -1;
  }
}

// Read the ram file with the instructions using the trimtag, deletecoment and valid methods
void Ram_t::readInstructions(string inst) {
  fstream file;
  file.open(inst);
  string line;
  int atline = 1;
  bool istag = false;
  bool iscomment = false;
  while (getline(file,line)) {
    std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
    line.erase(end_pos, line.end());
    iscomment = deleteComent(line);
    transform(line.begin(), line.end(),line.begin(), ::toupper);
    istag = trimTag(line);
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line == "HALT") { 
      Instruction_t* inst = new Instruction_t(new HALT(),'h',0);
      instructions_.push_back(*inst);
    } else if (!iscomment && line.length() != 0) {
     valid(line,atline);
    } else {

    }
     atline++;
    }
      for(int i = 0; i < instructions_.size(); i++) {
      tags_.push_back(" ");
    }
    for(int i = 0; i < instructions_.size(); i++) {
      if (instructions_[i].get_method()->print() == "TAG") {
        tags_[i] = instructions_[i].get_tag();
      }
  }
  file.close();
}

// Read the input file into the input tape
void Ram_t::readInput(string input) {
  fstream ifile;
  ifile.open(input);
  int value;
  while (ifile >> value) {
    input_.push_back(value);
  }
  ifile.close();
}

// Write the RAM specification to console
void Ram_t::write() {
  for(int i = 0; i < instructions_.size(); i++) {
    if (instructions_[i].get_method()->print() == "TAG") {
      cout << instructions_[i].get_tag() << ":" << endl;
    } else {
    cout << instructions_[i].get_method()->print();
    if (instructions_[i].get_op() != 'h') {
      cout << instructions_[i].get_op() << " ";
      cout << instructions_[i].get_value();
      }
    cout << endl;
    }
  }
}

// Write the input tape content to console
void Ram_t::writeInput() {
  for (int i = 0; i < input_.size(); i++) {
    cout << input_[i] << "\t";
  }
  cout << endl;
}

// Write the registers state to console
void Ram_t::writeRegistros() {
  for (int i = 0; i < registros_.size(); i++) {
    cout << registros_[i] << "\t";
  }
  cout << endl;
}

// Write the tags vector to console
void Ram_t::writeTags() {
  for (int i = 0; i < tags_.size(); i++) {
    cout << tags_[i] << endl;
  }
}

// Write the output tape to console
void Ram_t::writeOutputs() {
  for (int i = 0; i < output_.size(); i++) {
    cout << output_[i] << "\t";
  }
  cout << endl;
}

// Write the output tape to file
void Ram_t::writeToFile(string file) {
  ofstream ofile;
  ofile.open(file);
  for (int i = 0; i < output_.size(); i++) {
    ofile << output_[i] << " ";
  }
  ofile.close();
}

// Execute the RAM machine aka the instructions following the IP if debug is 1 print info
void Ram_t::exe(string debug) {
  bool changeinput = false;
  int contador = 0;
  registros_[0] = 0;
  int inputcount = 0;
  while (IP_ < instructions_.size()) {
    int ipcopy = IP_;
    changeinput = false;
    contador++;
    if (IP_ == -1) {
        cout << "Error en la línea: " << contador << endl;
        break;
    } else {
      if (instructions_[IP_].get_method()->print() == "READ") {
        changeinput = true;
      }
      IP_ = instructions_[IP_].get_method()->execute(&registros_,tags_,IP_,inputcount,input_,&output_);
      if (changeinput) {
        inputcount++;
      }
      if (debug == "1" && IP_ != 1) {
      cout << "Ip " << ipcopy << endl;
      cout << "Estado de los registros: " << endl;
      writeRegistros();
      cout << "Instruccion ejecutando:" << instructions_[ipcopy].get_method()->print();
      cout << endl;
      //writeTags();
      cout << "Cinta de salida:" << endl;
      writeOutputs();
      } 
    }
  }
  cout << endl;

}
