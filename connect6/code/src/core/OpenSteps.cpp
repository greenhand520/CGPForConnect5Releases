//
// Created by mdmbct on 2019/12/18.
//

#include <ctime>
#include <iostream>
#include "OpenSteps.hpp"

const string OPEN_BOARD_NAMES[27] = {"", "D1寒心局", "D2溪月局", "D3疏星局", "D4花月局", "D5残月局", "D6雨月局", "D7金星局",
                                                "D8松月局",
                                                "D9丘月局", "D10新月局", "D11瑞星局", "D12山月局", "D13游星局",
                                                "I1长星局", "I2峡月局", "I3恒星局", "I4水月局", "I5流星局", "I6云月局", "I7浦月局", "I8岚风局",
                                                "I9银月局", "I10明星局", "I11邪月局", "I12明月局", "I13彗星局"
};

int count = 0;

const string &getOpenSteps(int num, vector<Step> &openSteps) {

    switch (num) {
        case 1:
            openSteps = getD1();
            break;
        case 2:
            openSteps = getD2();
            break;
        case 3:
            openSteps = getD3();
            break;
        case 4:
            openSteps = getD4();
            break;
        case 5:
            openSteps = getD5();
            break;
        case 6:
            openSteps = getD6();
            break;
        case 7:
            openSteps = getD7();
            break;
        case 8:
            openSteps = getD8();
            break;
        case 9:
            openSteps = getD9();
            break;
        case 10:
            openSteps = getD10();
            break;
        case 11:
            openSteps = getD11();
            break;
        case 12:
            openSteps = getD12();
            break;
        case 13:
            openSteps = getD13();
            break;
        case 14:
            openSteps = getI1();
            break;
        case 15:
            openSteps = getI2();
            break;
        case 16:
            openSteps = getI3();
            break;
        case 17:
            openSteps = getI4();
            break;
        case 18:
            openSteps = getI5();
            break;
        case 19:
            openSteps = getI6();
            break;
        case 20:
            openSteps = getI7();
            break;
        case 21:
            openSteps = getI8();
            break;
        case 22:
            openSteps = getI9();
            break;
        case 23:
            openSteps = getI10();
            break;
        case 24:
            openSteps = getI11();
            break;
        case 25:
            openSteps = getI12();
            break;
        case 26:
            openSteps = getI13();
            break;
        default:
            openSteps = getD1();
            break;
    }
    return OPEN_BOARD_NAMES[num];
}

const string &getRandomOpenSteps(vector<Step> &openSteps) {
    srand(time(NULL));
    // 1 ~ 26
    int num = rand() % 26 + 1;
    getOpenSteps(num, openSteps);
    return OPEN_BOARD_NAMES[num];
}

vector<Step> getD1() {

    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(9, 7, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD2() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(9, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD3() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(9, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD4() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(8, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}


vector<Step> getD5() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(8, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD6() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(7, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD7() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(7, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;;
}

vector<Step> getD8() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(6, 7, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD9() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(6, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD10() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(6, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD11() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(5, 7, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD12() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(5, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getD13() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 7, STONE_WHITE);
    Step step3(5, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI1() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(9, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI2() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(8, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI3() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(7, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI4() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(6, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI5() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(5, 9, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI6() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(7, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI7() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(6, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI8() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(5, 8, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI9() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(6, 7, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI10() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(5, 7, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI11() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(6, 6, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI12() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(5, 6, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}

vector<Step> getI13() {
    vector<Step> openSteps;
    openSteps.reserve(3);
    Step step1(7, 7, STONE_BLACK);
    Step step2(8, 8, STONE_WHITE);
    Step step3(5, 5, STONE_BLACK);
    openSteps.push_back(step1);
    openSteps.push_back(step2);
    openSteps.push_back(step3);
    return openSteps;
}





