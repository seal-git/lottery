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

#include "Myutil.h"

using namespace std;


double CalcPossibility_1(int n, bool is_printed_all ="true"){
	/*calculate the possibility to get more than n*300 yen when buying n tickets*/
	/*n must be [1, 10]*/
	/*First		200mil, 42/420mil
	 * sub 1		50mil, 84/420mil
	 * sub2		0.1mil, 4158/420mil
	 * Second	100mil, 126/420mil
	 * Third		10mil, 420/420mil
	 * Fourth	0.1mil, 4200/420mil
	 * Fifth		3000, 4.2mil/420mil
	 * Sixth		300, 42mil/420mil
	 * Happy	10000, 0.42mil, 420mil
	 */
	int prize = 300;
	double possibility = 0.1;
	double all_possibility = 0.0;

	/*calulate the possibility of winning \10000+ to all_possibility*/
	double all_tickets = 420.0 * pow(10, 6);
	double other_possibility = (double)(42+84+4158+126+420+4200+420000+4200000) / all_tickets;

	/*set cost to buy n tickets*/
	int M = 300*n;

	/*express the combination of X1, X2as range to minimize complexity*/
	int X1_begin;
	int X1_end;
	int X1_flag = 0;/*flag becomes 1 when result is printed*/
	for(int i = n; i>=0; i--){
		int X1 = prize*i;
		if(X1>=M){
			X1_begin = n;
			X1_end = i;
		}else{
			if(X1_flag == 0){
				/*result is printed only once in one loop*/
				if(is_printed_all)printf("%d:%d-%d\n", prize, X1_begin, X1_end);
				X1_flag = 1;
				/*calculate total possibility in the range*/
				double total_possibility = get_sum_of_GP(possibility, X1_begin, X1_end);
				all_possibility += total_possibility;
				if(is_printed_all)printf("%.15lf\n", total_possibility);
			}
		}
	}
	all_possibility+=other_possibility;
	printf("all possibility:%.15lf ", all_possibility);
	printf("(other possibility:%.15lf)\n", other_possibility);

	return all_possibility;
}



