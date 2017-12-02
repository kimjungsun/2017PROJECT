
#pragma  once 
#pragma warning(disable:4996)
void *gotoNode(int,void *,char *);
void deleteNode(void *,void *,char *);
void linkactor(mp *,ap *);
void linktitle(mp *,void *,char *);
void linkdirector(mp *,dp *);
void init_list(mp *);
void init_actorlist(ap2 *);
void addNode(mp *,mp);
void movie_info(mp *,FILE *,FILE *);
void init_list2(dp *);
void init_titlelist(tp *);
void addNode2(dp *,dp);
void director_info(dp *,FILE *);
void init_list3(ap *);
void addNode3(ap *,ap);
void actor_info(ap *,FILE *);
