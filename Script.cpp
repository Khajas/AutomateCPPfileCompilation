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
	 while (!_input.eof())
    {
        string file_Name("");
        if (getline(_input, file_Name))
        {
        	int f_length=file_Name.length();
			if(file_Name[f_length-3]=='c' && file_Name[f_length-2]=='p' && file_Name[f_length-1]=='p' && file_Name!="Script.cpp"){
			Num_Files++;
			cout<<"Processing: File #"<<Num_Files<<"\n\nName: "<<file_Name<<endl;
			file=file_Name.substr(0,f_length-4);
		string cmd0, cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7;
		cmd0="mkdir "+file;
		cmd1="g++ -o "+file+" "+file_Name;
		cmd2=file+".exe<input1.txt>"+file+"\\Output1.txt";
		cmd3=file+".exe<input2.txt>"+file+"\\Output2.txt";
		cmd4=file+".exe<input3.txt>"+file+"\\Output3.txt";
		cmd5=file+".exe<input4.txt>"+file+"\\Output4.txt";
		cmd6="copy "+file+".cpp "+file;
		cmd7="move "+file+".exe "+file;
		if(file_Name!="Script.cpp" || file_Name!="Rename.cpp"){
				system(cmd0.c_str());				cout<<"\nCreated directory: "<<file<<endl;
				system(cmd1.c_str());				cout<<"\nCompilation attempted for: "<<file_Name<<endl;
				system(cmd2.c_str());				cout<<"\nFirst input file supplied. Output saved!"<<endl;
				system(cmd3.c_str());				cout<<"Second input file supplied. Output saved!"<<endl;
				system(cmd4.c_str());				cout<<"Third input file supplied. Output saved!"<<endl;
				system(cmd5.c_str());				cout<<"Fourth input file supplied. Output saved!"<<endl;
				system(cmd6.c_str());				cout<<"\nSource file copied to directory: "<<file<<endl;
				system(cmd7.c_str());				cout<<"\nExecutable file moved to directory: "<<file<<endl;
				cout<<string(69,'*')<<"\n\n"<<endl;
			}
		}
	}    
        }
	_input.close();
	cout<<"\n\n\n\nTotal Files Compiled: "<<Num_Files<<endl;
	return 0;
}
string FileNames(){
	string file_Name="Students.txt";
	system("dir /b /a-d> Students.txt");
	return file_Name;
}
