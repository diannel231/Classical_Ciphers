#include <iostream>
#include <fstream>
#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "RowTransposition.h"
#include "Railfence.h"
#include "Vigenere.h"
#include "Caesar.h"

using namespace std;

int main(int argc, char** argv)
{
	/* REPLACE THIS PART WITH YOUR CODE
	 * THE CODE BELOW IS A SAMPLE TO
	 * ILLUSTRATE INSTANTIATION OF CLASSES
	 * THAT USE THE SAME INTERFACE.
	 */

	 string c = argv[1];
	 string key = argv[2];
	 string enc_dec = argv[3];
	 string input_file = argv[4];
	 string output_file = argv[5];

	 // Check and open input file
	 string file_text;
	 ifstream inFile(input_file);

	 if(inFile.is_open())
	 {
		 inFile >> file_text;
	 }

	 else
	 {
		 cout << "Error opening input file." << endl;
		 return 1;
	 }

	 inFile.close();

	 ofstream outFile(output_file);

	 // Playfair Cipher
	 if(c == "PLF")
	 {
		 /* Create an instance of the Playfair cipher */
		 CipherInterface* cipher = new Playfair();

		 /* Error checks */
		 if(!cipher)
		 {
			 fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			 __FILE__, __FUNCTION__, __LINE__);
			 exit(-1);
		 }

		 /* Set the encryption key */
		 if(cipher->setKey(key))
		 {
			 if(enc_dec == "ENC")
			 {
				 /* Perform encryption */
				 // string plaintext
				 string cipherText = cipher->encrypt(file_text);

				 // Write results to output text file
				 outFile << cipherText;
				 outFile.close();
			 }

			 else if(enc_dec == "DEC")
			 {
				/* Perform decryption */
				string plaintext = cipher->decrypt(file_text);

				// Write results to output text file
				outFile << plaintext;
				outFile.close();
			 }

		 }

	 }

	 // Row Transposition Cipher
	 else if(c == "RTS")
	 {
		 /* Create an instance of the Playfair cipher */
		 CipherInterface* cipher = new RowTransposition();

		 /* Error checks */
		 if(!cipher)
		 {
			 fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			 __FILE__, __FUNCTION__, __LINE__);
			 exit(-1);
		 }

		 /* Set the encryption key */
		 if(cipher->setKey(key))
		 {
			 if(enc_dec == "ENC")
			 {
				 /* Perform encryption */
				 // string plaintext
				 string cipherText = cipher->encrypt(file_text);

				 // Write results to output text file
				 outFile << cipherText;
				 outFile.close();
			 }

			 else if(enc_dec == "DEC")
			 {
				/* Perform decryption */
				string plaintext = cipher->decrypt(file_text);

				// Write results to output text file
				outFile << plaintext;
				outFile.close();
			 }

		 }

	 }

	 // Railfence Cipher
	 else if(c == "RFC")
	 {
		 /* Create an instance of the Playfair cipher */
		 CipherInterface* cipher = new Railfence();

		 /* Error checks */
		 if(!cipher)
		 {
			 fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			 __FILE__, __FUNCTION__, __LINE__);
			 exit(-1);
		 }

		 /* Set the encryption key */
		 if(cipher->setKey(key))
		 {
			 if(enc_dec == "ENC")
			 {
				 /* Perform encryption */
				 // string plaintext
				 string cipherText = cipher->encrypt(file_text);

				 // Write results to output text file
				 outFile << cipherText;
				 outFile.close();
			 }

			 else if(enc_dec == "DEC")
			 {
				/* Perform decryption */
				string plaintext = cipher->decrypt(file_text);

				// Write results to output text file
				outFile << plaintext;
				outFile.close();
			 }

		 }

	 }

	 // Vigenere Cipher
	 else if(c == "VIG")
	 {
		 /* Create an instance of the Playfair cipher */
		 CipherInterface* cipher = new Vigenere();

		 /* Error checks */
		 if(!cipher)
		 {
			 fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			 __FILE__, __FUNCTION__, __LINE__);
			 exit(-1);
		 }

		 /* Set the encryption key */
		 if(cipher->setKey(key))
		 {
			 if(enc_dec == "ENC")
			 {
				 /* Perform encryption */
				 // string plaintext
				 string cipherText = cipher->encrypt(file_text);

				 // Write results to output text file
				 outFile << cipherText;
				 outFile.close();
			 }

			 else if(enc_dec == "DEC")
			 {
				/* Perform decryption */
				string plaintext = cipher->decrypt(file_text);

				// Write results to output text file
				outFile << plaintext;
				outFile.close();
			 }

		 }

	 }

	 // Caesar Cipher
	 else if(c == "CES")
	 {
		 /* Create an instance of the Playfair cipher */
		 CipherInterface* cipher = new Caesar();

		 /* Error checks */
		 if(!cipher)
		 {
			 fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			 __FILE__, __FUNCTION__, __LINE__);
			 exit(-1);
		 }

		 /* Set the encryption key */
		 if(cipher->setKey(key))
		 {
			 if(enc_dec == "ENC")
			 {
				 /* Perform encryption */
				 // string plaintext
				 string cipherText = cipher->encrypt(file_text);

				 // Write results to output text file
				 outFile << cipherText;
				 outFile.close();
			 }

			 else if(enc_dec == "DEC")
			 {
				/* Perform decryption */
				string plaintext = cipher->decrypt(file_text);

				// Write results to output text file
				outFile << plaintext;
				outFile.close();
			 }

		 }

	 }

	return 0;

}
