

//int main()
//{
//    std::string connectionString = "host=localhost port=5432 dbname=kursach user=postgres password =27240121";
//
//    try
//    {
//        pqxx::connection connectionObject(connectionString.c_str());
//        if (connectionObject.is_open()) {
//            std::cout << "Opened database successfully: " << connectionObject.dbname() << std::endl;
//        }
//        else {
//            std::cout << "Can't open database" << std::endl;
//            return 1;
//        }
//        pqxx::work worker(connectionObject);
//
//        /*pqxx::result response = worker.exec("SELECT * FROM users");
//
//        for (size_t i = 0; i < response.size(); i++)
//        {
//            std::cout << "Id: " << response[i][0] << " Username: " << response[i][1] << " Password: " << response[i][2] << " Email: " << response[i][3] << std::endl;
//        }*/
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << e.what() << std::endl;
//    }
//
//    system("pause");
//}