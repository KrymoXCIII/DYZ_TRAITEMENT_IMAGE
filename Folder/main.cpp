#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char *img = stbi_load("joconde.jpg", &width, &height, &channels, 3);
    if(img == nullptr) {
        printf("img null");
    }
    else {
        unsigned char *img2 = img;
        unsigned bytePerPixel = channels;
        for(int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
                unsigned char r = pixelOffset1[0];
                unsigned char g = pixelOffset1[1];
                unsigned char b = pixelOffset1[2];

                unsigned char *pixelOffset2 = img2 + (i + width * j) * bytePerPixel;
                pixelOffset2[0] =  255-r;
                pixelOffset2[1] =  255-g;
                pixelOffset2[2] =  255-b;
            }
        }
        stbi_write_jpg("1.jpg", width, height, channels, img2, 100);
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
