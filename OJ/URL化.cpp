/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
*/

// 
string replaceSpaces(string S, int length)
{
      if (S.size() < length)
      {
          return "";
      }

      string resStr;

      for (int i = 0; i < length; ++i)
      {
          if (' ' == S[i])
          {
              resStr += "%20";
          } 
          else
          {
              resStr.push_back(S[i]);
          }
      }

      return resStr;
}
