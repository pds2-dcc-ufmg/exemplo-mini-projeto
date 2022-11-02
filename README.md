# Mini Projeto

Esse é um exemplo de projeto bem básico que utiliza todas as ferramentas e utilitários vistos ao longo da disciplina.

## **Ferramentas**

Esse projeto utiliza as seguintes linguagem, ferramentas e bibliotecas:

* Linguagem: [C++11](https://cplusplus.com/doc/)
* Compilação: [Make](https://www.gnu.org/software/make/)
* Documentação: [Doxygen](https://doxygen.nl/)
* Testes Unitários: [Doctest](https://github.com/doctest/doctest)
* Cobertura: [gcovr](https://gcovr.com/)

## **Compilação**

```bash
$ make
```

## **Execução**

```bash
$ make run
```

## **Compilação Testes**

```bash
$ make tests
```

## **Execução Testes**

```bash
$ make run_tests
```

## **Documentação**

É necessário ter na raiz do projeto um arquivo _Doxyfile_. Um arquivo padrão pode ser gerado pelo comando:
```bash
$ doxygen -g
```

Abaixo a lista de flags que foram modificadas no arquivo original.

```
PROJECT_NAME           = "PDS2 - Mini-projeto de exemplo"

OUTPUT_DIRECTORY       = doc/

RECURSIVE              = YES

EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES

HAVE_DOT               = NO
```

Para gerar a documentação, utilizar:

```bash
$ doxygen Doxyfile
```
