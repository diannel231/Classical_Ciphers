#include "Caesar.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{

  // Check if key is a number
  for(int i = 0; i < key.size(); i++)
  {
    if(!isdigit(key[i]))
    {
      cout << "Key must be a number." << endl;
      return false;
    }

  }

  cout << "Key is valid." << endl;
  keyText = stoi(key);
  return true;

}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted dtext string
 */
string Caesar::encrypt(const string& plaintext)
{
	string eText = plaintext;
  string cText;

  for(int i = 0; i < eText.length(); i++)
  {
    // Formula for Caesar: (plaintext + key) mod 26
    cText += (((eText[i]) + (keyText) - 'a') % 26) + 'a';
  }

	return cText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText)
{
	string dText = cipherText;
  string pText;

  for(int i = 0; i < dText.length(); i++)
  {
    // Formula for Caesar (decrypt): (26 + (ciphertext - key)) mod 26
    pText += ((26 + ((dText[i]) - (keyText) - 'a')) % 26) + 'a';
  }

	return pText;

}