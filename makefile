# Makefile

# Compilador e opções
CXX = g++
CXXFLAGS = -Wall -Wextra

# Diretórios
SRCDIR = src
TESTDIR = test/funcional
BINDIR = bin

# Arquivos-fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(TESTDIR)/*.cpp)

# Nome do executável final
EXECUTABLE = $(BINDIR)/meu_programa

# Regra principal
all: $(EXECUTABLE)

# Regra para o programa final
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para criar o diretório de destino
$(shell mkdir -p $(BINDIR))

# Regra para limpar o executável
clean:
	rm -f $(EXECUTABLE)
	rmdir $(BINDIR) 2>/dev/null || true
