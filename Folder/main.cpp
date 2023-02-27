#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

void lines_tracing(unsigned char *img, int width, int height, int channels, int lx, int ly, std::string filename);


void invert_image_colors(unsigned char *img, int width, int height, int channels, std::string filename);

// S4
void flip_horizontal(unsigned char *img, int width, int height, int channels, std::string filename);

void flip_vertical(unsigned char *img, int width, int height, int channels, std::string filename);

void rotate_90(unsigned char *img, int width, int height, int channels, std::string filename);

void crop_image(unsigned char *img, int width, int height, int channels, int top, int left, int bottom, int right, std::string filename);

void translate_image(unsigned char *img, int width, int height, int channels, int dx, int dy, std::string filename);

void resize_image(unsigned char *img, int width, int height, int channels, int new_width, int new_height, std::string filename);

void transvection_image(unsigned char *img, int width, int height, int channels, int dx, int dy, std::string filename);

void rotate_image(unsigned char *img, int width, int height, int channels, float angle_degrees, std::string filename);
//

// S5
void blur(unsigned char *img, int width, int height, int channels, float radius, std::string filename);

void erode(unsigned char *img, int width, int height, int channels, float radius, std::string filename);

void dilate(unsigned char *img, int width, int height, int channels, float radius, std::string filename);

void median_blur(unsigned char *img, int width, int height, int channels, float radius, std::string filename);

void min_max(unsigned char *img, int width, int height, int channels, int radius, std::string filename);

void local_contrast(unsigned char *img, int width, int height, int channels, int radius, float factor, std::string filename);

void adaptive_threshold(unsigned char *img, int width, int height, int channels, int radius, float threshold, std::string filename);

void sharpen(unsigned char *img, int width, int height, int channels, std::string filename);
//

void normalize_images(std::vector<unsigned char*> ListImages, int top, int left, int bottom, int right, std::string filename);

int main() {
    std::ifstream infile("process.txt");
    if (!infile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier process.txt" << std::endl;
        return 1;
    }
    std::string line;
    int width, height, channels;
    unsigned char *img;
    if(img == nullptr) {
        printf("img null");
    }
    while (std::getline(infile, line)) {
        std::string operation, filename, wordkey, temp1, temp2, temp3,temp4,temp5,temp6;
        std::stringstream ss(line);
        ss >> operation >> filename >> wordkey >> temp1 >> temp2 >> temp3>>temp4>>temp5>>temp6;

        if (operation == "load") {
            img = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            if(img == nullptr) {
                std::cerr << "Impossible de charger l'image " << filename << std::endl;
                return 1;
            }
            stbi_write_jpg(temp1.c_str(), width, height, channels, img, 100);


        }
        else if (operation == "save") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            stbi_write_jpg(temp1.c_str(), width, height, channels, tempImg, 100);
        }
        else if (operation == "lines_tracing") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            lines_tracing(tempImg, width, height, channels,tempdata,tempdata2,temp4);
        }
        else if (operation == "invert_image_colors") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            invert_image_colors(tempImg, width, height, channels,temp1);
        }
        else if (operation == "flip_horizontal") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            flip_horizontal(tempImg, width, height, channels,temp1);
        }
        else if (operation == "flip_vertical") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            flip_vertical(tempImg, width, height, channels,temp1);
        }
        else if (operation == "rotate_90") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            rotate_90(tempImg, width, height, channels,temp1);
        }
        else if (operation == "crop_image") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            int tempdata3 = std::stoi(temp3);
            int tempdata4 = std::stoi(temp4);
            crop_image(tempImg, width, height, channels,tempdata,tempdata2,tempdata3,tempdata4,temp6);
        }
        else if (operation == "translate_image") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            translate_image(tempImg, width, height, channels,tempdata,tempdata2,temp4);
        }
        else if (operation == "resize_image") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            resize_image(tempImg, width, height, channels,tempdata,tempdata2,temp4);
        }
        else if (operation == "transvection_image") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            transvection_image(tempImg, width, height, channels,tempdata,tempdata2,temp4);
        }
        else if (operation == "rotate_image") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            rotate_image(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "blur") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            blur(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "erode") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            erode(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "dilate") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            dilate(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "median_blur") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            median_blur(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "min_max") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            min_max(tempImg, width, height, channels,tempdata,temp3);
        }
        else if (operation == "local_contrast") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            local_contrast(tempImg, width, height, channels,tempdata,tempdata2,temp4);
        }
        else if (operation == "adaptive_threshold") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            int tempdata = std::stoi(temp1);
            int tempdata2 = std::stoi(temp2);
            adaptive_threshold(tempImg, width, height, channels,tempdata,tempdata,temp4);
        }
        else if (operation == "sharpen") {
            unsigned char *tempImg = stbi_load(filename.c_str(), &width, &height, &channels, 3);
            sharpen(tempImg, width, height, channels,temp1);
        }
        else if (operation == "normalize_images") {
           // normalize_images(img, width, height, channels,temp1);
        }
    }

    std::cout << "Excécution fini" << std::endl;
    return 0;
}

