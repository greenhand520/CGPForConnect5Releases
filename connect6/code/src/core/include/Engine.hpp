//
// Created by mdmbct on 2019/12/9.
//

#ifndef HFNUCGPENGINEAPIINCPP_ENGINE_HPP
#define HFNUCGPENGINEAPIINCPP_ENGINE_HPP

#include <string>
#include "Step.hpp"
#include "vector"
#include "Utils.hpp"

using namespace std;

class Engine {
private:

    /**
     * Java调用内存清理函数清理vector里的内容所占内存
     */
    vector<int *> tempIntArray;

    int *stepToIntArray(Step &step);

    int * stepsToIntArray(vector<Step> steps);

    int *stepArrayToIntArray(Step *steps, int stepNum);

protected:
    static const int BOARD_SIZE = 19;
    string name;
    /**
     * 单局已使用时间
     */
    long gameTimeUsed;
    /**
     * 单步已使用时间
     */
    long stepTimeUsed;

    // 下面是玩家的配置信息
    /**
     * 玩家执子类型
     */
    StoneType stoneType;
    StoneType opponentStoneType;
    long gameTimeLimit;
    long stepTimeLimit;

    virtual void initEngine() = 0;

    virtual Step startGame() = 0;

    virtual Step *responseStepByLastStep(const Step &opponentLastStep) = 0;

    virtual Step *responseStepByOrderSteps(const vector<Step> &stepsOrder) = 0;

    virtual void undoStep(const StoneType &stoneTypeUndo, int undoNum) = 0;

    virtual Step *isInvalidStep() = 0;

public:

    const string &getName() const;

    long getGameTimeUsed() const;

    long getStepTimeUsed() const;

    const StoneType &getStoneType() const;

    const StoneType &getOpponentStoneType() const;

    int getStoneTypeValue() const;

    int getOpponentStoneTypeValue() const;

    long getGameTimeLimit() const;

    long getStepTimeLimit() const;

    void setPlayTime(long gameTimeLimit, long stepTimeLimit);

    void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue);

    /**
     * Java代码调用这个函数实现内存释放
     */
    void cleanMemory();

    int *startNewGame();

    int *responseStepByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed);

    int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed);

    void undoStep(int stoneTypeUndoValue, int undoNum, long gameTimeUsed);

    int *isInvalidStepFormatIntArray(long gameTimeUsed);

    virtual void finishGame() = 0;
};

#endif //HFNUCGPENGINEAPIINCPP_ENGINE_HPP
