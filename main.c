#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Syslog kayd�n� temsil eden d���m yap�s�
struct SyslogNode {
    char timestamp[100];   // Log mesaj�n�n zaman�
    char message[512];     // Log mesaj�n�n i�eri�i
    char level[20];        // Log seviyesi (INFO, ERROR, WARN vb.)
    struct SyslogNode *next; // Sonraki d���me i�aret�i
};

// Ba�l� listenin ba�� (Ba�lang��ta NULL)
struct SyslogNode* head = NULL;

// Yeni bir syslog kayd�n� ba�l� listeye ekleme fonksiyonu
void addSyslogEntry(char* timestamp, char* message, char* level) {
    // Yeni bir syslog kayd� i�in haf�zada yer ay�r�yoruz
    struct SyslogNode* newNode = (struct SyslogNode*)malloc(sizeof(struct SyslogNode));
    
    // Yeni d���me de�erleri at�yoruz
    strcpy(newNode->timestamp, timestamp);  // Zaman damgas�
    strcpy(newNode->message, message);      // Mesaj i�eri�i
    strcpy(newNode->level, level);          // Log seviyesi
    
    // Yeni d���m�n next i�aret�isini �u anki head'e y�nlendiriyoruz
    newNode->next = head;  
    head = newNode;  // Listeyi g�ncelleyip, yeni d���m� ba�a ekliyoruz
}

// Ba�l� listeyi ekrana yazd�ran fonksiyon
void printSyslogs() {
    struct SyslogNode* current = head;  // Listeyi ba�tan ba�lat�yoruz
    
    // Ba�l� listedeki t�m syslog kay�tlar�n� gezip ekrana yazd�r�yoruz
    while (current != NULL) {  // Listeyi sonuna kadar gez
        printf("Timestamp: %s\n", current->timestamp);  // Zaman damgas�
        printf("Level: %s\n", current->level);          // Log seviyesi
        printf("Message: %s\n", current->message);      // Mesaj i�eri�i
        printf("------------------------------------\n");
        current = current->next;  // Sonraki d���me ge�
    }
}

// �u anki zaman� alarak syslog kayd�n� ekleyen fonksiyon
void addTestSyslog() {
    time_t t;  // Zaman� alabilmek i�in de�i�ken
    struct tm *tm_info;  // Zaman bilgisini tutacak yap�
    char timestamp[100];  // Zaman damgas� i�in dizi

    // �u anki zaman� al�yoruz
    time(&t);
    tm_info = localtime(&t);  // Sistem zaman�n� yerel zamana d�n��t�r�yoruz

    // Zaman� "YYYY-MM-DD HH:MM:SS" format�nda formatl�yoruz
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    // Mesaj i�eri�i ve seviyesi belirliyoruz
    char message[] = "Disk dolulugu yuksek!";  // �rnek bir log mesaj�
    char level[] = "WARNING";  // Log seviyesi (Uyar�)

    // Yeni bir syslog kayd�n� ekliyoruz
    addSyslogEntry(timestamp, message, level);
}

// Ana fonksiyon
int main() {
    // Test ama�l� syslog kayd�n� ekliyoruz
    addTestSyslog();
    
    // Syslog kay�tlar�n� yazd�r�yoruz
    printf("Syslog Kayitlari:\n");
    printSyslogs();  // Ba�l� listedeki t�m syslog kay�tlar�n� ekrana yazd�r�yoruz

    return 0;  // Program sonlan�yor
}

