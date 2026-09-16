#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];
    int image_count = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, 1, 512, raw_file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (image_count > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", image_count);
            img = fopen(filename, "w");
            image_count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }
    fclose(raw_file);

    return 0;
}
