#include <bits/stdc++.h>
#define ll long long
using namespace std;

// hash 1
int h1(string s)
{
	ll int hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash = (hash + ((int)s[i]));
		hash = hash % 15;
	}
	return hash;
}

// hash 2
int h2(string s)
{
	ll int hash = 1;
	for (int i = 0; i < s.size(); i++)
	{
		hash = hash + pow(19, i) * s[i];
		hash = hash % 15;
	}
	return hash;
}

bool lookup(bool* bitarray,  string s)
{
	int a = h1(s);
	int b = h2(s);

	if (bitarray[a] && bitarray[b])
		return true;
	else
		return false;
}

void insert(bool* bitarray, string s)
{
	if (lookup(bitarray, s))
		cout << s << " is probably already present" << endl;
	else
	{
		int a = h1(s);
		int b = h2(s);

		bitarray[a] = true;
		bitarray[b] = true;

		cout << s << " inserted" << endl;
	}
}

// Driver Code
int main()
{
	bool bitarray[15] = { false };
	string sarray[6]
		= { "grow", "cat",	 "dog",
			"dog", "grow", "tree"};
	for (int i = 0; i < 6; i++) {
		insert(bitarray, sarray[i]);
	}
	return 0;
}
