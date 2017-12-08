#include<stdio.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "datatype.h"
#include "linkedlist.h"

void init_list(mp *Mhead){
  *Mhead = malloc(sizeof(movie));
	(*Mhead) -> next = NULL;
}
void init_list2(dp *Dhead){
	*Dhead = malloc(sizeof(director));
	(*Dhead) -> next = NULL;
}
void init_list3(ap *Ahead){
	*Ahead = malloc(sizeof(actor));
	(*Ahead) -> next = NULL;
}

void init_actorlist(ap2 *ahead){
	*ahead = malloc(sizeof(actors));
	(*ahead) -> next = NULL;
}
void init_titlelist(tp *thead){
	*thead = malloc(sizeof(titles));
	(*thead) -> next = NULL;
}

void addNode(mp *head,mp cur){

	mp tail = malloc(sizeof(movie));
		  tail = (*head);
		  while(tail->next != NULL)
		  { 
			  tail = tail->next;
		  }
		  tail->next = cur;
	}
void addNode2(dp *head,dp cur){

	dp tail = malloc(sizeof(director));
		  tail = (*head);
		  while(tail->next != NULL)
		  { 
			  tail = tail->next;
		  }
		  tail->next = cur;
	}
void addNode3(ap *head,ap cur){

	ap tail = malloc(sizeof(actor));
		  tail = (*head);
		  while(tail->next != NULL)
		  { 
			  tail = tail->next;
		  }
		  tail->next = cur;
	}
void * gotoNode(int num,void *head,char *s){
	if(!strcmp(s,"M")){
	mp tmp = (mp)head;
		while(tmp->next != NULL){
			if(tmp->next->num == num) return tmp->next;
			tmp = tmp->next;
		}
		return NULL;
	}
	if(!strcmp(s,"D")){
	dp tmp = (dp)head;
	while(tmp->next!= NULL){
			if(tmp->next->num == num) return tmp->next;
			tmp = tmp->next;
		}
	return NULL;
	}
	if(!strcmp(s,"A")){
	ap tmp =(ap)head;
	while(tmp->next != NULL){
			if(tmp->next->num == num) return tmp->next;
			tmp = tmp->next;
		}
	return NULL;
	}
}
void deleteNode(void *head,int num,char *s){
    void *cur = gotoNode(num,head,s);
	if(!strcmp(s,"M")){
	mp tmp = (mp)head;
	mp Cur = (mp)cur;
	while(tmp->next != Cur)
			tmp = tmp->next;
				
	tmp-> next = tmp->next->next;
	free(Cur);
	}
	if(!strcmp(s,"D")){
	dp tmp = (dp)head;
	dp Cur = (dp)cur;
	while(tmp->next != Cur)
			tmp = tmp->next;
				
	tmp-> next = tmp->next->next;
	free(Cur);
	}
	if(!strcmp(s,"A")){
	ap tmp = (ap)head;
	ap Cur = (ap)cur;
	while(tmp->next != Cur)
			tmp = tmp->next;
				
	tmp-> next = tmp->next->next;
	free(Cur);
	}
	}
