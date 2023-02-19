#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

void invert_image_colors(unsigned char *img, int width, int height, int channels);

void flip_horizontal(unsigned char *img, int width, int height, int channels);

void flip_vertical(unsigned char *img, int width, int height, int channels);

void rotate_90(unsigned char *img, int width, int height, int channels);

void crop_image(unsigned char *img, int width, int height, int channels, int top, int left, int bottom, int right);


void translate_image(unsigned char *img, int width, int height, int channels, int dx, int dy);

void resize_image(unsigned char *img, int width, int height, int channels, int new_width, int new_height);

void transvection_image(unsigned char *img, int width, int height, int channels, int dx, int dy);

void rotate_image(unsigned char *img, int width, int height, int channels, float angle_degrees);

int main() {
    int width, height, channels;
    unsigned char *img = stbi_load("joconde.jpg", &width, &height, &channels, 3);
    if(img == nullptr) {
        printf("img null");
    }
    rotate_image(img, width, height, channels, 40.8f);

    std::cout << "Excécution fini" << std::endl;
    return 0;
}

void rotate_image(unsigned char *img, int width, int height, int channels, float angle_degrees) {
    const float PI = 3.14159265358979323846;
    float angle_radians = angle_degrees * PI / 180.0;

    float cosine = cos(angle_radians);
    float sine = sin(angle_radians);

    unsigned int bytePerPixel = channels;
    unsigned char *newImg = new unsigned char[width * height * bytePerPixel];

    int cx = width / 2;
    int cy = height / 2;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int k = 0; k < bytePerPixel; k++) {
                int x = i - cx;
                int y = j - cy;

                int new_x = (int)(x * cosine - y * sine + 0.5);
                int new_y = (int)(x * sine + y * cosine + 0.5);

                int new_i = new_x + cx;
                int new_j = new_y + cy;

                if (new_i >= 0 && new_i < width && new_j >= 0 && new_j < height) {
                    unsigned char *srcPixel = img + (i + j * width) * bytePerPixel;
                    unsigned char *dstPixel = newImg + (new_i + new_j * width) * bytePerPixel;

                    *dstPixel++ = *srcPixel++;
                    *dstPixel++ = *srcPixel++;
                    *dstPixel++ = *srcPixel++;
                }
            }
        }
    }

    stbi_write_jpg("rotated_image.jpg", width, height, channels, newImg, 100);
    delete[] newImg;

}

void transvection_image(unsigned char *img, int width, int height, int channels, int dx, int dy) {
    unsigned int bytePerPixel = channels;
    unsigned char *newImg = new unsigned char[width * height * bytePerPixel];

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int k = 0; k < bytePerPixel; k++) {
                int new_i = i + dx;
                int new_j = j + dy;
                if (new_i >= 0 && new_i < width && new_j >= 0 && new_j < height) {
                    unsigned char *srcPixel = img + (i + j * width) * bytePerPixel;
                    unsigned char *dstPixel = newImg + (new_i + new_j * width) * bytePerPixel;

                    *dstPixel++ = *srcPixel++;
                    *dstPixel++ = *srcPixel++;
                    *dstPixel++ = *srcPixel++;
                }
            }
        }
    }

    stbi_write_jpg("transvection_image.jpg", width, height, channels, newImg, 100);
    delete[] newImg;
}

void resize_image(unsigned char *img, int width, int height, int channels, int new_width, int new_height) {
    unsigned char *resized_img = new unsigned char[new_width * new_height * channels];

    stbir_resize_uint8(img, width, height, 0, resized_img, new_width, new_height, 0, channels);

    stbi_write_jpg("resized_image.jpg", new_width, new_height, channels, resized_img, 100);

    delete[] resized_img;
}

void translate_image(unsigned char *img, int width, int height, int channels, int dx, int dy) {
    unsigned int bytePerPixel = channels;
    unsigned char *newImg = new unsigned char[width * height * bytePerPixel];

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int k = 0; k < bytePerPixel; k++) {
                int new_i = (i + dx) % width;
                int new_j = (j + dy) % height;

                unsigned char *srcPixel = img + (i + j * width) * bytePerPixel;
                unsigned char *dstPixel = newImg + (new_i + new_j * width) * bytePerPixel;

                *dstPixel++ = *srcPixel++;
                *dstPixel++ = *srcPixel++;
                *dstPixel++ = *srcPixel++;
            }
        }
    }

    stbi_write_jpg("translated_image.jpg", width, height, channels, newImg, 100);
    delete[] newImg;
}

