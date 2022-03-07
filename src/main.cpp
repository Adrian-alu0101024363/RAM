#include <iostream>
#include <string>
#include "../headers/Ram.h"

using namespace std;


int main (int argc, char *argv[] ) {
  string inst, input,debug,output, options = "";
  Ram_t ram;
  if (argc < 4) {
    cout << "Formato no valido del comando" << endl; 
  } else if (argc == 5) {
    inst = argv[1];
    input = argv[2];
    output = argv[3];
    debug = argv[4];
    ram.readInstructions(inst);
    ram.readInput(input);
    if (debug == "1") {
      do {
      cout << ">h" << endl << "r:ver los registros" << endl;
      cout << "t:traza" << endl << "e:ejecutar" << endl;
      cout << "s:desensamblador" << endl << "i:ver cinta entrada" << endl;
      cout << "o:ver cinta salida" << endl << "h:ayuda" << endl;
      cout << "x:salir" << endl << ">" << endl; 
      cin >> options;
      if (options == "i") ram.writeInput();
      if (options == "s") ram.write();
      if (options == "r") ram.writeRegistros();
      if (options == "e") {
        ram.exe("0");
        ram.writeToFile(output);
      }
      if (options == "t") {
        ram.exe("1");
        ram.writeToFile(output);
      }
      if (options == "o") ram.writeOutputs();
      if (options == "h") cout << "mostrando ayuda";
      } while (options != "x");
    }
  } else {
    inst = argv[1];
    input = argv[2];
    output = argv[3];
    ram.readInstructions(inst);
    ram.readInput(input);
    ram.exe("0");
    ram.writeToFile(output);
    cout << "Numero de instrucciones: ";
    ram.writenumber();
    //ram.write();
  }
  return 0;
}