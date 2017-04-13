#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
//Eric Sognefest
//0476698
//Deliverable 2
//10/19/15
int alpha [2][26];

using namespace std;
string Read (string file);
void Write (string cleaned);
void Count (string encrypted);

int main ()
{
string file,clean;
/* this is the file that you are trying to decrypted TODO fix the file extention */
cout<<"enter file name you would like to clean (Make sure you type the name correctly and include file extentions!!!!!)\n"
	<<"->: ";
cin>>file;

clean = Read(file);
Count(clean);
Write(clean);

return 0;
}

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
int ch=97;
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
outKey<<(char)alpha[0][x]<<" "<<alpha[1][x]<<"\n"; //out puts the freqency
}
}
