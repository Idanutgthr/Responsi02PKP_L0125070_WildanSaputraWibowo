#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "logika.h"

void pinjamBuku(Buku* buku, Anggota* anggota) {
    if (!buku || !anggota) return;
    
    if (buku->status == TERSEDIA) {
        buku->status = DIPINJAM;
        anggota->jumlahPinjaman++;
        printf("Buku '%s' berhasil dipinjam oleh %s\n", buku->judul, anggota->nama);
    } else {
        printf("Buku '%s' tidak tersedia untuk dipinjam\n", buku->judul);
    }
}

void kembalikanBuku(Buku* buku, Anggota* anggota) {
    if (!buku || !anggota) return;
    
    if (buku->status == DIPINJAM) {
        buku->status = TERSEDIA;
        if (anggota->jumlahPinjaman > 0) {
            anggota->jumlahPinjaman--;
        }
        printf("Buku '%s' berhasil dikembalikan\n", buku->judul);
    } else {
        printf("Buku '%s' tidak sedang dipinjam\n", buku->judul);
    }
}

void cariBuku(Buku** daftarBuku, int jumlahBuku, const char* kataKunci) {
    if (!daftarBuku || !kataKunci) return;
    
    printf("\nHasil pencarian untuk '%s':\n", kataKunci);
    int ditemukan = 0;
    
    for (int i = 0; i < jumlahBuku; i++) {
        // Case-insensitive search
        char judulLower[100];
        strcpy(judulLower, daftarBuku[i]->judul);
        for (int j = 0; judulLower[j]; j++) {
            judulLower[j] = tolower(judulLower[j]);
        }
        
        char kataKunciLower[100];
        strcpy(kataKunciLower, kataKunci);
        for (int j = 0; kataKunciLower[j]; j++) {
            kataKunciLower[j] = tolower(kataKunciLower[j]);
        }
        
        if (strstr(judulLower, kataKunciLower) != NULL) {
            tampilkanBuku(daftarBuku[i]);
            ditemukan = 1;
        }
    }
    
    if (!ditemukan) {
        printf("Tidak ditemukan buku dengan kata kunci '%s'\n", kataKunci);
    }
}