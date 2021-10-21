class Solution {
public:
    int reverse(long int x)
{
    long int rev_num = 0;
    long int temp=x;
    
    if (x < 0)
        x = -1 * x;
    while (x > 0)
    {
        rev_num = rev_num * 10 + x % 10;
        x = x / 10;
    }
    if (rev_num <= pow(2, 31) - 1 && rev_num >= -pow(2, 31))
    {
        if (temp < 0)
        {
            return -1 * rev_num;
        }
        else
        {
            return rev_num;
        }
    }
    else
    {
        return 0;
    }
}
};