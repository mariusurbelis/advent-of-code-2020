#include <iostream>

using namespace std;

int main()
{
    int *testNumber;

    string testString = "adf3a0";

    testNumber = (int *)malloc(sizeof(int));

    long long answer = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;

    try
    {
        *testNumber = stoi(testString);
    }
    catch (invalid_argument const &e)
    {
    }

    cout << testString << " " << *testNumber << endl;

    free(testNumber);

    return 0;
}