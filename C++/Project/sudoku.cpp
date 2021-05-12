#include <cstdio>
#include <iostream>
#include <math.h>       
using namespace std;

bool multiple_of(int in, int multiple) {
    return in % multiple == 0;
}

int int_length (int num) {
    return trunc(log10(num)) + 1;
}
//int[] number_matrix() {

    //return [];
//}
void build_table(int sector_count = 3 ) {
    //if (int_length(sector_count) > 3) 
        //bool 
    int lenght = pow(sector_count, 2) + sector_count; // The number of total positions of the column/row

    for(int row = 0 ; row <= lenght; row++) {
        bool first_row = row == 0;

    int cell = 0;
        for(int col = 0 ; col <= lenght; col++) {
            //bool last_col = cell == 20;
            // If the column its multiple of the sector number and isn't the first row put a vertical line 
            // (Example: after every third number column in a 3 sector board)
            bool vertical_line_position = multiple_of(col, sector_count + 1); 
            //bool space_position = multiple_of(col, sector_count) && !first_row; 
            // If the row its multiple of the sector number and isn't the last column put a vertical line 
            // (Example: after every third number row in a 3 sector board)
            bool horizontal_line_position = multiple_of(row, sector_count + 1);

            if(vertical_line_position && horizontal_line_position){
                cout << "+";
                continue;
            }
            if(vertical_line_position) {
                cout << "|";
                continue;
            }
            if (horizontal_line_position) {
                cout << "-";
                continue;
            }
            cell++;
            cout << cell;
        }
        cout << "\n";
    }
}

int main() {
    int number = 5;
    //int *myPointer;
    int *myPointer = &number;
    int *anotherPointer;
    cout << "My pointer: " << myPointer << "\n";
    cout << "Another pointer" << anotherPointer << "\n";
    build_table();
    cout << "This is my sudoku solver";
    return 0;
}
