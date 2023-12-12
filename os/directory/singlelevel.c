#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Directory
{
    char name[20];
    char files[10][20];
    int fileCount;
};

int main()
{
    int choice;
    char filename[30];
    struct Directory directory;
    directory.fileCount = 0;

    printf("\nEnter the name of the directory: ");
    scanf("%s", directory.name);

    while (1)
    {
        printf("\nOptions:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name of the file: ");
            scanf("%s", directory.files[directory.fileCount]);
            printf("File `%s` has been created.\n", directory.files[directory.fileCount]);
            directory.fileCount++;
            break;

        case 2:
            if (directory.fileCount == 0)
                printf("Directory is empty. No files to delete.\n");
            else
            {
                printf("Enter the name of the file to delete: ");
                scanf("%s", filename);
                int found = 0;
                for (int i = 0; i < directory.fileCount; i++)
                {
                    if (strcmp(filename, directory.files[i]) == 0)
                    {
                        printf("File `%s` has been deleted.\n", filename);
                        strcpy(directory.files[i], directory.files[directory.fileCount - 1]);
                        directory.fileCount--;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("File `%s` not found.\n", filename);
            }
            break;

        case 3:
            if (directory.fileCount == 0)
                printf("Directory is empty. No files to search for.\n");
            else
            {
                printf("Enter the name of the file to search: ");
                scanf("%s", filename);
                int found = 0;
                for (int i = 0; i < directory.fileCount; i++)
                {
                    if (strcmp(filename, directory.files[i]) == 0)
                    {
                        printf("File `%s` is present in the directory.\n", filename);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("File `%s` not found.\n", filename);
            }
            break;

        case 4:
            if (directory.fileCount == 0)
                printf("Directory is empty.\n");
            else
            {
                printf("Files in the directory: ");
                for (int i = 0; i < directory.fileCount; i++)
                    printf("%s ", directory.files[i]);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting the program...\n");
            exit(0);
            break;


        default:
            printf("Invalid choice. Please enter a valid option (1-5).\n");
        }
    }

    return 0;
}
