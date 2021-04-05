#include "Header.h"

void ReadFromFile(struct Sstudent* pStudent, FILE* pInput) {
    struct Sstudent* add = pStudent;
    fscanf(pInput, "%s %s", &add->cSurname, &add->cName);
    fscanf(pInput, "%d %d %d", &add->StudentBirthday.nDay, &add->StudentBirthday.nMonth, &add->StudentBirthday.nYear);
    fscanf(pInput, "%d %d %d", &add->nMarks[0], &add->nMarks[1], &add->nMarks[2]);
}

//-------------------------------------------------------------------

void PrintTable(struct Sstudent* pHead) {
    printf("________________________________________________________________________________\n");
    printf("|Surname\t|Name\t\t|Date of birth\t|Marks\t\t|Average mark \t|\n");
    printf("|_______________|_______________|_______________|_______________|_______________|\n");
    while (pHead != NULL) {
        printf("|%10s\t|%10s\t", pHead->cSurname, pHead->cName);
        printf("|%2d.%2d.%d", pHead->StudentBirthday.nDay, pHead->StudentBirthday.nMonth, pHead->StudentBirthday.nYear);
        printf("\t|%2d %2d %2d\t|%.2lf\t\t|\n", pHead->nMarks[0], pHead->nMarks[1], pHead->nMarks[2], StudentMarkAvg(pHead));
        pHead = pHead->pNext;
    }
    printf("|_______________|_______________|_______________|_______________|_______________|\n \n");
}

//-------------------------------------------------------------------

double StudentMarkAvg(struct Sstudent* pStudent) {
    double dTemp;
    dTemp = pStudent->nMarks[0] + pStudent->nMarks[1] + pStudent->nMarks[2];
    pStudent->dMarkAvg = dTemp / 3;
    return pStudent->dMarkAvg;
}

//-------------------------------------------------------------------

void RemoveStudents(struct Sstudent* pHead) {
    struct Sstudent* pTemp = pHead;
    while (1) {
        struct Sstudent* pTmp = pTemp;
        pTemp = pTemp->pNext;
        if (!pTemp) {
            break;
        }
        if (pTemp->dMarkAvg < 4.5)
        {
            if (!pTemp->pNext) {
                pTmp->pNext = NULL;
                break;
            }
            pTmp->pNext = pTemp->pNext;
            free(pTemp);
            pTemp = pTmp;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------

double GroupMarkAvg(struct Sstudent* pStudent) {
    double dAmount = 0;
    double dSum = 0;

    for (Sstudent* i = pStudent; i != NULL; i = i->pNext) {
        dAmount++;
        dSum += i->dMarkAvg;
    }
    return dSum / dAmount;
}

//----------------------------------------------------------------------------------------------------------------------------

void SortByMarkAvg(struct Sstudent* pHead, double dGroupAvgMark) {
    struct  Sstudent* pTemp = pHead;
    while (1) {
        struct Sstudent* pTmp = pTemp;
        pTemp = pTemp->pNext;
        if (!pTemp) {
            break;
        }
        if (pTemp->dMarkAvg < dGroupAvgMark) {
            break;
        }
        pTmp->pNext = pTemp->pNext;
        if (!pTemp->pNext) {
            pTmp->pNext = NULL;
            free(pTemp);
            pTemp = pTmp;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------

struct  Sstudent* BubbleSort(struct  Sstudent* pHead) {
    struct  Sstudent* pTemp = pHead;
    while (1) {
        struct  Sstudent* pTmp = (struct Sstudent*)calloc(1, sizeof(struct  Sstudent));
        pTmp->pNext = pTemp;
        int i = 0;
        while (pTmp->pNext->pNext != NULL) {
            if ((pTmp->pNext->dMarkAvg) > (pTmp->pNext->pNext->dMarkAvg)) {
                i = 1;
                if (pTmp->pNext == pTemp) {
                    pTemp = Swap(pTmp);
                }
                else
                    Swap(pTmp);
            }
            pTmp = pTmp->pNext;
        }
        if (!i) {
            return pTemp;
        }
    }
}

//-------------------------------------------------------------------
struct  Sstudent* Swap(struct  Sstudent* pStudent) {
    struct  Sstudent* pTemp;
    pTemp = pStudent->pNext;
    pStudent->pNext = pStudent->pNext->pNext;
    pTemp->pNext = pTemp->pNext->pNext;
    pStudent->pNext->pNext = pTemp;
    return pStudent->pNext;
}

//-------------------------------------------------------------------

void InsertNew(struct Sstudent** pHead) {
    struct Sstudent* first = (struct Sstudent*)calloc(1, sizeof(struct Sstudent));
    printf("Enter the surname: ");
    scanf("%s", first->cSurname);
    printf("Enter the name: ");
    scanf("%s", first->cName);
    printf("Enter the day of birth: ");
    scanf("%d", &first->StudentBirthday.nDay);
    printf("Enter the month of birth: ");
    scanf("%d", &first->StudentBirthday.nMonth);
    printf("Enter the year of birth: ");
    scanf("%d", &first->StudentBirthday.nYear);
    printf("Enter the first mark: ");
    scanf("%d", &first->nMarks[0]);
    printf("Enter the second mark: ");
    scanf("%d", &first->nMarks[1]);
    printf("Enter the third mark: ");
    scanf("%d", &first->nMarks[2]);
    first->dMarkAvg = StudentMarkAvg(first);
    first->pNext = (*pHead);
    (*pHead) = first;
}


//-------------------------------------------------------------------

void FreeList(struct Sstudent** pHead) {
    struct Sstudent* pTemp = *pHead;
    while (pTemp) {
        *pHead = pTemp->pNext;
        free(pTemp);
        pTemp = *pHead;
    }
    *pHead = NULL;

}