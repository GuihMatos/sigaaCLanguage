#include <stdio.h>
#include <string.h>

#define TAM 30

struct Disciplina{
	char codigo[TAM];
	char nome[TAM];
	int CH;
	float nota;
} disc[TAM];
//todas as funcoes foram incializadas na declaracao
void Alterar(struct Disciplina disc[TAM]){
	char codigo_aux[TAM];
	getchar();
	printf("\n-Digite o codigo da disciplina que deseja alterar: ");
	fgets(codigo_aux, TAM, stdin);
	int g;
	for(g = 0;g < TAM;g++){
		if(strcmp(disc[g].codigo, codigo_aux) == 0){ //Compara se as strings sao iguais
			printf("*A disciplina existe*");
			printf("\n-Digite o novo nome da disciplina: ");
			fgets(disc[g].nome, TAM, stdin);
			printf("\n-Insira a nova CH da disciplina: ");
			scanf(" %d", &disc[g].CH);
			printf("\n-Atualize a nota: ");
			scanf(" %f", &disc[g].nota);
		}
	}
	printf("\n----DISCIPLINA ALTERADA!----\n");
}

void Excluir(struct Disciplina disc[TAM]){
	char codigo_aux[TAM];
	printf("-Digite o codigo da disciplina que deseja excluir: ");
	getchar();
	fgets(codigo_aux, TAM, stdin);
	int f;
	for(f = 0;f < TAM;f++){ //zera a disciplina
		if(strcmp(disc[f].codigo, codigo_aux) == 0){
		disc[f].CH = 0;
		disc[f].nota = 0;
		int e;
			for(e = 0;e < TAM;e++){
			disc[f].codigo[e] = 0;
			disc[f].nome[e] = 0;
			}
		}
	}
	printf("\n----DISCIPLINA EXCLUIDA----\n");
}

void Localizar(struct Disciplina disc[TAM]){
	char codigo_aux[TAM];
	printf("-Informe o codigo da disciplina p/ localiza-la: ");
	getchar();
	fgets(codigo_aux, TAM, stdin);
	int v;
	for(v = 0;v < TAM;v++){
		if(strcmp(disc[v].codigo, codigo_aux) == 0){
			printf("Legenda: \n[Codigo, Nome, CH, Nota]\n"); //o print nao exibiu exatamente dessa forma
			printf("\n[%s, %s, %d, %.3f]", disc[v].codigo, disc[v].nome, disc[v].CH, disc[v].nota);//ajeitar esse printe aqui
 		}
	}
}

void Listar(struct Disciplina disc[TAM]){
	printf("\nLegenda: \n[Codigo, Nome, CH, Nota]\n");
    int p;
	for(p = 0;p < TAM;p++){ //por causa do f-g-e-t-s, saltou duas linhas em cada disciplina 
		printf("\n[%s, %s, %d, %.3f]", disc[p].codigo, disc[p].nome, disc[p].CH, disc[p].nota);//ajeitar esse printe aqui
	}
}

void Sair(){ //antes de finalizar, o conteudo da s-t-r-u-c-t eh mandado para um arquivo
	FILE *pont_arq;
	pont_arq = fopen("ARQUIVO.txt", "a");

	if(pont_arq == NULL){
	printf("ERRO!Nao foi possivel guardar dados em arquivo");
	}
	else{
	printf("Dados guardados em arquivo\n");
	}
	int x;
	for(x = 0;x < TAM;x++){
	fprintf(pont_arq, "\n%s", disc[x].codigo);
	fprintf(pont_arq, "\n%s", disc[x].nome);
	fprintf(pont_arq, "\n%d", disc[x].CH);
	fprintf(pont_arq, "\n%.3f", disc[x].nota);
	fprintf(pont_arq,"\n------------------");
	}
	fclose(pont_arq);
	printf("\n****App fechado.****\n");
}

int main(){ //rotina principal do programa
	
	int op, i = 0;
    while(op != 6){
		printf("\nDigite o numero da opcao desejada: \n");
        printf("\n[1]CADASTRAR DISCIPLINA\n[2]ALTERAR DISCIPLINA\n[3]EXCLUIR DISCIPLINA\n[4]LOCALIZAR DISCIPLINA\n[5]LISTAR TODAS AS DISCIPLINAS\n[6]SAIR\n");
		printf("\n-OPCAO: ");
        scanf(" %d", &op);
        if(op == 1){
			getchar();
			printf("\n-Digite o codigo da disciplina: ");
			fgets(disc[i].codigo, TAM, stdin);
			printf("\n-Digite o nome da disciplina: ");
			fgets(disc[i].nome, TAM, stdin);
			printf("\n-Insira a CH da disciplina: ");
			scanf(" %d", &disc[i].CH);
			printf("\n-Informe a nota: ");
			scanf(" %f", &disc[i].nota);
			printf("\nDISCIPLINA CADASTRADA COM SUCESSO!");
			i += 1;
		}
		else if(op == 2){
			Alterar(disc);
		}
		else if(op == 3){
			Excluir(disc);			
		}
		else if(op == 4){
			Localizar(disc);
		}
		else if(op == 5){
			Listar(disc);
		}
		else if(op == 6){
			Sair();
			break;
		}
	}
	return 0;
}