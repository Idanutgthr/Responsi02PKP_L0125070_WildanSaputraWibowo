#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buku.h"

Buku* buatBuku(int id, const char* judul, const char* penulis, int tahun) {
    Buku* bukuBaru = (Buku*)malloc(sizeof(Buku));
    if (bukuBaru == NULL) return NULL;
    
    bukuBaru->id = id;
    bukuBaru->tahun = tahun;
    bukuBaru->status = TERSEDIA;
    
    // Dynamic allocation untuk string
    bukuBaru->judul = (char*)malloc(strlen(judul) + 1);
    bukuBaru->penulis = (char*)malloc(strlen(penulis) + 1);
    
    if (bukuBaru->judul && bukuBaru->penulis) {
        strcpy(bukuBaru->judul, judul);
        strcpy(bukuBaru->penulis, penulis);
    }
    
    return bukuBaru;
}

void tampilkanBuku(const Buku* buku) {
    if (!buku) return;
    
    const char* statusStr;
    switch (buku->status) {
        case TERSEDIA: statusStr = "Tersedia"; break;
        case DIPINJAM: statusStr = "Dipinjam"; break;
        case HILANG: statusStr = "Hilang"; break;
        default: statusStr = "Tidak diketahui";
    }
    
    printf("ID: %d | Judul: %s | Penulis: %s | Tahun: %d | Status: %s\n",
           buku->id, buku->judul, buku->penulis, buku->tahun, statusStr);
}

void bebasBuku(Buku* buku) {
    if (buku) {
        free(buku->judul);
        free(buku->penulis);
        free(buku);
    }
}