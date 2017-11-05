#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
	int row;
	int col;
	double **mat;

	void Create();
	int Row() const;
	int Col() const;
public:
	Matrix(int row, int col);
	Matrix(int n, double value = 0);

	void GetRND(double a, double b);

	bool isDiag() const;
	bool isNull() const;
	bool isE() const;
	bool isSim() const;
	bool isUpTringle() const;
	bool isDownTriangle() const;

	Matrix& operator=(const Matrix &mat);
	bool operator==(const Matrix &mat) const;
	bool operator!=(const Matrix &mat) const;

	Matrix operator-() const;
	Matrix operator-(const Matrix &mat) const;
	Matrix operator-=(const Matrix &mat);

	Matrix operator+(const Matrix &mat) const;
	Matrix operator+=(const Matrix &mat);

	Matrix operator*(const Matrix &mat) const;
	Matrix operator*(double value) const;
	Matrix operator*=(const Matrix &mat);
	Matrix operator*=(double value);

	Matrix operator/(const Matrix &mat) const;
	Matrix operator/(double value) const;
	Matrix operator/=(const Matrix &mat);

	Matrix operator^(const Matrix &mat) const;

	Matrix Inverse() const;
	Matrix Transp() const;

	double Det() const;

	friend std::ostream& operator<<(std::ostream& output, const Matrix &mat);
	friend std::istream& operator>>(std::istream& input, Matrix &mat);

	~Matrix();
};

std::ostream& operator<<(std::ostream& output, const Matrix &mat);
std::istream& operator >>(std::istream& input, Matrix &mat);

#endif