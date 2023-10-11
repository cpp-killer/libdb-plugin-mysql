#include "libmysql.h"
#include <stdio.h>
#include <exception>
dbmysql::dbmysql()
{
	m_ctx.m_pCtx = NULL;
	m_ctx.res = NULL;
}

void dbmysql::outSrvVersion() throw (dbexception)
{

	int res = mysql_query(m_ctx.m_pCtx, MySQL_VERSION.c_str());
	if (res)
		throw dbexception(mysql_errno(m_ctx.m_pCtx), "Get MySQL Version Error: %s", mysql_error(m_ctx.m_pCtx));	

}

int dbmysql::initDB(const ctxinfo &info) throw (dbexception)
{
	mysql_library_init(0, NULL, NULL);
	m_ctx.m_pCtx = mysql_init(NULL);
	if (m_ctx.m_pCtx == NULL)
		throw dbexception(mysql_errno(m_ctx.m_pCtx), "MySQL Init Error: %s", mysql_error(m_ctx.m_pCtx));	


	std::stringstream ConnStr;

	ConnStr << "tcp://" << info.ip << ":" << info.port;
	std::cout << "connect info :" <<ConnStr << std::endl;

	this->m_cInfo = info;
	//m_cInfo. = host;

	return 0;
}

int dbmysql::initDB() throw (dbexception)
{
	mysql_library_init(0, NULL, NULL);
	m_ctx.m_pCtx = mysql_init(NULL);
	if (m_ctx.m_pCtx == NULL)
	{
		throw dbexception(mysql_errno(m_ctx.m_pCtx), "MySQL Init Error: %s", mysql_error(m_ctx.m_pCtx));
	}

	return 0;
}

int dbmysql::connDB() throw (dbexception)
{
	if (!mysql_real_connect(m_ctx.m_pCtx, m_cInfo.ip.c_str(), \
		m_cInfo.usr.c_str(), m_cInfo.pwd.c_str(), \
		m_cInfo.dbname.c_str(), m_cInfo.port, NULL, 0))
		{
			std::cout <<  m_cInfo.ip << " : " << m_cInfo.port<< std::endl;
			throw dbexception(mysql_errno(m_ctx.m_pCtx), "MySQL Connect Error: %s", mysql_error(m_ctx.m_pCtx));	
		}

	return 0;
}

int dbmysql::connDB( const ctxinfo &info ) throw (dbexception)
{
	m_cInfo = info;
	if (!mysql_real_connect(m_ctx.m_pCtx, m_cInfo.ip.c_str(), \
		m_cInfo.usr.c_str(), m_cInfo.pwd.c_str(), \
		m_cInfo.dbname.c_str(), m_cInfo.port, NULL, 0))
	{
		throw dbexception(mysql_errno(m_ctx.m_pCtx), "MySQL Connect Error: %s", mysql_error(m_ctx.m_pCtx));	
	}
	return 0;
}

int dbmysql::setCharSet(const std::string &En) throw (dbexception)
{
	std::string charset = "SET CHARSET ";
	if (En.length() != 0)
	{
		charset += En;
		return mysql_query(m_ctx.m_pCtx, charset.c_str());	
// 		if (res)
// 			throw dbexception((int)mysql_errno, "Get MySQL Version Error: %s", mysql_error(m_ctx.m_pCtx));	

	}

	return 0;
}

int dbmysql::updateDB(const std::string &sql) throw (dbexception)
{
// 	try
// 	{
// 		std::string _sql;
// 		if (sql.length() == 0)
// 		{
// 			_sql = sql;
// 		}
// 		else
// 		{
// 			_sql = m_sSQL;
// 		}
// 		m_ctx.stmt->executeUpdate(_sql);
// 	}
// 	catch (sql::SQLException& e)
// 	{
// 		throw dbexception(e.getErrorCode(), e.what());
// 		return e.getErrorCode();
// 	}

	return 0;
}

int dbmysql::excuteQuery(const std::string &sql, const int &fields) throw (dbexception)
{
	if ( 0!= mysql_real_query(m_ctx.m_pCtx, sql.c_str(), sql.length()))
		throw dbexception(mysql_errno(m_ctx.m_pCtx), mysql_error(m_ctx.m_pCtx));
	return mysql_errno(m_ctx.m_pCtx);
}

void dbmysql::foreachDB() throw (dbexception)
{

}

