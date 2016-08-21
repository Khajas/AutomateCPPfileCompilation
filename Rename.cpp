#include<string>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
string FileNames();
int main (void){
	int Num_Files=0;
	ifstream _input;
	string files=FileNames();		//Function call to store the filenames into the text file called "tempt.txt"
	_input.open(files.c_str());
	string file;
	while (!_input.eof()){
        string file_Name("");
        if (getline(_input, file_Name))
        {
        	int f_length=file_Name.length();
			if(file_Name[0]=='P' && file_Name[f_length-3]=='c' && file_Name[f_length-2]=='p' && file_Name[f_length-1]=='p' && file_Name!="Script.cpp"){
			Num_Files++; //if(Num_Files%10==0) system("pause");
			cout<<"Processing: File #"<<Num_Files<<"\n\nName: "<<file_Name<<endl;
			file=file_Name.substr(10,8);
			cout<<"File Name: "<<file<<endl;
			string cmd0, cmd1;
			cmd0="copy \""+file_Name+"\" "+file+".cpp";
			cmd1="del \""+file_Name+"\"";
			system(cmd0.c_str());
			system(cmd1.c_str());
			cout<<string(69,'*')<<"\n\n"<<endl;
			}
		}
	}
	_input.close();
	cout<<"\n\n\n\nTotal Files Renamed: "<<Num_Files<<endl;
	return 0;
}
string FileNames(){
	string file_Name="Students.txt";
	system("dir /b /a-d> Students.txt");
	return file_Name;
}
