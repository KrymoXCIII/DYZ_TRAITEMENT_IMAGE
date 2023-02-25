#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"
#include <vector>
#include <algorithm>

/// WIP
void lines_tracing(unsigned char *img, int width, int height, int channels, int lx, int ly);
///

void invert_image_colors(unsigned char *img, int width, int height, int channels);

// S4
void flip_horizontal(unsigned char *img, int width, int height, int channels);

void flip_vertical(unsigned char *img, int width, int height, int channels);

void rotate_90(unsigned char *img, int width, int height, int channels);

void crop_image(unsigned char *img, int width, int height, int channels, int top, int left, int bottom, int right);

void translate_image(unsigned char *img, int width, int height, int channels, int dx, int dy);

void resize_image(unsigned char *img, int width, int height, int channels, int new_width, int new_height);

void transvection_image(unsigned char *img, int width, int height, int channels, int dx, int dy);

void rotate_image(unsigned char *img, int width, int height, int channels, float angle_degrees);
//

// S5
void blur(unsigned char *img, int width, int height, int channels, float radius);

void erode(unsigned char *img, int width, int height, int channels, float radius);

void dilate(unsigned char *img, int width, int height, int channels, float radius);

void median_blur(unsigned char *img, int width, int height, int channels, float radius);

void min_max(unsigned char *img, int width, int height, int channels, int radius);

void local_contrast(unsigned char *img, int width, int height, int channels, int radius, float factor);

void adaptive_threshold(unsigned char *img, int width, int height, int channels, int radius, float threshold);

void sharpen(unsigned char *img, int width, int height, int channels);
//

int main() {
    int width, height, channels;
    unsigned char *img = stbi_load("joconde.jpg", &width, &height, &channels, 3);
    if(img == nullptr) {
        printf("img null");
    }
    //rotate_image(img, width, height, channels, 40.8f);
    //local_contrast(img, width, height, channels,5,2);
    ///
    lines_tracing(img,width,height,channels,20,40);
    ///
    std::cout << "Excécution fini" << std::endl;
    return 0;
}

/// WIP
void lines_tracing(unsigned char *img, int width, int height, int channels, int lx, int ly)
{
    unsigned int bytePerPixel = channels;
    unsigned char *newImg = new unsigned char[width * height * bytePerPixel];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            unsigned char r = 255;
            unsigned char g = 255;
            unsigned char b = 255;

            unsigned char *pixel = newImg + (i + width * j) * bytePerPixel;

            if(i == lx || j == ly)
            {
                pixel[0] = (r);
                pixel[1] = (g);
                pixel[2] = (b);
            }
        }
    }

    stbi_write_jpg("joconde_crossed.jpg", width, height, channels, newImg, 100);
    
}
///

/*

            void erode(unsigned char *img, int width, int height, int channels, float radius) {
                unsigned char newImg[width*height*channels];
                unsigned int bytePerPixel = channels;
                for (int i = 0; i < width; i++) {
                    for (int j = 0; j < height; j++) {
                        unsigned char r = 255;
                        unsigned char g = 255;
                        unsigned char b = 255;
                        for (int x = -radius; x < radius+1; x++) {
                            for (int y = -radius; y < radius+1; y++) {
                                if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                                    int newI = x+i;
                                    int newJ = y+j;
                                    unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                                    if(pixelOffset1[0] < r && pixelOffset1[1] < g && pixelOffset1[2] < b) {
                                        r = pixelOffset1[0];
                                        g = pixelOffset1[1];
                                        b = pixelOffset1[2];
                                    }
                                }
                            }
                        }
                        unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
                        pixelOffset2[0] = (r);
                        pixelOffset2[1] = (g);
                        pixelOffset2[2] = (b);
                    }
                }
                stbi_write_jpg("joconde_erode.jpg", width, height, channels, newImg, 100);
            }
            

//////



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
 
 */

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

void blur(unsigned char *img, int width, int height, int channels, float radius) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int r = 0;
            int g = 0;
            int b = 0;
            int nbVoisin = 0;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        r += pixelOffset1[0];
                        g += pixelOffset1[1];
                        b += pixelOffset1[2];
                        nbVoisin++;
                    }
                }
            }
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = (unsigned char)(r/nbVoisin);
            pixelOffset2[1] = (unsigned char)(g/nbVoisin);
            pixelOffset2[2] = (unsigned char)(b/nbVoisin);
        }
    }
    stbi_write_jpg("joconde_blur.jpg", width, height, channels, newImg, 100);
}

