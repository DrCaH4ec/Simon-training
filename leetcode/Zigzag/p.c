#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *convert(char * s, int16_t numRows)
{
    int16_t size = strlen(s);
    if (numRows >= size || numRows == 1)
        return s;
    char *string_buf = malloc(sizeof(char) * size +1);
    int16_t current_pos = 0;
    int16_t counter = 0;
    for (int16_t i = 0; i < numRows; i++)
    {
        string_buf[counter++] = s[i];
        printf("\nletter  = %c space  = %d\n",string_buf[counter - 1], counter - 1);
        if (i != numRows - 1)
            current_pos = 2 * numRows - 2 - i;
        else
            current_pos = 3 * numRows - 3;
        while (current_pos < size)
        {
            string_buf[counter++] = s[current_pos];
            printf("\nletter  = %c space  = %d\n",string_buf[counter - 1], counter - 1);
            if (i != 0 && i != numRows -1)
                if (current_pos + 2 * i < size)
                    string_buf[counter++] = s[current_pos + 2 * i];
            current_pos += 2 * numRows - 2;
        }
    }
    stpcpy(s,string_buf);
    free(string_buf);
    return s;
}

int main(int argc, char const *argv[])
{
    int16_t size = 30;
    int16_t numRows = 2;
    char string[] = "PAYPALISHIRING";
    char *string_out;
    printf("\n\n");
    printf("In start\n%d\n",strlen(string));
    for (int16_t i = 0; i < strlen(string); i++)
        printf("%c ", string[i]);
    printf("].\n");
    //---------------------------------
    string_out = convert(string, numRows); //trash
    //---------------------------------
    printf("\n\n");
    printf("in result\n");
    for (int16_t i = 0; i < strlen(string); i++)
        printf("%c ", string[i]);
    printf("].\n");

    return 0;
}
