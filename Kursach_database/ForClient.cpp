#include "ForClient.h"

#include "ForCourier.h"
#include "ForGoods.h"
#include "ForMarkets.h"
#include "ForOrder.h"
#include "ForDelivery.h"
#include "pqxx/nontransaction"

using namespace System;
using namespace System::Windows::Forms;

namespace Kursachdatabase {
	System::Void ForClient::CourierTriger_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ForCourier^ window = gcnew ForCourier(this->worker);
		window->Show();
		this->Hide();
	}
	System::Void ForClient::Goods_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ForGoods^ window = gcnew ForGoods(this->worker);
		window->Show();
		this->Hide();
	}
	System::Void ForClient::Market_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ForMarkets^ window = gcnew ForMarkets(this->worker);
		window->Show();
		this->Hide();
	}
	System::Void ForClient::Order_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ForOrder^ window = gcnew ForOrder(this->worker);
		window->Show();
		this->Hide();
	}
	System::Void ForClient::Delivery_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ForDelivery^ window = gcnew ForDelivery(this->worker);
		window->Show();
		this->Hide();
	}
}

[STAThreadAttribute]
int main(array<String^>^ args) {
	setlocale(LC_ALL, "RU");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	std::string connectionString = "host=localhost port=5432 dbname=kursach user=postgres password =27240121";

	try
	{
		pqxx::connection connectionObject(connectionString.c_str());
		if (connectionObject.is_open()) {
			std::cout << "Opened database successfully: " << connectionObject.dbname() << std::endl;
		}
		else {
			std::cout << "Can't open database" << std::endl;
			return 1;
		}
		pqxx::nontransaction worker(connectionObject);
		Kursachdatabase::ForClient form(&worker);
		Application::Run(% form);

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	
	
}
