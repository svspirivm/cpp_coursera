#include<iostream>
#include<vector>
#include <stdexcept>

using namespace std;

class Matrix {
public:
	Matrix() {
		rows = 0;
		columns = 0;
	}
	Matrix(int num_rows, int num_cols) {
		if (num_rows < 0 || num_cols < 0) throw out_of_range("Out of range");
		else {
			rows = num_rows;
			columns = num_cols;
			for (int i = 0; i < rows; ++i) {
				vector<int> tmp;
				mat.push_back(tmp);
				for (int j = 0; j < columns; j++) {
					mat[i].push_back(0);
				}
			}
		}
	}
	int GetNumRows() const {
		return this->rows;
	}
	int GetNumColumns() const {
		return this->columns;
	}
	void Reset(int new_rows, int new_columns) {
		if (new_rows < 0 || new_columns < 0) throw out_of_range("Out of range");
		else {
			rows = new_rows;
			columns = new_columns;
			mat.clear();
			for (int i = 0; i < rows; ++i) {
				vector<int> tmp;
				mat.push_back(tmp);
				for (int j = 0; j < columns; j++) {
					mat[i].push_back(0);
				}
			}
		}
	}
	int At(int r, int c) const {
		if (r < rows && c < columns && r >= 0 && c >= 0) return mat[r][c];
		else throw out_of_range("Out of range");
	}
	int& At(int r, int c) {
		if (r < rows && c < columns && r >= 0 && c >= 0) return mat.at(r).at(c);
		else throw out_of_range("Out of range");
	}
	bool operator== (const Matrix& matrix) const {
		if ((this->rows == 0 || this->columns == 0) && (matrix.rows == 0 || matrix.columns == 0)) return true;
		else if (this->rows == matrix.rows && this->columns == matrix.columns) {
			for (int i = 0; i < this->rows; ++i) {
				for (int j = 0; j < this->columns; ++j) {
					if (this->mat[i][j] != matrix.mat[i][j]) return false;
				}
			}
			return true;
		}
		else return false;
	}
	Matrix operator+ (const Matrix& matrix) const {
		if (this->rows == matrix.rows && this->columns == matrix.columns) {
			Matrix result(this->rows, this->columns);
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					result.mat[i][j] = this->mat[i][j] + matrix.mat[i][j];
				}
			}
			return result;
		}
		else if ((this->rows == 0 || this->columns == 0) && (matrix.rows == 0 || matrix.columns == 0)) {
			Matrix empty;
			return empty;
		}
		else throw invalid_argument("Invalid argument");
	}
	friend istream& operator>> (istream& stream, Matrix& matrix);
	friend ostream& operator<< (ostream& stream, const Matrix& matrix);
private:
	int rows;
	int columns;
	vector<vector<int>> mat;
};

istream& operator>>(istream& stream, Matrix& matrix) {
	stream >> matrix.rows;
	stream >> matrix.columns;
	for (int i = 0; i < matrix.rows; ++i) {
		vector<int> tmp;
		matrix.mat.push_back(tmp);
		for (int j = 0; j < matrix.columns; j++) {
			matrix.mat[i].push_back(0);
		}
	}
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.columns; ++j) {
			stream >> matrix.mat[i][j];
		}
	}
	return stream;
}

ostream& operator<< (ostream& stream, const Matrix& matrix) {
	stream << matrix.rows << " " << matrix.columns << "\n";
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.columns; ++j) {
			stream << matrix.mat[i][j];
			if (j != matrix.columns - 1) stream << " ";
		}
		stream << "\n";
	}
	return stream;
}


int main() {
	Matrix one;
	Matrix two;
	cin >> one;
	cin >> two;
	cout << one + two << endl;
	return 0;
}