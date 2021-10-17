class Solution {
    public int findComplement(int num) {
        // 找到最高位的 1 ，然后构造从该位开始到最低位的数字全部都为 1 的数，之后和 num 进行异或
        int highbit = 0;
        for(int i = 0; i <= 30; i++) {
            if((1 << i) > num) {
                highbit = i;
                break;
            }
        }
        int mask = (1 << (highbit)) - 1;
        if(highbit == 0 && num != 1) {
            mask = 0x7fffffff;
        }

        return mask ^ num;
    }
}