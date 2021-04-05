#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
#define NUMBER_OF_MARKS 50

//
//Struct, that keeps data about a student's birthday
//
struct SBirthday {
    int nDay;
    int nMonth;
    int nYear;
};
//
//Struct, that keeps data about a student
//
struct Sstudent {
    char cSurname[SIZE];
    char cName[SIZE];
    struct SBirthday StudentBirthday;
    int nMarks[NUMBER_OF_MARKS];
    double dMarkAvg;
    struct Sstudent* pNext;
};

//
//Reads students' data from a file
//
void ReadFromFile(struct Sstudent* pStudent, FILE* pInput);
//
//Prints a table with students'data
//
void PrintTable(struct Sstudent* pHead);
//
//Finds a student's average mark
//
double StudentMarkAvg(struct Sstudent* pStudent);
//
//Removes students, whose average marks is below 4.5
//
void RemoveStudents(struct Sstudent* pHead);
//
//Finds a groups's average mark
//
double GroupMarkAvg(struct Sstudent* pStudent);
//
//Removes students, whose average marks is below the group's average mark
//
void SortByMarkAvg(struct Sstudent* pHead, double dGroupAvgMark);
//
//Sorts students by their average marks in increasing order
//
struct Sstudent* BubbleSort(struct Sstudent* pHead);
//
//Swaps the element with the following one
//
struct Sstudent* Swap(struct Sstudent* pStudent);
//
//Insert a new element in the beginning of the list
//
void InsertNew(struct Sstudent** pHead);
//
//Frees dynamic memory
//
void FreeList(struct Sstudent** pHead);
