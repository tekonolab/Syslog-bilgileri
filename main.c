#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Syslog kaydýný temsil eden düðüm yapýsý
struct SyslogNode {
    char timestamp[100];   // Log mesajýnýn zamaný
    char message[512];     // Log mesajýnýn içeriði
    char level[20];        // Log seviyesi (INFO, ERROR, WARN vb.)
    struct SyslogNode *next; // Sonraki düðüme iþaretçi
};

// Baðlý listenin baþý (Baþlangýçta NULL)
struct SyslogNode* head = NULL;

// Yeni bir syslog kaydýný baðlý listeye ekleme fonksiyonu
void addSyslogEntry(char* timestamp, char* message, char* level) {
    // Yeni bir syslog kaydý için hafýzada yer ayýrýyoruz
    struct SyslogNode* newNode = (struct SyslogNode*)malloc(sizeof(struct SyslogNode));
    
    // Yeni düðüme deðerleri atýyoruz
    strcpy(newNode->timestamp, timestamp);  // Zaman damgasý
    strcpy(newNode->message, message);      // Mesaj içeriði
    strcpy(newNode->level, level);          // Log seviyesi
    
    // Yeni düðümün next iþaretçisini þu anki head'e yönlendiriyoruz
    newNode->next = head;  
    head = newNode;  // Listeyi güncelleyip, yeni düðümü baþa ekliyoruz
}

// Baðlý listeyi ekrana yazdýran fonksiyon
void printSyslogs() {
    struct SyslogNode* current = head;  // Listeyi baþtan baþlatýyoruz
    
    // Baðlý listedeki tüm syslog kayýtlarýný gezip ekrana yazdýrýyoruz
    while (current != NULL) {  // Listeyi sonuna kadar gez
        printf("Timestamp: %s\n", current->timestamp);  // Zaman damgasý
        printf("Level: %s\n", current->level);          // Log seviyesi
        printf("Message: %s\n", current->message);      // Mesaj içeriði
        printf("------------------------------------\n");
        current = current->next;  // Sonraki düðüme geç
    }
}

// Þu anki zamaný alarak syslog kaydýný ekleyen fonksiyon
void addTestSyslog() {
    time_t t;  // Zamaný alabilmek için deðiþken
    struct tm *tm_info;  // Zaman bilgisini tutacak yapý
    char timestamp[100];  // Zaman damgasý için dizi

    // Þu anki zamaný alýyoruz
    time(&t);
    tm_info = localtime(&t);  // Sistem zamanýný yerel zamana dönüþtürüyoruz

    // Zamaný "YYYY-MM-DD HH:MM:SS" formatýnda formatlýyoruz
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    // Mesaj içeriði ve seviyesi belirliyoruz
    char message[] = "Disk dolulugu yuksek!";  // Örnek bir log mesajý
    char level[] = "WARNING";  // Log seviyesi (Uyarý)

    // Yeni bir syslog kaydýný ekliyoruz
    addSyslogEntry(timestamp, message, level);
}

// Ana fonksiyon
int main() {
    // Test amaçlý syslog kaydýný ekliyoruz
    addTestSyslog();
    
    // Syslog kayýtlarýný yazdýrýyoruz
    printf("Syslog Kayitlari:\n");
    printSyslogs();  // Baðlý listedeki tüm syslog kayýtlarýný ekrana yazdýrýyoruz

    return 0;  // Program sonlanýyor
}

