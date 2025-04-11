#include <stdio.h>
#include "rcrng/rcrng.h"

int main() {
    uint16_t three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
    for (uint16_t i = 0; i < 10000; i++) {
        switch (rcrng(3, 9)) {
            case 3:
                three++;
                break;
            case 4:
                four++;
                break;
            case 5:
                five++;
                break;
            case 6:
                six++;
                break;
            case 7:
                seven++;
                break;
            case 8:
                eight++;
                break;
            case 9:
                nine++;
                break;
        }
    }
    printf("sample size 10 000 | range 3-9: %d %d %d %d %d %d %d\n", three, four, five, six, seven, eight, nine);
    uint16_t ones = 0, zeros = 0;
    for (uint16_t i = 0; i < 10000; i++) {
        if (rcrng(0, 1))
            ones++;
        else
            zeros++;
    }
    printf("sample size 10 000 | range 0-1: %d %d\n", ones, zeros);
    return 0;
}