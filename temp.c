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
	void search(char *U){
		FILE *f = fopen("movielist.txt","r");
		FILE *f2 = fopen("directorlist.txt","r");
		FILE *f3 = fopen("actorlist.txt","r");
		int i=0;
		int check = 0;
		int meta;
		char *option = malloc(sizeof(char)*5);
		option = NULL;
		option = strtok(U," ");
		FILE **fpa = malloc(sizeof(FILE *)*3);
		if(!strcmp(option,"-m")){ fpa[0] = f;}
		else if(!strcmp(option,"-d")) {fpa[0] = f2; }
		else if(!strcmp(option,"-a")) {fpa[0] = f3; }
		else if((!strcmp(option,"-md"))||(!strcmp(option,"-dm"))) {fpa[0] = f;fpa[1]=f2;}
		else if((!strcmp(option,"-ma"))||(!strcmp(option,"-am"))) {fpa[0] = f; fpa[1]=f3;}
		else if((!strcmp(option,"-da"))||(!strcmp(option,"-ad"))) {fpa[0] = f2;fpa[1]=f3;}
		 else { check = 1;fpa[0] = f; fpa[1] = f2; fpa[2]=f3;}      
	 
		fseek(f,0,SEEK_SET);
		fseek(f2,0,SEEK_SET);
		fseek(f3,0,SEEK_SET);
		char *st = malloc(sizeof(char)*100);
		char *st1 = malloc(sizeof(char)*100);
		if(check) st1 = option;
		else st1 = strtok(NULL,"\0");
		meta = strlen(st1)-1;
		if(st1[meta]=='*') st1 = strtok(st1,"*"); 
		while(*fpa != NULL){
		while(fgets(st,100,*fpa)!=NULL){
			if(strstr(st,st1)){i++; printf("%s\n",st);}
		
		}
	   fpa = fpa+1;
		}
	if(!i) printf("There is no %s  in file\n",st1);
    fclose(f);
	fclose(f2);
	fclose(f3);
		return ;
	}

	void print(char *U){
	printf("%s\n",U);
		printf("\n");
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
           if(!m) {printf("No serialNo.%d's info in the directory\n",num); return;}
			actors *a = m->actor;
		printf("%d / %s / %s / %d / %d\n",m->num,m->title,m->genre,m->year,m->time);

		
		if(m->director->directorP == NULL) printf("%s\n",m->director->director);
		else printf("%s(%s)\n",m->director->director,m->director->directorP->birth);
		
		while(a->next != NULL){
		if(a->next->actorP == NULL) printf("%s\n",a->next->actor);
		else printf("%s(%s)\n",a->next->actor,a->next->actorP->birth);
		a = a->next;
		}
	}
		else if(i==1){
			dp m = p;
           if(!m) {printf("No serialNo.%d's info in the directory\n",num); return;}
			titles *a = m -> title;
		printf("%d / %s / %c / %s\n",m->num,m->director,m->sex,m->birth);
		
		while(a->next != NULL){
		if(a->next->movieP == NULL) printf("%s\n",a->next->title);
		else printf("%s(%d,%dmin)\n",a->next->title,a->next->movieP->year,a->next->movieP->time);
		a = a->next;
		}	
		}
		else if(i==2){
			ap m = p;
           if(!m) {printf("No serialNo.%d's info in the directory\n",num); return;}
			titles *a = m -> title;
		printf("%d / %s / %c / %s\n",m->num,m->actor,m->sex,m->birth);
		
		while(a->next != NULL){
		if(a->next->movieP == NULL) printf("%s\n",a->next->title);
		else printf("%s(%d,%dmin)\n",a->next->title,a->next->movieP->year,a->next->movieP->time);
		a = a->next;
		}
		}
		else {printf("No option '%s'. Try again.\n",option); return ;}

	}
	void add(char *U){
		char *option = strtok(U," ");
		if(!strcmp(option,"m")) {
		FILE *f = fopen("movielog.txt","a");
		FILE *f2 = fopen("movielist.txt","a");	
		    mp cur= malloc(sizeof(movie));
			cur->title = malloc(sizeof(char)*30);
			cur->genre = malloc(sizeof(char)*30);
			cur->director = malloc(sizeof(directorlist));
			cur->director->director = malloc(sizeof(char)*30);
			ap2 temp = malloc(sizeof(actors));
			ap2 ahead = temp;
			char *str = malloc(sizeof(char)*110);
			char *str2 = malloc(sizeof(char)*110);
			
			cur->num = (curNum1)++;
			printf("TITLE > ");
			scanf("%[^\n]s",cur->title);
			getchar();
			printf("GENRE > ");
			scanf("%s",cur->genre);
			printf("DIRECTOR > ");
			getchar();
			scanf("%[^\n]s",cur->director->director);
			getchar();
			cur->director->directorP= NULL;    	
			printf("YEAR > ");
			scanf("%d",&(cur->year));
			printf("TIME > ");
			scanf("%d",&(cur->time));
				getchar();
			sprintf(str,"add:%d:%s:%s:%s:%d:%d:",cur->num,cur->title,cur->genre,cur->director->director,cur->year,cur->time);
				fputs(str,f);
			sprintf(str2,"%d:%s:%s:%s:%d:%d:",cur->num,cur->title,cur->genre,cur->director->director,cur->year,cur->time);
				fputs(str2,f2);
		int i=0;
			while(1){
				printf("ACTORS >");
				temp ->next = malloc(sizeof(actors));
				temp->next->actor = malloc(sizeof(char)*30);
				scanf("%[^\n]s",temp -> next->actor);
				printf("%s\n",temp->next->actor);
				getchar();
				temp -> next -> actorP = NULL;
				temp -> next ->next = NULL;
			   if(!strcmp(temp->next->actor,"end")) {
				   fputc('\n',f);
				   fputc('\n',f2);
				   temp->next=NULL;break;}
			  if(i++) fputs(",",f);
			  fputs(temp->next->actor,f2);
			   temp = temp->next;
			} 
			
			cur->actor = ahead; 
			cur->next = NULL;
			addNode(&Mhead,cur);
	fclose(f);
	fclose(f2);
		}
		else if(!strcmp(option,"d")) {
		FILE *f = fopen("directorlog.txt","a");
		FILE *f2 = fopen("directorlist.txt","a");
			dp cur= malloc(sizeof(director));
			cur->director = malloc(sizeof(char)*30);
			cur->birth = malloc(sizeof(char)*30);
			tp temp = malloc(sizeof(titles));
			tp ahead = temp;
			cur->num = curNum2++;
			char *str = malloc(sizeof(char)*100);
			char *str2 = malloc(sizeof(char)*100);
				int i=0;
		
			printf("Director > ");
			scanf("%[^\n]s",cur->director);
				getchar();
			printf("Sex > ");
			scanf(" %c",&cur->sex);
			printf("Birth > ");
			scanf("%s",cur->birth);
				getchar();
		
			sprintf(str,"add:%d:%s:%c:%s:",cur->num,cur->director,cur->sex,cur->birth);
				fputs(str,f);
			sprintf(str2,"%d:%s:%c:%s:",cur->num,cur->director,cur->sex,cur->birth);
				fputs(str2,f2);
			while(1){
				printf("Titles >");
				temp ->next = malloc(sizeof(titles));
				temp->next->title = malloc(sizeof(char)*30);
				scanf("%[^\n]s",temp -> next->title);
				getchar();
				temp -> next -> movieP = NULL;
				temp -> next ->next = NULL;
			   if(!strcmp(temp->next->title,"end")) {
				   fputc('\n',f);
				   temp->next=NULL;break;}
				if(i++) fputs(",",f);
			   fputs(temp->next->title,f2);
			  temp = temp->next;
			} 
			
			cur->title = ahead; 
			cur->next = NULL;
			addNode2(&Dhead,cur);
	fclose(f);
	fclose(f2);
	}

		else if(!strcmp(option,"a")) {
		FILE *f = fopen("actorlog.txt","a");
		FILE *f2 = fopen("actorlist.txt","a");
			ap cur= malloc(sizeof(actor));
			cur->actor = malloc(sizeof(char)*30);
			cur->birth = malloc(sizeof(char)*30);
			tp temp = malloc(sizeof(titles));
			tp thead = temp;
			cur->num = curNum2++;
			char *str = malloc(sizeof(char)*100);
			char *str2 = malloc(sizeof(char)*100);
				int i=0;
		
			printf("Actor > ");
			scanf("%[^\n]s",cur->actor);
				getchar();
			printf("Sex > ");
			scanf(" %c",&cur->sex);
			printf("Birth > ");
			scanf("%s",cur->birth);
				getchar();
		
			sprintf(str,"add:%d:%s:%c:%s:",cur->num,cur->actor,cur->sex,cur->birth);
				fputs(str,f);
			sprintf(str2,"%d:%s:%c:%s:",cur->num,cur->actor,cur->sex,cur->birth);
				fputs(str2,f2);
			while(1){
				printf("Titles >");
				temp ->next = malloc(sizeof(titles));
				temp->next->title = malloc(sizeof(char)*30);
				scanf("%[^\n]s",temp -> next->title);
				getchar();
				temp -> next -> movieP = NULL;
				temp -> next ->next = NULL;
			   if(!strcmp(temp->next->title,"end")) {
				   fputc('\n',f);
				   temp->next=NULL;break;}
				if(i++) fputs(",",f);
			   fputs(temp->next->title,f2);
			  temp = temp->next;
			} 
			
			cur->title = thead; 
			cur->next = NULL;
			addNode3(&Ahead,cur);
	fclose(f);
	fclose(f2);
	}
}

