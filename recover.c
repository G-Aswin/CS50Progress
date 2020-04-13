#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checks if there is exactly one command-line arguement
    if (argc != 2)
    {
        printf("Usage : ./recover 'filename'\n");
        return 1;
    }

    //opens the memory card and names it "file"
    FILE *raw = fopen(argv[1], "r");
    FILE *filenew = NULL;
    int filecount = -1;
    BYTE *buffer = malloc(512);
    char *filename = malloc(10);
    while(fread(buffer, sizeof(BYTE), 512, raw) == 512)
    {
        //check if start of a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // yes? : first jpeg?
            if (filecount == -1)
            {
                filecount++;
                sprintf(filename, "%03i.jpg", filecount);
                filenew = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, filenew);
            }
            else
            {
                fclose(filenew);
                filecount++;
                sprintf(filename, "%03i.jpg", filecount);
                filenew = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, filenew);
            }
        }
        else if(filecount != -1)
        {
            fwrite(buffer, sizeof(BYTE), 512, filenew);
        }
    }
    fclose(filenew);
    fclose(raw);
    free(buffer);
}