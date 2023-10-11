compiler=c++
src=./dbexception.cpp ./libmysql.cpp
lib_inc=./include/
libdb_path=../libdb/
libmysql_path=./lib/
src_inc=$(libdb_path)/include/

tar=libdbmysql.so

shared:
	$(compiler) -DOS_UNIX $(src)  -fPIC -o $(tar) -shared -I$(lib_inc) -I$(src_inc) $(libdb_path)libdb.a -L$(libmysql_path) -lmysqlclient 

clean:
	rm -f $(tar)
	