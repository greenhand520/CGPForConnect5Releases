//
// Created by mdmbct on 2019/12/9.
//

#ifndef HFNUCGPENGINEAPIFORCPP_STEP_HPP
#define HFNUCGPENGINEAPIFORCPP_STEP_HPP

#include "Enums.hpp"
#include<string>

class Step final{

private:
    static const std::string STONE_COLOR_STR[4];
    static const std::string STONE_SHAPES[4];
    static const std::string STONE_PREDICTED_SHAPES[4];
    int row;
    int col;
    StoneType stoneType;
    int score;
    int directScores[4];
public:

    Step(int row, int col, StoneType stoneType);

    Step(const Step &step);

//    ~Step();

    int getRow() const;

    void setRow(int row);

    int getCol() const;

    void setCol(int col);

    int getStoneType() const;

    void setStoneType(StoneType &stoneType);

    int getScore() const;

    void setScore(int score);

    const int *getDirectScores() const;

    int getDirectScore(Direction &direction);

    void setDirectScore(Direction &direction, int directScore);

    void setDirectScores(int newDirectScores[4]);

    int getIndex();

    static StoneType getStoneType(int stoneTypeValue);

    StoneType getOpponentStoneType();

    static StoneType getOpponentStoneType(StoneType &stoneType);

    const std::string &getStoneStr();

    const std::string &getStoneShape();

    const std::string &getStonePredictedShape();

};


#endif //HFNUCGPENGINEAPIFORCPP_STEP_HPP
