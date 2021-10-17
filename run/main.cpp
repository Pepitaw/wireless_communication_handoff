#include<iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<cmath>
using namespace std;
class car{
	public:
		car();
		void direction();
		void run();
		int x,y,z,runtime,bs1=1,bs2=1,bs3=1,bs4=1;
		double strength1=0,strength2=0,strength3=0,strength4=0;
	private:
};
int count=0,handoff1=0,handoff2=0,handoff3=0,handoff4=0,re=0;
double P1=0,P2=0,P3=0,P4=0;
vector <car> data;
car::car(){
	x=0,y=0,z=0,runtime=0;
}
void car::direction(){
	srand( time(NULL) );
	if(rand()%12+1<=6){	//straight
	}
	else if(rand()%12+1<=10){	//right
		if(z==0) z=1;
		else if(z==1) z=2;
		else if(z==2) z=3;
		else z=0;
	}
	else{	//left
		if(z==0) z=3;
		else if(z==1) z=0;
		else if(z==2) z=1;
		else z=2;
	}
}
void car::run(){
	if(z==0){
		y-=1;
	}
	else if(z==1){
		x+=1;
	}
	else if(z==2){
		y+=1;
	}
	else{
		x-=1;
	}
}
void rem(){
	int i;
	car temp;
	for(i=0;i<count;i++){
		if(data[i].x<0||data[i].y<0||data[i].x>300||data[i].y>300){
			data.erase(data.begin()+i);
			count--;
			i-=1;
		}
	}
}
void appear(){
	int i;
	srand( (unsigned)time(NULL) );
	double in=0.03224054;
	car temp;
	double random=((rand()%10000)+1);
	if(random<=322){
		temp.x=75;temp.y=0;temp.z=2;temp.bs1=1,temp.bs2=1,temp.bs3=1,temp.bs4=1;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=150;temp.y=0;temp.z=2;temp.bs1=1,temp.bs2=1,temp.bs3=1,temp.bs4=1;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=225;temp.y=0;temp.z=2;temp.bs1=2,temp.bs2=2,temp.bs3=2,temp.bs4=2;
		data.push_back(temp);
		count++;
	}
////////////////////////////////////////////////////////////////////////////////////////////
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=0;temp.y=75;temp.z=1;temp.bs1=1,temp.bs2=1,temp.bs3=1,temp.bs4=1;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=0;temp.y=150;temp.z=1;temp.bs1=3,temp.bs2=3,temp.bs3=3,temp.bs4=3;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=0;temp.y=225;temp.z=1;temp.bs1=3,temp.bs2=3,temp.bs3=3,temp.bs4=3;
		data.push_back(temp);
		count++;
	}
////////////////////////////////////////////////////////////////////////////////////////////
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=75;temp.y=300;temp.z=0;temp.bs1=3,temp.bs2=3,temp.bs3=3,temp.bs4=3;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=150;temp.y=300;temp.z=0;temp.bs1=4,temp.bs2=4,temp.bs3=4,temp.bs4=4;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=225;temp.y=300;temp.z=0;temp.bs1=4,temp.bs2=4,temp.bs3=4,temp.bs4=4;
		data.push_back(temp);
		count++;
	}
