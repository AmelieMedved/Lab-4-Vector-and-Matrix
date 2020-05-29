#pragma once
#include "_vector.h"
#include "_matrix.h"

template <class T>
Vector<T> operator*(Matrix<T>& matrix, Vector<T>& vector)
{
  if (vector.GetSize() == matrix.GetCols())
  {
    T* REST = new T[matrix.GetCols()];
    T** MATRIXT = matrix.GetMatrix();
    T* VECTORT = vector.GetVector();
    for (size_t i = 0; i < matrix.GetRows(); i++)
    {
      REST[i] = 0;
      for (size_t j = 0; j < matrix.GetCols(); j++)
        REST[i] = REST[i] + (MATRIXT[i][j] * VECTORT[j]);
    }
    Vector<T> res(matrix.GetRows(), REST);
    delete[] REST;
    return res;
  }
  else
    throw "matrix.cols != vector.rows";
};

template<class T>
Matrix<T> operator*(Vector<T>& vector, Matrix<T>& matrix)
{
  if (vector.GetSize() == matrix.GetCols() && matrix.GetRows() == 1)
  {
    size_t SIZET = vector.GetSize();
    T** REST = new T * [SIZET];
    for (size_t i = 0; i < SIZET; i++)
      REST[i] = new T[SIZET];

    for (size_t i = 0; i < SIZET; i++)
      for (size_t j = 0; j < SIZET; j++)
      {
        REST[i][j] = (matrix[0][j] * vector[i]);
      }
    Matrix<T> res(SIZET, SIZET, REST);

    for (size_t i = 0; i < SIZET; i++)
      delete[] REST[i];
    delete[] REST;
    return res;
  }
  else
    throw "vector.GetSize() != matrix.GetCols() OR matrix.GetRows() != 1";
}