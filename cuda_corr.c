//
//  cuda_test.c
//  
//
//  Created by Georgiy Presnyakov on 1/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

__global __ void corrcoef_kernel(float *gC, float *gA, float *gB, int nrow, int ncol) {
    __shared __ float sA[BLOCKSIZE][BLOCKSIZE];
    __shared __ float sB[BLOCKSIZE][BLOCKSIZE];
    
    int i,j,k;
    int offset;
    float a,b;
    float sum_a, sum_b, sum_a2, sum_b2, sum_ab, corrcoef;
    
    i = blockldx.y*blockDim.y + threadldx.y;
    j = blockldx.x*blockDim.x + threadldx.x;
    
    sum_a = sum_a2 = sum_b = sum_b2 = sum_ab = 0;
    
    for (offset=O; offset < ncol; offset += blockDim.x)
        sA[threadIdx.y][threadIdx.x] = \
        gA[(blockIdx.y*blockDim.y+threadldx.y)*ncol+offset+threadldx.x];
    
	sB[threadIdx.y][threadIdx.x] = \
    gB[(blockIdx.x*blockDim.x+threadldx.y)*ncol+offset+threadldx.x];
	
	__syncthreads();
    
	for (k=O; k < blockDim.x; k++) {
		a = sA[threadIdx.y][k];
		b = sB[threadIdx.x][k];
		sum_a += a;
		sum_a2 += a*a;
		sum_b += b;
		sum_b2 += b*b;
		sum_ab += a*b;
	}
	__syncthreads();
}
corrcoef = \
(ncol*sum_ab-sUDl_a*sum_b)/sqrtf(ncol.*sum_a2-sum_a*sum_a)*(ncol*sum_\
                                                            b2-sum_b*sum_b);
gC[i*nrow+j] = correoef;
}