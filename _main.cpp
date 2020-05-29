#include "_vector_matrix.h"
#include <chrono>
#include <iomanip>

int main()
{

  srand((size_t)time(NULL));

  int* _arrvec;
  size_t size = 10;

  _arrvec = new int[size];
  for (size_t i = 0; i < size; i++)
    _arrvec[i] = rand() % 10;

  size_t rows = 1;
  size_t cols = 10;

  int** _arrmat = new int* [rows];
  for (size_t i = 0; i < rows; i++)
    _arrmat[i] = new int[cols];

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
      _arrmat[i][j] = rand() % 10;
  }

  Vector<int> VectorA(10, _arrvec);
  Matrix<int> MatrixB(1, 10, _arrmat);

  Vector<int> VectorC;
  VectorC = MatrixB * VectorA;
  std::cout << VectorC << std::endl;
  Matrix<int> MatrixD;
  MatrixD = VectorA * MatrixB;
  std::cout << MatrixD << std::endl;

  Vector<double> _Vector;
  Vector<double> log0;
  Vector<int> log1(10, _arrvec);

  std::cout << log1 << std::endl;

  std::cout << log0.FindAllPositionNumber(0) << std::endl;

  log1.FindAllPosition(1);

  _Vector.SetVector(10);

  Vector<double> Vector96;

  Vector<double> VectorDouble;

  Vector96 = _Vector;

  VectorDouble = (_Vector / Vector96);

  VectorDouble.BubbleSort();
  Vector96.InsertionSort();
  _Vector.QuickSort(0, (_Vector.GetSize() - 1));

  std::cout << VectorDouble.FindAllPositionNumber(0) << std::endl;

  Matrix<int> Vector;
  Vector.SetMatrix(1, 3);

  std::cout << Vector.GetRows() << " " << Vector.GetCols() << std::endl;

  Matrix<int> mat0(13, 13);


  mat0 = Vector;

  if (mat0 == Vector)
    std::cout << mat0.GetRows() << " " << mat0.GetCols() << std::endl;

  mat0.SetMatrix(3, 1);

  Matrix<int> mat1;
  mat1 = Vector * mat0;
  std::cout << mat1.GetRows() << " " << mat1.GetCols() << std::endl;

  for (size_t i = 0; i < mat1.GetRows(); i++)
  {
    for (size_t j = 0; j < mat1.GetCols(); j++)
    {
      std::cout << mat1.GetMatrix()[i][j] << std::endl;
    }
  }

  //std::cout << "===TEST===Matrix + Matrix===TEST===" << std::endl;

  //size_t rows = 3200;
  //size_t cols = 3200;

  //int** _arrmat0 = new int* [rows];
  //for (size_t i = 0; i < rows; i++)
  //  _arrmat0[i] = new int[cols];

  //for (size_t i = 0; i < rows; i++)
  //{
  //  for (size_t j = 0; j < cols; j++)
  //    _arrmat0[i][j] = rand() % 10;
  //}

  //int** _arrmat1 = new int* [rows];
  //for (size_t i = 0; i < rows; i++)
  //  _arrmat1[i] = new int[cols];

  //for (size_t i = 0; i < rows; i++)
  //{
  //  for (size_t j = 0; j < cols; j++)
  //    _arrmat1[i][j] = rand() % 10;
  //}

  //Matrix<int> MatTime0(3200, 3200, _arrmat0);
  //Matrix<int> MatTime1(3200, 3200, _arrmat1);

  class Timer
  {
  private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

  public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
      m_beg = clock_t::now();
    }

    double elapsed() const
    {
      return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
  };

  //Timer t1;
  //clock_t T1 = clock() / CLOCKS_PER_SEC;
  //MatTime0 + MatTime1;
  //clock_t T2 = clock() / CLOCKS_PER_SEC;
  //std::cout << T2 - T1 << std::endl;
  //std::cout << t1.elapsed() << std::endl;

  /*std::cout << "===TEST===Matrix * Matrix===TEST===" << std::endl;

  rows = 3200;
  cols = 3200;

  int** _arrmat0 = new int* [rows];
  for (size_t i = 0; i < rows; i++)
    _arrmat0[i] = new int[cols];

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
      _arrmat0[i][j] = rand() % 10;
  }

  int** _arrmat1 = new int* [cols];
  for (size_t i = 0; i < cols; i++)
    _arrmat1[i] = new int[rows];

  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
      _arrmat1[i][j] = rand() % 10;
  }

  Matrix<int> MatTime0(3200, 3200, _arrmat0);
  Matrix<int> MatTime1(3200, 3200, _arrmat1);

  clock_t T1 = clock()/ CLOCKS_PER_SEC;
  Timer t2;
  MatTime0* MatTime1;
  clock_t T2 = clock()/ CLOCKS_PER_SEC;
 
  std::cout << T2 - T1 << std::endl;
  std::cout << t2.elapsed() << std::endl;*/

  //std::cout << "===TEST===Matrix * Vector===TEST===" << std::endl;

  //rows = 1;
  //cols = 40000;
   size = 40000;
 
  //int** _arrmat0 = new int* [rows];
  //for (size_t i = 0; i < rows; i++)
  //  _arrmat0[i] = new int[cols];

  //for (size_t i = 0; i < rows; i++)
  //{
  //  for (size_t j = 0; j < cols; j++)
  //    _arrmat0[i][j] = rand() % 10;
  //}

  //int * _arrvec0 = new int[size];
  //for (size_t i = 0; i < size; i++)
  //  _arrvec0[i] = rand() % 10;

  //Matrix<int> MV0(1, 40000, _arrmat0);
  //Vector<int> MV1(40000, _arrvec0);

  //Timer MVT;
  //MV0 * MV1;
  //std::cout << MVT.elapsed() << std::endl;

  /*std::cout << "===TEST===Bubble-Sort===TEST===" << std::endl;

   size = 500000;

  int * _arrvec0 = new int[size];
  for (size_t i = 0; i < size; i++)
  _arrvec0[i] = rand() % 10;

  Vector<int> SortVector(size, _arrvec0);

  Timer L;
  SortVector.QuickSort(0, size-1);
  std::cout << L.elapsed() << std::endl;*/

  return 0;
}