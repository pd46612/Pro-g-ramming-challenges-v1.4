#pragma once
class N_queens
{
private:
	short axeSize;
	short placedQueens;
	short* board;

	void initialize();
	bool isSizeTooBig();
	bool solve(short col);
	bool isSafeToPlace(size_t row, size_t col);
	void display();

public:
	N_queens(short size);
	~N_queens();
};

