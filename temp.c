#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "datatype.h"
#include "linkedlist.h"
mp Mhead;
dp Dhead;
ap Ahead;
ap2 ahead;
tp thead1;
tp thead2;
char *Menu;
int numS;

void search(char *U,FILE *fp,FILE *fp2,FILE *fp3){
    int i=0;
	char *option = malloc(sizeof(char)*5);
	option = NULL;
	option = strtok(U," ");
	FILE **fpa = malloc(sizeof(FILE *)*3);
	if(!strcmp(option,"-m")) fpa[0] = fp;
	else if(!strcmp(option,"-d")) {fpa[0] = fp2; 
	option = strtok(NULL,"\0");}
	else if(!strcmp(option,"-a")) {fpa[0] = fp3; 
	option = strtok(NULL,"\0");}
	else if((!strcmp(option,"-md"))||(!strcmp(option,"-dm"))) {fpa[0] = fp;fpa[1]=fp2;
	option = strtok(NULL,"\0");}
	else if((!strcmp(option,"-ma"))||(!strcmp(option,"-am"))) {fpa[0] = fp; fpa[1]=fp3;
	option = strtok(NULL,"\0");}
	else if((!strcmp(option,"-da"))||(!strcmp(option,"-ad"))) {fpa[0] = fp2;fpa[1]=fp3;
	option = strtok(NULL,"\0");}
     else { fpa[0] = fp; fpa[1] = fp2; fpa[2]=fp3;}      
 
	fseek(fp,0,SEEK_SET);
	fseek(fp2,0,SEEK_SET);
	fseek(fp3,0,SEEK_SET);
	char *st = malloc(sizeof(char)*100);
    while(*fpa != NULL){
	while(fgets(st,100,*fpa)!=NULL){
		if(strstr(st,option)){i++; printf("%s\n",st);}
	
	}
   fpa = fpa+1;
	}
if(!i) printf("There is no '%s' in file\n",option);

	return ;
}

void print(char *U){
	int i,num;
	char *name = malloc(sizeof(void)*10);
	void **list = malloc(sizeof(void *)*4);
    list[0] = Mhead;
	list[1] = Dhead;
	list[2] = Ahead;

	char *option = malloc(sizeof(char)*5);
	option = strtok(U," ");
	if(!strcmp(option,"m")) {i=0; name = "M";}
	else if(!strcmp(option,"d")) {	i=1; name = "D"; }
	else if(!strcmp(option,"a")) {i=2; name = "A";}
	num = atoi(strtok(NULL," "));
    void *p = gotoNode(num,list[i],name);
	
	if(i==0){
        mp m = p;
	printf("%d %s %s %d %d\n",m->num,m->title,m->genre,m->year,m->time);

	
	if(m->director->directorP == NULL) printf("%s\n",m->director->director);
	else printf("%s(%s)\n",m->director->director,m->director->directorP->birth);
    
	while(m->actor->next != NULL){
	if(m->actor->next->actorP == NULL) printf("%s\n",m->actor->next->actor);
	else printf("%s(%s)\n",m->actor->next->actor,m->actor->next->actorP->birth);
    m->actor = m->actor->next;
	}
}
    else if(i==1){
		dp m = p;
	printf("%d / %s / %c / %s\n",m->num,m->director,m->sex,m->birth);
	
	while(m->title->next != NULL){
	if(m->title->next->movieP == NULL) printf("%s\n",m->title->next->title);
	else printf("%s(%d,%dmin)\n",m->title->next->title,m->title->next->movieP->year,m->title->next->movieP->time);
	m->title = m->title->next;
	}	
	}
    else if(i==2){
		ap m = p;
	printf("%d / %s / %c / %s\n",m->num,m->actor,m->sex,m->birth);
	
	while(m->title->next != NULL){
	if(m->title->next->movieP == NULL) printf("%s\n",m->title->next->title);
	else printf("%s(%d,%dmin)\n",m->title->next->title,m->title->next->movieP->year,m->title->next->movieP->time);
	m->title = m->title->next;
	}
	}

}
void add(char *U){
	char *option = strtok(U," ");
	if(!strcmp(option,"m")) {
        mp cur= malloc(sizeof(movie));
        cur->title = malloc(sizeof(char)*30);
        cur->genre = malloc(sizeof(char)*30);
		cur->director = malloc(sizeof(directorlist));
        cur->director->director = malloc(sizeof(char)*30);
	    ap2 temp = malloc(sizeof(actors));
		ap2 ahead = temp;
		
		cur->num = 13;
		printf("TITLE > ");
		scanf("%s",cur->title);
		printf("GENRE > ");
		scanf("%s",cur->genre);
	    printf("DIRECTOR > ");
        scanf("%s",cur->director->director);
        cur->director->directorP= NULL;    	
        printf("YEAR > ");
		scanf("%d",&(cur->year));
		printf("TIME > ");
		scanf("%d",&(cur->time));
         	getchar();
		while(1){
			printf("ACTORS >");
			temp ->next = malloc(sizeof(actors));
			temp->next->actor = malloc(sizeof(char)*30);
			scanf("%[^\n]s",temp -> next->actor);
	        getchar();
			temp -> next -> actorP = NULL;
			temp -> next ->next = NULL;
		   if(!strcmp(temp->next->actor,"end")) {temp->next=NULL;break;}
		  temp = temp->next;
		} 
		
		cur->actor = ahead; 
		cur->next = NULL;
		addNode(&Mhead,cur);

	}

}

