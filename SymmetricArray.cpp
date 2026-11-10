#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class symmetricArr
{
	int* _shortendArr;
	unsigned _shortendArrSize;

	unsigned _n;

public:


	// Consrtuctors and Destructor

	symmetricArr(unsigned n) // Rows = Columns
	{
		_n = n;
		_shortendArrSize = (n * n + n) / 2; // Upper triangular in any square matrix = (1/2)(columns * rows + rows)
		_shortendArr = new int[_shortendArrSize];
	}

	// Copy Constructor
	symmetricArr(const symmetricArr& other)
	{
		_shortendArrSize = other._shortendArrSize;

		_shortendArr = new int[_shortendArrSize];
		for (int i = 0; i < _shortendArrSize; ++i)
			_shortendArr[i] = other._shortendArr[i];

		_n = other._n;
	}

	// Copy Assignment Operator
	symmetricArr& operator=(const symmetricArr& other)
	{
		if (this == &other) return *this;

		delete[] _shortendArr;

		_n = other._n;
		_shortendArrSize = other._shortendArrSize;
		_shortendArr = new int[_shortendArrSize];

		for (unsigned i = 0; i < _shortendArrSize; ++i)
			_shortendArr[i] = other._shortendArr[i];

		return *this;
	}

	~symmetricArr() { delete[] _shortendArr; }


	// Setters and Getters

	// Methods

	void initialize(int** arr, unsigned n)
	{
		unsigned index = 0;

		for (int i = 0; i < _n; ++i)
			for (int j = i; j < _n; ++j)
				_shortendArr[index++] = arr[i][j];
	}

	void initialize(const vector<vector<int>>& arr)
	{
		if (arr.size() != _n || arr[0].size() != _n) throw invalid_argument("You can't fill the array with more or less than initial n(" + to_string(_n) + ")");

		unsigned index = 0;

		for (int i = 0; i < _n; ++i)
			for (int j = i; j < _n; ++j)
				_shortendArr[index++] = arr[i][j];
	}

	unsigned indexInShortendArr(unsigned index1, unsigned index2) const
	{
		if (index1 >= _n || index2 >= _n) throw out_of_range("Index out of bounds! Max size is: " + to_string(_n));

		unsigned index;

		if (index1 <= index2) index = (index1 * _n) + (index2) - ((index1 * (index1 + 1)) / 2);

		else                  index = (index2 * _n) + (index1) - ((index2 * (index2 + 1)) / 2);

		return index;
	}

	void set(unsigned index1, unsigned index2, int val) { _shortendArr[indexInShortendArr(index1, index2)] = val; }

	int get(unsigned index1, unsigned index2) const { return _shortendArr[indexInShortendArr(index1, index2)]; }

	void display() const
	{
		for (int i = 0; i < _n; ++i)
		{
			// The openning arrow
			cout << (i == 0 ? "┌ " : (i == _n - 1 ? "└ " : "│ "));

			// Row elements
			for (int j = 0; j < _n; ++j) cout << setw(4) << get(i, j) << " ";

			// The ending arrow
			cout << (i == 0 ? " ┐" : (i == _n - 1 ? " ┘" : " │")) << "\n";
		}
	}
};

int main()
{
	// Array row and column length (square array)
	const unsigned n = 3;

	symmetricArr symm(n);

	// Initilize with 2d Array

	int* arr[n];
	int row1[] = { 7, 2, 3 };
	int row2[] = { 2, 8, 4 };
	int row3[] = { 3, 4, 9 };

	arr[0] = row1;
	arr[1] = row2;
	arr[2] = row3;

	int** arrP = arr;

	symm.initialize(arrP, 3);


	// ---------------------------------------------



	// Initialize with vector


	//vector<vector<int>> vec
	//{
	//	{ 7, 2, 3 },
	//	{ 2, 8, 4 },
	//	{ 3, 4, 9 }
	//};

	//symm.initialize(vec);

	// ---------------------------------------------



	// Set and Get Test


	//cout << symm.get(1, 0) << "  ";
	//cout << symm.get(0, 1) << "  ";

	//symm.set(1, 0, 99);
	//symm.set(0, 1, 99);

	//cout << symm.get(1, 0) << "  ";
	//cout << symm.get(0, 1) << "  ";


	// ---------------------------------------------



	// Display elements

	
	symm.display();

	// ---------------------------------------------
}
