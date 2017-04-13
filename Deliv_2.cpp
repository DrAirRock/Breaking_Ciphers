#include <iostream>
#include <fstream>
#include <string>
//#include <ctype.h>
#include<conio.h>
//Eric Sognefest
//0476698
//Deliverable 2
//09/23/15

using namespace std;

int main ()
{
int i=0;
string encrypted, file;
bool alpha=0; 
cout<<"enter file name you would like to clean (Make sure you type the name correctly and include file extentions!!!!!)\n"
	<<"->: ";
	

cin>>file;

ifstream inDat;
inDat.open(file);
getline(inDat,encrypted); //takes what is in the file and saves it to a string called encrypted 
inDat.close();


while(i != (encrypted.length())) //this is to check to see that the you havent reached the end of the string
{

	if(alpha = !isalnum(encrypted[i])) //checks to see if a charicter is not alpha numeric if it is not then it replaces that part of the stirng with a space
	{
	encrypted[i]=' ';
	}
	
encrypted[i]=tolower(encrypted[i]); //chages all charicters to lowwer case
i++;
}

ofstream outDat;
outDat.open("cleaned.txt");
outDat<<encrypted;  //prints out cleaned string into a file called cleaned
outDat.close();

cout<<"Messeage stored in cleaned.txt!\n"
	  <<"Please press Enter To Continue...";
getch();

return 0;

}