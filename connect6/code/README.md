# 合肥师范学院计算机博弈比赛五子棋平台引擎C++接口

## 项目简介

使用[CLion](http://www.jetbrains.com/clion/)+[CMake](https://cmake.org/)+MinGW+C++编写的HUNUCGP的C/C++引擎接口，通过将此项目打包成动态链接库形式，[博弈平台](https://github.com/mdmbct/HFNUComputerGamePlatformForConnect5)可以调用动态链接库中的引擎。

**使用Visual Studio也是可以继续开发的。**

### 项目结构

```
│  CMakeLists.txt
└─src
    │  main.cpp 接口函数的具体实现代码，该文件名可以为任意
    │  
    ├─core
    │  │  Engine.cpp
    │  │  Step.cpp
    │  │  Utils.cpp
    │  │  
    │  └─include
    │          APICore.hpp 在此项目基础上继续添加引擎需要引入的头文件
    │          Engine.hpp 引擎基类的头文件
    │          Enums.hpp 枚举头文件
    │          Export.h HFNUCGP引擎接口函数声明的头文件
    │          Step.hpp 引擎每一步落子的头文件
    │          Utils.hpp 一些工具函数的头文件
    │          
    └─engine
        │  RandomEngine.cpp 随机落子引擎的具体实现
        │  
        └─include
                RandomEngine.hpp 随机落子引擎的头文件
```

## 使用

项目中`src/core/include/Export.h`中是平台调用动态链接库的接口函数声明，该函数必须手动用C/C++实现平台才能调用。项目中使用C++编写的一个随机落子引擎实现这些接口函数。

### 接口函数

不要修改这些接口函数的名字、参数、返回类型，否则平台会无法调用。

接口函数中的参数`gameTimeUsed`表示当前引擎的单局以使用时间。

接口函数中返回的结果或者参数类型中有指针揭示数组指针，要么是表示一个落子的int数组，要么是表示很多落子的int数组。

表示一个落子的int数组大小为3，第一个元素为落子所在行（0 - 14），第二个元素为落子所在列（0 - 14），第三个元素为落子颜色对应的int值（1->黑子， 2->白子）。

表示很多个落子的数组是每连续三个元素表示一个落子信息，所以该数组的大小始终为3的整数倍。

`void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue, bool isCheckHandForbidden, bool isFreeOpen)`

设置新一局一些规则

| 参数           | 解释                                       |
| -------------- | ------------------------------------------ |
| gameTimeLimit  | 单局时间限制                               |
| stepTimeLimit  | 单步时间限制                               |
| stoneTypeValue | 引擎执子颜色对应的int值，1->黑子， 2->白子 |

`int *startNewGame()`

新一局开始，返回引擎第一步落子的数组表示。

`void setStoneType(int stoneColorValue)`

设置引擎执子的颜色，对手三手交换时平台调用这个函数告诉引擎更换执子颜色。

`void cleanMemory()`

清理内存，C++需要开发者手动释放申请的堆区的内存，通过这个函数释放返回给平台的数组所占内存。

`int *responseStepByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed)`

将对手的上一步落子发送给引擎后获取引擎的下一步落子。

`int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed)`

将棋盘上的所有落子发送给引擎后获取引擎的下一步落子。

`void undoStep(int stoneTypeUndoValue, long gameTimeUsed)`

撤回一个落子，参数`stoneTypeUndoValue`表示撤回的落子颜色值。

`int *isInvalidStepFormatIntArray(long gameTimeUsed)`

告诉引擎上一步落子无效，返回一个新的落子。

` void finishGame()` 

结束一局，清理内存。

### 文件说明

### CMakeLists.txt

文件的一些说明如下：

```cmake
cmake_minimum_required(VERSION 3.14)
project(HFNUCGPForConnect6EngineAPIInCpp)

#引擎名
set(ENGINE_NAME RandomDllEngine)
#引擎作者
set(ENGINE_AUTHOR mdmbct)
#引擎版本
set(ENGINE_VERSION v1.0)
#引擎棋类，不可改动
set(CHESS_TYPE CONNECT5)
#引擎dll文件输出路径
set(ENGINE_OUTPUT_PATH E:/PublicFiles/Projects/IdeaProjects/HFNUCGPForConnect5/CGPData/ExtEngines)

#引擎dll文件名，形如“RandomDllEngine_CONNECT5_mdmbct_v1.0.dll”，引擎名、作者名、版本必须用‘_’分隔，否则平台无法解析
set(DLL_NAME ${ENGINE_NAME}_${CHESS_TYPE}_${ENGINE_AUTHOR}_${ENGINE_VERSION})
include_directories(src/core/include)
include_directories(src/engine/include)

aux_source_directory(src dir_srcs)
aux_source_directory(src/core api_core)
aux_source_directory(src/engine example_engine)

set(CMAKE_CXX_STANDARD 11)
set(MAIN ${dir_srcs} ${api_core} ${example_engine} src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
#生成可执行文件
#add_executable(HFNUCGPEngineAPIForCpp ${MAIN})
#生成动态链接库
add_library(${DLL_NAME} SHARED ${MAIN})
set_target_properties(${DLL_NAME} PROPERTIES LINKER_LANGUAGE C)
set_target_properties(${DLL_NAME} PROPERTIES PREFIX "")
SET(LIBRARY_OUTPUT_PATH ${ENGINE_OUTPUT_PATH})
```

### src/core

include文件夹在此项目基础上添加引擎需要用到的类、函数等的声明。core下的cpp文件是这些声明的具体实现。

| 文件        | 说明                                       |
| ----------- | ------------------------------------------ |
| APICore.hpp | 在此项目基础上继续添加引擎需要引入的头文件 |
| Engine.hpp  | 引擎基类的头文件                           |
| Enums.hpp   | 枚举头文件                                 |
| Export.h    | HFNUCGP引擎接口函数声明的头文件            |
| Step.hpp    | 引擎每一步落子的头文件                     |

#### APICore.hpp

添加自己的引擎只需`#include "APICore.h"`即可

#### Step.hpp

是表示引擎每一步落子Step类的声明，该类具体实现参阅源码。

#### Enums.hpp

包含棋子颜色类型、四个方向（横向、竖向、撇向 像这个/、捺向 像这个 \）及开局落子中文名的枚举。

#### Engine.hpp

是你需要添加的引擎的基类的声明，Engine类是个抽象类，添加的引擎需要继承该类手动实现其中的纯虚函数，实现这些纯虚函数后就不用关心Export.hpp的具体实现，只需手动添加代码调用基类Engine中对应的同名函数即可。

下面是其中的纯虚函数说明：

`virtual void initEngine() = 0`

初始化引擎。

`virtual Step startGame() = 0`

生成开局落子。

`virtual Step *responseStepByLastStep(const Step &opponentLastStep) = 0`

根据对手上一步落子产生下一步落子。

`virtual Step *responseStepByOrderSteps(const vector<Step> &stepsOrder) = 0`

根据棋盘上所有落子决定是否进行三手交换。

`virtual void undoStep(const StoneType &stoneTypeUndo) = 0`

撤销一步落子，参数表示撤销的落子颜色。

`virtual Step *isInvalidStep() = 0`

上一步落子无效并返回新的落子。

## 示例引擎

下面以项目中的`RandomEngine`为例，说明怎么在这个项目基础上添加自己的引擎。

首先创建一个`RandomEngine`类继承`Engine`，文件RandomEngine.hpp如下：

```cpp
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

    Step *responseStepByLastStep(const Step &opponentLastStep) override;

    Step *responseStepByOrderSteps(const vector<Step> &stepsOrder) override;

    void undoStep(const StoneType &stoneTypeUndo, int undoNum) override;

    Step *isInvalidStep() override;

};

#endif //HFNUCGPENGINEAPIINCPP_RANDOMENGINE_HPP

```

在Clion中通过快捷键`Ctrl + i`快速补全需要手动实现的函数。 

成员变量`stepStack`用于顺序存储棋手的每一步落子。

`RandomEngine.cpp`文件如下：

```cpp
#include "APICore.hpp"
#include "RandomEngine.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RandomEngine::RandomEngine() {

}

int RandomEngine::getFifthPlayNum() {
    // 2 ~ 4
    return rand() % 3 + 2;
}

void RandomEngine::initEngine() {
    srand(time(NULL));
}

Step RandomEngine::startGame() {
    Step step(7, 7, STONE_BLACK);
    stepStack.push(step);
    return step;
}

vector<Step> RandomEngine::responseOpenBoard() {
    vector<Step> steps;
    getRandomOpenSteps(steps);
    for (int i = 0; i < 3; ++i) {
        stepStack.push(steps.at(i));
    }
    return steps;
}

const Step &RandomEngine::nextRandomStep() {
    Step *step = new Step(rand() % 14, rand() % 14, stoneType);
    return *step;
}

Step RandomEngine::responseStepByLastStep(const Step &opponentLastStep) {
    stepStack.push(opponentLastStep);
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

Step RandomEngine::responseStepByOrderSteps(const vector<Step> &stepsOrder) {
    for (const auto & i : stepsOrder) {
        stepStack.push(i);
    }
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

bool RandomEngine::isThirdExchange(const vector<Step> &steps) {
    return rand() % 2;
}

void RandomEngine::undoStep(const StoneType &stoneTypeUndo) {
    if (!stepStack.empty()) {
        if (stepStack.top().getStoneType() == this->stoneType) {
            stepStack.pop();
            if (!stepStack.empty()) {
                stepStack.pop();
            }
        } else {
            stepStack.pop();
        }
    }
}

Step RandomEngine::isInvalidStep() {
    stepStack.pop();
    const Step &step = nextRandomStep();
    stepStack.push(step);
    delete &step;
    return stepStack.top();
}

vector<Step> RandomEngine::responseFifthSteps(int playNum, const vector<Step> &orderSteps) {
    vector<Step> steps;
    steps.reserve(playNum);
    for (int i = 0; i < playNum; ++i) {
        steps.push_back(nextRandomStep());
    }
    return steps;
}

void RandomEngine::setFifthStep(const Step &fifthStep) {
    stepStack.push(fifthStep);
}

Step RandomEngine::decideOpponentFifthStep(const vector<Step> &opponentFifthSteps) {
    return opponentFifthSteps.at(rand() % opponentFifthSteps.size());
}

void RandomEngine::finishGame() {
    stack<Step>().swap(stepStack);
}
```

**注意：**
悔棋时需要根据悔棋的颜色决定从堆栈中弹出一个还是两个棋子。如果是我方悔棋需要从堆栈中弹出两个棋子，其中第二个是对方棋子，因为在平台获取下一步我方落子会将对手的落子发送给引擎，如果不在堆栈中弹出就会出现连续两个相同棋子的情况。

在函数finishGamez中，需要清理存放棋子的堆栈的存储空间，对于复杂的落子算法，用到其他数据结构存储数据，都需要在此函数中清理它们所占的内存空间。

最后在另一个cpp文件中实现对`Export.h`中声明的函数的实现，如下:

需要在该文件中声明一个`static`的引擎类型，如代码中的`static RandomEngine randomEngine;`

`Export.h`中函数即对应引擎中的同名函数。

```cpp
#include <iostream>

#include "APICore.hpp"
#include "RandomEngine.hpp"

using namespace std;

static RandomEngine randomEngine;


void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue) {
    randomEngine.setupGame(gameTimeLimit, stepTimeLimit, stoneTypeValue);
}

int *startNewGame() {
    return randomEngine.startNewGame();
}


void cleanMemory() {
    randomEngine.cleanMemory();
}


int *responseStepByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed) {
    return randomEngine.responseStepByLastStepsFormatIntArray(opponentLastStep, gameTimeUsed);
}

int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed) {
    return randomEngine.responseStepByOrderStepsFormatIntArray(stepsOrder, orderStepsNum, gameTimeUsed);
}


void undoStep(int stoneTypeUndoValue, int undoNum, long gameTimeUsed) {
    randomEngine.Engine::undoStep(stoneTypeUndoValue, undoNum, gameTimeUsed);
}

int *isInvalidStepFormatIntArray(long gameTimeUsed) {
    return randomEngine.isInvalidStepFormatIntArray(gameTimeUsed);
}


void finishGame() {
    randomEngine.finishGame();
}

```

