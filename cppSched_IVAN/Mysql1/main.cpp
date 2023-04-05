#include "connect.h"


int main()
{
    try
    {

       // student karim{ "Karim", "Nigmatulin", "Rinatovich", "st164970",1,2 };
       // teacher teach{ "Tayler","Derden" };
       // laba do5{ "do5",3 };
        
       // group GR2018{ 2018,2 };
       // std::vector<student> V;
       // add_st(karim);
        //fetchAll_st(V);
       // std::string id;
        //std::cin >> id;
       // delete_st(id);
        
        std::vector<std::string> OUT;
        OUT = get_Scheduler();
        for (int i = 0; i < OUT.size(); i++)
        {
            std::cout << OUT[i]<< std::endl;
        }
    }
    catch (const mysqlx::Error& err)
    {
        cout << "ERROR: " << err << endl;
        return 1;
    }
    catch (std::exception& ex)
    {
        cout << "STD EXCEPTION: " << ex.what() << endl;
        return 2;
    }
    catch (const char* ex)
    {
        cout << "EXCEPTION: " << ex << endl;
        return 3;
    }
}
