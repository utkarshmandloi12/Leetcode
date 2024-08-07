// Faster

// class Solution
// {
// public:
//     string intToRoman(int num)
//     {
//         string ans = "";

//         while (num >= 1000)
//         {
//             ans += "M";
//             num -= 1000;
//         }
//         while (num >= 900)
//         {
//             ans += "CM";
//             num -= 900;
//         }
//         while (num >= 500)
//         {
//             ans += "D";
//             num -= 500;
//         }
//         while (num >= 400)
//         {
//             ans += "CD";
//             num -= 400;
//         }
//         while (num >= 100)
//         {
//             ans += "C";
//             num -= 100;
//         }
//         while (num >= 90)
//         {
//             ans += "XC";
//             num -= 90;
//         }
//         while (num >= 50)
//         {
//             ans += "L";
//             num -= 50;
//         }
//         while (num >= 40)
//         {
//             ans += "XL";
//             num -= 40;
//         }
//         while (num >= 10)
//         {
//             ans += "X";
//             num -= 10;
//         }
//         while (num >= 9)
//         {
//             ans += "IX";
//             num -= 9;
//         }
//         while (num >= 5)
//         {
//             ans += "V";
//             num -= 5;
//         }
//         while (num >= 4)
//         {
//             ans += "IV";
//             num -= 4;
//         }
//         while (num >= 1)
//         {
//             ans += "I";
//             num--;
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> o = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> t = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> h = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> th = {"", "M", "MM", "MMM"};

        string ans = th[num / 1000] + h[(num % 1000) / 100] + t[(num % 100) / 10] + o[num % 10];
        return ans;
    }
};