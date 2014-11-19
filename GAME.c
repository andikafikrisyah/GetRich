#include "GAME.h"

int roll1, roll2;
int jumlah;

boolean IsEmpty (Queue Q)
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (Queue Q)
{
	return (Tail(Q) == MaxEl(Q));
}


void CreateEmpty (Queue *Q, int Maks)
{
	(*Q).T = (infotype *) malloc ((Maks + 1) * sizeof(infotype));
	if ((*Q).T != NULL)
	{
		Head((*Q)) = Nil;
		Tail((*Q)) = Nil;
		MaxEl((*Q)) = Maks;
	}
	else
	{
		MaxEl((*Q)) = Nil;
	}
}

int NBElmt (Queue Q)
{
	int Count;

	if (IsEmpty(Q))
	{
		Count = 0;
	}
	else
	{
		Count = (Tail(Q) - Head(Q) + 1);
	}
	return Count;
}

void Add (Queue *Q, infotype X)
{
	if(!IsFull((*Q)))
	{
		if(IsEmpty((*Q)))
		{
			Head((*Q)) = 1;
		}
		Tail((*Q)) = Tail((*Q)) + 1;
		InfoTail((*Q)) = X;
	}
}

void Del (Queue *Q, infotype *X)
{
	int i; /* pencacah */

	if(!IsEmpty((*Q)))
	{
		(*X) = InfoHead((*Q));
		if(NBElmt((*Q)) == 1)
		{
			Head((*Q)) = Nil;
			Tail((*Q)) = Nil;
		}
		else
		{
			i = Head((*Q));
			while(i <= Tail((*Q)))
			{
				(*Q).T[i] = (*Q).T[i+1];
				i = i + 1;
			}
			Tail((*Q)) = Tail((*Q)) - 1;
		}
	}
}

void RollDadu()
{
    // Kamus Lokal
    // Algoritma

    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
}

boolean IsDoble(int roll1,int roll2)
{
    // Kamus Lokal
    // Algortima
    return (roll1 == roll2);
}

int JumlahDadu(int roll1,int roll2)
{
    // Kamus Lokal
    // Algoritma

    return (roll1 + roll2);
}

void CreateQueuePemain (Queue *Q, int Maks)
{
    // Kamus Lokal
	address i;
	infotype Pemain;
	char Nama[10];
    // Algoritma
	CreateEmpty (&(*Q), Maks);
	for (i = 1; i <= Maks; i = i + 1)
	{
		printf("Nama Pemain %d : ",i);
		scanf("%s", &Nama);
		strcpy(Pemain.Nama, Nama);
		Pemain.Jumlah_Uang = 10000000;
		Pemain.Jumlah_Aset = 10000000;
		Pemain.ID = i;
		Pemain.Posisi = 0;
		Add(&(*Q),Pemain);
	}
}

void ChangeTurn (Queue *Q)
{
    // Kamus Lokal
	infotype Info;
    // Algoritma
	if (NBElmt((*Q)) >= 2)
	{
		Del(&(*Q), &Info);
		Add(&(*Q), Info);
	}
}

void DisplayAllPlayer(Queue Q)
{
    // Kamus Lokal
    int i =1;
    // Algoritma
    while(i != Tail(Q)+1)
    {
        if(Q.HEAD==NULL)
        {
            printf("Tidak ada pemain \n");
        }
        else
        {
          printf("----- %s -----\n",Q.T[i].Nama);
          printf("Jumlah Uang : Rp. %d \n",Q.T[i].Jumlah_Uang);
          printf("Jumlah Aset : Rp. %d \n",Q.T[i].Jumlah_Aset);
        }
        i++;
    }
}

/*void JumlahAset()
{
    // Kamus Lokal
    int Jumlah;
    // Algotirma
    Jumlah = Q.T[i].Jumlah_Uang + H;
}*/

void PosisiNow(indeks Lokasi, Queue *Q)
{
    // Kamus Lokal
    //int newplace;
    // Algoritma
    InfoHead(*Q).Posisi = (Lokasi + JumlahDadu(roll1,roll2)) % 20;
    if (InfoHead(*Q).Posisi == 0) {
        InfoHead(*Q).Posisi = 1;
    }
    //newplace = InfoHead(*Q).Posisi;
}

/*void Pilihan(indeks Lokasi, Pemain *P)
{
    // Kamus Lokal
    // Algoritma
    switch(InfoHead(Q).Posisi);

}*/

