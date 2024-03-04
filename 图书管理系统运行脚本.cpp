#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#define MAXSIZE 100
#define ERROR 0
#define OVERFLOW -2
#define OK 1
typedef int Status;

struct Book{
   char no[20];
   char name[50];
   float price;
};
typedef struct Book ElemType;

typedef struct {
   Book* elem;
   int length;
}SqList;

//顺序表初始化
Status InitList(SqList& L) {
   L.elem = new Book[MAXSIZE];
   if (!L.elem) exit(OVERFLOW);
   return OK;
}

Status bubble(SqList &L){                           //2222排序 
	int i,j;
	ElemType t;
	for(i=1;i<L.length;i++){
		for(j=0;j<L.length-i;j++){
			if(L.elem[j].price<L.elem[j+1].price){
			t=L.elem[j];
			L.elem[j]=L.elem[j+1];
			L.elem[j+1]=t;
		}
		}
	}
}

Status add(SqList &L){                           //3333图书信息表的修改 
	int i,c=0,j=1;
	double average;
	for(i=0;i<L.length;i++){
		c=c+L.elem[i].price;
		j++;
	}
	average=c/j;
	cout<< "平均价格为：" << average <<endl; 
	for(i=0;i<L.length;i++){
	if(L.elem[i].price<average){
		L.elem[i].price=L.elem[i].price+L.elem[i].price*0.2;
	}
	else{
		L.elem[i].price=L.elem[i].price+L.elem[i].price*0.1;
		}
	}
}

Status output(SqList &L){          //4444逆序排序 
      int i;
      Book t;
 for(i=0;i<L.length/2;i++){
  t=L.elem[i];
  L.elem[i]=L.elem[L.length-i-1];
  L.elem[L.length-i-1]=t; 
 }
}

Status expensive(SqList L)                        //5555最贵图书的寻找 
{
	int i,j=0;
	double Max;
	ElemType t;
	Max=L.elem[0].price;
	for(i=0;i<L.length;i++){
		if(L.elem[i].price>Max){
			Max=L.elem[i].price;
		}
	}
	for(i=0;i<L.length;i++){
		if(L.elem[i].price==Max){
			j++;
		}
	}
	cout << j << endl; 
	for(i=0;i<L.length;i++){
		if(L.elem[i].price==Max){
		cout << "最贵书籍的信息为:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
		}
	}
}

Status LocateElem_Sq(SqList L,string e){           //6666最爱图书的查找 
	int i;
	for (i = 0; i < L.length; i++){
		if(e==L.elem[i].name){
		cout << "最喜爱书籍的信息为:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
			return OK;
		}
	}
}	 

Status GetElem(SqList L,int a){                     //7777根据位置找书籍 
	int i;
	for ( i= 0; i<=L.length-1; i++){
		if(i==a-1){
		cout << "最佳位置的书籍的信息为:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
		return OK;
		}
		
}
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) { //8888插入 
	if ((i < 1) || (i > L.length + 1))
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--){
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}


Status ListDelete_Sq(SqList &L, int i, ElemType e) { //9999删除 
		if ((i < 1) || (i > L.length + 1))
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = i - 1; j < L.length - 1; j++){
		L.elem[j] = L.elem[j+1];
	}
	--L.length;
	return OK;
}

Status DeleteSame(SqList &L){//10101010查重 
	int i,j,k;
	for(i=0;i<L.length;i++){
		for(j=i+1;j<L.length;j++){
			if(strcmp(L.elem[i].no,L.elem[j].no)==0){
				for(k=j;k<L.length;k++){
					L.elem[k]=L.elem[k+1];
				}
				--L.length;
			}
		}
	}
}

int Menu() {
	int choice;
	choice=12;

	while (choice<0||choice>11) {
		cout << "1. 新建空表\n";
		cout << "2. 输入输出\n";
		cout << "3. 冒泡排序\n";
		cout << "4. 图书信息表的修改\n";
		cout << "5. 逆序存储\n";
		cout << "6. 最贵图书的查找\n";
		cout << "7. 最爱图书的查找\n";
		cout << "8. 根据位置找书籍\n";
		cout << "9. 插入书籍\n";
		cout << "10.删除书籍\n";
		cout << "11.查重\n";
		cout << "0. 退出\n"; 


		cout << "请选择:";
		cin >> choice;

	}
	return choice; 
}

