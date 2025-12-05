#include <stdio.h>
#include <string.h>

struct Directory {
    char dname[20];
    char fname[20][20];
    int fcount;
} user[20];

int main() {
    int n, choice, u, i, j;
    char uname[20], fname[20];

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter directory (user) name %d: ", i + 1);
        scanf("%s", user[i].dname);
        user[i].fcount = 0;
    }

    while (1) {
        printf("\n--- TWO LEVEL DIRECTORY ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Directory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Create file
            printf("Enter user name: ");
            scanf("%s", uname);

            for (u = 0; u < n; u++) {
                if (strcmp(uname, user[u].dname) == 0)
                    break;
            }
            if (u == n) {
                printf("User not found.\n");
                break;
            }

            printf("Enter filename to create: ");
            scanf("%s", fname);

            strcpy(user[u].fname[user[u].fcount], fname);
            user[u].fcount++;

            printf("File created.\n");
            break;

        case 2: // Delete file
            printf("Enter user name: ");
            scanf("%s", uname);

            for (u = 0; u < n; u++) {
                if (strcmp(uname, user[u].dname) == 0)
                    break;
            }
            if (u == n) {
                printf("User not found.\n");
                break;
            }

            printf("Enter filename to delete: ");
            scanf("%s", fname);

            for (i = 0; i < user[u].fcount; i++) {
                if (strcmp(fname, user[u].fname[i]) == 0) {
                    user[u].fcount--;
                    strcpy(user[u].fname[i], user[u].fname[user[u].fcount]);
                    printf("File deleted.\n");
                    goto delEnd;
                }
            }
            printf("File not found.\n");
        delEnd:
            break;

        case 3: // Search file
            printf("Enter user name: ");
            scanf("%s", uname);

            for (u = 0; u < n; u++) {
                if (strcmp(uname, user[u].dname) == 0)
                    break;
            }
            if (u == n) {
                printf("User not found.\n");
                break;
            }

            printf("Enter filename to search: ");
            scanf("%s", fname);

            for (i = 0; i < user[u].fcount; i++) {
                if (strcmp(fname, user[u].fname[i]) == 0) {
                    printf("File found.\n");
                    goto searchEnd;
                }
            }
            printf("File not found.\n");
        searchEnd:
            break;

        case 4: // Display all
            printf("\n--- DIRECTORY CONTENTS ---\n");
            for (i = 0; i < n; i++) {
                printf("\nUser: %s\n", user[i].dname);
                if (user[i].fcount == 0)
                    printf("No files.\n");
                else {
                    for (j = 0; j < user[i].fcount; j++)
                        printf("%s\n", user[i].fname[j]);
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}

