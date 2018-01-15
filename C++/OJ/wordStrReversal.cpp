/*
* 给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。 *
* 比如： （1） “hello xiao mi”-> “mi xiao hello”
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

string& wordStrReversal(const string &orgStr)
{
	deque<string> wordArr;

	size_t startPos = 0;
	size_t endPos = orgStr.find(" ", startPos);
	// 分隔取词
	while (string::npos != endPos)
	{
		wordArr.push_front(orgStr.substr(startPos, endPos-startPos));
		startPos = ++endPos;
		endPos = orgStr.find(" ", startPos);
	}

	wordArr.push_front(orgStr.substr(startPos));

	string res;
	for (auto &r : wordArr)
	{
		res += (r + " ");
	}
	// 去除末尾空格
	res.erase(res.find_last_not_of(" ") + 1);

	cout << res;

	return res;
}

int main()
{
	// 读取一行
	string inputStr;
	while (getline(cin,inputStr))
	{
		wordStrReversal(inputStr);
	}

    return 0;
}
