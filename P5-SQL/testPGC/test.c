/* Processed by ecpg (14.6 (Ubuntu 14.6-0ubuntu0.22.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "test.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <sqlca.h>

/* exec sql begin declare section */
   
   
   
 

#line 6 "test.pgc"
 char * dbname = "testdb" ;
 
#line 7 "test.pgc"
 char * user = "postgres" ;
 
#line 8 "test.pgc"
 char * password = "postgres" ;
 
#line 9 "test.pgc"
 char version [ 100 ] ;
/* exec sql end declare section */
#line 10 "test.pgc"


int main()
{
    { ECPGconnect(__LINE__, 0, dbname , user , password , NULL, 0); }
#line 14 "test.pgc"

    if (sqlca.sqlcode != 0)
    {
        printf("Connection failed: %s\n", sqlca.sqlerrm.sqlerrmc);
        exit(1);
    }
    else
    {
        printf("Connection successful\n");
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select version ( )", ECPGt_EOIT, 
	ECPGt_char,(version),(long)100,(long)1,(100)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 25 "test.pgc"

    if (sqlca.sqlcode != 0)
    {
        printf("Query failed: %s\n", sqlca.sqlerrm.sqlerrmc);
        exit(1);
    }
    else
    {
        printf("PostgreSQL version: %s\n", version);
    }

    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 36 "test.pgc"

}
