#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Bit manipulation untuk menyimpan multiple flag dalam satu byte
#define FLAG_DIPERBARUI  0x01  // Bit 0
#define FLAG_TERSEDIA    0x02  // Bit 1

void aturFlagBuku(Buku* buku, unsigned char flag) {
    // Contoh penggunaan bit manipulation
    unsigned char flags = 0;
    
    if (buku->status == TERSEDIA) {
        flags |= FLAG_TERSEDIA;
    }
    
    // Tambahkan flag tambahan
    flags |= flag;
    
    // Contoh: Gunakan bit ke-2 untuk menandai buku berkualitas
    flags |= (1 << 2);  // Set bit ke-2 menjadi 1
    
    // Clear bit ke-3
    flags &= ~(1 << 3);  // Clear bit ke-3
}

unsigned char dapatFlagBuku(const Buku* buku) {
    unsigned char flags = 0;
    
    if (buku->status == TERSEDIA) {
        flags |= FLAG_TERSEDIA;
    }
    
    return flags;
}

int simpanKeFile(Buku** daftarBuku, int jumlahBuku, const char* namaFile) {
    FILE* file = fopen(namaFile, "w");
    if (!file) return 0;
    
    fprintf(file, "%d\n", jumlahBuku);
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%d|%s|%s|%d|%d\n",
                daftarBuku[i]->id,
                daftarBuku[i]->judul,
                daftarBuku[i]->penulis,
                daftarBuku[i]->tahun,
                daftarBuku[i]->status);
    }
    
    fclose(file);
    return 1;
}

Buku** bacaDariFile(int* jumlahBuku, const char* namaFile) {
    FILE* file = fopen(namaFile, "r");
    if (!file) return NULL;
    
    fscanf(file, "%d\n", jumlahBuku);
    Buku** daftarBuku = (Buku**)malloc(*jumlahBuku * sizeof(Buku*));
    
    for (int i = 0; i < *jumlahBuku; i++) {
        int id, tahun, status;
        char judul[100], penulis[100];
        
        fscanf(file, "%d|%99[^|]|%99[^|]|%d|%d\n", 
               &id, judul, penulis, &tahun, &status);
        
        daftarBuku[i] = buatBuku(id, judul, penulis, tahun);
        daftarBuku[i]->status = status;
    }
    
    fclose(file);
    return daftarBuku;
}