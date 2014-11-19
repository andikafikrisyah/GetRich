#ifndef GAME_H
#define GAME_H
#include "boolean.h"
#include "board.h"
#include <stdio.h>
#include <time.h>


typedef int indeks;
typedef Pemain infotype;
typedef int address; /* indeks tabel */

typedef struct {
 infotype *T; /* tabel penyimpan elemen, tergantung bahasa */
 address HEAD; /* alamat penghapusan */
 address TAIL; /* alamat penambahan */
 int MaxEl; /* maksimum banyaknya elemen queue */
 } Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[Head(Q)]
#define InfoTail(Q) (Q).T[Tail(Q)]
#define MaxEl(Q) (Q).MaxEl
#define InfoHeadNama(Q) (Q).T[Head(Q)].Nama
#define InfoHeadSkor(Q) (Q).T[Head(Q)].Skor

#define Nil 0

// QUEUE
boolean IsEmpty (Queue Q);

boolean IsFull (Queue Q);

void CreateEmpty (Queue *Q, int Maks);

int NBElmt (Queue Q);

void Add (Queue *Q, infotype X);

void Del (Queue *Q, infotype *X);

// DADU
void RollDadu();

int JumlahDadu(int Dadu1,int Dadu2);

boolean IsDoble(int Roll1,int Roll2);

// QUEUE PEMAIN
void CreateQueuePemain (Queue *Q, int Maks);

void ChangeTurn (Queue *Q);

// STATUS PEMAIN
void DisplayAllPlayer(Queue Q);

int JumlahAset();

// CHANCE
void Chance();

void Undian();

void PosisiNow(indeks Lokasi,Queue *Q);

/*void Pilihan(indeks Lokasi,Pemain *P);*/
#endif // GAME_H
