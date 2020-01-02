//
// Created by mdmbct on 2019/12/30.
//

#ifndef HFNUCGPENGINEAPIFORCPP_UTILS_HPP
#define HFNUCGPENGINEAPIFORCPP_UTILS_HPP

#include "Step.hpp"
#include <iostream>
#include "vector"

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

#endif //HFNUCGPENGINEAPIFORCPP_UTILS_HPP
