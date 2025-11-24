#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30
#define NAME_LENGTH 50

typedef struct {
  char  student_Name[100];
  int   id;
  int   grade_Level;
  float gpa;
  char  bus_Status;

} Student;

Student students[MAX_STUDENTS];
int student_amount = 0;

int add_student(char *name, int grade, float gpa, char status) {

  if (student_amount >= MAX_STUDENTS) {
    printf("error: Max amount of students have been reached\n");
    return 0;
  }

  strncpy(students[student_amount].student_Name, name, NAME_LENGTH - 1);
  students[student_amount].id = student_amount + 1;
  students[student_amount].grade_Level = grade;
  students[student_amount].gpa = gpa;
  students[student_amount].bus_Status = status;

  student_amount += 1;
  printf("success: added student\n");
  return 1;

}


int remove_student(int id) {

  for (int i = 0; i < student_amount; i++) {
    if(i == id) {
      for (int j = i; j < student_amount - 1; j++) {
        students[j] = students[j + 1];
      }
      student_amount -= 1; 
      printf("success: student removed");
      return 1;
    }
  }
  printf("error: could not find student");
  return 0;
}

int display_student(int id) {

  for (int i = 0; i < student_amount; i++) {
    if (i == id) {
      printf("Name: %s\nGrade: %d\nGPA: %.1f\nBus Status: %c\n", students[i].student_Name, students[i].grade_Level, students[i].gpa, students[i].bus_Status);
      return 1;
    }
  }
  printf("error: student not found");
  return 0;
}

int main(){
  char user_Input;
  add_student("jett castle", 12, 4.0, 'N');
  add_student("john gray", 12, 3.0, 'Y');
  add_student("lindze parker", 12, 4.0, 'N');

  while (1){
    printf("\n==========Teacher easy==========\n");
    printf("What would you like to do?\n");
    printf("(A)dd a student?\n");
    printf("(R)emove a student?\n");
    printf("(D)isplay a student?\n");
    printf("(E)xit from program?\n");
    printf(": ");
    scanf(" %c", &user_Input);
    getchar();

    if (user_Input == 'A') {
      char  name[NAME_LENGTH];
      int   grade;
      float gpa;
      char  status;


      printf("\nName: ");

      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = '\0';

      printf("Grade: ");
      scanf("%d", &grade);

      printf("GPA: ");
      scanf("%f", &gpa);

      printf("Bus Status: ");
      scanf(" %c", &status);
      getchar();

      add_student(name, grade, gpa, status);

    }

    else if (user_Input == 'R') {
      int id;

      printf("ID: ");
      scanf("%d", &id);
      getchar();

      remove_student(id);
    }

    else if (user_Input == 'D') {
      int id;

      printf("ID: ");
      scanf("%d", &id);
      getchar();

      display_student(id);
    }

    else if (user_Input == 'E') {
      break;
    }

    else {
      printf("error: not an option\n");
    }

  }
  return 0;


}
