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

    int a = 0, b = 0, c = 0, d = 0, e = 0;

    input_stream.open(input_file_name, ifstream::in);

    for (int y = 0; y < MAX_Y; y++)
        for (int x = 0; x < MAX_X; x++)
            input_stream >> map[y][x];

    input_stream.close();
    
    int ax = 0, bx = 0, cx = 0, dx = 0, ex = 0;

    for (int y = 1; y < MAX_Y; y++)
    {
        ax += 1;
        bx += 3;
        cx += 5;
        dx += 7;

        if (ax >= MAX_X)
            ax -= MAX_X;

        if (bx >= MAX_X)
            bx -= MAX_X;

        if (cx >= MAX_X)
            cx -= MAX_X;

        if (dx >= MAX_X)
            dx -= MAX_X;

        if (map[y][ax] == '#')
            a++;

        if (map[y][bx] == '#')
            b++;

        if (map[y][cx] == '#')
            c++;

        if (map[y][dx] == '#')
            d++;
    }

    for (int y = 2; y < MAX_Y; y += 2)
    {
        ex += 1;

        if (ex >= MAX_X)
            ex -= MAX_X;

        if (map[y][ex] == '#')
            e++;
    }

    cout << a << " " << b << " " << c << " " << d << " " << e << " " << endl;

    long answer = a * b;
    answer *= c;
    answer *= d;
    answer *= e;

    cout << "Answer: " << answer << endl;

    return EXIT_SUCCESS;
}