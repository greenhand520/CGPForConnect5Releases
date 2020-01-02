//
// Created by mdmbct on 2019/12/9.
//

#ifndef HFNUCGPENGINEAPIFORCPP_RANDOMENGINE_HPP
#define HFNUCGPENGINEAPIFORCPP_RANDOMENGINE_HPP

#include "APICore.hpp"
#include "stack"

class RandomEngine : public Engine{

private:

    const Step & nextRandomStep();

    stack <Step> stepStack;

public:
    RandomEngine();

    int getFifthPlayNum() override;

    void finishGame() override;

protected:
    void initEngine() override;

    Step startGame() override;

    vector<Step> responseOpenBoard() override;

    Step responseStepByLastStep(const Step &opponentLastStep) override;

    Step responseStepByOrderSteps(const vector<Step> &stepsOrder) override;

    bool isThirdExchange(const vector<Step> &steps) override;

    void undoStep(const StoneType &stoneTypeUndo) override;

    Step isInvalidStep() override;

    vector<Step> responseFifthSteps(int playNum, const vector<Step> &orderSteps) override;

    void setFifthStep(const Step &fifthStep) override;

    Step decideOpponentFifthStep(const vector<Step> &opponentFifthSteps) override;

};




#endif //HFNUCGPENGINEAPIFORCPP_RANDOMENGINE_HPP
