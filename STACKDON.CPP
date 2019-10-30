#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <alloc.h>
#include <dos.h>

int z_buf2=0; //
int *buf,*buf2; //NUM BOX,,EMPTY BOX
int s,s2;
int count=0;
char *x[]={"1","2","3","4","5"};
//s=imagesize(50,50,200,150);
//buf=(int *)malloc(s);
void frame();
void unit();
void motion_in();
void motion_out();
void push();
void pop();
void before();
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
	printf("push:1 pop:2 finish:3\n");
	scanf("%d",&select);
	switch(select){
		case 1: push();
			break;
		case 2: pop();
			break;
		default: return 0;
		}
	}

}
void bebefore(){
	double i=0;
	while(i<count-1){
		putimage(150,250-50*i,buf2,COPY_PUT);
		settextstyle(1,0,3);
		outtextxy(190,250-50*i+50,x[i]);
		i++;
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
void push(){
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
void pop(){
	if(count==0){
		printf("underflow\n");
		return ;
	}
	motion_out();
	count--;


}
void unit(){  				//getimaged..
	//putimage(150,250-50*count,buf,COPY_PUT);
	delay(100);
	//char *x[]={"1","2","3","4","5"};

	s=imagesize(50,50,200,150);
	//s2=imagesize(50,50,200,150);
	buf=(int *)malloc(s);
	//buf2=(int *)malloc(s2);
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
	//before();
	double i,j,k;
	j=0;
	cleardevice();
	for(i=250-50*count;i>=10;i-=10){
		frame();
		bebefore();
		putimage(150,i,buf2,COPY_PUT);
		settextstyle(1,0,3);
		outtextxy(190,i+50,x[count-1]);
		delay(50);

		cleardevice();
		frame();
		bebefore();
	}
	for(i=190;i<300;i+=10){
		frame();
		bebefore();
		putimage(i,10,buf2,COPY_PUT);
		settextstyle(1,0,3);
		outtextxy(i+40,60,x[count-1]);
		delay(50);
		cleardevice();
		frame();
		bebefore();
	}
	bebefore();
	frame();
}
void motion_in(){			      //move cube...
	double i,j,k;
	j=0;
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
	int data1[]={145,100,145,350,255,350,255,100,145,100};
	int data2[]={255,100,305,50,305,300,255,350,255,100};
	int data3[]={145,100,255,100,305,50,195,50,145,100};
	drawpoly(5,data1);
	drawpoly(5,data2);
	drawpoly(5,data3);

	setlinestyle(1,0,1);
	line(145,350,195,300); line(195,300,195,50); line(195,300,305,300);

	//rail
	line(0,100,145,100); line(50,50,195,50);
	line(255,100,400,100); line(305,50,450,50);

	//setlinestyle(4,0xff00,1);

}


















