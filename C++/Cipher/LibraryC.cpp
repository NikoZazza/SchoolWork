#include "LibraryC.h"

namespace cesare{
	string crypt(string value, int key){
		value = rmwSpaces(value);
		for(int i = 0; i < value.length(); i++){
			if(value[i] >= 65 && value[i]  <= 90)//MAIUSCOLA
				int v = 65;
			else
				int v = 97;
			value[i] = (char)(value[i] - v + key) % 26 + v;
		}
		return value;		
	}
	
	string decrypt(string value, int key){
		value = rmwSpaces(value);
		for(int i = 0; i < value.length(); i++){
			if(value[i] >= 65 && value[i]  <= 90)//MAIUSCOLA
				int v = 65;
			else
				int v = 97;
			value[i] = (value[i] - v - key) % 26 + v;
			if(value[i] < v){
				if(v = 65)
					value[i] = value[i] - v + 90;
				else
					value[i] = value[i] - v + 122;
			}
			value[i] = (char)value[i];
		}		
		return value;
	}
	
	void bruteforce(string value){
		for(int i = 0; i <= 25; i++)
			cout<<decrypt(value, i);
	}
}
namespace vigenere{
	string crypt(string value, string key){
		value = rmwSpaces(value);
		key = rmwSpaces(key);
		int k = 0;
		for(int i = 0; i < value.length(); i++){
			if(k >= key.length())
				k = 0;
			if(value[i] >= 65 && value[i]  <= 90)
				int v = 65;
			else
				int v = 97;
			if(key[k] >= 65 && key[k]  <= 90)
				int t = 65;
			else
				int t = 97;
				
			value[i] = (char)((value[i] - v) + (key[k] - t)) % 26 + v;					
			k++;
		}
		return value;		
	}
	
	string decrypt(string value, string key){
		value = rmwSpaces(value);
		key = rmwSpaces(key);
		int k = 0;
		for(int i = 0; i < value.length(); i++){
			if(k >= key.length())
				k = 0;
			if(value[i] >= 65 && value[i]  <= 90)
				int v = 65;
			else
				int v = 97;
			if(key[k] >= 65 && key[k]  <= 90)
				int t = 65;
			else
				int t = 97;
				
			value[i] = ((value[i] - v) - (key[k] - t)) % 26 + v;		
			if(value[i] < v){
				if(v = 65)
					value[i] = value[i] - v + 90;
				else
					value[i] = value[i] - v + 122;
			}
			value[i] = (char) value[i];
			k++;
		}
		return value;		
	}
}
namespace file{
	string readLine(string dir){
		ifstream f(dir); 
	    string s;
	
	    if(!f) 
	        return "Il file non esiste!";
	
	    getline(f, s);
	    
	    f.close();
	    return s;		
	}
	
	string readLine(string dir, int line){
		ifstream f(dir); 
	    string s;
	
	    if(!f) 
	        return "Il file non esiste!";
		int l = 0;
	    while(getline(f, s)){
	    	if(line == l)
	    		break;
	    	l++;
	    }
	    
	    f.close();
	    if(line != l)
		 	return "Linea overflow";
	        
	    return s;
	}
	
	bool writeLine(string dir, string value){
		ofstream f(dir); 
	    if(!f)
	        return false;
    	f<<value<<endl;

  		f.close();
    	return true;	
	}	
}
string rmwSpaces(string value){
	string ret = "";
	for(int i = 0; i <= value.length(); i++){
		if(value[i] != ' ' && value[i] != '\r\n' && value[i] != '\n')
			ret += value[i];
	}
	return ret;
}
