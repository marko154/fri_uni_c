#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_WORD_LENGTH 20

int s, g, m;
char samostalniki[50][MAX_WORD_LENGTH + 1];
char samostalnikiToz[50][MAX_WORD_LENGTH + 1];
char glagoli[50][MAX_WORD_LENGTH + 1];

typedef struct {
    int glagol;
    int samostalnikToz;
} Odvisnik;

// all data needed to represent a sentence
int osebkovSamostalnik;
Odvisnik osebOdvisniki[50];
int stOsebOdvisnikov;
int glagol;
int predmetovSamostalnik;
Odvisnik predOdvisniki[50];
int stPredmetOdvisnikov;

void print_odvisnik(Odvisnik odvisnik) {
    printf(", ki %s %s", glagoli[odvisnik.glagol],
           samostalnikiToz[odvisnik.samostalnikToz]);
}

void print_sentence() {
    printf("%c", toupper(samostalniki[osebkovSamostalnik][0]));
    printf("%s", samostalniki[osebkovSamostalnik] + 1);

    for (int i = 0; i < stOsebOdvisnikov; i++) {
        print_odvisnik(osebOdvisniki[i]);
    }
    if (stOsebOdvisnikov > 0) printf(",");
    printf(" %s %s", glagoli[glagol], samostalnikiToz[predmetovSamostalnik]);
    for (int i = 0; i < stPredmetOdvisnikov; i++) {
        print_odvisnik(predOdvisniki[i]);
    }
    printf(".\n");
}

void stitch(int max, int firstSam, int firstGlagol);

void recurseOsebek(int max, int firstSam, int firstGlagol) {
    stitch(max, firstSam, firstGlagol);
    if (max == 0) return;
    for (int i = firstGlagol; i < g; i++) {
        for (int j = firstSam; j < s; j++) {
            osebOdvisniki[stOsebOdvisnikov++] = (Odvisnik){i, j};
            recurseOsebek(max - 1, j + 1, i + 1);
            stOsebOdvisnikov--;
        }
    }
}

void recursePredmet(int max, int firstSam, int firstGlagol) {
    print_sentence();
    if (max == 0) return;
    for (int i = firstGlagol; i < g; i++) {
        for (int j = firstSam; j < s; j++) {
            predOdvisniki[stPredmetOdvisnikov++] = (Odvisnik){i, j};
            recursePredmet(max - 1, j + 1, i + 1);
            stPredmetOdvisnikov--;
        }
    }
}

void stitch(int max, int firstSam, int firstGlagol) {
    for (int i = firstGlagol; i < g; i++) {
        for (int j = firstSam; j < s; j++) {
            glagol = i;
            predmetovSamostalnik = j;
            recursePredmet(max, j + 1, i + 1);
        }
    }
}

void sentences() {
    for (int i = 0; i < s; i++) {
        osebkovSamostalnik = i;
        recurseOsebek(m, i + 1, 0);
    }
}

int main() {
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf("%s %s", samostalniki[i], samostalnikiToz[i]);
    }
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%s", glagoli[i]);
    }
    scanf("%d", &m);
    sentences();
    return 0;
}