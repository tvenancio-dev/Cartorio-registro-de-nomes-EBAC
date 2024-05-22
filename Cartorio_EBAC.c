#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string's

int registro() //criação de função para cada opção do menu para melhorar a performance do sistema
{
	char arquivo[40]; //definição de uma variável/string local
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char email[100];
	char telefone[40];
	char cargo[40];
	
	printf("Digite abaixo os dados a serem cadastrados:\n\n- CPF: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuário (função "leia") / %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string's
	
	FILE *file; //criando o arquivo: função falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos criar um arquivo file
	file = fopen(arquivo, "w"); //criando o arquivo: aqui irá criar um arquivo com o nome "cpf", pois foi definido na função da linha 17. Como será um arquivo novo, foi usado o "w" (write)
	fprintf(file, cpf); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- Primeiro nome: ");	
	fgets(nome, sizeof(nome), stdin); //Lê uma linha inteira, incluindo espaços em branco, do texto digitado através entrada padrão, ou seja, do teclado (função "stdin")
	scanf("%s", nome); //armazenando o nome digitado pelo usuário (função "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, nome); //incluindo a variável "nome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Sobrenome completo: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); //Lê uma linha inteira, incluindo espaços em branco, do texto digitado através entrada padrão, ou seja, do teclado (função "stdin")
	scanf("%s", sobrenome); //armazenando o sobrenome digitado pelo usuário (função "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, sobrenome); //incluindo a variável "sobrenome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- E-mail: ");
	scanf("%s", email); //armazenando o e-mail digitado pelo usuário (função "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, email); //incluindo a variável "email" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Telefone: ");
	fgets(telefone, sizeof(telefone), stdin); //Lê uma linha inteira, incluindo espaços em branco, do texto digitado através entrada padrão, ou seja, do teclado (função "stdin")
	scanf("%s", telefone); //armazenando o telefone digitado pelo usuário (função "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, telefone); //incluindo a variável "telefone" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- Cargo na instituição: ");
	fgets(cargo, sizeof(cargo), stdin); //Lê uma linha inteira, incluindo espaços em branco, do texto digitado através entrada padrão, ou seja, do teclado (função "stdin")
	scanf("%s", cargo); //armazenando o cargo digitado pelo usuário (função "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, cargo); //incluindo a variável "cargo" no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\n### Usuário cadastrado com sucesso! ###\n\n");	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definição da linguagem e que se pode usar acentos
	
	char cpf[40]; //definição de uma variável/string local
	char conteudo[400];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuário (função "leia") / %s refere-se a string
	
	FILE *file; //função falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informação, por isso foi usado o "r" (read) 
	
	if(file == NULL) //função para sinalizar o usuário quando digitar um CPF não existente no banco de dados (NULL = nulo)
	{
		system("cls"); //limpar as opções do menu sempre que o usuário escolher alguma opção
		printf("\n### Usuário não cadastrado ou CPF digitado incorretamente! ###\n\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		
		// Separar os campos do conteúdo do arquivo a partir do elemento virgula
    	char *token = strtok(conteudo, ",");
    	printf("- CPF: %s\n", token);

    	token = strtok(NULL, ",");
    	printf("- Nome: %s\n", token);
    
    	token = strtok(NULL, ",");
     	printf("- Sobrenome: %s\n", token);

    	token = strtok(NULL, ",");
    	printf("- E-mail: %s\n", token);
    	
    	token = strtok(NULL, ",");
    	printf("- Telefone: %s\n", token); 	
    	    	
   		token = strtok(NULL, ",");
    	printf("- Cargo na instituição: %s\n", token);
				
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //definição de uma variável/string local
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuário (função "leia") / %s refere-se a string
	
	remove(cpf); //função para deletar o arquivo do "banco de dados"
	
	FILE *file; //função falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informação, por isso foi usado o "r" (read)
	
	if(file == NULL) //função para informar ao usuário que o arquivo foi deletado do banco de dados se o mesmo for "nulo"
	{
		system("cls"); //limpar as opções do menu sempre que o usuário escolher alguma opção
		printf("\n### Usuário deletado com sucesso! ###\n\n");
		system("pause");
	}
}


int main() //função principal (main) do sistema
{
	int opcao = 0; //definição de uma variável local
	int laco = 1;
	
	for(laco=1; laco=1;) //"macete" do operador de repetição para sempre retornar ao menu principal
	{
		system("cls"); //limpar as opções do menu sempre que o usuário escolher alguma opção
		setlocale(LC_ALL, "Portuguese"); //definição da linguagem e que se pode usar acentos
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes;\n");
		printf("\t2 - Consultar nomes;\n");
		printf("\t3 - Deletar nomes;\n");
		printf("\t4 - Sair do sistema.\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário (função "leia")
	
		system("cls"); //deletar todas mensagens antes desta função (limpar a tela)
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamando a função criada
			break;
			
			case 2:
			consulta(); //chamando a função criada
			break;
			
			case 3:
			deletar(); //chamando a função criada
			break;
			
			case 4:
			printf("### Até logo! ###\n");
			return 0;
			break;
			
			default:
			printf("### Essa opção não está diponível! ###\n");
			system("pause");
			break; //fim da seleção		
		}
	}
}
