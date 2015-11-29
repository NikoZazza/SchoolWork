#include <iostream>
#include <string>

//ascii table http://www.asciitable.com/
using namespace std;

string crypt(string str, int key){
	string var = "";
	for(int i = 0; i < str.length(); i++){ //elimino gli spazi
	    char& chr = str[i];
		if(chr != ' ' && chr != '\n')
			var += chr;
	}
	cout<<endl<<var<<endl;
	string ret = "";
	for(int i = 0; i < var.length(); i++){
		char& chr = var[i];
		int c = (int) chr; //carattere ascii in dec
		if(c >= 65 && c <= 90){ //carattere maiuscolo
			if(c + 3 > 90)
				ret += (char)(c + 3 - 90);
			else
				ret += (char)(c + 3);
		}else{
			if(c >= 97 && c <= 122){ //carattere minuscolo
				if(c + 3 > 122)
					ret += (char)(c + 3 - 122);
				else
					ret += (char)(c + 3);				
			}else //carattere sconosciuto
				ret += chr;
		}	
	}	
	cout<<endl<<"Ascii encoded: "<<ret<<endl;
	var = "";
	int z = ret.length()/key;
	if(ret.length()%key != 0) 
	    z++;
	
	for(int j = 0; j < key; j++){
		for(int i = 1; i <= z; i++)
			var += ret[((key*i)-key)+j];
	}
	return var;
}

int main(){
    bool finito = false;
    while(!finito){
    	string str = "";
    	int key = 0;
    	while(str == ""){
    		cout<<"Inserisci la frase da criptare -> ";
    		std::getline(std::cin, str); //prende la riga anche con gli spazi
    	}
		
    	while(key <= 0){
    		cout<<endl<<"Inserisci la chiave -> ";
    		cin>>key;
    	}
    	cout<<"La tua frase criptata e' "<<crypt(str, key);
    	
    	string ask;
    	cout<<endl<<"Finire programma? [Y/N] -> ";
    	cin>>ask;
    	if(ask == "Y" || ask == "y")
    		finito = true;
    }
    cout<<endl<<"Copyright 2015 Zazza";
}