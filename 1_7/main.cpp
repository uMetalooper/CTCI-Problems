#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "rotate_matrix.h"

int main()
{
    int width, height, channels;
    unsigned char *image = stbi_load("Lenna_(test_image).png", &width, &height, &channels, 0);
    if (image == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if (channels != 3) {
        printf("Only support image with 3 channels\n");
        exit(1);
    }
    int image_size = width * height * channels;
    int *image_int = new int[width * height];
    int index = 0;
    for (unsigned char *p = image; p != image + image_size; p = p + channels)
    {
        int pixel = 0;
        unsigned int r = *(p);
        unsigned int g = *(p + 1);
        unsigned int b = *(p + 2);
        pixel |= r;
        pixel |= g << 8;
        pixel |= b << 16;
        image_int[index] = pixel;
        index++;
    }

    bool result = Solution::rotateMatrix(image_int, width, height);

    printf("After solution\n");
    unsigned char *image_out = new unsigned char[width*height*channels];
    int index2 = 0;
    for (unsigned char *p = image_out; p != image_out + image_size; p = p + channels) {
        int pixel = image_int[index2];
        *(p) = pixel & 0xff;
        *(p+1) = (pixel & 0xff00) >> 8;
        *(p+2) = (pixel & 0xff0000) >> 16;
        index2++;
    }
    stbi_write_png("output.png", width, height, channels, image_out, width * channels);
}