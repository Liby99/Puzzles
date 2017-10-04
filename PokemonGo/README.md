# Pokemon Go

> Source: Microsoft Coding Challenge Fall 2017 @ UCSD

## Problem Description

Pokemon Go is totally still a thing, right? Well, it is to you at least. You've been playing
non-stop, but you want to optimize your experience. More specifically, you want to hatch more eggs.
In this version of the game, you hatch eggs by walking around and getting credit for the distance
you've walked. The game, however, uses a polling model and checks your current position at fixed
intervals and calculates the straight line distance between those points. This means that if you
aren't walking in a straight line, you aren't getting credit for all of the distance you walked.

For this problem, you will be given a set amount of time to walk along a fixed path of PokeStops
and the time interval at which the game queries your position. You must walk the straight line path
from PokeStop to PokeStop, and you may never go backward. You also must make it to the final
PokeStop within the time limit. Consecutive PokeStops will always be axis aligned, meaning you will
always be walking parallel to the x or y axis. You always move at one unit per second. For
simplicity, time works in discrete manner. In other words, at each second, you are at an integer set
of coordinates.

Your goal is to get credit for the most distance while completing the path in time. You may stop and
wait for any number of seconds at any time to increase the distance you receive.

Let's consider an example for which the polling interval is 2 seconds and you have a 4 second time
limit. Your path will need to run from (0, 0) to (1, 0) to (1, 1). In this case, you would wait at
(1, 0) for 1 second to get credit for one unit of distance at the first polling interval; you would
then go to the final stop, for a total of 2 distance units. If, however, you did not wait at (1, 0),
you would only get credit for sqrt(2) units of distance.

Note If you make it to the last stop with extra time, but not enough time for a polling interval to
pass, assume you wait infinitely at the last stop. (i.e. You do get credit for this movement.)

### Input definition

The first line of an input file for this problem will contain 3 integers, N, T, and K, the number of
PokeStops, the time limit, and the polling interval, respectively. The following N lines will
contain 2 integers describing the (X, Y) coordinates of each PokeStop in the order that you must
travel to them.

The following constraints apply:

* 2 ≤ N ≤ 10
* 3 ≤ K ≤ 100
* -105 < X, Y < 105
* D ≤ T ≤ D + (NK / 2) where D is the total distance of the path that needs to be walked.
* You will always have enough time to complete the path.

### Output definition

Your output should contain the maximum distance you could receive credit for with the given
constraints. The value should be rounded to 2 decimal places.

### Example input

7 60 12
0 0
0 10
10 10
10 0
20 0
20 10
30 10

### Example output

46.77
