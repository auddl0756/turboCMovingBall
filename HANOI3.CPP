#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
//#define bot 420;

int s[20],m[20],e[20];
int sNum,mNum,eNum;		//s,m,e의 스택 몇개 쌓여있는지 세아릴 용도
int s_last,m_last,e_last;
char *x[]={"1","2","3","4","5","6","7","8","9","10"};

void drawBGround(){
	bar(50,420,150,450);	line(100,100,100,420);
	bar(200,420,300,450);	line(250,100,250,420);
	bar(350,420,450,450);	line(400,100,400,420);
}

void drawD(int size,int n,int start,int end){
	
	int i=0,temp,s1=0,m1=0,e1=0;
	


/* why this code not work ........?

//find last of s[i],m[i],e[i]...
	s1=0;
	while(s[s1]!=0){	
		s1++;	
	}
	s_last=s1-1;

	m1=0;
	while(m[m1]!=0){	
		m1++;
	}
	m_last=m1-1;

	 e1=0;
	while(e[e1]!=0){
		e1++;
	}
	e_last=e1-1;
*/
cleardevice();
drawBGround();	






//draw nowstate...
	i=0;				
	while(s[i]!=0){
		bar(100-10*s[i],420-20*(i+1),100+10*s[i],420-20*i);
		i++;
	}
	i=0;
	while(m[i]!=0){
		bar(250-10*m[i],420-20*(i+1),250+10*m[i],420-20*i);
		i++;
	}
	i=0;
	while(e[i]!=0){
		bar(400-10*e[i],420-20*(i+1),400+10*e[i],420-20*i);
		i++;
	}

	delay(500);
	
//delete moved one at start...
	if(start==1){		
		temp=s[s_last-1];
		s[s_last-1]=0;
		s_last--;
	}
	if(start==2){
		temp=m[m_last-1];
		m[m_last-1]=0;
		m_last--;
	}
	if(start==3){
		temp=e[e_last-1];
		e[e_last-1]=0;
		e_last--;	
	}
	
	


//add moved one at end...
	
	if(end==1){	
		s_last++;		
		s[s_last-1]=temp;
		
	}
	if(end==2){
		m_last++;
		m[m_last-1]=temp;
		//printf("%d ",m[m_last]);
	}
	if(end==3){
		e_last++;
		e[e_last-1]=temp;
		//printf("%d ",e[e_last]);
	}

/*
for(i=0;i<5;i++){
	printf("s:%d ",s[i]);
}
for(i=0;i<5;i++){
	printf("m:%d ",m[i]);
}
for(i=0;i<5;i++){
	printf("e:%d ",e[i]);
}
delay(2000);
*/
cleardevice();
drawBGround();


//draw after state...
	i=0;				
	while(s[i]!=0){
		bar(100-10*s[i],420-20*(i+1),100+10*s[i],420-20*i);
		i++;
	}
	i=0;
	while(m[i]!=0){
		bar(250-10*m[i],420-20*(i+1),250+10*m[i],420-20*i);
		i++;
	}
	i=0;
	while(e[i]!=0){
		bar(400-10*e[i],420-20*(i+1),400+10*e[i],420-20*i);
		i++;
	}

	delay(500);
cleardevice();
drawBGround();

}


void move(int n0,int n,int start,int end){
	int i;	
	if(n==0) return;
	
	move(n,n-1,start,6-start-end);
	//printf("[%d]번째 원판을 [%d]에서 [%d]로 옮겼다\n",n,start,end);
	
	drawD(n,n,start,end);
		
	move(n,n-1,6-start-end,end);
}


int main(){
	int gm=VGA,gd=VGAHI;
	initgraph(&gm,&gd,"..//bgi");
	int n,n0,i;
	printf("HOW MANY DIscur?");
	scanf("%d",&n);
	for(i=0;i<n;i++){	//1st bar initialize..
		s[i]=n-i;
	}

	s_last=n;
	m_last=0;
	e_last=0;

	n0=n;
	sNum=n; mNum=0; eNum=0;
	move(n0,n,1,3);
}