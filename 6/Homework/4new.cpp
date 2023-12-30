#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int sum = 0;
    int counter = 0;
    unordered_map<int, int> frequency; // 用于存储前缀和的频次

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        sum = (sum + num) % N; // 计算前缀和并取余
        if (sum == 0)
            counter++;             // 当前前缀和为0时，即找到一个符合条件的子数组
        counter += frequency[sum]; // 加上之前出现相同前缀和的次数
        frequency[sum]++;          // 更新前缀和的频次
    }

    cout << counter << endl;
    return 0;
}