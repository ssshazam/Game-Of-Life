#include "field_print.h"

#include <stdio.h>
#include <unistd.h>

void print_field(unsigned char field[FIELD_SIZE][FIELD_SIZE])
{
    /*Вывод поля*/
    for (int i = 1; i < FIELD_SIZE - 1; i++) {
        for (int j = 1; j < FIELD_SIZE - 1; j++) {
            if (field[i][j] == 0) {
                printf("□ ");
            } else if (field[i][j] == 1) {
                printf("■ ");
            }
        }
        printf("\n");
    }
}

void clear_screen()
{
    /*Очистка терминала*/
    const char* clear_screen_ansi = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, clear_screen_ansi, 12);
}
