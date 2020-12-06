#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    ifstream input_stream;

    string input_line, password;

    char password_letter;

    int min, max, occurrences = 0;
    int valid_password_count = 0;

    input_stream.open(input_file_name, ifstream::in);

    while (getline(input_stream, input_line))
    {
        replace(input_line.begin(), input_line.end(), '-', ' ');
        input_line.erase(remove(input_line.begin(), input_line.end(), ':'), input_line.end());

        stringstream string_stream;
        string_stream << input_line;

        string_stream >> min >> max >> password_letter >> password;

        for (int i = 0; i < password.length(); i++)
            if (password[i] == password_letter)
                occurrences++;

        if (occurrences >= min && occurrences <= max)
            valid_password_count++;

        occurrences = 0;
    }

    input_stream.close();

    cout << "Valid password count: " << valid_password_count << endl;

    return EXIT_SUCCESS;
}