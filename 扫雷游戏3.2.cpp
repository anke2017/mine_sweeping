#include <bits/stdc++.h>
using namespace std;
char map1[1009][1009];//first
char map2[1009][1009];//for user
int map3[1009][1009];//build?
int map4[1009][1009];//did
int x1[8]={-1,0,1,1,1,0,-1,-1},y2[8]={-1,-1,-1,0,1,1,1,0},fnum;
ifstream fin;ofstream fout;
char read(){
	char ans='\0';while((ans<'0'||ans>'9')&&(ans<'a'||ans>'z')&&(ans<'A'||ans>'Z'))ans=getchar();return ans;
}
inline int getn(){
	char a;a=getchar();while(a<'0'||a>'9'){a=getchar();}int n=0;while(a>='0'&&a<='9'){n*=10;n+=(a-48);a=getchar();}return n;
} 
int user_lei(int x,int y){
	int ans=0;
	for(int i=0;i<8;i++)
	{
		if(map2[x+x1[i]][y+y2[i]]=='!')ans++;
	}
	return ans;
}
int user_blank(int x,int y){
	int ans=0;
	for(int i=0;i<8;i++)
	{
		if(map2[x+x1[i]][y+y2[i]]=='.')ans++;
	}
	return ans;
}
bool set_all_lei(int x,int y){
	bool flag=false;
	for(int i=0;i<8;i++)
	{
		if(map2[x+x1[i]][y+y2[i]]=='.')fnum++,map2[x+x1[i]][y+y2[i]]='!',flag=true;
	}
	return flag;
}
bool have_done(int x,int y){
	if(map3[x][y]==1)return true;
	for(int i=0;i<8;i++)
	{
		if(map3[x+x1[i]][y+y2[i]]==1)return true;
	}return false;
}/*
bool reset_lei(int maxn,int maxm){
	int flag=0;
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=maxm;j++)
		{
			if(
			map1[i][j]!='#'
			&&(map1[i][j]-'0')-user_lei(i,j)==user_blank(i,j)
			&&have_done(i,j)
			&&map4[i][j]<=2
			)
			map4[i][j]++,flag=1,set_all_lei(i,j);
		}
	}
	return flag;
}*/
int build(int i,int j,int a1,int b1){
	if(map2[i][j]=='!')fnum--;
	if(map3[i][j]==1)
	{
		if((map1[i][j]-'0')!=user_lei(i,j))return 0;
		for(int p=0;p<8;p++)
			if(
			i+x1[p]>=1
			&&i+x1[p]<=a1
			&&j+y2[p]>=1
			&&j+y2[p]<=b1
			&&map2[i+x1[p]][j+y2[p]]!='!'
			&&map3[i+x1[p]][j+y2[p]]==0
			)
			if(build(i+x1[p],j+y2[p],a1,b1)==1)return 1;
		return 0;
	}
	map3[i][j]=1;
	if(map1[i][j]=='#')
	{cout<<"\b你触发了地雷！！！\n";return 1; }
	if(map1[i][j]=='0')
	{
		map2[i][j]='0';
		for(int p=0;p<8;p++)
		if(
		i+x1[p]>=1
		&&i+x1[p]<=a1
		&&j+y2[p]>=1
		&&j+y2[p]<=b1
		&&!map3[i+x1[p]][j+y2[p]]
		) 
		build(i+x1[p],j+y2[p],a1,b1);
		}
	else map2[i][j]=map1[i][j];
	return 0;
}/*
bool auto_build(int maxn,int maxm){
	int flag=0;
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=maxm;j++)
		{
			if(map1[i][j]-'0'==user_lei(i,j)
			&&have_done(i,j)
			&&map4[i][j]<=2
			)map4[i][j]++,flag=1,build(i,j,maxn,maxm);
		}
	}return flag;
}*/
void printmap(int a1,int b1){
	for(int i=0;i<=a1;i++) {
	printf("%-4d",i);
	if(i==0) {for(int j=1;j<=b1;j++) {cout<<j<<' ';if(j<10)cout<<' ';}cout<<endl;}
	else for(int j=1;j<=b1;j++){cout<<map2[i][j]<<' ';cout<<' ';}
	cout<<endl<<endl;
	}
}
bool win(int a1,int b1){
	for(int i=1;i<=a1;i++) for(int j=1;j<=b1;j++)if(map2[i][j]=='.') return false;
	return true;
}
void build_map(int a1,int b1){
	for(int i=1;i<=a1;i++) 
	for(int j=1;j<=b1;j++) 
	{
		int t1=0;
		if(map1[i][j]!='#') 
		{
			for(int p=0;p<8;p++) 
				if(i+x1[p]>=1&&i+x1[p]<=a1&&j+y2[p]>=1&&j+y2[p]<=b1&&map1[i+x1[p]][j+y2[p]]=='#')t1++;
			map1[i][j]=(char)(t1+'0');
		}
	}
}
void summonmap(int a1,int b1,int c){
	int t=time(0);
	fout<<t<<endl;
	fout<<a1<<' '<<b1<<' '<<c<<endl;
	srand(t);
	int x,y;
	int z=0;
	while(z<c)
	{
		x=rand()%a1+1;
		y=rand()%b1+1;
		if(map1[x][y]=='\0'){map1[x][y]='#';z++;}
	}
	build_map(a1,b1);
}
void summonmap(int a1,int b1,int c,int seed){
	int x,y;
	int z=0;
	srand(seed);
	fout<<seed<<endl;
	while(z<c)
	{
		x=rand()%a1+1;
		y=rand()%b1+1;
		if(map1[x][y]=='\0'){map1[x][y]='#';z++;}
	}
	build_map(a1,b1);
}
void first_b_caozuo(int a1,int b1,int x,int y){
	if(map1[x][y]!='#')return;
	map1[x][y]='.';
	while(1)
	{
		int tmp1=rand()%a1+1;
		int tmp2=rand()%b1+1;
		if(map1[tmp1][tmp2]!='#'&&!(tmp1==x||tmp2==y)){map1[tmp1][tmp2]='#';/*cout<<tmp1<<" "<<tmp2<<'\n';*/break;}
	}
	build_map(a1,b1);
}
void sl(){
	int openf;
	cout<<"请输入要存档的文件编号（请注意这将把原文件的内容删除，编号从1~30），0为不存档\n";
	openf=getn();if(openf==1)fout.open("Lucy=2b1.txt");if(openf==2)fout.open("Lucy=2b2.txt");if(openf==3)fout.open("Lucy=2b3.txt");if(openf==4)fout.open("Lucy=2b4.txt");if(openf==5)fout.open("Lucy=2b5.txt");if(openf==6)fout.open("Lucy=2b6.txt");if(openf==7)fout.open("Lucy=2b7.txt");if(openf==8)fout.open("Lucy=2b8.txt");if(openf==9)fout.open("Lucy=2b9.txt");if(openf==10)fout.open("Lucy=2b10.txt");if(openf==11)fout.open("Lucy=2b11.txt");if(openf==12)fout.open("Lucy=2b12.txt");if(openf==13)fout.open("Lucy=2b13.txt");if(openf==14)fout.open("Lucy=2b14.txt");if(openf==15)fout.open("Lucy=2b15.txt");if(openf==16)fout.open("Lucy=2b16.txt");if(openf==17)fout.open("Lucy=2b17.txt");if(openf==18)fout.open("Lucy=2b18.txt");if(openf==19)fout.open("Lucy=2b19.txt");if(openf==20)fout.open("Lucy=2b20.txt");if(openf==21)fout.open("Lucy=2b21.txt");if(openf==22)fout.open("Lucy=2b22.txt");if(openf==23)fout.open("Lucy=2b23.txt");if(openf==24)fout.open("Lucy=2b24.txt");if(openf==25)fout.open("Lucy=2b25.txt");if(openf==26)fout.open("Lucy=2b26.txt");if(openf==27)fout.open("Lucy=2b27.txt");if(openf==28)fout.open("Lucy=2b28.txt");if(openf==29)fout.open("Lucy=2b29.txt");if(openf==30)fout.open("Lucy=2b30.txt");
	char x;
	int flag=1;
	cout<<"\b扫雷游戏，请输入难度（E简单，N中等，H困难，I自定义，L读档）（规则：b 数字 数字：挖开（数字，数字）；f 数字 数字：标记（数字，数字））\n";
	x=read();
	int n,m,q;
	int first_b=1;
	for(int i=0;i<=1001;i++) for(int j=0;j<=1001;j++) map1[i][j]='\0',map2[i][j]='.';
	for(int i=0;i<=1001;i++) for(int j=0;j<=1001;j++) map3[i][j]=0;
	if(x=='E') n=5,m=5,q=4;
	else if(x=='N')n=10,m=10,q=20;
	else if(x=='H') n=20,m=20,q=100;
	else if(x=='L')
	{
		int flag114=1;
		while(flag114)
		{
			flag114=0;
			cout<<"请输入要读取的存档编号（1~30）\n";
			openf=getn();
			if(openf==1)fin.open("Lucy=2b1.txt");else if(openf==2)fin.open("Lucy=2b2.txt");else if(openf==3)fin.open("Lucy=2b3.txt");else if(openf==4)fin.open("Lucy=2b4.txt");else if(openf==5)fin.open("Lucy=2b5.txt");else if(openf==6)fin.open("Lucy=2b6.txt");else if(openf==7)fin.open("Lucy=2b7.txt");else if(openf==8)fin.open("Lucy=2b8.txt");else if(openf==9)fin.open("Lucy=2b9.txt");else if(openf==10)fin.open("Lucy=2b10.txt");else if(openf==11)fin.open("Lucy=2b11.txt");else if(openf==12)fin.open("Lucy=2b12.txt");else if(openf==13)fin.open("Lucy=2b13.txt");else if(openf==14)fin.open("Lucy=2b14.txt");else if(openf==15)fin.open("Lucy=2b15.txt");else if(openf==16)fin.open("Lucy=2b16.txt");else if(openf==17)fin.open("Lucy=2b17.txt");else if(openf==18)fin.open("Lucy=2b18.txt");else if(openf==19)fin.open("Lucy=2b19.txt");else if(openf==20)fin.open("Lucy=2b20.txt");else if(openf==21)fin.open("Lucy=2b21.txt");else if(openf==22)fin.open("Lucy=2b22.txt");else if(openf==23)fin.open("Lucy=2b23.txt");else if(openf==24)fin.open("Lucy=2b24.txt");else if(openf==25)fin.open("Lucy=2b25.txt");else if(openf==26)fin.open("Lucy=2b26.txt");else if(openf==27)fin.open("Lucy=2b27.txt");else if(openf==28)fin.open("Lucy=2b28.txt");else if(openf==29)fin.open("Lucy=2b29.txt");else if(openf==30)fin.open("Lucy=2b30.txt");
			else flag114=1;
		}
		cout<<"\b读档中\n";
		int t;
		fin>>t;
		fin>>n>>m>>q;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) map2[i][j]='.';
		int i=1;
		do{
			if(n*m>=q&&n<=1000&&m<=1000)break;
			else {
				cout<<"\b数据不合法\n\n";
				cout<<"\b继续游玩吗？是请按Y,不是按N\n\n";
				return;
			}
		}while(i);
		summonmap(n,m,q,t);
		fout<<n<<' '<<m<<' '<<q<<endl;
		flag=0;
		char t1;
		int t2,t3;
		while(fin>>t1>>t2>>t3)
		{
			if(t1=='#')break;
			fout<<t1<<' '<<t2<<' '<<t3<<endl;
			if(t1=='f'&&t2<=n&&t2>=1&&t3<=m&&t3>=1&&map3[t2][t3]==0)
			{
				fnum++;
				map2[t2][t3]='!';
			}
			else if(t1=='f'&&t2<=n&&t2>=1&&t3<=m&&t3>=1)
			{
				set_all_lei(t2,t3);
			}
			else if(t1=='b'&&t2<=n&&t2>=1&&t3<=m&&t3>=1){
				if(first_b)
				{
					first_b=0;
					first_b_caozuo(n,m,t2,t3);
				}
				if(build(t2,t3,n,m))
				{
					cout<<"\b继续游玩吗？是请按Y,不是按N\n";return;
				}
			}
			else {
				cout<<"\b命令不合法\n\n";
				cout<<"\b继续游玩吗？是请按Y,不是按N\n\n";
				return;
			}
			//while(reset_lei(n,m)||auto_build(n,m))printmap(n,m);
			//for(int i=1;i<=50;i++)cout<<"-------------------------------------------------------\n";
		}
		cout<<"\b读档完成！\n";
	}
	else{
	cout<<"\b请输入行数，列数和雷数（行，列不超过1000，雷少于行数*列数）\n";
	int i=1;
		do{
			n=getn(),m=getn(),q=getn();
			if(n*m>q&&n<=1000&&m<=1000)break;
			else {
				cout<<"\b数据不合法，请重新输入\n\n";
			}
		}while(i);
	}
	if(flag)summonmap(n,m,q);
	if(flag)fnum=0;
	if(flag)for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) map2[i][j]='.';
	while(!win(n,m)||!(fnum==q))
	{
		printmap(n,m);
		int t2,t3;
		char t1;
		t1=read(),t2=getn(),t3=getn();
		fout<<t1<<' '<<t2<<' '<<t3<<endl;
		if(t1=='f'&&t2<=n&&t2>=1&&t3<=m&&t3>=1&&map3[t2][t3]==0)
		{
			fnum++;
			map2[t2][t3]='!';
			cout<<"\b还有"<<q-fnum<<0<<"\b个雷，加油！\n";
		}
		else if(t1=='f'&&t2<=n&&t2>=1&&t3<=m&&t3>=1)
		{
			set_all_lei(t2,t3);
			cout<<"\b还有"<<q-fnum<<0<<"\b个雷，加油！\n";
		}
		else if(t1=='b'&&t2<=n&&t2>=1&&t3<=m&&t3>=1)
		{
			if(first_b)
			{
				first_b_caozuo(n,m,t2,t3);
				first_b=0;
			}
			if(build(t2,t3,n,m))
			{
				cout<<"\b继续游玩吗？是请按Y,不是按N\n";
				fout<<'#'<<endl;
				return;
			}
		}
		else if(t1=='D')cout<<map4[t2][t3]<<'\n'<<have_done(t2,t3)<<'\n';
		else {
			cout<<"\b命令不合法\n\n";
		}
		//while(reset_lei(n,m)||auto_build(n,m))printmap(n,m);
	}
	fout<<'#'<<endl;
	cout<<"\b恭喜你，胜利了！"<<endl;
	cout<<"\b继续游玩吗？是请按Y,不是按N\n\n";
}
int main(){char tmp;do{sl();fin.close();fout.close();}while(cin>>tmp&&tmp=='Y');return 0;}
//the length of this code  
//is: 
//9824
