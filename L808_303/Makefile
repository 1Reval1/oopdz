# ����������� ����������� � ������� ��������
CXX = g++
RM = rm -f # ���������� rm ��� ������������� � Unix/Linux

# ���������� ��� ������
OBJECTS = L808_303.o zagolovok.o
EXECUTABLE = L808_303.exe

# ������ ������������ �����
$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $(EXECUTABLE) $(OBJECTS)

# ���������� L808_303.o
L808_303.o: L808_303.cpp 
	$(CXX) -c L808_303.cpp

# ���������� zagolovok.o
zagolovok.o: zagolovok.cpp 
	$(CXX) -c zagolovok.cpp

# ������� ������������� ������
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)