//Pozdin Konstantin Pm-201
#include "zagolovok.cpp"
#include <iostream>
#include <cstring> // ��� strlen

// ������� ������������� ����������������
Cell m[MAXLEN + 1][MAXLEN + 1];

// ������������� ������ �������
void row_init(int i) {
    for (int j = 0; j <= MAXLEN; j++) {
        m[i][j].cost = j;
        m[i][j].parent = (j == 0) ? -1 : 1; // -1: ������, 1: �������
    }
}

// ������������� ������� �������
void column_init(int i) {
    for (int j = 0; j <= MAXLEN; j++) {
        m[j][i].cost = j;
        m[j][i].parent = (j == 0) ? -1 : 2; // -1: ������, 2: ��������
    }
}

// ���������� ��������� ����������
int match(char a, char b) {
    return (a == b) ? 0 : 1;
}

// ���������� ��������� �������
int insert(char c) {
    return 1; // ������������� ���������
}

// ���������� ��������� ��������
int del(char c) {
    return 1; // ������������� ���������
}

// ����������� ������� ������
void goal_cell(const char* s, const char* t, int* i, int* j) {
    *i = strlen(s);
    *j = strlen(t);
}

// �������� ������� ���������� ��������� ��������������
int string_compare(const char* s, const char* t) {
    int i, j, k;
    int opt[3];

    // ������������� ������ ������ � �������
    for (i = 0; i <= MAXLEN; i++) {
        row_init(i);
        column_init(i);
    }

    // ���������� ������� ������������� ����������������
    for (i = 1; i <= strlen(s); i++) {
        for (j = 1; j <= strlen(t); j++) {
            opt[0] = m[i - 1][j - 1].cost + match(s[i - 1], t[j - 1]);
            opt[1] = m[i][j - 1].cost + insert(t[j - 1]);
            opt[2] = m[i - 1][j].cost + del(s[i - 1]);

            m[i][j].cost = opt[0];
            m[i][j].parent = 0;

            for (k = 1; k <= 2; k++) {
                if (opt[k] < m[i][j].cost) {
                    m[i][j].cost = opt[k];
                    m[i][j].parent = k;
                }
            }
        }
    }

    // ����������� ������� ������
    goal_cell(s, t, &i, &j);
    return m[i][j].cost;
}

// ������ �������������
int main() {
    const char s[] = "kitten";
    const char t[] = "sitting";

    int cost = string_compare(s, t);

    std::cout << "Cost of editing a line \"" << s
        << "\" in line \"" << t << "\": " << cost << std::endl;

    return 0;
}