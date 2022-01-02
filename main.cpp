// Example of Database class usage

#include "Database.h"

int main()
{
	Database db;

	std::vector<std::pair<std::string, std::string>> data;
	const char* s = "C:/Users/[USER]/Documents/testdatabase.db";
	std::string table = "TEST("
						"DATE			CHAR(20)	PRIMARY KEY NOT NULL,"
						"ID				INT			UNIQUE		NOT NULL,"
						"TEMPERATURE	REAL		NOT NULL);";

	db.createDB(s);

	db.createTable(s, table);

	db.insertData(s, "TEST", "'10-10-1010', 1, 23.54");

	db.selectData(s, data, "TEST", "ID=1");

	db.printData(data);

	std::cout << "Count: " << db.getCount(s, "TEST") << std::endl;

	db.deleteData(s, "TEST", "ID=1");

	std::cout << "Count: " << db.getCount(s, "TEST") << std::endl;

	db.deleteTable(s, "TEST");

	db.createTable(s, table);

	return 0;
}
