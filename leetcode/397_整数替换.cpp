/*
题目 :
给定一个正整数 n，你可以做如下操作：

1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？
*/

class Solution { 
public:
    /*
    这个题目实际上要做的就是 消除 n 在二进制表达中的 1
    1111 -> 1
    1001 -> 1
    */
    int integerReplacement(int n) {
        int res = 0;
        long m = n;
        while (m != 1){
            if ((m & 1) == 0){ // 如若是偶数
                m = m >> 1;
            }else if (m == 3 || ((m >> 1) & 1) == 0){ // 如若 /2 后是偶数,或者是3
                m--;
            }else { // 如若最低两位是 11
                m++;
            }res++;
        }return res;
    }
};