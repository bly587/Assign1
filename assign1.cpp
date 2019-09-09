/*
Titan Mitchell
2327159
tmitchell@chapman.edu
CPSC 350 - 02
Assignment 1

Executes a program that prints out "Hello World" to the user
*/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argr)
{
  string fileName = "";
  if(argr[1] != NULL)
  {
    fileName = argr[1];
  }
  else
  {
    cout << "Please enter a file!" << endl;
    return 1;
  }

  cout << fileName << endl;

  string line = "";
  ifstream file (fileName);
  while(getline(file, line))
  {
    cout << line << endl;
  }
}
