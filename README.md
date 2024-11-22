# Cplus-Advance
Self-learning C++ more Advances.
### What is the difference between `signed char` and `unsigned char`?
* `signed char`: Represents integers from -128 to 127. It uses the most significant bit (MSB) to indicate the sign (0 for positive, 1 for negative).

* `unsigned char`: Represents integers from 0 to 255. It treats all bits as part of the value, allowing it to store a wider range of positive numbers.

### When would you use `unsigned char` instead of `signed char`?

* **Working with raw binary data:** When dealing with data like image pixels or network packets, where values should always be non-negative.

### What are the potential issues when using `char` without explicitly specifying `signed` or `unsigned`?
* The behavior of plain `char` can vary depending on the compiler and platform. It might be treated as `signed char` or `unsigned char` by default. This can lead to portability issues and unexpected results, especially when comparing characters or performing arithmetic operations.

### Example where using `signed char` instead of `unsigned char` might lead to an error?

``` c++
for (char i = 0; i < 255; i++) {
  // Do something with i
}
```
If `char` is treated as `signed char`, the loop will become **infinite**. This is because when `i` reaches 127, the next increment will overflow to -128, and the condition `i < 255` will always remain true.

### Example performing 5 + (-3) with Signed Numbers
**1. Represent the Numbers in Binary**
* **5 in binary:** 00000101
* **-3 in two's complement:**
  * Start with 3 in binary: 00000011
  * Invert the bits: 11111100
  * Add 1: 11111101

**2. Perform the Binary Addition**
```
     00000101   (5)
   + 11111101   (-3)
   ------------
  1 00000010 
```
* **Start from the rightmost bit:** 1 + 1 = 10. Write down the 0, carry-over the 1.
* **Continue adding each column:** Remember to include the carry-over from the previous column.
* **The leftmost '1' is the overflow bit.**

**3. Handling the Overflow Bit**
Since we're working with 8-bit numbers, we discard the **overflow** bit (the 9th bit). This leaves us with: 00000010

**4. Convert the Result to Decimal**
00000010 in binary is equal to 2 in decimal.
**Therefore, 5 + (-3) = 2**

**Example:**
```cpp
#include <iostream>
#include <bitset> // For printing binary representation

int main() {
  // Declare signed char variables (to allow negative values)
  signed char a = 5;
  signed char b = -3;

  // Calculate the sum
  signed char result = a + b;

  // Print the binary representations and the result
  std::cout << "  " << std::bitset<8>(a) << "  (" << static_cast<int>(a) << ")\n";
  std::cout << "+ " << std::bitset<8>(b) << "  (" << static_cast<int>(b) << ")\n";
  std::cout << "  --------\n";
  std::cout << "  " << std::bitset<8>(result) << "  (" << static_cast<int>(result) << ")\n";

  return 0;
}
```

### Why We Use 8 Bits?
Hardware components and instructions are optimized for handling 8-bit data = 1 byte

### What happen if the number bigger than 8 bits?
* It will be **overflow** and modulo 256, it's mean the remainder when a number is divided by 256.

**Example**
`200 + 100 = 300`
But 300 is too big to fit in an 8-bit unsigned number. So, we take the modulo 256 of the result:
`300 modulo 256 = 44`
So, in the context of 8-bit unsigned arithmetic, `200 + 100 = 44`
**Same**: `255 + 5 would become 4.`

```C++
#include <iostream>

int main() {
  // Declare unsigned char variables (guarantees 8 bits)
  unsigned char a = 200;
  unsigned char b = 100;

  // Calculate the sum
  unsigned char result = a + b; 

  // Print the result
  std::cout << "a (" << static_cast<int>(a) << ") + b (" 
            << static_cast<int>(b) << ") = " 
            << static_cast<int>(result) << std::endl; 

  return 0;
}
```

**Explanation:**

* **`unsigned char`:** This data type ensures we are working with 8-bit unsigned integers.
* **`a = 200` and `b = 100`:** We initialize our variables with the decimal values.
* **`unsigned char result = a + b;`:** This line performs the addition. Since `a` and `b` are unsigned chars, the addition will be performed modulo 256.
* **`static_cast<int>(...)`:** This is used to print the values as integers so that the output shows the decimal values instead of potentially interpreting the `char` values as characters.

**Output:**

```
a (200) + b (100) = 44
```