void delete(char *U){
	char *option = strtok(U," ");
	int num = atoi(strtok(NULL," "));
	char *str = malloc(sizeof(char)*40);
	if(!strcmp(option,"m")) {
		mp cur = gotoNode(num,Mhead,"M");
           if(cur==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		else {
		FILE *f = fopen("movielog.txt","a");
	sprintf(str,"delete:%d:%s:%s:%s:%d:%d:",cur->num,cur->title,cur->genre,cur->director->director,cur->year,cur->time);
       fputs(str,f);
		int i=0;
		ap2 temp = cur->actor;
				while(temp->next!=NULL)
				{
					fputs(temp->next->actor,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
				}
	   fclose(f);
			deleteNode(Mhead,num,"M");
			mkList(Mhead);
		}
	}
	
	else if(!strcmp(option,"d")) {
		dp cur = gotoNode(num,Dhead,"D");
           if(cur==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		else{
		FILE *f = fopen("directorlog","a");
	sprintf(str,"delete:%d:%s:%c:%s:",cur->num,cur->director,cur->sex,cur->birth);
       fputs(str,f);
		int i=0;
		tp temp = cur->title;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}
	   fclose(f);
		 deleteNode(Dhead,num,"D");
			mkList2(Dhead);
	}
	}
	else if(!strcmp(option,"a")) {
	    ap cur = gotoNode(num,Ahead,"A");
           if(cur==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		else{
	FILE *f = fopen("actorlog","a");
	sprintf(str,"delete:%d:%s:%c:%s:",cur->num,cur->actor,cur->sex,cur->birth);
       fputs(str,f);
		tp temp = cur->title;
		int i = 0;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}

	   fclose(f);
		 deleteNode(Ahead,num,"A");
			mkList3(Ahead);
	}
	}
	else { printf("No option '%s'. Try again.\n\n",option); return;}

}

int Put(char c,void *nodes,char *s){
	if(!strcmp(s,"M")){ 
		mp node = nodes;
		actors *a = node->actor;
		char *str = malloc(sizeof(char)*100);	
			if(c=='t'){
		printf("Title :");
		scanf("%[^\n]s",str);
		node->title = str;

     	}
		else if(c=='g'){
		printf("Genre :");
		scanf("%[^\n]s",node->genre);
		}
		else if(c=='y'){
		printf("Year :");
		scanf("%d",&(node->year));
		}
		else if(c=='r'){
		printf("Time :");
		scanf("%d",&node->time);
		}
		else if(c=='d'){
		printf("Director :");
		scanf("%[^\n]s",node->director->director);
		}
		else if(c=='a'){
		while(1){
		printf("Actor :");
		scanf("%[^\n]s",a->next->actor);
		if(!strcmp(a->next->actor,"end")) { a->next = NULL;break;}
		getchar();
		if(a ->next->next == NULL){ a->next->next = malloc(sizeof(actors));
			a->next->next->actor = malloc(sizeof(char)*30);
				a->next->next->actorP = NULL;}
		a = a->next ; 
		
		}
			}
			else {printf("No option '%c'. Try again. \n",c);return 0;}		
	}
	else if(!strcmp(s,"D")) {
		dp node = nodes;	
		titles *a = node->title;
		if(c=='n'){
		printf("Director :");
		scanf("%[^\n]s",node->director);
		}
		else if(c=='s'){
		printf("Sex :");
		scanf("%c",&node->sex);
		}
		else if(c=='b'){
		printf("Birth :");
		scanf("%s",node->birth);
		}
		else if(c=='m'){
		while(1){
		printf("Movie :");
		scanf("%[^\n]s",a->next->title);
		if(!strcmp(a->next->title,"end")) {; a->next= NULL; break;}
		getchar();
		if(a ->next->next == NULL){ a->next->next = malloc(sizeof(titles));
			a->next->next->title = malloc(sizeof(char)*30);
				a->next->next->movieP = NULL;}
		a = a->next ; 
		}
		}
			else {printf("No option '%c'. Try again. \n",c);return 0;}		
	 }
	else if(!strcmp(s,"A")){
		ap node = nodes;
		titles *a = node->title;
		if(c=='n'){
		printf("Actor :");
		scanf("%[^\n]s",node->actor);
		}
		else if(c=='s'){
		printf("Sex :");
		scanf("%c",&node->sex);
		}
		else if(c=='b'){
		printf("Birth :");
		scanf("%s",node->birth);
		}
		else if(c=='m'){
		while(1){
		printf("Movie :");
		scanf("%[^\n]s",a->next->title);
		if(!strcmp(a->next->title,"end")){ a->next= NULL; break;}
		getchar();
		if(a ->next->next == NULL){ a->next->next = malloc(sizeof(titles));
			a->next->next->title = malloc(sizeof(char)*30);
				a->next->next->movieP = NULL;}
		a = a->next ; 
		}	
		}
			else {printf("No option '%c'. Try again. \n",c);return 0;}		
		}
return 1;
}
void update(char *U){
	char *option = strtok(U," ");
	char *str = malloc(sizeof(char)*100); 
	str = strtok(NULL," ");
	int num = atoi(strtok(NULL," "));
	if(!strcmp(option,"m")){
	mp node ;
		node= gotoNode(num,Mhead,"M");
           if(node==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		for(int i=0;i<strlen(str);i++)
		{	if(Put(str[i],node,"M"))
			{ if(i!=strlen(str)-1) getchar();
			}
				else{printf("comecome\n"); return;}
		}
		FILE *f = fopen("movielog.txt","a");
	sprintf(str,"update:%d:%s:%s:%s:%d:%d:",node->num,node->title,node->genre,node->director->director,node->year,node->time);
       fputs(str,f);
		int i=0;
		ap2 temp = node->actor;
				while(temp->next!=NULL)
				{
					fputs(temp->next->actor,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
				}
	   fclose(f);
	   mkList(Mhead);
		}
	if(!strcmp(option,"d")){
	dp node ;
		node= gotoNode(num,Dhead,"D");
           if(node==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		for(int i=0;i<strlen(str);i++)
		{	if(Put(str[i],node,"D"))
			{  if(i!=strlen(str)-1) getchar();
			}
				else return;
		}
		FILE *f = fopen("directorlog.txt","a");
	sprintf(str,"update:%d:%s:%c:%s:",node->num,node->director,node->sex,node->birth);
       fputs(str,f);
		int i=0;
		tp temp = node->title;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}
				fclose(f);
				mkList2(Dhead);
		}
	if(!strcmp(option,"a")){
	ap node ;
		node= gotoNode(num,Ahead,"A");
           if(node==NULL) {printf("No serialNo.%d's info in the directory\n",num);return;}		
		for(int i=0;i<strlen(str);i++)
		{	if(Put(str[i],node,"A"))
			{ if(i!=strlen(str)-1) getchar();
		   
			}else return;
		}

	FILE *f = fopen("actorlog.txt","a");
	sprintf(str,"update:%d:%s:%c:%s:",node->num,node->actor,node->sex,node->birth);
		printf("%s\n",node->actor);
       fputs(str,f);
		tp temp = node->title;
		int i = 0;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
				}
				fclose(f);
				mkList3(Ahead);
		}
	return ;
}

void save(char *U){
	char *str = strtok(U," ");
	char *option = malloc(sizeof(char)*10);
	option = strtok(NULL," ");
	char *file =  malloc(sizeof(char)*30);
    if(!strcmp(option,"-f")){
	option = NULL;
	file = strtok(NULL," ");
	}
	else {
		if(strtok(NULL," ")) file = strtok(NULL," ");
	else file = NULL;
	}
	if(!strcmp(str,"m")) saveNode(Mhead,"M",option,file);
	else if(!strcmp(str,"d")) saveNode(Dhead,"D",option,file);
	else if(!strcmp(str,"a")) saveNode(Ahead,"A",option,file);
	else printf("No option '%s'. Try again.\n",str);
}
void sort(char *U){
	char *str = strtok(U," ");
	char *option = malloc(sizeof(char)*10);
	option = strtok(NULL," ");
	char *file =  malloc(sizeof(char)*30);
    if(!strcmp(option,"-f")){
	option = NULL;
	file = strtok(NULL," ");
	}
	else {
		if(strtok(NULL," ")) file = strtok(NULL," ");
	else file = NULL;
	}
	printf("%s\n",option);
	if(!strcmp(str,"m")) sortNode(Mhead,"M",option,file);
	else if(!strcmp(str,"d")) sortNode(Dhead,"D",option,file);
	else if(!strcmp(str,"a")) sortNode(Ahead,"A",option,file);
    }
void end(){

	printf("종료합니다\n");
}
char *menu(){
    printf("(movie)");
	char *U = malloc(sizeof(char)*50);
	scanf("%[^\n]s",U);
	getchar();
	return U;
}


int main(){
	FILE *ff,*fp,*fp2,*fp3,*f,*f2,*f3;
	f = fopen("movielist.txt","w");
	f2 = fopen("directorlist.txt","w");
	f3 = fopen("actorlist.txt","w");
	fp = fopen("movielog.txt","r");
	fp2 = fopen("directorlog.txt","r");
	fp3 = fopen("actorlog.txt","r");
	/* 정보 링크드 리스트 생성 */
    curNum1 = curNum2 = curNum3 = 0;
	init_list(&Mhead);
	movie_info(&Mhead,fp,f);
	mkList(Mhead);

	init_list2(&Dhead);
	director_info(&Dhead,fp2,f2);
    mkList2(Dhead);

	init_list3(&Ahead);
	actor_info(&Ahead,fp3,f3);
    mkList3(Ahead); 
	/* 메뉴 프롬프트 */
    int i;
	char *Menu = malloc(sizeof(char)*50);
	char *Menu2 = malloc(sizeof(char)*50);
	char *Menu3 = malloc(sizeof(char)*50);
	printf("<input :search/print/add/update/delete/sort/save/end>\n");
    printf("\n");
	while(1){
	linkdirector(&Mhead,&Dhead);
	linktitle(&Mhead,Dhead,"Dhead");
	linktitle(&Mhead,Ahead,"Ahead");
	linkactor(&Mhead,&Ahead);
		Menu = menu();
		Menu2 = strtok(Menu," ");
        Menu3 = strtok(NULL,"\0");
		if(!strcmp(Menu2,"search"))search(Menu3);
		else if(!strcmp(Menu,"print")) print(Menu3);
		else if(!strcmp(Menu,"add")) add(Menu3);
		else if(!strcmp(Menu,"update")) {update(Menu3);getchar();} 
		else if(!strcmp(Menu,"delete")) delete(Menu3);
		else if(!strcmp(Menu,"sort")) sort(Menu3);
		else if(!strcmp(Menu,"save")) save(Menu3);
		else if(!strcmp(Menu,"end")){end(); break; }
		else printf(" 메뉴명을 다시 입력하세요 \n");
printf("\n");
	}

	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	return 0;
}