void erode(unsigned char *img, int width, int height, int channels, float radius) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char r = 255;
            unsigned char g = 255;
            unsigned char b = 255;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        if(pixelOffset1[0] < r && pixelOffset1[1] < g && pixelOffset1[2] < b) {
                            r = pixelOffset1[0];
                            g = pixelOffset1[1];
                            b = pixelOffset1[2];
                        }
                    }
                }
            }
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = (r);
            pixelOffset2[1] = (g);
            pixelOffset2[2] = (b);
        }
    }
    stbi_write_jpg("joconde_erode.jpg", width, height, channels, newImg, 100);
}

void dilate(unsigned char *img, int width, int height, int channels, float radius) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char r = 0;
            unsigned char g = 0;
            unsigned char b = 0;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        if(pixelOffset1[0] > r && pixelOffset1[1] > g && pixelOffset1[2] > b) {
                            r = pixelOffset1[0];
                            g = pixelOffset1[1];
                            b = pixelOffset1[2];
                        }
                    }
                }
            }
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = (r);
            pixelOffset2[1] = (g);
            pixelOffset2[2] = (b);
        }
    }
    stbi_write_jpg("joconde_dilate.jpg", width, height, channels, newImg, 100);
}

void median_blur(unsigned char *img, int width, int height, int channels, float radius) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            std::vector<unsigned char> listR;
            std::vector<unsigned char> listG;
            std::vector<unsigned char> listB;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        listR.push_back(pixelOffset1[0]);
                        listG.push_back(pixelOffset1[1]);
                        listB.push_back(pixelOffset1[2]);
                    }
                }
            }
            sort(listR.begin(), listR.end());
            sort(listG.begin(), listG.end());
            sort(listB.begin(), listB.end());
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            int lenV = listR.size();
            if (lenV % 2 == 0) {
                pixelOffset2[0] = (listR[lenV/2] + listR[lenV/2 - 1]) / 2;
                pixelOffset2[1] = (listG[lenV/2] + listG[lenV/2 - 1]) / 2;
                pixelOffset2[2] = (listB[lenV/2] + listB[lenV/2 - 1]) / 2;
            } else {
                pixelOffset2[0] = listR[lenV/2];
                pixelOffset2[1] = listG[lenV/2];
                pixelOffset2[2] = listB[lenV/2];
            }
        }
    }
    stbi_write_jpg("joconde_median_blur.jpg", width, height, channels, newImg, 100);
}

void min_max(unsigned char *img, int width, int height, int channels, int radius) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char maxR = 0;
            unsigned char maxG = 0;
            unsigned char maxB = 0;
            unsigned char minR = 255;
            unsigned char minG = 255;
            unsigned char minB = 255;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if(x != 0 || y != 0) {
                        if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                            int newI = x + i;
                            int newJ = y + j;
                            unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                            if (pixelOffset1[0] > maxR && pixelOffset1[1] > maxG && pixelOffset1[2] > maxB) {
                                maxR = pixelOffset1[0];
                                maxG = pixelOffset1[1];
                                maxB = pixelOffset1[2];
                            }
                            if (pixelOffset1[0] < minR && pixelOffset1[1] < minG && pixelOffset1[2] < minB) {
                                minR = pixelOffset1[0];
                                minG = pixelOffset1[1];
                                minB = pixelOffset1[2];
                            }
                        }
                    }
                }
            }
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            if(pixelOffset2[0] > maxR && pixelOffset2[1] > maxG && pixelOffset2[2] > maxB) {
                pixelOffset2[0] = maxR;
                pixelOffset2[1] = maxG;
                pixelOffset2[2] = maxB;
            }
            else if (pixelOffset2[0] < minR && pixelOffset2[1] < minG && pixelOffset2[2] < minB) {
                pixelOffset2[0] = minR;
                pixelOffset2[1] = minG;
                pixelOffset2[2] = minB;
            }
            else {
                pixelOffset2[0] = pixelOffset1[0];
                pixelOffset2[1] = pixelOffset1[1];
                pixelOffset2[2] = pixelOffset1[2];
            }
        }
    }
    stbi_write_jpg("joconde_min_max.jpg", width, height, channels, newImg, 100);
}

