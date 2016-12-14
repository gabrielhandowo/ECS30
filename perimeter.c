#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions
void File_Read(char* argv);
void Data_Calc(int** points, int num_rows, int num_cols);

//coordiantes
typedef struct point_struct {
    int rows;
    int** coordinates;
} coor;

//main exceutions
int main(int argc, char* argv[]) {
    
    //Call the function openBinary to open the binary file
    File_Read(argv[1]);
    
    return 0;
}

//read files and allocate spaces
void File_Read(char* argv) {
    FILE* fp = NULL;
    double dataAllocate = 0;
    coor p;
    
    fp = fopen(argv, "rb");
    if (fp == NULL) {
        printf("ERROR........ File Is Empty\n");
        exit(0);
    }

    //store the size
    dataAllocate = fread(&p.rows, sizeof(int), 1, fp);
    p.coordinates = malloc(p.rows * sizeof(int *));

    //allocate rows
    for (int i = 0; i < p.rows; i++) {
        p.coordinates[i] = malloc(2 * sizeof(int));
    }

    while(dataAllocate != 0) {
        for(int i = 0; i < p.rows; ++i) {
            for (int j = 0; j < 2; ++j) {
                dataAllocate = fread(&p.coordinates[i][j], sizeof(int), 1, fp);
            }
        }
    }

    Data_Calc(p.coordinates, p.rows, 2);
    fclose(fp);
}

void Data_Calc(int** points, int num_rows, int num_cols){

    int temp = num_rows;
    int length[num_rows][num_cols];
    double perimeter = 0;

    //diffrence between the coordinate
    for (int i = 0; i < num_rows; ++i){
        length[i][0] = points[i][0] - points[temp - 1][0];
        ++temp;

        if (temp > num_rows) {
            temp = 1;
        }
    }

    temp = num_rows; 

    //Find length
    for (int i = 0; i < num_rows; ++i){
        length[i][1] = points[i][1] - points[temp - 1][1];
        ++temp;
        
        if (temp > num_rows){
            temp = 1;
        }
        perimeter = perimeter + sqrt((pow(length[i][0], 2.0) + pow(length[i][1], 2.0)));
    }

    printf("The perimeter is %.2lf\n", perimeter);
}
