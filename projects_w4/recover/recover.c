#include <stdio.h>
#include <stdlib.h>
 
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8];
    int file_count = 0;

    // Read memory card block by block
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Check for JPEG signature (first three bytes are fixed, fourth varies)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file, if one is open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new filename
            sprintf(filename, "%02d.jpg", file_count);
            file_count++;

            // Open new JPEG file
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file %s.\n", filename);
                fclose(card);
                return 1;
            }
        }

        // Write to JPEG file if one is open
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    
    return 0;
 
}