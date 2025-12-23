SISTEM MANAJEMEN PERPUSTAKAAN SEDERHANA

DESKRIPSI

Program Sistem Manajemen Perpustakaan Sederhana adalah aplikasi berbasis konsol yang dikembangkan menggunakan bahasa pemrograman C. Program ini dirancang untuk mengelola data buku dan anggota perpustakaan dengan antarmuka baris perintah yang mudah digunakan. Program ini mengimplementasikan berbagai konsep pemrograman C yang esensial sesuai dengan spesifikasi yang ditentukan.

FITUR UTAMA

1. Manajemen Data Buku
Tambah buku baru dengan informasi lengkap (ID, judul, penulis, tahun, status)
Tampilkan daftar semua buku yang tersedia
Status buku (Tersedia, Dipinjam, Hilang)
Pencarian buku berdasarkan kata kunci

2. Manajemen Data Anggota
Pendaftaran anggota baru
Tampilkan daftar anggota
Pelacakan jumlah buku yang dipinjam setiap anggota

3. Operasi Perpustakaan
Peminjaman buku oleh anggota
Pengembalian buku
Validasi ketersediaan buku

4. Penyimpanan Data
Penyimpanan data buku ke file eksternal (data_perpustakaan.txt)
Pembacaan data dari file untuk pemulihan data
Data persisten antar sesi program

Cara Kompilasi dan Menjalankan

gcc -o perpustakaan.exe main.c buku.c anggota.c logika.c utils.c

./perpustakaan.exe

Menu Program

Tambah Buku - Menambahkan buku baru ke sistem
Tampilkan Semua Buku - Menampilkan seluruh koleksi buku
Tambah Anggota - Mendaftarkan anggota baru
Tampilkan Semua Anggota - Menampilkan daftar anggota
Pinjam Buku - Proses peminjaman buku oleh anggota
Kembalikan Buku - Proses pengembalian buku
Cari Buku - Mencari buku berdasarkan kata kunci
Simpan Data ke File - Menyimpan data ke file eksternal
Baca Data dari File - Memuat data dari file eksternal
Keluar - Keluar dari program
