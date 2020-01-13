#include <iostream>

#include "APICore.hpp"
#include "RandomEngine.hpp"

using namespace std;

static RandomEngine randomEngine;


void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue, bool isCheckHandForbidden, bool isFreeOpen) {
    randomEngine.setupGame(gameTimeLimit, stepTimeLimit, stoneTypeValue, isCheckHandForbidden, isFreeOpen);
}

int *startNewGame() {
    return randomEngine.startNewGame();
}

void setStoneType(int stoneColorValue) {
    randomEngine.setStoneType(stoneColorValue);
}

void cleanMemory() {
    randomEngine.cleanMemory();
}

int getFifthPlayNum() {
    return randomEngine.getFifthPlayNum();
}

int * responseOpenBoardFormatIntArray() {
    return randomEngine.responseOpenBoardFormat2dIntArray();
}

int *responseStepByLastStepFormatIntArray(const int *opponentLastStep, long gameTimeUsed) {
    return randomEngine.responseStepByLastStepFormatIntArray(opponentLastStep, gameTimeUsed);
}

int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed) {
    return randomEngine.responseStepByOrderStepsFormatIntArray(stepsOrder, orderStepsNum, gameTimeUsed);
}

bool isThirdExchange(const int *steps) {
    return randomEngine.Engine::isThirdExchange(steps);
}

void undoStep(int stoneTypeUndoValue, long gameTimeUsed) {
    randomEngine.Engine::undoStep(stoneTypeUndoValue, gameTimeUsed);
}

int *isInvalidStepFormatIntArray(long gameTimeUsed) {
    return randomEngine.isInvalidStepFormatIntArray(gameTimeUsed);
}

int * responseFifthStepsFormatIntArray(int playNum, const int *orderSteps, int orderStepsNum, long gameTimeUsed) {
    return randomEngine.responseFifthStepsFormat2dIntArray(playNum, orderSteps, orderStepsNum, gameTimeUsed);
}

void setFifthStep(const int *fifthStep) {
    randomEngine.Engine::setFifthStep(fifthStep);
}

int *decideOpponentFifthStepFormatIntArray(const int *opponentFifthSteps, int playNum, long gameTimeUsed) {
    return randomEngine.decideOpponentFifthStepFormatIntArray(opponentFifthSteps, playNum, gameTimeUsed);
}

void finishGame() {
    randomEngine.finishGame();
}
