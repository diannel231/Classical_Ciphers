#include "Playfair.h"
#include <string>
#include <iostream>


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key)
{
	for (int i = 0; i < key.size(); i++)
	{
		if (!isalpha(key[i]))
		{
			cout << "Key needs to contain only letters." << endl;
			return false;
		}

	}

	cout << "Key is valid." << endl;
	keyText = key;

	// Create matrix
	int keyLen = keyText.length();
	int row = 0;
	int col = 0;
	int markedAlpha[26];

	// Data going into markedAlpha will be subtracted by 'a' to fix ASCII

	// Skip 'j'
	markedAlpha['j' - 'a'] = 1;

	for(int i = 0; i < keyLen; i++)
	{
		// If letter in key is not already 1, make it 1
		// then, add it to the keyTable
		if(markedAlpha[keyText[i] - 'a'] != 1)
		{
			markedAlpha[keyText[i] - 'a'] = 1;
			keyTable[row][col] = keyText[i];
			col++;

			// Go to next row and reset column
			if(col == 5)
			{
				row++;
				col = 0;
			}

		}

	}

	// Fill the rest of table with latters by filling the value with
	// 0-25 + a (because ASCII), skip if it's already 1 in markedAlpha
	for(int c = 0; c < 26; c++)
	{
		if(markedAlpha[c] != 1)
		{
			keyTable[row][col] = c + 'a';
			col++;

			// Go to next row and reset column
			if(col == 5){
				row++;
				col = 0;
			}

		}

	}

	return true;

}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted dtext string
 */
string Playfair::encrypt(const string& plaintext)
{
	string eText = plaintext;

	// Prepare plaintext

	// Add 'x' between repeating letters
	for(int i = 0; i < eText.length(); i += 2)
	{
    if(eText[i] == eText[i+1])
		{
			eText.insert(i+1, "x");
    }

  }

	// Add 'x' in the end if it's uneven
  if(eText.length() % 2 != 0)
	{
    eText.push_back('x');
  }

	// Encryption starts
  for(int i = 0; i < eText.length(); i += 2)
	{
		// alphaA and alphaB will be the pairs
    int alphaA = eText[i];
    int alphaB = eText[i+1];

		// Turn all 'j' into 'i'
    if(alphaA == 'j'){
      alphaA = 'i';
    }

    else if(alphaB == 'j'){
      alphaB ='i';
    }

		// This will represent rows and columns of A and B
		int rowA, rowB, colA, colB;

		// Store the positions of A and B in the keyTable
    for(int x = 0; x < 5; x++)
		{
      for(int y = 0; y < 5; y++)
			{
        if(keyTable[x][y] == alphaA)
				{
          rowA = x;
          colA = y;
        }

        else if(keyTable[x][y] == alphaB)
				{
          rowB = x;
          colB = y;
        }

      }

    }

		// If the same row
    if(rowA == rowB)
		{
			// Change to letter on the right
      eText[i] = keyTable[rowA][(colA + 1) % 5];
      eText[i+1] = keyTable[rowB][(colB + 1) % 5];
    }

		// If the same column
    else if(colA == colB)
		{
			// Change to letter below
      eText[i] = keyTable[(rowA + 1) % 5][colA];
      eText[i+1] = keyTable[(rowB + 1) % 5][colB];
    }

		// Else change letter to in the same row and in column of the other letter
    else
		{
      eText[i] = keyTable[rowA][colB];
      eText[i+1] = keyTable[rowB][colA];
    }

  }

	return eText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText)
{

	string dText = cipherText;

	// Decrypting is about the same, only thing that mostly changes is when
	// the pair of letters are in either the same row or column
	// in which they change to the letter to the left or above them
	// Also need to add if statements in cases where the index value becomes
	// -1 because of subtraction. Mod just results in 0

	// Decryption starts
	for(int i = 0; i < dText.length(); i += 2)
	{
		int alphaA = dText[i];
		int alphaB = dText[i+1];

		if(alphaA == 'j')
		{
			alphaA = 'i';
		}

		else if(alphaB == 'j')
		{
			alphaB ='i';
		}

		int rowA, rowB, colA, colB;

		for(int x = 0; x < 5; x++)
		{
			for(int y = 0; y < 5; y++)
			{
				if(keyTable[x][y] == alphaA)
				{
					rowA = x;
					colA = y;
				}

				else if(keyTable[x][y] == alphaB)
				{
					rowB = x;
					colB = y;
				}

			}

		}

		if(rowA == rowB)
		{
			// Just in case the cols end up being -1 and need to jump to the last col
			if(((colA - 1) % 5) < 0)
			{
				dText[i] = keyTable[rowA][4];
				dText[i+1] = keyTable[rowB][(colB - 1) % 5];
			}
			else if(((colB - 1) % 5) < 0)
			{
				dText[i] = keyTable[rowA][(colA - 1) % 5];
				dText[i+1] = keyTable[rowB][4];
			}
			else
			{
				dText[i] = keyTable[rowA][(colA - 1) % 5];
				dText[i+1] = keyTable[rowB][(colB - 1) % 5];
			}

		}

		else if(colA == colB)
		{
			// Just in case the rows end up being -1 and need to jump to the last row
			if(((rowA - 1) % 5) < 0)
			{
				dText[i] = keyTable[4][colA];
				dText[i+1] = keyTable[(rowB - 1) % 5][colB];
			}
			else if(((rowB - 1) % 5) < 0)
			{
				dText[i] = keyTable[(rowA - 1) % 5][colA];
				dText[i+1] = keyTable[4][colB];
			}
			else
			{
				dText[i] = keyTable[(rowA - 1) % 5][colA];
				dText[i+1] = keyTable[(rowB - 1) % 5][colB];
			}

		}

		else
		{
			dText[i] = keyTable[rowA][colB];
			dText[i+1] = keyTable[rowB][colA];
		}

	}

	return dText;

}