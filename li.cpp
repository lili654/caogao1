#include <iostream>
using namespace std;

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y, int m, int d) //判断是否是合法日期
{
    if (d <= 0 || m <= 0 || m >= 13) return false;
    if (m != 2) 
    {
        if (d > months[m]) return false;
    }
    else
    {
        int days = months[2] + (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
        if (d > days) return false;
    }
    
    return true;
}

int flip(int x)
{
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

bool st1, st2;
int ans1, ans2;

int main()
{
    int n;
    cin >> n;
    
    for (int i = n + 1; i <= 89991231; i++)
    {
        int year = i / 10000, month = i % 10000 / 100, day = i % 100;
        if (check(year, month, day))
        {
            if (i % 10000 == flip(year) && !st1) 
                st1 = true, ans1 = i;
            
            if (i % 10000 == flip(year) && (month / 10 == day / 10) && (month % 10 == day % 10) && !st2) 
                st2 = true, ans2 = i;
        }
        
        if (st1 && st2) break;
    }
    
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}
