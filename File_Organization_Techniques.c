#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DIRECTORIES 10
#define MAX_FILES_PER_DIR 10
#define MAX_FILENAME_LENGTH 50
#define MAX_DIRECTORY_NAME 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char content[1000];
} File;

typedef struct {
    char name[MAX_DIRECTORY_NAME];
    File files[MAX_FILES_PER_DIR];
    int fileCount;
} Directory;

void listFiles(File files[], int fileCount);
void createFile(File files[], int *fileCount);
void readFile(File files[], int fileCount);

void listDirectories(Directory directories[], int dirCount);
void listFilesInDirectory(Directory directories[], int dirCount);
void createFileInDirectory(Directory directories[], int dirCount);
void readFileFromDirectory(Directory directories[], int dirCount);

int main() {
    File singleLevelFiles[MAX_FILES];
    Directory twoLevelDirectories[MAX_DIRECTORIES];
    int singleLevelFileCount = 0;
    int twoLevelDirCount = 0;
    int choice;

    while (1) {
        printf("\nChoose Directory Simulation\n");
        printf("1. Single Level Directory\n");
        printf("2. Two Level Directory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                while (1) {
                    printf("\nSingle Level Directory Menu\n");
                    printf("1. List Files\n");
                    printf("2. Create File\n");
                    printf("3. Read File\n");
                    printf("4. Go Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar(); 

                    switch (choice) {
                        case 1:
                            listFiles(singleLevelFiles, singleLevelFileCount);
                            break;
                        case 2:
                            createFile(singleLevelFiles, &singleLevelFileCount);
                            break;
                        case 3:
                            readFile(singleLevelFiles, singleLevelFileCount);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                    if (choice == 4) break;
                }
                break;

            case 2:
                while (1) {
                    printf("\nTwo Level Directory Menu\n");
                    printf("1. List Directories\n");
                    printf("2. List Files in Directory\n");
                    printf("3. Create File in Directory\n");
                    printf("4. Read File from Directory\n");
                    printf("5. Go Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar(); 

                    switch (choice) {
                        case 1:
                            listDirectories(twoLevelDirectories, twoLevelDirCount);
                            break;
                        case 2:
                            listFilesInDirectory(twoLevelDirectories, twoLevelDirCount);
                            break;
                        case 3:
                            createFileInDirectory(twoLevelDirectories, twoLevelDirCount);
                            break;
                        case 4:
                            readFileFromDirectory(twoLevelDirectories, twoLevelDirCount);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                    if (choice == 5) break;
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void listFiles(File files[], int fileCount) {
    if (fileCount == 0) {
        printf("No files to list.\n");
        return;
    }

    printf("Files in directory:\n");
    for (int i = 0; i < fileCount; ++i) {
        printf("%d. %s\n", i + 1, files[i].name);
    }
}

void createFile(File files[], int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("Directory is full. Cannot create more files.\n");
        return;
    }

    File newFile;
    printf("Enter file name: ");
    fgets(newFile.name, MAX_FILENAME_LENGTH, stdin);
    newFile.name[strcspn(newFile.name, "\n")] = '\0'; 

    printf("Enter file content: ");
    fgets(newFile.content, sizeof(newFile.content), stdin);
    newFile.content[strcspn(newFile.content, "\n")] = '\0';

    files[*fileCount] = newFile;
    (*fileCount)++;
    printf("File created successfully.\n");
}

void readFile(File files[], int fileCount) {
    int index;
    listFiles(files, fileCount);
    printf("Enter the file number to read: ");
    scanf("%d", &index);
    getchar(); 

    if (index < 1 || index > fileCount) {
        printf("Invalid file number.\n");
        return;
    }

    printf("Content of file '%s':\n%s\n", files[index - 1].name, files[index - 1].content);
}

void listDirectories(Directory directories[], int dirCount) {
    if (dirCount == 0) {
        printf("No directories to list.\n");
        return;
    }

    printf("Directories:\n");
    for (int i = 0; i < dirCount; ++i) {
        printf("%d. %s\n", i + 1, directories[i].name);
    }
}

void listFilesInDirectory(Directory directories[], int dirCount) {
    int dirIndex;
    listDirectories(directories, dirCount);
    printf("Enter the directory number to list files: ");
    scanf("%d", &dirIndex);
    getchar(); 

    if (dirIndex < 1 || dirIndex > dirCount) {
        printf("Invalid directory number.\n");
        return;
    }

    Directory dir = directories[dirIndex - 1];
    if (dir.fileCount == 0) {
        printf("No files in this directory.\n");
        return;
    }

    printf("Files in directory '%s':\n", dir.name);
    for (int i = 0; i < dir.fileCount; ++i) {
        printf("%d. %s\n", i + 1, dir.files[i].name);
    }
}

void createFileInDirectory(Directory directories[], int dirCount) {
    int dirIndex;
    listDirectories(directories, dirCount);
    printf("Enter the directory number to create a file: ");
    scanf("%d", &dirIndex);
    getchar(); 

    if (dirIndex < 1 || dirIndex > dirCount) {
        printf("Invalid directory number.\n");
        return;
    }

    Directory *dir = &directories[dirIndex - 1];
    if (dir->fileCount >= MAX_FILES_PER_DIR) {
        printf("Directory is full. Cannot create more files.\n");
        return;
    }

    File newFile;
    printf("Enter file name: ");
    fgets(newFile.name, MAX_FILENAME_LENGTH, stdin);
    newFile.name[strcspn(newFile.name, "\n")] = '\0'; 

    printf("Enter file content: ");
    fgets(newFile.content, sizeof(newFile.content), stdin);
    newFile.content[strcspn(newFile.content, "\n")] = '\0'; 

    dir->files[dir->fileCount] = newFile;
    dir->fileCount++;
    printf("File created successfully in directory '%s'.\n", dir->name);
}

void readFileFromDirectory(Directory directories[], int dirCount) {
    int dirIndex, fileIndex;
    listDirectories(directories, dirCount);
    printf("Enter the directory number to read a file: ");
    scanf("%d", &dirIndex);
    getchar(); 

    if (dirIndex < 1 || dirIndex > dirCount) {
        printf("Invalid directory number.\n");
        return;
    }

    Directory dir = directories[dirIndex - 1];
    if (dir.fileCount == 0) {
        printf("No files in this directory.\n");
        return;
    }

    listFilesInDirectory(directories, dirCount);
    printf("Enter the file number to read: ");
    scanf("%d", &fileIndex);
    getchar();

    if (fileIndex < 1 || fileIndex > dir.fileCount) {
        printf("Invalid file number.\n");
        return;
    }

    printf("Content of file '%s':\n%s\n", dir.files[fileIndex - 1].name, dir.files[fileIndex - 1].content);
}


'''
Output:

***********************************OUTPUT 1***********************************

braham@braham:~/Desktop/program$ gcc directory.c -o directory
braham@braham:~/Desktop/program$ ./directory

Choose Directory Simulation
1. Single Level Directory
2. Two Level Directory
3. Exit
Enter your choice: 1

Single Level Directory Menu
1. List Files
2. Create File
3. Read File
4. Go Back
Enter your choice: 2
Enter file name: file1.txt
Enter file content: Hello, this is file 1.

File created successfully.

Single Level Directory Menu
1. List Files
2. Create File
3. Read File
4. Go Back
Enter your choice: 1
Files in directory:
1. file1.txt

Single Level Directory Menu
1. List Files
2. Create File
3. Read File
4. Go Back
Enter your choice: 3
Enter the file number to read: 1
Content of file 'file1.txt':
Hello, this is file 1.

Single Level Directory Menu
1. List Files
2. Create File
3. Read File
4. Go Back
Enter your choice: 4


***********************************OUTPUT 2***********************************

braham@braham:~/Desktop/program$ gcc directory.c -o directory
braham@braham:~/Desktop/program$ ./directory

Choose Directory Simulation
1. Single Level Directory
2. Two Level Directory
3. Exit
Enter your choice: 2

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 1
Directories:
1. dir1

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 2
Enter the directory number to list files: 1
Files in directory 'dir1':
1. file1.txt

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 3
Enter the directory number to create a file: 1
Enter file name: file2.txt
Enter file content: Hello, this is file 2 in dir1.

File created successfully in directory 'dir1'.

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 2
Enter the directory number to list files: 1
Files in directory 'dir1':
1. file1.txt
2. file2.txt

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 4
Enter the directory number to read a file: 1
Enter the file number to read: 2
Content of file 'file2.txt':
Hello, this is file 2 in dir1.

Two Level Directory Menu
1. List Directories
2. List Files in Directory
3. Create File in Directory
4. Read File from Directory
5. Go Back
Enter your choice: 5
'''