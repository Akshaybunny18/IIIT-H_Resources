#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct m {
    int id;
    char title[100];
    char dir[100];
    float p;
    int q;
};

struct c {
    int id;
    char name[100];
    //int lo[10000][1000];
    int q;
};

int main() {
    int kk = 0;
    struct m mo[100];
    struct c co[100];
    FILE *file;
    char bu[1000];
	//printf("hi");
    int h = 0;
    int cc = 0, mm = 0;
    file = fopen("movies.txt", "r");
	//printf("hi");
    while (fgets(bu, 1000, file) != NULL) {
        h++;
    }
	//printf("%d\n", h);
    //h;
    for (int i = 0; i < 100; i++) {
        co[i].q = 0;
    }
    int k;
	int kkk=0;
    rewind(file);
    while(fscanf(file, "%d", &kkk)==1) {
		//printf("%d\n", kkk);
        if (kkk == 1) {
            fscanf(file, "%d", &co[cc].id);
            fscanf(file, "%s", bu);
            strcpy(co[cc].name, bu);
            cc++;
			//printf("%d %s", co[cc].id, co[cc].name);
        }
        if (kkk == 2) {
            fscanf(file, "%d", &mo[mm].id);
            fscanf(file, "%s", bu);
            strcpy(mo[mm].title, bu);
            fscanf(file, "%s", bu);
            strcpy(mo[mm].dir, bu);
            fscanf(file, "%f", &mo[mm].p);
            fscanf(file, "%d", &mo[mm].q);
            mm++;
			//printf("%d %s %s %d %f", mo[mm].id, mo[mm].title, mo[mm].dir, mo[mm].q, mo[mm].p);
        }
        if (kkk == 3) {
            for (int aa = 0; aa < mm; aa++) {
                printf("%d %s %s %d %.2f", mo[aa].id, mo[aa].title, mo[aa].dir, mo[aa].q, mo[aa].p);
            }
			//printf("%d %s %s %d %f", mo[aa].id, mo[aa].title, mo[aa].dir, mo[aa].q, mo[aa].p);
        }
        if (kkk == 4) {
            for (int aa = 0; aa < cc; aa++) {
                printf("%d %s %d", co[aa].id, co[aa].name, co[aa].q);
            }

        }
        if (kkk == 5) {
            fscanf(file, "%d", &k);
            fscanf(file, "%s", bu);
            fscanf(file, "%d", &kk);
            for (int v = 0; v < cc; v++) {
                if (co[v].id == k) {
                    co[v].q += 1;
                }
            }
            for (int v = 0; v < mm; v++) {
                if (mo[v].id == kk) {
                    mo[v].q--;
                    break;
                }
            }
        }
        if (kkk == 6) {
            fscanf(file, "%d", &k);
            fscanf(file, "%s", bu);
            fscanf(file, "%d", &kk);
            for (int v = 0; v < cc; v++) {
                if (co[v].id == k) {
                    co[v].q -= 1;
                }
			}
            for (int v = 0; v < mm; v++) {
                if (mo[v].id == kk) {
                    mo[v].q++;
                    break;
                }
            }
        }
    }
	//printf("\n");
}
