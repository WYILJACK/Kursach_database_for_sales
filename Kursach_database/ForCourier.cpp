#include "ForCourier.h"

#include "ForClient.h"
#include "ForGoods.h"
#include "ForMarkets.h"
#include "ForOrder.h"
#include "ForDelivery.h"

System::Void Kursachdatabase::ForCourier::Client_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForClient^ window = gcnew ForClient(this->worker);
	window->Show();
	worker = nullptr;
	this->Close();
}

System::Void Kursachdatabase::ForCourier::Goods_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForGoods^ window = gcnew ForGoods(this->worker);
	window->Show();
	worker = nullptr;
	this->Close();
}

System::Void Kursachdatabase::ForCourier::Market_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForMarkets^ window = gcnew ForMarkets(this->worker);
	window->Show();
	worker = nullptr;
	this->Close();
}

System::Void Kursachdatabase::ForCourier::Order_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForOrder^ window = gcnew ForOrder(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForCourier::Delivery_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForDelivery^ window = gcnew ForDelivery(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForCourier::add_new_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string full_name = msclr::interop::marshal_as<std::string>(fullname->Text);
	std::string phone_num = msclr::interop::marshal_as<std::string>(phone->Text);

	if (check_name(full_name) && isInteger(phone_num)) {
		try {
			worker->exec(std::format("INSERT INTO courier VALUES ({},'{}');", phone_num, full_name));
			worker->exec("commit;");
			MessageBox::Show("Курьер Добавлен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (const std::exception& e)
			    {
			MessageBox::Show("Добавление курьера с уже существующим номером телефона", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
		
	}
	else {
		MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}