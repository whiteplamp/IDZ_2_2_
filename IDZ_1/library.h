//
// Created by yan on 01.06.2021.
//

#ifndef IDZ_1_LIBRARY_H
#define IDZ_1_LIBRARY_H

#include <iostream>
#include <fstream>
using namespace std;

int MainFunc(ifstream &fin, double &res);
/*
Function calculates average length of sequence using inductive
method
Input:
      fin - input stream class. Passed by Link.
      res - result of working program

Output:
      ret - result of working function:
          -1 if stream isn`t opened
          -2 if all is ok
          -3 if stream is opened, but file is empty


*/

void TestFunc(ofstream &fout);
/*Генератор последовательнсоти*/

#endif //IDZ_1_LIBRARY_H
