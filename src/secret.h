#ifndef SECRET_H
#define SECRET_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <map>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

//The maximum fucntion of a two dimentional array
int my_max_2d(int a[][26], int start , int stop, int row){
	int temp = 0;
	//int i = 0;
	for (int i = start; i < stop ; i++){
		cout << "in for";
		if(!(a[row][i] < a[row][temp])){
				temp = i;
		}
	}
	return temp;
}

void selection_sort_2d(int a[][26], int start, int stop, int row, bool reverse){

	 //cout<<"enter function\n";
	int other_row;
	if( row == 1){ other_row = 0; } else{ other_row = 1; }
	 //cout<<"setting rows\n";
	if( reverse == true){
		while((stop - start) >= 2){

			 //cout<<"before max\n";
			int k =  my_max_2d( a , start, stop, row);
			cout <<" after k has been set !\n";
			std::swap( a[row][stop - 1], a[row][k]);
			std::swap(a[other_row][stop - 1] ,a[other_row][k] );
			stop--;

		}
	}else{
		while((stop - start) >= 2){

			int k =  my_max_2d( a , start, stop, row);
			std::swap(a[row][k] , a[row][stop - 1]);
			std::swap(a[other_row][k] , a[other_row][stop - 1]);
			stop--;

		}
	}

}


// READ AND CLEAN THE DATA YOU PASS THE IN
string read(string file){
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

//Wrtie out to file
void write(string cleaned, string file_name){
	ofstream outDat;
	outDat.open(file_name);
	outDat<<cleaned;  //prints out cleaned string into a file called cleaned
	outDat.close();
	cout<<"Messeage stored in " << file_name << "\n";
}


//void write_alpha(string file){

//	ofstream outkey;
//	outkey.open(file);
//	for(int x=0; x<=25 ; x++){
//		outkey<<(char)alpha[0][x]<<" "<<alpha[1][x]<<"\n"; //out puts the freqency (globals and type defineing all in one program thats what i get for sticking to primitive types
//   }

//}


//count the number of occurances of each letter in the file -> wirtes out to freq.txt
std::map<char, int> count_freq (string encrypted){
	cout << "\ncounting...\n";
	int i=0;
	int x=0;
	int ch=97; /* ascii encoding of a */
	bool isalph=0;
	std::map <char, int> freq;
	string bet="abcdefghijklmnopqrstuvwxyz"; //refrence string
	for (int q = 0; q < bet.length(); q++){
		freq[bet[q]] = 0;
	}

	while (i < encrypted.size()){
		if(isalph == isalpha(encrypted[i])){ //if its not a letter its defined as a space more filtering just in case
			encrypted[i]=' ';
		 }
		auto x = freq.find(encrypted[i]); //using the std find function
		x->second = x->second + 1;
		i++;
	}

	return freq;
}


//Decryption function here we go math well simple math but still
void decrypt(string encrypted, std::map<char, int> & alpha,  string file_name){
	cout <<"decrypting...\n";

	string file = "./engFreq.txt";
	string engFreq;
	engFreq = "etaoinshrdlcumwfgypbvkjxqz";
	std::reverse(engFreq.begin(), engFreq.end());
	cout <<"reversed \n";
	std::map<char, char> mapping;
	std::map<char, char> mapping_2;
	std::map<int, char> revAlpha;
	cout<<"debug flag 1\n";
	std::map<char, int>::iterator itr_1;
	std::map<int, char>::iterator itr_2;
	std::map<char, char>::iterator itr_3;
	cout<<"debug flag 2\n";
	int i = 0;
	cout<<"mapping\n";

	//swith key value pairs so it sorts by freqency
	for(itr_1 = alpha.begin(); itr_1 != alpha.end(); itr_1++)
	{

 	   revAlpha[itr_1->second] = itr_1->first;
	   cout << itr_1->first << itr_1->second <<"\n";

	}
	cout<<std::endl;

	for(itr_2 = revAlpha.begin(); itr_2 != revAlpha.end() ; itr_2++)
	{
	   mapping[itr_2->second] = engFreq[i];
	   cout << itr_2->first  << itr_2->second <<"\n";
	   i++;
	}

	cout<<std::endl;

	for(itr_3 = mapping.begin(); itr_3 != mapping.end(); itr_3++)
	{
	   mapping_2[itr_3->second] = itr_3->first;
	   cout << itr_3->first << itr_3->second <<"\n";
	}
	cout<<std::endl;

	for(itr_3 = mapping_2.begin(); itr_3 != mapping_2.end(); itr_3++)
	{
	   cout << itr_3->first << itr_3->second <<"\n";
	}
	cout<<std::endl;

	cout << "replacing stuff\n";
	while (i < encrypted.size()){

		auto x = mapping_2.find(encrypted[i]); //using the std find function
		encrypted[i] = x->second;
		i++;
	}

	write(encrypted, file_name);

}

#endif
