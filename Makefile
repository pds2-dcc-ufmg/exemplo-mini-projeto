CC=g++
CFLAGS=-std=c++11 -Wall --coverage
TARGET=program
TARGET_TESTS=program_tests

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
TEST_DIR = ./tests
COVERAGE_DIR = ./coverage
THIRD_DIR = ./third_party

all: ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/MensagemBase.o ${BUILD_DIR}/MensagemTexto.o ${BUILD_DIR}/MensagemImagem.o ${BUILD_DIR}/MensagemAudio.o ${BUILD_DIR}/Chat.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/MensagemBase.o: ${INCLUDE_DIR}/mensagem/MensagemBase.hpp ${SRC_DIR}/mensagem/MensagemBase.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -c ${SRC_DIR}/mensagem/MensagemBase.cpp -o ${BUILD_DIR}/MensagemBase.o

${BUILD_DIR}/MensagemTexto.o: ${INCLUDE_DIR}/mensagem/MensagemBase.hpp ${INCLUDE_DIR}/mensagem/MensagemTexto.hpp ${SRC_DIR}/mensagem/MensagemTexto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -c ${SRC_DIR}/mensagem/MensagemTexto.cpp -o ${BUILD_DIR}/MensagemTexto.o

${BUILD_DIR}/MensagemImagem.o: ${INCLUDE_DIR}/mensagem/MensagemBase.hpp ${INCLUDE_DIR}/mensagem/MensagemImagem.hpp ${SRC_DIR}/mensagem/MensagemImagem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -c ${SRC_DIR}/mensagem/MensagemImagem.cpp -o ${BUILD_DIR}/MensagemImagem.o
	
${BUILD_DIR}/MensagemAudio.o: ${INCLUDE_DIR}/mensagem/MensagemBase.hpp ${INCLUDE_DIR}/mensagem/MensagemAudio.hpp ${SRC_DIR}/mensagem/MensagemAudio.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -c ${SRC_DIR}/mensagem/MensagemAudio.cpp -o ${BUILD_DIR}/MensagemAudio.o

${BUILD_DIR}/Chat.o: ${INCLUDE_DIR}/mensagem/MensagemBase.hpp ${INCLUDE_DIR}/mensagem/MensagemTexto.hpp ${INCLUDE_DIR}/mensagem/MensagemImagem.hpp ${INCLUDE_DIR}/mensagem/MensagemAudio.hpp ${INCLUDE_DIR}/chat/Chat.hpp ${SRC_DIR}/chat/Chat.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -I ${INCLUDE_DIR}/chat/ -c ${SRC_DIR}/chat/Chat.cpp -o ${BUILD_DIR}/Chat.o
	
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/chat/Chat.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/mensagem/ -I ${INCLUDE_DIR}/chat/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${TEST_DIR}/TesteChat.o: ${TEST_DIR}/chat/TesteChat.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/mensagem/ -I ${INCLUDE_DIR}/chat/ -c ${TEST_DIR}/chat/TesteChat.cpp -o ${TEST_DIR}/TesteChat.o

${TEST_DIR}/TesteMensagem.o: ${TEST_DIR}/mensagem/TesteMensagem.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/mensagem/ -c ${TEST_DIR}/mensagem/TesteMensagem.cpp -o ${TEST_DIR}/TesteMensagem.o

${TEST_DIR}/main_testes.o: ${TEST_DIR}/main_testes.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/mensagem/ -I ${INCLUDE_DIR}/chat/ -c ${TEST_DIR}/main_testes.cpp -o ${TEST_DIR}/main_testes.o

tests: all ${TEST_DIR}/TesteChat.o ${TEST_DIR}/TesteMensagem.o ${TEST_DIR}/main_testes.o
	${CC} ${CFLAGS} -o ${TEST_DIR}/${TARGET_TESTS} ${BUILD_DIR}/MensagemBase.o ${BUILD_DIR}/MensagemTexto.o ${BUILD_DIR}/MensagemImagem.o ${BUILD_DIR}/MensagemAudio.o ${BUILD_DIR}/Chat.o ${TEST_DIR}/*.o

run_tests: tests
	./${TEST_DIR}/${TARGET_TESTS}

run: all
	./${BUILD_DIR}/${TARGET}

coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h"
	gcovr -r . --exclude="third_party/doctest.h" -b	

html_coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h" --html --html-details -o ${COVERAGE_DIR}/relatorio.html

documentation:
	doxygen Doxyfile

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/*
	rm -f ${TEST_DIR}/*.o ${TEST_DIR}/*.gcda ${TEST_DIR}/*.gcno ${TEST_DIR}/${TARGET_TESTS}
	rm -f ${COVERAGE_DIR}/*
	rm -rf ./doc/*