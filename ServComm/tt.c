#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include <iconv.h>
#include <unicode/ucnv.h>
#define PORT 777
#define col 166
#define row 36
FILE* f;
int summ(int x){
int a=x%100000;
   a+=x%10000;
   a+=x%1000;
   a+=x%100;
   //a+=x%10;

   return (x/100000+x/10000%10+x/1000%10+x/100%10+x/10%10)%((x/10)%10);

}
void displ(char* m,int* y,WINDOW* winl){

f=fopen("logs","a");
fputc('\n',f);
fprintf(f,"Ja: ");
	int x=0;
		*y+=1;
for(int i=0;i<strlen(m);i++){
	if((x>(col/2)-20)&&m[i]==' '){
		*y+=1;
	x=0;
	}

	fputc(m[i],f);
	if(x==col/2-1)
	{*y+=1;
	x=0;}
mvwaddch(winl,*y,x,m[i]);
wrefresh(winl);
usleep(20000);
x+=1;}
fclose(f);
}

void dispr(char* m,int* y,WINDOW* winl){
				int x=0;
		*y+=1;
f=fopen("logs","a");
fputc('\n',f);
fprintf(f,"Serv: ");


	if(*y>=36){
	werase(winl);
	*y=0;
	}
for(int i=0;i<strlen(m);i++){

if((x>(col/2)-15)&&m[i]==' '){
	*y+=1;
	x=0;
	}

	putc(m[i],f);
	if(x==col/2-1)
	{*y+=1;
	x=0;}

		
mvwaddch(winl,*y,x,m[i]);
wrefresh(winl);
usleep(20000);
x+=1;}
fclose(f);
}
int main(int argc, char const argv[]) {
f=fopen("logs","w");
fclose(f);
//putc('m',f);
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "123293", *code = "8484848",*name="Oleksii Kondratiuk";
    char buffer[4096] = {0};
    char *ip ="147.175.115.34";
    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

inet_pton(AF_INET, ip,&serv_addr.sin_addr);
    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
//Window

	initscr();
cbreak();	
int x=0,y=0,xr=0,yr=0;
WINDOW* winl=newwin(row,col/2,0,0);
WINDOW* winr=newwin(row,col/2,0,col/2);
start_color();//color
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	wattron(winl,COLOR_PAIR(1));
	wcolor_set(winr,2,NULL);
 // receive message from server
    
  send(sock, "wassup",strlen("wassup"), 0);//server hello
  displ("wassup",&y,winl);

  valread = read(sock, buffer, 4096);
  
  dispr(buffer,&yr,winr);
  //read req send id

 
    // send message to server
  send(sock, hello,strlen(hello), 0);//send id
				  
displ(hello,&y,winl); //printf("%s",hello);
    valread = read(sock, buffer, 4096); 
  dispr(buffer,&yr,winr); // printf("%s\n", buffer);//read need tdsmth
  
   
  send(sock, "ok dude",strlen("ok dude"), 0);
		 displ("ok dude",&y,winl);
  valread = read(sock, buffer, 4096);
    		 dispr(buffer,&yr,winr);//please disconnect ..

  //send(sock, "Oleksii Kondratiuk",strlen("Oleksii KOndratiuk"), 0);
displ("Oleksii Kondratiuk",&y,winl);
		 

		 //code8484848 			  	
  send(sock, code,strlen(code), 0);
 displ(code,&y,winl);
  valread = read(sock, buffer, 4096); 
dispr(buffer,&yr,winr);
 //
 
  send(sock, "753422",strlen("753422"), 0);
  		displ("753422",&y,winl);
 valread = read(sock, buffer, 4096); 
		dispr(buffer,&yr,winr);
		int p=summ(123293);
 char str[10];
	sprintf(str,"%d",p);
 send(sock,str,strlen("8345"), 0);
 		displ(str,&y,winl);
 valread = read(sock, buffer, 4096); 

		dispr(buffer,&yr,winr);
 
 send(sock, "333222333",strlen("333222333"), 0);
 displ("33222333",&y,winl);
 valread = read(sock, buffer, 4096); 

		dispr(buffer,&yr,winr);

  send(sock, "123",strlen("123"), 0);

		displ("123",&y,winl);
 valread = read(sock, buffer, 4096);

		dispr(buffer,&yr,winr);
//Xor55
	for(int i=0;i<150;i++)
	buffer[i]=buffer[i]^55;


  send(sock,buffer,strlen(buffer), 0);
		displ(buffer,&y,winl);
  valread = read(sock, buffer, 4096); 

		dispr(buffer,&yr,winr);
		
 send(sock, "40",strlen("40"), 0);
 		displ("40",&y,winl);
 valread = read(sock, buffer, 4096); 
		
		dispr(buffer,&yr,winr);

 send(sock, "-74",strlen("-74"), 0);
 		displ("-74",&y,winl);
 valread = read(sock, buffer, 4096); 
		
		dispr(buffer,&yr,winr);


 send(sock, "S.O.L.",strlen("S.O.L."), 0);
 		displ("S.O.L.",&y,winl);
//yr=0;
//werase(winr);
	 valread = read(sock, buffer, 4096); 
   
		dispr(buffer,&yr,winr);

 send(sock, "PRIMENUMBER",strlen("PRIMENUMBER"), 0);
 		displ("PRINMENUMBER",&y,winl);
	 valread = read(sock, buffer, 4096); 
  
		dispr(buffer,&yr,winr);
	 //PRIMENUM	
    int bull=0,l=0;
    char m[100];
for(int i=2;i<strlen(buffer);i++){
	for(int j=2;j<=i;j++){
		if(i%j==0)
		{	if(i==j)bull=1;
			break;
		}
	}
    if(bull)
    {m[l]=buffer[i-1];
    l++;
    }
bull=0;
}

//printf("%s",m);
 send(sock, m,strlen(m), 0);
 		displ(m,&y,winl);
 valread = read(sock, buffer, 4096); 

		dispr(buffer,&yr,winr);

 send(sock, "Trinity",strlen("Trinity"), 0);
		displ("Trinity",&y,winl);
 valread = read(sock, buffer, 4096); 

		dispr(buffer,&yr,winr);



setlocale(LC_CTYPE,"en_US.utf8"); 
  
char ut[]="nekonecno";
send(sock,ut,12, 0);

valread = read(sock, buffer, 4096); 
		
			
		displ(ut,&y,winl);
 		dispr(buffer,&yr,winr);
// 
send(sock,"cache",9,0);
		displ("cache",&y,winl);
valread = read(sock, buffer, 4096); 

 		dispr(buffer,&yr,winr);

    return 0;
}
  
