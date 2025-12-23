#ifndef LOGIKA_H
#define LOGIKA_H

#include "buku.h"
#include "anggota.h"

// Function prototypes
void pinjamBuku(Buku* buku, Anggota* anggota);
void kembalikanBuku(Buku* buku, Anggota* anggota);
void cariBuku(Buku** daftarBuku, int jumlahBuku, const char* kataKunci);

#endif