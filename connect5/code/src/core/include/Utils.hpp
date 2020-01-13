//
// Created by mdmbct on 2019/12/30.
//

#ifndef HFNUCGPENGINEAPIINCPP_UTILS_HPP
#define HFNUCGPENGINEAPIINCPP_UTILS_HPP

#include "Step.hpp"
#include <iostream>
#include "vector"
#include "stack"
#include "Enums.hpp"

using namespace std;

ostream &operator<<(ostream &out, Step &step);

Step intArrayToStep(const int *stepInfo);

/**
 * 将vector里的所有Step用以为int数组表示
 * @param stepInfos 存储转换结果的int数组
 * @param stepsNum Step的数量
 * @param steps Step的vector
 */
void intArrayToSteps(const int *stepInfos, int stepsNum, vector<Step> &steps);

void printSteps(vector<Step> &steps);

void printSteps(const int *stepInfos, int stepsNum);

void printStep(const int *stepInfo);

StoneType getStoneType(int stoneTypeValue);

StoneType getOpponentStoneType(StoneType &stoneType);

#endif //HFNUCGPENGINEAPIINCPP_UTILS_HPP
