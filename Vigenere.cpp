#include "Vigenere.h"
#include <string>
#include <iostream>


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& key)
{

	// Check if key is letters only
	for (int i = 0; i < key.size(); i++)
	{
		if (!isalpha(key[i]))
		{
			cout << "Key must contain only letters,";
			return false;
		}

	}

	//Else return False
	cout << "Key is valid." << endl;
	keyText = key;
	return true;

}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted dtext string
 */
string Vigenere::encrypt(const string& plaintext)
{

	string eText = plaintext;
  string cText;
	// Create matrix

  // Modify key until it's as long as plaintext
  for(int i = 0; i < eText.length(); i++)
	{
    if(eText.length() == i)
		{
      i = 0;
    }

    if(keyText.length() == eText.length())
		{
      break;
    }

    keyText.push_back(keyText[i]);
  }

  for(int i = 0; i < eText.size(); i++)
	{
    // Formula for Vigenere: (plaintext + key) mod 26
		// Need to subtract with 'a' to fix ASCII
    int ct = (((eText[i] - 'a') + (keyText[i] - 'a')) % 26) + 'a';

		// Store ciphertext into string
    cText.push_back(ct);
  }

	return cText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText)
{
	string dText = cipherText;
  string pText;

  // Modify key until it's as long as plaintext
  for(int i = 0; i < dText.length(); i++)
	{
    if(dText.length() == i)
		{
      i = 0;
    }

    if(keyText.length() == dText.length())
		{
      break;
    }

    keyText.push_back(keyText[i]);
  }

  for(int i = 0; i < dText.size(); i++)
	{
    //Formula for Vigenere decrypt: (26 + (ciphertext + key)) mod 26
    int pt = ((26 + ((dText[i] - 'a') - (keyText[i] - 'a'))) % 26) + 'a';
    pText.push_back(pt);
  }

	return pText;

}