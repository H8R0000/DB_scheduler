#include "connect.h"

void fetchAll_st()
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std:string table = "student";
    cout << "Working with table: " << table << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);


    // Accessing an existing table
    Table myTable = myDb.getTable(table);
   
    // Find a row in the SQL Table
    RowResult myRows = myTable.select("id_st", "name", "surname", "patronymic", "st", "alive", "id_group").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "Surname:" << row[2] << "\t";
        cout << "Patronymic:" << row[3] << "\t";
        cout << "St:" << row[4] << "\t";
        cout << "alive?:" << bool(row[5]) << "\t";
        cout << "id_group:" << row[6] << endl;

    }

}
void fetchAll_teachers()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std:string table = "teacher";
    cout << "Working with table: " << table << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);


    // Accessing an existing table
    Table myTable = myDb.getTable(table);

    // Find a row in the SQL Table
    RowResult myRows = myTable.select("id_t", "name", "surname").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "Surname:" << row[2] << endl;
    }
}
void fetchAll_labs()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "laba";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    RowResult myRows = myTable.select("id_laba", "name", "id_block").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "ID_LABA:" << row[0] << "\t";
        cout << "Name:" << row[1] << "\t";
        cout << "ID_BLOCK:" << row[2] << endl;
    }
}
void fetchAll_groups()
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    cout << "Creating session on " << "mysqlx://root:Zxcqwe7931@127.0.0.1" << " ..." << endl;
    std::string table_str = "group";
    cout << "Working with table: " << table_str << endl << "..." << endl;
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    RowResult myRows = myTable.select("id_g", "YearForm", "id_spec").execute();

    for (Row row : myRows.fetchAll())
    {
        cout << "id_g:" << row[0] << "\t";
        cout << "YearForm:" << row[1] << "\t";
        cout << "id_spec:" << row[2] << endl;
    }
}


void add_st(struct student student)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std:string table_str = "student";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

        // Find a row in the SQL Table
        myTable.insert("name", "surname", "patronymic", "st", "alive", "id_group")
            .values(student.name, student.surname, student.patronymic, student.st, student.alive, student.id_group)
            .execute();

}
void add_t(struct teacher teacher)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std:string table_str = "teacher";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.insert("name", "surname")
        .values(teacher.name, teacher.surname)
        .execute();

}
void add_group(struct group group)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std:string table_str = "group";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.insert("YearForm", "id_spec")
        .values(group.YearForm, group.id_spec)
        .execute();
}
void add_lab(struct laba laba)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "laba";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.insert("name", "id_block")
        .values(laba.name, laba.id_block)
        .execute();
}


void delete_lab(std::string id)
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "laba";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.remove().where("id_laba = " + id).execute();
}
void delete_st(std::string id)
{

    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "student";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.remove().where("id_st = " + id).execute();
}
void delete_t(std::string id)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "teacher";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.remove().where("id_t = " + id).execute();
}
void delete_group(std::string id)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "group";
    Schema myDb = sess.getSchema("students_db", true);

    // Accessing an existing table
    Table myTable = myDb.getTable(table_str);

    // Find a row in the SQL Table
    myTable.remove().where("id_g = " + id).execute();
}