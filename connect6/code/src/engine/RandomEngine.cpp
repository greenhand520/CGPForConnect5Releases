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

void RandomEngine::initEngine() {
    srand(time(NULL));
}

Step RandomEngine::startGame() {
    Step step(9, 9, STONE_BLACK);
    stepStack.push(step);
    return step;
}

const Step &RandomEngine::nextRandomStep() {
    Step *step = new Step(rand() % BOARD_SIZE - 1, rand() % BOARD_SIZE - 1, stoneType);
    return *step;
}

Step *RandomEngine::responseStepByLastStep(const Step &opponentLastStep) {
    stepStack.push(opponentLastStep);
    const Step &firstStep = nextRandomStep();
    stepStack.push(firstStep);
    const Step &secondStep = nextRandomStep();
    stepStack.push(secondStep);
    Step *steps = new Step[2]{firstStep, secondStep};
    return steps;
}

Step *RandomEngine::responseStepByOrderSteps(const vector<Step> &stepsOrder) {
    for (const auto & i : stepsOrder) {
        stepStack.push(i);
    }
    const Step &firstStep = nextRandomStep();
    stepStack.push(firstStep);
    const Step &secondStep = nextRandomStep();
    stepStack.push(secondStep);
    Step *steps = new Step[2]{firstStep, secondStep};
    return steps;
}

void RandomEngine::undoStep(const StoneType &stoneTypeUndo, int undoNum) {
    cout << "undo one step: " << stoneTypeUndo << endl;
    if (stoneTypeUndo == this->stoneType) {
        // 自己悔棋
        // 撤回刚才自己的落子
        if (undoNum == 1) {
            stepStack.pop();
            if (stepStack.top().getStoneType() == ::getOpponentStoneType(stoneType)) {
                stepStack.pop();
                stepStack.pop();
            }
        } else {
            stepStack.pop();
            stepStack.pop();
            // 撤回对方的落子 -> 下一次响应平台落子请求时，平台会发送最后一次对方的两个落子
            if (!stepStack.empty() ) {
                stepStack.pop();
                stepStack.pop();
            }
        }
    }else {
        // 对手悔棋
        if (stepStack.size() > 0 && stepStack.top().getStoneType() != this->stoneType) {
            if (undoNum == 1) {
                stepStack.pop();
            } else {
                stepStack.pop();
                stepStack.pop();
            }
        }
    }
}

Step *RandomEngine::isInvalidStep() {
    stepStack.pop();
    const Step &firstStep = nextRandomStep();
    stepStack.push(firstStep);
    const Step &secondStep = nextRandomStep();
    stepStack.push(secondStep);
    Step *steps = new Step[2]{firstStep, secondStep};
    return steps;
}


void RandomEngine::finishGame() {
    stack<Step>().swap(stepStack);
}


