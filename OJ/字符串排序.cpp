/*
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。如，输入： Type 输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。如，输入： BabA 输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。如，输入： By?e 输出： Be?y
用例：
A Famous Saying: Much Ado About Nothing (2012/8).  -》 A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std; //todo

// 开始思路，未优化方法
bool isNeedSortChar(int c, int &key)
{
    if (c <= 'z' && c >= 'a')
    {
        key = c;
        return true;
    }
    
    if (c <= 'Z' && c >= 'A')
    {
        key = c + 32;
        return true;
    }
    
    return false;
}

string getSortStrByRule(const string &orgStr)
{
    map<int, vector<char>> sortCache;
    
    int key;
    for (char c : orgStr)
    {
        if (isNeedSortChar(c, key))
        {
            sortCache[key].push_back(c);
        }
    }
    
    string sortedStr;
    for (auto iter = sortCache.begin(); iter != sortCache.end(); ++iter)
    {
        for (auto item : iter->second)
        {
            sortedStr += item;
        }       
    }
    
    int startSite = 0;
    string resStr;
    for (char c : orgStr)
    {
        if (isNeedSortChar(c, key))
        {
            resStr += sortedStr[startSite];
            ++startSite; 
        }
        else
        {
            resStr += c;        
        }
    }
    
    return resStr;
}

// 方法简化
string getSortStrByRule2(const string &orgStr)
{
    vector<char> sortCache;
    
    for (int i = 0; i < 26; ++i)
    {
        for (char c : orgStr)
        {
            if (i == c - 'a' || i == c - 'A')
            {
                sortCache.push_back(c);
            }
        }
    }
    
    string resStr;
    int startSite = 0;
    for (char c : orgStr)
    {
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        {
            resStr += sortCache[startSite++];
        }
        else
        {
            resStr += c;        
        }
    }
    
    return resStr;
}

int main()
{
    string inputStr;
    while (getline(cin, inputStr))
    {
        cout << getSortStrByRule2(inputStr) << endl;
    }
    
    return 0;
}