void crop_image(unsigned char *img, int width, int height, int channels, int top, int left, int bottom, int right) {
    unsigned int bytePerPixel = channels;
    unsigned int cropped_width = right - left;
    unsigned int cropped_height = bottom - top;

    // Allouer l'espace mémoire pour la nouvelle image
    unsigned char *cropped_img = new unsigned char[cropped_width * cropped_height * bytePerPixel];

    // Copier les pixels de l'image originale vers la nouvelle image
    for (int i = 0; i < cropped_width; i++) {
        for (int j = 0; j < cropped_height; j++) {
            unsigned char *pixelOffset1 = img + ((i + left) + width * (j + top)) * bytePerPixel;
            unsigned char *pixelOffset2 = cropped_img + (i + cropped_width * j) * bytePerPixel;
            for (int k = 0; k < bytePerPixel; k++) {
                pixelOffset2[k] = pixelOffset1[k];
            }
        }
    }
    stbi_write_jpg("joconde_crop.jpg", cropped_width, cropped_height, channels, cropped_img, 100);

    delete[] cropped_img;
}
void rotate_90(unsigned char *img, int width, int height, int channels) {
    unsigned int bytePerPixel = channels;
    unsigned char *newImg = new unsigned char[width * height * bytePerPixel];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            unsigned char *pixelOffset2 = newImg + ((height - j - 1) + i * height) * bytePerPixel;
            pixelOffset2[0] = pixelOffset1[0];
            pixelOffset2[1] = pixelOffset1[1];
            pixelOffset2[2] = pixelOffset1[2];
        }
    }
    std::swap(width, height); // Inverser les dimensions de l'image
    delete[] img;
    img = newImg;
    stbi_write_jpg("rotated_90.jpg", width, height, channels, img, 100);
    delete[] newImg;
}

void flip_vertical(unsigned char *img, int width, int height, int channels) {
    unsigned int bytePerPixel = channels;
    unsigned char *line = new unsigned char[width * bytePerPixel];

    for (int j = 0; j < height / 2; j++) {
        for (int i = 0; i < width; i++) {
            // Échanger les pixels
            for (int k = 0; k < bytePerPixel; k++) {
                line[k] = img[(i + j * width) * bytePerPixel + k];
                img[(i + j * width) * bytePerPixel + k] = img[(i + (height - 1 - j) * width) * bytePerPixel + k];
                img[(i + (height - 1 - j) * width) * bytePerPixel + k] = line[k];
            }
        }
    }
    delete[] line;
    stbi_write_jpg("joconde_flip_vertical.jpg", width, height, channels, img, 100);
}

void flip_horizontal(unsigned char *img, int width, int height, int channels) {
    unsigned int bytePerPixel = channels;
    unsigned char *line = new unsigned char[width * bytePerPixel];

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width / 2; i++) {
            // Échanger les pixels
            for (int k = 0; k < bytePerPixel; k++) {
                line[k] = img[(i + j * width) * bytePerPixel + k];
                img[(i + j * width) * bytePerPixel + k] = img[((width - 1 - i) + j * width) * bytePerPixel + k];
                img[((width - 1 - i) + j * width) * bytePerPixel + k] = line[k];
            }
        }
    }
    delete[] line;
    stbi_write_jpg("joconde_flip.jpg", width, height, channels, img, 100);
}

void invert_image_colors(unsigned char *img, int width, int height, int channels) {
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            unsigned char r = pixelOffset1[0];
            unsigned char g = pixelOffset1[1];
            unsigned char b = pixelOffset1[2];

            unsigned char *pixelOffset2 = img + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = 255 - r;
            pixelOffset2[1] = 255 - g;
            pixelOffset2[2] = 255 - b;
        }
    }
    stbi_write_jpg("joconde_insert_image_color.jpg", width, height, channels, img, 100);
}


