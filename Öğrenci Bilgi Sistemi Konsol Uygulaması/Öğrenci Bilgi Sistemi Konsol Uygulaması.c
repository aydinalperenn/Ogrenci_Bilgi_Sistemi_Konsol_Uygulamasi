#include<stdio.h>
#include<string.h>


struct kullanicilar {
	char ad[20];
	char soyad[20];
	char ogrenciNo[20];
	char telefonNo[20];
	char mail[35];
};

int main() {

	FILE* odevptr;

	static int menu = 1;
	int islem;

	int kaliciKullaniciSayisi, * kaliciKullaniciSayisiptr;
	kaliciKullaniciSayisiptr = &kaliciKullaniciSayisi;


	while (menu) {

		int secim_iki_menu = 1;
		int secim_uc_menu = 1;

		printf("DIKKAT! PROGRAMIN CALISMASI ICIN ONCELIKLE KULLANICI EKLENMESI GEREKLIDIR!\n\n");
		printf("NOT: Girilen kullanıcılar, program dosyaları içerisindeki \"Kullanıcılar.txt\" dosyasının içerisine kaydedilmektedir.\n\n");
		printf("1-> KULLANICI EKLE \n2-> KULLANICI BUL \n3-> KULLANICI SIRALA \n4-> CIKIS \n\n");
		scanf("%d", &islem);

		system("CLS");

		switch (islem) {

		case 1:

			int kullaniciSayisi;

			printf("Kac adet kullanici gireceginizi tuslayin (TAM SAYI GIRMEK ZORUNLUDUR): ");
			scanf("%d", &kullaniciSayisi);

			*kaliciKullaniciSayisiptr = kullaniciSayisi;

			printf("\nDIKKAT!! GIRECEGINIZ KULLANICININ ADINI, SOYADINI VE MAILINI INGILIZCE KARAKTERLER ILE GIRMENIZ GEREKMEKTEDIR.");

			struct kullanicilar* kullanici = (struct kullanicilar*)malloc(sizeof(struct kullanicilar) * kullaniciSayisi);

			odevptr = fopen("Kullanıcılar.txt", "w+");

			fprintf(odevptr, "\t\tIsim\t\t Soyisim\t  Ogrenci No\t      Telefon No\t\t\t       Mail\t\n");

			for (int i = 0; i < kullaniciSayisi; i++) {
				printf("\n\n%d. kullanicinin bilgilerini giriniz: ", i + 1);

				printf("\n\nAdi: ");
				scanf("%s", &kullanici[i].ad);

				printf("\nSoyadi: ");
				scanf("%s", &kullanici[i].soyad);

				printf("\nOgrenci Numarasi: ");
				scanf("%s", &kullanici[i].ogrenciNo);

				printf("\nTelefon Numarasi: ");
				scanf("%s", &kullanici[i].telefonNo);

				printf("\nMail: ");
				scanf("%s", &kullanici[i].mail);

				fprintf(odevptr, "%20s%20s%20s%20s%35s\n", kullanici[i].ad, kullanici[i].soyad, kullanici[i].ogrenciNo, kullanici[i].telefonNo, kullanici[i].mail);
			}

			fclose(odevptr);

			printf("\n\nAna menuye donuluyor, bir tusa basiniz.\n");

			getch();
			system("CLS");

			break;

		case 2:

			while (secim_iki_menu) {

				int islem_menu_iki;

				printf("1-> TELEFON NUMARASINA GORE BUL \n2-> OGRENCI NUMARASINA GORE BUL \n3-> MAIL ADRESINE GORE BUL \n4-> BIR UST MENUYE DON\n\n");
				scanf("%d", &islem_menu_iki);

				system("CLS");

				if (islem_menu_iki == 1) {

					char aranan[20];
					int kullaniciindisi = 0;
					int cikisdegeri;

					printf("Bulmak istediginiz kullanicinin telefon numarasini giriniz: ");
					scanf("%s", aranan);

					odevptr = fopen("Kullanıcılar.txt", "r");

					for (kullaniciindisi; kullaniciindisi < *kaliciKullaniciSayisiptr; kullaniciindisi++) {
						cikisdegeri = 1;
						cikisdegeri = strcmp(aranan, kullanici[kullaniciindisi].telefonNo);
						if (cikisdegeri == 0) {
							printf("\nAradiginiz Kullanici (ISIM / SOYISIM / OGRENCI NO / TELEFON NO / MAIL):\n\n\t%s\t %s\t %s\t %s\t %s\n", kullanici[kullaniciindisi].ad, kullanici[kullaniciindisi].soyad, kullanici[kullaniciindisi].ogrenciNo, kullanici[kullaniciindisi].telefonNo, kullanici[kullaniciindisi].mail);
							kullaniciindisi = *kaliciKullaniciSayisiptr;
						}
					}

					if (cikisdegeri < 0 || cikisdegeri>0) {
						printf("\nGirdiginiz telefon numarasina kayitli kullanici bulunamamistir.");
					}


					fclose(odevptr);

					printf("\n\nKULLANICI BUL menusune donuluyor. Bir tusa basiniz.");

					getch();
					system("CLS");

				}

				if (islem_menu_iki == 2) {

					char aranan2[20];
					int kullaniciindisi2 = 0;
					int cikisdegeri2;

					printf("Bulmak istediginiz kullanicinin ogrenci numarasini giriniz: ");
					scanf("%s", aranan2);

					odevptr = fopen("Kullanıcılar.txt", "r");

					for (kullaniciindisi2; kullaniciindisi2 < *kaliciKullaniciSayisiptr; kullaniciindisi2++) {
						cikisdegeri2 = 1;
						cikisdegeri2 = strcmp(aranan2, kullanici[kullaniciindisi2].ogrenciNo);
						if (cikisdegeri2 == 0) {
							printf("\nAradiginiz Kullanici (ISIM / SOYISIM / OGRENCI NO / TELEFON NO / MAIL):\n\n\t%s\t %s\t %s\t %s\t %s\n", kullanici[kullaniciindisi2].ad, kullanici[kullaniciindisi2].soyad, kullanici[kullaniciindisi2].ogrenciNo, kullanici[kullaniciindisi2].telefonNo, kullanici[kullaniciindisi2].mail);
							kullaniciindisi2 = *kaliciKullaniciSayisiptr;
						}
					}

					if (cikisdegeri2 < 0 || cikisdegeri2>0) {
						printf("\nGirdiginiz ogrenci numarasina kayitli kullanici bulunamamistir.");
					}


					fclose(odevptr);

					printf("\n\nKULLANICI BUL menusune donuluyor. Bir tusa basiniz.");

					getch();
					system("CLS");

				}



				if (islem_menu_iki == 3) {

					char aranan3[20];
					int kullaniciindisi3 = 0;
					int cikisdegeri3;

					printf("Bulmak istediginiz kullanicinin mail adresini giriniz: ");
					scanf("%s", aranan3);

					odevptr = fopen("Kullanıcılar.txt", "r");

					for (kullaniciindisi3; kullaniciindisi3 < *kaliciKullaniciSayisiptr; kullaniciindisi3++) {
						cikisdegeri3 = 1;
						cikisdegeri3 = strcmp(aranan3, kullanici[kullaniciindisi3].mail);
						if (cikisdegeri3 == 0) {
							printf("\nAradiginiz Kullanici (ISIM / SOYISIM / OGRENCI NO / TELEFON NO / MAIL):\n\n\t%s\t %s\t %s\t %s\t %s\n", kullanici[kullaniciindisi3].ad, kullanici[kullaniciindisi3].soyad, kullanici[kullaniciindisi3].ogrenciNo, kullanici[kullaniciindisi3].telefonNo, kullanici[kullaniciindisi3].mail);
							kullaniciindisi3 = *kaliciKullaniciSayisiptr;
						}
					}

					if (cikisdegeri3 < 0 || cikisdegeri3>0) {
						printf("\nGirdiginiz mail adresine kayitli kullanici bulunamamistir.");
					}


					fclose(odevptr);

					printf("\n\nKULLANICI BUL menusune donuluyor. Bir tusa basiniz.");

					getch();
					system("CLS");
				}

				if (islem_menu_iki == 4) {

					printf("Ana menuye donuluyor, bir tusa basiniz.\n");
					secim_iki_menu = 0;
					getch();
					system("CLS");

				}

				if (islem_menu_iki < 1 || islem_menu_iki>4) {

					printf("HATA! Tekrar deneyin!\n");
					printf("\nDevam etmek icin herhangi bir tusa basin.");
					getch();
					system("CLS");

				}

			}

			break;



		case 3:

			while (secim_uc_menu) {

				int islem_menu_uc;

				printf("1-> ISME GORE SIRALA \n2-> OGRENCI NUMARASINA GORE SIRALA \n3-> BIR UST MENUYE DON\n\n");
				scanf("%d", &islem_menu_uc);

				system("CLS");

				if (islem_menu_uc == 1) {

					int gecis = 1;
					int j = 0;

					struct kullanicilar* kullanici_sirali = (struct kullanicilar*)malloc(sizeof(struct kullanicilar) * kaliciKullaniciSayisi);
					struct kullanicilar* yedek = (struct kullanicilar*)malloc(sizeof(struct kullanicilar) * kaliciKullaniciSayisi);

					odevptr = fopen("Kullanıcılar.txt", "r+");

					for (int esitle = 0; esitle < kaliciKullaniciSayisi; esitle++) {
						kullanici_sirali[esitle] = kullanici[esitle];
					}

					for (gecis; gecis < kaliciKullaniciSayisi; gecis++) {

						for (j; j < kaliciKullaniciSayisi - 1; j++) {
							if (strcmp(kullanici_sirali[j].ad, kullanici_sirali[j + 1].ad) > 0) {
								yedek[j] = kullanici_sirali[j];
								kullanici_sirali[j] = kullanici_sirali[j + 1];
								kullanici_sirali[j + 1] = yedek[j];
							}
						}
					}

					printf("Isme gore siralanmis hali (ISIM / SOYISIM / OGRENCI NO / TELEFON NO / MAIL): \n\n");

					for (int z = 0; z < kaliciKullaniciSayisi; z++) {
						printf("%20s%20s%20s%20s%35s\n", kullanici_sirali[z].ad, kullanici_sirali[z].soyad, kullanici_sirali[z].ogrenciNo, kullanici_sirali[z].telefonNo, kullanici_sirali[z].mail);
					}

					fclose(odevptr);

					free(kullanici_sirali);
					free(yedek);

					printf("\n\nKULLANICI SIRALA menusune donuluyor. Bir tusa basiniz.");

					getch();
					system("CLS");

				}

				if (islem_menu_uc == 2) {

					int gecis2 = 1;
					int j2 = 0;

					struct kullanicilar* kullanici_sirali = (struct kullanicilar*)malloc(sizeof(struct kullanicilar) * kaliciKullaniciSayisi);
					struct kullanicilar* yedek = (struct kullanicilar*)malloc(sizeof(struct kullanicilar) * kaliciKullaniciSayisi);

					odevptr = fopen("Kullanıcılar.txt", "r+");

					for (int esitle2 = 0; esitle2 < kaliciKullaniciSayisi; esitle2++) {
						kullanici_sirali[esitle2] = kullanici[esitle2];
					}

					for (gecis2; gecis2 < kaliciKullaniciSayisi; gecis2++) {

						for (j2; j2 < kaliciKullaniciSayisi - 1; j2++) {
							if (strcmp(kullanici_sirali[j2].ogrenciNo, kullanici_sirali[j2 + 1].ogrenciNo) > 0) {
								yedek[j2] = kullanici_sirali[j2];
								kullanici_sirali[j2] = kullanici_sirali[j2 + 1];
								kullanici_sirali[j2 + 1] = yedek[j2];
							}
						}
					}

					printf("Ogrenci numarasina gore siralanmis hali (ISIM / SOYISIM / OGRENCI NO / TELEFON NO / MAIL): \n\n");

					for (int z2 = 0; z2 < kaliciKullaniciSayisi; z2++) {
						printf("%20s%20s%20s%20s%35s\n", kullanici_sirali[z2].ad, kullanici_sirali[z2].soyad, kullanici_sirali[z2].ogrenciNo, kullanici_sirali[z2].telefonNo, kullanici_sirali[z2].mail);
					}

					fclose(odevptr);

					free(kullanici_sirali);
					free(yedek);

					printf("\n\nKULLANICI SIRALA menusune donuluyor. Bir tusa basiniz.");

					getch();
					system("CLS");

				}

				if (islem_menu_uc == 3) {

					printf("Ana menuye donuluyor, bir tusa basiniz.\n");
					secim_uc_menu = 0;
					getch();
					system("CLS");

				}

				if (islem_menu_uc < 1 || islem_menu_uc>3) {

					printf("HATA! Tekrar deneyin!\n");
					printf("\nDevam etmek icin herhangi bir tusa basin.");
					getch();
					system("CLS");

				}

			}
			break;

		case 4:
			printf("Islem sonlandi, cikis yapiliyor.\n");
			printf("\nBir tusa basiniz.\n");
			menu = 0;
			break;

		default:
			printf("HATA! Tekrar deneyin!\n");
			printf("\nDevam etmek icin herhangi bir tusa basin.");
			getch();
			system("CLS");
			break;
		}

	}

	return 0;
}

