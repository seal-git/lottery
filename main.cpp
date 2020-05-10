/*
 * main.cpp
 *
 *  Created on: 2020/05/09
 *      Author: seal0
 */
#include <stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

double get_sum_of_GP(double possibility, int begin, int end){
	/*get sum of geometric progression(等比数列) from begin to end*/
	/*double type can treat 15digit decimal, so 16+digit should be cut*/

	/*sum_of_GP = (p^{end}-p^{begin}/(1-p)*/
	if(begin == end){
		return pow(possibility, (double)begin);
	}else{
		return (pow(possibility, (double)end) - pow(possibility, (double)begin)) / (1.0 - possibility);
	}
}

int main(){
	/*calculate the possibility to get more than n*300 yen when buying n tickets*/
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
	int prize[3] = {10000, 3000, 300};
	double possibility[3] = {0.001, 0.01, 0.1};
	double all_possibility = 0.0;

	/*calulate the possibility of winning \100000+ to all_possibility*/
	double all_tickets = 420.0 * pow(10, 6);
	double other_possibility = (double)(42+84+4158+126+420+4200) / all_tickets;


	int n = 37;
	int M = 300*n;

	/*express the combination of X1, X2, X3 as range to minimize complexity*/
	int X1_begin;
	int X1_end;
	int X1_flag = 0;/*flag becomes 1 when result is printed*/
	for(int i = n; i>=0; i--){
		int X1 = prize[0]*i;
		if(X1>=M){
			X1_begin = n;
			X1_end = i;
			//			printf("10000:%d\n", i);
		}else{
			if(X1_flag == 0){
				/*result is printed only once in one loop*/
				printf("%d:%d-%d\n", prize[0], X1_begin, X1_end);
				X1_flag = 1;

				/*calculate total possibility in the range*/
				double total_possibility = get_sum_of_GP(possibility[0], X1_begin, X1_end);
				all_possibility += total_possibility;
				printf("%.15lf\n", total_possibility);
			}
			/*calculate X2*/
			int X2_begin;
			int X2_end;
			int X2_flag = 0;
			for(int j=n-i; j>=0; j--){
				int X2 = X1 + prize[1]*j;
				if(X2>=M){
					X2_begin = n-i;
					X2_end = j;
					//	printf("10000:%d, 3000:%d\n", i, j);
				}else{
					if(X2_flag==0){
						/*this scope is executed only once in one loop*/
						printf("%d:%d, ", prize[0], i);
						printf("%d:%d-%d\n", prize[1], X2_begin, X2_end);
						X2_flag = 1;

						/*calculate total possibility in the range*/
						double total_possibility = get_sum_of_GP(possibility[1], X2_begin, X2_end);
						if(i>0){
							total_possibility *= pow(possibility[0], (double)i);
						}
						printf("%.15lf\n", total_possibility);
						all_possibility += total_possibility;
					}
					/*calculate X3*/
					int X3_begin;
					int X3_end;
					int X3_flag = 0; /*flag becomes 1 when X3_begin & X3_end are printed*/
					for(int k=n-i-j; k>=0; k--){
						int X3 = X2 + prize[2]*k;
						if(X3>=M){
							X3_begin = n-i-j;
							X3_end = k;
							//	printf("10000:%d, 3000:%d, 300:%d\n", i, j, k);
						}else if(X3_flag == 0){
							/*this scope is executed only once in one loop*/
							printf("%d:%d, ", prize[0], i);
							printf("%d:%d, ", prize[1], j);
							X3_flag = 1;
							printf("%d:%d-%d\n",prize[2], X3_begin, X3_end);
							/*calculate total possibility in the range*/
							double total_possibility = get_sum_of_GP(possibility[2], X3_begin, X3_end);
							if(i > 0){
								total_possibility *= pow(possibility[0], (double)i);
							}
							if(j > 0){
								total_possibility *= pow(possibility[1], (double)j);
							}
							printf("%.15lf\n", total_possibility);
							all_possibility += total_possibility;
						}
					}
				}
			}
		}
	}
	all_possibility+=other_possibility;
	printf("all possibility:%.15lf ", all_possibility);
	printf("(other possibility:%.15lf)\n", other_possibility);

	return 0;
}
