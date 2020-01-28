#include <iostream>

#include "APICore.hpp"
#include "RandomEngine.hpp"

using namespace std;

static RandomEngine randomEngine;


void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue) {
    randomEngine.setupGame(gameTimeLimit, stepTimeLimit, stoneTypeValue);
}

int *startNewGame() {
    return randomEngine.startNewGame();
}


void cleanMemory() {
    randomEngine.cleanMemory();
}


int *responseStepByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed) {
    return randomEngine.responseStepByLastStepsFormatIntArray(opponentLastStep, gameTimeUsed);
}

int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed) {
    return randomEngine.responseStepByOrderStepsFormatIntArray(stepsOrder, orderStepsNum, gameTimeUsed);
}


void undoStep(int stoneTypeUndoValue, int undoNum, long gameTimeUsed) {
    randomEngine.Engine::undoStep(stoneTypeUndoValue, undoNum, gameTimeUsed);
}

int *isInvalidStepFormatIntArray(long gameTimeUsed) {
    return randomEngine.isInvalidStepFormatIntArray(gameTimeUsed);
}


void finishGame() {
    randomEngine.finishGame();
}

//测试
int main() {

    setupGame(100000, 10000, 1);
    cout << randomEngine.getStoneType() << endl;
    int *stepInfo = startNewGame();
    printStep(stepInfo);
    int *lastSteps = new int[2 * 3] {1, 1, 0, 2, 2, 0};
    stepInfo = responseStepByLastStepsFormatIntArray(lastSteps, 9000);
    cleanMemory();
    printSteps(stepInfo, 2);
    lastSteps = new int[4 * 3]{1, 1, 0, 2, 2, 0, 3, 3, 1, 4, 4, 1};
    stepInfo = responseStepByOrderStepsFormatIntArray(lastSteps, 4, 8000);
    cleanMemory();
    printSteps(stepInfo, 4);
//    undoStep(1, 2, 7000);
    stepInfo = isInvalidStepFormatIntArray(6000);
    cleanMemory();
    printSteps(stepInfo, 2);
    cleanMemory();
    finishGame();
    return 0;
}
