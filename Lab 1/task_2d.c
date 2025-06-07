#include <stdio.h>
#include <string.h>

int Check_updated_email(const char* email) {
    const char* domain = strchr(email, '@');
    
    if (domain == NULL) {
        return 0; 
    }

    if (strcmp(domain + 1, "sheba.xyz") == 0) {
        return 1; 
    }

    return 0; 
}

void email_domain_update(char* email) {
    char* domain = strchr(email, '@');
    
    if ( domain != NULL && strcmp(domain + 1, "kaaj.com")  ) {
        strcpy(domain + 1, "sheba.xyz");
    }
}

int main() {
    char email[200];
    
    printf("Enter email address: ");
    scanf("%s", email);

    if (Check_updated_email(email)) {
        printf("The email address is okay\n");
    } else {
        printf("The email address is outdated\n");

        char update[20];
    
        // printf("Want to update email address?: y/n ");
        // scanf("%s", update);
        // if (update == "y" || update == "Y"){
            
            
            
        //     email_domain_update(email);
        //     printf("Updating email address...\n");
        //     printf("Updated email address: %s\n", email);
        // }
    }

    return 0;
}