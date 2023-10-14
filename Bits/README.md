# BIT MAGIC

These are used for bit manipulation. This is much more efficient for than normal operations. 
For ex. To check if the number N is even or odd 
=> If the last bit of the N is SET then it is ODD else EVEN.
=> if((N & 1) != 0) ODD else EVEN

## Bitwise Operators

1. & operator
Takes 2 numbers as operands. It does AND operation on every bit of the 2 numbers.
Ex. A = 5, B = 3 => A & B = 1

2. | operator
Takes 2 numbers as operands. It does OR operation on every bit of the 2 numbers.
Result of OR is 1 if any of the 2 bits are 1.
Ex. A = 5, B = 3 => A | B = 7

3. ^ XOR operator

