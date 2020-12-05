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

    input_stream.open(input_file_name, ifstream::in);

    string input_line, password;
    char password_letter;

    int first_position, second_position;

    int valid_password_count = 0;

    while (getline(input_stream, input_line))
    {
        replace(input_line.begin(), input_line.end(), '-', ' ');
        input_line.erase(remove(input_line.begin(), input_line.end(), ':'), input_line.end());

        stringstream string_stream;
        string_stream << input_line;

        string_stream >> first_position >> second_position >> password_letter >> password;

        first_position--;
        second_position--;

        if (password[first_position] == password_letter && password[second_position] != password_letter)
            valid_password_count++;
        else if (password[first_position] != password_letter && password[second_position] == password_letter)
            valid_password_count++;
    }

    input_stream.close();

    cout << "Valid password count: " << valid_password_count << endl;

    return EXIT_SUCCESS;
}