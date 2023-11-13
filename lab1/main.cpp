
#include "modAlphaCipher.h"
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s)
{
	for(const auto &c:s)
		if (!iswalpha(c))
			return false;
	return true;
}
int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	int key;
	wstring st;
	unsigned op;
	cout<<"Cipher ready. Input key(number): ";
	wcin>>key;
	if (!wcin.good()) {
		wcerr<<"key not valid\n";
		return 1;
 	}
 wcout<<L"Key loaded\n";
 modAlphaCipher cipher(key);
 do {
 	wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
 	wcin>>op;
 	if (op > 2) {
 		wcout<<L"Illegal operation\n";
 	} else if (op >0) {
 		wcout<<L"Cipher ready. Input text: ";
 		wcin>>st;
 		if (isValid(st)) {
 			if (op==1) {
 				wcout<<L"Encrypted text: "<<cipher.encrypt(st)<<endl;
 			} else {
 				wcout<<L"Decrypted text: "<<cipher.decrypt(st)<<endl;
 			}
 		} else {
 			wcout<<L"Operation aborted: invalid text\n";
		}
	 }
 } while (op!=0);
 return 0;
}
