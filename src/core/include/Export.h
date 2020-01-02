//
// Created by mdmbct on 2019/12/19.
//

#ifndef HFNUCGPENGINEAPIFORCPP_EXPORT_HPP
#define HFNUCGPENGINEAPIFORCPP_EXPORT_HPP

#ifdef _WIN32
#   define DLL_EXPORT __declspec(dllexport)
#else
#   define DLL_EXPORT
#endif

extern "C" DLL_EXPORT void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue,
                                     bool isCheckHandForbidden, bool isFreeOpen);

extern "C" DLL_EXPORT int *startNewGame();

extern "C" DLL_EXPORT void cleanMemory();

extern "C" DLL_EXPORT int getFifthPlayNum();

extern "C" DLL_EXPORT int *responseOpenBoardFormatIntArray();

extern "C" DLL_EXPORT int *responseStepByLastStepFormatIntArray(const int *opponentLastStep);

extern "C" DLL_EXPORT int *responseStepByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum);

extern "C" DLL_EXPORT bool isThirdExchange(const int *steps);

extern "C" DLL_EXPORT void undoStep(int stoneTypeUndoValue);

extern "C" DLL_EXPORT int *isInvalidStepFormatIntArray();

extern "C" DLL_EXPORT int *responseFifthStepsFormatIntArray(int playNum, const int *orderSteps, int orderStepsNum);

extern "C" DLL_EXPORT void setFifthStep(const int *fifthStep);

extern "C" DLL_EXPORT int *decideOpponentFifthStepFormatIntArray(const int *opponentFifthSteps, int playNum);

extern "C" DLL_EXPORT void finishGame();

#endif //HFNUCGPENGINEAPIFORCPP_EXPORT_HPP
