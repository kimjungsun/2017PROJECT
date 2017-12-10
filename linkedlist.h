
#pragma  once 
#pragma warning(disable:4996)
int curNum1,curNum2,curNum3;
int compare(const void *,const void *);
void sortNode();
void updateNode(void *,void *,char *);
void *gotoNode(int,void *,char *);
void deleteNode(void *,int,char *);
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
void director_info(dp *,FILE *,FILE *);
void init_list3(ap *);
void addNode3(ap *,ap);
void actor_info(ap *,FILE *,FILE *);
void mkList(mp);
void mkList2(dp);
void mkList3(ap);
void saveNode(void *,char *,char *,char *);
void sortNode(void *,char *,char *,char *);
void sorting(char **,int *,int);
