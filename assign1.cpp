/*
Titan Mitchell
2327159
tmitchell@chapman.edu
CPSC 350 - 02
Assignment 1


*/
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

//function for variance
float varianceOfStrings(string filename, float mean, int numOfLines)
{
  ifstream myfile (filename);
  float varianceNum = 0;
  string line = "";
  float calc = 0;
  while(getline(myfile, line))
  {
    //Subtract the mean from each value in the data. This gives you a measure of the distance of each value from the mean.
    //Square each of these distances (so that they are all positive values), and add all of the squares together.
    int x = stoi(line);
    //cout << mean << endl;
    cout << x << endl;
    if(mean > x)
    {
      //should be negative but if being squared it doesn't mattter
      calc = (mean - x);
      cout << calc << endl;
    }
    else
    {
      calc = x - mean;
    }
    calc = pow(calc, 2);
    cout << calc << endl;
    varianceNum += calc;
    cout << "Variance number so far " << varianceNum << endl;
  }
  //Divide the sum of the squares by the number of values in the data set.
  varianceNum = varianceNum / numOfLines;
  return varianceNum;
}
//sum of lengths
//function for mean
float meanOfStrings(string filename, int numOfLines)
{
  ifstream myfile (filename);
  float mean = 0;
  string line = "";
  while(getline(myfile, line))
  {
    int x = stoi(line);
    mean += x;
  }
  mean /= numOfLines;
  cout << mean << endl;
  return mean;
}
//
//funciton for converting line to lowercase
string converter(string s)
{
  char c;
  string updated = "";
  int len = s.size();
  for(int i = 0; i < len; ++i)
  {
    c = s[i];
    char letter = tolower(c);
    string s1 (1, letter);
    updated.append(s1);
  }
  return updated;
}


int main(int argc, char** argr)
{
  string user;
  cout << "Hi would you like to process a list?(yes/no)" << endl;
  cin >> user;
  //check for file
  string fileName = "";
  string varianceFile = "variance.txt";
  if(argr[1] != NULL)
  {
    fileName = argr[1];
  }
  else
  {
    cout << "Please enter a file on the command line!" << endl;
    return 1;
  }
  //variance per length
  float variance = 0;
  //Total of lines
  int numOfLines = 0;
  //Sum of lengths
  int sumOfLengths = 0;
  //file writing to
  string file = "output.txt";
  //allows for multiple submissions
  while(user == "yes")
  {
    cout << fileName << endl;
    //open file
    ofstream myfile;
    ofstream variance;
    myfile.open(file);
    variance.open(varianceFile);

    string line = "";
    ifstream file (fileName);
    string updated = "";
    while(getline(file, line))
    {
      //find size of line
      int lengthOfLine = line.size();
      //write out size to a file to solve for variance
      variance << lengthOfLine << endl;
      //add length to the total length of lines
      sumOfLengths += lengthOfLine;
      //make line lowercase
      updated = converter(line);
      myfile << updated << endl;
      //cout << updated << endl;
      //cout << "wrote to file" << endl;
      //update number of lines
      numOfLines++;
    }
    float mean = meanOfStrings(varianceFile, numOfLines);
    float varianceNum = varianceOfStrings(varianceFile, mean, numOfLines);
    //print out what we found using funcitons
    cout << "The number of lines read in " << numOfLines << endl;
    cout << "The sum of line lengths read in " << sumOfLengths << endl;
    cout << "The mean of lengths read in " << mean << endl;
    cout << "The variance is " << varianceNum << endl;
    //if user would like to add another file to be decifered
    cout << "Would you like to process another list?(yes/no)" << endl;
    cin >> user;
    if(user == "yes")
    {
      fileName = "";
      cout << "Enter file name" << endl;
      cin >> fileName;
    }
    else
    {
      myfile.close();
      variance.close();
      return 0;
    }
  }
}
