
#ifdef WINDOWS_ENV

#endif // WINDOWS_ENV

#include "dbglobal.h"
#include "mysql_def.h"

#ifdef  OS_WIN32
	#define  OUTAPI __stdcall
	#ifndef DBDLL_EXPORT
		#define DBDLL  __declspec(dllexport)
	#else
		#define DBDLL  __declspec(dllimport)
	#endif

#else
#define DLLMYSQL
#define OUTAPI
#endif

const std::string MySQL_VERSION = "select version();";


class /*DBDLL*/ dbmysql :public dbbase
{
public:
	dbmysql();
	virtual void outSrvVersion() throw (dbexception);
	virtual int initDB(const ctxinfo &info) throw (dbexception);
	virtual int connDB() throw (dbexception);
	virtual int initDB() throw (dbexception);
	virtual int connDB(const ctxinfo &info) throw (dbexception);
	/*设置字符集*/
	virtual int setCharSet(const std::string &En) throw (dbexception);
	virtual int	setAutoCommitOK() throw (dbexception);
	virtual int	setAutoCommitNo() throw (dbexception);
	virtual int excuteSQL(const std::string &sql) throw (dbexception);
	virtual int updateDB(const std::string &sql) throw (dbexception);
	virtual int	excuteQuery(const std::string &sql, const int &fields = 0) throw (dbexception);
	virtual void foreachDB() throw (dbexception);

	virtual int StoreResult() throw (dbexception); //遍历结果
	virtual void SetNumRows(const ULONG64 &rows)  throw (dbexception) ;
	virtual void SetNumFields(const ULONG64 &fields) throw (dbexception) ;
	virtual ULONG64 getNumRows() throw (dbexception); //获取行数
	virtual ULONG64 getNumFields() throw (dbexception);//获取当前行的列数
	virtual int StoreResultRow(const int &row, std::vector<std::string> &cols) throw (dbexception);
	virtual int freeResult() throw (dbexception) ;//删除结果集

	
	virtual int Commit() throw (dbexception) ;
	virtual int RollBack() throw (dbexception) ;
	virtual int AffairBegin() throw (dbexception) ;
	virtual int AffairStop() throw (dbexception)  ;
	virtual void closeDB() throw (dbexception);
	virtual void destoryDB() throw (dbexception);
	virtual std::string getDBString(const size_t &co)throw (dbexception);
	void setDataBufDB(jjdb::uint32 column, void **values, jjdb::uint16 valtype, jjdb::uint32 size, size_t *len) throw (dbexception);
	virtual std::string getDbDesc();

	//virtual int RecordDate(LONG key, char* farmId, char* grpId, char _val[32]) throw (dbexception);
	//virtual int UpdateRecordDate(LONG key, char* farmId, SYSTEMTIME curtime) throw (dbexception);
	//virtual int GetFarmInfos(void* _this, int m_nDepots, int (*fun)(void *, char *, char *, char *, char *, char *) ) throw (dbexception);
	//virtual int GetVirtualGroupInfos(void* _this, int m_nDepots,  int(*fun)(void *, char *, char *, char *)) throw (dbexception);
	//virtual int GetTruelyGroupInfos(void* _this, int m_nDepots, int(*fun)(void *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetEnvironGroupInfos(void* _this, int m_nDepots,  int (*fun)(void *,  char *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetPhvsInfos(void* _this, int m_nDepots, int (*fun)(void *,  char *, char *, char *, char *, char *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetWindInfos(void* _this, int m_nDepots, int (*fun)(void *,  char *, char *, char *, char *, char *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetThreodInfo(void* _this, int m_nDepots, int (*fun)(void *, char *, char *, char *, int)) throw (dbexception);
	//virtual int GetFactorStateInfo(void* _this, int m_nDepots, int(*fun)(void *, char *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetDarkTimeFromNWP(void* _this, int m_nDepots, int(*fun)(void *, char *, char *, char *, char *)) throw (dbexception);
	//virtual int GetRecordInfos(void* _this, int (*fun)(void *, char *, char *), char *farmid, int nFlag) throw (dbexception) ;
	//virtual int InitDataFlagInfos(char *farmid) throw (dbexception);
	virtual const char* ErrorStr() throw (dbexception);
	//virtual int InsertLog(char *farm_id,int data_type,SYSTEMTIME sysTime,int status,char *memo,char *model_no)  throw (dbexception);

	~dbmysql();

private:

	MYSQLCTX m_ctx;
	CTXINFO m_cInfo;
};

