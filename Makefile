
#Переопределение команды удаления файлов для Windows
RM=del
#Правило сборки исполняемого файла из объектных.
#CXX - переменная для команды компилятора. (По умолчанию g++.)
objects=m.o kva.o

m.exe: $(objects)
	$(CXX) -o m.exe $(objects)

#Правило компиляции исходного файла с завизимостью от заголовочного файла в объектный
m.o: m.c kva.h
	$(CXX) -c m.c

#Правило компиляции исходного файла в объектный
kva.o: kva.c
	$(CXX) -c kva.c

#Фиктивное правило для очистки каталога от созданных в процессе сборки файлов.
#Для его вызова нужно указать clean после команды make.

#Пример теста листинга 1.1 со стр. 22
l101022o=L101_022.o L101_022test.o
L101022.exe: $(l101022o)
	$(CXX) -o L101022.exe $(l101022o)

L101_022.o: L101_022.c
	$(CXX) -c L101_022.c

L101_022test.o: L101_022test.c L101_022.h
	$(CXX) -c L101_022test.c

# Объекты для L664_217.exe
l664217o=L664_217.o graph.o

# Правило сборки L664_217.exe
L664_217.exe: $(l664217o)
	$(CXX) -o L664_217.exe $(l664217o)

# Компиляция L664_217.o с зависимостью от заголовочного файла graph.h
L664_217.o: L664_217.cpp graph.h
	$(CXX) -c L664_217.cpp

# Компиляция graph.o
graph.o: graph.cpp
	$(CXX) -c graph.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l101022o) $(l664217o) m.exe L101022.exe L664_217.exe
