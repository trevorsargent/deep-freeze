#include "stdio.h"
#include "math.h"

int main()
{
  double height;
  double distance;
  printf("Input the vertical distance in feet): ");
  scanf("%lf", &height);
  printf("Input the horizontal distance (in feet): ");
  scanf("%lf", &distance);

  printf("19 Deg: %lf\n", sqrt(distance * distance + height * height) * 0.26);
  printf("26 Deg: %lf\n", sqrt(distance * distance + height * height) * 0.32);
  printf("36 Deg: %lf\n", sqrt(distance * distance + height * height) * 0.47);
  printf("50 Deg: %lf\n", sqrt(distance * distance + height * height) * 0.65);
  printf("70 Deg: %lf\n", sqrt(distance * distance + height * height) * 1.15);
  printf("90 Deg: %lf\n", sqrt(distance * distance + height * height) * 1.63);
}