////////////////////////////////////////////////////////////////////////////////////////////
    random=((rand()%10000)+1);
	if(random<=322){
		temp.x=300;temp.y=75;temp.z=3;temp.bs1=2,temp.bs2=2,temp.bs3=2,temp.bs4=2;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=300;temp.y=150;temp.z=3;temp.bs1=2,temp.bs2=2,temp.bs3=2,temp.bs4=2;
		data.push_back(temp);
		count++;
	}
	random=((rand()%10000)+1);
	if(random<=322){
		temp.x=300;temp.y=225;temp.z=3;temp.bs1=4,temp.bs2=4,temp.bs3=4,temp.bs4=4;
		data.push_back(temp);
		count++;
	}
}
void power(){
    double a,b,c;
	for(int i=0;i<count;i++){
        a=data[i].x-75;
        b=data[i].y-75;
        c=100*pow(a,2)+100*pow(b,2);
        if(c>0){
            c=(-60)-20*(log10(sqrt(c)));
            data[i].strength1=c;
        }
        else{
            data[i].strength1=(-50);
        }
        a=data[i].x-225;
        b=data[i].y-75;
        c=100*pow(a,2)+100*pow(b,2);
        if(c>0){
            c=(-60)-20*(log10(sqrt(c)));
            data[i].strength2=c;
        }
        else{
            data[i].strength2=(-50);
        }
        a=data[i].x-75;
        b=data[i].y-225;
        c=100*pow(a,2)+100*pow(b,2);
        if(c>0){
            c=(-60)-20*(log10(sqrt(c)));
            data[i].strength3=c;
        }
        else{
            data[i].strength3=(-50);
        }
        a=data[i].x-225;
        b=data[i].y-225;
        c=100*pow(a,2)+100*pow(b,2);
        if(c>0){
            c=(-60)-20*(log10(sqrt(c)));
            data[i].strength4=c;
        }
        else{
            data[i].strength4=(-50);
        }
        //cout<<data[i].strength1<<" "<<data[i].strength2<<" "<<data[i].strength3<<" "<<data[i].strength4<<endl;
	}
}
void solution1(){
	double a;
	for(int i=0;i<count;i++){
		if(data[i].bs1==1){
			a=data[i].strength1;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs1=2;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs1=3;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs1=4;
			}
			if(data[i].bs1!=1){
				handoff1++;
			}
		}
		else if(data[i].bs1==2){
			a=data[i].strength2;
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs1=1;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs1=3;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs1=4;
			}
			if(data[i].bs1!=2){
				handoff1++;
			}
		}

		else if(data[i].bs1==3){
			a=data[i].strength3;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs1=2;
			}
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs1=1;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs1=4;
			}
			if(data[i].bs1!=3){
				handoff1++;
			}
		}

		else{
			a=data[i].strength4;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs1=2;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs1=3;
			}
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs1=1;
			}
			if(data[i].bs1!=4){
				handoff1++;
			}
		}
	}
}
void solution2(){
	double a;
	for(int i=0;i<count;i++){
		if(data[i].bs2==1&&data[i].strength1<(-110)){
			a=data[i].strength1;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs2=2;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs2=3;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs2=4;
			}
			if(data[i].bs2!=1){
				handoff2++;
			}
		}
		else if(data[i].bs2==2&&data[i].strength2<(-110)){
			a=data[i].strength2;
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs2=1;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs2=3;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs2=4;
			}
			if(data[i].bs2!=2){
				handoff2++;
			}
		}

		else if(data[i].bs2==3&&data[i].strength3<(-110)){
			a=data[i].strength3;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs2=2;
			}
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs2=1;
			}
			if(a<data[i].strength4){
				a=data[i].strength4;
				data[i].bs2=4;
			}
			if(data[i].bs2!=3){
				handoff2++;
			}
		}

		else if(data[i].bs2==4&&data[i].strength4<(-110)){
			a=data[i].strength4;
			if(a<data[i].strength2){
				a=data[i].strength2;
				data[i].bs2=2;
			}
			if(a<data[i].strength3){
				a=data[i].strength3;
				data[i].bs2=3;
			}
			if(a<data[i].strength1){
				a=data[i].strength1;
				data[i].bs2=1;
			}
			if(data[i].bs2!=4){
				handoff2++;
			}
		}
	}
}
void solution3(){
	double a;
	for(int i=0;i<count;i++){
		if(data[i].bs3==1){
			a=data[i].strength1;
			if(a<(data[i].strength2-5)){
				a=data[i].strength2;
				data[i].bs3=2;
			}
			if(a<(data[i].strength3-5)){
				a=data[i].strength3;
				data[i].bs3=3;
			}
			if(a<(data[i].strength4-5)){
				a=data[i].strength4;
				data[i].bs3=4;
			}
			if(data[i].bs3!=1){
				handoff3++;
			}
		}
		else if(data[i].bs3==2){
			a=data[i].strength2;
			if(a<(data[i].strength1-5)){
				a=data[i].strength1;
				data[i].bs3=1;
			}
			if(a<(data[i].strength3-5)){
				a=data[i].strength3;
				data[i].bs3=3;
			}
			if(a<(data[i].strength4-5)){
				a=data[i].strength4;
				data[i].bs3=4;
			}
			if(data[i].bs3!=2){
				handoff3++;
			}
		}
		else if(data[i].bs3==3){
			a=data[i].strength3;
			if(a<(data[i].strength1-5)){
				a=data[i].strength1;
				data[i].bs3=1;
			}
			if(a<(data[i].strength2-5)){
				a=data[i].strength2;
				data[i].bs3=2;
			}
			if(a<(data[i].strength4-5)){
				a=data[i].strength4;
				data[i].bs3=4;
			}
			if(data[i].bs3!=3){
				handoff3++;
			}
		}
		else{
			a=data[i].strength4;
			if(a<(data[i].strength1-5)){
				a=data[i].strength1;
				data[i].bs3=1;
			}
			if(a<(data[i].strength2-5)){
				a=data[i].strength2;
				data[i].bs3=2;
			}
			if(a<(data[i].strength3-5)){
				a=data[i].strength3;
				data[i].bs3=3;
			}
			if(data[i].bs3!=4){
				handoff3++;
			}
		}
	}
}
void solution4(){
	double a;
	for(int i=0;i<count;i++){
		if(data[i].bs4==1){
			if(data[i].strength1<(-125)){
				a=data[i].strength2;
				data[i].bs4=2;
				if(a<data[i].strength3){
					a=data[i].strength3;
					data[i].bs4=3;
				}
				if(a<data[i].strength4){
					data[i].bs4=4;
				}
				handoff4++;
			}
		}
		else if(data[i].bs4==2){
			if(data[i].strength2<(-125)){
				a=data[i].strength1;
				data[i].bs4=1;
				if(a<data[i].strength3){
					a=data[i].strength3;
					data[i].bs4=3;
				}
				if(a<data[i].strength4){
					data[i].bs4=4;
				}
                handoff4++;
			}
		}
		else if(data[i].bs4==3){
			if(data[i].strength3<(-125)){
				a=data[i].strength1;
				data[i].bs4=1;
				if(a<data[i].strength2){
					a=data[i].strength2;
					data[i].bs4=2;
				}
				if(a<data[i].strength4){
					data[i].bs4=4;
				}
                handoff4++;
			}
		}
		else{
			if(data[i].strength4<(-125)){
				a=data[i].strength1;
				data[i].bs4=1;
				if(a<data[i].strength3){
					a=data[i].strength3;
					data[i].bs4=3;
				}
				if(a<data[i].strength2){
					data[i].bs4=2;
				}
                handoff4++;
			}
		}
	}
}
void average_power(){
    if(count!=0){
        for(int i=0;i<count;i++){
            P1+=(data[i].strength1/count);
        }
        for(int i=0;i<count;i++){
            P2+=(data[i].strength2/count);
        }
        for(int i=0;i<count;i++){
            P3+=(data[i].strength3/count);
        }
        for(int i=0;i<count;i++){
            P4+=(data[i].strength4/count);
        }
    }
    else re++;
}
int main(){
	int t=1,i;
	fstream fp;
    fp.open("data.txt", ios::out | ios::app);
    appear();
	for(i=0;i<count;i++){
        if((data[i].runtime%75)==0){
            data[i].direction();
        }
    }
	power();
	for(i=0;i<count;i++){
        cout<<data[i].strength1<<" "<<data[i].strength2<<" "<<data[i].strength3<<" "<<data[i].strength4<<endl;
	}
	while(t<=86400){
		appear();
		for(i=0;i<count;i++){
			data[i].runtime+=1;
			data[i].run();
			if((data[i].runtime%75)==0){
                if(data[i].x==0&&data[i].y==0&&data[i].z==0)  data[i].z=1;
                else if(data[i].x==0&&data[i].y==0&&data[i].z==3)  data[i].z=2;
                else if(data[i].x==300&&data[i].y==0&&data[i].z==1)  data[i].z=2;
                else if(data[i].x==300&&data[i].y==0&&data[i].z==0)  data[i].z=3;
                else if(data[i].x==0&&data[i].y==300&&data[i].z==2)  data[i].z=1;
                else if(data[i].x==0&&data[i].y==300&&data[i].z==3)  data[i].z=0;
                else if(data[i].x==300&&data[i].y==300&&data[i].z==2)  data[i].z=3;
                else if(data[i].x==300&&data[i].y==300&&data[i].z==1)  data[i].z=0;
                else  data[i].direction();
			}
		}
		rem();
		power();
		solution1();
		solution2();
		solution3();
		solution4();
		average_power();
		fp << handoff1 << "," << handoff2 << "," << handoff3 << "," << handoff4 << endl;
		t++;
		//cout<<t<<'\t'<<count<<'\n';
		cout<<count<<" ";
	}
	fp << (P1/(86400-re)) << "," << (P2/(86400-re)) << "," << (P3/(86400-re)) << "," << (P4/(86400-re)) << endl;
	fp.close();
	return 0;
}