void updateNode(void *tmp,void *tmp2,char *s){
    if(!strcmp(s,"M")){
	mp head = (mp)tmp;
	mp cur = (mp)tmp2;
	mp Cur  = gotoNode(cur->num,head,"M");
	
	while(head->next != Cur)
			head = head->next;
		
	deleteNode(head,cur->num,"M");
	cur -> next = head->next;
	head-> next = cur;
	}

	else if(!strcmp(s,"D")){
	dp head = (dp)tmp;
	dp cur = (dp)tmp2;
	dp Cur  = gotoNode(cur->num,head,"D");
	
	while(head->next != Cur)
			head = head->next;
		
	deleteNode(head,cur->num,"D");
	cur -> next = head->next;
	head-> next = cur;
	}
	
	else if(!strcmp(s,"A")){
	ap head = (ap)tmp;
	ap cur = (ap)tmp2;
	ap Cur  = gotoNode(cur->num,head,"A");
	
	while(head->next != Cur)
			head = head->next;
		
	deleteNode(head,cur->num,"A");
	cur -> next = head->next;
	head-> next = cur;
	}

}
void mkList(mp head){
		FILE *f = fopen("movielist.txt","w");	
		mp cur = head;
	while(cur ->next != NULL){
		actors *temp = cur->next->actor;	
		char *str = malloc(sizeof(char)*110);
				sprintf(str,"%d:%s:%s:%s:%d:%d:",cur->next->num,cur->next->title,cur->next->genre,cur->next->director->director,cur->next->year,cur->next->time);
				fputs(str,f);
		int i=0;
				while(temp->next!=NULL)
				{
					fputs(temp->next->actor,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}
				cur = cur->next;
	fputc('\n',f);
	}
	fclose(f);
	
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	char *str = malloc(sizeof(char)*100);
	char *str1 = malloc(sizeof(char)*100);
    strcpy(str1,"movie_list.");
	sprintf(str,"%d",(t->tm_year+1900));
	sprintf(&str[4],"%d",(t->tm_mon+1));
	sprintf(&str[6],"%02d",(t->tm_mday));
	sprintf(&str[8],"%02d",(t->tm_hour));
	sprintf(&str[10],"%02d",(t->tm_min));
    strcat(str1,str);
	f= fopen("movielist.txt","r");
	
	int fd =creat(str1,0644);
	close(fd);
	FILE *f3= fopen(str1,"w");
	while(fgets(str,100,f)){
			fputs(str,f3);
			}
	fclose(f);
	fclose(f3);
	printf("%s 저장되었습니다.\n",str1);
}
			
void mkList2(dp head){
		FILE *f = fopen("directorlist.txt","w");	
		dp cur = head;
	while(cur ->next != NULL){
		titles *temp = cur->next->title;	
		char *str = malloc(sizeof(char)*110);
				sprintf(str,"%d:%s:%c:%s:",cur->next->num,cur->next->director,cur->next->sex,cur->next->birth);
				fputs(str,f);
		int i=0;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}
				cur = cur->next;
	fputc('\n',f);
	}
	fclose(f);
	
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	char *str = malloc(sizeof(char)*100);
	char *str1 = malloc(sizeof(char)*100);
    strcpy(str1,"actor_list.");
	sprintf(str,"%d",(t->tm_year+1900));
	sprintf(&str[4],"%d",(t->tm_mon+1));
	sprintf(&str[6],"%02d",(t->tm_mday));
	sprintf(&str[8],"%02d",(t->tm_hour));
	sprintf(&str[10],"%02d",(t->tm_min));
    strcat(str1,str);
	f= fopen("directorlist.txt","r");
	
	int fd =creat(str1,0644);
	close(fd);
	FILE *f3= fopen(str1,"w");
	while(fgets(str,100,f)){
			fputs(str,f3);
			}
	fclose(f);
	fclose(f3);
	printf("%s 저장되었습니다.\n",str1);
}
void mkList3(ap head){
		FILE *f = fopen("actorlist.txt","w");	
		ap cur = head;
	while(cur ->next != NULL){
		titles *temp = cur->next->title;	
		char *str = malloc(sizeof(char)*110);
				sprintf(str,"%d:%s:%c:%s:",cur->next->num,cur->next->actor,cur->next->sex,cur->next->birth);
				fputs(str,f);
		int i=0;
				while(temp->next!=NULL)
				{
					fputs(temp->next->title,f);
					if(i++) fputc(',',f);
			   temp = temp->next;
			}
				cur = cur->next;
	fputc('\n',f);
	}
	fclose(f);
	
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	char *str = malloc(sizeof(char)*100);
	char *str1 = malloc(sizeof(char)*100);
    strcpy(str1,"actor_list.");
	sprintf(str,"%d",(t->tm_year+1900));
	sprintf(&str[4],"%d",(t->tm_mon+1));
	sprintf(&str[6],"%02d",(t->tm_mday));
	sprintf(&str[8],"%02d",(t->tm_hour));
	sprintf(&str[10],"%02d",(t->tm_min));
    strcat(str1,str);
	f= fopen("actorlist.txt","r");
	
	int fd =creat(str1,0644);
	close(fd);
	FILE *f3= fopen(str1,"w");
	while(fgets(str,100,f)){
			fputs(str,f3);
			}
	fclose(f);
	fclose(f3);
	printf("%s 저장되었습니다.\n",str1);
}
void movie_info(mp *head,FILE *fp,FILE *fp2){
    mp cur;
	char *state= malloc(sizeof(char)*100);// 일단 임시적으로 add,update,,등을버려놓는곳
	while(1){// 영화 정보 받기
	char *s = malloc(sizeof(char)*100);// 파일에서 받은 라인 
	if(fgets(s,100,fp)){
		s[strlen(s)-1] ='\0';
        cur = malloc(sizeof(movie));
		cur->director = malloc(sizeof(directorlist));
		state = strtok(s,":");
		if(!strcmp(state,"add")){
		cur->num = atoi(strtok(NULL,":")); 
		cur->title=strtok(NULL,":");
		cur->genre=strtok(NULL,":");
	    cur->director->director = strtok(NULL,":");
        cur->director->directorP= NULL;    	
        cur->year = atoi(strtok(NULL,":"));
		cur->time = atoi(strtok(NULL,":"));
		 ap2 temp = malloc(sizeof(actors));
		 ap2 ahead = temp;
		while(1){
			temp ->next = malloc(sizeof(actors));
			temp -> next->actor = strtok(NULL,",");
			temp -> next -> actorP = NULL;
			temp -> next ->next = NULL;
		   if(temp->next->actor == NULL) {temp->next=NULL;break;}
		  temp = temp->next;
		}  
		cur->actor = ahead; 
		cur->next = NULL;
		addNode(head,cur);
		curNum1 = (cur->num) + 1;
		
	}
		else if(!strcmp(state,"update")){
		cur->num = atoi(strtok(NULL,":"));
		cur->title=strtok(NULL,":");
		cur->genre=strtok(NULL,":");
	    cur->director->director = strtok(NULL,":");
        cur->director->directorP= NULL;    	
        cur->year = atoi(strtok(NULL,":"));
		cur->time = atoi(strtok(NULL,":"));
		 ap2 temp = malloc(sizeof(actors));
		 ap2 ahead = temp;
		 int i=0;
		while(1){
			temp ->next = malloc(sizeof(actors));
			temp -> next->actor = strtok(NULL,",");
			temp -> next -> actorP = NULL;
			temp -> next ->next = NULL;
		   if(temp->next->actor == NULL) {temp->next=NULL;break;}
		  temp = temp->next;
		}  
		cur->actor = ahead; 
		cur->next = NULL;
		updateNode(*head,cur,"M");
	}
    else if(!strcmp(state,"delete")){
		deleteNode(*head,2,"M");
		return ;
	}
	}
	else break;
	
	}

}


