#include <iostream>
#include "Q1_180942.h"
#include <fstream>
using namespace std;
void readDataFromFile( gitHubUser * users, string filepath);
void setEduBckGrnd(gitHubUser &users);
void print(gitHubUser &users);
void remove(gitHubUser &users);
void backup(gitHubUser *originalArry, gitHubUser *backupArry, int userCount);
int main()
{
	string path;
	cout<<"Enter file name (with path if needed): "<<endl;
	cin>>path;
	//path="Q1_180942.txt";
	gitHubUser *users=nullptr;
	readDataFromFile(users, path);
	//memory deallocation
	users=nullptr;
	delete users;
	return 0;
}
void readDataFromFile( gitHubUser * users, string filepath) // to read data from file 
{
	gitHubUser *backupArr=nullptr;
	cout<<"......Reading Data From File......."<<endl;
	char e;
	ifstream fin;
	fin.open(filepath);
	int cases=0;
	fin>>cases;
	fin.ignore();
	users=new gitHubUser[cases];
	for (int i=0; i<cases;i++)
	{
		getline(fin,users[i].firstName);
		getline(fin,users[i].userName);
		getline(fin,users[i].email);
		fin>>users[i].folders;
		fin.ignore();
		users[i].folderName=new string[users[i].folders];
		for(int j=0; j<users[i].folders; j++)
		{
			getline(fin,users[i].folderName[j]);
		}
		users[i].institute_name=nullptr;
		users[i].qualification_level=nullptr;
		cout<<"......Menu for "<<users[i].firstName<<"......."<<endl;
		cout<<"1) Add Educational Background"<<endl;
		cout<<"2) Print Data"<<endl;
		cout<<"3) Remove Educational Background"<<endl;
		cout<<"4) Create Backup"<<endl;
		cout<<"5) Continue reading from file"<<endl;
		//showing menu for every user
		while(1)
		{
			cout<<endl<<"Enter your choice: "<<endl;
			cin>>e;
			if (e=='1')
				setEduBckGrnd(users[i]);
			else if (e=='2')
				print(users[i]);
			else if (e=='3')
				remove(users[i]);
			else if (e=='4')
				backup(users,backupArr,i);
			else if (e=='5')
				break;
			else
				cout<<"Wrong choice"<<endl;
		}
		//memory deallocation
		users[i].institute_name=nullptr;
		users[i].qualification_level=nullptr;
		delete users[i].qualification_level;
		delete users[i].institute_name;
	}
	cout<<"..........File has been read............."<<endl;
	//memory deallocation
	backupArr=nullptr;
	delete backupArr;
}
void setEduBckGrnd(gitHubUser &users) //inputs educational background for a user
{
	cin.ignore();
	string str;
	cout<<users.firstName<<" Enter Institute name: "<<endl;
	getline(cin,str);
	users.institute_name=new string();
	*users.institute_name=str;
	cout<<users.firstName<<" Enter Qualification: "<<endl;
	getline(cin,str);
	users.qualification_level=new string();
	*users.qualification_level=str;
}
void print(gitHubUser &users) //prints data of user
{
	cout<<"........................"<<endl;
	cout<<"First Name: "<<users.firstName<<endl;
	cout<<"Username: "<<users.userName<<endl;
	cout<<"Email: "<<users.email<<endl;
	cout<<"No of Folders: "<<users.folders<<endl;
	for (int i=0;i<users.folders;i++)
	{
		cout<<"Folder "<<i+1<<" Name: "<<users.folderName[i]<<endl;
	}
	if (*users.institute_name!="\0")
	{
		cout<<"Institute Name: "<<*users.institute_name<<endl;
	}
	if (*users.qualification_level!="\0")
	{
		cout<<"Qualification Level: "<<*users.qualification_level<<endl;
	}
	cout<<"........................"<<endl;
}
void remove(gitHubUser &users) //remove educational background of user
{
	*users.institute_name="";
	*users.qualification_level="";
	cout<<"Educational background removed"<<endl;
}
void backup(gitHubUser *originalArray, gitHubUser *backupArray, int userCount) //creates a backup array
{
	backupArray=new gitHubUser[userCount];
	for(int i=0; i<userCount;i++)
	{
		backupArray[i].email=originalArray[i].email;
		backupArray[i].userName=originalArray[i].userName;
		backupArray[i].firstName=originalArray[i].firstName;
		backupArray[i].folders=originalArray[i].folders;
		backupArray[i].folderName=new string[backupArray[i].folders];
		for (int j=0; j<backupArray[i].folders;j++)
		{
			backupArray[i].folderName=originalArray[i].folderName;
		}
		backupArray[i].institute_name=originalArray[i].institute_name;
		backupArray[i].qualification_level=originalArray[i].qualification_level;
	}
	cout<<"Backup Array created"<<endl;
	//memory deallocation
	backupArray=nullptr;
	delete backupArray;
}