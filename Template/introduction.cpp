#include <iostream>

template<typename T> class Matrix
{
public:
    Matrix(int row, int col)
    {
        _rows = row;
        _cols = col;
        
        m = new T*[_rows];
        for (int i = 0; i < _rows; i++)
        {
            m[i] = new T[_cols];
            for(int j=0; j < _cols; j++)
            {
                m[i][j] = i*_rows + j;
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < _rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
    }

    T **m;
    int _rows;
    int _cols;
};

int main(int argc, char* argv[])
{
    Matrix<int> a(3,4);

    for(int i=0; i<a._rows; i++)
    {
        for(int j=0; j<a._cols; j++)
        {
            std::cout << "[" << i << "][" << j << "]: " << a.m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}