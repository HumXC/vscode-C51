void Delay(unsigned int ms)
{
    while (ms--)
    {
        unsigned int j;
        for (j = 0; j < 130; j++)
            ;
    }
}
void HexToString(unsigned char hex, char *str)
{
    int i;
    str[0] = '['; // 开始符号
    for (i = 7; i >= 0; i--)
    {
        str[8 - i] = (hex & (1 << i)) ? '1' : '0'; // 获取每一位
        str[9 + (8 - i)] = ' ';                    // 添加空格
    }
    str[18] = ']';  // 结束符号
    str[19] = '\0'; // 字符串结束
}
void IntToString(long num, char *str)
{
    int i = 0;
    int isNegative = 0;

    // 处理负数
    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }

    // 转换数字为字符串
    do
    {
        str[i++] = (num % 10) + '0'; // 提取最后一位并转换为字符
        num /= 10;                   // 去掉最后一位
    } while (num > 0);

    if (isNegative)
    {
        str[i++] = '-'; // 添加负号
    }

    str[i] = '\0'; // 结束字符串

    // 反转字符串
    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}