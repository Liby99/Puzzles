#include <iostream>

int * caches;

int oneEgg(int floor) {
    return floor;
}

int twoEgg(int floor) {
    if (caches[floor] >= 0) {
        return caches[floor];
    }
    else {
        int minCount = floor + 1;
        for (int i = 1; i < floor; i++) {
            int count = std::max(oneEgg(i), 1 + twoEgg(floor - i));
            if (count < minCount) {
                minCount = count;
            }
        }
        return caches[floor] = minCount;
    }
}

int main(int argc, char ** argv) {
    int floor;
    
    if (argc >= 2) {
        floor = atoi(argv[1]);
    }
    else {
        floor = 100;
    }
    
    caches = (int *)malloc((floor + 1) * sizeof(int));
    for (int i = 0; i < floor + 1; i++) {
        caches[i] = -1;
    }
    caches[0] = 1;
    caches[1] = 1;
    std::cout << twoEgg(floor) << std::endl;
}
