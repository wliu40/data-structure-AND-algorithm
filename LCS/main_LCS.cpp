#include <iostream>
#include <string>
#include "LCS.h"
using namespace std;

int main()
{
	string s1 = "ABCBDAB";
	string s2 = "BDCABA";
	LCS lcs(s1, s2);
	lcs.solve();
	lcs.showMatrix();
	lcs.showTrack();
	lcs.showLCS();
}