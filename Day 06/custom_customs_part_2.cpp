#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define ABC_MAX 26

using namespace std;

int IntFromChar(char c);

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    int groups_declaration[ABC_MAX] = {0};

    ifstream input_stream;

    input_stream.open(input_file_name, ifstream::in);

    string text_line, declaration;

    int answer_count = 0;
    int people_in_group = 0;

    while (!input_stream.eof())
    {
        getline(input_stream, text_line);

        declaration += text_line;

        if (text_line == "")
        {
            for (int i = 0; i < declaration.length(); i++)
                groups_declaration[IntFromChar(declaration[i])]++;

            for (int i = 0; i < ABC_MAX; i++)
            {
                if (groups_declaration[i] == people_in_group)
                    answer_count++;

                groups_declaration[i] = 0;
            }

            declaration = "";
            people_in_group = 0;
        }
        else
        {
            people_in_group++;
        }
    }

    input_stream.close();

    cout << "Answer count: " << answer_count << endl;

    return EXIT_SUCCESS;
}

int IntFromChar(char c)
{
    return (int)c - 97;
}