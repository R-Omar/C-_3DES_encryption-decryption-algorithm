#include <sstream>
#include <list>

#include "headers/SequenceD.h"

#include "headers/Crypt.h"
#include "headers/Decrypt.h"

int main() {
	try {
		/*srand((int)time(NULL));*/
// ---------------------------------Main de test-------------------------------------------
		cout << "Bienvenue dans la console de test :)\n\n";

		cout << "Veuillez saisir le nom du fichier a crypter (qui contiendra du binaire) : ";
		string filename;
		cin >> filename;
		cout << "\n";

		string sKey;
		cout << "Veuillez saisir la premiere cle (8 caracteres) : ";
		cin >> sKey;
		while (sKey.length() != 8) {
			cout << "8 caracteres svp !!! Veuillez ressaisir : ";
			cin >> sKey;
		}
		cout << "\n";

		istringstream iKey(sKey);
		SequenceD<64> seKey1;
		iKey >> seKey1;

		cout << "Veuillez saisir la seconde cle (8 caracteres) : ";
		cin >> sKey;
		while (sKey.length() != 8) {
			cout << "8 caracteres svp !!! Veuillez ressaisir : ";
			cin >> sKey;
		}
		cout << "\n";
		iKey >> sKey;
		SequenceD<64> seKey2;
		iKey >> seKey2;

		Crypt crypt(seKey1, seKey2);
		crypt(filename);
		Decrypt decrypt(seKey1, seKey2);
		decrypt("encrypted_"+filename);

		cout << "Vos fichiers encryptes et decryptes se trouvent dans le repertoire ;-)\n";
	
		return 0;
	}
	catch (const std::exception& e) {
		cout << "Erreur: " << e.what() << '\n';
		return 1;
	}
	
}