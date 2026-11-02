#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    uint8_t buffer[512]; 
    FILE *output = NULL;
    int count = 0;
    char filename[8];
    while (fread(buffer, 512, 1, input) == 1)
    {
       if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
       {
        if (output != NULL)
        {
            fclose(output);
        }
        sprintf(filename, "%03i.jpg", count);
        output = fopen(filename, "wb");
        if (output == NULL)
        {
            printf("Could not create file.\n");
            fclose(input);
            return 1;
        }
        fwrite(buffer, 512, 1, output);
        count++;
       }else if (output != NULL)
        {
         fwrite(buffer, 512, 1, output);
        }
    }
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);
    return 0;
    
}