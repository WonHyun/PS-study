#if 0

// hash table open address 삽입, 삭제 문제

#include <stdio.h>
#define MAX    10
#define HASH_KEY 5 
#define STEP     1 

int Hash_table[MAX] = { -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1 }; //  빈 데이터는 -1
int test[MAX] = { 1, 5, 3, 4, 9, 10, 11, 6, 2, 7 };
int Get_Hash_Key(int id)
{
    return id % HASH_KEY;
}

void Print_All_Data(void)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (Hash_table[i] > 0) printf("[%d] data=%d\n", i, Hash_table[i]);
    }
}

int Insert_Data(int  data) {
    int key;
    key = Get_Hash_Key(data);

    for (int i = 0; i < MAX; i += STEP) { // hash table의 크기만큼 루프
        if (Hash_table[key] == -1) { // 데이터가 비어있는 경우만 삽입한다
            Hash_table[key] = data;
            return key;
        }
        key = (key + STEP) % MAX; // 데이터가 이미 있다면 다음 스텝으로
    }
    return -1;
}

int Delete_Data(int data) {
    int i, key;
    key = Get_Hash_Key(data);

    for (int i = 0; i < MAX; i += STEP) {
        if (Hash_table[key] == -1) return -1; // 다음 탐색할 데이터가 없다면 찾지 못한것
        if (Hash_table[key] == data) { // 해당 데이터가 같은 경우 삭제
            Hash_table[key] = 0; // 0이 삭제되었다는 것
            return key;
        }
        key = (key + STEP) % MAX;
    }

    return -1;
}

int main()
{
    int i, r;
    for (i = 0; i < MAX; i++) Insert_Data(test[i]);
    Print_All_Data();
    printf("[3] Delete Result=%d\n", r = Delete_Data(3));
    printf("[11] Delete Result=%d\n", r = Delete_Data(11));
    printf("[3] Delete Result=%d\n", r = Delete_Data(3));
    Print_All_Data();

    return 0;
}

#endif
