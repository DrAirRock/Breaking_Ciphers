#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#define
//Eric Sognefest
//started on apromatly 
//10/19/15

//yeah im sorry about the global its just inexcusable reall
int alpha [2][26];

using namespace std;

	/string Read (string file);
	/void Write (string cleaned);
	/void Count (string encrypted);

//RETURN THE MAXIMUM OF A TWO DIMETIONAL ARRAY
template<class T>
int my_max(T a[][], int start , int stop){

	int temp = 0;
	int i = 0;
	for (i = start; i < stop ; i++){
		if(!(a[][i] < a[][temp])){
				temp = i;
		}
	}
	return temp;
}

// READ AND CLEAN THE DATA YOU PASS THE IN
string Read (string file){
	//--------------------
	string encrypted;
	int i=0;
	bool isalph=0;
	//------------------------

	ifstream inDat;
	inDat.open(file);
	getline(inDat,encrypted); //takes what is in the file and saves it to a string called encrypted
	inDat.close();
	while(i != (encrypted.length())) //this is to check to see that the you havent reached the end of the string
	{
		if(isalph == isalnum(encrypted[i])) //checks to see if a charicter is not alpha numeric if it is not then it replaces that part of the stirng with a space filtering out punction, however if puction was used in a subsituion my progrm would not be able to decrypt the information
		{
		encrypted[i]=' ';
		}
	encrypted[i]=tolower(encrypted[i]); //chages all charicters to lowwer case
	i++;
	}
	return encrypted;
	}


	void Write(string cleaned){ /* this is a cleaned version of the file with no chage in cases and no punctiona TODO: possibly expand find a way to include punction */
	ofstream outDat;
	outDat.open("cleaned.txt");
	outDat<<cleaned;  //prints out cleaned string into a file called cleaned
	outDat.close();
	cout<<"Messeage stored in cleaned.txt!\n"
		  <<"Please press Enter To Continue...";
	getch(); //wait for any user input not just enter
}


void Count (string encrypted){

	int i=0;
	int alpha[2][27]; /* this is to contain the entire alphabet including the ' ' charater hence the lengh of 27 I hope i can cout lol */
	int x=0;
	int ch=97; /* ascii encoding of a */
	bool isalph=0;
	string bet="abcdefghijklmnopqrstuvwxyz "; //refrence string

	for(x; x<=26; x++)
	{
	alpha[0][x]= ch; // a-z on the top row
	alpha[1][x]=0; //secnond row all equil to zero
	ch++;
	}
	while (i < encrypted.size()){
		if(isalph == isalpha(encrypted[i])){ //if its not a letter its defined as a space more filtering just in case
		encrypted[i]=' ';
		 }
	x=bet.find(encrypted[i]); //using the std find function
	alpha[1][x] = alpha[1][x]+1; //letter in postion of refrence string added to the corrisponding position in arry
	i++;
	}

	ofstream outKey;
	outKey.open("freq.txt");
	for(int x=0; x<=25 ; x++){
		outKey<<(char)alpha[0][x]<<" "<<alpha[1][x]<<"\n"; //out puts the freqency (globals and type defineing all in one program thats what i get for sticking to primitive types
   }
}

void Write(string cleaned){
	ofstream outDat;
	outDat.open("cleaned.txt");
	outDat<<cleaned;  //prints out cleaned string into a file called cleaned
	outDat.close();
	cout<<"Messeage stored in cleaned.txt!\n"
		  <<"Please press Enter To Continue...";
	getch();
	}


//MAIN FUNCTION
int main ()
{
	string file,clean;
	/* this is the file that you are trying to decrypted TODO fix the file extention */
	cout<<"enter file name you would like to clean (Make sure you type the name correctly and include file extentions!!!!!)\n"
		<<"->: ";
	cin>>file;

	clean = Read(file);
	Count(clean); //edit the global alpha that is defined above you know where globals go
	Write(clean);

	return 0;
}



//TODO open the cleaned text file and using the frequencey replace the charicter with the most frequent mapping each lettter to a new letter
//Example wait i need what letters apper most commemly in the english language however
//TODO get the most common letters in the english language

//step one sort the alpha array based on the second row

int keyval [2][27]; // a map of the most fregent letters in my array to the most common in the english alpha bet


//step two read in the file engFre
ifstream inDat;
inDat.open(file);
getline(inDat,encrypted); //takes what is in the file and saves it to a string called encrypted
inDat.close();
while(i != (encrypted.length())) //this is to check to see that the you havent reached the end of the string
{
			if(isalph == isalnum(encrypted[i])) //checks to see if a charicter is not alpha numeric if it is not then it replaces that part of the stirng with a space filtering out punction, however if puction was used in a subsituion my progrm would not be able to decrypt the information
	{
	encrypted[i]=' ';
	}
encrypted[i]=tolower(encrypted[i]); //chages all charicters to lowwer case
i++;
}
return encrypted;
//end of main
}