void director_info(dp *head,FILE *fp,FILE *fp2){
    dp cur;
	char *state= malloc(sizeof(char)*100);// 일단 임시적으로 add,update,,등을버려놓는곳
	while(1){// 영화 정보 받기
	char *s = malloc(sizeof(char)*100);// 파일에서 받은 라인 
    
	if(fgets(s,100,fp)){
		s[strlen(s)-1] ='\0';
    cur = malloc(sizeof(director));
		state = strtok(s,":");
		if(!strcmp(state,"add")){
		cur->num = atoi(strtok(NULL,":"));
		cur->director=strtok(NULL,":");
		cur->sex=strtok(NULL,":")[0];
		cur->birth =strtok(NULL,":");
    tp temp = malloc(sizeof(titles));
	temp->next = NULL;
	tp thead = temp;
		while(1){
			temp->next = malloc(sizeof(titles));
			temp -> next->title = strtok(NULL,",");
			temp -> next -> movieP = NULL;
			temp->next->next = NULL;
		   if(temp->next->title == NULL){ temp->next=NULL; break;}
		   temp = temp->next;
		} 
		cur->title = thead;
		cur->next = NULL;
		addNode2(head,cur);
	curNum2 = (cur->num)+1;
		}
		else if(!strcmp(state,"update")){
		cur->num = atoi(strtok(NULL,":"));
		cur->director = strtok(NULL,":");
		cur->sex = strtok(NULL,":")[0];
		cur->birth = strtok(NULL,":");
		tp temp = malloc(sizeof(titles));
		tp thead = temp;
		int i = 0;
		while(1){
			temp -> next = malloc(sizeof(titles));
			temp -> next -> title = strtok(NULL,",");
			temp -> next ->movieP = NULL;
			temp -> next->next = NULL;
			if(temp->next->title ==NULL){temp->next= NULL; break;}
			temp = temp->next;
		}
		cur->title = thead;
		cur->next = NULL;
		updateNode(*head,cur,"D");
	}
        
		}
		else break;
}
}
void actor_info(ap *head,FILE *fp,FILE *fp2){
    ap cur;
	char *state= malloc(sizeof(char)*100);// 일단 임시적으로 add,update,,등을버려놓는곳
	while(1){// 영화 정보 받기
	char *s = malloc(sizeof(char)*100);// 파일에서 받은 라인 
    
	if(fgets(s,MaxStrSize,fp)){
		s[strlen(s)-1]='\0';
    cur = malloc(sizeof(actor));
		state = strtok(s,":");
		if(!strcmp(state,"add")){
		cur->num = atoi(strtok(NULL,":"));
		cur->actor=strtok(NULL,":");
		cur->sex=strtok(NULL,":")[0];
		cur->birth=strtok(NULL,":");
		tp temp = malloc(sizeof(titles));
		tp thead = temp;
		while(1){
			temp->next = malloc(sizeof(titles));
			temp -> next->title = strtok(NULL,",");
			temp -> next -> movieP = NULL;
			temp->next->next = NULL;
		   if(temp->next->title == NULL){ temp->next = NULL;  break;}
		   temp = temp->next;
		}  
		cur->title = thead;
		cur->next = NULL;
		addNode3(head,cur);
	curNum3 = (cur->num)+1;
	}
		else if(!strcmp(state,"update")){
		cur->num = atoi(strtok(NULL,":"));
		cur->actor = strtok(NULL,":");
		cur->sex = strtok(NULL,":")[0];
		cur->birth = strtok(NULL,":");
		tp temp = malloc(sizeof(titles));
		tp thead = temp;
		temp->next = NULL;
		int i = 0;
		while(1){
			temp -> next = malloc(sizeof(titles));
			temp -> next -> title = strtok(NULL,",");
			temp -> next ->movieP = NULL;
			temp -> next->next = NULL;
			if(temp->next->title ==NULL){temp->next= NULL; break;}
			temp = temp->next;
		}
		cur->title = thead;
		cur->next = NULL;
		updateNode(*head,cur,"A");
		}
	}
	else break;
	}
}



