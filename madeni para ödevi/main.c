#include <stdio.h>

int enAzMadPara(int madeniPara[], int madeniSayisi, int miktar) {
    int DP[miktar+1]; // DP tablosu, ihtiyac�m�z olan madeni para say�s�n� tutar.
    int i, j;//i ve j de�erlerini tan�mlad�k

    
    for (i = 0; i <= miktar; i++)// DP tablosunu s�f�rlamam�z� sa�l�yor
        DP[i] = -1;
    DP[0] = 0;//S�f�r de�erine sahip bir paran�n madeni para say�s�da s�f�rd�r

   
    for (i = 1; i <= miktar; i++) // DP tablosunu doldurmam�z� sa�lar
    {
        for (j = 0; j < madeniSayisi; j++)
        {
            if (madeniPara[j] <= i)
            {
                int altDeger = DP[i-madeniPara[j]];//i de�erinden ��kart�yor gibi g�z�ksede asl�nda miktardan ��kart�yor.
                if (altDeger != -1 && (DP[i] == -1 || altDeger + 1 < DP[i]))
                    DP[i] = altDeger + 1;
            }
        }
    }

    return DP[miktar];//bu fonksiyonu girdi�imizde bu de�erin d�nmesini sa�lar
}

int main()
{
    int madeniSayisi, miktar, i;//madeni say�s�,miktar ve i de�erlerini tan�mlad�k
    int madeniPara[] = {5, 10, 25, 50, 100};//madeni para olarak tan�mlanan dizinin de�erlerini tan�mlad�k 
    madeniSayisi = sizeof(madeniPara)/sizeof(madeniPara[0]);//sizeof'la de�i�kenlerin boyutu ald�k
    printf("Lutfen bir miktar giriniz: ");//kullan�c�dan bir madeni say�s� girmesi istedik
    scanf("%d", &miktar);
    int enAzSayi = enAzMadPara(madeniPara, madeniSayisi, miktar);//yukar�da kurmu� oldu�umuz fonksiyonu burda �a��rd�k
    if (enAzSayi == -1)//yukar�da for d�ng�s�n� kullan�p t�m de�erlere de�er verilmedi�i s�rece -1 yapm��d�k ve bu sayede de�er verilmesse -1 de�erine e�it oldu�undan if ko�ul sa�lanacak
        printf("Madeni paralarin herhangi bir kombinasyonu ile %d miktari olusturulamaz.", miktar);
    else {
        printf("%d miktari en az %d madeni para kullanilarak olusturulabilir:\n", miktar, enAzSayi);
        for (i = 0; i < madeniSayisi; i++) {
            int paraSayisi = 0;//para say�s� de�erini s�f�ra e�itledik
            while (miktar >= madeniPara[i] && enAzMadPara(madeniPara, madeniSayisi, miktar-madeniPara[i]) == enAzSayi-1) {//while d�ng�s�yle istedi�imiz ko�ulu elde ettik
                paraSayisi++;
                miktar -= madeniPara[i];//miktar=miktar-madeniPara[i] de�erine e�ittir
            }
            if (paraSayisi > 0)//if ko�ol ifadesini kulland�k
                printf("%d adet %d kuru�luk madeni para\n", paraSayisi, madeniPara[i]);
        }
    }

    return 0;
}

