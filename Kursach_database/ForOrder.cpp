#include "ForOrder.h"

#include "ForClient.h"
#include "ForCourier.h"
#include "ForGoods.h"
#include "ForMarkets.h"
#include "ForDelivery.h"


System::Void Kursachdatabase::ForOrder::Client_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForClient^ window = gcnew ForClient(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForOrder::Goods_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForGoods^ window = gcnew ForGoods(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForOrder::Market_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForMarkets^ window = gcnew ForMarkets(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForOrder::Courier_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForCourier^ window = gcnew ForCourier(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForOrder::Delivery_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForDelivery^ window = gcnew ForDelivery(this->worker);
	window->Show();
	this->Close();
}