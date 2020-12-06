#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define MAX_R 127
#define MAX_C 7

using namespace std;

int IDFromString(string sequence);

const string input_file_name = "input.txt";

string test_input = "FBFBBFFRLR";

int main(int argc, char **argv)
{
    ifstream input_stream;

    string input_string;

    int highest_id = 0;
    int current_id = 0;
    
    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        input_stream >> input_string;

        current_id = IDFromString(input_string);

        if (current_id > highest_id)
            highest_id = current_id;
    }

    input_stream.close();

    cout << "Highest ID: " << highest_id << endl;

    return EXIT_SUCCESS;
}

int IDFromString(string sequence)
{
    int id = 0;
    int current_row_bottom = 0;
    int current_row_top = MAX_R;
    int current_column_bottom = 0;
    int current_column_top = MAX_C;

    for (int i = 0; i < 7; i++)
    {
        if (i == 6)
        {
            if (sequence[i] == 'F')
                id = current_row_bottom;
            else if (sequence[i] == 'B')
                id = current_row_top;

            break;
        }

        if (sequence[i] == 'F')
            current_row_top = ((current_row_bottom + current_row_top) / 2);
        else if (sequence[i] == 'B')
            current_row_bottom = ((current_row_bottom + current_row_top) / 2) + 1;
    }

    for (int i = 7; i <= 9; i++)
    {
        if (i == 9)
        {
            if (sequence[i] == 'L')
                id = id * 8 + current_column_bottom;
            else if (sequence[i] == 'R')
                id = id * 8 + current_column_top;
        }

        if (sequence[i] == 'L')
            current_column_top = ((current_column_bottom + current_column_top) / 2);
        else if (sequence[i] == 'R')
            current_column_bottom = ((current_column_bottom + current_column_top) / 2) + 1;
    }

    return id;
}