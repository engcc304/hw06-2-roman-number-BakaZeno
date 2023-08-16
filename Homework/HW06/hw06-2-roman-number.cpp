/*
    ผู้ใช้กรอกตัวเลขเข้ามาในระบบ และให้คุณแปลงตัวเลขดังกล่าวให้เป็นตัวเลขโรมัน
    (โจทย์ข้อนี้ให้ใช้ For Loop เท่านั้น)

    Test case:
        8
    Output:
        8 = VIII

    Test case:
        4
    Output:
        4 = IV

    Test case:
        514
    Output:
        514 = DXIV

    Test case:
        929
    Output:
        929 = CMXXIX

*/
#include <stdio.h>
#include <string.h>

const char* convertToRoman(int num) {
    static char roman_num[100]; // เก็บผลลัพธ์ที่ได้ในรูปของสตริง
    int val[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    };
    const char* syb[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };
    roman_num[0] = '\0'; // ล้างสตริงที่เก็บผลลัพธ์
    int i = 0;
    while (num > 0) {
        for (int j = 0; j < num / val[i]; j++) {
            strcat(roman_num, syb[i]);
            num -= val[i];
        }
        i++;
    }
    return roman_num;
}

int main() {
    int number;
    printf("กรุณากรอกตัวเลข: ");
    scanf("%d", &number);

    const char* roman_result = convertToRoman(number);

    printf("%d = %s\n", number, roman_result);

    return 0;
}





