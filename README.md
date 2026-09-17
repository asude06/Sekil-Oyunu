# Sekil-Oyunu
 Bağlı listeler veri yapısı ile oluşturulmuş tuvalde hareket ve diğer işlemlerin yapılabildiği bir terminal oyunu. 
 Bu oyun sayesinde başta bağıl listeler yapısını, düğüm mantığını, ortak bir sanal sınıf 
oluşturmayı, başlık ve kaynak dosyaları organizasyonunu, rastgele işlemler yapma 
yöntemlerini, konsol ekranını kullanmayı öğrendim.  
 
 Ana veri yapısı iki yönlü bir listeden oluşan her ana düğümünde tek yönlü bağlı 
bir şekiller nesnesi tutulan yapıdır. Şekillerimiz dikdörtgen, üçgen, yıldızdan 
oluşuyor. Bunları soyut bir sekil sınıfından türettik ve konsol ekranında 2B olacak şekilde 
çizdirdik. Şekilleri oluşturan karakterler ise belli bir önceliğe sahip olacak şekilde çizer. 
Başlangıçtan itibaren 2 şekilde çalıştırabiliyoruz ya rastgele ya da dosyadan okuma şeklinde.

 Program ilk açıldığında rastgele dedim. Konsolda 20 adet düğüm ve her düğümde rastgele 
konumlarda rastgele karakterlerle rastgele şekiller oluşturduk. Şekilleri veri olarak tutan iki 
yönlü liste üzerinde komutlarla sonrakine, öncekine geçebiliyoruz. Düğüm silebiliyoruz ve 
düğümü seç dediğimizde ise onun üzerinde işlem yapabiliyoruz. 2 ila 7 rastgele oluşmuş 
şekillerden rastgele bir öncelikle sağ sol aşağı yukarı hareketleri ve silme işlemi 
uygulayabiliyoruz. Sonrasında tekrar diğer düğümler menüsüne geçebiliyoruz.