void delete(char *U){
	char *option = strtok(U," ");
	int num = atoi(strtok(NULL," "));
	if(!strcmp(option,"m")) {
		mp cur = gotoNode(num,Mhead,"M");
		if(cur == NULL) printf("No such record\n");
		else deleteNode(Mhead,num,"M");
	}
	else if(!strcmp(option,"d")) {
		dp cur = gotoNode(num,Dhead,"D");
		if(cur == NULL) printf("No such record\n");
		else deleteNode(Dhead,num,"D");
	}
	if(!strcmp(option,"a")) {
	    ap cur = gotoNode(num,Ahead,"A");
		if(cur == NULL) printf("No such record\n");
		else deleteNode(Ahead,num,"A");
	}

}
void update(char *U){
	char *option = strtok(U," ");
	if(!strcmp(option,"m")){

void end(){
// 파일 저장 및 업데이트 관련 내용 작성 !! 

}
char *menu(){
    printf("(movie)");
	char *U = malloc(sizeof(char)*50);
	scanf("%[^\n]s",U);
	getchar();
	return U;
}


int main(){
	FILE *fp,*fp2,*fp3;
	fp = fopen("movielog.txt","r");
	fp2 = fopen("directorlog.txt","r");
	fp3 = fopen("actorlog.txt","r");
	/* 정보 링크드 리스트 생성 */

	init_list(&Mhead);
	movie_info(&Mhead,fp,fp2);

	init_list2(&Dhead);
	director_info(&Dhead,fp2);
	
	init_list3(&Ahead);
	actor_info(&Ahead,fp3);
	
     
	/* 메뉴 프롬프트 */
    int i;
	char *Menu = malloc(sizeof(char)*50);
	char *Menu2 = malloc(sizeof(char)*50);
	char *Menu3 = malloc(sizeof(char)*50);
	printf("<input :search/print/add/update/delete/sort/save/end>\n");
	while(1){
		
	linkdirector(&Mhead,&Dhead);
	linktitle(&Mhead,Dhead,"Dhead");
	linktitle(&Mhead,Ahead,"Ahead");
	linkactor(&Mhead,&Ahead);
		Menu = menu();
		Menu2 = strtok(Menu," ");
        Menu3 = strtok(NULL,"\0");
		if(!strcmp(Menu2,"search"))search(Menu3,fp,fp2,fp3);
		else if(!strcmp(Menu,"print")) print(Menu3);
		else if(!strcmp(Menu,"add")) add(Menu3);
		else if(!strcmp(Menu,"update")); 
		else if(!strcmp(Menu,"delete")) delete(Menu3);
		else if(!strcmp(Menu,"sort")) ;
		else if(!strcmp(Menu,"save")) ;
		else if(!strcmp(Menu,"end")){end(); break; }
		else printf(" 메뉴명을 다시 입력하세요 \n");
	}

	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	return 0;
}




