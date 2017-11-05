#include <iostream>
#include <ctime>
#include <cstdlib>

#include "matrix.h"

using namespace std;

void Matrix::Create() {
	mat = new double*[row];
	for (int i = 0; i < row; i++) 
		mat[i] = new double[col];
}

Matrix::Matrix(int row, int col) {
	this->row = row;
	this->col = col;
	Create();

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mat[i][j] = 0;
}

Matrix::Matrix(int n, double value) {
	this->row = n;
	this->col = n;
	Create();

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			mat[i][j] = (i==j) * value;
}

void Matrix::GetRND(double a, double b) {
	int w = (b - a + 1) * 10;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mat[i][j] = a + (rand() % w) / 10.0;
}

int Matrix::Row() const {
	return row;
}

int Matrix::Col() const {
	return col;
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++)
		delete[] mat[i];
	delete[] mat;
}

ostream& operator<<(ostream& output, const Matrix &mat){
	output << endl;
	for (int i = 0; i < mat.Row(); i++) {
		for (int j = 0; j < mat.Col(); j++)
			output << mat.mat[i][j] << "\t";
		output << endl;
	}
	return output;
}

istream& operator >>(istream &input, const Matrix &mat){
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cout << "Enter mat[" << i << "][" << j << "]: ";
			input >> mat[i][j];
	}
	return input;
}