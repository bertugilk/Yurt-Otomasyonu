#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

FILE*liste,*yedek;

struct yurt
{
	int odaNo,yatakNo,yas,tel,yurtNo;
	char ad[20],soyad[20],bolum[30];

}bilgi;

void kayit();
void sil();
void guncelle();
void ara();
void listele();
void cik();

int main(void)
{
	system("color C");
	printf("\n\t\t\t	BERTUG ILK OGRENCI YURDU\n");
	printf("\n\n");
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                        MENU                    |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|     1-) Ogrenci Kaydet       2-) Ogrenci Sil   |\n");
	printf("\t\t|     3-) Bilgi Guncelle       4-) Ogrenci Ara   |\n");
	printf("\t\t|     5-) Tum Ogrenciler       6-) CIKIS         |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|------------------------------------------------|\n\n\n");
	
	printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMI SECIN: ");
	
	switch(getch())
	{
		case '1':
			system("CLS");
			kayit();
		case '2':
			system("CLS");
			sil();
		case '3':
			system("CLS");
			guncelle();
		case '4':
			system("CLS");
			ara();
		case '5':
			system("CLS");
			listele();
		case '6':
			system("CLS");
			cik();					
	}
	
	
	getch();
	return 0;
}

void kayit(void)
{
	system("color A");
	printf("**************** OGRENCI KAYIT ISLEMI ********************\n\n\n");
	liste=fopen("ogrenciler.txt","a");
	fflush(stdin);
	printf("Yurt Ogrenci No: "); scanf("%d",&bilgi.yurtNo);
	printf("\n");
	printf("Oda No: "); scanf("%d",&bilgi.odaNo);
	printf("\n");
	printf("Yatak No: "); scanf("%d",&bilgi.yatakNo);
	printf("\n");
	printf("Isim: "); scanf("%s",&bilgi.ad);
	printf("\n");
	printf("Soyisim: "); scanf("%s",&bilgi.soyad);
	printf("\n");
	printf("Yas: "); scanf("%d",&bilgi.yas);
	printf("\n");
	printf("Telefon Numarasi: "); scanf("%d",&bilgi.tel);
	printf("\n");
	printf("Okudugu Bolum: "); 	scanf("%s",&bilgi.bolum);
	printf("\n");
	
	fprintf(liste,"%d %d %d %s %s %d %d %s\n",bilgi.yurtNo,bilgi.odaNo,bilgi.yatakNo,bilgi.ad,bilgi.soyad,bilgi.yas,bilgi.tel,bilgi.bolum);
	fclose(liste);
	printf("BILGILER BASARIYLA KAYDEDILDI...\n\n");
	
	printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
	switch(getch())
	{
		case 'E':
			system("CLS");
			main();
		case 'e':
			system("CLS");
			main();
		case 'H':
			exit(1);
		case 'h':
			exit(1);				
	}
}

void sil(void)
{
	system("color B");
	printf("*********** OGRENCI BILGILERI SILME ISLEMI *************\n\n\n");
	
	int yNo;
	int durum=0;
	
	printf("SILMEK ISTEDIGINIZ OGRENCININ YURT NUMARASI: "); scanf("%d",&yNo);
	printf("\n");
	
	liste=fopen("ogrenciler.txt","r");
	yedek=fopen("yedek.txt","a");
	
	while(!feof(liste))
	{
		fscanf(liste,"%d %d %d %s %s %d %d %s\n",&bilgi.yurtNo,&bilgi.odaNo,&bilgi.yatakNo,&bilgi.ad,&bilgi.soyad,&bilgi.yas,&bilgi.tel,&bilgi.bolum);
		
		if(yNo!=bilgi.yurtNo)
		{
			fprintf(yedek,"%d %d %d %s %s %d %d %s\n",bilgi.yurtNo,bilgi.odaNo,bilgi.yatakNo,bilgi.ad,bilgi.soyad,bilgi.yas,bilgi.tel,bilgi.bolum);
		}
		else durum=1;
	}
	
	fclose(liste);
	fclose(yedek);
	
	if(durum==1)
	{
		remove("ogrenciler.txt");
		rename("yedek.txt","ogrenciler.txt");
		printf("\n%d NUMARALI %s ADLI OGRENCIYI SILDINIZ!\n\n",bilgi.yurtNo,bilgi.ad);
		
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
	}
	else
	{
		remove("yedek.txt");
		printf("%d NUMARASINA SAHIP BIR OGRENCI BULUNAMAMAKTADIR!\n\n",yNo);
		
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
	}
	fflush(stdin);
}