/*void PosisiNow(int jumlah,int playerID)
{
  int newplace;
  newplace = player[playerID-1]->place + roll;

  if(newplace<=24)
    {
      player[playerID-1]->place = newplace;
    }
  else
    {
      newplace=newplace-24;
      player[playerID-1]->place = newplace; //setting new place (after rotation on board)
      player[playerID-1]->balance += 200; //passing through go or on go place
    }printf("%s maju sebanyak %d langkah!\n",InfoHeadNama(Q), JumlahDadu(roll1,roll2));
        PosisiNow(P.Posisi,&P);
        printf("Lokasi sekarang : %d\n",P.Posisi);
  bank_offer(newplace,playerID);
}


void Chance(indeks PosisiNow())
{
    // Kamus Lokal
    // Algoritma
    int lokasi;
    Player PemilikGedung;
    char ch[3];

  placetype = type[newplace-1];
  printf("Posisi sekarang = %d",newplace,placetype);

  switch (placetype)
    {
    case 2: // Property
      printf("\nYou hold on Property %s",name[newplace-1]);
      if(owner[newplace-1]==0)
	{
	  printf("\nProperty cost = %d",cost[newplace-1]);
	  printf("\nDo you want to buy : ");
	  scanf("%s",ch);//string from client yes or no
	  if(strcmp(ch,"yes")==0)
	    {
	      printf("\nCongratulation! %s is Yours",name[newplace-1]);
	      player[playerID-1]->totalproperty++;//incrementing property owned by player
	      owner[newplace-1]=playerID;
	      player[playerID-1]->balance -= cost[newplace-1];
	    }
	}
      else
	{
	  ownedby = owner[newplace-1];
	  if(ownedby!=playerID)
	    {
	      printf("\nThis property owned by %s, ID = %d",player[ownedby-1]->name,ownedby);
	      printf("\nYou have to pay Rent of Rs. %d/- ",rent[newplace-1]);

	      if(player[ownedby-1]->balance < rent[newplace-1])
		{
		  printf("\n%s You are running out of balance",player[playerID-1]->name);
		  //call to sell property
		}
	      else
		{
		  player[ownedby-1]->balance += rent[newplace-1];
		  player[playerID-1]->balance -= rent[newplace-1];
		}
	    }
	}
      break;
    case 3: // Station
      printf("\nYou hold on Station %s",name[newplace-1]);
      if(owner[newplace-1]==0)
	{
	  printf("\nStation cost = %d",cost[newplace-1]);
	  printf("\nDo you want to buy : ");
	  scanf("%s",ch);//string from client yes or no
	  if(strcmp(ch,"yes")==0)
	    {
	      printf("\nCongratulation! %s is Yours",name[newplace-1]);
	      player[playerID-1]->totalstation++;//incrementing station owned by player
	      owner[newplace-1]=playerID;
	      player[playerID-1]->balance -= cost[newplace-1];
	    }
	}
      else
	{
	  ownedby = owner[newplace-1];
	  if(ownedby!=playerID)
	    {

	      printf("\nThis Station owned by %s, ID = %d",player[ownedby-1]->name,ownedby);
	      printf("\nYou have to pay Rent of Rs. %d/- ",rent[newplace-1]);
	      player[ownedby-1]->balance += rent[newplace-1];
	      player[playerID-1]->balance -= rent[newplace-1];
	    }
	}

      break;
    case 4: // Utility
      printf("\nYou hold on Utility %s",name[newplace-1]);
      if(owner[newplace-1]==0)
	{
	  printf("\nUtility cost = %d",cost[newplace-1]);
	  printf("\nDo you want to buy : ");
	  scanf("%s",ch);//string from client yes or no
	  if(strcmp(ch,"yes")==0)
	    {
	      printf("\nCongratulation! %s is Yours",name[newplace-1]);
	      player[playerID-1]->totalutility++;//incrementing property owned by player
	      owner[newplace-1]=playerID;
	      player[playerID-1]->balance -= cost[newplace-1];
	    }
	}
      break;
    case 5: // Chance
      printf("\nYou hold on %s",name[newplace-1]);
      chance(roll,playerID);
      break;
    case 6: // Community Chest
      printf("\nYou hold on %s",name[newplace-1]);
      community_chest(roll,playerID);
      break;
    case 7: // Tax
      printf("\nYou hold on Tax %s",name[newplace-1]);
      printf("\nYou have to pay %d",cost[newplace-1]);
      player[playerID-1]->balance -= cost[newplace-1];
      break;
    case 8: // Jail
      printf("\nOops! You hold on %s",name[newplace-1]);
      printf("\nYou have to pay fine Rs. 50/-");
      player[playerID-1]->balance -= 50;
      break;
    case 9: // Parking
      printf("\nTake a rest! You hold on %s",name[newplace-1]);
      break;
    }
}
}
*/
