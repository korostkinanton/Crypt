#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;

class modAlphaCipher
{
private:
	wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
 	map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    int newkey; 
public:
    modAlphaCipher()=delete;
    //modAlphaCipher(const int& key);
    modAlphaCipher(const int& key) :newkey(key) {};   
    wstring encrypt(const wstring& open_st);   
    wstring decrypt(const wstring& cipher_st); 
};
