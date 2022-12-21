#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct serie {
    char serieName[20];
    int numSeasons;
    int rank;
    int* watchingDetails;
    int code;
}serie;

int showMenu();
void exeCmd(int);
int unifyDatabase(FILE*, FILE*);
serie** getUnifyDatabaseDetails();
void printSeriesList(serie**);
void getWatchingDetails(serie**);
void printWatchingDetails();
void printSeriesByRank();
void makeSeriesFileSortedByRank();
void WriteToFile(FILE*, char[], int, int);
void get_files();
int getSize(int, int);
void free_all_memory();

int input;
FILE* fp1;
FILE* fp2;
FILE* file3;
FILE* watching_file;
int Unify_flag = 0;
int Get_Unify_flag = 0;
int size_of_database = 0;
serie** database;

int main() {
    do
    {
        showMenu();      /* Prints the Menu */
        input = getSize(1, 8);  /* Get command input and validate it */
        exeCmd(input);   /* After input is valid integer, execute the corresponding command */
    } while (input != 8);  /* Loop ends when user enters '0' */
    //exit;
    return 0;
}
int showMenu() {
    // Prints Menu that describes the possible commands for the user.
    printf("**********Main Menu **************\n1. Unify Database.\n2. Get Unify Database Details.\n3. Print The Series List Sorted By Code.\n4. Get Watching Details.\n");
    printf("5. Show All Watching Details.\n6. Print Series Sorted By Rank.\n7. Make Series File Sorted By Rank.\n8. Exit.\n");
    printf("Enter Your Selection:");
    return 0;
}
void exeCmd(int cmd) {
    switch (cmd)    // choosing the function to be executed, according to the cmd (input) value.
    {
    case 1:
        if (!Unify_flag) {
            get_files();
            unifyDatabase(fp1, fp2);
            Unify_flag = 1;
            printf("Unify Succeeded\n");
        }
        else {
            printf("Unify Database Has Been Done Already !!!\n");
        }
        return;
    case 2:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (!Get_Unify_flag) {
                serie** database = getUnifyDatabaseDetails();
                printf("Get Unify Database Details Succeeded\n");
                Get_Unify_flag = 1;
            }
            else {
                printf("Get Unify Database Has Been Done Already !!!\n");
            }
        }
        return;
    case 3:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (Get_Unify_flag) {
                printSeriesList(database);
            }
            else {
                printf("You must Get Unify Database Details before using this option!!!\n");
            }
        }
        return;
    case 4:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (Get_Unify_flag){
                getWatchingDetails(database);
            }
            else {
                printf("You must Get Unify Database Details before using this option!!!\n");
            }
        }
        return;
    case 5:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (Get_Unify_flag) {
                printWatchingDetails();
            }
            else {
                printf("You must Get Unify Database Details before using this option!!!\n");
            }
        }
        return;
    case 6:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (Get_Unify_flag) {
                printSeriesByRank();
            }
            else {
                printf("You must Get Unify Database Details before using this option!!!\n");
            }
        }
        return;
    case 7:
        if (!Unify_flag) {
            printf("You must unify database before using this option!!!\n");
        }
        else {
            if (Get_Unify_flag) {
                makeSeriesFileSortedByRank();
            }
            else {
                printf("You must Get Unify Database Details before using this option!!!\n");
            }
        }
        return;
    case 8:
        printf("End Of The Program...\n");
        if (Unify_flag) {
            free_all_memory();
        }
        return;
    default:    return;
    }
}
int unifyDatabase(FILE* file1, FILE* file2) {
    file3 = fopen("series.txt", "w");   //First and only writing of "series.txt" file.
    char EOF_FLAG1;
    char EOF_FLAG2;
    int code1 = 0;
    int code2 = 0;
    int season1 = 0;
    int season2 = 0;
    char series1_name[100];
    char series1_active[2];
    char series2_name[100];
    char series2_active[2];
    int progress1 = 1;
    int progress2 = 1; 
    while ((EOF_FLAG1!=EOF) || (EOF_FLAG2!=EOF)){    
        if (progress1) {
            EOF_FLAG1 = fscanf(file1,"%[^,],%d,%d,%c%*c",series1_name, &code1,&season1,series1_active);
        }
        if (progress2) {
            EOF_FLAG2 = fscanf(file2,"%[^,],%d,%d,%c%*c",series2_name, &code2,&season2,series2_active);
        }
        if((EOF_FLAG1!=EOF) && (EOF_FLAG2!=EOF)){
            if (code1 == code2) {
                if (series1_active[0] == 'Y' && series2_active[0] == 'Y') {
                    if (season1 > season2) {
                        WriteToFile(file3, series1_name, code1, season1);
                        size_of_database++;
                    }
                    else {
                        WriteToFile(file3, series2_name, code2, season2);
                        size_of_database++;
                    }
                }
                else if (series1_active[0] == 'Y' && series2_active[0] == 'N') {
                    WriteToFile(file3, series1_name, code1, season1);
                    size_of_database++;
                }
                else if (series1_active[0] == 'N' && series2_active[0] == 'Y') {
                    WriteToFile(file3, series2_name, code2, season2);
                    size_of_database++;
                }
                progress1=progress2=1;    
            }
            else if (code1 < code2) {
                if (series1_active[0] == 'Y') {
                        WriteToFile(file3, series1_name, code1, season1);   
                        size_of_database++; 
                    }
                    progress1 = 1;
                    progress2 = 0;                           
            }
            else if (code2 < code1) {
                if (series2_active[0] == 'Y') {
                    WriteToFile(file3, series2_name, code2, season2); 
                    size_of_database++;   
                }
                progress1 = 0;
                progress2 = 1;          
            }

        } 
        else if((EOF_FLAG1==EOF) && (EOF_FLAG2!=EOF)){
           if (code1 < code2) {
                if (series2_active[0] == 'Y') {
                        WriteToFile(file3, series2_name, code2, season2);
                        size_of_database++;
                    }
                    progress2 = 1;
                    progress1 = 0;    
           }
           else if(code1 > code2){
                if (series2_active[0] == 'Y') {
                    WriteToFile(file3, series2_name, code2, season2);
                    size_of_database++;
                }
                progress2 = 1;
                progress1 = 0;        
           }      
        }
        else if((EOF_FLAG1!=EOF) && (EOF_FLAG2==EOF)){
            if (code1 < code2) {
                if (series1_active[0] == 'Y') {
                        WriteToFile(file3, series1_name, code1, season1);
                        size_of_database++; 
                    }
                    progress1 = 1;
                    progress2 = 0;
            }
            else if(code1 > code2){
                if (series1_active[0] == 'Y') {
                    WriteToFile(file3, series1_name, code1, season1); 
                    size_of_database++;
                }
                progress1 = 1;
                progress2 = 0;   
            } 
        }      
    }
    fclose(file1);    
    fclose(file2);     
    fclose(file3);      
    return 0;
}
serie** getUnifyDatabaseDetails() {
    int code = 0;
    int season = 0;
    char series_name[20];
    file3 = fopen("series.txt", "r");   //First and only reading of "series.txt" file.
    database = (serie**)malloc(size_of_database * sizeof(serie*));
    for (int i = 0; i < size_of_database; i++)
    {
        int a = fscanf(file3,"%[^,],%d,%d%*c",series_name, &code,&season);
        int* watching_details = (int*)calloc(season,sizeof(int));
        serie* series = (serie*)malloc(sizeof(serie));
        series->numSeasons = season;
        series->code = code;
        series->watchingDetails = watching_details;
        series->rank = 0;
        for (int j = 0; j < (int)strlen(series_name); j++)
        {
            series->serieName[j] = series_name[j];
        }
        series->serieName[strlen(series_name)] = '\0';
        database[i] = series;
    }
    FILE* watching = fopen("watching.txt", "w");        //initialize watching.txt file.
    fclose(watching);
    fclose(file3);
    return database;
}
void printSeriesList(serie** database) {
    printf("Series List\n");
    for (int i = 0; i < size_of_database; i++)
    {
        printf("%03d-%s(%d)\n", database[i]->code, database[i]->serieName, database[i]->numSeasons);
    }
    printf("\n");
}
void getWatchingDetails(serie** database){
    watching_file = fopen("watching.txt", "a");    //First and only writing of "watching.txt" file.
    char tmp;
    int input = 0;
    int flag = 0;
    int code_flag = 0;
    serie* current_serie;
    printf("Insert Serie Code:");
    while (!code_flag){
        flag = 0;
        flag = scanf("%d",&input);
        while (!flag){
            flag = scanf("%d",&input);
            printf("wrong serie code, try again!!!\n");
            }
        for (int i = 0; i < size_of_database; i++)
        {
            if (input == database[i]->code){
                code_flag = 1;
                current_serie = database[i];
                break;
            }
        }
        if (!code_flag){ printf("wrong serie code, try again!!!\n");}
    }
    int season_range = current_serie->numSeasons;
    printf("Insert Season Number (1 - %d):", season_range);
    flag = 0;
    code_flag = 0;
    while (!code_flag){
        flag = 0;
        flag = scanf("%d",&input);
        while (!flag){
            flag = scanf("%d",&input);
            printf("wrong season number, try again!!!\n");
            }
        if (input>=1 && input <= season_range){
            code_flag = 1;
            printf("series: %d, season: %d accepted!!!\n", current_serie->code, input);
            current_serie->watchingDetails[input-1]++;
            current_serie->rank ++;
            fprintf(watching_file, "%03d,%d\n", current_serie->code,input);
        }
        if(!code_flag){printf("wrong season number, try again!!!\n");}
    }
    fclose(watching_file);                 
}
void printWatchingDetails(){
    char EOF_FLAG;
    FILE* watching = fopen("watching.txt", "r");    //First and only reading of the "watching.txt" file.
    int code = 0;
    int season = 0;
    printf("Watching Details\n");
    while(1)
    {
        fscanf(watching,"%d,%d",&code,&season);
        EOF_FLAG = fgetc(watching);
        if(EOF_FLAG == EOF){break;}
        printf("Series Code:%03d, Season Number:%d\n",code,season);
    }
    fclose(watching);
}
void printSeriesByRank(){
//find maximal rank
    int max = 0;
    for (int i = 0; i < size_of_database; i++)
    {
        if (database[i]->rank > max){
            max = database[i]->rank;
        }
    }
    for (int j = max; j >= 0; j--)
    {
        printf("RANK %d\n", j);
        for (int k = 0; k < size_of_database; k++)
        {
            if(database[k]->rank == j){
                    printf("%03d-%s\n", database[k]->code, database[k]->serieName);
                    for (int t = 0; t < database[k]->numSeasons; t++)
                    {
                        printf("Season %d:%d\n", t+1, database[k]->watchingDetails[t]);
                    }                    
            }
        }
    }
}
void makeSeriesFileSortedByRank(){
    FILE* rank_file = fopen("seriesRank.txt","w");      //First and only reading of "seriesRank.txt" file.  
    //find maximal rank
    int max = 0;
    for (int i = 0; i < size_of_database; i++)
    {
        if (database[i]->rank > max){
            max = database[i]->rank;
        }
    }
    for (int j = max; j >= 0; j--)
    {
        for (int k = 0; k < size_of_database; k++)
        {
            if(database[k]->rank == j){
                    fprintf(rank_file,"%03d(Rank:%d)-%s\n", database[k]->code,j,database[k]->serieName);               
            }
        }
    }
    fclose(rank_file);
}
void WriteToFile(FILE* file, char seriesName[], int seriesCode, int seriesSeason) {
    fputs(seriesName, file3);
    fputs(",", file3);
    fprintf(file3, "%d", seriesCode); 
    fputs(",", file3);
    fprintf(file3, "%d", seriesSeason); 
    fputs("\n", file3);
}
void get_files() {
    int counter = 0;
    char input_file[20];
    while (counter < 2) {
        if (!counter) printf("Enter First File Name:\n");
        else { printf("Enter Second File Name:\n"); }
        fflush(stdin);
        fgets(input_file, 20, stdin);
        input_file[strcspn(input_file, "\n")] = 0;
        if (!counter) {
            fp1 = fopen(input_file, "r");          //First and only reading of the first text file.
            if (fp1!=NULL) counter++;
            else { printf("error in opening file %s !!!\n", input_file); }
        }
        else {
            fp2 = fopen(input_file, "r");          //First and only reading of the second text file.
            if (fp2!=NULL) counter++;
            else { printf("error in opening file %s !!!\n", input_file); }
        }
    }
}
int getSize(int a, int b) {
    int flag = 1;
    int first_num_flag = 0;
    int input = 0;
    char input_str[200];
    fflush(stdin);
    fgets(input_str, 200, stdin);
    for (int i = 0; i < (int)strlen(input_str) - 1; i++)
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
        printf("Wrong Option, Try Again !!!\n");
        showMenu();
        fflush(stdin);
        fgets(input_str, 200, stdin);
        for (int i = 0; i < (int)strlen(input_str) - 1; i++)
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
void free_all_memory(){
for (int i = 0; i < size_of_database; i++)
{
free(database[i]->watchingDetails);
free(database[i]);
}
free(database);
}
