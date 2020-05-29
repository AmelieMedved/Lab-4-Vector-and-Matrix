#pragma once
#include <iostream>

template<class M>
class Matrix
{
private:
  void MemOut(size_t _rows, size_t _cols);
  size_t rows;
  size_t cols;
  M** mtrx;
public:
  Matrix();
  Matrix(size_t _rows, size_t _cols);
  Matrix(size_t _rows, size_t _cols, M** _mtrx);
  Matrix(const Matrix<M>& obj);
  ~Matrix();
  M** GetMatrix();
  size_t GetRows();
  size_t GetCols();
  void SetMatrix(size_t _rows, size_t _cols);
  size_t FindAllPositionNumber(M value);//Вхождения указанного значения

  Matrix<M> operator=(const Matrix<M>& obj);
  bool operator ==(const Matrix<M>& obj);
  M*& operator [](const size_t index);
  Matrix<M> operator+(const Matrix<M>& obj);
  Matrix<M> operator-(const Matrix<M>& obj);
  Matrix<M> operator*(const Matrix<M>& obj);

  template<class M>
  friend std::ostream& operator<<(std::ostream& out, const Matrix<M>& obj);
  template<class M>
  friend std::istream& operator>>(std::istream& in, Matrix<M>& obj);
};

template<class M>
void Matrix<M>::MemOut(size_t _rows, size_t _cols)
{
  mtrx = new M * [_rows];
  for (size_t i = 0; i < _rows; i++)
    mtrx[i] = new M[_cols];
}

template<class M>
Matrix<M>::Matrix(size_t _rows, size_t _cols, M** _mtrx)
{
  MemOut(_rows, _cols);
  for (size_t i = 0; i < _rows; i++)
    for (size_t j = 0; j < _cols; j++)
      mtrx[i][j] = _mtrx[i][j];
  rows = _rows;
  cols = _cols;
}

template<class M>
Matrix<M>::Matrix()
{
  rows = 1;
  cols = 1;
  MemOut(rows, cols);
  mtrx[0][0] = 0;
}

template<class M>
Matrix<M>::Matrix(size_t _rows, size_t _cols)
{
  MemOut(_rows, _cols);
  for (size_t i = 0; i < _rows; i++)
  {
    for (size_t j = 0; j < _cols; j++)
    {
      mtrx[i][j] = 0;
    }
  }
  rows = _rows;
  cols = _cols;
}

template<class M>
Matrix<M>::Matrix(const Matrix<M>& obj)
{
  MemOut(obj.rows, obj.cols);
  for (size_t i = 0; i < obj.rows; i++)
  {
    for (size_t j = 0; j < obj.cols; j++)
    {
      mtrx[i][j] = obj.mtrx[i][j];
    }
  }
  rows = obj.rows;
  cols = obj.cols;
}

template<class M>
Matrix<M>::~Matrix()
{
  if (mtrx != nullptr)
  {
    for (size_t i = 0; i < rows; i++)
    {
      delete[] mtrx[i];
    }
    delete[] mtrx;
  }
  rows = 0;
  cols = 0;
}

template<class M>
size_t Matrix<M>::FindAllPositionNumber(M value)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      if (mtrx[i][j] == value)
      {
        count++;
      }
    }
  }
  return count;
}

template<class M>
size_t Matrix<M>::GetRows()
{
  return rows;
}

template<class M>
size_t Matrix<M>::GetCols()
{
  return cols;
}

template<class M>
M** Matrix<M>::GetMatrix()
{
  return mtrx;
}