void guncelle(void)
{
	system("color D");
	printf("***************** OGRENCI BILGI GUNCELLEME ISLEMI ******************\n\n\n");
	
	int yNo;
	int durum=0;

	printf("Guncellemek istediginiz ogrencinin yurt numarasi: ");
	scanf("%d",&yNo);
	printf("\n");
	
	liste=fopen("ogrenciler.txt","r");
	yedek=fopen("yedek.txt","a");
	
	while(!feof(liste))
	{
		fscanf(liste,"%d %d %d %s %s %d %d %s\n",&bilgi.yurtNo,&bilgi.odaNo,&bilgi.yatakNo,&bilgi.ad,&bilgi.soyad,&bilgi.yas,&bilgi.tel,&bilgi.bolum);
		
			if(yNo!=bilgi.yurtNo)
			{
				fprintf(yedek,"%d %d %d %s %s %d %d %s\n",bilgi.yurtNo,bilgi.odaNo,bilgi.yatakNo,bilgi.ad,bilgi.soyad,bilgi.yas,bilgi.tel,bilgi.bolum);
			}
			else
			{
				fflush(stdin);
				printf("Yurt Ogrenci No: "); scanf("%d",&bilgi.yurtNo);
				printf("\n");
				printf("Oda No: "); scanf("%d",&bilgi.odaNo);
				printf("\n");
				printf("Yatak No: "); scanf("%d",&bilgi.yatakNo);
				printf("\n");
				printf("Isim: "); scanf("%s",&bilgi.ad);
				printf("\n");
				printf("Soyisim: "); scanf("%s",&bilgi.soyad);
				printf("\n");
				printf("Yas: "); scanf("%d",&bilgi.yas);
				printf("\n");
				printf("Telefon Numarasi: "); scanf("%d",&bilgi.tel);
				printf("\n");
				printf("Okudugu Bolum: "); 	scanf("%s",&bilgi.bolum);
				printf("\n");
				
				fprintf(yedek,"%d %d %d %s %s %d %d %s\n",bilgi.yurtNo,bilgi.odaNo,bilgi.yatakNo,bilgi.ad,bilgi.soyad,bilgi.yas,bilgi.tel,bilgi.bolum);
				
				durum=1;	
			}
	}
	
	fclose(liste);
	fclose(yedek);
	
	if(durum==1)
	{
		remove("ogrenciler.txt");
		rename("yedek.txt","ogrenciler.txt");
		printf("\n%d NUMARALI OGRENCININ BILGILERINI BASARIYLA GUNCELLEDINIZ!\n\n",yNo);
		
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
	}
	else
	{
		remove("yedek.txt");
		printf("%d NUMARASINA SAHIP BIR OGRENCI BULUNAMAMAKTADIR!\n\n",yNo);
		
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
	}
	fflush(stdin);
}

void ara(void)
{
	system("color E");
	printf("********************* OGRENCI ARAMA ISLEMI ***************************\n\n\n");
	
	int yNo;
	int durum=0;
	
	fflush(stdin);
	
	printf("Bilgilerini ogrenmek istediginiz ogrencinin yurt numarasi: ");
	scanf("%d",&yNo);
	printf("\n");
	liste=fopen("ogrenciler.txt","r");
	
	while(!feof(liste))
	{
		fscanf(liste,"%d %d %d %s %s %d %d %s\n",&bilgi.yurtNo,&bilgi.odaNo,&bilgi.yatakNo,&bilgi.ad,&bilgi.soyad,&bilgi.yas,&bilgi.tel,&bilgi.bolum);
		if((bilgi.yurtNo,yNo)==0)
	    	printf("YURT NUMARASI: %d\n",bilgi.yurtNo);
			printf("ODA NO: %d\n",bilgi.odaNo);
			printf("YATAK NO: %d\n",bilgi.yatakNo);
			printf("AD: %s\n",bilgi.ad);
			printf("SOYAD: %s\n",bilgi.soyad);
			printf("YAS: %d\n",bilgi.yas);
			printf("TELEFON NUMARA: %d\n",bilgi.tel);
			printf("BOLUMU: %d\n\n",bilgi.bolum);
			
			durum=1;
			
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
		
	}
	fclose(liste);
	if(durum==0)
	{
		printf("\n%d NUMARASINA SAHIP BIR OGRENCI BULUNAMAMAKTADIR!\n\n",yNo);
		
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
	}
}

void listele(void)
{
	system("color F");
	printf("********************* BERTUG ILK YURDUNDA KALAN TUM OGRENCILER *****************************\n\n\n");
	
	liste=fopen("ogrenciler.txt","r");
	
	while(!feof(liste))
	{
		fflush(stdout);
		fscanf(liste,"%d %d %d %s %s %d %d %s\n",&bilgi.yurtNo,&bilgi.odaNo,&bilgi.yatakNo,&bilgi.ad,&bilgi.soyad,&bilgi.yas,&bilgi.tel,&bilgi.bolum);
	    
		if(bilgi.yurtNo!=NULL)
		{
			printf("YURT NUMARASI: %d\n",bilgi.yurtNo);
			printf("ODA NO: %d\n",bilgi.odaNo);
			printf("YATAK NO: %d\n",bilgi.yatakNo);
			printf("AD: %s\n",bilgi.ad);
			printf("SOYAD: %s\n",bilgi.soyad);
			printf("YAS: %d\n",bilgi.yas);
			printf("TELEFON NUMARA: %d\n",bilgi.tel);
			printf("BOLUMU: %s\n\n",bilgi.bolum);
		}
	}

	fclose(liste);
	
		printf("YENI BIR ISLEM YAPMAK ISTIYORMUSUNUZ(E/H)?");
	
		switch(getch())
		{
			case 'E':
				system("CLS");
				main();
			case 'e':
				system("CLS");
				main();
			case 'H':
				exit(1);
			case 'h':
				exit(1);				
		}
}

void cik(void)
{
	printf("\n\tCIKMAK ICIN BIR TUSA BASIN...\n\n");
	exit(1);
}
