#include <ctype.h>
#include <stdio.h>

#define BUFFER_SIZE 100

// Definindo os tipos de tokens
enum TokenType {
  CHARACTER, // CARACTERE
  INTEGER, // NUMBER
  FLOAT, // Real number
  ADDITION, // ADD
  SUBTRACTION, // SUBTRACT
  MULTIPLICATION, // MULTIPLY
  DIVISION, // DIVIDE
  LEFT_PARENTHESIS, // LPAREN
  RIGHT_PARENTHESIS, // RPAREN
  LEFT_BRACE, // LCHAVE
  RIGHT_BRACE, // RCHAVE
  LEFT_BRACKET, // LCOLCHETE
  RIGHT_BRACKET, // RCOLCHETE
  LESS_THAN, // MENOR
  GREATER_THAN, // MAIOR
  SEMICOLON, //  ; PONTODOT
  COMMA, // VIRGULA 
  DOUBLE_QUOTES, // 'hello, world'
  SINGLE_QUOTES, // one word like 'a'
  SQUARE_ROOT, // SQRT
  EQUALS, // IGUAL
  EQUALS_TO, // IGUAL A
  AND, // & operador
  OR, // | operador
  NOT, // ! operador
  MODULUS, // % operador
  END_OF_FILE // fim de arquivo

};


// Definindo a estrutura de um token
typedef struct {
  enum TokenType type;
  char value[BUFFER_SIZE];
} Token;

// Lendo o próximo caractere do buffer
char getNextChar() {
  static char buffer[BUFFER_SIZE];
  static char *pBuffer = buffer;

  if (*pBuffer == '\0') {

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
      return EOF;
    }
    pBuffer = buffer;
  }

  return *pBuffer++;
}

// Desfazendo a leitura do último caractere do buffer
void ungetChar() {
  static char buffer[BUFFER_SIZE];
  static char *pBuffer = buffer;

  if (pBuffer > buffer) {
    --pBuffer;
  }
}

// Obtendo o próximo token
Token getNextToken() {
  Token token;
  char ch;
  int i = 0;

  // Ignorando espaços em branco
  do {
    ch = getNextChar();
  } while (isspace(ch));

  // Identificando o tipo de token
  switch (ch) {
    case '+':
      token.type = ADDITION;
      break;
    case '-':
      token.type = SUBTRACTION;
      break;
    case '*':
      token.type = MULTIPLICATION;
      break;
    case '/':
      token.type = DIVISION;
      break;
    case '(':
      token.type = LEFT_PARENTHESIS;
      break;
    case ')':
      token.type = RIGHT_PARENTHESIS;
      break;
    case '{':
      token.type = LEFT_BRACE;
      break;
    case '}':
      token.type = RIGHT_BRACE;
      break;
    case '[':
      token.type = LEFT_BRACKET;
      break;
    
    case ']':
      token.type = RIGHT_BRACKET;
      break;
    case '<':
      token.type = LESS_THAN;
      break;
    case '>':
      token.type = GREATER_THAN;
      break;
  
    case ';':
      token.type = SEMICOLON;
      break;
    case ',':
      token.type = COMMA;
      break;
    case '"':
      token.type = DOUBLE_QUOTES;
      break;
    case '\'':
      token.type = SINGLE_QUOTES;
      break;
    case '^':
      token.type = SQUARE_ROOT;
      break;
    case '=':
      token.type = EQUALS;
      break;
    case ':':
      token.type = EQUALS_TO;
      break;
   case '&':
      token.type = AND;
      break;

    case '|':
      token.type = OR;
      break;

    case '!':
      token.type = NOT;
      break;

    case '%':
      token.type = MODULUS;
      break;

    case EOF:
      token.type = END_OF_FILE;
      break; 
  
 default:
  if (ch == EOF) {
    token.type = END_OF_FILE;
  } else if (isdigit(ch)) {
    do {
      token.value[i++] = ch;
      ch = getNextChar();
    } while (isdigit(ch));
    if (ch == '.') {
      token.type = FLOAT;
      token.value[i++] = ch;
      ch = getNextChar();
      if (isdigit(ch)) {
        do {
          token.value[i++] = ch;
          ch = getNextChar();
        } while (isdigit(ch));
      } else {
        printf("Erro: número real mal formado. O próximo caractere deveria ser um dígito, mas é '%c'\n", ch);
        token.type = END_OF_FILE;
      }
    } else {
      ungetChar();
      token.type = INTEGER;
    }
  } else if (isalpha(ch)) {
    
  do{
    // Lendo um caractere

        ungetChar();
      token.type = CHARACTER;
      token.value[i++] = ch;
      ch = getNextChar();
          
    
    } while (isalpha(ch));{
      // Desfazendo a leitura do último caractere
      ungetChar();
      token.type = CHARACTER;
    }
  } else if (ch == '\'') {
    
    // Desfazendo a leitura do último caractere
    ungetChar();

    token.value[i] = '\0';
    
    token.type = CHARACTER;
  } else {
    // Caractere inválido
    printf("Caractere inválido: %c\n", ch);
    token.type = END_OF_FILE;
  }
     return token;

  }}
    
  

int main() {
  Token token;

  do {
    printf("Digite algum símbolo: \n");
    token = getNextToken();

    switch (token.type) {
     case CHARACTER:
      printf("Caractere: %s\n", token.value);
      break;
    case INTEGER:
      printf("Número inteiro: %s\n", token.value);
      break;
    case FLOAT:
      printf("Número real: %s\n", token.value);
      break;
    case ADDITION:
      printf("Operador de Soma\n");
      break;
    case SUBTRACTION:
      printf("Operador de Subtração\n");
      break;
    case MULTIPLICATION:
      printf("Operador de Multiplicação\n");
      break;
    case DIVISION:
      printf("Operador de Divisão\n");
      break;
    case LEFT_PARENTHESIS:
      printf("Parêntese esquerdo\n");
      break;
    case RIGHT_PARENTHESIS:
      printf("Parêntese direito\n");
      break;
    
    case LEFT_BRACE:
      printf("Chave esquerda\n");
      break;
    case RIGHT_BRACE:
      printf("Chave direita\n");
      break;
    case LEFT_BRACKET:
      printf("Colchete esquerdo\n");
      break;
    case RIGHT_BRACKET:
      printf("Colchete direito\n");
      break;
    case LESS_THAN:
      printf("Menor que\n");
      break;
    case GREATER_THAN:
      printf("Maior que\n");
      break;
    
    case SEMICOLON:
      printf("Ponto e vírgula\n");
      break;
    case COMMA:
      printf("Vírgula\n");
      break;
    case DOUBLE_QUOTES:
      printf("Aspas duplas\n");
      break;
    case SINGLE_QUOTES:
      printf("Aspas simples\n");
      break;
    case SQUARE_ROOT:
      printf("Elevado a\n");
      break;

    case EQUALS:
      printf("Igual\n");
      break;
    case EQUALS_TO:
      printf("Igual a \n");
      break;

    case AND:
      printf("Operador lógico E\n");
      break;
    case OR:
      printf("Operador lógico OU\n");
      break;
    case NOT:
      printf("Operador lógico NÃO\n");
      break;
    case MODULUS:
      printf("Operador DE RESTO\n");
      break;
    
    case END_OF_FILE:
      printf("Fim do arquivo\n");
    default:
      // Tipo de token desconhecido
      printf("Tipo de token desconhecido\n");
      break;
    }
  } while (token.type != END_OF_FILE);

  return 0;
}