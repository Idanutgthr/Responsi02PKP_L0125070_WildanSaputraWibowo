#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anggota.h"

Anggota* buatAnggota(int id, const char* nama) {
    Anggota* anggotaBaru = (Anggota*)malloc(sizeof(Anggota));
    if (anggotaBaru == NULL) return NULL;
    
    anggotaBaru->id = id;
    anggotaBaru->jumlahPinjaman = 0;
    anggotaBaru->berikutnya = NULL;
    
    anggotaBaru->nama = (char*)malloc(strlen(nama) + 1);
    if (anggotaBaru->nama) {
        strcpy(anggotaBaru->nama, nama);
    }
    
    return anggotaBaru;
}

void tambahAnggota(Anggota** kepala, int id, const char* nama) {
    Anggota* anggotaBaru = buatAnggota(id, nama);
    if (!anggotaBaru) return;
    
    anggotaBaru->berikutnya = *kepala;
    *kepala = anggotaBaru;
}

void tampilkanAnggota(const Anggota* kepala) {
    const Anggota* saatIni = kepala;
    while (saatIni) {
        printf("ID: %d | Nama: %s | Pinjaman: %d\n",
               saatIni->id, saatIni->nama, saatIni->jumlahPinjaman);
        saatIni = saatIni->berikutnya;
    }
}

void bebasAnggota(Anggota* kepala) {
    Anggota* saatIni = kepala;
    while (saatIni) {
        Anggota* berikutnya = saatIni->berikutnya;
        free(saatIni->nama);
        free(saatIni);
        saatIni = berikutnya;
    }
}