# classical-ciphers

Name: Dianne Lopez

Email: diannel@csu.fullerton.edu

Programming Language: C++

How to execute program:

Simply type 'make' at the terminal to compile the files first.

Then to use the program:

./cipher CIPHERNAME KEY ENC/DEC INPUTFILE OUTPUTFILE

Example: ./cipher PLF security ENC in.txt out.txt

CIPHERNAME: Choose between PLF, RTS, RFC, VIG, CES

KEY:
- PLF: Can be any text as long as its just lowercase letters
- RTS: Must be numbers only and must have 1 and can be in a consecutive sequence
  - Ex:
      - 4231 is valid because it can be sorted to 1234,
      - 2345 will be rejected,
      - 1112 will be rejected
- RFC: Can be any number
- VIG: Can be any text as long as its just lowercase letters
- CES: Can be any number

ENC/DEC: Type ENC to encrypt or DEC to decrypt

INPUTFILE: File to read input

OUTPUTFILE: File where the output will be written in

Extra Credit was not implemented