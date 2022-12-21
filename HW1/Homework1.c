#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
int checkString(char[]);
int getInput();
void printWords(char[][20], int);
void insertStrings(char[][20], int);
int getSize(int, int);
int asciiSum(char[]);
double asciiAvg(char[]);
void sortStringsLexicographic(char[][20], int);
void sortStringsByLength(char[][20], int);
void sortStringsByAsciiSum(char[][20], int);
void sortStringsByAsciiAvg(char[][20], int);
void sortEachString(char[][20], int);
void sortString(char[]);
void sortAllAsOne(char[][20], int);
void exeCmd(int);
void stringCopy(char[20], char[20]);
int max_tab_by_sum();
int max_tab_by_avg();
void stable_sorting(char arr2sort[][20], int size, int type_of_sort);

int input;
int errors = 0;
char words[10][20];
int N;

int main() {
    do
    {
        printMenu();      /* Prints the Menu */ 
        input = getInput();  /* Get command input and validate it */
        exeCmd(input);   /* After input is valid integer, execute the corresponding command */
    } while (input);  /* Loop ends when user enters '0' */
    //exit;
    return 0;
}

void printMenu() {

    // Prints Menu that describes the possible commands for the user.
    printf("The menu:\n=========\n0. Exit\n1. Insert words\n2. Print words\n3. Sort words lexicographic\n4. Sort words by length\n");
    printf("5. Sort words by ascii sum\n6. Sort words by ascii average\n7. Sort each word by ascii\n8. Sort all words as one\n");
    printf("Please enter a number between 0 and 99:");
}

int getInput() {
    int i;
    i = getSize(0, 99);     /* gets an input from the user, and checks if the input is in the wanted range */
    if (i > 8 && i < 100) { /* If the input is indeed an integer but out of the defined ranged, count the errors */
        errors += 1;
        if (errors < 5) {
            printf("You made %d errors from 5, try again,\n", errors);
        }
    }
    return i;
}

void exeCmd(int cmd) {
    if (cmd == 0) {
        printf("You chose to end the program, bye!!!\n");
        return;
    }
    if ((cmd > 8) && (cmd < 100)) {
        if (errors == 5) {
            input = 0;  /*After returning, the program will exit*/
            printf("5 errors, bye bye.\n");
        }
        return;
    }
    switch (cmd)    // choosing the function to be executed, according to the cmd (input) value.
    {
    case 1:
        insertStrings(words, N);    return;
    case 2:
        printWords(words, N);   return;
    case 3:
        sortStringsLexicographic(words, N);  return;
    case 4:
        sortStringsByLength(words, N);  return;
    case 5:
        sortStringsByAsciiSum(words, N);    return;
    case 6:
        sortStringsByAsciiAvg(words, N);    return;
    case 7:
        sortEachString(words, N);   return;
    case 8:
        sortAllAsOne(words, N);     return;
    default:    return;
    }
}

void insertStrings(char word_array[][20], int size) {
    printf("Enter new word count,\n");
    printf("Please enter a number between 2 and 10:");
    N = getSize(2, 10);     /*Using the getsize func to scan and validate a new integer input*/
    for (int j = 0;j < N;j++) {
        char temp[20];
        printf("Please enter word #%d:\n", j + 1);
        while (!checkString(temp)) {    /* checkString scans a string from the user, and return 1 if the input string is valid.*/
            printf("Wrong input, try again:\n");
        }
        for (int k = 0;k < 20;k++) {        /* modify our final words array */
            word_array[j][k] = temp[k]; 
        }
    }
}

int checkString(char A[]) {
    char str[200];      /* we can assume string length is no longer than 200 chars */
    char helper[20];
    int c;
    fflush(stdin);
    gets(str);
    for (int i = 0;i < 20;i++) {
        if (str[i] == '\0') {      /*if we reached the end of the string */
            helper[i] = str[i];
            for (int j = 0; j < 20;j++) {
                A[j] = helper[j];
            }
            return 1;
        }
        if ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || (str[i] > 'z')) { /* if the char isn't a letter */
            return 0;
        }
        helper[i] = str[i];
    }
    return 0;
}

void printWords(char arr2print[][20], int size) {
    if (!size) {
        printf("There are no words, cannot operate.\n");
        return;
    }
    printf("The words are:\n");
    printf("==============\n");
    /* max_sum and avg_sum designed to deal with the words allignment by calculating extra spaces */
    int max_sum = max_tab_by_sum();
    int max_avg = max_tab_by_avg() + 3;
    for (int i = 0;i < size;i++) {
        printf("0%d:(ascii sum %*d", (i + 1), max_sum, asciiSum(arr2print[i]));
        printf(", ascii avg %*.2f)%s\n", max_avg, asciiAvg(arr2print[i]), arr2print[i]);
    }
}

int asciiSum(char word[]) {
    int sum = 0;
    int i = 0;
    while (word[i] != '\0') {
        sum += word[i];
        i++;
    }
    return sum;
}

double asciiAvg(char word[]) {
    double sum = 0;
    int i = 0;
    while (word[i] != '\0') {
        sum += word[i];
        i++;
    }
    if (i == 0)  return 0; 
    return (sum / i);
}

void sortStringsLexicographic(char arr2sort[][20], int size) {
    stable_sorting(arr2sort, size, 1);
    return;
}

