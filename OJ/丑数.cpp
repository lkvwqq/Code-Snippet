/*
给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
输入：n = 6  true  6 = 2 × 3
输入：n = 8  true  8 = 2 × 2 × 2
输入：n = 14 false 14 不是丑数，因为它包含了另外一个质因数 7 。
输入：n = 1  true  1 通常被视为丑数。
*/

bool isUgly(int n) 
{
  if (0 >= n)
  {
      return false;
  }

  // 直接写法
  // while (0 == n % 2)
  // {
  //     n /= 2;
  // }

  // while (0 == n % 3)
  // {
  //     n /= 3;
  // }

  // while (0 == n % 5)
  // {
  //     n /= 5;
  // }

  // 优化下
  array<int, 3> uglyNumFactor{2, 3, 5};
  for (auto factor : uglyNumFactor)
  {
      while (0 == n % factor)
      {
          n /= factor;
      }
  }

  return n == 1;
}
