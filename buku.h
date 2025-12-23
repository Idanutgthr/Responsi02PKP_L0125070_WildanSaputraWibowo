#ifndef BUKU_H
#define BUKU_H

typedef enum {
    TERSEDIA,
    DIPINJAM,
    HILANG
} StatusBuku;

typedef struct {
    int id;
    char *judul;  // Dynamic memory allocation
    char *penulis;
    int tahun;
    StatusBuku status;
} Buku;

// Function prototypes
Buku* buatBuku(int id, const char* judul, const char* penulis, int tahun);
void tampilkanBuku(const Buku* buku);
void bebasBuku(Buku* buku);

#endif