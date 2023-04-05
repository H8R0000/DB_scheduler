#include "connect.h"

void fetchAll_st(std::vector <student>& vector)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table = "student";
    Schema myDb = sess.getSchema("students_db", true);
    Table myTable = myDb.getTable(table);
    RowResult myRows = myTable\
        .select("id_st", "name", "surname", "patronymic", "st", "alive", "id_group", "id_labg", "spec", "group_name")\
        .execute();

    for (Row row : myRows.fetchAll())
    {
        student STUDENT;
        STUDENT.id_st = row.get(0);
        STUDENT.name = std::string(row.get(1));
        STUDENT.surname = std::string(row.get(2));
        if (!row.get(3).isNull())
            STUDENT.patronymic = std::string(row.get(3));
        STUDENT.st = std::string(row.get(4));
        STUDENT.alive = row.get(5);
        STUDENT.id_group = row.get(6);
       // STUDENT.id_labg = row.get(7);
        if (!row.get(7).isNull())
            STUDENT.spec = std::string(row.get(7));
        if (!row.get(8).isNull())
            STUDENT.group_name = std::string(row.get(8));
        vector.push_back(STUDENT);
    }
}
void fetchAll_t(std::vector <teacher>& vector)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table = "teacher";
    Schema myDb = sess.getSchema("students_db", true);
    Table myTable = myDb.getTable(table);
    RowResult myRows = myTable.select("id_t", "name", "surname", "patr", "id_labg")\
        .execute();

    for (Row row : myRows.fetchAll())
    {
        teacher TEACHER;
        TEACHER.id_t = row.get(0);
        TEACHER.name = std::string(row.get(1));
        TEACHER.surname = std::string(row.get(2));
        if (!row.get(3).isNull())
            TEACHER.patronymic = std::string(row.get(3));
        if (!row.get(4).isNull())
            TEACHER.id_labg = row.get(4);
        vector.push_back(TEACHER);
    }
}

