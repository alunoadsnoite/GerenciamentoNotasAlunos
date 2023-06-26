#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[30];
  int matricula;
  float av1, av2, av3, media;
} Aluno;
// Função para adicionar um aluno
void adicionarAluno(Aluno alunos[], int *numAlunos) {
  if (*numAlunos == 100) {
    printf("Nao e possivel adicionar mais alunos. Limite maximo atingido.\n");
    printf("\033[1;31m");
    return;
  }
  Aluno novoAluno;
  // Solicita os dados do novo aluno ao usuário.
  printf("Digite o nome do aluno: ");
  scanf(" %20[^\n]s", novoAluno.nome);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &novoAluno.matricula);

  printf("Digite a nota da AV1: ");
  scanf("%f", &novoAluno.av1);
  if (novoAluno.av1 < 0 || novoAluno.av1 > 10) {
    printf("Erro. A nota deve estar no intervalo de 0 a 10.\n");
    return;
  }
  printf("Digite a nota da AV2: ");
  scanf("%f", &novoAluno.av2);
  if (novoAluno.av2 < 0 || novoAluno.av2 > 10) {
    printf("Erro. A nota deve estar no intervalo de 0 a 10.\n");
    return;
  }
  printf("Digite a nota da AV3: ");
  scanf("%f", &novoAluno.av3);
  if (novoAluno.av3 < 0 || novoAluno.av3 > 10) {
    printf("Erro. A nota deve estar no intervalo de 0 a 10.\n");
    return;
  }

  // Calcula a média do aluno
  novoAluno.media = (novoAluno.av1 + novoAluno.av2 + novoAluno.av3) / 3.0;

  alunos[*numAlunos] = novoAluno;
  (*numAlunos)++;

  printf("Aluno adicionado com sucesso.\n");
  printf("\U0001F44D\n"); // Emoji do polegar
  printf("\033[1;31m");   // Define a cor vermelha para o texto
}
// Função excluir um aluno
void excluirAluno(Aluno alunos[], int *numAlunos) {
  if (*numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  int matricula;
  printf("Digite a matricula do aluno a ser excluido: ");
  scanf("%d", &matricula);

  int posicao = -1;
  for (int i = 0; i < *numAlunos; i++) {
    if (alunos[i].matricula == matricula) {
      posicao = i;
      break;
    }
  }

  if (posicao == -1) {
    printf("Aluno nao encontrado.\n");
  } else {
    for (int i = posicao; i < *numAlunos - 1; i++) {
      alunos[i] = alunos[i + 1];
    }
    (*numAlunos)--;
    printf("Aluno excluido com sucesso.\n");
    printf("\033[1;31m");
  }
}
// Lista os aluno
void listarAlunos(Aluno alunos[], int numAlunos) {
  if (numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("LISTA DE ALUNOS:\n");
  for (int i = 0; i < numAlunos; i++) {
    printf("Nome: %s\n", alunos[i].nome);
    printf("Matricula: %d\n", alunos[i].matricula);
    printf("AV1: %.2f\n", alunos[i].av1);
    printf("AV2: %.2f\n", alunos[i].av2);
    printf("AV3: %.2f\n", alunos[i].av3);
    printf("Media: %.2f\n\n", alunos[i].media);
    printf("\033[1;31m");
  }
}
// Consulta Aluno por Matrícula
void consultarAlunoPorMatricula(Aluno alunos[], int numAlunos) {
  if (numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  int matricula;
  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  int posicao = -1;
  for (int i = 0; i < numAlunos; i++) {
    if (alunos[i].matricula == matricula) {
      posicao = i;
      break;
    }
  }

  if (posicao == -1) {
    printf("Aluno nao encontrado.\n");
  } else {
    printf("Nome: %s\n", alunos[posicao].nome);
    printf("Matricula: %d\n", alunos[posicao].matricula);
    printf("AV1: %.2f\n", alunos[posicao].av1);
    printf("AV2: %.2f\n", alunos[posicao].av2);
    printf("AV3: %.2f\n", alunos[posicao].av3);
    printf("Media: %.2f\n", alunos[posicao].media);
  }
}
// Calcula a Media Geral da turma.
void calcularMediaGeral(Aluno alunos[], int numAlunos) {
  if (numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  float somaMedias = 0;
  for (int i = 0; i < numAlunos; i++) {
    somaMedias += alunos[i].media;
  }

  float mediaGeral = somaMedias / numAlunos;
  printf("Media geral da turma: %.2f\n", mediaGeral);
  printf("\U0001F44A\n");
}
// Mostra os Melhores alunos.
void mostrarMelhoresAlunos(Aluno alunos[], int numAlunos, int quantidade) {
  if (numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  if (quantidade > numAlunos) {
    quantidade = numAlunos;
  }

  for (int i = 0; i < quantidade; i++) {
    Aluno melhorAluno = alunos[0];
    int posicaoMelhorAluno = 0;

    for (int j = 1; j < numAlunos; j++) {
      if (alunos[j].media > melhorAluno.media) {
        melhorAluno = alunos[j];
        posicaoMelhorAluno = j;
      }
    }

    printf("Posicao %d:\n", i + 1);
    printf("\U0001F3C5\n"); // Emoji de Medalha
    printf("Nome: %s\n", melhorAluno.nome);
    printf("Matricula: %d\n", melhorAluno.matricula);
    printf("AV1: %.2f\n", melhorAluno.av1);
    printf("AV2: %.2f\n", melhorAluno.av2);
    printf("AV3: %.2f\n", melhorAluno.av3);
    printf("Media: %.2f\n\n", melhorAluno.media);

    for (int k = posicaoMelhorAluno; k < numAlunos - 1; k++) {
      alunos[k] = alunos[k + 1];
    }
  }
}
// Edita as notas do aluno.
void editarNotas(Aluno alunos[], int numAlunos) {
  if (numAlunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  int matricula;
  printf("Digite a matricula do aluno: ");
  scanf("%d", &matricula);

  int posicao = -1;
  for (int i = 0; i < numAlunos; i++) {
    if (alunos[i].matricula == matricula) {
      posicao = i;
      break;
    }
  }

  if (posicao == -1) {
    printf("Aluno nao encontrado.\n");
  } else {
    printf("Digite a nova nota da AV1: ");
    scanf("%f", &alunos[posicao].av1);
    printf("Digite a nova nota da AV2: ");
    scanf("%f", &alunos[posicao].av2);
    printf("Digite a nova nota da AV3: ");
    scanf("%f", &alunos[posicao].av3);

    // Atualiza a média do aluno
    alunos[posicao].media =
        (alunos[posicao].av1 + alunos[posicao].av2 + alunos[posicao].av3) / 3.0;

    printf("Notas do aluno atualizadas com sucesso.\n");
    printf("\033[1;31m");
  }
}
// Salva os dados na memória.
void salvarDadosDAT(Aluno alunos[], int numAlunos) {
  FILE *arquivo = fopen("dados.dat", "wb");
  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo.\n");
    return;
  }

  fwrite(&numAlunos, sizeof(int), 1, arquivo);
  fwrite(alunos, sizeof(Aluno), numAlunos, arquivo);

  fclose(arquivo);
  printf("Dados salvos no arquivo dados.dat.\n\n");
  printf("\033[1;31m"); // muda para cor vermelha
}
// Faz a leitura os dados da memória.
void carregarDadosDAT(Aluno alunos[], int *numAlunos) {
  FILE *arquivo = fopen("dados.dat", "rb");
  if (arquivo == NULL) {
    printf("Nenhum dado encontrado. Arquivo vazio ou inexistente.\n");
    return;
  }
  fread(numAlunos, sizeof(int), 1, arquivo);
  fread(alunos, sizeof(Aluno), *numAlunos, arquivo);
  fclose(arquivo);
  // Carrega os dados para serem usados.

  printf("Os dados carregados com sucesso!\n");
  printf("\033[1;31m");
  printf("----------------------------------\n");
  printf("Projeto valendo nota da AV 3\n");
  printf("Unibra \U0001F3EB\n");
  printf("Lógica de Programação\n");
  printf("Prof Cleyton\n");
}
// Exporta os dados para um arquivo de fácil leitura.
void exportarDadosCSV(Aluno alunos[], int numAlunos) {
  FILE *arquivo = fopen("dados.csv", "w"); // w pra abrir e escrever
  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo.\n");
    return;
  }

  fprintf(arquivo, "Nome;Matricula;AV1;AV2;AV3;Media\n");
  for (int i = 0; i < numAlunos; i++) {
    fprintf(arquivo, "%s;%d;%.2f;%.2f;%.2f;%.2f\n", alunos[i].nome,
            alunos[i].matricula, alunos[i].av1, alunos[i].av2, alunos[i].av3,
            alunos[i].media);
  }

  fclose(arquivo);
  printf("Dados exportados para: dados.csv.\n");
  printf("\033[1;31m"); // muda fonte p vermelho
}

int main() {
  Aluno alunos[100];
  int numAlunos = 0;
  int opcao;

  carregarDadosDAT(alunos, &numAlunos); // Carrega os Dados ao iniciar.

  do {
    printf("----------------------------------\n");
    printf("\033[0m");
    printf("Gerenciamento de Notas dos Alunos\n");
    printf("\033[1;31m");
    printf("----------------------------------\n");
    printf("Menu do Sistema:\n");
    printf("----------------------------------\n");
    printf("1. Adicionar um Aluno\n");
    printf("2. Excluir um Aluno\n");
    printf("3. Editar Notas\n");
    printf("4. Listar os Alunos\n");
    printf("5. Consultar Aluno por Matricula\n");
    printf("6. Calcular Media Geral da Turma\n");
    printf("7. Mostrar os Melhores Alunos\n");
    printf("8. Salvar os Dados\n");
    printf("9. Carregar os Dados\n");
    printf("10. Exportar Dados para Excel\n");
    printf("11. Sair\n");
    printf("----------------------------------\n");
    printf("Digite a opcao desejada: ");
    printf("\033[0m");
    scanf("%d", &opcao);

    switch (opcao) { // As escolhas do usuário
    case 1:
      adicionarAluno(alunos, &numAlunos);
      break;
    case 2:
      excluirAluno(alunos, &numAlunos);
      break;
    case 3:
      editarNotas(alunos, numAlunos);
      break;
    case 4:
      listarAlunos(alunos, numAlunos);
      break;
    case 5:
      consultarAlunoPorMatricula(alunos, numAlunos);
      break;
    case 6:
      calcularMediaGeral(alunos, numAlunos);
      break;
    case 7:
      int quantidade;
      printf("Digite a quantidade de melhores alunos a serem mostrados: ");
      scanf("%d", &quantidade);
      mostrarMelhoresAlunos(alunos, numAlunos, quantidade);
      break;
    case 8:
      salvarDadosDAT(alunos, numAlunos);
      break;
    case 9:
      carregarDadosDAT(alunos, &numAlunos);
      break;
    case 10:
      exportarDadosCSV(alunos, numAlunos);
      break;
    case 11:
      printf("Saindo...\n");
      printf("E recebendo um parabéns do prof!\n");
      printf(" \U0001F609\n"); // Emoji piscando olho
      break;
    default:
      printf("Opcao invalida. Digite um num de 1 a 11.\n");
      break;
    }

    printf("\n");

  } while (opcao != 11); // as opções que podem ser digitadas.

  return 0;
}
