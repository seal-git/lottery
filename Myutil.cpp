/*
 * Myutil.cpp
 *
 *  Created on: 2020/05/12
 *      Author: seal0
 */
#include <stdio.h>
#include<iostream>
#include<cmath>

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


