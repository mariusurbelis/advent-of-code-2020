#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertAnswer(vector<char> &declarations, char answer);

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    vector<char> groups_declaration;
    ifstream input_stream;

    input_stream.open(input_file_name, ifstream::in);

    string text_line, declaration;

    int answer_count = 0;

    while (!input_stream.eof())
    {
        getline(input_stream, text_line);

        declaration += text_line;

        if (text_line == "")
        {
            for (int i = 0; i < declaration.length(); i++)
                InsertAnswer(groups_declaration, declaration[i]);

            answer_count += groups_declaration.size();

            declaration = "";
            groups_declaration.clear();
        }
    }

    input_stream.close();

    cout << "Answer count: " << answer_count << endl;

    return EXIT_SUCCESS;
}

void InsertAnswer(vector<char> &declarations, char answer)
{
    if (!(find(declarations.begin(), declarations.end(), answer) != declarations.end()))
    {
        declarations.push_back(answer);
    }    
}