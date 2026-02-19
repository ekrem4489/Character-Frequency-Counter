#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // strlen ve diðer string fonksiyonlarý için gerekli
#include <ctype.h>  // tolower fonksiyonu için gerekli

// Fonksiyon prototipi
void calculate(char*);

int main() {
    char message[100];
    
    printf("Enter a sentence: "); // puts yerine printf de kullanýlabilir
    gets(message);
    
    calculate(message);
    
    return 0;
}

void calculate(char* ptr) {
    int letters[26], i = 0, length;
    char activeLetter;
    length = strlen(ptr);

    // Diziyi sýfýrlama (Her harfin sayýsýný 0'dan baþlatýyoruz)
    for (i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    // Harfleri sayma döngüsü
    for (i = 0; i < length; i++) {
        // Karakteri küçük harfe çeviriyoruz (Büyük/küçük duyarlýlýðýný kaldýrmak için)
        activeLetter = tolower(*(ptr + i));
        
        // Sadece 'a' ve 'z' arasýndaki harfleri say (Boþluk veya noktalamalarý atla)
        if (activeLetter >= 'a' && activeLetter <= 'z') {
            // ASCII'de 'a' harfi 97'dir. activeLetter - 97 iþlemi, 
            // 'a' için 0, 'b' için 1 indeksini verir.
            letters[activeLetter - 97]++;
        }
    }

    // Sonuçlarý ekrana yazdýrma
    printf("Letter\tRepeat\n");
    printf("------\t------\n");

    for (i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            // i + 97 yaparak tekrar karakter karþýlýðýný buluyoruz
            printf("%c\t%d\n", i + 97, letters[i]);
        }
    }
}

