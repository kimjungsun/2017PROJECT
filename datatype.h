
#define MaxStrSize 100
	typedef struct directorlist {
		char *director;
		struct director *directorP;
	}directorlist;
typedef directorlist *dlp;

	struct movie {
		int num;
		char *title;
		char *genre;
		directorlist *director;
		int year;
		int time;
		struct actors *actor;
		struct movie *next;
	};

typedef struct movie movie;
typedef movie *mp;


struct titles{
		char *title;
       struct movie *movieP;
		struct titles *next;
	};
typedef struct titles titles;
typedef titles *tp;
    
    struct director{
		int num;
		char *director;
		char sex;
		char *birth;
		titles *title;
		struct director *next;
	};
typedef struct director director;
typedef director *dp;
	
struct actors{
		char *actor;
	    struct actor *actorP;
		struct actors *next;
	};
	typedef struct actors actors;
    typedef actors *ap2;




struct actor{
	int num;
	char *actor;
	char sex;
	char *birth;
	titles *title;
	struct actor *next;
};
typedef struct actor actor;
typedef actor *ap;
