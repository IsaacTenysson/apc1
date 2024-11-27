#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char id[3];
    float valor;
    char nome[50];    
    int qtd;
    int flag;
} Dados;

typedef struct 
{
    float valor;
    char nome[50];    
    int qtd;
    int flag;
} Dados_Temp;

int main (){
    char opcao = '\0';
    Dados dado [100];
    Dados_Temp dado_t;
    int total_cadastro = 0; 
    char temp_name [50];
    char op = '\0';
    int q = 0;

    memset(dado, '0' , sizeof(dado));
    memset(temp_name, '\0' , sizeof(temp_name));

    while (opcao != 5) {
        opcao = '\0';
        system("clear");
        printf("\n------------MENU---------------\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1-Cadastrar Produto.\n");
        printf("2-Editar Produto.\n");
        printf("3-Excluir Produto.\n");
        printf("4-Listar Produtos.\n");
        printf("5-Sair do Programa.\n\n");
        printf("Opcao => ");
        fflush(stdin);
        scanf("%[^\n]s", &opcao);
        getchar();
        fflush(stdin);

        switch(opcao){

            case '1':{
                if ( total_cadastro < 100){
                    system("clear");
                    printf("----Cadastrar Produto----\n");
                    printf("Insira o nome do Produto: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &dado[total_cadastro].nome);
                    fflush(stdin); 
                    printf("Insira a Quantidade do Produto: ");
                    scanf("%i", &dado[total_cadastro].qtd);
                    printf("Insira o valor do Produto no Seguinte Formato (00.00) : R$ ");
                    scanf("%f", &dado[total_cadastro].valor);
                    dado[total_cadastro].flag = 1;
                    sprintf(dado[total_cadastro].id,"%i\0", total_cadastro);
                    total_cadastro++;

                } else {
                    printf("Cadastro Cheio!\n");
                } 
            break;}
            case '2':{ 
              q = 0;
              while(q != 1){  
                op = '\0';
                system("clear");
                printf("            ----Editar Produto----\n *Aperte enter para sair*\n");
        
                if (total_cadastro == 0){
                    printf("Cadastro Vazio\n");
                    q = 1;
                    break;
                }

                printf("Voce deseja listar os produtos ou buscar por nome?\n");
                printf("1- Buscar por nome\n2- Listar Produtos\n Opcao =>");
                scanf("%[^\n]s",&op);
        
                switch(op){
                    
                    case'1':{
                        memset(temp_name, '\0' , sizeof(temp_name));
                        system("clear");
                        printf("            ----Editar Produto----\n");
                        printf("Insira o nome ou parte do nome para buscar:");
                        fflush(stdin);
                        scanf("%[^\n]s", temp_name);
                        fflush(stdin);
                        printf("ID-Nome do produto%-15s \t Qtd \t Valor Unit\n");
                        for(int j=0;j<total_cadastro; j++){       
                            if(dado[j].flag == 1){
                                if (strstr(dado[j].nome, temp_name)){
                                    printf("%s-%-30s \t %i \t R$ %.2f\n", dado[j].id,dado[j].nome, dado[j].qtd, dado[j].valor);
                                }
                            }
                        }
                        memset(temp_name, '\0' , sizeof(temp_name)); 
                        printf("Insira nome completo ou ID do produto que deseja editar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", temp_name);
                        fflush(stdin);
           
                        for (int i = 0; i < total_cadastro; i++){
                                if( strcmp(temp_name,dado[i].nome)==0 || strcmp(temp_name,dado[i].id)==0 ){
                                    system("clear");            
                                    op = '\0';
                                    printf("Nome do Produto%-15s \t Qtd \t Valor Unit \n");
                                    printf("%-30s \t %i \t R$ %.2f\n", dado[i].nome, dado[i].qtd, dado[i].valor);
                                    printf("Este e o produto que deseja editar? \n");
                                    printf(" 0-Nao | 1-Sim:  \n");
                                    printf("Opcao => ");
                                    fflush(stdin);
                                    scanf("%c", &op);
                                    fflush(stdin);
                                    switch(op){

                                        case '1':{
                                            char h = '\0';
                                            system ("clear");
                                            printf("Produto --> %s\n", dado[i].nome);
                                            printf("Qual informacao deseja alterar?\n");
                                            printf("1-Nome | 2-Quantidade | 3-Valor \n");
                                            printf("Opcao => ");
                                            fflush(stdin);
                                            scanf("%c", &h);
                                            fflush(stdin); 
                                            switch (h) {
                                
                                                case '1':{
                                                    char f = '\0';
                                                    do{   
                                                        printf("Insira o novo nome: ");
                                                        scanf("%[^\n]s", dado_t.nome);
                                                        system ("clear");
                                                        printf("\n Nome Atual: %s | Novo nome: %s\n\n", dado[i].nome, dado_t.nome);
                                                        printf("Alteracao esta correta? ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        fflush(stdin);
                                                        if(f == '1'){
                                                            strcpy(dado[i].nome,dado_t.nome);
                                                            q = 1;
                                                        }
                                                    } while (f !='1');
                            
                                                break; }
                                                case '2':{
                                                    char f ='\0';
                                                    do{
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Quantidade Atual: %i\n", dado[i].qtd);
                                                        printf("Insira a nova quantidade: ");
                                                        scanf("%i", &dado_t.qtd);
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("\nQuantidade Atual: %i | Nova Quantidade: %i\n\n", dado[i].qtd, dado_t.qtd);
                                                        printf("Confirmar alteracao?\n ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        fflush(stdin);
                                                        if(f == '1'){
                                                            dado[i].qtd = dado_t.qtd;
                                                            q = 1;
                                                        }
                                                    } while (f !='1');
                                
                                                break;}
                                                case '3':{
                                                    char f  = '\0';
                                                    do{    
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Valor Atual: %.2f\n", dado[i].valor);
                                                        printf("Insira o novo valor: ");
                                                        scanf("%f", &dado_t.valor);
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Valor Atual: R$ %.2f | Novo Valor: %.2f \n", dado[i].valor, dado_t.valor);
                                                        printf("Confirmar alteracao?\n ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        fflush(stdin);
                                
                                                        if(f == '1'){
                                                            dado[i].valor = dado_t.valor;
                                                            q = 1;
                                                        }
                            
                                                    } while (f !='1');
                                                break;}        
                                                default: printf("Insira uma opção valida");
                                            }
                                        break;}        
                                        case '0': break;
                                        default: printf("\nInsira uma opcao valida !\n");
                                    }
                                }
                        }                       
                    break;}                        
                    case'2':{
                        memset(temp_name, '\0' , sizeof(temp_name));
                        system("clear");
                        printf("            ----Editar Produto----\n");
                        fflush(stdin);
                        printf("ID-Nome do Produto%-15s \t Qtd \t Valor Unit\n");
                        for(int j=0;j<total_cadastro; j++){       
                                if(dado[j].flag == 1){
                                printf("%s-%-30s \t %i \t R$ %.2f\n", dado[j].id,dado[j].nome, dado[j].qtd, dado[j].valor);
                                }
                        }    
                        printf("Insira o nome completo ou ID do produto que deseja editar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", temp_name);
                        fflush(stdin);
           
                        for (int i = 0; i < total_cadastro; i++){
                                if( strcmp(temp_name,dado[i].nome)==0 || strcmp(temp_name,dado[i].id)==0 ){
                                    system("clear");            
                                    op = '\0';
                                    printf("Nome do Produto%-15s \t Qtd \t Valor Unit \n");
                                    printf("%-30s \t %i \t R$ %.2f\n", dado[i].nome, dado[i].qtd, dado[i].valor);
                                    printf("Este e o produto que deseja editar? \n");
                                    printf(" 0-Nao | 1-Sim:  \n");
                                    printf("Opcao => ");
                                    fflush(stdin);
                                    scanf("%c", &op);
                                    fflush(stdin);
                    
                                    switch(op){

                                        case '1':{
                                            char h = '\0';
                                            system ("clear");
                                            printf("Produto --> %s\n", dado[i].nome);
                                            printf("Qual informacao deseja alterar?\n");
                                            printf("1-Nome | 2-Quantidade | 3-Valor \n");
                                            printf("Opcao => ");
                                            fflush(stdin);
                                            scanf("%c", &h);
                                            getchar(); 
                                            switch (h) {
                                
                                                case '1':{
                                                    char f = '\0';
                                                    do{   
                                                        printf("Insira o novo nome: ");
                                                        scanf("%[^\n]s", dado_t.nome);
                                                        system ("clear");
                                                        printf("\n Nome Atual: %s | Novo nome: %s\n\n", dado[i].nome, dado_t.nome);
                                                        printf("Alteracao esta correta? ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        fflush(stdin);
                                                        if(f == '1'){
                                                            strcpy(dado[i].nome,dado_t.nome);
                                                        }
                                                    } while (f !='1');
                            
                                                break; }
                                                case '2':{
                                                    char f ='\0';
                                                    do{
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Quantidade Atual: %i\n", dado[i].qtd);
                                                        printf("Insira a nova quantidade: ");
                                                        scanf("%i", &dado_t.qtd);
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("\nQuantidade Atual: %i | Nova Quantidade: %i\n\n", dado[i].qtd, dado_t.qtd);
                                                        printf("Confirmar alteracao?\n ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        getchar();
                                                        if(f == '1'){
                                                            dado[i].qtd = dado_t.qtd;
                                                        }
                                                    } while (f !='1');
                                
                                                break;}
                                                case '3':{
                                                    char f  = '\0';
                                                    do{    
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Valor Atual: %.2f\n", dado[i].valor);
                                                        printf("Insira o novo valor: ");
                                                        scanf("%f", &dado_t.valor);
                                                        system ("clear");
                                                        printf("Produto --> %s\n", dado[i].nome);
                                                        printf("Valor Atual: R$ %.2f | Novo Valor: %.2f \n", dado[i].valor, dado_t.valor);
                                                        printf("Confirmar alteracao?\n ");
                                                        printf("0- Nao | 1- Sim:");
                                                        fflush(stdin);
                                                        scanf("%c", &f);
                                                        getchar();
                                
                                                        if(f == '1'){
                                                            dado[i].valor = dado_t.valor;
                                                        }
                            
                                                    } while (f !='1');
                                                break;}        
                                                default: printf("Insira uma opção valida");}
                                        break;}        
                                        case '0': break;
                                        default: printf("\nInsira uma opcao valida !\n");
                                    }    
                                }
                        }    
                    break;}
                    default: q = 1; printf("\nInsira uma opcao valida !\n");
                }    
              }
            break;}             
            case '3':{
                system("clear");
                printf("----Excluir Produtos----\n");
                fflush(stdin);
                printf("ID-Nome do Produto %-15s \t Qtd \t Valor Unit \t Valor Total \n");
                if (total_cadastro == 0){
                    printf("Cadastro Vazio\n");
                    break;
                }
                for(int j = 0;j<total_cadastro;j++){
                    if(dado[j].flag == 1){
                    float valor_total = dado[j].qtd * dado[j].valor;
                        printf("%s-%-30s \t %i \t R$ %.2f \t R$ %.2f\n", dado[j].id,dado[j].nome, dado[j].qtd, dado[j].valor, valor_total);   
                    }
                }
                    memset(temp_name, '\0' , sizeof(temp_name)); 
                    printf("Insira o nome completo ou ID do produto que deseja excluir: ");
                    fflush(stdin);
                    scanf("%[^\n]s", temp_name);
                    fflush(stdin);
                    int e = 0;
                    int i = 0;
                    q = 0;
                    
                    while(q != 1){
                        if( strcmp(temp_name,dado[i].nome)==0 || strcmp(temp_name,dado[i].id)==0 ){
                            if(strcmp(temp_name,"\n")==0){
                              printf("Produto Nao encontrado \n");
                            break;   
                            }
                            system("clear");
                            printf("Nome do Produto%-15s \t Qtd \t Valor Unit \t Valor Total \n");
                            float valor_total = dado[i].qtd * dado[i].valor;
                            printf("%-30s \t %i \t R$ %.2f \t R$ %.2f\n", dado[i].nome, dado[i].qtd, dado[i].valor, valor_total);
                            e = i;
                            q = 1;
                            }
                        i++;
                        if(i>total_cadastro){
                            printf("Produto Nao encontrado \n");
                            break;
                        }
                    }    
                            if(e==0 && q==0){
                                break;
                            }
                            op = '\0';
                            printf("confirmar exclusao deste produto?\n");
                            printf(" 0-Nao | 1-Sim:  \n");
                            printf("Opcao => ");
                            fflush(stdin);
                            scanf("%c", &op);
                            fflush(stdin);   
                            switch(op){
                                case '1':{                                 
                                    strcpy(dado[total_cadastro-1].id,dado[e].id);
                                    dado[e]=dado[total_cadastro-1];
                                    memset(&dado[total_cadastro-1], 0, sizeof(dado[total_cadastro-1]));
                                    total_cadastro--;
                                break;}
                                case '0': break;
                                default: printf("\nInsira uma opcao valida !\n"); 
                            }                   
            break;}
            case '4':{
               system("clear");
               printf("----Listar Produtos----\n");
               fflush(stdin);
               printf("Nome do Produto%-15s \t Qtd \t Valor Unit \t Valor Total \n");
               if (total_cadastro == 0){
                    printf("Cadastro Vazio\n");
                    break;
                }
               for (int j = 0; j < total_cadastro; j++){
               if (dado[j].flag == 1){
                
                float valor_total = dado[j].qtd * dado[j].valor;       
                printf("%-30s \t %i \t R$ %.2f \t R$ %.2f\n", dado[j].nome, dado[j].qtd, dado[j].valor, valor_total);
        
            }
               }
        
            break; }    
            case '5':{
        printf("Saindo do programa!\n");
        return 0; 
        break; }
            default : printf("\nInsira uma opcao valida !\n");
        }

        if (opcao != 5){
            printf("Pressione ENTER para continuar...");
            fflush(stdin);
            getchar();
   }
    }    
    
    return 0; 
}