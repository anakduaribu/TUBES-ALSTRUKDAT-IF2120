/* Ini adalah header untuk menyimpan semua variabel dalam permainan */

#ifndef kamusvar_H
#define kamusvar_H

#include "boolean.h"
#include <string.h>
#include <stdlib.h>

/* Definisi variabel untuk Engi's Kitchen Expansion*/

/*Bentukan si player*/
typedef struct{
	int life;
	int money;
} PLAYER

#define Life(P) (P).Life
#define Money(P) (P).Money

/* Untuk ADT JAM -> Waktu game  */
typedef struct {
    int SS; /* buat simpan waktu permainan kalau jadi di save */
} JAM
/*Definisi pemanggilan Time */
#define Time(J) (J).SS


/*Untuk ADT POINT */
typedef struct {
	float X; /* absis */
	float Y; /* ordinat*/
	int ID /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;
/*Definisi pemanggilan Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Lokasi(P) (P).lokasi


/*Untuk ADT ARRAY -> <makanan,nomormeja,kesabaran>*/ 
typedef struct {
    int nomormeja;
    int kesabaran;
    char makanan[30];
} TabInt
/*Definisi pemanggilan Point */
#define Nomormeja(A) (A).nomormeja
#define Kesabaran(A) (A).kesabaran
#define Makanan(A) (A).makanan  /*coba deh bisa di string atau engga */

/*Untuk ADT Matriks*/
typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/*Untuk ADT Mesin Karakter dan Karakter*/
/* Definisi elemen dan address */

/*Untuk ADT Queue*/
typedef struct {
                 int wktantri;/* waktu antrean si pelanggan */
				 int jumlahorang; /*antrian per grup, kan antriannya ga harus sendiri (per kelomppok)*/
               } infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype T [30];  /*panjang antrian maksimal*/
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
#define WktAntri(e)     (e).wktantri
#define Jumlahorang(e) (e).jumlahorang              
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]


/*Untuk ADT Stack*/
typedef int infotype;
typedef int address;   /* indeks tabel */
typedef struct {
	infotype T[5]; /* tabel penyimpan elemen pada tray*/
	address TOP;  /* alamat TOP: elemen puncak */
} StackTray;

/* Definisi akses dengan Selektor : Set dan Get */
#define TopTray(ST) (ST).TOP
#define InfoTopTray(ST) (ST).T[(ST).TOP]

/*Untuk ADT Stack*/
typedef int infotype;
typedef int address;   /* indeks tabel */

typedef struct {
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} StackHand;

/* Definisi akses dengan Selektor : Set dan Get */
#define TopHand(SH) (SH).TOP
#define InfoTopHand(SH) (SH).T[(SH).TOP]


#endif