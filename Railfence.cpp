#include "Railfence.h"
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
bool Railfence::setKey(const string& key)
{

  //Check if key is a number
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
string Railfence::encrypt(const string& plaintext)
{

	string eText = plaintext;
  string cText;

  // Determine the rows and columns needed for grid
  int row = keyText;
  int col = eText.length()/row;

  if(eText.length() % row)
  {
    col += 1;
  }

  char railGrid[row][col];

  int c = 0;

  // Fill the grid by column first
  for(int j = 0; j < col; j++)
  {
    for(int i = 0; i < row; i++)
    {
      railGrid[i][j] = eText[c];
      c++;
    }

  }

  // Then fill string with the grid by row
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      cText += railGrid[i][j];
    }

  }

	return cText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Railfence::decrypt(const string& cipherText)
{

	string dText = cipherText;
  string pText;

  int row = keyText;
  int col = dText.length()/row;

  if(dText.length() % row)
  {
    col += 1;
  }

  char railGrid[row][col];

  int c = 0;

  // Fill grid with ciphertext by row
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      railGrid[i][j] = dText[c];
      c++;
    }

  }

  // Read grid by column then store to string
  for(int j = 0; j < col; j++)
  {
    for(int i = 0; i < row; i++)
    {
      pText += railGrid[i][j];
    }

  }

	return pText;

}