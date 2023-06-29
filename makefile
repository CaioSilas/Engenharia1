CC = g++
RMV = rm -rf

clean:
	$(RMV) bin/*

run_funcionalTests:
	./bin/funcional.exe

run_unitTests:
	./bin/unit.exe

funcionalTests: bin/funcional_main.o bin/funcionalTests.o bin/myVensim.dll
	$(CC) -o bin/funcional.exe bin/funcional_main.o bin/funcionalTests.o bin/myVensim.dll -Wall

unitTests: bin/unit_main.o bin/unitSystem.o bin/unitFlow.o bin/unitModel.o bin/myVensim.dll
	$(CC) -o bin/unit.exe bin/unit_main.o bin/unitSystem.o bin/unitFlow.o bin/unitModel.o bin/myVensim.dll -Wall

bin/myVensim.dll: bin/systemImpl.o bin/FlowImpl.o bin/ModelImpl.o
	$(CC) -shared bin/systemImpl.o bin/FlowImpl.o bin/ModelImpl.o -o bin/myVensim.dll

bin/systemImpl.o: src/system.h src/systemImpl.h src/systemImpl.cpp
	$(CC) -c -fPIC src/systemImpl.cpp -o bin/systemImpl.o -Wall

bin/FlowImpl.o: src/flow.h src/FlowImpl.h src/FlowImpl.cpp src/system.h
	$(CC) -c -fPIC src/FlowImpl.cpp -o bin/FlowImpl.o -Wall

bin/ModelImpl.o: src/model.h src/ModelImpl.h src/ModelImpl.cpp src/system.h src/flow.h
	$(CC) -c -fPIC src/ModelImpl.cpp -o bin/ModelImpl.o -Wall

bin/funcional_main.o: tests/funcional/main.cpp tests/funcional/funcionalTests.h
	$(CC) -c -fPIC tests/funcional/main.cpp -o bin/funcional_main.o -Wall

bin/funcionalTests.o: tests/funcional/funcionalTests.cpp tests/funcional/funcionalTests.h
	$(CC) -c -fPIC tests/funcional/funcionalTests.cpp -o bin/funcionalTests.o -Wall

bin/unit_main.o: tests/unit/main.cpp tests/unit/unitSystem.h tests/unit/unitFlow.h tests/unit/unitModel.h
	$(CC) -c -fPIC tests/unit/main.cpp -o bin/unit_main.o -Wall

bin/unitSystem.o: tests/unit/unitSystem.cpp tests/unit/unitSystem.h
	$(CC) -c -fPIC tests/unit/unitSystem.cpp -o bin/unitSystem.o -Wall

bin/unitFlow.o: tests/unit/unitFlow.cpp tests/unit/unitFlow.h
	$(CC) -c -fPIC tests/unit/unitFlow.cpp -o bin/unitFlow.o -Wall

bin/unitModel.o: tests/unit/unitModel.cpp tests/unit/unitModel.h
	$(CC) -c -fPIC tests/unit/unitModel.cpp -o bin/unitModel.o -Wall
