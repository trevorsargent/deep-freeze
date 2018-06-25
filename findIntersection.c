#include <FPT.h>

void findEquation(double *A, double *B, double *C, double x1, double y1, double x2, double y2, int i)
{

  A[i] = (y1 - y2);
  B[i] = (x2 - x1);
  C[i] = (x1 * y2 - x2 * y1);
}

double intersect(double ax1, double ay1, double ax2, double ay2, double bx1, double by1, double bx2, double by2)
{

  double A[2], B[2], C[2], det;

  findEquation(A, B, C, -ax1, -ay1, -ax2, -ay2, 0);
  findEquation(A, B, C, -bx1, -by1, -bx2, -by2, 1);

  det = A[0] * B[1] - A[1] * B[0];

  printf(" x: %lf \n", (B[1] * C[0] - B[0] * C[1]) / det);
  printf(" y: %lf \n", (A[0] * C[1] - A[1] * C[0]) / det);
}

int main()
{

  double x[8];

  int i = 0;

  cout << "enter the points for one line, and then the other (order: x, y, x, y), enter after each coordinate\n\n";
  for (i = 0; i < 8; i++)
  {
    cin >> x[i];
  }
  intersect(x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7]);
}