void local_contrast(unsigned char *img, int width, int height, int channels, int radius, float factor) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int r = 0;
            int g = 0;
            int b = 0;
            int nbVoisin = 0;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        r += pixelOffset1[0];
                        g += pixelOffset1[1];
                        b += pixelOffset1[2];
                        nbVoisin++;
                    }
                }
            }
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = (unsigned char)(pixelOffset1[0]+(abs(pixelOffset1[0] - (r/nbVoisin)) * factor));
            pixelOffset2[1] = (unsigned char)(pixelOffset1[1]+(abs(pixelOffset1[1] - (g/nbVoisin)) * factor));
            pixelOffset2[2] = (unsigned char)(pixelOffset1[2]+(abs(pixelOffset1[2] - (b/nbVoisin)) * factor));
        }
    }
    stbi_write_jpg("joconde_local_contrast.jpg", width, height, channels, newImg, 100);
}

void adaptive_threshold(unsigned char *img, int width, int height, int channels, int radius, float threshold) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int r = 0;
            int g = 0;
            int b = 0;
            int nbVoisin = 0;
            for (int x = -radius; x < radius+1; x++) {
                for (int y = -radius; y < radius+1; y++) {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                        int newI = x+i;
                        int newJ = y+j;
                        unsigned char *pixelOffset1 = img + (newI + width * newJ) * bytePerPixel;
                        r += pixelOffset1[0];
                        g += pixelOffset1[1];
                        b += pixelOffset1[2];
                        nbVoisin++;
                    }
                }
            }
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            if(pixelOffset1[0] > (r/nbVoisin)+threshold && pixelOffset1[1] > (g/nbVoisin)+threshold && pixelOffset1[2] > (b/nbVoisin)+threshold) {
                pixelOffset2[0] = 255;
                pixelOffset2[1] = 255;
                pixelOffset2[2] = 255;
            }
            else {
                pixelOffset2[0] = 0;
                pixelOffset2[1] = 0;
                pixelOffset2[2] = 0;
            }
        }
    }
    stbi_write_jpg("joconde_adaptive_threshold.jpg", width, height, channels, newImg, 100);
}

void sharpen(unsigned char *img, int width, int height, int channels) {
    unsigned char newImg[width*height*channels];
    unsigned int bytePerPixel = channels;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char *pixelOffset1 = img + (i + width * j) * bytePerPixel;
            int r = 5*pixelOffset1[0];
            int g = 5*pixelOffset1[1];
            int b = 5*pixelOffset1[2];
            if(i-1 >= 0) {
                pixelOffset1 = img + (i-1 + width * j) * bytePerPixel;
                r -= pixelOffset1[0];
                g -= pixelOffset1[1];
                b -= pixelOffset1[2];
            }
            if(i+1 < width) {
                pixelOffset1 = img + (i+1 + width * j) * bytePerPixel;
                r -= pixelOffset1[0];
                g -= pixelOffset1[1];
                b -= pixelOffset1[2];
            }
            if(j-1 >= 0) {
                pixelOffset1 = img + (i + width * (j-1)) * bytePerPixel;
                r -= pixelOffset1[0];
                g -= pixelOffset1[1];
                b -= pixelOffset1[2];
            }
            if(j+1 < height) {
                pixelOffset1 = img + (i + width * (j+1)) * bytePerPixel;
                r -= pixelOffset1[0];
                g -= pixelOffset1[1];
                b -= pixelOffset1[2];
            }

            if(r>255)
                r=255;
            if(b>255)
                b=255;
            if(g>255)
                g=255;

            unsigned char *pixelOffset2 = newImg + (i + width * j) * bytePerPixel;
            pixelOffset2[0] = r<0 ? 0 : r;
            pixelOffset2[1] = g<0 ? 0 : g;
            pixelOffset2[2] = b<0 ? 0 : b;
        }
    }
    stbi_write_jpg("joconde_sharpen.jpg", width, height, channels, newImg, 100);
}