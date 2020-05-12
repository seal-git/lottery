/*
 * CalcPossibility.cpp
 *
 *  Created on: 2020/05/10
 *      Author: seal0
 */

/*
 * main.cpp
 *
 *  Created on: 2020/05/09
 *      Author: seal0
 */
#include <stdio.h>
#include<iostream>
#include<cmath>

#include "CalcPossibility_3.h"
#include "CalcPossibility_2.h"
#include "CalcPossibility_1.h"

using namespace std;

double CalcPossibility(int n, bool is_printed_all ="true"){
	/*calculate the possibility to get more than n*300 yen when buying n tickets*/
	/*n=[1, 10] -> call CalcPossibility_1
	 *n=[11, 33] -> call CalcPossibility_2
	 *n=[34, 333] -> call CalcPossibility_3
	 *else -> exit(0)
	 *
	 * */

	double all_possibility;
	if(n<=333 && n>33){
		all_possibility = CalcPossibility_3(n, is_printed_all);
	}
	else if(n<=33 && n>10){
		all_possibility = CalcPossibility_2(n, is_printed_all);
	}else if(n<=10 && n>0){
		all_possibility = CalcPossibility_1(n, is_printed_all);
	}
	else{
		printf("n must be [1, 333]");
		exit(0);
	}
	return all_possibility;
}



