#include <stdio.h>
#include <string.h>

struct {
    char dname[20];
    char fname[20][20];
    int fcount;
} dir;

int main() {
    int choice;
    char name[20];

    // Directory name
    printf("Enter directory name: ");
    scanf("%s", dir.dname);
    dir.fcount = 0;

    while (1) {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:   // Create file
            printf("Enter filename to create: ");
            scanf("%s", name);
            strcpy(dir.fname[dir.fcount], name);
            dir.fcount++;
            printf("File created.\n");
            break;

        case 2:   // Delete file
            printf("Enter filename to delete: ");
            scanf("%s", name);

            for (int i = 0; i < dir.fcount; i++) {
                if (strcmp(name, dir.fname[i]) == 0) {
                    printf("File deleted.\n");
                    dir.fcount--;
                    strcpy(dir.fname[i], dir.fname[dir.fcount]);
                    goto endDelete;
                }
            }
            printf("File not found.\n");
        endDelete:
            break;

        case 3:   // Search file
            printf("Enter filename to search: ");
            scanf("%s", name);

            for (int i = 0; i < dir.fcount; i++) {
                if (strcmp(name, dir.fname[i]) == 0) {
                    printf("File found.\n");
                    goto endSearch;
                }
            }
            printf("File not found.\n");
        endSearch:
            break;

        case 4:   // Display all files
            printf("\nDirectory: %s\n", dir.dname);
            if (dir.fcount == 0) {
                printf("No files present.\n");
            } else {
                for (int i = 0; i < dir.fcount; i++)
                    printf("%s\n", dir.fname[i]);
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

