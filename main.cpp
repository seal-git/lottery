/*
 * main.cpp
 *
 *  Created on: 2020/05/09
 *      Author: seal0
 */
#include <stdio.h>

int main(){
	/*M円を超える確率を求める*/
	int A[3] = {300, 3000, 10000};
	double P[3] = {0.1, 0.01, 0.001};

	int n = 80;
	int M = 300*n;

	/*get the range of combination of X1, X2, X3* to minimize complexity*/
	int X1_begin;
	int X1_end;
	int flag = 1;/*flag becomes 1 when X1_begin & X1_end are printed*/
	for(int i = n; i>=0; i--){
		int X1 = 10000*i;
		if(X1>=M){
			X1_begin = n;
			X1_end = i;
			//			printf("10000:%d\n", i);
		}else if(flag == 1){
			/*this scope is executed only once in one loop*/
			printf("10000:%d-%d\n", X1_begin, X1_end);
			flag = 0;
		}else{
			int X2_begin;
			int X2_end;
			int flag = 1;/*flag becomes 1 when X2_begin & X2_end are printed*/
			for(int j=n-i; j>=0; j--){
				int X2 = X1 + 3000*j;
				if(X2>=M){
					X2_begin = n-i;
					X2_end = j;
					//	printf("10000:%d, 3000:%d\n", i, j);
				}else if(flag == 1){
					/*this scope is executed only once in one loop*/
					printf("10000:%d, 3000:%d-%d\n", i,  X2_begin, X2_end);
					flag = 0;
				}else{
					int X3_begin;
					int X3_end;
					int flag = 1; /*flag becomes 1 when X3_begin & X3_end are printed*/
					for(int k=n-i-j; k>=0; k--){
						int X3 = X2 + 300*k;
						if(X3>=M){
							X3_begin = n-i-j;
							X3_end = k;
							//	printf("10000:%d, 3000:%d, 300:%d\n", i, j, k);
						}else if(flag == 1){
							/*this scope is executed only once in one loop*/
							printf("10000:%d, 3000:%d, 300:%d-%d\n", i, j, X3_begin, X3_end);
							flag = 0;
						}
					}
				}
			}
		}
	}
	return 0;
}
