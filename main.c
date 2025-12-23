#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buku.h"
#include "anggota.h"
#include "logika.h"
#include "utils.h"

#define MAX_BUKU 100

// Pass by reference contoh
void tambahBukuKeKoleksi(Buku*** koleksi, int* jumlah, Buku* bukuBaru) {
    if (*jumlah >= MAX_BUKU) {
        printf("Koleksi buku penuh!\n");
        return;
    }
    
    (*koleksi)[*jumlah] = bukuBaru;
    (*jumlah)++;
}

void tampilkanMenu() {
    printf("\n=== SISTEM MANAJEMEN PERPUSTAKAAN ===\n");
    printf("1. Tambah Buku\n");
    printf("2. Tampilkan Semua Buku\n");
    printf("3. Tambah Anggota\n");
    printf("4. Tampilkan Semua Anggota\n");
    printf("5. Pinjam Buku\n");
    printf("6. Kembalikan Buku\n");
    printf("7. Cari Buku\n");
    printf("8. Simpan Data ke File\n");
    printf("9. Baca Data dari File\n");
    printf("10. Keluar\n");
    printf("Pilihan: ");
}

int main() {
    // Dynamic memory allocation untuk array buku
    Buku** daftarBuku = (Buku**)malloc(MAX_BUKU * sizeof(Buku*));
    int jumlahBuku = 0;
    
    // Linked list untuk anggota
    Anggota* daftarAnggota = NULL;
    
    int pilihan;
    char input[100];
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();  // Consume newline
        
        switch (pilihan) {
            case 1: {  // Tambah buku
                int id, tahun;
                char judul[100], penulis[100];
                
                printf("Masukkan ID buku: ");
                scanf("%d", &id);
                getchar();
                
                printf("Masukkan judul buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                
                printf("Masukkan penulis: ");
                fgets(penulis, sizeof(penulis), stdin);
                penulis[strcspn(penulis, "\n")] = 0;
                
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                
                Buku* bukuBaru = buatBuku(id, judul, penulis, tahun);
                if (bukuBaru) {
                    tambahBukuKeKoleksi(&daftarBuku, &jumlahBuku, bukuBaru);
                    printf("Buku berhasil ditambahkan!\n");
                }
                break;
            }
            
            case 2:  // Tampilkan semua buku
                printf("\n=== DAFTAR BUKU ===\n");
                for (int i = 0; i < jumlahBuku; i++) {
                    tampilkanBuku(daftarBuku[i]);
                }
                break;
                
            case 3: {  // Tambah anggota
                int id;
                char nama[100];
                
                printf("Masukkan ID anggota: ");
                scanf("%d", &id);
                getchar();
                
                printf("Masukkan nama anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                
                tambahAnggota(&daftarAnggota, id, nama);
                printf("Anggota berhasil ditambahkan!\n");
                break;
            }
            
            case 4:  // Tampilkan semua anggota
                printf("\n=== DAFTAR ANGGOTA ===\n");
                tampilkanAnggota(daftarAnggota);
                break;
                
            case 5: {  // Pinjam buku
                if (!daftarAnggota) {
                    printf("Belum ada anggota terdaftar!\n");
                    break;
                }
                
                int idBuku, idAnggota;
                printf("Masukkan ID buku: ");
                scanf("%d", &idBuku);
                printf("Masukkan ID anggota: ");
                scanf("%d", &idAnggota);
                
                // Cari buku
                Buku* bukuDipinjam = NULL;
                for (int i = 0; i < jumlahBuku; i++) {
                    if (daftarBuku[i]->id == idBuku) {
                        bukuDipinjam = daftarBuku[i];
                        break;
                    }
                }
                
                // Cari anggota
                Anggota* anggotaPinjam = daftarAnggota;
                while (anggotaPinjam && anggotaPinjam->id != idAnggota) {
                    anggotaPinjam = anggotaPinjam->berikutnya;
                }
                
                if (bukuDipinjam && anggotaPinjam) {
                    pinjamBuku(bukuDipinjam, anggotaPinjam);
                } else {
                    printf("Buku atau anggota tidak ditemukan!\n");
                }
                break;
            }
            
            case 6: {  // Kembalikan buku
                int idBuku, idAnggota;
                printf("Masukkan ID buku: ");
                scanf("%d", &idBuku);
                printf("Masukkan ID anggota: ");
                scanf("%d", &idAnggota);
                
                // Cari buku
                Buku* bukuDikembalikan = NULL;
                for (int i = 0; i < jumlahBuku; i++) {
                    if (daftarBuku[i]->id == idBuku) {
                        bukuDikembalikan = daftarBuku[i];
                        break;
                    }
                }
                
                // Cari anggota
                Anggota* anggotaKembali = daftarAnggota;
                while (anggotaKembali && anggotaKembali->id != idAnggota) {
                    anggotaKembali = anggotaKembali->berikutnya;
                }
                
                if (bukuDikembalikan && anggotaKembali) {
                    kembalikanBuku(bukuDikembalikan, anggotaKembali);
                } else {
                    printf("Buku atau anggota tidak ditemukan!\n");
                }
                break;
            }
            
            case 7: {  // Cari buku
                char kataKunci[100];
                printf("Masukkan kata kunci pencarian: ");
                fgets(kataKunci, sizeof(kataKunci), stdin);
                kataKunci[strcspn(kataKunci, "\n")] = 0;
                
                cariBuku(daftarBuku, jumlahBuku, kataKunci);
                break;
            }
            
            case 8:  // Simpan ke file
                if (simpanKeFile(daftarBuku, jumlahBuku, "data_perpustakaan.txt")) {
                    printf("Data berhasil disimpan ke file!\n");
                } else {
                    printf("Gagal menyimpan data ke file!\n");
                }
                break;
                
            case 9:  // Baca dari file
                for (int i = 0; i < jumlahBuku; i++) {
                    bebasBuku(daftarBuku[i]);
                }
                free(daftarBuku);
                
                daftarBuku = bacaDariFile(&jumlahBuku, "data_perpustakaan.txt");
                if (daftarBuku) {
                    printf("Data berhasil dibaca dari file! (%d buku)\n", jumlahBuku);
                } else {
                    printf("Gagal membaca data dari file!\n");
                }
                break;
                
            case 10:  // Keluar
                printf("Terima kasih telah menggunakan sistem perpustakaan!\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 10);
    
    // Cleanup
    for (int i = 0; i < jumlahBuku; i++) {
        bebasBuku(daftarBuku[i]);
    }
    free(daftarBuku);
    bebasAnggota(daftarAnggota);
    
    return 0;
}