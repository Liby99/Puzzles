#include <iostream>

int * caches;

/**
 * Get the minimum amount of steps to take to find out what is the lowest floor
 * that the egg will crash when fall with 1 eggs.
 * @param  floor the maximum floor
 * @return       
 */
int oneEgg(int floor) {
    return floor;
}

/**
 * Get the minimum amount of steps to take to find out what is the lowest floor
 * that the egg will crash when fall with 2 eggs.
 * @param  floor [description]
 * @return       [description]
 */
int twoEgg(int floor) {
    
    // Check if the number is already cached.
    if (caches[floor]) {
        
        // We are using dynamic programming here, so if the floor is already
        // computed, we directly return the number from caches.
        return caches[floor];
    }
    else {
        
        // Initiate the minCount
        int minCount = floor + 1;
        for (int i = 1; i < floor; i++) {
            
            // !IMPORTANT
            // For Worst Case Scenario, We Take the MAX between the following 2
            // Situations:
            //   1. in this floor the egg crashed, and we only have one egg then
            //      we need to act linearly from 1st floor to ith floor
            //   2. the egg is not crashed yet, and we still have two eggs. But
            //      the remaining floors to test is (floor - i) floors. So we
            //      use 1 (the current step) + the step to test the rest floor,
            //      which is a recursion call of twoEgg.
            int count = std::max(oneEgg(i), 1 + twoEgg(floor - i));
            
            // Compare this count with the minimum count. If is min, update
            if (count < minCount) {
                minCount = count;
            }
        }
        
        // Update the cache and return the value
        return caches[floor] = minCount;
    }
}

int main(int argc, char ** argv) {
    
    // Initiate the floor number
    int floor;
    
    // Check if the number is specified in the command line argument. If not,
    // give it 100.
    if (argc >= 2) floor = atoi(argv[1]);
    else floor = 100;
    
    // Initiate the caches. the initial values will be 0.
    caches = (int *)malloc((floor + 1) * sizeof(int));
    for (int i = 0; i < floor + 1; i++) {
        caches[i] = 0;
    }
    caches[0] = 1;
    caches[1] = 1;
    
    // Finally get the answer by passing the floor amount to the twoEgg function
    std::cout << twoEgg(floor) << std::endl;
}
