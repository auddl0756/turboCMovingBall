#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <alloc.h>
#include <dos.h>

int z_buf2=0; //   to capture empty box just once..
int *buf,*buf2,*buf3; //NUM BOX,,EMPTY BOX ,capture except_bot
int s,s2,s3;
int count=0;
char *x[5];
//s=imagesize(50,50,200,150);
//buf=(int *)malloc(s);
void frame();
void unit();
void motion_in();
void motion_out();
void put();
void get();
void before();
void except_bot();
int main(){

	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"..//bgi");
	setactivepage(0);
	setvisualpage(0);
	cleardevice();
	int select;
	//line(550,350,550,450);
	//unit();
	//frame();
	//delay(1000);
	//motion();
	//delay(1000);

	//push();
	while(1){
	printf("put:1 get:2 finish:3\n");
	scanf("%d",&select);
	switch(select){
		case 1: put();
			break;
		case 2: get();
			break;
		default: return 0;
		}
	}

}
void except_bot(double j){
	double i;
	for(i=1;i<count;i++){
		putimage(150,250-50*i+j,buf2,COPY_PUT);
		//putimage(150,250-j,buf2,COPY_PUT);
		settextstyle(1,0,3);
		outtextxy(190,250-50*i+50+j,x[i]);
		//outtextxy(190,250-50*i+50,x[i]);
	}
}
void before(){
	double i=0;
	//char *x[]={"1","2","3","4","5"};
	while(i<count){
		putimage(150,250-50*(i),buf2,COPY_PUT);
		//delay(100);
		settextstyle(1,0,3);
		outtextxy(190,250-50*(i)+50,x[i]);
		i++;
	}
	//delay(1000);
}
void put(){
	if(count==5){
		printf("overflow\n");
		return ;

	}
	unit();
	motion_in();
	free(buf);
	//free(buf2);
	count++;

}
void get(){
	if(count==0){
		printf("underflow\n");
		return ;
	}
	motion_out();
	count--;
	//free(x[0]);
	//x[1]=x[0],x[2]=x[1],x[3]=x[2],x[4]=x[3];

}
void unit(){  				//getimaged..
	x[count]=(char *)malloc(4);
	s=imagesize(50,50,200,150);
	//s2=imagesize(50,50,200,150);
	buf=(int *)malloc(s);
	//printf("now count:%d\n",count);
	//printf("now array x:%s %s %s %s %s\n",x[0],x[1],x[2],x[3],x[4]);
	printf("input:");
	scanf("%s",x[count]);
	setlinestyle(1,0,1);
	line(400,400,400,450); line(400,450,500,450); line(500,450,500,400); line(500,400,400,400);
	line(400,400,450,350); line(450,350,550,350); line(550,350,500,400); line(500,400,400,400);
	line(500,400,550,350); line(550,350,550,400); line(550,400,500,450); line(500,450,500,400);
	setlinestyle(1,0,1);
	line(450,400,400,450); line(450,400,450,350); line(450,400,550,400);
	if(z_buf2==0){
		s2=imagesize(50,50,200,150);
		buf2=(int *)malloc(s2);
		getimage(400,350,550,450,buf2);//no text just box
	}
	settextstyle(1,0,3);
	//setcolor(1);
	outtextxy(440,410,x[count]);
	getimage(400,350,550,450,buf);//box with text
	z_buf2++;
}
void motion_out(){
	double i,j,k;

	cleardevice();
	for(i=150;i<400;i+=20){  //move ->
		frame();
		except_bot(0);

		//delay(50);

		putimage(i,250,buf2,COPY_PUT);
		settextstyle(1,0,3);
		outtextxy(i+40,250+50,x[0]);//****need repair....***.
		//delay(50);
		delay(30);
		cleardevice();
		frame();
		except_bot(0);
	}
	/*
	for(i=1;i<count;i++){
		x[i-1]=x[i];
	}
	*/
	for(i=0;i<=50;i+=5){		//    downside motion..
		frame();
		except_bot(i);

		//delay(50);

		putimage(150,i,buf3,COPY_PUT);
		settextstyle(1,0,3);
		//outtextxy(190,i,x[0]);
		//delay(50);
		delay(30);
		cleardevice();
		frame();
		except_bot(i);
	}
	//putimage(150,300-50*count+50,buf3,COPY_PUT);
	//except_bot();
	//frame();
	for(i=1;i<count;i++){
		x[i-1]=x[i];
	}

	frame();
}
void motion_in(){			      //move cube...
	double i,j,k;
	j=0;
	//printf("input:");
	//scanf("%s",x[count]);
	for(i=10;i<150;i+=10){
	putimage(i,0,buf,COPY_PUT);
	//before();
	delay(50);
	cleardevice();
	frame();
	before();
	}
	//before();
	for(i=0;i<=250-50*count;i+=10){
	//if(i>=250-50*count){
	  //	getimage(150,250-50*count,300,250-50*(count)+100,buf2);
	//}
	putimage(150,i,buf,COPY_PUT);
	//before();
	delay(50);
	cleardevice();
	frame();
	//putimage(150,250-50*count,buf,COPY_PUT);
	before();
	}
	//putimage(150,250-50*count,buf,COPY_PUT);

	before();
	putimage(150,250-50*count,buf2,COPY_PUT);
	outtextxy(190,250-50*count+50,x[count]);
	frame();
	//putimage(150,250-50*count,buf2,COPY_PUT);
	//delay(100);
	//free(buf);
}
void frame(){
	 double i;
	int data1[]={145,100,145,350,255,350,255,100,145,100};
	int data2[]={255,100,305,50,305,300,255,350,255,100};
	int data3[]={145,100,255,100,305,50,200,50,145,100};
	drawpoly(5,data1);
	drawpoly(5,data2);
	drawpoly(5,data3);

	setlinestyle(1,0,1);
	line(150,350,200,300); line(200,300,200,50); line(200,300,300,300);
	//setlinestyle(4,0xff00,1);
	//rail
		line(0,100,150,100); line(50,50,200,50);
	for(i=0;i<150;i+=30){
		setlinestyle(4,1,1);
		line(i,100,i+50,50);
	}
	setlinestyle(1,1,1);
	line(255,350,400,350); line(305,300,450,300);

	line(255,290,305,240);
	line(255,290,400,290); line(305,240,450,240);
	int exit[]={400,290,400,350,450,300,450,240,400,290};
	drawpoly(5,exit);
}


















