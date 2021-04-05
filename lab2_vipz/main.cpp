#include "Header.h"
int main() {
    system("color f0");
    FILE* pInput;
    pInput = fopen("list.txt", "r");
    if (!pInput) {
        printf("Couldn't open the file");
    }
    struct Sstudent* pHead = (struct Sstudent*)malloc(sizeof(struct Sstudent));
    struct Sstudent* pStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
    pHead->pNext = NULL;
    while (!feof(pInput)) {
        ReadFromFile(pStudent, pInput);
        if (pHead->pNext == NULL) {
            pHead = pStudent;
        }
        if (!feof(pInput)) {
            struct Sstudent* pNextStudent = (struct Sstudent*)calloc(1, sizeof(struct Sstudent));
            pStudent->pNext = pNextStudent;
            pStudent = pNextStudent;
        }
    }
    fclose(pInput);
    pInput = NULL;
    printf("\n Before sorting:\n");
    PrintTable(pHead);
    double dGroupAvgMark = GroupMarkAvg(pHead);
    RemoveStudents(pHead);
    pHead = BubbleSort(pHead);
    printf(" After removing students with average mark less than 4.5:\n");
    PrintTable(pHead);
    printf(" After sorting:\n");
    SortByMarkAvg(pHead, dGroupAvgMark);
    pHead = BubbleSort(pHead);
    PrintTable(pHead);
    InsertNew(&pHead);
    pHead = BubbleSort(pHead);
    printf("\nAfter insertion:\n");
    PrintTable(pHead);
    FreeList(&pHead);
    return 0;
}