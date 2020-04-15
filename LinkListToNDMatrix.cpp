struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]

Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *head = new Node(mat[0][0]);
    Node *traverse = head;

    Node *Htraverse = head;
    Node *Vtraverse = head;

    Node *BindRight,*BindDown;

	BindDown = BindRight = head;    

    for(int cols=1,rows = 1;cols<n && rows<n;cols++,rows++)
    {
    	Htraverse->right = mat[0][cols];
    	Htraverse = Htraverse->right;

    	Vtraverse->down = mat[rows][0];
    	Vtraverse = Vtraverse->down;
    }

    BindRight = head->right;
    BindDown = head->down;

    for(int rows = 1;rows<n;rows++)
    {
    	
    	Node *horizontalCols = BindRight,*horizontalRows = BindDown;
    	
    	for(int cols=1;cols<n;cols++)
    	{
    		horizontalRows->right = horizontalCols->down = new Node(mat[rows][cols]);
    		horizontalRows = horizontalRows->right;
    		horizontalCols = horizontalCols->right;
    	}

    	BindRight = BindRight->down;
    	BindDown = BindDown->down;
    }
    return head;
}