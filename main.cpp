/*
 * main.cpp
 *
 *  Created on: 2020/05/09
 *      Author: seal0
 */
#include <stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<iomanip>

#include "CalcPossibility.h"

using namespace std;

int main(){

	CalcPossibility(2, true);
	string filename = "possibility.txt";
	ofstream writing_file;
	writing_file.open(filename, ios::out);

	for(int i=1; i<333; i++){
		printf("%3d:", i);
		double all_possibility = CalcPossibility(i, false);
		writing_file << i << "\t" <<fixed<<setprecision(15)<< all_possibility << endl;
	}
	return 0;
}
