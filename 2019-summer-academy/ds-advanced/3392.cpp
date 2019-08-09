#if 0

// 에디터 문제

#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    char data;
    node* next;
    node* prev;
};

node head;
node tail;

node* cursor;

char str[600001];

void insertNode(char ch) {
    node* temp = (node*)calloc(1, sizeof(node));
    temp->data = ch;
    temp->next = cursor;
    temp->prev = cursor->prev;
    temp->prev->next = temp;
    temp->next->prev = temp;
}

void deleteNode() {
    node* del = cursor->prev;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
}

void printNode() {
    node* temp = &head;

    while (temp->next != &tail) {
        printf("%c", temp->next->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    char cmd, data;
    head.next = &tail;
    tail.prev = &head;
    cursor = &tail;

    scanf("%s", str);
    scanf("%d", &n);
    
    for (int i = 0; str[i]; i++) {
        insertNode(str[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'L':
            if (cursor->prev != &head) cursor = cursor->prev;
            break;
        case 'D':
            if (cursor->next != &tail) cursor = cursor->next;
            break;
        case 'B':
            if (cursor->prev != &head) {
                deleteNode();
            }
            break;
        case 'P':
            scanf(" %c", &data);
            insertNode(data);
            break;
        default:
            break;
        }
    }

    printNode();

    return 0;
}

#endif

#if 0

// c버전

#include <stdio.h>
typedef struct st {
    char ch;
    struct st* next, * prev;
}NODE;
char str[600001];
NODE* cur;
NODE Head, Tail;
void insert(char ch) {
    NODE* new = calloc(1, sizeof(NODE));
    new->ch = ch;
    new->next = cur;
    new->prev = cur->prev;
    new->prev->next = new;//cur->prev->next=new;
    new->next->prev = new;//cur->prev=new;
}
void delete(void) {
    NODE* del = cur->prev;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
}
void print_node(void) {
    NODE* p = &Head;
    for (;;) {
        if (p->next == &Tail)return;
        printf("%c", p->next->ch);
        p = p->next;
    }
}
int main(void) {
    int N, i;
    char cmd, ch;
    scanf("%s", str);
    scanf("%d", &N);
    Head.next = &Tail;
    Tail.prev = &Head;
    cur = &Tail;//커서는 맨끝에 위치에서 시작
    for (i = 0; str[i]; i++) {
        insert(str[i]);//입력받은 글자 힙에 생성하여 링크 연결
    }
    for (i = 0; i < N; i++) {
        scanf(" %c", &cmd);//명령어
        if (cmd == 'L') {//커서를 왼쪽한 칸 이동(단 맨앞이면 무시)
            if (cur->prev == &Head) continue;
            cur = cur->prev;
        }
        else if (cmd == 'D') {//커서 오른쪽 이동(맨 뒤면 무시)
            if (cur == &Tail) continue;
            cur = cur->next;
        }
        else if (cmd == 'P') {//문자를 커서 왼쪽에 추가
            scanf(" %c", &ch);//추가할 글자
            insert(ch);
        }
        else {//커서 왼쪽 문자 삭제(맨 앞이면 무시)
            if (cur->prev == &Head) continue;
            delete();
        }
    }
    print_node();//링크따라 문자 인쇄
    return 0;
}

#endif
