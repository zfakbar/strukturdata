#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void sisip_awal_LIFO();
void tampil_list();

struct dtnilai
{
      char nrp[10];
      char nama[20];
      double nilai;
      struct dtnilai *next;
};
struct dtnilai *ujung;

void sisip_awal_LIFO()
{
    struct dtnilai *tampung;
    int j=0;char jawab[2];
    while(1){
        ujung=(struct dtnilai*)malloc(sizeof(struct dtnilai));
        fflush(stdin);
        printf("NRP :");scanf("%s",&ujung->nrp);
        printf("Nama      :");scanf("%s",&ujung->nama);
        printf("Nilai Test :");scanf("%lf",&ujung->nilai);
        if(j==0){
            ujung->next=NULL;
            tampung=ujung;
        }else {
            ujung->next=tampung;
            tampung=ujung;
        }
        printf("Ujung : %p \n",ujung);
            // printf("TampilNext : %p \n",tampil->next);
        printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
        if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0)){
            j++;continue;
        }
        else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
        break;
    } 
}

void sisip_awal_FIFO(){
    struct dtnilai *tampung, *awal;
    int j=0;char jawab[2];
    while(1){
        awal=(struct dtnilai*)malloc(sizeof(struct dtnilai));
        fflush(stdin);
        printf("NRP :");scanf("%s",&awal->nrp);
        printf("Nama      :" );scanf("%s",&awal->nama);
        printf("Nilai Test :" );scanf("%lf",&awal->nilai);
        awal->next=NULL;
        printf("Alamat Awal : %p \n",awal);
        if(j==0){
            ujung=awal;
            // printf("Isi Ujung : %p \n",ujung);
            tampung=ujung;
            // printf("Isi tampung : %p \n",tampung);

        }else{
            tampung->next=awal;
            tampung=tampung->next;
            // printf("Isi tampung : %p \n",tampung);
            // printf("Isi tampungnext : %p \n",tampung->next);

        }
        printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
        if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0))
        {
            j++;
            continue;
        }
        else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
            break;
    } 
}

void sisip_stl_simpul()
{
      struct dtnilai *sisip; 
      struct dtnilai *stl;
      char cari[20];
      if (ujung == NULL)
            printf("List Belum Terbentuk. Buatlah Dulu!");
      else{
            sisip=(struct dtnilai*)malloc(sizeof(struct dtnilai));
            printf("Masukkan Data Yang Akan Disisipkan \n");
            printf("NRP :"); gets(sisip->nrp);
            printf("Nama      :"); gets(sisip->nama);
            printf("Nilai Test :");scanf("%lf",&sisip->nilai);
            printf("Data disisipkan setelah data ? (nama) : ");gets(cari);
            stl = ujung;
            while(strcmp(stl->nama,cari)!=0){
                stl=stl->next;
            }   
            sisip->next = stl->next;
            stl->next = sisip;
      }
}

void tampil_list()
{
      struct dtnilai *tampil;
      printf("Data Mahasiswa yang telah diinputkan :\n");
      printf("NRP\tNama\tNilai\n");
      tampil = ujung;
        printf("Tampil : %p \n",tampil);
            printf("Ujung : %p \n",ujung);
      while(tampil!=NULL)
      {
            printf("%s\t%s\t%6.2f\n",tampil->nrp,tampil->nama,
            tampil->nilai);
            tampil=tampil->next;
      }
}

void hapus_simpul_tertentu()
{
    struct dtnilai *hapus; struct dtnilai *sblhapus;
    char cari[20];
    if (ujung == NULL)
        printf("List Belum Terbentuk. Buatlah Dulu!");
    else{
        printf("Data yang akan dihapus? (nama) : ");
        gets(cari);
        hapus = ujung;
        if(strcmp(hapus->nama,cari)==0)
        {
            ujung = ujung->next;
            free(hapus);
        }
        else {
            while(strcmp(hapus->nama,cari)!=0)
            {
                sblhapus=hapus;
                hapus=hapus->next;
            }
            if (hapus->next == NULL){
                sblhapus->next=NULL;
                free(hapus);
            }else{
                sblhapus->next = hapus->next;
                free(hapus);
            }

        }
    }
}


void rubah_data()
{
    struct dtnilai *rubah;
    char cari[20];
    char nrpbaru[10];
    char namabaru[20];
    double nilaibaru;
    rubah = ujung;
    fflush(stdin);
    printf("Masukkan nama dari data yang akan dirubah : ");
    scanf("%s",&cari);
    while (strcmp(rubah->nama,cari)!=0)
    {
        rubah = rubah->next;
    }
    printf("Masukkan data yang akan dirubah.\n");
    printf("NRP :");scanf("%s",&nrpbaru);
    printf("Nama      :" );scanf("%s",&namabaru);
    printf("Nilai Test :" );scanf("%lf",&nilaibaru);
    strcpy(rubah->nrp,nrpbaru);
    strcpy(rubah->nama,namabaru);
    rubah->nilai=nilaibaru;
}


void main(){
    sisip_awal_LIFO();
    tampil_list();
}
