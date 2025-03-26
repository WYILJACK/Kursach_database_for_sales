#include "ForDelivery.h"

#include "ForClient.h"
#include "ForCourier.h"
#include "ForGoods.h"
#include "ForMarkets.h"
#include "ForOrder.h"


System::Void Kursachdatabase::ForDelivery::Client_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForClient^ window = gcnew ForClient(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForDelivery::Goods_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForGoods^ window = gcnew ForGoods(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForDelivery::Market_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForMarkets^ window = gcnew ForMarkets(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForDelivery::Order_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForOrder^ window = gcnew ForOrder(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForDelivery::Courier_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForCourier^ window = gcnew ForCourier(this->worker);
	window->Show();
	this->Close();
}