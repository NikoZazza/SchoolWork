#include <string>
#include <iostream>
#include <fstream.h>

/**
Raccolta di funzioni per il cifrario di Cesare

Esempio:
Testo = LANEBBIAAGLIIRTICOLLI
Chiave = 3
Risultato = ODQHEELDDJOLLUWLFROOL
*/
namespace cesare{
	/**
	Descrizione:
		Questa funzione serve a codificare una frase secondo il cifrario di Cesare	
	Parametri:
		-value = rappresenta la frase da cifrare
		-key = rappresenta la chiave sulla quale bisogna codificare la frase
	Valore di ritorno: (string) ritorna la frase codificata
	*/
	string crypt(string value, int key);
	
	/**
	Descrizione:
		Questa funzione serve a decodificare una frase secondo il cifrario di Cesare	
	Parametri:
		-value = rappresenta la frase da decifrare
		-key = rappresenta la chiave sulla quale bisogna decodificare la frase
	Valore di ritorno: (string) ritorna la frase decodificata
	*/
	string decrypt(string value, int key);
	
	/**
	Descrizione:
		Questa funzione serve a decodificare una frase brutalmente, cioè forzando la frase tentando diverse chiavi, secondo il cifrario di Cesare	
	Parametri:
		-value = rappresenta la frase da decifrare
	Valore di ritorno: nessuno
	*/
	void bruteforce(string value);	
}

/**
Raccolta di funzioni per il cifrario di Vigenère

Esempio:
Testo = LANEBBIAAGLIIRTICOLLI
Chiave = CARDUCCI
Risultato = NAWHVDKICGCKCTVQEOCOC
*/
namespace vigenere{
	/**
	Descrizione:
		Questa funzione serve a codificare una frase secondo il cifrario di Vigenère
	Parametri:
		-value = rappresenta la frase da cifrare
		-key = rappresenta la chiave sulla quale bisogna codificare la frase
	Valore di ritorno: (string) ritorna la frase codificata
	*/
	string crypt(string value, int key);
	/**
	Descrizione:
		Questa funzione serve a decodificare una frase secondo il cifrario di Vigenère
	Parametri:
		-value = rappresenta la frase da decifrare
		-key = rappresenta la chiave sulla quale bisogna decodificare la frase
	Valore di ritorno: (string) ritorna la frase decodificata
	*/
	string decrypt(string value, int key);
}
/**
Raccolta di funzioni per la lettura/scrittura da/su file
*/
namespace file{
	/**
	Descrizione:
		Questa funzione serve a leggere la prima riga del file specificato
	Parametri:
		-dir = rappresenta il nome del file da leggere (deve essere specificata anche l'estenzione)
	Valore di ritorno: (string) ritorna la frase letta da file
	*/
	string readLine(string dir);
	
	/**
	Descrizione:
		Questa funzione serve a leggere la riga specificata del file
	Parametri:
		-dir = rappresenta il nome del file da leggere (deve essere specificata anche l'estenzione)
		-line = rappresenta la riga del file da leggere
	Valore di ritorno: (string) ritorna la frase letta da file
	*/
	string readLine(string dir, int line);
	
	/**
	Descrizione:
		Questa funzione serve a scrivere sulla prima riga del file specificato
	Parametri:
		-dir = rappresenta il nome del file da leggere (deve essere specificata anche l'estenzione)
		-value = rappresenta la stringa da scrivere su file
	Valore di ritorno: (bool) ritorna se la frase è stata scritta su file (true) o si è verificato un' errore (false)
	*/
	bool writeLine(string dir, string value);
}
/**
Descrizione:
	Questa funzione elimina tutti gli spazi in una stringa
Parametri
	-value = Rappresenta la strinda dove bisogna eliminare gli spazi
Valore di ritorno: (string) ritorna la stringa senza gli spazi

*/
string rmwSpaces(string value);
