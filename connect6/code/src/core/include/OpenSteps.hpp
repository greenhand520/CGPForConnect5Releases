//
// Created by mdmbct on 2019/12/18.
//

#ifndef HFNUCGPENGINEAPIINCPP_OPENSTEPS_HPP
#define HFNUCGPENGINEAPIINCPP_OPENSTEPS_HPP

#include <string>
#include "Enums.hpp"
#include "Step.hpp"
#include "vector"

using namespace std;


const string &getOpenSteps(int num, vector<Step> &openSteps);

const string &getRandomOpenSteps(vector<Step> &openSteps);

vector<Step> getD1();

vector<Step> getD2();

vector<Step> getD3();

vector<Step> getD4();

vector<Step> getD5();

vector<Step> getD6();

vector<Step> getD7();

vector<Step> getD8();

vector<Step> getD9();

vector<Step> getD10();

vector<Step> getD11();

vector<Step> getD12();

vector<Step> getD13();

vector<Step> getI1();

vector<Step> getI2();

vector<Step> getI3();

vector<Step> getI4();

vector<Step> getI5();

vector<Step> getI6();

vector<Step> getI7();

vector<Step> getI8();

vector<Step> getI9();

vector<Step> getI10();

vector<Step> getI11();

vector<Step> getI12();

vector<Step> getI13();

#endif //HFNUCGPENGINEAPIINCPP_OPENSTEPS_HPP
