#include <iostream>
#include <fstream>
#include <vector>

#define MAX_X 31
#define MAX_Y 323

using namespace std;

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    char map[MAX_Y][MAX_X];

    vector<int> input_numbers;
    
    ifstream input_stream;

    int tree_count = 0;

    input_stream.open(input_file_name, ifstream::in);

    for (int y = 0; y < MAX_Y; y++)
        for (int x = 0; x < MAX_X; x++)
            input_stream >> map[y][x];

    input_stream.close();
    
    int x = 0;

    for (int y = 1; y < MAX_Y; y++)
    {
        x += 3;

        if (x >= MAX_X)
            x -= MAX_X;

        if (map[y][x] == '#')
            tree_count++;
    }

    cout << "Encountered trees: " << tree_count << endl;

    return EXIT_SUCCESS;
}