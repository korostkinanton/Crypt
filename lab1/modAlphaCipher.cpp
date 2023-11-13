#include "modAlphaCipher.h"
/*modAlphaCipher::modAlphaCipher(const int& key)
{
 	for (unsigned i=0; i<numAlpha.size(); i++) {
 		alphaNum[numAlpha[i]]=i;
 	}
 	//key = convert(skey);
}*/
wstring modAlphaCipher::decrypt(const wstring& cipher_st) 
{
    wstring n_s = cipher_st;
    int l0ng, position, line, a; 
    l0ng = cipher_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = newkey*line_number+colum_number; 
            if (position-1 < l0ng) {
                n_s[position-1] = cipher_st[a];
                a++;
            }
        }
    }
    return n_s;
}
wstring modAlphaCipher::encrypt(const wstring& open_st) 
{
    wstring n_s = open_st;
    int l0ng, line, position, a; 
    l0ng = open_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = colum_number+newkey*line_number;
            if (position-1 < l0ng) {
                n_s[a] = open_st[position-1];
                a++;
            }
        }
    }
    return n_s;
}
