#include <stdio.h>
#include "connection.h"

void addConnection()
{
	printf("MySQL client version from add function: %s\n", mysql_get_client_info());
}

void secondConnection()
{
	printf("MySQL client version from second function: %s\n", mysql_get_client_info());
}

void connection()
{
	MYSQL *con = mysql_init(NULL);
	if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "netdotter", 
          NULL, 0, NULL, 0) == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }  

  if (mysql_query(con, "CREATE DATABASE testdb")) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  mysql_close(con);  
}