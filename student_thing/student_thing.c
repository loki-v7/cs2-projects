#include <stdio.h>
#include <string.h>

struct student{
    char  name[50];
    int   grade;
    float gpa;
    char  busrider;
};

int main(){
    struct student s1 = {"oel", 12, 2.8, 'N'};

    struct student s2;
    strcpy(s2.name, "namor");
    s2.grade = 10;
    s2.gpa = 3.8;
    s2.busrider = 'N';

    struct student s3 = {.name = "okin", .grade = 10, .gpa = 4.0, .busrider = 'N'};

    printf("Name: %s\nGrade: %d \nGPA: %.1f \nBus Status: %c \n", s1.name, s1.grade, s1.gpa, s1.busrider);
    printf("Name: %s\nGrade: %d \nGPA: %.1f \nBus Status: %c \n", s2.name, s2.grade, s2.gpa, s2.busrider);
    printf("Name: %s\nGrade: %d \nGPA: %.1f \nBus Status: %c \n", s3.name, s3.grade, s3.gpa, s3.busrider);
    return 0;

}
