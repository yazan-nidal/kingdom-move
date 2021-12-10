#include<iostream>
#define size 100
using namespace std;
struct node{int x;
int y;
void operator=(int v[2]){x=v[0];y=v[1];}
};
struct queue{ node item[size];
int front;
int rear;
bool emptY(){return front==rear;}
bool fuLL(){return front==(rear+1)%size;}
void cleaR(){front=rear=0;}
void inserT(node x){if(!fuLL()){rear=(rear+1)%size;
item[rear]=x;}else{cout<<"	Queue is FuLL \n";}}
node removE(){if(!emptY()){front=(front+1)%size;
return item[front];}else{cout<<"	Queue is Empty \n";}}
node fronT(){return item[(front+1)%size];}
};
// basics
int row=0;
int colom=0;
bool valid(int x,int y){return(((x>=0)&&(x<row))&&((y>=0)&&(y<colom-1)));}
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
int **visted=NULL;
//Matrix function
bool emptY_Matrix(char **&buzel){return((buzel==NULL)&&(visted==NULL)&&(row==0)&&(colom==0));}// test if empty matrix
void delete_Matrix(char **&buzel){if(!emptY_Matrix(buzel)){for(int i=0;i<row;i++){delete []buzel[i]; delete[]visted[i];}
	delete []buzel; delete[]visted; }
buzel=NULL; visted=NULL; row=0; colom;}//delete matrix
void prinT_Matrix(char **&buzel){//prt
	if(!emptY_Matrix(buzel)){cout<<"\n";
	for(int i=0;i<row;i++){
	for (int j=0;j<colom;j++)
	{cout<<"	"<<buzel[i][j];}cout<<"\n";}}else{cout<<"	Error : Empty Matrix please Insert Matrix color \n";}}//eprt MYC
void insert_Matrix(char **&buzel){//bi
	delete_Matrix(buzel);
	cout<<"\n";
	cout<<"	Enter number of Row -> "; cin>>row;
cout<<"	Enter number of colom -> "; cin>>colom;
colom++;// for NULL
cout<<"\n";
visted= new int*[row];
for(int i=0;i<row;i++){visted[i]=new int[colom];}
for(int i=0;i<row;i++){for(int j=0;j<colom;j++){visted[i][j]=0;}}
buzel=new char*[row];
for(int i=0;i<row;i++){buzel[i]=new char[colom];}
for(int i=0;i<row;i++){cout<<"	Enter "<<i+1<<" row -> "; cin>>buzel[i];}
}//ebi
void convert_color(char **&buzel){//move
	if(!emptY_Matrix(buzel)){
		for(int i=0;i<row;i++){for(int j=0;j<colom;j++){visted[i][j]=0;}}//empty visted
	queue q;
	q.cleaR();
	int x;
	int y;
	char c;
	cout<<"\n	Note :\n	The range of rows starts from "<<1<<" and ends with "<<row<<"\n";
	cout<<"	The range of coloms starts from "<<1<<" and ends with "<<colom-1<<"  \n";
	do{cout<<"\n	Enter start point from range :\n\n";
	cout<<"	Enter X position -> "; cin>>y; y=y-1;// colom position as x-axis
	cout<<"	Enter Y position -> "; cin>>x; x=x-1;// row position as y-axis
	cout<<"	Enter New Color ->";cin>>c; cout<<"\n";
	if(!valid(x,y)){cout<<"	Error : unvalid point \n";}}
	while(!valid(x,y));
	visted[x][y]=1;
	node *ne=new node;
	int v[2];
	v[0]=x;
	v[1]=y;
	*ne=v;
	q.inserT(*ne);
	char temp=buzel[x][y];
	buzel[x][y]=c;
	while(!q.emptY()){
		x=q.fronT().x;
		y=q.fronT().y;
		for(int i=0;i<4;i++){
		x+=movex[i];
		y+=movey[i];
		if(valid(x,y)&&(!visted[x][y])){
			visted[x][y]=1;
			if((buzel[x][y]==temp)){
			buzel[x][y]=c;
		v[0]=x;
		v[1]=y;
		*ne=v;
		q.inserT(*ne);
			}}
	x=q.fronT().x;
		y=q.fronT().y;
		}
		q.removE();}}
	else{cout<<"	Error : Empty Matrix please Insert Matrix color \n";}
	}//emove
void List_and_Processing(char **&buzel){
int select=0;
cout<<"	List : \n";
cout<<"	1 -	Insert Matrix color \n";
cout<<"	2 -	Print Matrix \n";
cout<<"	3 -	Insert start point and replacement color to replaced it and replaced the connected similarly colored \n";
cout<<"	4 -	Clean the Screen \n";
cout<<"	5 -	Exit the Program \n";
while(select !=5){
cout<<"\n	Select from the List -> ";
cin>>select;
cout<<endl;
switch(select){
case 1:{insert_Matrix(buzel);
	   break ;}
case 2:{prinT_Matrix(buzel);
	break;}
case 3:{ convert_color(buzel);
	break;}
	   
case 4:{system("cls");
cout<<"	List : \n";
cout<<"	1 -	Insert Matrix color \n";
cout<<"	2 -	Print Matrix \n";
cout<<"	3 -	Insert start point and replacement color to replaced it and replaced the connected similarly colored \n";
cout<<"	4 -	Clean the Screen \n";
cout<<"	5 -	Exit the Program \n";
	   break;}

default :{if(select!=5)cout<<"\n	Error Select \n";
		 }}
}
cout<<"\n	End OF ProGraM \n";
}
void main(){//main
	char **buzel=NULL;
	List_and_Processing(buzel);

	}//end main

