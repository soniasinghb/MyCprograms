struct node *getnode(struct node *s, int ele, int row_i, int col_i){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->val=ele;
    p->row=row_i;
    p->col=col_i;
    p->next=p->prev=NULL;

    if(s==NULL)
        s=p;
    else{
        while
    }
    return s;
}

void printf(struct node *s,int rows,int cols){
    if(s==NULL)
        printf("Empty");
    else{
        for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
        printf("SPARSE MATRIX:");
        struct node *temp=s;
        if(temp!=NULL&&temp->row==i&&temp->col==j)
        {
            printf("%d\t",temp->val);
            temp=temp->next;
        }
        else
            printf("0\t");
        }
    }        
}