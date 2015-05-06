//
//  main.c
//  PoppinBottles
//
//  Created by JIAN WANG on 5/5/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>

int bottlesAfterRecyling(int totalRecycledPopsByBottles, int totalRecycledPopsByCaps, int bottlesSum, int capsSum);
int const costOfOneBottleCop = 2;

int main(int argc, const char * argv[]) {
    int moneyPaid;
    do {
        printf("How much are you going to spend?\n");
        scanf("%d", &moneyPaid);
        int boughtPops = moneyPaid / costOfOneBottleCop;
        printf("You purchased %d bottles of Pops.\n", boughtPops);
        
        int totalRecycledPops = 0;
        int totalRecycledPopsByBottles = 0;
        int totalRecycledPopsByCaps = 0;
        
        int bottlesSum = boughtPops;
        int capsSum = boughtPops;
        
        totalRecycledPops = bottlesAfterRecyling(totalRecycledPopsByBottles, totalRecycledPopsByCaps, bottlesSum, capsSum);
        
        printf("Total recycled bottles: %d\n", totalRecycledPops);
        printf("---Next Customer---\n");
    } while (moneyPaid);
    
    return 0;
}

int bottlesAfterRecyling(int totalRecycledPopsByBottles, int totalRecycledPopsByCaps, int bottlesSum, int capsSum) {
    int numberRecyledByBottles = bottlesSum / 2;
    int numberRecyledByCaps = capsSum / 4;
    
    int numberOfBottlesLeft = bottlesSum % 2;
    int numberOfCapsLeft = capsSum % 4;
    
    int bottlesRecyled = numberRecyledByBottles + numberRecyledByCaps;
    
    bottlesSum = numberOfBottlesLeft + bottlesRecyled;
    capsSum = numberOfCapsLeft + bottlesRecyled;
    
    totalRecycledPopsByBottles += numberRecyledByBottles;
    totalRecycledPopsByCaps += numberRecyledByCaps;
    
    if (bottlesSum < 2 && capsSum < 4) {
        printf("Pops obtained through bottles recycling - %d\n", totalRecycledPopsByBottles);
        printf("Pops obtained through caps recycling - %d\n", totalRecycledPopsByCaps);
        return totalRecycledPopsByBottles + totalRecycledPopsByCaps;
    } else {
        return bottlesAfterRecyling(totalRecycledPopsByBottles, totalRecycledPopsByCaps, bottlesSum, capsSum);
    }
}
