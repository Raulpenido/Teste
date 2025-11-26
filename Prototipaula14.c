#include <stdio.h>
#include <string.h>

int main()
{
    int escolha;
    int encerrar = 0;

    
    while(encerrar !=1){
    

    printf("1 Registrar equipamento\n");
    printf("2 Listar equipamentos\n");
    printf("3 Buscar equipamento\n");
    printf("4 Encerrar\n");
    scanf("%d", &escolha);
    getchar();

    switch (escolha)
    {
    case 1:
        {
    FILE *file = fopen("caxumba.txt", "a+");
    if (file == NULL)
    {
        printf("Error ao abrir o arquivo\n");
        
        return 0;
    }
            char registro[100];
            int ID;
            
        printf("Digite o ID\n");
        scanf("%d", &ID);
        getchar();
        printf("Nome equipamento selecionado\n");
        fgets(registro, sizeof(registro), stdin);
        strtok(registro, "\n");
        fprintf(file, "%d;%s\n", ID, registro);
        
        fclose(file);
        break;
        }
    case 2:
        {
            FILE *file = fopen("caxumba.txt", "r");
    if (file == NULL)
    {
        printf("Error ao abrir o arquivo\n");
        
        return 0;
    }
            char linha[100];
            printf("Listar equipamentos selecionado\n");
            while (fgets(linha, sizeof(linha), file) != NULL)
            {
                printf("%s", linha);
            }
            fclose(file);
        break;
        }

    case 3:
    {
        FILE *file = fopen("caxumba.txt", "r");
    if (file == NULL)
    {
        printf("Error ao abrir o arquivo\n");
        
        return 0;
    }
        int idn;
        char linha[100];
        char separa1[100];
        int separa2;
        int veri = 0;
        printf("Digite o id\n");
        scanf("%d", &idn);
        getchar();
        while (fgets(linha, sizeof(linha), file) != NULL)
            {
                sscanf(linha, "%d;%s", &separa2, separa1);
                if(separa2 == idn){
                    printf("Equipamento encontrado\n");
                    printf("%s", linha);
                    veri++;
                    continue;

                }
                else{

                }

               
            }
        if(veri == 0){
            printf("Equipamento não encontrado\n");
        }
        fclose(file);
        break;
        
    }

    case 4:
    {
        encerrar = 1;
        break;
    }

    default:
    {
        printf("Opcao invalida\n");
        break;

    }

    }
}

FILE *file = fopen("caxumba.txt", "w");
fclose(file);


    
    


    return 0;

}
