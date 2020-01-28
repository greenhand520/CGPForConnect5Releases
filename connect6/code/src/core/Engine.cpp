//
// Created by mdmbct on 2019/12/13.
//

#include <iostream>
#include "Engine.hpp"

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


void Engine::setPlayTime(long gameTimeLimit, long stepTimeLimit) {
    this->gameTimeLimit = gameTimeLimit;
    this->stepTimeLimit = stepTimeLimit;
}

void Engine::setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue) {
    this->gameTimeLimit = gameTimeLimit;
    this->stepTimeLimit = stepTimeLimit;
    stoneType = ::getStoneType(stoneTypeValue);
    opponentStoneType = ::getOpponentStoneType(stoneType);
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

int *Engine::stepArrayToIntArray(Step *steps, int stepNum) {
    int *stepInfos = new int[3 * stepNum];
    for (int i = 0; i < stepNum; ++i) {
        Step step = steps[i];
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


int *Engine::responseStepByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed) {
    this->gameTimeUsed = gameTimeUsed;
    Step lastStep = intArrayToStep(opponentLastStep);
    Step *nextSteps = responseStepByLastStep(lastStep);
    return stepArrayToIntArray(nextSteps, 2);
}

int *Engine::responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed) {
    this->gameTimeUsed = gameTimeUsed;
    vector<Step> stepsOrderVector;
    intArrayToSteps(stepsOrder, orderStepsNum, stepsOrderVector);
    Step *nextSteps = responseStepByOrderSteps(stepsOrderVector);
    int *stepInfos = stepArrayToIntArray(nextSteps, 2);
    return stepInfos;
}


void Engine::undoStep(int stoneTypeUndoValue, int undoNum, long gameTimeUsed) {
    this->gameTimeUsed = gameTimeUsed;
    undoStep(StoneType(stoneTypeUndoValue), undoNum);
}

int *Engine::isInvalidStepFormatIntArray(long gameTimeUsed) {
    this->gameTimeUsed = gameTimeUsed;
    Step *newSteps = isInvalidStep();
    int *stepInfos = stepArrayToIntArray(newSteps, 2);
    return stepInfos;
}
















