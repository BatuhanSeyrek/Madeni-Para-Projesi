# **_En Az Madeni Para Kullanarak Para Üstü Verme_**

Bu kod, minimum sayıda madeni para kullanarak belirli bir miktarda para oluşturmanızı sağlar. Kod, madeni para dizisini ve ihtiyacınız olan miktarı alır ve ardından dinamik programlama kullanarak ihtiyacınız olan madeni para sayısını hesaplar.

Kod, "enAzMadPara" adlı bir fonksiyon kullanarak çalışır. Bu fonksiyon, DP (dinamik programlama) tablosunu oluşturarak ihtiyacımız olan madeni para sayısını hesaplar. İlk olarak DP tablosunu sıfırlar ve ardından tabloyu doldurmak için iç içe iki döngü kullanır. İçteki döngü, madeni para dizisini kontrol eder ve dıştaki döngü, DP tablosunu doldurmak için miktarı kontrol eder. DP tablosu, ihtiyacımız olan madeni para sayısını tutar.

Ardından, "main" fonksiyonu, kullanıcıdan bir miktar girilmesini ister ve bu miktarı "enAzMadPara" fonksiyonuna gönderir. "enAzMadPara" fonksiyonu, minimum madeni para sayısını hesaplar ve geri döndürür. Sonuç olarak, "main" fonksiyonu, minimum madeni para sayısını kullanarak belirli bir miktarı oluşturmanın mümkün olup olmadığını kontrol eder ve ekrana minimum madeni para sayısını ve bu madeni paraların sayısını yazdırır.
## **_Nasıl Kullanılır?_**

Programı çalıştırdıktan sonra, kullanıcıdan istenen miktarı girerek programın çalışmasını sağlayabilirsiniz.

## **_Nasıl Çalışır?_**

Program, verilen madeni para listesi (5, 10, 25, 50, 100) ile DP (dynamic programming) yöntemi kullanarak, verilen miktar için en az sayıda madeni para kullanarak para üstü verme işlemini gerçekleştirir.

## **_Örnek Çalışma_**

Program çalıştırıldığında, örneğin kullanıcıdan 67 kuruş para üstü istendiğinde, program şu çıktıyı verecektir:

Lutfen bir miktar giriniz: 65

67 miktari en az 4 madeni para kullanilarak olusturulabilir:

1 adet 25 kuruşluk madeni para

1 adet 25 kuruşluk madeni para

1 adet 10 kuruşluk madeni para

1 adet 5 kuruşluk madeni para

Bu çıktıda, 65 kuruş için en az 4 adet madeni para kullanarak para üstü vermenin mümkün olduğu, bunların da 1 adet 25 kuruş, 1 adet 10 kuruş ve 1 adet 5 kuruş madeni para olduğu görülmektedir.