template<class M>
void Matrix<M>::SetMatrix(size_t _rows, size_t _cols)//переписать значение полей в матрице уже созданной размерности
{
  if (mtrx != nullptr)
  {
    Matrix<M>temp(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        temp.mtrx[i][j] = mtrx[i][j];
    }
    for (size_t i = 0; i < rows; i++)
      delete[] mtrx[i];
    delete[]  mtrx;

    rows = _rows;
    cols = _cols;
    mtrx = new M * [rows];
    for (size_t i = 0; i < rows; i++)
      mtrx[i] = new M[cols];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        mtrx[i][j] = 0;
    }
    size_t ROWST = (temp.rows < rows) ? temp.rows : rows;
    size_t COLST = (temp.cols < cols) ? temp.cols : cols;
    for (size_t i = 0; i < ROWST; i++)
    {
      for (size_t j = 0; j < COLST; j++)
        mtrx[i][j] = temp.mtrx[i][j];
    }
  }
  else
  {
    rows = _rows;
    cols = _cols;
    mtrx = new M * [rows];
    for (size_t i = 0; i < rows; i++)
      mtrx[i] = new M[cols];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        mtrx[i][j] = 0;
    }
  }
}

template<class M>
Matrix<M> Matrix<M>::operator=(const Matrix<M>& obj)
{
  if (this != &obj)
  {
    for (size_t i = 0; i < rows; i++)
    {
      delete[] mtrx[i];
    }
    delete[] mtrx;

    rows = obj.rows;
    cols = obj.cols;
    MemOut(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
      {
        mtrx[i][j] = obj.mtrx[i][j];
      }
    }
  }
  return *this;
}

template<class M>
M*& Matrix<M>::operator [](const size_t index)
{
  return mtrx[index];
}

template<class M>
bool Matrix<M>::operator==(const Matrix<M>& obj)
{
  if (rows == obj.rows && cols == obj.cols)
  {
    for (size_t i = 0; i < rows; i++)
      for (size_t j = 0; j < cols; j++)
        if (mtrx[i][j] != obj.mtrx[i][j])
          return false;
    return true;
  }
  else
    return false;
}

template<class M>
Matrix<M> Matrix<M>::operator+(const Matrix<M>& obj)
{
  if (cols == obj.cols && rows == obj.rows)
  {
    Matrix<M> res(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        res.mtrx[i][j] = mtrx[i][j] + obj.mtrx[i][j];
    }
    return res;
  }
  else
    throw "this->rows!=obj.cols";
}

template<class M>
Matrix<M> Matrix<M>::operator-(const Matrix<M>& obj)
{
  if (cols == obj.cols && rows == obj.rows)
  {
    Matrix<M> res(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        res.mtrx[i][j] = mtrx[i][j] - obj.mtrx[i][j];
    }
    return res;
  }
  else
    throw "this->rows!=obj.cols";
}

template<class M>
Matrix<M> Matrix<M>::operator*(const Matrix<M>& obj)
{
  if (cols == obj.rows)
  {
    Matrix<M> res(rows, obj.cols);
    M sum;
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < obj.cols; j++)
      {
        sum = 0;
        for (size_t k = 0; k < obj.rows; k++)
        {
          sum = sum + mtrx[i][k] * obj.mtrx[k][j];
        }
        res[i][j] = sum;
      }
    }
    return res;
  }
  else
    throw "this->rows!=obj.cols";
}

template<class M>
std::ostream& operator<<(std::ostream& out, const Matrix<M>& obj)
{
  if (obj.cols != 0 && obj.rows != 0)
  {
    for (size_t i = 0; i < obj.cols; i++)
    {
      for (size_t j = 0; j < obj.rows; j++)
        out << obj.mtrx[i][j] << " ";
      out << std::endl;
    }
    return out;
  }
  else
    throw "obj.cols == 0 || obj.rows == 0";
}

template<class M>
std::istream& operator>>(std::istream& in, Matrix<M>& obj)
{
  if ((obj.rows == 0) || (obj.cols == 0))
  {
    obj.rows++;
    obj.cols++;
    obj.SetMatrix(obj.rows, obj.cols);
  }
  for (size_t i = 0; i < obj.cols; i++)
  {
    for (size_t j = 0; j < obj.rows; j++)
      in >> obj.mtrx[i][j];
  }
  return in;
}