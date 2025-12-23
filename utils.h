#ifndef UTILS_H
#define UTILS_H

#include "buku.h"

// Function prototypes untuk bit manipulation dan file processing
void aturFlagBuku(Buku* buku, unsigned char flag);
unsigned char dapatFlagBuku(const Buku* buku);
int simpanKeFile(Buku** daftarBuku, int jumlahBuku, const char* namaFile);
Buku** bacaDariFile(int* jumlahBuku, const char* namaFile);

#endif