class Solution
{
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> th = {"", "Thousand", "Million", "Billion"};

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        int c = 0;
        string ans = "";

        while (num > 0)
        {
            string temp = "";
            if (num % 1000 != 0)
            {
                int n = num % 1000;
                if (n >= 100)
                {
                    temp += ones[n / 100] + " Hundred ";
                    n %= 100;
                }
                if (n >= 20)
                {
                    temp += tens[n / 10] + " ";
                    n %= 10;
                }
                if (n > 0)
                    temp += ones[n] + " ";

                ans = temp + th[c] + " " + ans;
            }

            num /= 1000;
            c++;
        }
        return ans.substr(0, ans.find_last_not_of(" ") + 1);
    };
};