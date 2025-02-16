Syslog Kaydı Bağlı Liste Uygulaması
Bu proje, syslog kayıtlarını tutmak için bağlı liste (linked list) veri yapısını kullanan bir C programıdır. Syslog kayıtları, zaman damgası, mesaj içeriği ve log seviyesi bilgilerini içerir. Program, kullanıcıya syslog kayıtlarını eklemeyi ve eklediği kayıtları ekranda görüntülemeyi sağlar.

Özellikler
Syslog Kaydı: Her kayıt zaman damgası, log seviyesi ve mesaj içeriklerinden oluşur.
Bağlı Liste: Syslog kayıtları bir bağlı liste veri yapısı kullanılarak saklanır.
Dinamik Bellek Kullanımı: Syslog kayıtları için dinamik bellek (malloc) kullanılır.
Zaman Desteği: Program, geçerli zamanı alarak syslog kaydını oluşturur.
Kullanım
Gereksinimler
C derleyicisi (örneğin GCC)
Bir terminal veya IDE (örneğin Code::Blocks, Visual Studio Code vb.)Programın Çalışması
Program çalıştırıldığında:

Bir syslog kaydı oluşturulacak. Bu kayıt, geçerli zaman damgası, bir uyarı mesajı ("Disk doluluğu yüksek!") ve WARNING seviyesi içerir.
Syslog kayıtları ekrana yazdırılacak. Bağlı liste, her kayıt için zaman damgasını, seviyeyi ve mesajı gösterecek şekilde ekrana yazdırılır.Kod Açıklamaları
1. Syslog Kayıdını Temsil Eden Yapı
Her bir syslog kaydını temsil etmek için SyslogNode yapısı kullanılır. Bu yapı, zaman damgası (timestamp), mesaj içeriği (message), log seviyesi (level) ve bağlı listenin bir sonraki elemanına işaretçi (next) içerir.2. Bağlı Listeyi Yönetme
Syslog kayıtları, bağlı liste kullanılarak saklanır. Her yeni syslog kaydı, listenin başına eklenir. Yeni bir kayıt eklemek için addSyslogEntry fonksiyonu kullanılır:3. Syslog Kayıtlarını Yazdırma
Syslog kayıtları, bağlı listedeki her bir düğüm için printSyslogs fonksiyonu ile yazdırılır:4. Test Syslog Kaydı Ekleme
addTestSyslog fonksiyonu, mevcut zamanı alarak bir syslog kaydını ekler:5. Ana Fonksiyon
Ana fonksiyon (main), test amaçlı bir syslog kaydını ekler ve ardından tüm syslog kayıtlarını ekrana yazdırır:Katkıda Bulunma
Bu projeye katkıda bulunmak isterseniz, pull request göndererek yeni özellikler ekleyebilir veya mevcut hataları düzeltebilirsiniz.

Projeyi forkladıktan sonra bir dal (branch) oluşturun.
Değişikliklerinizi yapın ve test edin.
Pull request gönderin.
