#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;

    struct node* next;
}node;

node* head = NULL;

void memfree(node** head)
{
    node* temp = *head;
    while(*head != NULL)
    {
        temp = (*head) -> next;
        free(*head);

        *head = temp;
    }
}

node* node_alloc(int val)
{
    node* temp = malloc(sizeof(node));
    if(!temp)
    {
        printf("Memory error!");

        exit(EXIT_FAILURE);
    }
    
    temp -> next = NULL;

    temp -> val = val;

    return temp;
}

void add_toEnd(node** head,int val)
{
    if(!(*head))
    {
        *head = node_alloc(val);

        return;
    }

    node* cur = *head;
    while(cur -> next != NULL) cur = cur -> next;

    cur -> next = node_alloc(val);
}

void list_print(node* head)
{
    if(!head)
    {
        printf("No elements in list!\n");
        printf("Press any key to continue...");

        getchar();
        return;
    }

    printf("List: ");
    for(int i =0;head!=NULL;i++,head = head -> next)
    {
        printf("[%d]: %d\t",i,head -> val);
    }

    printf("\n");
}

void list_get(node* head,long index)
{
    if(index < 0)
    {
        printf("Indalid index!\n");

        return;
    }

    long val = -1;
    for(int i = 0;head != NULL;i++,head = head -> next)
    {
        if(i == index)
        {
            printf("[%d]: %d\n",i,head->val);

            return;
        }
    }

    printf("No element with given index!\n");
}

void get_size(node* head)
{
    int count = 0;
    if(!head)
    {
        printf("No elements in list!\n");
        printf("Press any key to continue...");

        getchar();
        return;
    }

    int i = 0;						//  Оптимизировала немного получение размера массива,
    for(i; head!=NULL; i++,head = head -> next){}	// теперь выглядит не так громоздко.
    
    printf("Size: %d\n",i);
}

void new_num(node* head,long index, int new)
{
    if(index < 0)
    {
        printf("Indalid index!\n");

        return;
    }

    long val = -1;
    for(int i = 0;head != NULL;i++,head = head -> next)
    {
        if(i == index)
        {
            head->val = new;

            return;
        }
    }

    printf("No element with given index!\n");
}

void del_el(node** head, long index)
{
    if(!(*head))
    {
        printf("No element in List\n");
    }
    
    if(index == 0) // Смотрим, если удалить нужно самый первый элемент списка
    {
    	node* temp = *head;
	*head = (*head) -> next;
	
	free(temp);

	return;
    }

    node* cur = *head;
    for(int i = 0;cur != NULL;i++, cur = cur -> next )
    {
        if(i + 1 == index)   // Остановились перед элементом на удаление
        {
            node* tmp = cur -> next;
            cur -> next = tmp ->next;
            
            free(tmp);

            return;
        }
    }

    printf("No element with such index\n");
}


void add_byindex(node* head,int val, long index)
{
    if(!head)
    {
        printf("No element in List\n");
    }
    
    if(index < 1)
    {
	printf("Wrong index!\n");

	return;
    }

    for(int i = 0;head != NULL;i++, head = head -> next )
    {
        if(i + 1 == index)   // Останавливаемся перед местом добавления  
        {
		node* tmp = node_alloc(val);
		
		tmp -> next = head -> next;
		head -> next = tmp;

		return;
        }
    }

    printf("No element with such index\n");
}


int main()
{
    printf("ArrayList program\n");

    while(1)
    {
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Get value by index\n");
        printf("4. Get size\n");
        printf("5. New num\n");
	printf("6. Delete by index\n");
	printf("7. Add by index\n");
        printf("8. Exit\n");

        int ch = -1;
        scanf("%1d",&ch);
        while(getchar()!='\n');

        switch (ch) 
        {
            case 1:
            {
                printf("Enter value: ");
                int val = 0;
                scanf("%d",&val);
                while(getchar()!='\n');

                add_toEnd(&head, val);

                break;
            }

            case 2:
            {
                list_print(head);

                break;
            }

            case 3:
            {
                printf("Enter index: ");
                int index = 0;
                scanf("%d",&index);
                while(getchar()!='\n');

                list_get(head, index);
                break;
            }
            
            case 4:
            {
                get_size(head);
                break;
            }
            
            case 5:
            {
                printf("Enter index: ");
                int index = 0;
                scanf("%d",&index);
                printf("Enter new num: ");
                int num = 0;
                scanf("%d",&num);
                while(getchar()!='\n');

                new_num(head, index, num);
                break;
            }

	    case 6:
	    {
                printf("Enter index: ");
                int index = 0;
                scanf("%d",&index);
                while(getchar()!='\n');

		del_el(&head,index);

		break;
	    }

	    case 7:
	    {
		
                printf("Enter index: ");
                int index = 0;
                scanf("%d",&index);
                printf("Enter val: ");
                int val = 0;
                scanf("%d",&val);
                while(getchar()!='\n');

                add_byindex(head,val, index);
                break;
	    }
            
            case 8:
            {
                memfree(&head);
                
                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
}

