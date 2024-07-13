class Solution
{
public:
   bool check(const string& s, int i, char ch)
   {
       return s[i -2] != ch && s[i - 1] != ch;
   }
   string smallestBeautifulString(string& s, int kk)
   {
       s = "00" + s + "00";
       int len = s.length() - 2;
       --kk;
       for (int i = s.length() - 3; i >= 2; i--)
       {
           if (s[i] - 'a' == kk)
           {
               continue;
           }
           else
           {
               // abcd
               // abda
               for (char ch = s[i]+1; ch <= 'a' + kk; ch++)
               {
                   if (s[i - 1] != ch && s[i - 2] != ch)
                   {
                       s[i] = ch;
                       for (int k = i + 1; k < len; k++)
                       {
                           for (char tr = 'a'; tr <= 'a'+k; ++tr)
                           {
                               if (check(s, k, tr))
                               {
                                   s[k] = tr;
                                   break;
                               }
                           }
                       }
                       string re = s.substr(2, len-2);
                       return re;
                   }
               }
           }
       }
       return "";
   }
};
class Solution
{
public:
   bool check(const string& s, int i, char ch)
   {
       return s[i -2] != ch && s[i - 1] != ch;
   }
   string smallestBeautifulString(string& s, int kk)
   {
       s = "00" + s + "00";
       int len = s.length() - 2;
       --kk;
       for (int i = s.length() - 3; i >= 2; i--)
       {
           if (s[i] - 'a' == kk)
           {
               continue;
           }
           else
           {
               // abcd
               // abda
               for (char ch = s[i]+1; ch <= 'a' + kk; ch++)
               {
                   if (s[i - 1] != ch && s[i - 2] != ch)
                   {
                       s[i] = ch;
                       for (int k = i + 1; k < len; k++)
                       {
                           for (char tr = 'a'; tr <= 'a'+k; ++tr)
                           {
                               if (check(s, k, tr))
                               {
                                   s[k] = tr;
                                   break;
                               }
                           }
                       }
                       string re = s.substr(2, len-2);
                       return re;
                   }
               }
           }
       }
       return "";
   }
};
