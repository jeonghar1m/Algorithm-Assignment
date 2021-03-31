//동적 배열 소스 참고: https://soooprmx.com/archives/4113
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX_PLAYER_SIZE 10
#define MAX_NAME_SIZE 10
typedef char element;

typedef struct QueueType
{
    element data[MAX_PLAYER_SIZE][MAX_NAME_SIZE];
    char* front, rear;
} QueueType;

void init_queue(QueueType *q, int size)
{
    q->front = q->rear = NULL;
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    q->rear = (q->rear + 1) % MAX_PLAYER_SIZE;
    q->data[q->rear - 1] = item;
}

//삭제 함수
element dequeue(QueueType *q)
{
    q->front = (q->front + 1) % MAX_PLAYER_SIZE;
    return q->data[q->front];
}

//삭제 함수
element peek(QueueType *q)
{
    return q->data[(q->front + 1) % MAX_PLAYER_SIZE];
}

int main()
{
    QueueType queue;
    int num = 0;
    int maxPlayer = 0;  //Max Player Value
    cout << "플레이어 수: ";
    cin >> maxPlayer;
    //char* playerList[maxPlayer];
    //char nameBuffer[10];
    char player[10][10];

    int i = 0;
    int length = 0;

    cout << "-------------------------------------------" << endl;

    // while(i < maxPlayer)
    // {
    //     cout << i + 1 << "번째 플레이어 이름: ";
    //     cin >> nameBuffer;
    //     length = strlen(nameBuffer);

    //     if(length > 0)
    //     {
    //         char* newStrPtr = (char*)malloc(sizeof(char) * (length + 1));
    //         strcpy(newStrPtr, nameBuffer);
    //         playerList[i] = newStrPtr;
    //         enqueue(&queue, nameBuffer);
    //         i++;
    //     }
    //     else
    //         break;
    // }

    for(i = 0; i < maxPlayer; i++)
    {
        cout << i + 1 << "번째 플레이어 이름: ";
        cin >> player[i];
        enqueue(&queue, player[i]);
    }    

    for(int input = 0; input < maxPlayer; input++)
    {
        enqueue(&queue, playerList[i]);
    }

    cout << "-------------------------------------------" << endl;

    for(i = 0; i < maxPlayer; i++)
        cout << i + 1 << "번째 참가자: " << queue.data[i] << endl;  //Print Player Name

    cout << "-------------------------------------------" << endl;

    cout << "num: ";
    cin >> num;

    for(int turn = 0; turn < num; turn++)
    {
        element = dequeue(&queue);  //dequeue front and assignment it to element
        enqueue(&queue, element);   //enqueue element to rear
    }

    cout << "Size of queue: " << sizeof(queue) << endl;

    return 0;
}