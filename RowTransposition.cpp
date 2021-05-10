#include "RowTransposition.h"
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
bool RowTransposition::setKey(const string& key)
{
  // Set up bool to chack if key at least has 1
  bool check_1 = false;

	for (int i = 0; i < key.size(); i++)
  {
    // Check if it's all digits
		if (!isdigit(key[i]))
    {
      cout << "Key must contain numbers only." << endl;
			return false;
		}

    else if(key[i] == '1')
    {
      check_1 = true;
    }

	}

  // Return false if there is no 1
  if(check_1 != true)
  {
    cout << "Key must contain '1'" << endl;
    return false;
  }

  // Check to see if key can be sorted into a consecutive sequence
  else
  {
    string keyString = key;
    string num = "123456789";

    sort(keyString.begin(), keyString.end());

    if(num.find(keyString) != std::string::npos)
    {
      cout << "Key is valid." << endl;
      keyText = key;
      return true;
    }

  }

	//Else return False
  cout << "Key must have a possible consecutive sequence." << endl;
	return false;

}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted dtext string
 */
string RowTransposition::encrypt(const string& plaintext)
{
	string eText = plaintext;
  string cText;

  int col = keyText.length();
  int row = eText.length()/col;

  // Add one more for extra letters
  if(eText.length() % col != 0)
  {
    row += 1;
  }

  char tMatrix[row][col];

  int c = 0;

  // Fill in matrix with plaintext
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      // Fill space with 'X'
      if(!isalpha(eText[c]))
      {
        tMatrix[i][j] = 'X';
      }

      else
      {
        tMatrix[i][j] = eText[c];
        c++;
      }

    }

  }

  // Vector would be used for encryption
  vector<int> key;

  for(int i = 0; i < keyText.length(); i++)
  {
    // Subtract 48 to get correct values (because ASCII)
    key.push_back(keyText[i] - 48);
  }

  // Iterator would determine which column to use to get letter
  for(vector<int>::iterator i = key.begin(); i != key.end(); i++)
  {
    // Iterator will determine which column will be stored in the string first
    for(int j = 0; j < row; j++)
    {
      cText += tMatrix[j][*i-1];
    }

  }

	return cText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const string& cipherText)
{

	string dText = cipherText;
  string pText;

  int col = keyText.length();
  int row = dText.length()/col;

  char tMatrix[row][col];

  int c = 0;

  // Fill grid with ciphertext
  for(int j = 0; j < col; j++)
  {
    for(int i = 0; i < row; i++)
    {
      tMatrix[i][j] = dText[c++];
    }

  }

  vector<int> key;

  for(int i = 0; i < keyText.length(); i++)
  {
    key.push_back(keyText[i] - 48);
  }

  char dMatrix[row][col];
  int d = 0;

  // Transfer values of matrix with ciphertext to decrypted matrix
  // Ex: If 4 is first in the key, the 4th column would become the first column
  // in the decrypted matrix
  for(vector<int>::iterator j = key.begin(); j != key.end(); j++)
  {
    for(int i = 0; i < row; i++)
    {
      dMatrix[i][*j-1] = tMatrix[i][d];
    }
    d++;
  }

  // Store contents of matrix by rows
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      pText += dMatrix[i][j];
    }

  }

	return pText;

}