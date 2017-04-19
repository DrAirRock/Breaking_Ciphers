#ifndef SECRET_H
#define SECRET_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <cstring>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

// READ AND CLEAN THE DATA YOU PASS THE IN
string read(string file_name){
	int i=0;
	bool isalph=0;
	std::ifstream file(file_name.c_str());
       std::stringstream buffer;
       buffer << file.ifstream::rdbuf();
       std::string encrypted = buffer.str();
	while(i != (encrypted.length())) //this is to check to see that the you havent reached the end of the string
	{
		if(isalph == isalnum(encrypted[i]) && encrypted[i] != '\t' && encrypted[i] != '\n') //checks to see if a charicter is not alpha numeric if it is not then it replaces that part of the stirng with a space filtering out punction, however if puction was used in a subsituion my progrm would not be able to decrypt the information
		{
		encrypted[i]=' ';
		}
	encrypted[i]=tolower(encrypted[i]); //chages all charicters to lowwer case
	i++;
	}
	return encrypted;
}

//Wrtie out to file
void write(string str, string file_name){
	ofstream outDat;
	outDat.open(file_name);
	outDat<<str;
	outDat.close();
	cout<<"Messeage stored in " << file_name << "\n";
}

std::map<char, int> count_freq (string encrypted){
	cout << "\ncounting...\n";
	int i=0;
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

bool look(std::map<int, char> & look, int value){
		if(look.find(value) == look.end()){
			return false;
		}else return true;
}

bool look(std::map<char, char> & look, int value){
		if(look.find(value) == look.end()){
			return false;
		}else return true;
}

//Decryption function here we go math well simple math but still
void decrypt(string encrypted, std::map<char, int> & alpha,  string file_name){
	cout <<"decrypting...\n";
	string file = "./engFreq.txt";
	string engFreq;
	engFreq = "etaoinshrdlcumwfgypbvkjxqz";
	std::reverse(engFreq.begin(), engFreq.end());
	cout <<"reversed \n";
	int i = 0;
	std::map<char, char> mapping;
	std::map<int, char> revAlpha;
	std::map<char, int>::iterator itr_1;
	std::map<int, char>::iterator itr_2;
	cout<<"mapping\n";

	//This is reallly hacky code dont recamend doing it this way
	int count = 0;
	//swith key value pairs so it sorts by freqency and make sure there are no collisons -> they have to have some sort of order anyway
	for(itr_1 = alpha.begin(); itr_1 != alpha.end(); itr_1++)
	{
		
	   if(!look(revAlpha, (itr_1->second))){
	 	   revAlpha[itr_1->second] = itr_1->first;
		}else{
			int temp = itr_1 -> second;
			while(look(revAlpha, temp)){
				temp++;
				std::cerr <<"hey\n";
			}
			revAlpha[temp] = itr_1->first;
		}

		cout << itr_1->first << "   "  <<itr_1->second <<"\n";
	}
	cout<<std::endl;
	count = 0;
	i = 0;
	//take the new map sorted by freqency and replace it with the string containing how freqently letters show up.
	for(itr_2 = revAlpha.begin(); itr_2 != revAlpha.end() ; itr_2++)
	{
	   mapping[itr_2->second] = engFreq[i];
	   i++;
	}

	cout<<std::endl;
	i =0;
	cout << "replacing stuff\n";
	string decrypted = encrypted;
	
	while (i < encrypted.size()){

		if(look(mapping, decrypted[i])){
			
			auto x = mapping.find(decrypted[i]);
			decrypted[i] = char(x->second);
		
		}else{ decrypted[i] = decrypted[i];}

		i++;
	}

	write(decrypted, file_name);

}

#endif
