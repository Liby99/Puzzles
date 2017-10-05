var STOPS = [
    [0, 0],
    [0, 1],
    [1, 1]
];
var INTERVAL = 2;
var TIME = 3;

function calcDistance(p1, p2) {
    return Math.sqrt(Math.pow(p1[0] - p2[0], 2) + Math.pow(p1[1] - p2[1], 2));
}

function equals(p1, p2) {
    return p1[0] == p2[0] && p1[1] == p2[1];
}
 
function takeAction(currTime, currStop, lastPos) {
    
    // First check if the player need to stay
    var timeInInterval = INTERVAL - currTime % INTERVAL;
    var stayReward = 0, goReward = 0;
    
    // Check if the player has already finished the trials
    if (currStop == STOPS.length - 1) {
        return 0;
    }
    
    // If can stay, calculate the reward if the player stays
    if (currTime % INTERVAL != 0) {
        var reward = calcDistance(STOPS[currStop], lastPos);
        stayReward = reward + takeAction(currTime + timeInInterval, currStop, STOPS[currStop]);
    }
    
    // Calculate the reward if the player choose to go
    var currPos = []; currPos[0] = STOPS[currStop][0]; currPos[1] = STOPS[currStop][1];
    var nextPos = STOPS[currStop + 1];
    var id = currPos[0] == nextPos[0] ? 1 : 0;
    var dir = nextPos[id] - currPos[id] > 0 ? 1 : -1;
    var dist = Math.abs(nextPos[id] - currPos[id]);
    
    // Check if the player can reach the next step on time, else return
    if (currTime + dist > TIME) {
        return -TIME;
    }
    
    if (dist < timeInInterval) {
        goReward = takeAction(currTime + dist, currStop + 1, lastPos);
    }
    else {
        var loopAmount = Math.floor(dist / INTERVAL);
        var travelTime = dist - dist % INTERVAL;
        currPos[id] += dir * travelTime;
        goReward = travelTime + takeAction(currTime + dist, currStop + loopAmount, currPos);
    }
    
    // Return the maximum between stay and go
    return Math.max(stayReward, goReward);
}

console.log(takeAction(0, 0, STOPS[0]));
