//include the libraries iostream and fstream
#include <iostream>
#include <fstream>
#include <string>
//declare using namespace std
using namespace std;

//declare reverseFile that takes a filename as input
void reverseFile(string fileName){
	//create ifstream object readFile to extract info from
	ifstream readFile(fileName);
	//create ofstream object writeFile to write data to file
	ofstream writeFile("CSC450-mod5-reverse.txt");
	//declare string variable to hold input
	string fileLine;
	//iterate through code while readFile still has data
	while(getline(readFile, fileLine)){
		//declare variable reverseLine to store reversed input
		string reverseLine;
		//iterate through length of fileLine to reverse the string
		//and store in variable reverseLine
		for (int i = fileLine.length(); i >= 0; i--){
			reverseLine += fileLine[i];
		}
		//Write reverseLine to file
		writeFile << reverseLine;
		//write an end line to file
		writeFile << endl;

	}
}


//main function
int main(){
	//create ofstream object named file thats connected to the
	//txt file CSC450_CT5_mod5.txt and has a flag stating that it will
	//append information to the file
	ofstream writeFile("CSC450_CT5_mod5.txt", std::ios::app);
	ifstream readFile("CSC450_CT5_mod5.txt");
	//declare boolean variable, char variable, and a char array variable
	bool keepWriting = true;
	char closeFile;
	char writeString[200];
	//check if file is open
	if(writeFile.is_open()){
		//declare while loop while keepWriting is true
		while (keepWriting){
			//prompt user to enter data for file input
			cout << "Enter data for file: ";
			//get users input and store in writeString
			cin.getline(writeString, 200);
			//write writeString to file
			writeFile << writeString;
			//prompt user to decide if more info should be appended to file
			cout << "close file? (Y/N): ";
			//store user input in closeFile
			cin >> closeFile;
			//if user entered yes keepWriting will be assigned
			//false and while loop will terminate
			if (closeFile == 'Y'){
				keepWriting = false;
			}
			//clear input buffer
			cin.ignore();
		}
		writeFile.close();
		reverseFile("CSC450_CT5_mod5.txt");
		//close file

	}else {
		//if file can't be opened inform the user
		cout << "file can't be opened";
	}
	//return zero
	return 0;
}
