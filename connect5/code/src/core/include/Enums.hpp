//
// Created by mdmbct on 2019/12/13.
//

#ifndef HFNUCGPENGINEAPIFORCPP_ENUMS_HPP
#define HFNUCGPENGINEAPIFORCPP_ENUMS_HPP

enum StoneType {
    STONE_NULL = 0,
    STONE_BLACK = 1,
    STONE_WHITE = 2,
    /**
     * 无效棋子,用于引擎中填充超出边界的棋子
     */
    STONE_INVALID = 3
};

enum Direction {
    /**
     * 横向
     */
    HORIZONTAL = 0,
    /**
     * 竖向
     */
    VERTICAL = 1,
    /**
     * 撇向 像这个/
     */
    TOP_RIGHT_TO_BOTTOM_LEFT = 2,
    /**
     * 捺向 像这个 \
     */
    TOP_LEFT_TO_BOTTOM_RIGHT = 3
};

enum OpenBoardName {
    D1 = 1,
    D2 = 2,
    D3 = 3,
    D4 = 4,
    D5 = 5,
    D6 = 6,
    D7 = 7,
    D8 = 8,
    D9 = 9,
    D10 = 10,
    D11 = 11,
    D12 = 12,
    D13 = 13,
    I1 = 14,
    I2 = 15,
    I3 = 16,
    I4 = 17,
    I5 = 18,
    I6 = 19,
    I7 = 20,
    I8 = 21,
    I9 = 22,
    I10 = 23,
    I11 = 24,
    I12 = 25,
    I13 = 26
};

#endif //HFNUCGPENGINEAPIFORCPP_ENUMS_HPP
