/*
Titan Mitchell
2327159
tmitchell@chapman.edu
CPSC 350 - 02
Assignment 1
assign1.cpp includes all functions to read in a list and calculate the mean, sum,
variance, and standard deviation of the lengths of strings. Then it prints out
1000 strings following the same statistics.
*/
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//function to solve for gaussian distribution
/*
a. Name of the function
b. A description of the value returned and its type, if applicable
c. A description of each parameter and its type, if applicable
d. A description of any exceptions thrown, if applicable
*/
/*
gDistribution()
returns a float which contains the gaussian distribution
parameters: variance, mean, and 2 random numbers between 0 and 1
*/
float gDistribution(float varianceNum, float mean, double randA, double randB)
{
  float sDev = sqrt(varianceNum);
  float c = sqrt((-2) * log(randA))*cos(2* M_PI *(randB));
  //need to generate a and b
  //d = (standard deviation) * c + mean;
  float d = sDev * c + mean;
  //d = the average length of string
  return d;
}
//function for variance
/*
varianceOfStrings()
returns the variance from the file just read in
paramters: filneame, mean, number of lines in the file
*/
float varianceOfStrings(string filename, float mean, int numOfLines)
{
  //reads in from variance file where the numbers are stored
  ifstream myfile (filename);
  float varianceNum = 0;
  string line = "";
  float calc = 0;
  while(getline(myfile, line))
  {
    //Subtract the mean from each value in the data. This gives you a measure of the distance of each value from the mean.
    //Square each of these distances (so that they are all positive values), and add all of the squares together.
    int x = stoi(line);
    if(mean > x)
    {
      //should be negative but if being squared it doesn't mattter
      calc = (mean - x);
    }
    else
    {
      calc = x - mean;
    }
    calc = pow(calc, 2);
    varianceNum += calc;
  }
  //Divide the sum of the squares by the number of values in the data set.
  varianceNum = varianceNum / numOfLines;
  return varianceNum;
}
//sum of lengths
//function for mean
/*
meanOfStrings()
returns the mean of all the strings
paramters: filneame and numOfLines
*/
float meanOfStrings(string filename, int numOfLines)
{
  //takes in variance file to read in the numbers
  ifstream myfile (filename);
  float mean = 0;
  string line = "";
  while(getline(myfile, line))
  {
    int x = stoi(line);
    mean += x;
  }
  mean /= numOfLines;
  return mean;
}
//
//funciton for converting line to lowercase
/*
converter()
returns a string that is all the letters in the string entered just lowercase
paramters: Enter a string that you would like to make lowercase
*/
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
//solve for probability of each nucleotide
/*
probability
returns a float that contains the number of times a nucleotide was counted divided by the total # of nucleotides
parameter: The nucleotide you want the probability for and the total number of nucleotides
*/
float probability(int nucleotide, int sumOfLengths)
{
  //must type cast at least one variable to get a float value
  float probability = (float)nucleotide / sumOfLengths;
  return probability;
}

