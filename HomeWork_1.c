#include <stdio.h>
#include <string.h>

int main(){
    char line[255], login[255];
    FILE *file;
    file = fopen("/etc/passwd", "r"); 
    if (file == NULL){
        printf("Error\n");
        return -1;
    }
    printf("Enter a login: ");
    scanf("%s", login);
    char* user_info;
    while (fgets(line, sizeof(line),file)){
        if (strncmp(line, login, strlen(login)) == 0){
            char* username = strtok(line,":");
            strtok(NULL,":");
            strtok(NULL,":");
            strtok(NULL,":");
            user_info = strtok(NULL, ":");
            break;

        }
    }
    while (1)
    {
        if (user_info != NULL) 
        {
            printf("Username: %s\n", user_info);
        } 
        else 
        {
            printf("Login is not found\n");
        }
    fclose(file);
    return 0;
    }
    
}