void linkdirector(mp *Mhead,dp *Dhead){
	mp Mcur = (*Mhead)->next;
	while(Mcur != NULL)
	{
	dp Dcur = (*Dhead)->next;
		while(Dcur != NULL){
			if(!strcmp(Mcur->director->director,Dcur->director))
			Mcur->director->directorP = Dcur;
			Dcur = Dcur -> next ;
									 }
	Mcur = Mcur -> next;
}
}
void linktitle(mp *Mhead,void *head,char *S){
    dp Dcur;
	ap Acur;
	
	if(!strcmp(S,"Dhead")){
		
		Dcur = ((dp)head)->next;
	while(Dcur != NULL){
	tp temp = malloc(sizeof(titles));
	temp =Dcur->title->next;

      while(temp != '\0'){
     	mp Mcur = (*Mhead)->next;
		
		while(Mcur != NULL){
			if(!strcmp(Mcur->title,temp->title))
			{		temp->movieP = Mcur;
			}
				Mcur = Mcur -> next ;
		}
		temp = temp->next;
									 }
	Dcur = Dcur -> next;
	}
	}
	else if(!strcmp(S,"Ahead")){
		Acur = ((ap)head)->next;
	while(Acur != NULL){
	tp temp = malloc(sizeof(titles));
	temp =Acur->title->next;

      while(temp != '\0'){
     	mp Mcur = (*Mhead)->next;
		
		while(Mcur != NULL){
			if(!strcmp(Mcur->title,temp->title))
			{		temp->movieP = Mcur;
			}
				Mcur = Mcur -> next ;
		}
		temp = temp->next;
									 }
	Acur = Acur -> next;
	}
	}
}

void linkactor(mp *Mhead, ap *Ahead){

	mp Mcur = (*Mhead)->next;
	while(Mcur != NULL){
//	ap2 temp = malloc(sizeof(actors));
ap2 temp = Mcur->actor->next;

      while(temp != '\0'){
     	ap Acur = (*Ahead)->next;
		
		while(Acur != NULL){
			if(!strcmp(Acur->actor,temp->actor))
			{		temp->actorP = Acur ;
			}
				Acur = Acur -> next ;
		}
		temp = temp->next;
									 }
	Mcur = Mcur -> next;
	}
}
