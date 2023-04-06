#include <stdio.h>
int enAzMadPara(int madeniPara[], int madeniSayisi, int miktar) {
    int DP[miktar+1]; // DP tablosu, ihtiyacimiz olan madeni para sayisini tutar.
    int i, j;//i ve j deðerlerini tanimladik

    
    for (i = 0; i <= miktar; i++)// DP tablosunu sifirlamamizi sagliyor
        DP[i] = -1;
    DP[0] = 0;//Sifir degerine sahip bir paranin madeni para sayisida sifirdir
    for (i = 1; i <= miktar; i++) // DP tablosunu doldurmamizi saglar
    {
        for (j = 0; j < madeniSayisi; j++)
        {
            if (madeniPara[j] <= i)
            {
                int altDeger = DP[i-madeniPara[j]];//i degerinden cikartiyor gibi gozuksede aslinda miktardan cikartiyor.
                if (altDeger != -1 && (DP[i] == -1 || altDeger + 1 < DP[i]))
                    DP[i] = altDeger + 1;
            }
        }
    }

    return DP[miktar];//bu fonksiyonu girdigimizde bu degerin donmesini saglar
}

int main()
{
    int madeniSayisi, miktar, i;//madeni sayisi,miktar ve i degerlerini tanimladik
    int madeniPara[] = {5, 10, 25, 50, 100};//madeni para olarak tanimlanan dizinin degerlerini tanimladik 
    madeniSayisi = sizeof(madeniPara)/sizeof(madeniPara[0]);//sizeof'la degiskenlerin boyutu aldik
    printf("Lutfen bir miktar giriniz: ");//kullanicidan bir madeni sayisi girmesi istedik
    scanf("%d", &miktar);
    int enAzSayi = enAzMadPara(madeniPara, madeniSayisi, miktar);//yukarida kurmus oldugumuz fonksiyonu burda cagirdik
    if (enAzSayi == -1)//yukarida for dongusunu kullanip tum degerlere deger verilmedigi surece -1 yapmýsdýk ve bu sayede deger verilmesse -1 degerine esit oldugundan if kosul saglanacak
        printf("Madeni paralarin herhangi bir kombinasyonu ile %d miktari olusturulamaz.", miktar);
    else {
        printf("%d miktari en az %d madeni para kullanilarak olusturulabilir:\n", miktar, enAzSayi);
        for (i = 0; i < madeniSayisi; i++) {
            int paraSayisi = 0;//para sayýsý deðerini sýfýra eþitledik
            while (miktar >= madeniPara[i] && enAzMadPara(madeniPara, madeniSayisi, miktar-madeniPara[i]) == enAzSayi-1) {//while döngüsüyle istediðimiz koþulu elde ettik
                paraSayisi++;
                miktar -= madeniPara[i];//miktar=miktar-madeniPara[i] degerine eþittir
            }
            if (paraSayisi > 0)//if kosul ifadesini kullandik
                printf("%d adet %d kuruþluk madeni para\n", paraSayisi, madeniPara[i]);
        }
    }

    return 0;
}

