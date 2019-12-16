//
// Created by jenny on 09/12/2019.
// Name - Jenny Davidov
// ID - 206792186
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fourCase(FILE *fPtr, int k);

int multMethod(FILE *fPtr, int n, int m, bool flagEax, int countBySub, int countByNeg);

void ifItsNegNumber(FILE *fPtr, bool flagEax, int k);

int subNegMult(FILE *fPtr, int n, int m, bool flagEax, int countBySub, int countByNeg);

int main(int argc, char *argv[]) {
    bool done = false;
    FILE *fPtr;
    fPtr = fopen("kefel.s", "w");
    //check if opening file didn't succeed
    if (fPtr == NULL) {
        printf("Didn't succeed to open file\n");
        return -1;
    }
    //Write data to file
    fprintf(fPtr, ".section .text\n.globl   kefel\nkefel:  ");
    //convert the given K param to int from string
    int k = atoi(argv[1]);
    //check if K can be devided in 3 OR 9 OR 5
    switch (k) {
        case 0: {
            fprintf(fPtr, "movl $0x00,%%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        case 1: {
            fprintf(fPtr, "movl %%eax,%%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        case -1: {
            fprintf(fPtr, "movl %%eax,%%eax\n");
            fprintf(fPtr, "neg %%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        case 3: {
            fprintf(fPtr, "leal (%%edi,%%edi,2), %%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        case 5: {
            fprintf(fPtr, "leal (%%edi,%%edi,4), %%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        case 9: {
            fprintf(fPtr,
                    "leal (%%edi,%%edi,8), %%eax\n");
            fprintf(fPtr, "ret\n");
            done = true;
            break;
        }
        default:
            break;
    }
    //for all other K values
    if (done == false) {
        if ((k % 3 == 0) || (k % 5 == 0) || (k % 9 == 0)) {
            //if K is kind of 3/5/9 * 2^pow - THIRD case
            if (k % 3 == 0) {
                int temp = k / 3, pow = 0;
                while (temp != 1) {
                    if (temp % 2 != 0) {
                        pow = -1;
                        break;
                    }
                    pow++;
                    temp = temp / 2;
                }
                if (pow != -1) {
                    fprintf(fPtr, "leal (%%edi,%%edi,2), %%eax\n");
                    fprintf(fPtr, "shl $%d,%%eax\n", pow);
                    fprintf(fPtr, "ret\n");
                } else {
                    fourCase(fPtr, k);
                }
            }
            if (k % 5 == 0) {
                int temp = k / 5, pow = 0;
                while (temp != 1) {
                    if (temp % 2 != 0) {
                        pow = -1;
                        break;
                    }
                    pow++;
                    temp = temp / 2;
                }
                if (pow != -1) {
                    fprintf(fPtr, "leal (%%edi,%%edi,4), %%eax\n");
                    fprintf(fPtr, "shl $%d,%%eax\n", pow);
                    fprintf(fPtr, "ret\n");
                } else {
                    fourCase(fPtr, k);
                }
            }
            if (k % 9 == 0) {
                int temp = k / 9, pow = 0;
                while (temp != 1) {
                    if (temp % 2 != 0) {
                        pow = -1;
                        break;
                    }
                    pow++;
                    temp = temp / 2;
                }
                if (pow != -1) {
                    fprintf(fPtr, "leal (%%edi,%%edi,8), %%eax\n");
                    fprintf(fPtr, "shl $%d,%%eax\n", pow);
                    fprintf(fPtr, "ret\n");
                } else {
                    fourCase(fPtr, k);
                }
            }
        } else {
            fourCase(fPtr, k);
        }
    }
// Close file to save file data
    fclose(fPtr);
    return 0;
}

void fourCase(FILE *fPtr, int k) {
    int countByNeg = 0, countBySub = 0;
    bool flagEax = true;
    //find n,m param
    //n- the most left light bit
    //m - the most right light bit
    int numOfShifts = 31;
    int n, m;
    if (k < 0) {
        //convert it to positive
        ifItsNegNumber(fPtr, flagEax, k);
    }
    while (numOfShifts >= 0) {
        //check if the bit is light
        if (k & (1 << numOfShifts)) {
            //set n to be this number
            n = numOfShifts;
            if (numOfShifts == 0) {
                fprintf(fPtr, "leal (%%edi,%%eax), %%eax\n");
                break;
            }
            while (k & (1 << numOfShifts)) {
                numOfShifts = numOfShifts - 1;
            }
            m = numOfShifts + 1;
            if (numOfShifts == 0) {
                fprintf(fPtr, "leal (%%edi,%%eax), %%eax\n");
            }
            countByNeg = multMethod(fPtr, n, m, flagEax, countByNeg, countBySub);
            flagEax = false;
        }
        numOfShifts = numOfShifts - 1;
    }
    fprintf(fPtr, "ret\n");
}

int multMethod(FILE *fPtr, int n, int m, bool flagEax, int countBySub, int countByNeg) {
    if (n == m) {
        //implement the A method
        //(x << n) + (x << n-1) + . . . + (x << m)
        //if eax is available
        if (flagEax == true) {
            countByNeg = countByNeg + 2;
            fprintf(fPtr, "movl %%edi,%%eax\n");
            fprintf(fPtr, "shl $%d,%%eax\n", n);
            //fprintf(fPtr, "ret\n");
        } else {
            countByNeg = countByNeg + 3;
            fprintf(fPtr, "movl %%edi,%%ecx\n");
            fprintf(fPtr, "shl $%d,%%ecx\n", n);
            fprintf(fPtr, "addl %%ecx,%%eax\n");
        }
    } else {
        //implement the B method - (x << n+1) - (x << m)
        if (flagEax == true) {
            countByNeg = countByNeg + 2;
            fprintf(fPtr, "movl %%edi,%%eax\n");
            fprintf(fPtr, "shl $%d,%%eax\n", n + 1);
            if (m == 0) {
                countByNeg = countByNeg + 1;
                fprintf(fPtr, "subl %%edi,%%eax\n");
            } else {
                countByNeg = countByNeg + 3;
                fprintf(fPtr, "movl %%edi,%%ecx\n");
                fprintf(fPtr, "shl $%d,%%ecx\n", m);
                fprintf(fPtr, "subl %%ecx,%%eax\n");
            }
        } else {
            countByNeg = countByNeg + 2;
            fprintf(fPtr, "movl %%edi,%%ecx\n");
            fprintf(fPtr, "shl $%d,%%ecx\n", n + 1);
            if (m == 0) {
                countByNeg = countByNeg + 1;
                fprintf(fPtr, "subl %%edi,%%eax\n");
            } else {
                countByNeg = countByNeg + 4;
                fprintf(fPtr, "movl %%edi,%%edx\n");
                fprintf(fPtr, "shl $%d,%%edx\n", m);
                fprintf(fPtr, "subl %%edx,%%ecx\n");
                fprintf(fPtr, "addl %%ecx,%%eax\n");
            }
        }
    }
}

int subNegMult(FILE *fPtr, int n, int m, bool flagEax, int countBySub, int countByNeg) {
    //implementation: on first m-n, other as usual, sub between
    if (n == m) {
        if (flagEax == true) {
            countBySub = countBySub + 3;
            fprintf(fPtr, "movl %%edi,%%eax\n");
            fprintf(fPtr, "shl $%d,%%eax\n", n);
            fprintf(fPtr, "neg %%eax\n");
        } else {
            countBySub = countBySub + 3;
            fprintf(fPtr, "movl %%edi,%%ecx\n");
            fprintf(fPtr, "shl $%d,%%ecx\n", n);
            fprintf(fPtr, "subl %%ecx,%%eax\n");
        }
    } else {
        //implement the B method - (x << m)- (x << n+1)
        if (flagEax == true) {
            if (m == 0) {
                fprintf(fPtr, "movl %%edi,%%eax\n");
                countBySub = countBySub + 1;
            } else {
                fprintf(fPtr, "movl %%edi,%%eax\n");
                fprintf(fPtr, "shl $%d,%%eax\n", m);
                countBySub = countBySub + 2;
            }
            //if its the first be negative
            countBySub = countBySub + 3;
            fprintf(fPtr, "movl %%edi,%%ecx\n");
            fprintf(fPtr, "shl $%d,%%ecx\n", n + 1);
            fprintf(fPtr, "subl %%ecx,%%eax\n");
        } else {
            countBySub = countBySub + 2;
            fprintf(fPtr, "movl %%edi,%%ecx\n");
            fprintf(fPtr, "shl $%d,%%ecx\n", n + 1);
            if (m == 0) {
                countBySub = countBySub + 2;
                fprintf(fPtr, "subl %%edi,%%ecx\n");
                fprintf(fPtr, "subl %%ecx,%%eax\n");
            } else {
                countBySub = countBySub + 4;
                fprintf(fPtr, "movl %%edi,%%edx\n");
                fprintf(fPtr, "shl $%d,%%edx\n", m);
                fprintf(fPtr, "subl %%edx,%%ecx\n");
                fprintf(fPtr, "subl %%ecx,%%eax\n");
            }
        }
    }
    return countBySub;
}

void ifItsNegNumber(FILE *fPtr, bool flagEax, int k) {
    int countBySub = 0, countbyNeg = 0;
    //convert it to positive
    k = k * (-1);
    //TEST THE FIRST METHOD
    int numOfShifts = 31;
    int n, m;
    while (numOfShifts >= 0) {
        //check if the bit is light
        if (k & (1 << numOfShifts)) {
            if (numOfShifts == 0) {
                countBySub++;
                countbyNeg++;
                break;
            }
            //set n to be this number
            n = numOfShifts;
            while (k & (1 << numOfShifts)) {
                numOfShifts = numOfShifts - 1;
            }
            m = numOfShifts + 1;
            countBySub = subNegMult(fPtr, n, m, flagEax, countBySub, countbyNeg);
            countbyNeg = multMethod(fPtr, n, m, flagEax, countBySub, countbyNeg);
            countbyNeg++;
            flagEax = false;
        }
        numOfShifts = numOfShifts - 1;
    }
    fclose(fPtr);
    fPtr = fopen("kefel.s", "w");
    //check if opening file didn't succeed
    //Write data to file
    fprintf(fPtr, ".section .text\n.globl   kefel\nkefel:  ");
    if (countBySub <= countbyNeg) {
        numOfShifts = 31;
        flagEax = true;
        while (numOfShifts >= 0) {
            //check if the bit is light
            if (k & (1 << numOfShifts)) {
                if (numOfShifts == 0) {
                    fprintf(fPtr, "subl %%edi,%%eax\n");
                    break;
                }
                //set n to be this number
                n = numOfShifts;
                while (k & (1 << numOfShifts)) {
                    numOfShifts = numOfShifts - 1;
                }
                m = numOfShifts + 1;
                subNegMult(fPtr, n, m, flagEax, countBySub, countbyNeg);
                flagEax = false;
            }
            numOfShifts = numOfShifts - 1;
        }
        fprintf(fPtr, "ret\n");
        fclose(fPtr);

    } else {
        numOfShifts = 31;
        flagEax = true;
        while (numOfShifts >= 0) {
            //check if the bit is light
            if (k & (1 << numOfShifts)) {
                if (numOfShifts == 0) {
                    fprintf(fPtr, "leal (%%edi,%%eax), %%eax\n");
                    break;
                }
                //set n to be this number
                n = numOfShifts;
                while (k & (1 << numOfShifts)) {
                    numOfShifts = numOfShifts - 1;
                }
                m = numOfShifts + 1;
                subNegMult(fPtr, n, m, flagEax, countBySub, countbyNeg);
                flagEax = false;
            }
            numOfShifts = numOfShifts - 1;
        }
        fprintf(fPtr, "neg %%eax\n");
    }
    fprintf(fPtr, "ret\n");
    fclose(fPtr);
}


