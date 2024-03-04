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

//˳����ʼ��
Status InitList(SqList& L) {
   L.elem = new Book[MAXSIZE];
   if (!L.elem) exit(OVERFLOW);
   return OK;
}

Status bubble(SqList &L){                           //2222���� 
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

Status add(SqList &L){                           //3333ͼ����Ϣ����޸� 
	int i,c=0,j=1;
	double average;
	for(i=0;i<L.length;i++){
		c=c+L.elem[i].price;
		j++;
	}
	average=c/j;
	cout<< "ƽ���۸�Ϊ��" << average <<endl; 
	for(i=0;i<L.length;i++){
	if(L.elem[i].price<average){
		L.elem[i].price=L.elem[i].price+L.elem[i].price*0.2;
	}
	else{
		L.elem[i].price=L.elem[i].price+L.elem[i].price*0.1;
		}
	}
}

Status output(SqList &L){          //4444�������� 
      int i;
      Book t;
 for(i=0;i<L.length/2;i++){
  t=L.elem[i];
  L.elem[i]=L.elem[L.length-i-1];
  L.elem[L.length-i-1]=t; 
 }
}

Status expensive(SqList L)                        //5555���ͼ���Ѱ�� 
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
		cout << "����鼮����ϢΪ:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
		}
	}
}

Status LocateElem_Sq(SqList L,string e){           //6666�ͼ��Ĳ��� 
	int i;
	for (i = 0; i < L.length; i++){
		if(e==L.elem[i].name){
		cout << "��ϲ���鼮����ϢΪ:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
			return OK;
		}
	}
}	 

Status GetElem(SqList L,int a){                     //7777����λ�����鼮 
	int i;
	for ( i= 0; i<=L.length-1; i++){
		if(i==a-1){
		cout << "���λ�õ��鼮����ϢΪ:" << L.elem[i].no<<" " << L.elem[i].name<<" "  << L.elem[i].price << endl;
		return OK;
		}
		
}
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) { //8888���� 
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


Status ListDelete_Sq(SqList &L, int i, ElemType e) { //9999ɾ�� 
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

Status DeleteSame(SqList &L){//10101010���� 
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
		cout << "1. �½��ձ�\n";
		cout << "2. �������\n";
		cout << "3. ð������\n";
		cout << "4. ͼ����Ϣ����޸�\n";
		cout << "5. ����洢\n";
		cout << "6. ���ͼ��Ĳ���\n";
		cout << "7. �ͼ��Ĳ���\n";
		cout << "8. ����λ�����鼮\n";
		cout << "9. �����鼮\n";
		cout << "10.ɾ���鼮\n";
		cout << "11.����\n";
		cout << "0. �˳�\n"; 


		cout << "��ѡ��:";
		cin >> choice;

	}
	return choice; 
}

int PrintAllElement(SqList L) {//�����ȫ��Ԫ�������
	int i,n;
	cout << "��ǰ��������Ԫ��Ϊ:\n";
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
			case 1://����
			if(InitList(L)){
				cout << "����ɹ���" << endl; 
			}else{
				cout << "����ʧ�ܣ�" << endl; 
			}
			break;
			case 2://ʵ��1111������� 
   cout<< "���������š����֡��۸�(��0 0 0 ��Ϊ������־) "<<endl;
   while (1) {                     
    cin >> L.elem[i - 1].no >> L.elem[i - 1].name >> L.elem[i - 1].price;
     if (!(L.elem[i - 1].no== "0") && !(L.elem[i - 1].name== "0") && L.elem[i - 1].price == 0.0)//���������ʶ 
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
     		case 3://ʵ��2222����
    	bubble(L);     	
	    PrintAllElement(L);
	 	break;
	 		case 4://ʵ��3333ͼ����Ϣ����޸�
     	add(L);
     	PrintAllElement(L);
     	break; 
     	    PrintAllElement(L);
     	    break; 
     		case 5://ʵ��4444����洢
     	output(L); 
		cout<<"�����Ϊ:"<<endl;                   
	    PrintAllElement(L); 
     	break;
     		case 6://ʵ��5555���ͼ��Ĳ���
     	expensive(L);
		break;                                
     		case 7://ʵ��6666�ͼ��Ĳ���
     	cout << "������Ҫ���ҵĴ�����";
		 cin >> N;
		 for(i=0;i<N;i++) {
	 cout<< "������Ҫ���ҵ�������"; 
	 cin>>inputelem.name;
	 	location=LocateElem_Sq(L,inputelem.name);                     
		 if(location!=1){
		 	cout << "��Ǹ��û��������鼮" << endl; 
		 }
	 }
	 	break;
	 		case 8://ʵ��7777����λ�����鼮
	 	cout <<"������Ҫ���ҵĴ�����";
		 cin >> N;
		  for(i=0;i<N;i++) {
	cout<< "������Ҫ���ҵ�λ�ã�"; 
	cin>> location; 
	location=GetElem(L,location);                             
	 if(location!=1){
		 	cout << "û���ҵ�����鼮��" << endl; 
		 }
	 }
	 break;
	 		case 9://ʵ��8888���� 
	 cout << "������Ҫ�����λ�ã�"; 
	 cin >> N;
	cout<< "���������š����֡��۸� "<<endl;
	cin >> inputelem.no >> inputelem.name >> inputelem.price;
	if (ListInsert_Sq(L,N,inputelem)){
		cout << "����ɹ�!" << endl;
		}else{
		cout << "����ʧ��!" << endl;
		}
	    PrintAllElement(L);
     break;
     		case 10://ʵ��9999ɾ��
      cout << "������Ҫɾ����λ�ã�"; 
	 cin >> N;
//	ListDelete_Sq(L,N,inputelem);
	if (ListDelete_Sq(L,N,inputelem)){
		cout << "ɾ���ɹ�!" << endl;
		}else{
		cout << "ɾ��ʧ��!" << endl;
		}
	    PrintAllElement(L);
     break;
     		case 11://ʵ��101010����
     DeleteSame(L); 
        PrintAllElement(L);
     
     
		}
	}
}
