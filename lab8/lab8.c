#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Структура для представлення студента
typedef struct {
    char name[50];
    int birthYear;
    int course;
    float averageGrade;
} Student;
// Функція для порівняння за ім'ям (зростання)
int compareByNameAsc(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}
// Функція для порівняння за ім'ям (спадання)
int compareByNameDesc(const void* a, const void* b) {
    return strcmp(((Student*)b)->name, ((Student*)a)->name);
}
// Функція для порівняння за роком народження (зростання)
int compareByYearAsc(const void* a, const void* b) {
    return ((Student*)a)->birthYear - ((Student*)b)->birthYear;
}
// Функція для порівняння за роком народження (спадання)
int compareByYearDesc(const void* a, const void* b) {
    return ((Student*)b)->birthYear - ((Student*)a)->birthYear;
}
// Функція для порівняння за курсом (зростання)
int compareByCourseAsc(const void* a, const void* b) {
    return ((Student*)a)->course - ((Student*)b)->course;
}

// Функція для порівняння за курсом (спадання)
int compareByCourseDesc(const void* a, const void* b) {
    return ((Student*)b)->course - ((Student*)a)->course;
}
// Функція для порівняння за середнім балом (зростання)
int compareByGradeAsc(const void* a, const void* b) {
    if (((Student*)a)->averageGrade < ((Student*)b)->averageGrade) return -1;
    if (((Student*)a)->averageGrade > ((Student*)b)->averageGrade) return 1;
    return 0;
}
// Функція для порівняння за середнім балом (спадання)
int compareByGradeDesc(const void* a, const void* b) {
    if (((Student*)b)->averageGrade < ((Student*)a)->averageGrade) return -1;
    if (((Student*)b)->averageGrade > ((Student*)a)->averageGrade) return 1;
    return 0;
}
// Функція для виводу списку студентів
void printStudents(Student* students, int count) {
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Ім'я: %s, Рік народження: %d, Курс: %d, Середній бал: %.2f\n",
            students[i].name, students[i].birthYear, students[i].course, students[i].averageGrade);
    }
    printf("-------------------------------------------------\n");
}
int main() {
    int n = 3;
    Student students[3] = {
        {"Андрій", 2002, 3, 85.5},
        {"Олена", 2003, 2, 90.0},
        {"Ігор", 2001, 4, 78.0}
    };
    printf("Оригінальний список студентів:\n");
    printStudents(students, n);
    // Сортування за ім'ям (зростання)
    qsort(students, n, sizeof(Student), compareByNameAsc);
    printf("Список студентів, відсортований за ім'ям (зростання):\n");
    printStudents(students, n);
    // Сортування за ім'ям (спадання)
    qsort(students, n, sizeof(Student), compareByNameDesc);
    printf("Список студентів, відсортований за ім'ям (спадання):\n");
    printStudents(students, n);
    // Сортування за роком народження (зростання)
    qsort(students, n, sizeof(Student), compareByYearAsc);
    printf("Список студентів, відсортований за роком народження (зростання):\n");
    printStudents(students, n);
    // Сортування за роком народження (спадання)
    qsort(students, n, sizeof(Student), compareByYearDesc);
    printf("Список студентів, відсортований за роком народження (спадання):\n");
    printStudents(students, n);
    // Сортування за курсом (зростання)
    qsort(students, n, sizeof(Student), compareByCourseAsc);
    printf("Список студентів, відсортований за курсом (зростання):\n");
    printStudents(students, n);
    // Сортування за середнім балом (спадання)
    qsort(students, n, sizeof(Student), compareByGradeDesc);
    printf("Список студентів, відсортований за середнім балом (спадання):\n");
    printStudents(students, n);
    return 0;
}