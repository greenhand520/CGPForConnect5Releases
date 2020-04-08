//
// Created by mdmbct on 2019/12/19.
//

#ifndef HFNUCGPENGINEAPIINCPP_EXPORT_H
#define HFNUCGPENGINEAPIINCPP_EXPORT_H

#ifdef _WIN32
#   define DLL_EXPORT __declspec(dllexport)
#else
#   define DLL_EXPORT
#endif

extern "C" DLL_EXPORT void setupGame(long gameTimeLimit, long stepTimeLimit, int stoneTypeValue);

extern "C" DLL_EXPORT int *startNewGame();

extern "C" DLL_EXPORT void cleanMemory();

extern "C" DLL_EXPORT int *responseStepsByLastStepsFormatIntArray(const int *opponentLastStep, long gameTimeUsed);

extern "C" DLL_EXPORT int *responseStepsByOrderStepsFormatIntArray(const int *stepsOrder, int orderStepsNum, long gameTimeUsed);

extern "C" DLL_EXPORT void undoStep(int stoneTypeUndoValue, int undoNum, long gameTimeUsed);

extern "C" DLL_EXPORT int *isInvalidStepsFormatIntArray(long gameTimeUsed);

extern "C" DLL_EXPORT void finishGame();

#endif //HFNUCGPENGINEAPIINCPP_EXPORT_H
