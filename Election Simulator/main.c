#include <stdio.h>
#include <stdlib.h>

void Secim_Sonuc(char x[],long int y[][3],float z,int a,float b);
void Duzenleme(char partiler[]);
void Sonuc_TR(char S[],long int K[],int G,float I,int x,long int P[][2],float f,int Q,int T[][1]);

int main()
{
       char x;
       char Partiler[6]={'A','B','C','D','E','F'};
       int Parti_Sayisi=6,il_Plaka_Kodu,il_Milletvekili_Kontenjan;
       int MV_Sayisi[20];
       int i=0,MV_Toplami=0,a,b,j;
       int il_sayac=1;
       int MV_Birincilik[10][1]={};
       int tmp;
       int sayac=0;
       long int Parti_Oy_Sayi[23][3]={};
       long int tmp_Parti_Oy[23]={};
       long int toplam_Parti_MV[23][2]={};
       float Toplam_Oy=0,TR_Toplam_Oy=0;
       float Oy_Yuzde=0;
       float MV_Yuzde=0;


       for(int i=0;i<2;i++)             {
       printf("\t\t\t");
       for(int j=0;j<80;j++)
                                        {
       printf("*");
                                        }
       printf("\t");
       printf("\n");
                                        }
       printf("\t\t\t-----------------TURKIYE GENELI SECIM SIMULASYONUNA HOSGELDINIZ-----------------\n");


       for(int i=0;i<2;i++)             {
       printf("\t\t\t");
       for(int j=0;j<80;j++)            {
       printf("*");
                                        }
       printf("\n");
                                        }

        do
        {


        do
        {
        printf("%d. Ilin plaka kodunu giriniz(1-81) :",il_sayac); // sayý sýnýrlandýrmasý türkiye esas alýnarak belirlenmiþtir.
        il_sayac++;
        scanf("%d",&il_Plaka_Kodu);

        if(il_Plaka_Kodu>0 && il_Plaka_Kodu<82)
        break;
        }
        while(il_Plaka_Kodu>0 || il_Plaka_Kodu<82);

        do
		{
		printf("Ilin milletvekili kontenjanini giriniz(1-10) :");
        scanf("%d",&il_Milletvekili_Kontenjan);
        printf("\n");

        if(il_Milletvekili_Kontenjan>0 && il_Milletvekili_Kontenjan<11)
        break;
		}
        while(il_Milletvekili_Kontenjan>0 || il_Milletvekili_Kontenjan<82);

        MV_Toplami+=il_Milletvekili_Kontenjan;

        for(i=0;i<Parti_Sayisi;i++)
        {
        printf("%c Partisi'nin oy sayisini giriniz :",Partiler[i]);
        scanf("%ld",&Parti_Oy_Sayi[i][0]);
        Toplam_Oy+=Parti_Oy_Sayi[i][0];
        tmp_Parti_Oy[i]+=Parti_Oy_Sayi[i][0];

        }

        TR_Toplam_Oy+=Toplam_Oy;
        printf("\nIl Plaka Kodu : %d",il_Plaka_Kodu);
        printf("\nMilletvekili Kontenjani : %d",il_Milletvekili_Kontenjan);
        printf("\nGecerli Oy Sayisi : %.0f",Toplam_Oy);

        for(i=0;i<Parti_Sayisi;i++)
        {
        Parti_Oy_Sayi[i][2]=i;
        toplam_Parti_MV[i][1]=i;
        }
        for(a=0;a<=Parti_Sayisi;a++)
                                                                {
        for(b=0;b<=Parti_Sayisi;b++)
                                                                {
        if(Parti_Oy_Sayi[a][0]>Parti_Oy_Sayi[b][0])
                                                                {
        tmp=Parti_Oy_Sayi[a][0];
        Parti_Oy_Sayi[a][0]=Parti_Oy_Sayi[b][0];
        Parti_Oy_Sayi[b][0]=tmp;

        tmp=Parti_Oy_Sayi[a][2];
        Parti_Oy_Sayi[a][2] = Parti_Oy_Sayi[b][2];
        Parti_Oy_Sayi[b][2] = tmp;
                                                                }
                                                                }
                                                                }
        for(i=0;i<Parti_Sayisi;i++)
                                                                {
        if(Parti_Oy_Sayi[0][2]==i)
                                                                {
        MV_Birincilik[i][0]++;
        break;                       //1.lik atama iþlemi.
                                                                }
                                                                }
        int Parti_Ayar[Parti_Sayisi][2];

        for(i=0;i<Parti_Sayisi;i++)
                                                               {
        Parti_Ayar[i][0] = Parti_Oy_Sayi[i][0];
        Parti_Ayar[i][1] = i;
                                                               }
        do{

        for(i=0;i<Parti_Sayisi;i++)
                                                               {
        for(j=0;j<Parti_Sayisi-1;j++)
                                                               {
        if(Parti_Ayar[j][0] < Parti_Ayar[j+1][0])
                                                               {
        tmp = Parti_Ayar[j][0];
        Parti_Ayar[j][0] = Parti_Ayar[j+1][0];
        Parti_Ayar[j+1][0] = tmp;

        tmp = Parti_Ayar[j][1];
        Parti_Ayar[j][1] = Parti_Ayar[j+1][1];
        Parti_Ayar[j+1][1] = tmp;
                                                                }
                                                                }
                                                                }
        il_Milletvekili_Kontenjan--;
        Parti_Oy_Sayi[Parti_Ayar[0][1]][1]++;
        Parti_Ayar[0][0] = Parti_Ayar[0][0]/2;

        }
        while(il_Milletvekili_Kontenjan>0);

        for(i=0;i<Parti_Sayisi;i++)
                                                                             {

                                                                             }
      printf("\n\t\tOy Sayisi \tOy Yuzdesi      MV Sayisi");
      printf("\n\t\t----------\t-----------    ----------");
      Secim_Sonuc(Partiler,Parti_Oy_Sayi,Oy_Yuzde,Parti_Sayisi,Toplam_Oy);
      for(i=0;i<Parti_Sayisi;i++)
                                                                             {
      toplam_Parti_MV[Parti_Oy_Sayi[i][2]][0]+=Parti_Oy_Sayi[i][1];
		                                                                     }
	  printf("\n\n");
      printf("isleme devam etmek icin bir tusa basiniz...");
      system("PAUSE");

      printf("\n\n");
      if(sayac<5)
                                                                             {
      Toplam_Oy=0;
      il_Milletvekili_Kontenjan=0;
      for(i=0;i<Parti_Sayisi;i++)
                                                                             {
      Parti_Oy_Sayi[i][1]=0;
                                                                             }
      sayac++;
                                                                             }
                                                                             }//yukarýdaki do'nun parantezi
      while(sayac<5);




     for(int i=0;i<2;i++)          {
     printf("\t\t\t");
     for(int j=0;j<80;j++)
                                   {
     printf("*");
                                   }
     printf("\t");
     printf("\n");
                                   }
    printf("\t\t\t---------------------------TURKIYE GENELI SECIM SONUCU--------------------------\t\t\n");


     for(int i=0;i<2;i++)          {
     printf("\t\t\t");
     for(int j=0;j<80;j++)
                                   {
     printf("*");
                                   }
     printf("\t");
     printf("\n");
                                   }








    printf("\nMilletvekili Kontenjani : %d",MV_Toplami);
    printf("\nGecerli Oy Sayisi : %.0f",TR_Toplam_Oy);
    printf("\n\n\n\t\tOy Sayisi\tOy Yuzdesi    MV Sayisi \tMV Yuzdesi      liderlik sayisi ");
    printf("\n\t\t---------\t---------    --------- \t       -----------    ----------------");

    Sonuc_TR(Partiler,tmp_Parti_Oy,Parti_Sayisi,Oy_Yuzde,TR_Toplam_Oy,toplam_Parti_MV,MV_Yuzde,MV_Toplami,MV_Birincilik);

                                                                                        }

    void Secim_Sonuc(char x[],long int y[][3],float z,int a,float b)
                                                                                        {
    int c;
    for(c=0;c<a;c++)
                                                                                        {
    z=(y[c][0]*100)/b;
    printf("\n%c Partisi \t%ld \t\t%.2f \t\t%ld",x[y[c][2]],y[c][0],z,y[c][1]);
                                                                                        }
                                                                                        }

    void Duzenleme(char partiler[])
                                                           {
    char partiler1[6]={'A','B','C','D','E','F'};
    int i;
    for(i=0;i<6;i++)
                                                           {
    partiler[i]=partiler1[i];
                                                           }
                                                           }

    void Sonuc_TR(char S[],long int K[],int G,float I,int x,long int P[][2],float f,int Q,int T[][1])
                                            {
    long int MV_R[G][2];
    int i,j;
    for(i=0;i<G;i++)
                                            {
    MV_R[i][0] = T[i][0];
    MV_R[i][1] = i;
                                            }
    for(i=0;i<G;i++)
                                            {
    for(j=0;j<G-1;j++)
                                            {
    if(MV_R[j][0] < MV_R[j+1][0])
                                            {
    int tmp;
    tmp = MV_R[j][0];
    MV_R[j][0] = MV_R[j+1][0];
    MV_R[j+1][0] = tmp;

    tmp = MV_R[j][1];
    MV_R[j][1] =MV_R[j+1][1];
    MV_R[j+1][1] = tmp;
                                            }
                                            }
                                            }
    for(i=0;i<G;i++)
                                                                                                       {
    f= (float)(P[i][0]*100)/Q;
    I=(float)(K[i]*100)/x;
    printf("\n%c Partisi \t%ld \t\t%.2f\t\t%1d\t\t%.2f\t\t%d",S[i],K[i],I,P[i][0],f,T[i][0]);
                                                                                                        }
    printf("\n\nIktidar Partisi : %c\nAna Muhalefet Partisi:%c",S[MV_R[0][1]],S[MV_R[1][1]]);
                                                                                                        }
