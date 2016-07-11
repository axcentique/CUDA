//
//  cuda_test.c
//  
//
//  Created by Georgiy Presnyakov on 1/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

__global __ void lincomb_kernel (mint* arrU, mint* arrV, mint* conA, mint* conB, mint len) 
{
  	int index = threadIdx.x + blockIdx.x * blockDim.x;
  	if (index >= len) return;
    
  	printf ("U,V,A,B = %d, %d, %d, %d \n", arrU[index], arrV[index], 
            conA, conB);
    
    arrU[index] = conA * arrU[index] + conB * arrV[index];
}