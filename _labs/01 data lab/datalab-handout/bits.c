/* 
 * CS:APP Data Lab 
 * 
 * Peter Kan 087
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* ^(notAandB, notBandA), or = nand(~A, ~B) */
  
  int notX = ~x;
  int notY = ~y;
  int notXandY = notX & y;
  int notYandX = notY & x;
  int notnotXandY = ~notXandY;
  int notnotYandX = ~notYandX;
  int var1 = notnotXandY & notnotYandX;
  int result = ~var1;

  return result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* shift left the constant 1 by 31 and you will get tmin */
  return (1 << 31);

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*  */
  int tmin = x + 1;
  int neg1 = tmin + x;
  int zero = ~neg1;
  int pretzero = !tmin; //to exculde x = -1
  int result = zero + pretzero;
  
  return !result;


}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* I have no clue what it is about */
  int mask = 0xAA + (0xAA << 8);
  mask = mask + (mask << 16);

  return !((mask & x) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* flip all number then plus one */
  int result = ~x + 1;
  return result;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* 通过位级运算计算 x 是否在 0x30 - 0x39 范围内就是这个题的解决方案。那如何用位级
  运算来操作呢？我们可以使用两个数，一个数是加上比0x39大的数后符号由正变负，另一个数是
  加上比0x30小的值时是负数。这两个数是代码中初始化的 upperBound 和 lowerBound，然
  后加法之后获取其符号位判断即可。*/
  int tMin = 0x1 << 31;
  int tMax = ~tMin;
  int upperbound = ~(tMin | 0x39); // equals to tMax - 0x39
  int lowerbound = ~0x30 + 1; // equals to 0 - 0x30;
  int upperResult = tMin&(upperbound+x) >> 31; //will be zero if positive
  int lowerResult = tMin&(lowerbound+x) >> 31; // will be 0xFFFFFFF if negative
  
  return !(upperResult | lowerResult);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* 如果我们根据 x 的布尔值转换为全0或全1是不是更容易解决了，即 x==0 时位表示是全0的， 
  x!=0 时位表示是全1的。这就是1-2行代码，通过获取其布尔值0或1，然后求其补码（0的补码是本
  身，位表示全0；1的补码是-1，位表示全1）得到想要的结果。然后通过位运算获取最终值。*/
  
  // if x is 0, x remains zero, else x is 1
  x = !!x;
  // if x is 0, x remains 0, else x is -1 (all one)
  x = ~x + 1;
  // if true, (x & y) makes y, else, make zero, if false, (~x & z) makes z, else zero 
  // because x will turn into all one
  return (x & y) | (~x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* x <= y means y - x >= 0, */

  int negX = ~x + 1;
  int yminx = (y + negX) >> 31 & 1; //the reason of & 1 is because arthimetic shift

  int signx = x >> 31 & 1;
  int signy = y >> 31 & 1;

  int bitXor = signx ^ signy; 

  return (bitXor & signx) | ((!bitXor) & (!yminx));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* 逻辑非就是非0为1，非非0为0。利用其补码（取反加一）的性质，除了0和最小数（
  * 符号位为1，其余为0），外其他数都是互为相反数关系（符号位取位或为1）。0和最小
  * 数的补码是本身，不过0的符号位与其补码符号位位或为0，最小数的为1。利用这一点
  * 得到解决方法。  
  * 
  * x 小于 0 时结果为 1，否则检查 x + TMAX 是否进位为负数。
  * */
  
  int negX = x >> 31 & 1; //if negX = 1, x is negative
  int posX = (~x + 1) >> 31 & 1; // is posX == 1, x is positive

  return (negX | posX) ^ 1; //flip the result
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* 如果是一个正数，则需要找到它最高的一位（假设是n）是1的，再加上符号位，结果为n+1；
  * 如果是一个负数，则需要知道其最高的一位是0的（例如4位的1101和三位的101补码表示的是一
  * 个值：-3，最少需要3位来表示）。 
  * 
  * 这里我利用了之前 conditional 的做法，讲 x 为负的情况排除掉，统一处理正整数。统
  * 计位数可以采取二分法查找最高位的 1，但做了几轮测试就会发现二分法存在漏位的问题。
  * 不过这只在偶数位发生，奇数位不受影响。因此为了排除这个影响，我暴力地用 x |= (x << 1) 
  * 的办法让最高位的 1 左移 1 位。
  * */

  // 1. turn negative to positive (to avoid counting extra bit)
  int sign = x >> 31;
  // just get rid of MSB, and add 1 at last section
  x = (sign & ~x) | (~sign & x);

  int b16, b8, b4, b2, b1, b0; //total 31, you can choose any you want
  b16 = !!(x >> 16) << 4; //to indicate the number
  x = x >> b16; //if there's 16 bits, shift it
  b8 = !!(x >> 8) << 3;
  x = x >> b8;
  b4 = !!(x >> 4) << 2;
  x = x >> b4;
  b2 = !!(x >> 2) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  b0 = x;

  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /* 首先排除无穷小、0、无穷大和非数值NaN，此时浮点数指数部分（真正指数+bias）
   * 分别存储的的为0，0，,255，255。这些情况，无穷大和NaN都只需要返回参数（ [公式] ），
   * 无穷小和0只需要将原数乘二再加上符号位就行了（并不会越界）。剩下的情况，如果指数+1之后为
   * 指数为255则返回原符号无穷大，否则返回指数+1之后的原符号数。   */

  unsigned exp = (uf << 1) >> 24;
  unsigned frac = uf << 9 >> 9;
  unsigned msb = uf >> 31 << 31;
  if (exp == 0) return msb | uf << 1;
  if (exp == 255) return uf;
  exp += 1;
  return msb | (exp << 23) | frac;

}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  
  unsigned exp = (uf << 1) >> 24;
  unsigned frac = uf << 9 >> 9;
  unsigned msb = uf >> 31;
  int e = (uf << 1) >> 24;
  e = e - 127;
  if (e < 0) return 0;
  if (e > 31) return 0x80000000u;

  if (msb == 1) return -(1 << e);
  if (msb == 0) return 1 << e;

  return 0; // it shouldn't be triggered.
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  
  if (x < 0) return 0;
  if (x + 127 < 0) return (255 << 23);

  unsigned e, exp;
  e = x;
  exp = e + 127;

  if (exp >= 255) return (255 << 23);
  if (exp < 127) return 0;

  return exp << 23;
}
