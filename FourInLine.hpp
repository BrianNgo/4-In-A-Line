#ifndef FOUR_IN_LINE_HPP
#define FOUR_IN_LINE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <climits>

class FourInLine {
public:
  explicit FourInLine(int xThinkTime, int xNumberOfPlies);
    ~FourInLine();
    int evaluateTheCurrentBoard();
    int calculateMin(int xDepth, int xAlpha, int xBeta);
    int calculateMax(int xDepth, int xAlpha, int xBeta);
    int getRowNumber(char xRow);
    int getColumnNumber(char xColumn);
    void computerMove();
    bool isPlayerMoveValid(std::string xMove);
    bool playerMove(std::string xMove);
    int checkForWinner();
    std::string currentStateOfTheBoard();

    static const int SIZE_OF_THE_BOARD = 8;
private:
    char **mBoard;
    int mNumberOfPlies;
    time_t mStartTime;
    time_t mCurrentTime;
    int mThinkTime;
};

#endif
