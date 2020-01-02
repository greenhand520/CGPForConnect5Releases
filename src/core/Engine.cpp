//
// Created by mdmbct on 2019/12/13.
//

#include <iostream>
#include "Engine.hpp"

//template<class T>
//void clearVector(vector<T> &vector, bool isDeleteEveryElement);

const string &Engine::getName() const {
    return name;
}

long Engine::getGameTimeUsed() const {
    return gameTimeUsed;
}

long Engine::getStepTimeUsed() const {
    return stepTimeUsed;
}

const StoneType &Engine::getStoneType() const {
    return stoneType;
}

const StoneType &Engine::getOpponentStoneType() const {
    return opponentStoneType;
}

int Engine::getStoneTypeValue() const {
    return stoneType;
}

int Engine::getOpponentStoneTypeValue() const {
    return opponentStoneType;
}

long Engine::getGameTimeLimit() const {
    return gameTimeLimit;
}

long Engine::getStepTimeLimit() const {
    return stepTimeLimit;
}

bool Engine::isCheckHandForbidden() const {
    return checkHandForbidden;
}

bool Engine::isFreeOpen() const {
    return freeOpen;
}

void Engine::setPlayTime(long gameTimeLimit, long stepTimeLimit) {
    this->gameTimeLimit = gameTimeLimit;
    this->stepTimeLimit = stepTimeLimit;
}

void Engine::setStoneType(int stoneTypeValue) {
    stoneType = Step::getStoneType(stoneTypeValue);
    opponentStoneType = Step::getOpponentStoneType(stoneType);
}


void Engine::setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue,
                       bool isCheckHandForbidden, bool isFreeOpen) {
    this->gameTimeLimit = gameTimeLimit;
    this->stepTimeLimit = stepTimeLimit;
    setStoneType(stoneTypeValue);
    this->checkHandForbidden = isCheckHandForbidden;
    this->freeOpen = isFreeOpen;
    initEngine();
}

int *Engine::stepToIntArray(Step &step) {
    int *stepInfo = new int[3];
    stepInfo[0] = step.getRow();
    stepInfo[1] = step.getCol();
    stepInfo[2] = step.getStoneType();
    tempIntArray.push_back(stepInfo);
    return stepInfo;
}

int *Engine::stepsToIntArray(vector<Step> steps) {
    int size = steps.size();
    int *stepInfos = new int [size * 3];
    for (int i = 0; i < size; ++i) {
        Step step = steps.at(i);
        for (int j = 0; j < 3; ++j) {
            if (j == 0) {
                stepInfos[i * 3 + j] = step.getRow();
            } else if (j == 1) {
                stepInfos[i * 3 + j] = step.getCol();
            } else {
                stepInfos[i * 3 + j] = step.getStoneType();
            }
        }
    }
    tempIntArray.push_back(stepInfos);
    return stepInfos;
}

int *Engine::startNewGame() {
    Step step = startGame();
    int *firstStepInfo = stepToIntArray(step);
    return firstStepInfo;
}

void Engine::cleanMemory() {
    vector<int *>().swap(tempIntArray);
}

int * Engine::responseOpenBoardFormat2dIntArray() {
    vector<Step> openSteps = responseOpenBoard();
    return stepsToIntArray(openSteps);
}

int *Engine::responseStepByLastStepFormatIntArray(const int *opponentLastStep) {
    Step lastStep = intArrayToStep(opponentLastStep);
    Step nextStep = responseStepByLastStep(lastStep);
    return stepToIntArray(nextStep);
}

int *Engine::responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum) {
    vector<Step> stepsOrderVector;
    intArrayToSteps(stepsOrder, orderStepsNum, stepsOrderVector);
    Step nextStep = responseStepByOrderSteps(stepsOrderVector);
    return stepToIntArray(nextStep);
}

bool Engine::isThirdExchange(const int *steps) {
    vector<Step> stepsOrderVector;
    intArrayToSteps(steps, 3, stepsOrderVector);
    bool isExchange = isThirdExchange(stepsOrderVector);
    return isExchange;
}

void Engine::undoStep(int stoneTypeUndoValue) {
    undoStep(StoneType(stoneTypeUndoValue));
}

int *Engine::isInvalidStepFormatIntArray() {
    Step newStep = isInvalidStep();
    return stepToIntArray(newStep);
}

int * Engine::responseFifthStepsFormat2dIntArray(int playNum, const int *orderSteps, int orderStepsNum) {
    vector<Step> orderStepsVector;
    intArrayToSteps(orderSteps, orderStepsNum, orderStepsVector);
    vector<Step> fifthSteps = responseFifthSteps(playNum, orderStepsVector);
    return stepsToIntArray(fifthSteps);
}

void Engine::setFifthStep(const int *fifthStep) {
    Step step = intArrayToStep(fifthStep);
    setFifthStep(step);
}

int *Engine::decideOpponentFifthStepFormatIntArray(const int *opponentFifthSteps, int playNum) {
    vector<Step> fifthStepsVector;
    intArrayToSteps(opponentFifthSteps, playNum, fifthStepsVector);
    Step step = decideOpponentFifthStep(fifthStepsVector);
    return stepToIntArray(step);
}












