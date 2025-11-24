#include <stdio.h>
#include <math.h>

  typedef struct{
    double x;
    double y;
  }point;


double slope(point A, point B){
  if (A.x == B.x){
    return NAN;
  }
  else{
    double m = (B.y - A.y)/(B.x - A.x);
    return m;
  }
}

double distance(point A, point B){

  double d = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));

  return d;

}

point mid_Point(point A, point B){
  point  C;
  double x = (A.x + B.x)/2;
  double y = (A.y + B.y)/2;
  

  C.x = x;
  C.y = y;

  return C;
}

int main(){
  point A;
  point B;
  char  operation_Choice;
  
  printf("__point A__\nEnter x: ");
  scanf("%lf", &A.x); 
  printf("Enter y: ");
  scanf("%lf", &A.y); 

  printf("\n__point B__\nEnter x: ");
  scanf("%lf", &B.x); 
  printf("Enter y: ");
  scanf("%lf", &B.y); 
  
  printf("What operation? (M)idpoint, (D)istance, (S)lope, (E)xit: ");
  scanf(" %c", &operation_Choice);

  switch (operation_Choice){
    case 'M':
      point C = mid_Point(A, B);
      printf("the mid point is (%.2lf, %.2lf)\n", C.x, C.y);
      break;
    case 'D':
      double d = distance(A, B);
      printf("the distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf\n", A.x, A.y, B.x, B.y, d);
      break;
    case 'S':
      double m = slope(A, B);
      printf("the slope of the line is %.2lf\n", m);
      break;
    default:
      printf("not an option");
      return 1;
  }

  return 0;
}