void normalize_images(std::vector<unsigned char*> image_files, int top, int left, int bottom, int right,std::string filename) {
    // Parcourir chaque fichier d'image dans la liste
    for (unsigned char* image_file : image_files) {
        int width, height, channels;
        // Charger l'image à partir du fichier
        if (image_file == nullptr) {
            std::cout << "Erreur lors du chargement de l'image " << image_file << std::endl;
            continue;
        }


        crop_image(image_file, width, height, channels, top, left, bottom, right,filename);


        stbi_image_free(image_file);

    }
}


void lines_tracing(unsigned char *img, int width, int height, int channels, int lx, int ly,std::string filename)
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] newImg;
}



void translate_image(unsigned char *img, int width, int height, int channels, int dx, int dy,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] newImg;
}
 


void rotate_image(unsigned char *img, int width, int height, int channels, float angle_degrees,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] newImg;

}

void transvection_image(unsigned char *img, int width, int height, int channels, int dx, int dy,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] newImg;
}

void resize_image(unsigned char *img, int width, int height, int channels, int new_width, int new_height,std::string filename) {
    unsigned char *resized_img = new unsigned char[new_width * new_height * channels];

    stbir_resize_uint8(img, width, height, 0, resized_img, new_width, new_height, 0, channels);


    img = resized_img;
    stbi_write_jpg(filename.c_str(), new_width, new_height, channels, img, 100);
    delete[] resized_img;
}



void crop_image(unsigned char *img, int width, int height, int channels, int top, int left, int bottom, int right,std::string filename) {
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
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] cropped_img;
}
void rotate_90(unsigned char *img, int width, int height, int channels,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] newImg;
}

void flip_vertical(unsigned char *img, int width, int height, int channels,std::string filename) {
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
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] line;
}

void flip_horizontal(unsigned char *img, int width, int height, int channels,std::string filename) {
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

    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
    delete[] line;
}

void invert_image_colors(unsigned char *img, int width, int height, int channels,std::string filename) {
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
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);

}

void blur(unsigned char *img, int width, int height, int channels, float radius,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void erode(unsigned char *img, int width, int height, int channels, float radius,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void dilate(unsigned char *img, int width, int height, int channels, float radius,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void median_blur(unsigned char *img, int width, int height, int channels, float radius,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void min_max(unsigned char *img, int width, int height, int channels, int radius,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void local_contrast(unsigned char *img, int width, int height, int channels, int radius, float factor,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void adaptive_threshold(unsigned char *img, int width, int height, int channels, int radius, float threshold,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);
}

void sharpen(unsigned char *img, int width, int height, int channels,std::string filename) {
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
    img = newImg;
    stbi_write_jpg(filename.c_str(), width, height, channels, img, 100);

}
