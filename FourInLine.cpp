#include "FourInLine.hpp"

FourInLine::FourInLine(int xThinkTime, int xNumberOfPlies)
    : mNumberOfPlies(xNumberOfPlies),
      mThinkTime(xThinkTime) {
    time(&mStartTime);
    time(&mCurrentTime);
    mBoard = new char*[SIZE_OF_THE_BOARD];
    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii)
	mBoard[ii] = new char[SIZE_OF_THE_BOARD];

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj)
	    mBoard[ii][jj] = '-';
    }
}

FourInLine::~FourInLine() {
    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii)
	delete[] mBoard[ii];
    delete mBoard;
}

int FourInLine::evaluateTheCurrentBoard() {
    int calculatedResult = 0;

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD - 2; ++jj) {
	    if (jj < SIZE_OF_THE_BOARD - 3) {
		if (mBoard[ii][jj] == 'O'
		    && mBoard[ii][jj + 1] == 'O'
		    && mBoard[ii][jj + 2] == 'O') {
		    if ((jj == 0 && mBoard[ii][jj + 3] == 'X')
			|| (jj + 3 == 7 && mBoard[ii][jj] == 'X')
			|| (jj >= 2 && (mBoard[ii][jj - 1] == 'X'
					&& mBoard[ii][jj + 3] == 'X')))
			calculatedResult = 2500;
		}
	    }

	    if (mBoard[ii][jj] == 'O'
		&& mBoard[ii][jj + 1] == 'O') {
		if ((jj == 0 && mBoard[ii][jj + 2] == 'X')
		    || (jj + 2 == 7 && mBoard[ii][jj] == 'X')
		    || (jj >= 1 && (mBoard[ii][jj - 1] == 'X'
				    || mBoard[ii][jj + 2] == 'X')))
		    calculatedResult = 50;
	    }
	}
    }

    for (int ii = 0; ii < SIZE_OF_THE_BOARD - 3; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (ii < SIZE_OF_THE_BOARD - 3) {
		if (mBoard[ii][jj] == 'O'
		    && mBoard[ii + 1][jj] == 'O'
		    && mBoard[ii + 2][jj] == 'O') {
		    if ((ii == 0 && mBoard[ii + 3][jj] == 'X')
			|| (ii + 3 == 7 && mBoard[ii][jj] == 'X')
			|| (ii >= 2 && (mBoard[ii - 1][jj] == 'X'
					&& mBoard[ii + 3][jj] == 'X')))
			calculatedResult = 250;
		}
	    }

	    if (mBoard[ii][jj] == 'O'
		&& mBoard[ii + 1][jj] == 'O') {
		if ((ii == 0 && mBoard[ii + 2][jj] == 'X')
		    || (ii + 2 == 7 && mBoard[ii][jj] == 'X')
		    || (ii >= 1 && (mBoard[ii - 1][jj] == 'X'
				    || mBoard[ii + 2][jj] == 'X')))
		    calculatedResult = 50;
	    }
	}
    }

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (mBoard[ii][jj] == 'O') {
		if ((ii == 0 && jj == 0
		    && (mBoard[1][0] == 'X' || mBoard[0][1] == 'X'))
		    || (ii == 0 && jj == 7
		    && (mBoard[1][7] == 'X' || mBoard[0][6] == 'X'))
		    || (ii == 7 && jj == 0
		    && (mBoard[6][0] == 'X' || mBoard[7][1] == 'X'))
		    || (ii == 7 && jj == 7
		    && (mBoard[6][7] == 'X' || mBoard[7][6] == 'X'))
		    || (ii == 0 && jj >= 1 && jj <= 6
		    && (mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'))
		    || (ii == 7 && jj >= 1 && jj <= 6
		    && (mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'))
		    || (jj == 0 && ii >= 1 && ii <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'))
		    || (jj == 7 && ii >= 1 && ii <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'))
		    || (ii >= 1 && ii <= 6 && jj >= 1 && jj <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X')))
		    calculatedResult = 50;
	    }
	}
    }

    if (mBoard[3][3] == 'X'
	|| mBoard[3][4] == 'X'
	|| mBoard[4][3] == 'X'
	|| mBoard[4][4] == 'X')
	calculatedResult = 100;

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (mBoard[ii][jj] == 'X') {
		if ((ii == 0 && jj == 0
		    && (mBoard[1][0] == 'X' || mBoard[0][1] == 'X'))
		    || (ii == 0 && jj == 7
		    && (mBoard[1][7] == 'X' || mBoard[0][6] == 'X'))
		    || (ii == 7 && jj == 0
		    && (mBoard[6][0] == 'X' || mBoard[7][1] == 'X'))
		    || (ii == 7 && jj == 7
		    && (mBoard[6][7] == 'X' || mBoard[7][6] == 'X'))
		    || (ii == 0 && jj >= 1 && jj <= 6
		    && (mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'))
		    || (ii == 7 && jj >= 1 && jj <= 6
		    && (mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'))
		    || (jj == 0 && ii >= 1 && ii <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'))
		    || (jj == 7 && ii >= 1 && ii <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'))
		    || (ii >= 1 && ii <= 6 && jj >= 1 && jj <= 6
		    && (mBoard[ii - 1][jj] == 'X'
			|| mBoard[ii][jj - 1] == 'X'
			|| mBoard[ii + 1][jj] == 'X'
			|| mBoard[ii][jj + 1] == 'X')))
		    calculatedResult = 50;
	    }
	}
    }
    return calculatedResult;
}

int FourInLine::calculateMin(int xDepth, int xAlpha, int xBeta) {
    int bestCase = INT_MAX;
    if ((int)difftime(time(&mCurrentTime), mStartTime) < mThinkTime) {
	if (checkForWinner() != 0)
	    return checkForWinner();
	if (xDepth == 0)
	    return evaluateTheCurrentBoard();
	for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	    for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
		if (mBoard[ii][jj] == '-') {
		    mBoard[ii][jj] = 'O';
		    bestCase = std::min(bestCase,
					      calculateMax(xDepth - 1, xAlpha, xBeta));
		    if (bestCase <= xAlpha) {
			mBoard[ii][jj] = '-';
			return bestCase;
		    }

		    xBeta = std::min(xBeta, bestCase);
		    mBoard[ii][jj] = '-';
		}
	    }
	}
    }
    return bestCase;
}

int FourInLine::calculateMax(int xDepth, int xAlpha, int xBeta) {
    int bestCase = INT_MIN;
    if ((int)difftime(time(&mCurrentTime), mStartTime) < mThinkTime) {
	if (checkForWinner() != 0)
	    return checkForWinner();
	if (xDepth == 0)
	  return evaluateTheCurrentBoard();
	for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	    for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
		if (mBoard[ii][jj] == '-') {
		    mBoard[ii][jj] = 'X';
		    bestCase = std::max(bestCase,
					calculateMin(xDepth - 1, xAlpha, xBeta));

		    if (bestCase >= xBeta) {
			mBoard[ii][jj] = '-';
			return bestCase;
		    }

		    xAlpha = std::max(xAlpha, bestCase);
		    mBoard[ii][jj] = '-';
		}
	    }
	}
    }
    return bestCase;
}

int FourInLine::getRowNumber(char xRow) {
    if (xRow == 'A' || xRow == 'a')
	return 0;
    if (xRow == 'B' || xRow == 'b')
	return 1;
    if (xRow == 'C' || xRow == 'c')
	return 2;
    if (xRow == 'D' || xRow == 'd')
	return 3;
    if (xRow == 'E' || xRow == 'e')
	return 4;
    if (xRow == 'F' || xRow == 'f')
	return 5;
    if (xRow == 'G' || xRow == 'g')
	return 6;
    if (xRow == 'H' || xRow == 'h')
	return 7;
    return -1;
}

int FourInLine::getColumnNumber(char xColumn) {
    if (xColumn == '1')
	return 0;
    if (xColumn == '2')
	return 1;
    if (xColumn == '3')
	return 2;
    if (xColumn == '4')
	return 3;
    if (xColumn == '5')
	return 4;
    if (xColumn == '6')
	return 5;
    if (xColumn == '7')
	return 6;
    if (xColumn == '8')
	return 7;
    return -1;
}

void FourInLine::computerMove() {
    int bestCase = INT_MIN,
	score = 0,
	depth = mNumberOfPlies,
	currentX = 0,
	currentY = 0;

    time(&mStartTime);
    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (mBoard[ii][jj] == '-') {
		mBoard[ii][jj] = 'X';
		score = calculateMin(depth - 1, INT_MIN, INT_MAX);

		if (score > bestCase) {
		    currentX = ii;
		    currentY = jj;
		    bestCase = score;
		}
		mBoard[ii][jj] = '-';
		if ((int)difftime(time(&mCurrentTime), mStartTime) >= mThinkTime)
		    break;

	    }
	}
    }
    std::cout << "\nMy move is: "
	      << (char) ('A' + currentX) << "" << (currentY + 1);
    mBoard[currentX][currentY] = 'X';
}

bool FourInLine::isPlayerMoveValid(std::string xMove) {
    if (xMove.length() < 2)
	return false;
    int row = getRowNumber(xMove[0]);
    if (row < 0)
	return false;
    int column = getColumnNumber(xMove[1]);
    if (column < 0)
	return false;
    if (mBoard[row][column] != '-')
	return false;
    mBoard[row][column] = 'O';
    return true;
}

bool FourInLine::playerMove(std::string xMove) {
    if (!isPlayerMoveValid(xMove)) {
	std::cout << "\nInvalid move!";
	return false;
    }
    return true;
}

int FourInLine::checkForWinner() {
    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD - 4; ++jj) {
	    if (mBoard[ii][jj] == 'O'
		&& mBoard[ii][jj + 1] == 'O'
		&& mBoard[ii][jj + 2] == 'O'
		&& mBoard[ii][jj + 3] == 'O')
		return -5000;

	    if (mBoard[ii][jj] == 'X'
		&& mBoard[ii][jj + 1] == 'X'
		&& mBoard[ii][jj + 2] == 'X'
		&& mBoard[ii][jj + 3] == 'X')
		return 5000;
	}
    }

    for (int ii = 0; ii < SIZE_OF_THE_BOARD - 4; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (mBoard[ii][jj] == 'O'
		&& mBoard[ii + 1][jj] == 'O'
		&& mBoard[ii + 2][jj] == 'O'
		&& mBoard[ii + 3][jj] == 'O')
		return -5000;

	    if (mBoard[ii][jj] == 'X'
		&& mBoard[ii + 1][jj] == 'X'
		&& mBoard[ii + 2][jj] == 'X'
		&& mBoard[ii + 3][jj] == 'X')
		return 5000;
	}
    }

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    if (mBoard[ii][jj] == '-')
		return 0;
	}
    }
    std::cout << "\n" << currentStateOfTheBoard();
    return 1;
}

std::string FourInLine::currentStateOfTheBoard() {
    std::string row = "\n  1 2 3 4 5 6 7 8\n";
    std::string col[] = {"A", "B", "C", "D", "E", "F", "G", "H"};

    for (int ii = 0; ii < SIZE_OF_THE_BOARD; ++ii) {
    	row += col[ii];
	for (int jj = 0; jj < SIZE_OF_THE_BOARD; ++jj) {
	    row += " ";
	    row += mBoard[ii][jj];
	}
	row += "\n";
    }
    row += "\n";
    return row;
}
