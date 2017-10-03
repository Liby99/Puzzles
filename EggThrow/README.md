# How high can the egg fall without smash?

## Problem Description

Now you have two eggs, and you are on a very high building with given height (in
floor). And you want to determine what is the minimum floor that the egg will
get smashed when fall. How do you find out this floor? What is the worst amount
of steps to take to find this floor?

Assumptions:
1. If the egg is not smashed into pieces, it will not be weakened by the crash.
2. The two eggs are completely identical.

Consider the condition that you only have one egg. And if the building
is 100-floor high, you might need 100 steps to determine the height for the egg
to crash if the actual height for crash is 100 floor. Since you are going to try
to throw the egg from floor 1, and then floor 2, and then ..., and finally floor
100.

Now you have two eggs, meaning that you don't have to do it linearly. You can
now try the 50th floor with the first egg, and if it is smashed into pieces, you
can infer that the floor is going to be in range 1 to 49. So overall you will
need to throw 50 times, which is much smaller than 100. But there is definitely
better solutions. Use your smart brain to find out!

## Solution

> Ignore this part if you want to do your own solution!

### Intuitive Explanation

We want to minimize the steps. As one can see 

### Mathematical Explanation

Suppose the building is $n$-floor-high, and you have two eggs.

Now define function $p(k) = 1 + 2 + 3 + ... + k$.

There must exists $m$ such that $p(m - 1) < n <= p(m)$

And the minimum step to find out the floor is simply $m$.

### Programming Approach
