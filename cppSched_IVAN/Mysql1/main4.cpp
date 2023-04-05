
//#include <iostream>
//#include <string>
//#include <memory>
//
//#include "mysql_connection.h"
//#include "mysql_driver.h"
//
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
//#include <cppconn/statement.h>
//#include <cppconn/resultset.h>
//
//#define DB "students_db"
//
//using namespace std;
//    
//
//const string server = "tcp://127.0.0.1:3306";
//const string username = "root";
//const string password = "Zxcqwe7931";

//
//int main()
//{
//    sql::Driver* driver;
//    sql::Connection* con;
//    sql::Statement* stmt;
//    sql::PreparedStatement* pstmt;
//    sql::ResultSet* res;
//
//    try
//    {
//
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        con = driver->connect(server, username, password);
//        /* Connect to the MySQL test database */
//        con->setSchema(DB);
//
//
//        stmt = con->createStatement();
//
//        //res = stmt->executeQuery("SELECT name, surname, st FROM student ORDER BY id_st ASC");
//        //while (res->next()) {
//        //    // You can use either numeric offsets...
//        //    cout << "name = " << res->getString(1) << "\t"; // getInt(1) returns the first column
//        //    // ... or column names for accessing results.
//        //    // The latter is recommended.
//        //    cout << "surname = '" << res->getString(2) << "'" << "\t";
//        //    cout << "st = '" << res->getString(3) << "'" << endl;
//        //}
//
//        
//        string q = "insert into student(name, surname, st,alive) values(?,?,?,?)";
//        pstmt = con->prepareStatement(q);
//        pstmt->setString(1, "Karimm2");
//        pstmt->setString(2, "Niggma");
//        pstmt->setString(3, "st076338");
//        pstmt->setInt(4, 0);
//        pstmt->execute();
//
//        delete stmt;
//        delete con;
//
//    }
//    catch (sql::SQLException e)
//    {
//        /*
//          The JDBC API throws three different exceptions:
//
//        - sql::MethodNotImplementedException (derived from sql::SQLException)
//        - sql::InvalidArgumentException (derived from sql::SQLException)
//        - sql::SQLException (derived from std::runtime_error)
//        */
//
//        cout << "# ERR: SQLException in " << __FILE__;
//        cout << "(" << "EXAMPLE_FUNCTION" << ") on line " << __LINE__ << endl;
//
//        /* Use what() (derived from std::runtime_error) to fetch the error message */
//
//        cout << "# ERR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//
//        return EXIT_FAILURE;
//    }
//    
//    return 0;
//}