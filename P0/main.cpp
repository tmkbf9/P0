#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "validation.h"
#include "node.h"
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]) {

  Node node;

  // variable for handling multiple filenames
  string filename;
  string outputFileName("out");

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
    filename = argv[1];
    outputFileName = filename;
  }
  else if (argc > 2) {
    cerr << "Too many command line arguments." << endl;
    exit(EXIT_FAILURE);
  };

  //for parsing words and building tree
  string word;
  char letter;

  ifstream tokenFile(filename.c_str());
  if (tokenFile.is_open()) {
    while (tokenFile >> word) {

      bool validWord = isValid(word); // TODO
      if(validWord == false) {
	cerr << "Input string of " << word << " has invalid characters, aborting." << endl;
	exit(EXIT_FAILURE);
      }
      
      node.buildTree(word);
    }
    tokenFile.close();
  }
  else cout << "Unable to open file";

  //determine which output files to make

  ofstream inOrderOutputFile((outputFileName + ".inorder").c_str());
  ofstream preOrderOutputFile((outputFileName + ".preorder").c_str());
  ofstream levelOrderOutputFile((outputFileName + ".levelorder").c_str());

  node.traverseInOrder(inOrderOutputFile);
  node.traversePreOrder(preOrderOutputFile);
  node.traverseLevelOrder(levelOrderOutputFile);

  inOrderOutputFile.close();
  preOrderOutputFile.close();
  levelOrderOutputFile.close();

  exit(EXIT_SUCCESS);
}
