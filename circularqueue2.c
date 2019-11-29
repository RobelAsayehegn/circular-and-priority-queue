#include<stdio.h>
void crenqueue(int num);
void crdequeue();
void Display();
int front = -1, rear = -1,queue[6];

int main(){
	int s,j=2,r;
	int num;
	do{ 
		printf("\n#####################################################################\n");
		printf("\nEnter one to enqueue \n");
		printf("\nEnter two to dequeu \n");
		printf("\nEnter three display items in the queue \n");
		printf("\n#####################################################################\n");
		scanf("%d",&s);
		switch(s)
	    {
		    case 1:
		    	
		    	printf("Enter the number you need to enqueue\n");
		    	scanf("%d",&num);
		    	crenqueue(num);
		    	break;
		    case 2:
		    	crdequeue();
		    	break;
		    case 3:
		    	Display();
		    	break;
		    default:
		    	printf("no operation for this number choose(1,2,3)");
		    	break;
	    }j = 1;
	printf("\nif you want to continue press num>0 else press 0:");
	scanf("%d",&r);
}while(j<=r);
}

void crenqueue(num){
	int temp = (rear+1)%6;
	if(front == temp){
		printf("queue is full\n");
		return;
	}
	rear = temp;
	if(front == -1){
		front = 0;
		rear = 0;
	}
	queue[rear] = num;
	
	
	
}
void crdequeue(){
	int temp ;
	if(front == -1){
		printf("queue is empty\n");
	}else{
		temp = queue[front];
	}
	
	if(rear == front){
		front = -1;
		rear = -1;
	}else{
		front = (front+1)%6;
	}
}
void Display(){
	if(front == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",queue[i++]);
      }
      else{
	 while(i <= 6 - 1)
	    printf("%d\t", queue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",queue[i++]);
      }
   }
}
