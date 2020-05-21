#include <iostream>
#include <fstream>

#include "node.h"

int main(int argc, char* argv[]) {

  Node node;

  // variable for handling multiple filenames
  string filename;

  // sort command line arguments
  // get keyboard input or pipe and write to file
  if (argc == 1) {

    string input;

    //output stream and .dat filename
    ofstream datFile;
    filename = "tokens.dat";

    //open file for read
    // .c_str() converts to formal c string
    datFile.open(filename.c_str());

    while (cin >> input) {
      datFile << input << " ";
    }

    //close file
    datFile.close();

  }
  else if (argc == 2) {

    // argv[1] is filename (second param)
    filename = argv[1];
    // makes filename a valid file in directory
    //	see README
  }
  else if (argc > 2) {
    cerr << "Too many command line arguments." << endl;
    exit(EXIT_FAILURE);
  };

  //for parsing words and building tree
  string word;
  char letter;

  ifstream outFile(filename.c_str());
  if (outFile.is_open()) {
    while (outFile >> word) {

      boolean isValid = validateInputString(word); // TODO
      if(isValue == false) {
	cerr << "Input string of " << word << " has invalid characters, aborting." << endl;
	exit(1);
      }
      
      letter = word.at(0);
      node.buildTree(letter);
    }
    outFile.close();
  }
  else cout << "Unable to open file";

  //determine which output files to make

  cout << endl << endl;
  node.print_inorder();
  cout << endl;
  node.print_preorder();
  cout << endl;
	

  return 0;
}
