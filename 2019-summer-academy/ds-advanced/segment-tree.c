/***********************************************************/
// [2-3-2.1~4] Segment Tree
/***********************************************************/

#if 0

/***********************************************************/
// [2-3-2.1] Segment Tree 자료 확인
/***********************************************************/
#if 01
#include <stdio.h>

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*2)
#define LAST_NODE	(MAX_DATA*2-1)

int tree[MAX_TREE];

int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}


// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다
void Update_New_Data(int node, int s, int e, int idx, int data);
void Update_Add(int node, int s, int e, int us, int ue, int add);
int Query(int node, int s, int e, int qs, int qe);
#endif
/***********************************************************/
// [2-3-2.2] 새로운 데이터의 추가 및 데이터 업데이트 함수
/***********************************************************/
#if 01
void Update_New_Data(int node, int s, int e, int idx, int data)
{
    int m;
    if (s == e) { // leaf
        tree[node] = data;
        return;
    }
    m = (s + e) / 2;
    if (idx <= m) {
        Update_New_Data(node * 2, s, m, idx, data); // left
    }
    else {
        Update_New_Data(node * 2 + 1, m + 1, e, idx, data); // right
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // parent update (sum)

}
#endif

#if 0
void main(void)
{
    int i;

    printf("Update_New_Data() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
        printf("[%d] data : %d ", i, exam[i]);
        PRINT_TREE;
    }
}
#endif


/***********************************************************/
// [2-3-2.3] 구간 정보 요청
/***********************************************************/
#if 01
int Query(int node, int s, int e, int qs, int qe) // qs, qe == query range
{
    int m, sum = 0;
    if (e < qs || s > qe) return 0; // if current range is out of range, return 0.
    if (s >= qs && e <= qe || s == e) return tree[node]; // if current range included in query range, return subtotal.
    m = (s + e) / 2;
    sum += Query(node * 2, s, m, qs, qe);
    sum += Query(node * 2 + 1, m + 1, e, qs, qe);
    return sum;
}
#endif

#if 0
void main(void)
{
    int i;

    printf("Query() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
    }

    printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif


/*************************************************************/
// [2-3-2.4] 특정 구간 데이터 변경 함수 - 데이터 증가/감소
/*************************************************************/
#if 1
void Update_Add(int node, int s, int e, int us, int ue, int add)
{
    int m;
    if (ue < s || e < us) return;
    if (s == e) {
        tree[node] += add;
        return;
    }
    m = (s + e) / 2;
    Update_Add(node * 2, s, m, us, ue, add);
    Update_Add(node * 2 + 1, m + 1, e, us, ue, add);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
    int i;

    printf("Update_Add() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
    }

    printf("[Before Range Update] ");
    PRINT_TREE;
    printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));

    Update_Add(1, 1, NUM_DATA, 2, 4, 2);

    printf("\n[After Range Update] ");
    PRINT_TREE;
    printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif
#endif

/***********************************************************/
// [2-3-2.5~9] Segment Tree with Lazy Propagation
/***********************************************************/

#if 0

/***********************************************************/
// [2-3-2.5] Segment Tree with Lazy Propagation 자료 확인
/***********************************************************/
#if 0
#include <stdio.h>

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*2)
#define LAST_NODE	(MAX_DATA*2-1)

int tree[MAX_TREE];
int lazy[MAX_TREE];

int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}


// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다
void Propagate(int n, int s, int e);
void Update_New_Data_Lazy(int node, int s, int e, int idx, int data);
void Update_Add_Lazy(int node, int s, int e, int us, int ue, int add);
int Query_Lazy(int node, int s, int e, int qs, int qe);
#endif


/***********************************************************/
// [2-3-2.6] Propagate 함수
/***********************************************************/
#if 0

void Propagate(int node, int s, int e)
{
    if (lazy[node] != 0)
    {
        if (s != e)
        {
            lazy[node * 2] += lazy[node];
            if (node * 2 + 1 <= LAST_NODE) lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] += (e - s + 1) * lazy[node];
        lazy[node] = 0;
    }
}
#endif

/***********************************************************/
// [2-3-2.7] 새로운 data 추가/Update
/***********************************************************/

#if 0
void Update_New_Data_Lazy(int node, int s, int e, int idx, int data)
{
    int m;

    Propagate(node, s, e);

    if (s == e)
    {
        tree[node] = data;
        return;
    }

    m = (s + e) / 2;
    if (idx <= m) Update_New_Data_Lazy(node * 2, s, m, idx, data);
    else Update_New_Data_Lazy(node * 2 + 1, m + 1, e, idx, data);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
    int i;

    printf("Update_New_Data() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
        printf("[%d] data : %d ", i, exam[i]);
        PRINT_TREE;
    }
}
#endif


/***********************************************************/
// [2-3-2.8] 구간 정보 요청
/***********************************************************/
#if 0
int Query_Lazy(int node, int s, int e, int qs, int qe)
{
    int m, l, r;

    Propagate(node, s, e);

    if (qs <= s && e <= qe) return tree[node];
    else if (qs > e || s > qe) return 0;

    m = (s + e) / 2;
    l = Query_Lazy(node * 2, s, m, qs, qe);
    r = Query_Lazy(node * 2 + 1, m + 1, e, qs, qe);

    return l + r;
}
#endif

#if 0
void main(void)
{
    int i;

    printf("Query() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
    }

    printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));
}
#endif


/*************************************************************/
// [2-3-2.9] 특정 구간 데이터 변경 함수 - 데이터 증가/감소
/*************************************************************/
#if 0
void Update_Add_Lazy(int node, int s, int e, int us, int ue, int add)
{
    int m;

    Propagate(node, s, e);

    if (us <= s && e <= ue)
    {
        lazy[node] += add;
        Propagate(node, s, e);
        return;
    }
    else if (us > e || s > ue) return;

    m = (s + e) / 2;
    Update_Add_Lazy(node * 2, s, m, us, ue, add);
    Update_Add_Lazy(node * 2 + 1, m + 1, e, us, ue, add);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
    int i;

    printf("Update_Add() Test\n");

    for (i = 1; i <= NUM_DATA; i++)
    {
        Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
    }

    printf("[Before Range Update] ");
    PRINT_TREE;
    printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));

    Update_Add_Lazy(1, 1, NUM_DATA, 2, 4, 2);

    printf("\n[After Range Update] ");
    PRINT_TREE;
    printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
    printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
    printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
    printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
    printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));
}
#endif
#endif
