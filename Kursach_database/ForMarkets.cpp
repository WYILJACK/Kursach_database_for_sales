#include "ForMarkets.h"

#include "ForClient.h"
#include "ForCourier.h"
#include "ForGoods.h"
#include "ForOrder.h"
#include "ForDelivery.h"


System::Void Kursachdatabase::ForMarkets::Client_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForClient^ window = gcnew ForClient(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForMarkets::Goods_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForGoods^ window = gcnew ForGoods(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForMarkets::Courier_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForCourier^ window = gcnew ForCourier(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForMarkets::Order_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForOrder^ window = gcnew ForOrder(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForMarkets::Delivery_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForDelivery^ window = gcnew ForDelivery(this->worker);
	window->Show();
	this->Close();
}