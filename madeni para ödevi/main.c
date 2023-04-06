#include <stdio.h>

int enAzMadPara(int madeniPara[], int madeniSayisi, int miktar) {
    int DP[miktar+1]; // DP tablosu, ihtiyacýmýz olan madeni para sayýsýný tutar.
    int i, j;//i ve j deðerlerini tanýmladýk

    
    for (i = 0; i <= miktar; i++)// DP tablosunu sýfýrlamamýzý saðlýyor
        DP[i] = -1;
    DP[0] = 0;//Sýfýr deðerine sahip bir paranýn madeni para sayýsýda sýfýrdýr

   
    for (i = 1; i <= miktar; i++) // DP tablosunu doldurmamýzý saðlar
    {
        for (j = 0; j < madeniSayisi; j++)
        {
            if (madeniPara[j] <= i)
            {
                int altDeger = DP[i-madeniPara[j]];//i deðerinden çýkartýyor gibi gözüksede aslýnda miktardan çýkartýyor.
                if (altDeger != -1 && (DP[i] == -1 || altDeger + 1 < DP[i]))
                    DP[i] = altDeger + 1;
            }
        }
    }

    return DP[miktar];//bu fonksiyonu girdiðimizde bu deðerin dönmesini saðlar
}

int main()
{
    int madeniSayisi, miktar, i;//madeni sayýsý,miktar ve i deðerlerini tanýmladýk
    int madeniPara[] = {5, 10, 25, 50, 100};//madeni para olarak tanýmlanan dizinin deðerlerini tanýmladýk 
    madeniSayisi = sizeof(madeniPara)/sizeof(madeniPara[0]);//sizeof'la deðiþkenlerin boyutu aldýk
    printf("Lutfen bir miktar giriniz: ");//kullanýcýdan bir madeni sayýsý girmesi istedik
    scanf("%d", &miktar);
    int enAzSayi = enAzMadPara(madeniPara, madeniSayisi, miktar);//yukarýda kurmuþ olduðumuz fonksiyonu burda çaðýrdýk
    if (enAzSayi == -1)//yukarýda for döngüsünü kullanýp tüm deðerlere deðer verilmediði sürece -1 yapmýþdýk ve bu sayede deðer verilmesse -1 deðerine eþit olduðundan if koþul saðlanacak
        printf("Madeni paralarin herhangi bir kombinasyonu ile %d miktari olusturulamaz.", miktar);
    else {
        printf("%d miktari en az %d madeni para kullanilarak olusturulabilir:\n", miktar, enAzSayi);
        for (i = 0; i < madeniSayisi; i++) {
            int paraSayisi = 0;//para sayýsý deðerini sýfýra eþitledik
            while (miktar >= madeniPara[i] && enAzMadPara(madeniPara, madeniSayisi, miktar-madeniPara[i]) == enAzSayi-1) {//while döngüsüyle istediðimiz koþulu elde ettik
                paraSayisi++;
                miktar -= madeniPara[i];//miktar=miktar-madeniPara[i] deðerine eþittir
            }
            if (paraSayisi > 0)//if koþol ifadesini kullandýk
                printf("%d adet %d kuruþluk madeni para\n", paraSayisi, madeniPara[i]);
        }
    }

    return 0;
}

