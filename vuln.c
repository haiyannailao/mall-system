#include <stdio.h>
#include <string.h>

/* 一个带有典型漏洞的示例程序 */

/* 漏洞1：硬编码密码（应使用环境变量或配置文件） */
#define ADMIN_PASSWORD "123456"

int check_login(const char *input)
{
    return strcmp(input, ADMIN_PASSWORD) == 0;
}

int main(void)
{
    char name[8];
    char pwd[32];

    printf("username: ");
    /* 漏洞2：gets 不检查长度，输入超过 7 个字符就会栈溢出 */
    gets(name);

    printf("password: ");
    scanf("%31s", pwd);

    if (check_login(pwd)) {
        printf("welcome, %s\n", name);
    } else {
        printf("login failed\n");
    }
    return 0;
}
