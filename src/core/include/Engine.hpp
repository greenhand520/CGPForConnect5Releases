//
// Created by mdmbct on 2019/12/9.
//

#ifndef HFNUCGPENGINEAPIFORCPP_ENGINE_HPP
#define HFNUCGPENGINEAPIFORCPP_ENGINE_HPP

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

protected:
    static const int BOARD_SIZE = 15;
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
    /**
     * 是否采用禁手检查
     */
    bool checkHandForbidden;
    /**
     * 是否自由开局
     */
    bool freeOpen;

    virtual void initEngine() = 0;

    virtual Step startGame() = 0;

    virtual vector<Step> responseOpenBoard() = 0;

    virtual Step responseStepByLastStep(const Step &opponentLastStep) = 0;

    virtual Step responseStepByOrderSteps(const vector<Step> &stepsOrder) = 0;

    virtual bool isThirdExchange(const vector<Step> &steps) = 0;

    virtual void undoStep(const StoneType &stoneTypeUndo) = 0;

    virtual Step isInvalidStep() = 0;

    virtual vector<Step> responseFifthSteps(int playNum, const vector<Step> &orderSteps) = 0;

    virtual void setFifthStep(const Step &fifthStep) = 0;

    virtual Step decideOpponentFifthStep(const vector<Step> &opponentFifthSteps) = 0;

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

    bool isCheckHandForbidden() const;

    bool isFreeOpen() const;

    void setPlayTime(long gameTimeLimit, long stepTimeLimit);

    void setStoneType(int stoneColorValue);

    void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue,
                   bool isCheckHandForbidden, bool isFreeOpen);

    /**
     * Java代码调用这个函数实现内存释放
     */
    void cleanMemory();

    int *startNewGame();

    virtual int getFifthPlayNum() = 0;

    int * responseOpenBoardFormat2dIntArray();

    int *responseStepByLastStepFormatIntArray(const int *opponentLastStep, long gameTimeUsed);

    int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed);

    bool isThirdExchange(const int *steps);

    void undoStep(int stoneTypeUndoValue, long gameTimeUsed);

    int *isInvalidStepFormatIntArray(long gameTimeUsed);

    int *responseFifthStepsFormat2dIntArray(int playNum, const int *orderSteps, int orderStepsNum, long gameTimeUsed);

    void setFifthStep(const int *fifthStep);

    int *decideOpponentFifthStepFormatIntArray(const int *opponentFifthSteps, int playNum, long gameTimeUsed);

    virtual void finishGame() = 0;
};

#endif //HFNUCGPENGINEAPIFORCPP_ENGINE_HPP
