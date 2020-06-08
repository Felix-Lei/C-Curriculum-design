#include<stdio.h>
#include<stdlib.h>

#define OK      0
#define ERROR   -1

typedef struct queue
{
        int value;
        struct queue *next;
}Queue;


typedef struct linkqueue
{
        Queue *front;
        Queue *tail;
}LinkQueue;

#define QUEUE_LEN  sizeof(Queue)

int initQueue(LinkQueue *);


int isEmptyQueue(LinkQueue *);

int enterQueue(LinkQueue *,int value);

int deQueue(LinkQueue *);

int printQueue(LinkQueue *);

int Query(LinkQueue *,int);


static bankNumber = 0;

static totalNumber = 0;

int stopBank();
int startBank();

int initQueue(LinkQueue *Q)
{
        printf("��ʼ����һ������......\n");
        if(!(Q->front = Q->tail = (Queue *)malloc(QUEUE_LEN)))
        {
                printf("malloc���� !\n");
                return ERROR;
        }
        Q->front->next = NULL;
        return OK;
}

int enterQueue(LinkQueue *Q,int enterValue)
{
        Queue *tmpNode = NULL;
        if(!(tmpNode = (Queue*)malloc(QUEUE_LEN)))
        {
                printf(" ���� !\n");
                return ERROR;
        }

        tmpNode->value = enterValue;
        tmpNode->next = NULL;
        Q->tail->next = tmpNode;
        Q->tail = tmpNode;

}

int isEmptyQueue(LinkQueue *Q)
{
        return  (Q->front->next == NULL);
}



int printQueue(LinkQueue *Q)
{
        Queue *tmpNode = NULL;
        tmpNode = Q->front->next;
        if(NULL == tmpNode)
        {
                printf("û�����ڵȴ���\n");
                return ERROR;

        }

        while(tmpNode != Q->tail)
        {
                printf("%d  ",tmpNode->value);
                tmpNode = tmpNode->next;
        }
        printf("%d\n",Q->tail->value);

}

int deQueue(LinkQueue *Q)
{
        if(isEmptyQueue(Q))
        {
                printf("û�����ڵȴ���\n");
                return ERROR;
        }
        int value;
        value = Q->front->next->value;
        Q->front->next = Q->front->next->next;
        return value;
}


int Query(LinkQueue *Q,int myNum)
{
        int numOfMan = 0;
        if(isEmptyQueue(Q))
        {
                printf("û�����ڵȴ���\n");
                return ERROR;
        }

        numOfMan = myNum-Q->front->next->value;
        return  numOfMan;
}

int main()
{
        int choice = 0;
        int num = 0;
        LinkQueue Q;
        initQueue(&Q);
        while(1)
        {
                printf("****************��ӭʹ�������Ŷӹ���ϵͳ*********************\n");
                printf("              1:ȡ��           \n");
                printf("              2:�鿴�Ŷ����   \n");
                printf("              3:�뿪����     \n");
                printf("              4:�к�     \n");
                printf("              5:�˳�ϵͳ                        \n\n\n");
                printf("*************************************************************\n");
                printf("������[1-5]������:   ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1 :
                                bankNumber++;
                                enterQueue(&Q,bankNumber);
                                totalNumber++;
                                printf("��ĺ����ǣ� %d\n",bankNumber);
                                printf("%d ����������ǰ��,�����ĵȴ���\n",Query(&Q,bankNumber));
                                break;

                case 2 :

                        printf("��������ĺ���:\n");
                        scanf("%d",&num);
                        if(Query(&Q,num)==-1){
                        printf("û����������ǰ�棬�����\n");
                        }else
                        printf("%d ����������ǰ�棬�����ĵȴ���\n",Query(&Q,num));
                        break;
                case 3 :

                        printf("%d�������뿪���У�\n",Q.front->next->value);
                        deQueue(&Q);
                        totalNumber--;
                        break;

                case 4 :

                        printf("�Ŷ���Ϣ :");
                        printQueue(&Q);
                        printf("%d�������\n",Q.front->next->value);
                        deQueue(&Q);
                        break;
                case 5 :
                        exit(0);
                        break;
                default :
                        break;

                }

        }

        return OK;
}