int main(int argc, char** argr)
{
  //variables to help with probability
  int a = 0;
  int g = 0;
  int c = 0;
  int t = 0;
  //find the doubles
  //all a's
  int aa = 0;
  int ac = 0;
  int ag = 0;
  int at = 0;
  //all c's
  int ca = 0;
  int cc = 0;
  int cg = 0;
  int ct = 0;
  //all g's
  int ga = 0;
  int gc = 0;
  int gg = 0;
  int gt = 0;
  //all t's
  int ta = 0;
  int tc = 0;
  int tg = 0;
  int tt = 0;


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
      //make line lowercase
      updated = converter(line);
      //write out updated line to file
      myfile << updated << endl;
      //solve for probability
      for(int i = 0; i < lengthOfLine; ++i)
      {
        if(updated[i] == 'a')
        {
          //if i is an even number then check the next value to see if it makes a pattern
          if(i % 2 == 0)
          {
            if(updated[i + 1] == 'a')
            {
              aa += 1;
            }
            else if(updated[i + 1] == 'c')
            {
              ac += 1;
            }
            else if(updated[i + 1] == 'g')
            {
              ag += 1;
            }
            else if(updated[i + 1] == 't')
            {
              at += 1;
            }
          }
          //add to a variable
          a += 1;
        }
        else if(line[i] == 'c')
        {
          //if i is an even number then check the next value to see if it makes a pattern
          if(i % 2 == 0)
          {
            if(updated[i + 1] == 'c')
            {
              cc += 1;
            }
            else if(updated[i + 1] == 'g')
            {
              cg += 1;
            }
            else if(updated[i + 1] == 't')
            {
              ct += 1;
            }
            else if(updated[i + 1] == 'a')
            {
              ca += 1;
            }
          }
          //add to c variable
          c += 1;
        }
        else if(line[i] == 'g')
        {
          if(i % 2 == 0)
          {
            if(updated[i + 1] == 'g')
            {
              gg += 1;
            }
            else if(updated[i + 1] == 't')
            {
              gt += 1;
            }
            else if(updated[i + 1] == 'a')
            {
              ga += 1;
            }
            else if(updated[i + 1] == 'c')
            {
              gc += 1;
            }
          }
          //add to g variable
          g += 1;
        }
        else
        {
          if(i % 2 == 0)
          {
            if(updated[i + 1] == 't')
            {
              tt += 1;
            }
            else if(updated[i + 1] == 'a')
            {
              ta += 1;
            }
            else if(updated[i + 1] == 'c')
            {
              tc += 1;
            }
            else if(updated[i + 1] == 'g')
            {
              tg += 1;
            }
          }
          //if not the other 3 then t is the only other option for a nucleotide
          t += 1;
        }
      }
      //write out size to a file to solve for variance
      variance << lengthOfLine << endl;
      //add length to the total length of lines
      sumOfLengths += lengthOfLine;
      //update number of lines
      numOfLines++;
    }
    cout << "a variable holds " << a << endl;
    float mean = meanOfStrings(varianceFile, numOfLines);
    float varianceNum = varianceOfStrings(varianceFile, mean, numOfLines);
    float pOfA = probability(a, sumOfLengths);
    float pOfG = probability(g, sumOfLengths);
    float pOfC = probability(c, sumOfLengths);
    float pOfT = probability(t, sumOfLengths);
    //float of doubles and float of chances of certain letters that follow
    //A's
    float pOfAA = probability(aa, sumOfLengths / 2);
    float pOfAC = probability(ac, sumOfLengths / 2);
    float pOfAG = probability(ag, sumOfLengths / 2);
    float pOfAT = probability(at, sumOfLengths / 2);
    //C's
    float pOfCA = probability(ca, sumOfLengths / 2);
    float pOfCC = probability(cc, sumOfLengths / 2);
    float pOfCG = probability(cg, sumOfLengths / 2);
    float pOfCT = probability(ct, sumOfLengths / 2);
    //G's
    float pOfGA = probability(ga, sumOfLengths / 2);
    float pOfGC = probability(gc, sumOfLengths / 2);
    float pOfGG = probability(gg, sumOfLengths / 2);
    float pOfGT = probability(gt, sumOfLengths / 2);
    //T's
    float pOfTA = probability(ta, sumOfLengths / 2);
    float pOfTC = probability(tc, sumOfLengths / 2);
    float pOfTG = probability(tg, sumOfLengths / 2);
    float pOfTT = probability(tt, sumOfLengths / 2);
    //get the proper percentage ranges for certain bigrams
    //a's
    pOfAC += pOfAA;
    pOfAG += pOfAC;
    pOfAT += pOfAG;
    //c's
    pOfCC += pOfCA;
    pOfCG += pOfCC;
    pOfCT += pOfCG;
    //g's
    pOfGC += pOfGA;
    pOfGG += pOfGC;
    pOfGT += pOfGG;
    //t's
    pOfTC += pOfTA;
    pOfTG += pOfTC;
    pOfTT += pOfTG;
    //cout<<"The probability of aa is: " << pOfAA << endl;

    //give percentages for nucleotides to use for printing to document
    //pOfA is stand alone because it's prob will be from [0-a)
    //pOfG will then be from [a - g)
    //etc
    //this will create the last value in the probability of G
    pOfG += pOfA;
    pOfC += pOfG;
    pOfT += pOfC;
    //find out what amount of nucleotides should be printed out to obtain same average
    //print out what we found using funcitons
    cout << "The number of lines read in " << numOfLines << endl;
    cout << "The sum of line lengths read in " << sumOfLengths << endl;
    cout << "The mean of lengths read in " << mean << endl;
    cout << "The variance is " << varianceNum << endl;
    cout << "The probability of a is " << pOfA << endl;
    cout << "The probability of G is " << pOfG << endl;
    cout << "The probability of C is " << pOfC << endl;
    cout << "The probability of T is " << pOfT << endl;
    //open ouput file
    ofstream output;
    output.open("titanMitchell.out");
    //write out to this file
    output << "Titan Mitchell" << endl;
    output << "2327159" << endl;
    output << "tmitchell@chapman.edu" << endl;
    output << "CPSC 350 - 02" << endl;
    output << "Assignment 1 \n" << endl;
    //output<< "check that line went down" << endl;
    //write out stats
    output << "The number of lines read in is " << numOfLines << endl;
    output << "The sum of line lengths read in is " << sumOfLengths << endl;
    output << "The mean of lengths read in is " << mean << endl;
    output << "The variance is " << varianceNum << endl;
    output << "The probability of a is " << pOfA << endl;
    output << "The probability of G is " << pOfG << endl;
    output << "The probability of C is " << pOfC << endl;
    output << "The probability of T is " << pOfT << endl;
    srand (time(NULL));
    for(int i = 0; i < 1000; i++)
    {
      //create new random numbers
      double randA = ((double) rand() / (RAND_MAX));
      double randB = ((double) rand() / (RAND_MAX));
      //solve for d everyline and then round
      float d = gDistribution(varianceNum, mean, randA, randB);
      d = round(d);
      for(int j = 0; j < d; ++j)
      {
        cout << "The d is : " << d << endl;
        cout << "J is : " << j << endl;
        //new random number every iteration to ensure the probabilty of different letters
        double randNuc = ((double) rand() / (RAND_MAX));
        //checks to see if that letter should be printed and if that letter still has an amount that can be printed
        //in order to ensure the proper mean
        if(j % 2 == 1)
        {
          //on the odd number use the percentages for the bigrams
          //a Bigrams
          if(randNuc < pOfAA)
          {
            output << "a";
          }
          else if(randNuc >= pOfAA && randNuc < pOfAC)
          {
            output<< "c";
          }
          else if(randNuc >= pOfAC && randNuc < pOfAG)
          {
            output << "g";
          }
          else if(randNuc >= pOfAG && randNuc < pOfAT)
          {
            output << "t";
          }
          //c bigrams
          else if(randNuc >= pOfAT && randNuc < pOfCA)
          {
            output << "a";
          }
          else if(randNuc >= pOfCA && randNuc < pOfCC)
          {
            output<< "c";
          }
          else if(randNuc >= pOfCC && randNuc < pOfCG)
          {
            output << "g";
          }
          else if(randNuc >= pOfCG && randNuc < pOfCT)
          {
            output << "t";
          }
          //g bigrams
          else if(randNuc >= pOfCT && randNuc < pOfGA)
          {
            output << "a";
          }
          else if(randNuc >= pOfGA && randNuc < pOfGC)
          {
            output<< "c";
          }
          else if(randNuc >= pOfGC && randNuc < pOfGG)
          {
            output << "g";
          }
          else if(randNuc >= pOfGG && randNuc < pOfGT)
          {
            output << "t";
          }
          //t bigrams
          else if(randNuc >= pOfGT && randNuc < pOfTA)
          {
            output << "a";
          }
          else if(randNuc >= pOfTA && randNuc < pOfTC)
          {
            output<< "c";
          }
          else if(randNuc >= pOfTC && randNuc < pOfTG)
          {
            output << "g";
          }
          else if(randNuc >= pOfTG && randNuc < pOfTT)
          {
            output << "t";
          }
        }
        else
        {
          if(randNuc < pOfA)
          {
            output << "a";
          }
          else if(randNuc >= pOfA && randNuc < pOfG)
          {
            output << "g";
          }
          else if(randNuc >= pOfG && randNuc < pOfC)
          {
            output << "c";
          }
          else if(randNuc >= pOfC && randNuc < pOfT)
          {
            output << "t";
          }
          //has to be else if to check for t's condition
        }
      }
      cout<<"new line"<<endl;
      output << "\n";
    }
    //gaussian distribution
    //if user would like to add another file to be decifered
    user = "";
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
      output.close();
      myfile.close();
      variance.close();
      return 0;
    }
  }
}
