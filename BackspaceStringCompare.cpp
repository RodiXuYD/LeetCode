// BackspaceStringCompare.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int ls = S.length(), lt = T.length();
		char *s = new char[ls + 1], *t = new char[lt + 1];
		strcpy_s(s, ls+1, S.data());
		strcpy_s(t, ls+1, T.data());
		char x = '#';
		int sBack = 0, tBack = 0;
		bool sEnd = false, tEnd = false;
		while (ls > 0 || lt > 0)
		{
			if (s[ls - 1] != '#' && ls > 0)
			{
				if (sBack != 0)
				{
					ls--;
					sBack--;
				}
				else {
					if (tEnd)
						return false;
					else
						x = s[ls - 1];
				}
			}
			else
			{
				sBack++;
				ls--;
				sEnd = ls <= 0 ? true : false;
			}

			if (t[lt - 1] != '#' && lt > 0)
			{
				if (tBack != 0)
				{
					lt--;
					tBack--;
				}
				else {
					if (sEnd)
						return false;
					else {
						if (t[lt - 1] != x)
							return false;
						else
							ls--;
						sEnd = ls <= 0 ? true : false;
						lt--;
						tEnd = lt <= 0 ? true : false;
					}
				}
			}
			else {
				tBack++;
				lt--;
				tEnd = lt <= 0 ? true : false;
			}
		}
		return true;
	}

};

int main()
{
	string S = "ab#c", T = "ad#c";
	Solution so;
	if (so.backspaceCompare(S, T))
		cout << "true" << endl;
	else
		cout << "false" << endl;


	int x;
	cin >> x;
    return 0;
}

