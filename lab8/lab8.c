#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ��������� ��� ������������� ��������
typedef struct {
    char name[50];
    int birthYear;
    int course;
    float averageGrade;
} Student;
// ������� ��� ��������� �� ��'�� (���������)
int compareByNameAsc(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}
// ������� ��� ��������� �� ��'�� (��������)
int compareByNameDesc(const void* a, const void* b) {
    return strcmp(((Student*)b)->name, ((Student*)a)->name);
}
// ������� ��� ��������� �� ����� ���������� (���������)
int compareByYearAsc(const void* a, const void* b) {
    return ((Student*)a)->birthYear - ((Student*)b)->birthYear;
}
// ������� ��� ��������� �� ����� ���������� (��������)
int compareByYearDesc(const void* a, const void* b) {
    return ((Student*)b)->birthYear - ((Student*)a)->birthYear;
}
// ������� ��� ��������� �� ������ (���������)
int compareByCourseAsc(const void* a, const void* b) {
    return ((Student*)a)->course - ((Student*)b)->course;
}

// ������� ��� ��������� �� ������ (��������)
int compareByCourseDesc(const void* a, const void* b) {
    return ((Student*)b)->course - ((Student*)a)->course;
}
// ������� ��� ��������� �� ������� ����� (���������)
int compareByGradeAsc(const void* a, const void* b) {
    if (((Student*)a)->averageGrade < ((Student*)b)->averageGrade) return -1;
    if (((Student*)a)->averageGrade > ((Student*)b)->averageGrade) return 1;
    return 0;
}
// ������� ��� ��������� �� ������� ����� (��������)
int compareByGradeDesc(const void* a, const void* b) {
    if (((Student*)b)->averageGrade < ((Student*)a)->averageGrade) return -1;
    if (((Student*)b)->averageGrade > ((Student*)a)->averageGrade) return 1;
    return 0;
}
// ������� ��� ������ ������ ��������
void printStudents(Student* students, int count) {
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("��'�: %s, г� ����������: %d, ����: %d, ������� ���: %.2f\n",
            students[i].name, students[i].birthYear, students[i].course, students[i].averageGrade);
    }
    printf("-------------------------------------------------\n");
}
int main() {
    int n = 3;
    Student students[3] = {
        {"�����", 2002, 3, 85.5},
        {"�����", 2003, 2, 90.0},
        {"����", 2001, 4, 78.0}
    };
    printf("����������� ������ ��������:\n");
    printStudents(students, n);
    // ���������� �� ��'�� (���������)
    qsort(students, n, sizeof(Student), compareByNameAsc);
    printf("������ ��������, ������������ �� ��'�� (���������):\n");
    printStudents(students, n);
    // ���������� �� ��'�� (��������)
    qsort(students, n, sizeof(Student), compareByNameDesc);
    printf("������ ��������, ������������ �� ��'�� (��������):\n");
    printStudents(students, n);
    // ���������� �� ����� ���������� (���������)
    qsort(students, n, sizeof(Student), compareByYearAsc);
    printf("������ ��������, ������������ �� ����� ���������� (���������):\n");
    printStudents(students, n);
    // ���������� �� ����� ���������� (��������)
    qsort(students, n, sizeof(Student), compareByYearDesc);
    printf("������ ��������, ������������ �� ����� ���������� (��������):\n");
    printStudents(students, n);
    // ���������� �� ������ (���������)
    qsort(students, n, sizeof(Student), compareByCourseAsc);
    printf("������ ��������, ������������ �� ������ (���������):\n");
    printStudents(students, n);
    // ���������� �� ������� ����� (��������)
    qsort(students, n, sizeof(Student), compareByGradeDesc);
    printf("������ ��������, ������������ �� ������� ����� (��������):\n");
    printStudents(students, n);
    return 0;
}