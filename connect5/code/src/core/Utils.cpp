//
// Created by mdmbct on 2019/12/30.
//

#include "Utils.hpp"


ostream &operator<<(ostream &out, Step &step) {
    out << "Step{row: "
        << step.getRow() + 1 << ",col: "
        << (char)('A' + step.getCol()) << ",stoneType: "
        << step.getStoneStr()
        << "}";
    return out;
}

Step intArrayToStep(const int *stepInfo) {
    Step step(stepInfo[0], stepInfo[1], StoneType(stepInfo[2]));
    return step;
}

void intArrayToSteps(const int *stepInfos, int stepsNum, vector<Step> &steps) {
    steps.reserve(stepsNum);
    int count = 1;
    int rowIndex, colIndex, stoneTypeIndex;
    for (int i = 0; i < stepsNum * 3; ++i) {
        if (count == 1) {
            rowIndex = i;
            count++;
        } else if (count == 2) {
            colIndex = i;
            count++;
        } else {
            stoneTypeIndex = i;
            count = 1;
            Step step(stepInfos[rowIndex], stepInfos[colIndex], StoneType(stepInfos[stoneTypeIndex]));
            steps.push_back(step);
        }
    }
}

void printSteps(vector<Step> &steps) {
    for (auto & step : steps) {
        cout << step << endl;
    }
}

void printSteps(const int *stepInfos, int stepsNum) {
    vector <Step> steps;
    intArrayToSteps(stepInfos, stepsNum, steps);
    printSteps(steps);
}

void printStep(const int *stepInfo) {
    Step step = intArrayToStep(stepInfo);
    cout << step << endl;
}

StoneType getStoneType(int stoneTypeValue) {
    switch (stoneTypeValue) {
        case 0:
            return STONE_NULL;
        case 1:
            return STONE_BLACK;
        case 2:
            return STONE_WHITE;
        default:
            return STONE_INVALID;
    }
}

StoneType getOpponentStoneType(StoneType &stoneType) {
    return stoneType == STONE_BLACK ? STONE_WHITE : STONE_BLACK;
}

