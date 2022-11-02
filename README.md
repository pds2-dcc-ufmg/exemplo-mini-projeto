# Mini Projeto

Esse é um exemplo de projeto bem básico que utiliza todas as ferramentas e utilitários vistos ao longo da disciplina. Ele pode ser melhorado em diferentes aspectos e portanto não deve ser visto como um guia definitivo a ser seguido.

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

**Atenção: Criar antes um diretório _./build/_**

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

## **Relatório de Cobertura**

Para imprimir o relatório simplificado no próprio Terminal, utilizar:
```bash
$ make coverage
```

Para gerar o relatório em HTML, utilizar:
```bash
$ make html_coverage
```

**Atenção: Criar antes um diretório _./coverage/_**

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
ou
```bash
$ make documentation
```

**Atenção: Criar antes um diretório _./doc/_**

## **Remover arquivos auxiliares**
```bash
$ make clean
```
