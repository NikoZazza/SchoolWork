#include <iostream>
#include <string>

//ascii table http://www.asciitable.com/
using namespace std;

string delSpaces(string str){
	string var = "";
	for(int i = 0; i < str.length(); i++){ //elimino gli spazi
	    char& chr = str[i];
		if(chr != ' ' && chr != '\n')
			var += chr;
	}
	return var;	
}

string crypt(string str, int key){
	str = delSpaces(str);
	
	string ret = "";
	for(int i = 0; i < str.length(); i++){
		char& chr = str[i];
		int c = (int) chr; //carattere ascii in dec
		
		if(c >= 65 && c <= 90) //carattere maiuscolo
			ret += (char)(c - 65 + key) % 26 + 65;
		
		else if(c >= 97 && c <= 122) //carattere minuscolo
			ret += (char)(c - 97 + key) % 26 + 97;			
		else //carattere sconosciuto
			ret += chr;
	}	
	return ret;
}
/**
LANEBBIAAGLIIRTICOLLI
ODQHEELDDJOLLUWLFROOL
*/

void decode(string str){
	str = delSpaces(str);
	char parole[] = {'A', 'E', 'I', 'O', 'U'};
	char last = ' ';
	
	for(int i = 0; i < str.length(); i++){
		char& chr = str[i];
		if(chr == last){
			for(int j = 0; j < 5; j++){
				int p = (int) parole[j]-(int)last;
				cout<<p<<endl;
				for(int k = 0; k < str.length(); k++){
					cout<<(char) ((int)str[k] - p);
				}		
				string ask = "";
				cout<<endl<<"La frase e' chiara? [Y/N] -> ";
				cin>>ask;
				if(ask == "Y" || ask == "y"){
					cout<<endl<<"La chiave e' in base "<<(int)parole[j] - (int)last<<endl;
					return;
				}				
			}			
		}			
		last = chr;
	}
	cout<<endl<<"Brute force enabled! "<<endl;
	
	for(int c = 1; c <= 26; c++){		
		for(int i = 0; i < str.length(); i++){
			char& chr = str[i];
			int y = (int)(((int)chr - 65 - c) % 26 + 65);
			//cout<<(int)chr<<" - 65 - "<<c<<" % 26 + 65 = "<<y;
			
			/*if(y < 65 || y > 90)
				cout<<y<<" range ";
			*/
			cout<<(char)y;
						
		}
		cout<<" con chiave in base "<<c<<endl;
	}	
	
}

int main(){
	cout<<"Gestione delle stringhe secondo il metodo di Cesare";
    while(true){
		int scelta = 0;
		string str = "";
		int key = 0;
		
		cout<<endl<<"========================================"<<endl<<"Scegli una delle seguenti opzioni: "<<endl;
		cout<<" 1. Codifica."<<endl<<" 2. Decodifica."<<endl<<" 3. Esci."<<endl<<"========================================"<<endl<<"->";
		while(scelta <= 0 || scelta > 3)
			cin>>scelta;
		
		switch(scelta){
			case 1:		
				while(str == ""){
					cout<<"Inserisci la frase da criptare -> ";
					std::getline(std::cin, str); //prende la riga anche con gli spazi
				}
				
				while(key <= 0 || key > 25){
					cout<<endl<<"Inserisci la chiave -> ";
					cin>>key;
				}
				cout<<"La tua frase criptata e' "<<crypt(str, key);
				break;
				
			case 2:
				while(str == ""){
					cout<<"Inserisci la frase da de-criptare -> ";
					std::getline(std::cin, str); //prende la riga anche con gli spazi
				}
				decode(str);			
				break;
				
			case 3:
				return 0;	
		}		
    }
	cout<<endl<<"Programma finito"<<endl;
	//system("PAUSE");
	return 0;
}
