#include "PixelProcessor.h"
#include "BmpProcessor.h"

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header) {
    fread(header->sig, sizeof(char) * 2, 1, file);
    fread(&header->size, sizeof(int),1,file);
    fread(&header->reserve1, sizeof(short ),1,file);
    fread(&header->reserve2, sizeof(short ),1,file);
    fread(&header->offset, sizeof(int),1,file);
}

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header) {
    fwrite(&header->sig, sizeof(char) * 2, 1, file);
    fwrite(&header->size, sizeof(int),1,file);
    fwrite(&header->reserve1, sizeof(short ),1,file);
    fwrite(&header->reserve2, sizeof(short ),1,file);
    fwrite(&header->offset, sizeof(int),1,file);
}

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header) {
    fread(&header->headerSize, sizeof(int), 1, file);
    fread(&header->width, sizeof(int), 1, file);
    fread(&header->height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(short), 1, file);
    fread(&header->bitPerPixel, sizeof(short), 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->imageSize, sizeof(int), 1, file);
    fread(&header->xPerMeter, sizeof(int), 1, file);
    fread(&header->yPerMeter, sizeof(int), 1, file);
    fread(&header->colors, sizeof(int), 1, file);
    fread(&header->colorCount, sizeof(int), 1, file);
}

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header) {
    fwrite(&header->headerSize, sizeof(int), 1, file);
    fwrite(&header->width, sizeof(int), 1, file);
    fwrite(&header->height, sizeof(int), 1, file);
    fwrite(&header->planes, sizeof(short), 1, file);
    fwrite(&header->bitPerPixel, sizeof(short), 1, file);
    fwrite(&header->compression, sizeof(int), 1, file);
    fwrite(&header->imageSize, sizeof(int), 1, file);
    fwrite(&header->xPerMeter, sizeof(int), 1, file);
    fwrite(&header->yPerMeter, sizeof(int), 1, file);
    fwrite(&header->colors, sizeof(int), 1, file);
    fwrite(&header->colorCount, sizeof(int), 1, file);
}

/**
 * make BMP header based on width and height.
 * The purpose of this is to create a new BMPHeader struct using the information
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height) {

}


/**
* Makes new DIB header based on width and height. Useful for converting files from PPM to BMP.
*
* @param  header: Pointer to the destination DIB header
* @param  width: Width of the image that this header is for
* @param  height: Height of the image that this header is for
*/
void makeDIBHeader(struct DIB_Header* header, int width, int height) {

}


/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    int buff =  (width * 3) % 4;
    if (buff != 0) {
        buff = 4 - buff;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pArr[i][j].b, sizeof(char), 1, file);
            fread(&pArr[i][j].g, sizeof(char), 1, file);
            fread(&pArr[i][j].r, sizeof(char), 1, file);
        }
        fseek(file, sizeof(unsigned char) * buff, SEEK_CUR);
    }
}


/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    unsigned char buffWrite = 0;
    int buff =  (width * 3) % 4;
    if (buff != 0) {
        buff = 4 - buff;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&pArr[i][j].b, sizeof(unsigned char), 1, file);
            fwrite(&pArr[i][j].g, sizeof(unsigned char), 1, file);
            fwrite(&pArr[i][j].r, sizeof(unsigned char), 1, file);
        }
        fwrite(&buffWrite,sizeof(unsigned char),buff,file);
    }
}

