#include <iostream>

#include "APICore.hpp"
#include "RandomEngine.hpp"

using namespace std;

static RandomEngine randomEngine;


void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue, bool isCheckHandForbidden, bool isFreeOpen) {
    randomEngine.setupGame(gameTimeLimit, stepTimeLimit, stoneTypeValue, isCheckHandForbidden, isFreeOpen);
    cout << "function setupGame is called..." << endl;
}

int *startNewGame() {
    cout << "function startNewGame is called..." << endl;
    return randomEngine.startNewGame();
}

void cleanMemory() {
    randomEngine.cleanMemory();
    cout << "function cleanMemory is called..." << endl;
}

int getFifthPlayNum() {
    cout << "function getFifthPlayNum is called..." << endl;
    return randomEngine.getFifthPlayNum();
}

int * responseOpenBoardFormatIntArray() {
    cout << "function responseOpenBoardFormatIntArray is called..." << endl;
    return randomEngine.responseOpenBoardFormat2dIntArray();
}

int *responseStepByLastStepFormatIntArray(const int *opponentLastStep, long gameTimeUsed) {
    cout << "function responseStepByLastStepFormatIntArray is called..." << endl;
    cout << "opponentLastStep: ";
    printStep(opponentLastStep);
    return randomEngine.responseStepByLastStepFormatIntArray(opponentLastStep, gameTimeUsed);
}

int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed) {
    cout << "function responseStepByOrderStepsFormatIntArray is called..." << endl;
    cout << "orderStepsNum: " << orderStepsNum << endl;
    cout << "stepsOrder: " << endl;
    printSteps(stepsOrder, orderStepsNum);
    return randomEngine.responseStepByOrderStepsFormatIntArray(stepsOrder, orderStepsNum, gameTimeUsed);
}

bool isThirdExchange(const int *steps) {
    cout << "function isThirdExchange is called..." << endl;
    cout << "steps: " << endl;
    printSteps(steps, 3);
    return randomEngine.Engine::isThirdExchange(steps);
}

void undoStep(int stoneTypeUndoValue, long gameTimeUsed) {
    cout << "function undoStep is called..." << endl;
    randomEngine.Engine::undoStep(stoneTypeUndoValue, gameTimeUsed);
}

int *isInvalidStepFormatIntArray(long gameTimeUsed) {
    cout << "function isInvalidStepFormatIntArray is called..." << endl;
    return randomEngine.isInvalidStepFormatIntArray(gameTimeUsed);
}

int * responseFifthStepsFormatIntArray(int playNum, const int *orderSteps, int orderStepsNum, long gameTimeUsed) {
    cout << "function responseFifthStepsFormatIntArray is called..." << endl;
    cout << "playNum: " << playNum << endl;
    cout << "orderStepsNum: " << orderStepsNum << endl;
    cout << "orderSteps: " << endl;
    printSteps(orderSteps, orderStepsNum);
    return randomEngine.responseFifthStepsFormat2dIntArray(playNum, orderSteps, orderStepsNum, gameTimeUsed);
}

void setFifthStep(const int *fifthStep) {
    cout << "function setFifthStep is called..." << endl;
    cout << "fifthStep: " << endl;
    printStep(fifthStep);
    randomEngine.Engine::setFifthStep(fifthStep);
}

int *decideOpponentFifthStepFormatIntArray(const int *opponentFifthSteps, int playNum, long gameTimeUsed) {
    cout << "function decideOpponentFifthStepFormatIntArray is called..." << endl;
    cout << "playerNum: " << playNum << endl;
    cout << "opponentFifthSteps :" << endl;
    printSteps(opponentFifthSteps, playNum);
    return randomEngine.decideOpponentFifthStepFormatIntArray(opponentFifthSteps, playNum, gameTimeUsed);
}

void finishGame() {
    cout << "function finishGame is called" << endl;
    randomEngine.finishGame();
}


int main() {

//    vector<Step> steps;
//    const string &name = getRandomOpenSteps(steps);
//    cout << name << endl;
//    for (int i = 0; i < steps.size(); ++i) {
//        cout << &steps.at(i) << endl;
//    }
//    setupGame(200000, 200000, 1, false, true);
//    startNewGame();
//    cout << "-----------------startNewGameOver" << endl;
//    responseOpenBoardFormatIntArray();
//    cout << "-----------------responseOpenBoardFormat2dIntArrayOver" << endl;
//    const int *step = new int[3] {1, 1, 1};
//    responseStepByLastStepFormatIntArray(step);
//    cout << "-----------------responseStepByLastStepFormatIntArrayOver" << endl;
    //    int **stepInfos = new int *[3];
//    stepInfos[0] = new int[3]{1, 1, 1};
//    stepInfos[1] = new int[3]{1, 2, 2};
//    stepInfos[2] = new int[3]{1, 3, 1};
//    const int **steps;
//    responseFifthStepsFormatIntArray(2, steps, 5);
//    cout << "-----------------responseFifthStepsFormat2dIntArrayOver" << endl;
//    responseStepByOrderStepsFormatIntArray(steps, 10);
//    cout << "-----------------responseStepByOrderStepsFormatIntArrayOver" << endl;

//    int *stepInfo = startNewGame();
//    cout << &stepInfo << endl;
//    cleanMemory();
//    cout << &randomEngine.tempIntArray << endl;
//    cout << stepInfo[0] << endl;
//    cout << stepInfo[1] << endl;
//    cout << stepInfo[2] << endl;
//    finishGame();

 }