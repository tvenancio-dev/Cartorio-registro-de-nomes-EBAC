#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string's

int registro() //criacao de funcao para cada opcao do menu para melhorar a performance do sistema
{
	char arquivo[40]; //definicao de uma variavel/string local
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char email[100];
	char telefone[40];
	char cargo[40];
	
	printf("Digite abaixo os dados a serem cadastrados:\n\n- CPF: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string's
	
	FILE *file; //criando o arquivo: funcao falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos criar um arquivo file
	file = fopen(arquivo, "w"); //criando o arquivo: aqui ira criar um arquivo com o nome "cpf", pois foi definido na funcao da linha 17. Como sera um arquivo novo, foi usado o "w" (write)
	fprintf(file, cpf); //salvando o valor da variavel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- Primeiro nome: ");	
	fgets(nome, sizeof(nome), stdin); //Le uma linha inteira, incluindo espacos em branco, do texto digitado atraves entrada padrao, ou seja, do teclado (funcao "stdin")
	scanf("%s", nome); //armazenando o nome digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, nome); //incluindo a variavel "nome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Sobrenome completo: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); //Le uma linha inteira, incluindo espacos em branco, do texto digitado atraves entrada padrao, ou seja, do teclado (funcao "stdin")
	scanf("%s", sobrenome); //armazenando o sobrenome digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, sobrenome); //incluindo a variavel "sobrenome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- E-mail: ");
	scanf("%s", email); //armazenando o e-mail digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, email); //incluindo a variavel "email" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Telefone: ");
	fgets(telefone, sizeof(telefone), stdin); //Le uma linha inteira, incluindo espacos em branco, do texto digitado atraves entrada padrao, ou seja, do teclado (funcao "stdin")
	scanf("%s", telefone); //armazenando o telefone digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, telefone); //incluindo a variavel "telefone" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informacao, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
		
	printf("- Cargo na instituição: ");
	fgets(cargo, sizeof(cargo), stdin); //Le uma linha inteira, incluindo espacos em branco, do texto digitado atraves entrada padrao, ou seja, do teclado (funcao "stdin")
	scanf("%s", cargo); //armazenando o cargo digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informação, por isso foi usado o "a" (alter)
	fprintf(file, cargo); //incluindo a variavel "cargo" no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\n### Usuário cadastrado com sucesso! ###\n\n");	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definicao da linguagem e que se pode usar acentos
	
	char cpf[40]; //definicao de uma variavel/string local
	char conteudo[400];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	FILE *file; //funcao falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informacao, por isso foi usado o "r" (read) 
	
	if(file == NULL) //funcao para sinalizar o usuario quando digitar um CPF nao existente no banco de dados (NULL = nulo)
	{
		system("cls"); //limpar as opcoes do menu sempre que o usuario escolher alguma opcao
		printf("\n### Usuário não cadastrado ou CPF digitado incorretamente! ###\n\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		
		// Separar os campos do conteudo do arquivo a partir do elemento virgula
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
	char cpf[40]; //definicao de uma variavel/string local
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usuario (funcao "leia") / %s refere-se a string
	
	remove(cpf); //funcao para deletar o arquivo do "banco de dados"
	
	FILE *file; //funcao falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informacao, por isso foi usado o "r" (read)
	
	if(file == NULL) //funcao para informar ao usuario que o arquivo foi deletado do banco de dados se o mesmo for "nulo"
	{
		system("cls"); //limpar as opcoes do menu sempre que o usuario escolher alguma opcao
		printf("\n### Usuário deletado com sucesso! ###\n\n");
		system("pause");
	}
}


int main() //funcao principal (main) do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definicao da linguagem e que se pode usar acentos
	
	int opcao = 0; //definicao de uma variavel local
	int laco = 1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador | Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) //se a senha digitada for = a "admin", a lógica da linguagem atribui o valor zero para a comparacao
	{
		for(laco=1; laco=1;) //"macete" do operador de repeticao para sempre retornar ao menu principal
		{
			system("cls"); //limpar as opcoes do menu sempre que o usuario escolher alguma opcao
			setlocale(LC_ALL, "Portuguese"); //definicao da linguagem e que se pode usar acentos
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes;\n");
			printf("\t2 - Consultar nomes;\n");
			printf("\t3 - Deletar nomes;\n");
			printf("\t4 - Sair do sistema.\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuario (funcao "leia")
	
			system("cls"); //deletar todas mensagens antes desta funcao (limpar a tela)
		
		
			switch(opcao)
			{
				case 1:
				registro(); //chamando a funcao criada
				break;
			
				case 2:
				consulta(); //chamando a funcao criada
				break;
			
				case 3:
				deletar(); //chamando a funcao criada
				break;
			
				case 4:
				printf("### Até logo! ###\n");
				return 0;
				break;
			
				default:
				printf("### Essa opção não está diponível! ###\n");
				system("pause");
				break; //fim da selecao		
			}
		}
	}
	
	else
		printf("\n\nSenha incorreta!\n\n");
}
