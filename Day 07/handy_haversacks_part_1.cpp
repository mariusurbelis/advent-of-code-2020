#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

#define LAST bags.size() - 1

using namespace std;

const string input_file_name = "input.txt";

void RemoveFromString(string &mainStr, const string &toErase);

vector<vector<string>> bags;

int bags_count = 0;

void FindBags(string bag_name)
{
    for (int i = 0; i < LAST; i++)
    {
        if (find(bags[i].begin() + 1, bags[i].end(), bag_name) != bags[i].end())
        {
            FindBags(bags[i][0]);
            cout << "ID: " << i << " " << bags[i][0] << " holds " << bag_name << endl;
            bags_count++;
            //return;
        }
    }
    
}

int main(int argc, char **argv)
{
    ifstream input_stream;

    string text_line;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        getline(input_stream, text_line);

        RemoveFromString(text_line, "bags");
        RemoveFromString(text_line, "bag");
        RemoveFromString(text_line, "contain");

        text_line.erase(remove_if(text_line.begin(), text_line.end(), [](char c) { return !isalpha(c) && c != ' '; }), text_line.end());

        string::iterator new_end =
            unique(text_line.begin(), text_line.end(),
                   [=](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
        text_line.erase(new_end, text_line.end());

        stringstream text_line_stream;

        text_line_stream << text_line;

        string bag_color = "";

        vector<string> bags_single;

        while (!text_line_stream.eof())
        {
            bag_color = "";

            text_line_stream >> bag_color;

            if (bag_color == "")
            {
                if (text_line_stream.str() != "")
                    bags.push_back(bags_single);
                break;
            }

            bags_single.push_back(bag_color);
            text_line_stream >> bag_color;
            bags_single[bags_single.size() - 1] += bag_color;
        }

        //cout << bags[LAST][bags[LAST].size() - 1] << endl;
        //cout << bags.size() << " " << bags[LAST].size() << endl;

        //cout << text_line << endl;

        //exit(0);
    }

    cout << bags.size() << endl;

    FindBags("shinygold");

    cout << "Answer count: " << bags_count << endl;

    input_stream.close();

    return EXIT_SUCCESS;
}

void RemoveFromString(string &mainStr, const string &toErase)
{
    size_t pos = string::npos;
    // Search for the substring in string in a loop untill nothing is found
    while ((pos = mainStr.find(toErase)) != string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}