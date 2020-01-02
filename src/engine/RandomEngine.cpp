//
// Created by mdmbct on 2019/12/9.
//

#include "APICore.hpp"
#include "RandomEngine.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RandomEngine::RandomEngine() {

}

int RandomEngine::getFifthPlayNum() {
    // 2 ~ 4
    return rand() % 3 + 2;
}

void RandomEngine::initEngine() {
    srand(time(NULL));
}

Step RandomEngine::startGame() {
    Step step(7, 7, STONE_BLACK);
    stepStack.push(step);
    return step;
}

vector<Step> RandomEngine::responseOpenBoard() {
    vector<Step> steps;
    getRandomOpenSteps(steps);
    for (int i = 0; i < 3; ++i) {
        stepStack.push(steps.at(i));
    }
    return steps;
}

const Step &RandomEngine::nextRandomStep() {
    Step *step = new Step(rand() % 14, rand() % 14, stoneType);
    return *step;
}

Step RandomEngine::responseStepByLastStep(const Step &opponentLastStep) {
    stepStack.push(opponentLastStep);
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

Step RandomEngine::responseStepByOrderSteps(const vector<Step> &stepsOrder) {
    for (const auto & i : stepsOrder) {
        stepStack.push(i);
    }
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

bool RandomEngine::isThirdExchange(const vector<Step> &steps) {
    return rand() % 2;
}

void RandomEngine::undoStep(const StoneType &stoneTypeUndo) {
    cout << "undo one step: " << stoneTypeUndo << endl;
    if (!stepStack.empty()) {
        if (stepStack.top().getStoneType() == this->stoneType) {
            stepStack.pop();
            if (!stepStack.empty()) {
                stepStack.pop();
            }
        } else {
            stepStack.pop();
        }
    }
}

Step RandomEngine::isInvalidStep() {
    stepStack.pop();
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

vector<Step> RandomEngine::responseFifthSteps(int playNum, const vector<Step> &orderSteps) {
    vector<Step> steps;
    steps.reserve(playNum);
    for (int i = 0; i < playNum; ++i) {
        steps.push_back(nextRandomStep());
    }
    return steps;
}

void RandomEngine::setFifthStep(const Step &fifthStep) {
    stepStack.push(fifthStep);
}

Step RandomEngine::decideOpponentFifthStep(const vector<Step> &opponentFifthSteps) {
    return opponentFifthSteps.at(rand() % opponentFifthSteps.size());
}

void RandomEngine::finishGame() {
    stack<Step>().swap(stepStack);
}


