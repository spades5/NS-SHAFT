#include <stdio.h>
#include <string.h>

typedef struct {
    int year, month, day;
} DateData;

typedef struct {
    int seatNo;
    char name[20];
    DateData birthdate;
} StudentInfo;

const char* monthName(int month) {
    char *months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

int main() {
    int num,lower, upper, i, current;
    printf("How many students? ");
    scanf("%d", &num); if (getchar() == '\r') getchar();

    StudentInfo students[num];

    for (i = 0; i < num; i++) {
        printf("student[%d].seatNo: ", i);
        scanf("%d", &students[i].seatNo);if (getchar() == '\r') getchar();

        printf("student[%d].name: ", i);
        scanf("%s", students[i].name);if (getchar() == '\r') getchar();

        printf("student[%d].birthdate: ", i);
        scanf("%d/%d/%d", &students[i].birthdate.year, &students[i].birthdate.month, &students[i].birthdate.day);if (getchar() == '\r') getchar();
    }

    printf("Lower range: ");
    scanf("%d", &lower);if (getchar() == '\r') getchar();
    printf("Upper range: ");
    scanf("%d", &upper);if (getchar() == '\r') getchar();

    current = lower;

    for (i = current; i <= upper; i++) {
        if (students[i].birthdate.year > students[current].birthdate.year) {
            current = i;
        }
        else if (students[i].birthdate.year == students[current].birthdate.year) {
            if (students[i].birthdate.month > students[current].birthdate.month) {
                current = i;
            }
            else if (students[i].birthdate.month == students[current].birthdate.month) {
                if (students[i].birthdate.day > students[current].birthdate.day) {
                    current = i;
                }
            }
        }
    }

     printf("The youngest student from student[%d] to student[%d] is:\n%s, No. %d, whose birthday is %s %d.\n",lower, upper, students[current].name, students[current].seatNo,monthName(students[current].birthdate.month), students[current].birthdate.day);
    return 0;
}
