#include <stdio.h>

void acesso(){
       printf("Parabens!\n");
       printf("Acesso livre!\n");
          }


void login() {
        char buffer[20];
        printf("Senha:\n");
        scanf("%s", buffer);
        printf("login incorreto: %s\n", buffer);
             }

int main(){
     
      login();
      return 0;
}
