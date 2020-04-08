//
// Created by mdmbct on 2019/12/9.
//

#ifndef HFNUCGPENGINEAPIINCPP_RANDOMENGINE_HPP
#define HFNUCGPENGINEAPIINCPP_RANDOMENGINE_HPP


#include "APICore.hpp"
#include "stack"

class RandomEngine : public Engine{

private:

    const Step & nextRandomStep();

    stack <Step> stepStack;

public:
    RandomEngine();

    void finishGame() override;

protected:
    void initEngine() override;

    Step startGame() override;

    Step *responseStepsByLastSteps(const Step &opponentLastStep) override;

    Step *responseStepsByOrderSteps(const vector<Step> &stepsOrder) override;

    void undoStep(const StoneType &stoneTypeUndo, int undoNum) override;

    Step *isInvalidSteps() override;

};

#endif //HFNUCGPENGINEAPIINCPP_RANDOMENGINE_HPP
