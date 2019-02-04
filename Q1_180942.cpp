#include <iostream>
#include "Q1_180942.h"
#include <fstream>
using namespace std;
void readDataFromFile( gitHubUser * users, string filepath);
void setEduBckGrnd(gitHubUser &user);
int main()
{
	string path;
	cout<<"enter file path:"<<endl;
	cin>>path;
	gitHubUser *users=nullptr;
	readDataFromFile(users, path);

	return 0;

}
void readDataFromFile( gitHubUser * users, string filepath) // to read data from file and save into struct variables
{
	char e;
	ifstream fin;
	fin.open(filepath);
	int cases, folders;
	fin>>cases;
	fin.ignore();
	users=new gitHubUser[cases];
	for (int i=0; i<cases;i++)
	{
		getline(fin,users[i].firstName);
		getline(fin,users[i].userName);
		getline(fin,users[i].email);

		fin>>folders;
		
		users[i].folderName=new string[folders];
		for(int j=0; j<folders; j++)
		{
			getline(fin,users[i].folderName[j]);
		}
		cout<<users[i].firstName<<" Want to provide educational background? Press Y for Yes else enter any key"<<endl;
		cin>>e;
		if (e=='y'||e=='Y')
			setEduBckGrnd(users[i]);

	}	


}
void setEduBckGrnd(gitHubUser &users)
{
	cout<<users.firstName<<" Enter Institute name: "<<endl;
	getline(cin,*users.institute_name);
	cout<<users.firstName<<" Enter Qualification: "<<endl;
	getline(cin,*users.qualification_level);
}
