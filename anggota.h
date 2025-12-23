#ifndef ANGGOTA_H
#define ANGGOTA_H

// Struct untuk linked list anggota
typedef struct AnggotaNode {
    int id;
    char *nama;
    int jumlahPinjaman;
    struct AnggotaNode* berikutnya;
} Anggota;

// Function prototypes
Anggota* buatAnggota(int id, const char* nama);
void tambahAnggota(Anggota** kepala, int id, const char* nama);
void tampilkanAnggota(const Anggota* kepala);
void bebasAnggota(Anggota* kepala);

#endif