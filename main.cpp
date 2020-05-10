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
	/*M円を超える確率を求める*/
	int prize[3] = {10000, 3000, 300};
	double possibility[3] = {0.001, 0.01, 0.1};
	double all_possibility = 0.0;

	int n = 50;
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
	printf("all possibility:%.15lf\n", all_possibility);

	return 0;
}
