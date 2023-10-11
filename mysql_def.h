#pragma once
#include "mysql.h"

typedef struct libmysql {
	MYSQL *m_pCtx;
	MYSQL_RES *res;

}MYSQLCTX;
