//
// Created by mdmbct on 2019/12/9.
//

#include <string>
#include <iostream>
#include "Step.hpp"
#include "Enums.hpp"

using namespace std;

const string Step::STONE_COLOR_STR[4] = {"Empty", "BlackStone", "WhiteStone", "InvalidStone"};
const string Step::STONE_SHAPES[4] = {".", "●", "○", "x"};
const string Step::STONE_PREDICTED_SHAPES[4] = {".", "■", "□", "x"};

Step::Step(int row, int col, StoneType stoneType) : row(row), col(col), stoneType(stoneType), score(0), directScores{0, 0, 0, 0} {
//    cout << "new Step " << &this->row << endl;
}

Step::Step(const Step &step) : row(step.row), col(step.col), stoneType(step.stoneType),
                               score(step.score), directScores{step.directScores[0], step.directScores[1], step.directScores[2], step.directScores[3]} {
//    cout << &step.row << " is copied, " << &this->row << endl;
}

//Step::~Step() {
//    cout << "Delete Step " << &this->row << endl;
//}

int Step::getRow() const {
    return row;
}

void Step::setRow(int row) {
    this->row = row;
}

int Step::getCol() const {
    return col;
}

void Step::setCol(int col) {
    this->col = col;
}

int Step::getStoneType() const {
    return stoneType;
}

void Step::setStoneType(StoneType &stoneType) {
    this->stoneType= stoneType;
}

int Step::getScore() const {
    return score;
}

void Step::setScore(int score) {
    this->score = score;
}

const int *Step::getDirectScores() const {
    return directScores;
}

int Step::getDirectScore(Direction &direction) {
    switch (direction) {
        case HORIZONTAL:
            return directScores[0];
        case VERTICAL:
            return directScores[1];
        case TOP_RIGHT_TO_BOTTOM_LEFT:
            return directScores[2];
        case TOP_LEFT_TO_BOTTOM_RIGHT:
            return directScores[3];
        default:
            return 0;
    }
}

void Step::setDirectScore(Direction &direction, int directScore) {
    switch (direction) {
        case HORIZONTAL:
            directScores[0] = directScore;
        case VERTICAL:
            directScores[1] = directScore;
        case TOP_RIGHT_TO_BOTTOM_LEFT:
            directScores[2] = directScore;
        case TOP_LEFT_TO_BOTTOM_RIGHT:
            directScores[3] = directScore;
    }
}

void Step::setDirectScores(int newDirectScores[4]) {

    int *p = newDirectScores;
    for (int &directScore : directScores) {
        directScore = *p;
        p++;
    }
}


int Step::getIndex() {
    switch (this->stoneType) {
        case STONE_BLACK:
            return 0;
        case STONE_WHITE:
            return 1;
        default:
            return 2;
    }
}

StoneType Step::getStoneType(int stoneTypeValue) {
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

StoneType Step::getOpponentStoneType() {
    return this->stoneType == STONE_BLACK ? STONE_WHITE : STONE_BLACK;
}


StoneType Step::getOpponentStoneType(StoneType &stoneType) {
    return stoneType == STONE_BLACK ? STONE_WHITE : STONE_BLACK;
}

const string &Step::getStoneStr() {
    return STONE_COLOR_STR[stoneType];
}

const string &Step::getStoneShape() {
    return STONE_SHAPES[stoneType];
}

const string &Step::getStonePredictedShape() {
    return STONE_PREDICTED_SHAPES[stoneType];
}



