int dbmysql::setAutoCommitOK() throw (dbexception)
{
	if (mysql_autocommit(m_ctx.m_pCtx, 1) != 0 )
		throw dbexception(mysql_errno(m_ctx.m_pCtx), mysql_error(m_ctx.m_pCtx));
	return mysql_errno(m_ctx.m_pCtx);
// 	if (res)
// 		throw dbexception(mysql_errno(m_ctx.m_pCtx), "setAutoCommitOK::err()", mysql_error(m_ctx.m_pCtx));

	return 0;
}

int dbmysql::setAutoCommitNo() throw (dbexception)
{
	if (mysql_autocommit(m_ctx.m_pCtx, 0) != 0) ;
		throw dbexception(mysql_errno(m_ctx.m_pCtx), mysql_error(m_ctx.m_pCtx));

	return mysql_errno(m_ctx.m_pCtx);
}

int dbmysql::excuteSQL(const std::string &sql) throw (dbexception)
{
	if (mysql_query(m_ctx.m_pCtx, sql.c_str()) != 0)
		throw dbexception(mysql_errno(m_ctx.m_pCtx), mysql_error(m_ctx.m_pCtx));
	return mysql_errno(m_ctx.m_pCtx);
}

void dbmysql::closeDB() throw (dbexception)
{
	if (m_ctx.m_pCtx != NULL)
		mysql_close(m_ctx.m_pCtx);
//	m_ctx.m_pCtx = NULL;
}

void dbmysql::destoryDB() throw (dbexception)
{
	closeDB();
	mysql_library_end();
	return;
}

std::string dbmysql::getDBString(const size_t &co) throw (dbexception)
{
	std::string dbdata;

	return dbdata;
}

void dbmysql::setDataBufDB(jjdb::uint32 column, void **values, jjdb::uint16 valtype, jjdb::uint32 size, size_t *len) throw (dbexception)
{

}

std::string dbmysql::getDbDesc()
{
	return "mysql!";
}

dbmysql::~dbmysql()
{
	destoryDB();
}

int dbmysql::Commit() throw (dbexception)
{
	this->excuteSQL("commit;");
	return 0;
}

int dbmysql::RollBack() throw (dbexception)
{ 
	this->excuteSQL("rollback;");
	return 0;
}

int dbmysql::AffairBegin() throw (dbexception)
{
	this->excuteSQL("Start Transaction;");
	return 0;
}

int dbmysql::AffairStop() throw (dbexception)
{
	this->excuteSQL("End Transaction;");

	return 0;
}


const char* dbmysql::ErrorStr() throw (dbexception)
{
	if(m_ctx.m_pCtx != NULL) {
		return mysql_error(m_ctx.m_pCtx);
	}
	return "mysql no error!";
}

//遍记结果集
int dbmysql::StoreResultRow(const int &row, std::vector<std::string> &cols) throw (dbexception)
{
	//遍记结果集
	//StoreResult();
	ULONG64 num = getNumFields();//获取多少列;
	SetNumFields(num);
	MYSQL_ROW rows = mysql_fetch_row(m_ctx.res);
	ULONG64 i;
	for (i = 0; m_ctx.res != NULL && i < num; ++i)
	{
		cols.push_back(static_cast<std::string>(rows[i]));
	}
	return i;
}

int dbmysql::StoreResult() throw (dbexception)
{
	if (m_ctx.m_pCtx == NULL)
	{
		throw dbexception(0, "mysql not init!");
	}

	m_ctx.res = mysql_store_result(m_ctx.m_pCtx);
	if (m_ctx.res == NULL)
	{
		throw dbexception(mysql_errno(m_ctx.m_pCtx), "not found record!");
	}
	return 0;
}

void dbmysql::SetNumRows( const ULONG64 &rows ) throw (dbexception) 
{
//	this->m_rows = rows;
}

void dbmysql::SetNumFields( const ULONG64 &fields ) throw (dbexception) 
{
	this->m_fields = fields;
}

ULONG64 dbmysql::getNumRows() throw (dbexception)
{
	return mysql_num_rows(m_ctx.res);
}

ULONG64 dbmysql::getNumFields() throw (dbexception)
{
	return mysql_num_fields(m_ctx.res);
}

int dbmysql::freeResult() throw (dbexception) 
{
	if (m_ctx.res != NULL)
		mysql_free_result(m_ctx.res);
	m_ctx.res = NULL;
	return 0;
}



#ifdef OS_UNIX
	#ifdef __cplusplus
		extern "C" {
	#endif
#endif
dbbase * OUTAPI getDbMain()
{
	return new dbmysql;
}

void OUTAPI delDbMain(dbbase *pDb)
{
	if (pDb != NULL)
		delete (dbmysql*)pDb;
	pDb = NULL;
}
#ifdef OS_UNIX
#ifdef __cplusplus
		}
#endif
#endif
