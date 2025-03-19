#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    char pw[61];
    char A[] = "000000", B[] = "001111", C[] = "010011", D[] = "011100";
    char E[] = "100110", F[] = "101001", G[] = "110101", H[] = "111010";
    
    char ans[11] = {0};
    
    scanf("%s", pw);
    
    for (int i = 0; i < N; i++) {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
        int valid = 0;

        for (int j = 0; j < 6; j++) {
            if (A[j] != pw[j + 6 * i]) a++;
            if (B[j] != pw[j + 6 * i]) b++;
            if (C[j] != pw[j + 6 * i]) c++;
            if (D[j] != pw[j + 6 * i]) d++;
            if (E[j] != pw[j + 6 * i]) e++;
            if (F[j] != pw[j + 6 * i]) f++;
            if (G[j] != pw[j + 6 * i]) g++;
            if (H[j] != pw[j + 6 * i]) h++;
        }

        if (a < 2) { ans[i] = 'A'; valid = 1; }
        else if (b < 2) { ans[i] = 'B'; valid = 1; }
        else if (c < 2) { ans[i] = 'C'; valid = 1; }
        else if (d < 2) { ans[i] = 'D'; valid = 1; }
        else if (e < 2) { ans[i] = 'E'; valid = 1; }
        else if (f < 2) { ans[i] = 'F'; valid = 1; }
        else if (g < 2) { ans[i] = 'G'; valid = 1; }
        else if (h < 2) { ans[i] = 'H'; valid = 1; }

        if (!valid) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    
    printf("%s\n", ans);
    return 0;
}