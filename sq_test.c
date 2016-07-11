//
//  sq_test.c
//  
//
//  Created by Georgiy Presnyakov on 1/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

# include <stdio.h>
# define arraySize 10
int square(int);
int squareAndAssign(int*, int, int); // new prototype
int main()
{
	int arry[arraySize];
//    arry[0]=1;
//    arry[1]=2;
//    arry[2]=3;
//    arry[3]=4;
//    arry[4]=5;
	for(int i=0 ; i < arraySize ; i++) {
		squareAndAssign(arry, i, arraySize);
	}
	for(int i=0 ; i < arraySize ; i++) {
		printf("arry[%d] = %d \n", i, arry[i]);
	}
    return 0;
}

int square(int i){
	return i*i; }

int squareAndAssign(int* a, int i, int b) {
    a[i] = i*i;
	// a[i] = square(a[i])*b;
	return 0; }

//int squareAndAssign(int* a, int i) {
//	a[i] = square(i);
//	return 0; }

// compile with:
// gcc sq_test.c -std=c99 -o sq_test.out