int PrintAllElement(SqList L) {//输出（全部元素输出）
	int i,n;
	cout << "当前表中所有元素为:\n";
	n=L.length;
	cout<<"__________________________________"<<endl;
	for (i = 0; i < n; i++) {
		cout<<i<< "\t" <<L.elem[i].no<< "\t"<<L.elem[i].name<< "\t"<<L.elem[i].price<<endl;
	}
	cout<<"__________________________________"<<endl;
}

int main() {
   SqList L;
//   InitList(L);
   int i=1,N,j,location;
   int choice;
   ElemType inputelem;
   
   	while(1) {
		choice=Menu();
		if(choice==0) break;
		switch(choice){
			case 1://建表
			if(InitList(L)){
				cout << "建表成功！" << endl; 
			}else{
				cout << "建表失败！" << endl; 
			}
			break;
			case 2://实验1111输入输出 
   cout<< "输入书的序号、名字、价格(以0 0 0 作为结束标志) "<<endl;
   while (1) {                     
    cin >> L.elem[i - 1].no >> L.elem[i - 1].name >> L.elem[i - 1].price;
     if (!(L.elem[i - 1].no== "0") && !(L.elem[i - 1].name== "0") && L.elem[i - 1].price == 0.0)//输入截至标识 
      {
        break;
      }
      i++; 
            }
   L.length = i - 1;
   N=i-1;
   cout << L.length << endl;
    PrintAllElement(L);
     	break;
     		case 3://实验2222排序
    	bubble(L);     	
	    PrintAllElement(L);
	 	break;
	 		case 4://实验3333图书信息表的修改
     	add(L);
     	PrintAllElement(L);
     	break; 
     	    PrintAllElement(L);
     	    break; 
     		case 5://实验4444逆序存储
     	output(L); 
		cout<<"倒序后为:"<<endl;                   
	    PrintAllElement(L); 
     	break;
     		case 6://实验5555最贵图书的查找
     	expensive(L);
		break;                                
     		case 7://实验6666最爱图书的查找
     	cout << "请输入要查找的次数：";
		 cin >> N;
		 for(i=0;i<N;i++) {
	 cout<< "请输入要查找的书名："; 
	 cin>>inputelem.name;
	 	location=LocateElem_Sq(L,inputelem.name);                     
		 if(location!=1){
		 	cout << "抱歉！没有你最爱的书籍" << endl; 
		 }
	 }
	 	break;
	 		case 8://实验7777根据位置找书籍
	 	cout <<"请输入要查找的次数：";
		 cin >> N;
		  for(i=0;i<N;i++) {
	cout<< "请输入要查找的位置："; 
	cin>> location; 
	location=GetElem(L,location);                             
	 if(location!=1){
		 	cout << "没有找到相关书籍！" << endl; 
		 }
	 }
	 break;
	 		case 9://实验8888插入 
	 cout << "请输入要插入的位置："; 
	 cin >> N;
	cout<< "输入书的序号、名字、价格 "<<endl;
	cin >> inputelem.no >> inputelem.name >> inputelem.price;
	if (ListInsert_Sq(L,N,inputelem)){
		cout << "插入成功!" << endl;
		}else{
		cout << "插入失败!" << endl;
		}
	    PrintAllElement(L);
     break;
     		case 10://实验9999删除
      cout << "请输入要删除的位置："; 
	 cin >> N;
//	ListDelete_Sq(L,N,inputelem);
	if (ListDelete_Sq(L,N,inputelem)){
		cout << "删除成功!" << endl;
		}else{
		cout << "删除失败!" << endl;
		}
	    PrintAllElement(L);
     break;
     		case 11://实验101010查重
     DeleteSame(L); 
        PrintAllElement(L);
     
     
		}
	}
}
