#include <stdio.h>
#include <stdlib.h>
#include "PixelProcessor.h"
#include "BmpProcessor.h"




int main() {

    //READ
    FILE* fileIn = fopen("/home/chase/Documents/SER 334/Mod3/wb.bmp","rb");

    struct BMP_Header* header = (struct BMP_Header*)malloc(sizeof(struct BMP_Header));
    readBMPHeader(fileIn, header);

    struct DIB_Header* dib = (struct DIB_Header*) malloc(sizeof(struct DIB_Header));
    readDIBHeader(fileIn, dib);

    struct Pixel** pixels = (struct Pixel**) malloc(dib->height * sizeof(struct Pixel*));
    for (int i = 0; i < dib->height; i++) {
        pixels[i] = (struct Pixel *) malloc(dib->width * sizeof(struct Pixel));
    }
    readPixelsBMP(fileIn,pixels,dib->width,dib->height);

    //display
//    printf("sig: %c%c\n",header->sig[0],header->sig[1]);
//    printf("size: %d\n", header->size);
//    printf("r1: %d\n",header->reserve1);
//    printf("r2: %d\n",header->reserve2);
//    printf("offset: %d\n", header->offset);
//    printf("////////////DIB///////////////////////\n");
//    printf("Header Size: %d\n",dib->headerSize);
//    printf("width: %d\n",dib->width);
//    printf("height: %d\n",dib->height);
//    printf("planes: %d\n",dib->planes);
//    printf("bit per pixel: %d\n",dib->bitPerPixel);
//    printf("compression: %d\n",dib->compression);
//    printf("image size: %d\n",dib->imageSize);
//    printf("x pixels per meter: %d\n",dib->xPerMeter);
//    printf("y pixels per meter: %d\n",dib->yPerMeter);
//    printf("colors in color table: %d\n",dib->colors);
//    printf("important color count: %d\n",dib->colorCount);
    //read pixels
//    for (int i = (dib->height-1); i >= 0; i--) {
//        printf("|");
//        for (int j = 0; j < dib->width; j++) {
//            printf("R: %d  G: %d  B: %d | ",pixels[i][j].r, pixels[i][j].g, pixels[i][j].b);
//        }
//        printf("\n");
//    }

    //Shift
    colorShiftPixels(pixels,dib->width,dib->height,56,45,78);

    //WRITE
    FILE* out = fopen("/home/chase/Documents/SER 334/Mod3/out.bmp","wb");
    writeBMPHeader(out,header);
    writeDIBHeader(out,dib);
    writePixelsBMP(out,pixels,dib->width,dib->height);
    close(out);

    //FREE ALL THE THINGS
    for (int i = 0; i < dib->height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    free(header);
    free(dib);
    close(fileIn);

    return 0;
}
