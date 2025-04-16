Classical Cipher Implementations in C

This repository provides a comprehensive collection of 13 classical cryptographic algorithms implemented in C.
Classical ciphers represent the foundation of modern cryptography, showcasing the evolution of encryption from simple character substitutions to complex mathematical transformations. While these algorithms have been superseded by modern cryptographic standards, they remain invaluable for demonstrating fundamental concepts like substitution, transposition, polyalphabetic encryption, and early applications of linear algebra in cryptography.
Each implementation includes both encryption and decryption functionality with detailed comments explaining the underlying mathematical principles.

Ciphers Included:

1. Caesar Cipher
Description: Shifts each letter in the plaintext by a fixed number of positions in the alphabet.
Key: A single integer (shift value).
Usage: Simple substitution cipher, named after Julius Caesar.

2. Atbash Cipher
Description: Substitutes each letter with its mirror in the alphabet (A→Z, B→Y, etc.).
Key: No key required (fixed transformation).
Usage: Ancient Hebrew cipher, used in the Bible.

3. August Cipher
Description: A Caesar cipher with a fixed shift of 1.
Key: No key required (fixed shift).
Usage: Simplest form of the Caesar cipher.

4. Affine Cipher
Description: Uses a mathematical function (ax + b) mod 26 to transform each letter.
Key: Two integers a and b, where a is coprime to 26.
Usage: Combines multiplication and addition in modular arithmetic.

5. Vigenère Cipher
Description: Polyalphabetic substitution using a keyword to determine shift values.
Key: A keyword or phrase.
Usage: Considered unbreakable for 300 years until Kasiski's method.

6. Gronsfeld Cipher
Description: Similar to Vigenère but uses digits (0-9) instead of letters as the key.
Key: A sequence of digits.
Usage: Developed by Count Gronsfeld in the 17th century.

7. Beaufort Cipher
Description: A reciprocal cipher where encryption and decryption are identical.
Key: A keyword or phrase.
Usage: Created by Sir Francis Beaufort, used in rotor-based machines.

8. Autokey Cipher
Description: A polyalphabetic cipher that uses the plaintext itself to extend the key.
Key: A primer key (initial keyword).
Usage: Avoids repeating key patterns, making it more secure than Vigenère.

9. N-gram Analysis
Description: Tool for analyzing frequency of character sequences in text.
Usage: Essential for cryptanalysis and breaking classical ciphers.

10. Hill Cipher
Description: Uses matrix multiplication to encrypt blocks of letters.
Key: An invertible square matrix.
Usage: First practical polygraphic cipher, invented by Lester S. Hill in 1929.

11. Rail Fence Cipher
Description: Writes text in a zigzag pattern across rails and reads off by rows.
Key: Number of rails.
Usage: Simple transposition cipher used during the American Civil War.

12. Route Cipher
Description: Arranges text in a grid and reads it following a specific path.
Key: Grid dimensions and route pattern.
Usage: Various route patterns (spiral, zigzag) provide different security levels.

13. Myszkowski Cipher
Description: A columnar transposition that handles repeated letters in the keyword differently.
Key: A keyword with potential repeated letters.
Usage: Enhanced version of columnar transposition proposed in 1902.

Code Usage:

Each cipher implementation includes:
Functions for encryption and decryption
User input for plaintext/ciphertext and keys
Error handling for invalid keys or inputs