# How high can the egg fall without getting smashed?

## Problem Description

Now you have two eggs, and you are on a very high building with given height (in
floor). And you want to determine what is the minimum floor that the egg will
get smashed when fall. How do you find out this floor? What is the worst amount
of steps to take to find this floor?

Assumptions:
1. If the egg is not smashed into pieces, it will not be weakened by the crash.
2. The two eggs are completely identical.
3. The height will be within the range of the building height.

Consider the condition that you only have one egg. And if the building
is 100-floor high, you might need 100 steps to determine the height for the egg
to crash. Since you are going to try to throw the egg from floor 1. If it is not
smashed, you are going to try on the 2nd floor. Then 3rd floor, then 4th... and
finally 100th floor. There, the egg will definitely get smashed into pieces (by
assumption). So the total is 100 steps (in the worst case).

Now you have two eggs, meaning that you don't have to do it linearly. You can
now try the 50th floor with the first egg, and if it is smashed into pieces, you
can infer that the floor is going to be in range 1 to 49. If not, then you only
need to test it out for floor 51 to 100. So overall you will need to throw
roughly 50 times, which is much smaller than 100. But there is definitely
better solutions. Use your smart brain to find out!

## Compile and Run the Sample Code

First, use `Makefile` provided in the directory

```
$ make
```

If you want to find out the answer for 100-floor-building (which is the default)

```
$ ./a.out
```

If you want to specify a building height

```
$ ./a.out [HEIGHT]
```

Example:

```
$ ./a.out 30
```

## Solution

> Ignore this part if you want to do your own solution!

### Intuitive Example

Let's start with an example assuming the building is 15-floor-high. The optimal
solution is:

1. You throw the first egg on the 5th floor. If it is smashed, you try the 2nd
   egg from 1st floor to 4th floor (worst case **5**).
   If it is not, go to step 2:
2. Then you throw the first egg on the 9th floor. If it is smashed, you try the
   2nd egg from 6th floor to 8th floor (4 steps plus 1 step in 1., **5** steps).
   If it is not, go to step 3:
3. Then you throw the first egg on the 12th floor. If smashed, try 10th and then
   11th (3 + 2 = **5 steps**).
   If it is not, go to step 4:
4. Then you throw the first egg on the 14th floor. If smashed, try 13th (4 + 1 =
   **5 steps**).
   If it is not, try 15th floor (the final floor. **5 steps**)

The worst case amount of step is **5**.

As you might notice, the first time we increase the floor by 5, and then 4, and
then 3... which makes the sequence of testing to be [5, 9, 12, 14, 15] a
**sequence of decreasing difference**. This is to make the earlier the first egg
was tested, the bigger the space we can test for the second egg.

It is not difficult to infer that 15 = 1 + 2 + 3 + 4 + 5. So you can presumably
guess that, since 100 can be rounded up to 105 = 1 + 2 + 3 + ... + 14, so the
answer for 100-floor-building is 14.

### Mathematical Explanation

Suppose the building is n-floor-high, and you have two eggs.

Now define function p(k) = 1 + 2 + 3 + ... + k.

There must exists m such that p(m - 1) < n <= p(m)

And the minimum step to find out the floor is simply m.

### Programming Approach

The logic is fairly simple when it comes to programming. The key step we are
going to do is to split the total floor into two parts, and find the part that
takes more steps.

Let's start with naming a function called `twoEggs(int floor)`. This function
is to determine how many steps is it going to take to find the floor that the
egg will smash with the building with `floor` high **with two eggs**.

Within this function, we are going to test out all cases: iterate `i` and try to
throw the egg in `i`th floor. When you throw the first egg in `i`th floor, there
are obviously two cases: it smashes, or it doesn't. If it is smashed, you need
to test the second egg from '`1`st floor' to '`i - 1`th floor', which in total
is `i` times. If it doesn't, you can recursively call `twoEggs` with `floor - i`
since the problem is identical if we ignore the lower floors. Remember to add
`1` to the result since we throw once this time.

Because we are finding the worst case, we need to pick the maximum between these
two, which is

```
max(i, 1 + twoEggs(floor - i))
```

While we are iterating `i` to find the lease worst case, we need

```
min({ max(i, 1 + twoEggs(floor - i)) for all i })
```

So the sudo code will be:

```
procedure twoEggs(floor):
    result <- INTEGER_MAX
    for i from 1 to floor - 1:
        result <- min(result, max(i, 1 + twoEggs(floor - i)))
    return result
```

It is very noticeable that we can use Dynamic Programming in this problem since
the kind of function call is fixed (to `floor`). So we can create an array with
size of `floor` and finally the runtime will be as simple as O(n) (where n is
floor).
