#include<stdio.h>
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
	mp Cur  = gotoNode(2,head,"M");
	
	while(head->next != Cur)
			head = head->next;
		
	deleteNode(head,2,"M");
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
		printf("%s\n",state);
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
		addNode(head,cur);
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
				deleteNode(head,atoi(strtok(NULL,":")),"M");
				}
	}
	else break;
	
	}
}


void director_info(dp *head,FILE *fp){
    dp cur;
	char *state= malloc(sizeof(char)*100);// 일단 임시적으로 add,update,,등을버려놓는곳
	while(1){// 영화 정보 받기
	char *s = malloc(sizeof(char)*100);// 파일에서 받은 라인 
    
	if(fgets(s,100,fp)){
		s[strlen(s)-1] ='\0';
    cur = malloc(sizeof(director));
		state = strtok(s,":");
		cur->num = atoi(strtok(NULL,":"));
		cur->director=strtok(NULL,":");
		cur->sex=strtok(NULL,":")[0];
		cur->birth =strtok(NULL,":");
    tp temp = malloc(sizeof(titles));
	temp->next = NULL;
	tp thead = temp;
	int i=0;
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
	}
	else break;
	}
}

void actor_info(ap *head,FILE *fp){
    ap cur;
	char *state= malloc(sizeof(char)*100);// 일단 임시적으로 add,update,,등을버려놓는곳
	while(1){// 영화 정보 받기
	char *s = malloc(sizeof(char)*100);// 파일에서 받은 라인 
    
	if(fgets(s,MaxStrSize,fp)){
		s[strlen(s)-1]='\0';
    cur = malloc(sizeof(actor));
		state = strtok(s,":");
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
