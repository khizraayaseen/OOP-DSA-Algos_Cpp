#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char s[10] ;
	cout << "Enter data for file";
	cin >> s;
	fstream myfile;
	myfile.open("myfile", ios::out);
	if (!myfile)
	{
		cout << "Error while creating the file";
	}
	else
	{

		cout << "File created successfully";
		myfile << s;
		myfile.close();
	}
	myfile.open("myfile", ios::in);
		if (!myfile)
		{
			cout << "Error";
		}
		else
		{
			cout << "File created successfully" << endl;
			cout << "Data written in file is ";
			myfile >> s;
			
				cout << s;
			
			myfile.close();
		}
	return 0;
}