void sortStringsByLength(char arr2sort[][20], int size) {
   stable_sorting(arr2sort, size, 2);
    return;
}

void sortStringsByAsciiSum(char arr2sort[][20], int size) {
    stable_sorting(arr2sort, size, 3);
    return;
}

void sortStringsByAsciiAvg(char arr2sort[][20], int size) {
    stable_sorting(arr2sort, size, 4);
    return;
}

void sortEachString(char arr2sort[][20], int size) {
    if (!size) {
        printf("There are no words, cannot operate.\n");
        return;
    }
    char temp;
    for (int k = 0; k < size; k++)
    {
        sortString(arr2sort[k]);
    }
    return;

}

void sortAllAsOne(char arr2sort[][20], int size) {
    if (!size) {
        printf("There are no words, cannot operate.\n");
        return;
    }
    char temp[200] = "";
    char arr_len[10];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        arr_len[i] = strlen(arr2sort[i]);
        for (int j = 0; j < strlen(arr2sort[i]); j++) {
            temp[counter] = arr2sort[i][j];
            counter++;
        }
    }
    sortString(temp);
    int counter2 = 0;
    for (int k = 0; k < size; k++) {
        for (int t = 0; t < arr_len[k]; t++) {
            arr2sort[k][t] = temp[counter2];
            counter2++;
        }
    }
    return;
}

void stringCopy(char dst[20], char src[20]) {
    for (int j = 0; j < 20;j++) {
        dst[j] = src[j];
    }
    return;
}

void sortString(char arr2sort[]) {
    char temp;
    for (int i = 0; i < strlen(arr2sort); ++i) {
        for (int j = i + 1; j < strlen(arr2sort); ++j) {
            // swapping letters if they are not in the lexicographical order
            if (arr2sort[i] > arr2sort[j]) {
                temp = arr2sort[i];
                arr2sort[i] = arr2sort[j];
                arr2sort[j] = temp;
            }
        }
    }
    return;
}

int getSize(int a, int b) {
    int flag = 1;
    int first_num_flag = 0;
    int input = 0;
    char input_str[200];
    fflush(stdin);
    fgets(input_str, 200, stdin);
    for (int i = 0; i < strlen(input_str) - 1; i++)
    {
        if (((input_str[i]) < 48 || (input_str[i]) > 57) && (input_str[i]) != 32) {
            flag = 1;
            break;
        }
        if (i > 0) {
            if (first_num_flag && (input_str[i] != 32) && (input_str[i - 1]) == 32) {
                flag = 1;
                break;
            }
        }
        if ((input_str[i]) != 32) {
            input = input * 10 + (int)input_str[i] - '0';
            first_num_flag = 1;
        }
        flag = 0;
    }
    while ((input < a) || (input > b) || (flag)) {
        input = 0;
        int first_num_flag = 0;
        printf("Please enter a number between %d and %d:", a, b);
        fflush(stdin);
        fgets(input_str, 200, stdin);
        for (int i = 0; i < strlen(input_str) - 1; i++)
        {
            if (((input_str[i]) < 48 || (input_str[i]) > 57) && (input_str[i]) != 32) {
                flag = 1;
                break;
            }
            if (i > 0) {
                if (first_num_flag && (input_str[i] != 32) && (input_str[i - 1]) == 32) {

                    flag = 1;
                    break;
                }
            }
            if ((input_str[i]) != 32) {
                input = input * 10 + (int)input_str[i] - '0';
                first_num_flag = 1;
            }
            flag = 0;
        }
    }
    return input;
}

int max_tab_by_sum() {
    int max_sum = 0;
    int count = 0;
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp = asciiSum(words[i]);
        if (temp > max_sum) {
            max_sum = temp;
        }
    }
    while (max_sum != 0)
    {
        max_sum = max_sum / 10;
        count++;
    }
    return count;

}

int max_tab_by_avg() {
    float max_avg = 0;
    int max_final;
    int count = 0;
    float temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp = asciiAvg(words[i]);
        if (temp > max_avg) {
            max_avg = temp;
        }
    }
    max_final = (int)max_avg;
    while (max_final != 0)
    {
        max_final = max_final / 10;
        count++;
    }
    return count;
}

void stable_sorting(char arr2sort[][20], int size, int type_of_sort){

    /* Here we use a stable sort algorithm */
    if (!size) {
        printf("There are no words, cannot operate.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++){  /* compares every 'minimal' word with all the next words in the array */
                 if(type_of_sort==1){ if (strcmp(arr2sort[min], arr2sort[j]) > 0) min= j;  }  
            else if(type_of_sort==2){ if (strlen(arr2sort[min]) > strlen(arr2sort[j])) min= j; }
            else if(type_of_sort==3){ if (asciiSum(arr2sort[min]) > asciiSum(arr2sort[j])) min= j; }
            else if(type_of_sort==4){ if (asciiAvg(arr2sort[min]) > asciiAvg(arr2sort[j])) min= j; }
        }
        char key[20];
        stringCopy(key, arr2sort[min]); /*save the minimal word found*/
        while (min > i)
        {
            stringCopy(arr2sort[min], arr2sort[min - 1]);
            min--;
        }
        stringCopy(arr2sort[i], key);
    }
    return;
}
