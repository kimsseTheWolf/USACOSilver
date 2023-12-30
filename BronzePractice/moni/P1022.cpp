#include <bits/stdc++.h>
using namespace std;

string statement;
vector<string> leftSide = {};
vector<string> rightSide = {};

int main(void)
{
    cin >> statement;
    int N = statement.length();
    int pt = 0;
    string segement = "";
    bool isLeft = true;
    // process the statement
    while (pt < N)
    {
        if (statement[pt] == '+' or statement[pt] == '-' or statement[pt] == '*' or statement[pt] == '=')
        {
            // cache the segment into the vector
            if (statement[pt] == '=')
            {
                isLeft = false;
                leftSide.push_back(segement);
                segement = "";
                pt++;
                continue;
            }
            if (isLeft)
            {
                leftSide.push_back(segement);
            }
            else
            {
                rightSide.push_back(segement);
            }
            segement = "";
            segement.push_back(statement[pt]);
            pt++;
        }
        else
        {
            // append the number
            segement.push_back(statement[pt]);
            pt++;
        }
    }
    rightSide.push_back(segement);

    // move letters to left
    for (int i = 0; i < rightSide.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < rightSide[i].length(); j++)
        {
            if (rightSide[i][j] >= 65)
            {
                // means contains letters
                found = true;
                break;
            }
        }
        if (found)
        {

            if (rightSide[i][0] == '+')
            {
                rightSide[i][0] = '-';
            }
            else if (rightSide[i][0] == '-')
            {
                rightSide[i][0] = '+';
            }
            else
            {
                rightSide[i].insert(0, "-");
            }
            leftSide.push_back(rightSide[i]);
            rightSide[i] = "0";
        }
    }

    // move numbers to right
    for (int i = 0; i < leftSide.size(); i++)
    {
        int c = 0;
        for (int j = 0; j < leftSide[i].length(); j++)
        {
            if (leftSide[i][j] < 65)
            {
                // means contains letters
                c++;
            }
        }
        if (c == leftSide[i].length())
        {
            if (leftSide[i][0] == '+')
            {
                leftSide[i][0] = '-';
            }
            else if (leftSide[i][0] == '-')
            {
                leftSide[i][0] = '+';
            }
            else
            {
                leftSide[i].insert(0, "-");
            }
            rightSide.push_back(leftSide[i]);
            leftSide[i] = "0";
        }
    }

    int p = 0;
    while (p < leftSide.size())
    {
        if (leftSide[p] == "0")
        {
            leftSide.erase(leftSide.begin() + p);
        }
        else
        {
            p++;
        }
    }
    // parse constant on right
    int rSum = 0;
    for (int i = 0; i < rightSide.size(); i++)
    {
        rSum += stoi(rightSide[i]);
    }

    // parse constant on left
    int lSum = 0;
    char letter;
    for (int i = 0; i < leftSide.size(); i++)
    {
        letter = *(leftSide[i].end() - 1);
        leftSide[i].pop_back();
        lSum += stoi(leftSide[i]);
    }
    cout << fixed << setprecision(3) << letter << "=" << (double)rSum / lSum << endl;

    return 0;
}