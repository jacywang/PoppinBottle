//
//  main.c
//  PoppinBottles
//
//  Created by JIAN WANG on 5/5/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>

int bottlesAfterRecyling(int totalRecycledPops, int bottlesSum, int capsSum);
int const costOfOneBottleCop = 2;

int main(int argc, const char * argv[]) {
    int moneyPaid = 10;
    int boughtPops = moneyPaid / costOfOneBottleCop;
    int totalRecycledPops = 0;
    int bottlesSum = boughtPops;
    int capsSum = boughtPops;
    totalRecycledPops = bottlesAfterRecyling(totalRecycledPops, bottlesSum, capsSum);
    printf("Total recycled bottles: %d\n", totalRecycledPops);
    return 0;
}

int bottlesAfterRecyling(int totalRecycledPops, int bottlesSum, int capsSum) {
    int numberRecyledByBottles = bottlesSum / 2;
    int numberRecyledByCaps = capsSum / 4;
    
    int numberOfBottlesLeft = bottlesSum % 2;
    int numberOfCapsLeft = capsSum % 4;
    
    int bottlesRecyled = numberRecyledByBottles + numberRecyledByCaps;
    
    bottlesSum = numberOfBottlesLeft + bottlesRecyled;
    capsSum = numberOfCapsLeft + bottlesRecyled;
    totalRecycledPops += bottlesRecyled;
    printf("totalRecycles - %d\n", totalRecycledPops);
    printf("bottlesSum - %d\n", bottlesSum);
    printf("capsSum - %d\n", capsSum);
    printf("------\n");
    if (bottlesSum < 2 && capsSum < 4) {
        return totalRecycledPops;
    } else {
        return bottlesAfterRecyling(totalRecycledPops, bottlesSum, capsSum);
    }
}
