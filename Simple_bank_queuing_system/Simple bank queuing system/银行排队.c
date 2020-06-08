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
        printf("初始化了一个队列......\n");
        if(!(Q->front = Q->tail = (Queue *)malloc(QUEUE_LEN)))
        {
                printf("malloc错误 !\n");
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
                printf(" 错误 !\n");
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
                printf("没有人在等待！\n");
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
                printf("没有人在等待！\n");
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
                printf("没有人在等待！\n");
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
                printf("****************欢迎使用银行排队管理系统*********************\n");
                printf("              1:取号           \n");
                printf("              2:查看排队情况   \n");
                printf("              3:离开银行     \n");
                printf("              4:叫号     \n");
                printf("              5:退出系统                        \n\n\n");
                printf("*************************************************************\n");
                printf("请输入[1-5]的数字:   ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1 :
                                bankNumber++;
                                enterQueue(&Q,bankNumber);
                                totalNumber++;
                                printf("你的号码是： %d\n",bankNumber);
                                printf("%d 个人在您的前面,请耐心等待！\n",Query(&Q,bankNumber));
                                break;

                case 2 :

                        printf("请输入你的号码:\n");
                        scanf("%d",&num);
                        if(Query(&Q,num)==-1){
                        printf("没有人在您的前面，请进！\n");
                        }else
                        printf("%d 个人在您的前面，请耐心等待！\n",Query(&Q,num));
                        break;
                case 3 :

                        printf("%d号正在离开银行！\n",Q.front->next->value);
                        deQueue(&Q);
                        totalNumber--;
                        break;

                case 4 :

                        printf("排队信息 :");
                        printQueue(&Q);
                        printf("%d号请进！\n",Q.front->next->value);
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
