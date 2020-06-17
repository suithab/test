#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ifstream file1("a.txt");
	vector<double>ch;
	int i;
	double b;
	while(!file1.eof())
	{
		file1>>b;
		ch.push_back(b);
	}
	sort(ch.begin(),ch.end());
	file1.close();
	ofstream file2("b.txt");
	for(i=0;i<ch.size();i++)
	file2<<ch[i]<<" ";
	file2.close();
	return 0;
} 
