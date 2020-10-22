//
// Created by chase on 10/21/20.
//

//fread(&dib, sizeof(char), 40, fileIn);
//
////read single pixel (BGR)
//unsigned char r, g, b;
//fread(&b, sizeof(char), 1, fileIn);
//fread(&g, sizeof(char), 1, fileIn);
//fread(&r, sizeof(char), 1, fileIn);
//printf("color: %d %d %d\n", b, g, r);
//
//fread(&b, sizeof(char), 1, fileIn);
//fread(&g, sizeof(char), 1, fileIn);
//fread(&r, sizeof(char), 1, fileIn);
//printf("color: %d %d %d\n", b, g, r);
//
////pixel padding: 2 bytes//
//fseek(fileIn, sizeof(unsigned char) * 2, SEEK_CUR);
//
//fread(&b, sizeof(char), 1, fileIn);
//fread(&g, sizeof(char), 1, fileIn);
//fread(&r, sizeof(char), 1, fileIn);
//printf("color: %d %d %d\n", b, g, r);
//
//fread(&b, sizeof(char), 1, fileIn);
//fread(&g, sizeof(char), 1, fileIn);
//fread(&r, sizeof(char), 1, fileIn);
//printf("color: %d %d %d\n", b, g, r);
//
//// wirte out//
//FILE* write = fopen("out.bmp","wb");
//fwrite(&header.sig, sizeof(char) * 2, 1, fileIn);
//fwrite(&header.size, sizeof(int),1,fileIn);
//fwrite(&header.reserve1, sizeof(short ),1,fileIn);
//fwrite(&header.reserve2, sizeof(short ),1,fileIn);
//fwrite(&header.offset, sizeof(int),1,fileIn);
//
//fwrite(&dib, sizeof(char), 40, fileIn);