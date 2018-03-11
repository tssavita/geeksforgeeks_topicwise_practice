# Egg Dropping Problem

## Problem Statement: Given _n_ eggs, find out from which floors of a building with _k_ floors it is okay to drop and egg and for it to still not break. 

## Check for optimal substructure

When an egg is dropped from a floor _x_, such that 1 <= x <= k, there can be two possibilities: 

1. The egg is broken, which means we have to consider only floors till x - 1 because if the egg breaks from a floor x, then it would definitely break from a floor above. We have n-1 eggs left. 
2. The egg is not broken, which means we have to consider only floors from x + 1 floors to k floors, because if the egg does not break from a floor, it will not break if thrown from a floors below the current floor. The number of eggs remains intact. 
```
bool eggDrop(int n, int k) {
    return 1 + min(eggDrop(n-1, x-1), eggDrop(n, k-x));
}
```

The non-recursive solution to this problem is to balance out the interval for the number of floors that an egg needs to be dropped from and the incremental number of trials that eggs need to be dropped from, between these intervals. There needs to be a load balancing done, between the loads to be carried by eggs in terms of the number of floors from which egg needs to be dropped. This concept is commonly also known as "worst case balancing". This can be solved using the following formula: 
```
n(n+1)/2 = number of floors 
```
The above equation is quadratic and can be solved to obtain the number of intervals and number of trials between these intervals. 

This is pseudocode:
```
breakpoint = {...};

bool drop(int egg) {
    countdropping++;
    if (egg >= breakingpoint)
        return true;
    return false;
}

int findingBreakingPoint() {
    int interval = // find this out by using the formula n(n+1) = 2 * number of floors
    while ( !drop(egg1) && egg1 <= floors) {
        interval -= 1;
        previousFloor = egg1;
        egg1 -= interval;
    }

    egg2 = previousFloor + 1;
    while ( egg2 <= floors && egg2 < egg1 && !drop(egg2) ) {
        egg2++;
    }

    return (egg2 > floors)? -1; egg2;
}
```
