//
//  main.c
//  PoppinBottles
//
//  Created by JIAN WANG on 5/5/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>

void bottlesAfterRecyling(int totalRecycledPopsByBottles, int totalRecycledPopsByCaps, int bottlesSum, int capsSum);
int const costOfOneBottleCop = 2;

int main(int argc, const char * argv[]) {
    int moneyPaid;
    do {
        printf("How much are you going to spend?\n");
        scanf("%d", &moneyPaid);
        int boughtPops = moneyPaid / costOfOneBottleCop;
        printf("You purchased %d bottles of Pops.\n", boughtPops);
        
        int totalRecycledPopsByBottles = 0;
        int totalRecycledPopsByCaps = 0;
        
        int bottlesSum = boughtPops;
        int capsSum = boughtPops;
        
        bottlesAfterRecyling(totalRecycledPopsByBottles, totalRecycledPopsByCaps, bottlesSum, capsSum);
        
        printf("---Next Customer---\n");
    } while (moneyPaid);
    
    return 0;
}

void bottlesAfterRecyling(int totalRecycledPopsByBottles, int totalRecycledPopsByCaps, int bottlesSum, int capsSum) {
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
        printf("Total recycled bottles: %d\n", totalRecycledPopsByBottles + totalRecycledPopsByCaps);
        printf("Bottles left - %d\n", numberOfBottlesLeft + 1);
        printf("Caps left - %d\n", numberOfCapsLeft + 1);
        printf("Buy more, get more!\n");
    } else {
        bottlesAfterRecyling(totalRecycledPopsByBottles, totalRecycledPopsByCaps, bottlesSum, capsSum);
    }
}