void fetchAll_labs(std::vector <laba>& vector)
{
    Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
    std::string table_str = "laba";
    Schema myDb = sess.getSchema("students_db", true);
    Table myTable = myDb.getTable(table_str);
    RowResult myRows = myTable.select("id_laba", "name", "id_block", "labs_direction").execute();

    for (Row row : myRows.fetchAll())
    {
        laba LABA;
        LABA.id_laba = row.get(0);
        if (!row.get(1).isNull())
            LABA.name = std::string(row.get(1));
        if (!row.get(2).isNull())
            LABA.id_block = row.get(2);
        if (!row.get(3).isNull())
            LABA.labs_direction = std::string(row.get(3));
        vector.push_back(LABA);
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
    std::string table_str = "student";
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
    std::string table_str = "teacher";
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
    std::string table_str = "group";
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

std::vector<std::string> get_Scheduler() {
    // get information about ALL
    std::vector <student> students;
    fetchAll_st(students);

    std::vector <teacher> teachers;
    fetchAll_t(teachers);

    std::vector <laba> labs;
    fetchAll_labs(labs);

    // get amount of students, teachers, groups
    int kolStudents = students.size();
    int kolTeachers = teachers.size();
    int kolLabs = teachers.size();

    // get true table order
    for (int i = 0; i < kolStudents; i++) {
        for (int j = i + 1; j < kolTeachers; j++) {
            if (students[i].spec == students[j].spec) {
                if (students[i].alive == 0 && students[j].alive == 1) {
                    if (students[i].group_name == students[j].group_name) {
                        SWAP(students[i], students[j]);
                    }
                    else if (students[i].group_name > students[j].group_name) {
                        if (students[i].surname > students[j].surname) {
                            SWAP(students[i], students[j]);
                        }
                        else if (students[i].surname == students[j].surname && students[i].name > students[j].name) {
                            SWAP(students[i], students[j]);
                        }
                        else if (students[i].surname == students[j].surname && students[i].name == students[j].name && students[i].patronymic > students[j].patronymic) {
                            SWAP(students[i], students[j]);
                        }
                    }
                }
                else if (students[i].alive == 1 && students[j].alive == 1 || students[i].alive == 0 && students[j].alive == 0) {
                    SWAP(students[i], students[j]);
                }
            }
            else if (students[i].spec > students[j].spec) {
                SWAP(students[i], students[j]);
            }
        }
    }

    // get Scheduler

    //// amount of students, who get different spec parameters
    //int counter_spec1 = 0, counter_spec2 = 0, counter_spec3 = 0, counter_spec4 = 0;

    //while (students[counter_spec2].spec == students[counter_spec1].spec) {
    //    counter_spec2++;
    //}
    //while (students[counter_spec2 + counter_spec3].spec == students[counter_spec2].spec) {
    //    counter_spec3++;
    //}
    //while (students[counter_spec2 + counter_spec3 + counter_spec4].spec == students[counter_spec3].spec) {
    //    counter_spec4++;
    //}

    // get amount of students, who get different alive parameter
    int counter_isAlive_spec1 = 0, counter_isntAlive_spec1 = 0, counter_isAlive_spec2 = 0, counter_isntAlive_spec2 = 0,
        counter_isAlive_spec3 = 0, counter_isntAlive_spec3 = 0, counter_isAlive_spec4 = 0, counter_isntAlive_spec4 = 0;

    while (students[counter_isAlive_spec1].alive != 0) {
        counter_isAlive_spec1++;
    }
    int index_isAlive_spec1 = 0;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1].alive != 1) {
        counter_isntAlive_spec1++;
    }
    int index_isntAlive_spec1 = counter_isAlive_spec1;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2].alive != 0) {
        counter_isAlive_spec2++;
    }
    int index_isAlive_spec2 = counter_isAlive_spec1 + counter_isntAlive_spec1;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2].alive != 1) {
        counter_isntAlive_spec2++;
    }
    int index_isntAlive_spec2 = counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3].alive != 0) {
        counter_isAlive_spec3++;
    }
    int index_isAlive_spec3 = counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3 + counter_isntAlive_spec3].alive != 1) {
        counter_isntAlive_spec3++;
    }
    int index_isntAlive_spec3 = counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3;

    while (students[counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3 + counter_isntAlive_spec3 + counter_isAlive_spec4].alive != 0) {
        counter_isAlive_spec4++;
    }
    int index_isAlive_spec4 = counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3 + counter_isntAlive_spec3;

    counter_isntAlive_spec4 = students.size() - (counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3 + counter_isntAlive_spec3 + counter_isAlive_spec4);
    int index_isntAlive_spec4 = counter_isAlive_spec1 + counter_isntAlive_spec1 + counter_isAlive_spec2 + counter_isntAlive_spec2
        + counter_isAlive_spec3 + counter_isntAlive_spec3 + counter_isAlive_spec4;

    // about time of work in lab
    int kolloc_time = 7;
    int kol_labs_semestr = 14;

    // DO IT!
    int time_hours_1 = NULL; int time_min_1 = NULL; int time_hours_2 = NULL; int time_min_2 = NULL;

    // get direction for this semester of study in lab
    std::string phys_direction = "MECH", pmf_direction = "TERM", astro_direction = "OPTC", chem_direction = "ELEC";

    // get amount of labs in any direction
    int index_lab_phys = 0, index_lab_pmf = 0, index_lab_astro = 0, index_lab_chem = 0;

    while (labs[index_lab_phys].labs_direction != phys_direction) {
        index_lab_phys++;
    }
    while (labs[index_lab_pmf].labs_direction != pmf_direction) {
        index_lab_pmf++;
    }
    while (labs[index_lab_astro].labs_direction != astro_direction) {
        index_lab_astro++;
    }
    while (labs[index_lab_chem].labs_direction != chem_direction) {
        index_lab_chem++;
    }

    // let's get amount of students in groups in any directions
    int kol_isAlive_in_group = (counter_isAlive_spec1 + counter_isAlive_spec2 + counter_isAlive_spec3 + counter_isAlive_spec4) / kolTeachers,
        kol_isntAlive_in_group = (counter_isntAlive_spec1 + counter_isntAlive_spec2 + counter_isntAlive_spec3 + counter_isntAlive_spec4) / kolTeachers,
        teachers_for_spec1 = (counter_isAlive_spec1 + counter_isntAlive_spec1) / 20,
        teachers_for_spec2 = (counter_isAlive_spec2 + counter_isntAlive_spec2) / 20,
        teachers_for_spec3 = (counter_isAlive_spec3 + counter_isntAlive_spec3) / 20,
        teachers_for_spec4 = (counter_isAlive_spec4 + counter_isntAlive_spec4) / 20;

    if (teachers_for_spec1 % 2 != 0) {
        teachers_for_spec1++;
    }
    if (teachers_for_spec2 % 2 != 0) {
        teachers_for_spec2++;
    }
    if (teachers_for_spec3 % 2 != 0) {
        teachers_for_spec3++;
    }
    if (teachers_for_spec4 % 2 != 0) {
        teachers_for_spec4++;
    }

    int students_for_group1 = (counter_isAlive_spec1 + counter_isntAlive_spec1) / teachers_for_spec1,
        students_for_group2 = (counter_isAlive_spec2 + counter_isntAlive_spec2) / teachers_for_spec2,
        students_for_group3 = (counter_isAlive_spec3 + counter_isntAlive_spec3) / teachers_for_spec3,
        students_for_group4 = (counter_isAlive_spec4 + counter_isntAlive_spec4) / teachers_for_spec4;

    // main getting scheduler
    std::vector <std::string> outScheduler;

    // writing about spec1
    for (int i = 0; i < teachers_for_spec1; i++) {
        outScheduler.push_back(teachers[i].surname);
        outScheduler.push_back(teachers[i].name);
        outScheduler.push_back(teachers[i].patronymic);

        for (int j = 0; j < counter_isAlive_spec1 / teachers_for_spec1; j++) {
            outScheduler.push_back(students[j + i * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * counter_isntAlive_spec1 % teachers_for_spec1].surname);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * counter_isntAlive_spec1 % teachers_for_spec1].name);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * counter_isntAlive_spec1 % teachers_for_spec1].patronymic);
        }

        if (i < counter_isAlive_spec1 % teachers_for_spec1) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + i * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].patronymic);
        }

        for (int j = 0; j < kol_isntAlive_in_group; j++) {
            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec1 % teachers_for_spec1)].surname);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec1 % teachers_for_spec1)].name);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec1 % teachers_for_spec1)].patronymic);
        }

        if (i < counter_isntAlive_spec1 % teachers_for_spec1) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + (i + 1) * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + (i + 1) * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec1 / teachers_for_spec1) + (i + 1) * (counter_isAlive_spec1 % teachers_for_spec1)
                + (i + 1) * (counter_isntAlive_spec1 / teachers_for_spec1) + i * (counter_isntAlive_spec1 % teachers_for_spec1)].patronymic);
        }
    }

    // writing about spec2
    for (int i = 0; i < teachers_for_spec2; i++) {
        outScheduler.push_back(teachers[i].surname);
        outScheduler.push_back(teachers[i].name);
        outScheduler.push_back(teachers[i].patronymic);

        for (int j = 0; j < counter_isAlive_spec2 / teachers_for_spec2; j++) {
            outScheduler.push_back(students[j + i * (counter_isAlive_spec1 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * counter_isntAlive_spec2 % teachers_for_spec2].surname);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec2 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * counter_isntAlive_spec2 % teachers_for_spec2].name);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec2 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * counter_isntAlive_spec2 % teachers_for_spec2].patronymic);
        }

        if (i < counter_isAlive_spec2 % teachers_for_spec2) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + i * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].patronymic);
        }

        for (int j = 0; j < kol_isntAlive_in_group; j++) {
            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec2 % teachers_for_spec2)].surname);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec2 % teachers_for_spec2)].name);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec2 % teachers_for_spec2)].patronymic);
        }

        if (i < counter_isntAlive_spec2 % teachers_for_spec2) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + (i + 1) * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + (i + 1) * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec2 / teachers_for_spec2) + (i + 1) * (counter_isAlive_spec2 % teachers_for_spec2)
                + (i + 1) * (counter_isntAlive_spec2 / teachers_for_spec2) + i * (counter_isntAlive_spec2 % teachers_for_spec2)].patronymic);
        }
    }

    // writing about spec3
    for (int i = 0; i < teachers_for_spec3; i++) {
        outScheduler.push_back(teachers[i].surname);
        outScheduler.push_back(teachers[i].name);
        outScheduler.push_back(teachers[i].patronymic);

        for (int j = 0; j < counter_isAlive_spec3 / teachers_for_spec3; j++) {
            outScheduler.push_back(students[j + i * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * counter_isntAlive_spec3 % teachers_for_spec3].surname);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * counter_isntAlive_spec3 % teachers_for_spec3].name);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * counter_isntAlive_spec3 % teachers_for_spec3].patronymic);
        }

        if (i < counter_isAlive_spec3 % teachers_for_spec3) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + i * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].patronymic);
        }

        for (int j = 0; j < kol_isntAlive_in_group; j++) {
            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec3 % teachers_for_spec3)].surname);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec3 % teachers_for_spec3)].name);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec3 % teachers_for_spec3)].patronymic);
        }

        if (i < counter_isntAlive_spec3 % teachers_for_spec3) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + (i + 1) * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + (i + 1) * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec3 / teachers_for_spec3) + (i + 1) * (counter_isAlive_spec3 % teachers_for_spec3)
                + (i + 1) * (counter_isntAlive_spec3 / teachers_for_spec3) + i * (counter_isntAlive_spec3 % teachers_for_spec3)].patronymic);
        }
    }

    // writing about spec4
    for (int i = 0; i < teachers_for_spec4; i++) {
        outScheduler.push_back(teachers[i].surname);
        outScheduler.push_back(teachers[i].name);
        outScheduler.push_back(teachers[i].patronymic);

        for (int j = 0; j < counter_isAlive_spec4 / teachers_for_spec4; j++) {
            outScheduler.push_back(students[j + i * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * counter_isntAlive_spec4 % teachers_for_spec4].surname);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * counter_isntAlive_spec4 % teachers_for_spec4].name);

            outScheduler.push_back(students[j + i * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * counter_isntAlive_spec4 % teachers_for_spec4].patronymic);
        }

        if (i < counter_isAlive_spec4 % teachers_for_spec4) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + i * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].patronymic);
        }

        for (int j = 0; j < kol_isntAlive_in_group; j++) {
            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec4 % teachers_for_spec4)].surname);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec4 % teachers_for_spec4)].name);

            outScheduler.push_back(students[j + (i + 1) * kol_isAlive_in_group + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + i * kol_isntAlive_in_group + i * (counter_isntAlive_spec4 % teachers_for_spec4)].patronymic);
        }

        if (i < counter_isntAlive_spec4 % teachers_for_spec4) {
            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + (i + 1) * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].surname);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + (i + 1) * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].name);

            outScheduler.push_back(students[(i + 1) * (counter_isAlive_spec4 / teachers_for_spec4) + (i + 1) * (counter_isAlive_spec4 % teachers_for_spec4)
                + (i + 1) * (counter_isntAlive_spec4 / teachers_for_spec4) + i * (counter_isntAlive_spec4 % teachers_for_spec4)].patronymic);
        }
    }

    outScheduler.push_back("0");

    return outScheduler;
}
