//���������� ����������� ����� � �����
#include <iostream>
#include <algorithm> // ��� std::min

struct edgenode {
    int v;              // �������� ������� �����
    int residual;       // ���������� ���������� �����������
    edgenode* next;     // ��������� �� ��������� �����
};

struct flow_graph {
    edgenode** edges;   // ������ ���������� �� ������ ��������� ��� ������ �������
};

// ������� ������ ����� ����� ��������� x � y
edgenode* find_edge(flow_graph* g, int x, int y) {
    edgenode* p = g->edges[x]; // �������������� ��������� ��������� ��� ������ ������ ��������� ������� x
    while (p != nullptr) {     // ���� �� ��������� ����� ������
        if (p->v == y) return p; // ���� �������� ������� ����� ����� y, ���������� ��������� �� ��� �����
        p = p->next;            // ��������� � ���������� ����� � ������
    }
    return nullptr;             // ���� ����� �� �������, ���������� nullptr
}

// ����������� ������� ��� ���������� ������ ����
int path_volume(flow_graph* g, int start, int end, int parents[]) {
    if (parents[end] == -1) return 0; // ���� ���� �� ����������, ���������� 0

    edgenode* e = find_edge(g, parents[end], end); // ������� ����� ����� ��������� parents[end] � end

    if (start == parents[end]) {  // ������� ������: ���� ��������� ������� ����� ������������ ������� end
        return e->residual;       // ���������� ���������� ������� ����� �����
    }
    else {
        // ����������� ����� ��� ������ ����������� ���������� ������� �� ����
        return std::min(path_volume(g, start, parents[end], parents), e->residual);
    }
}