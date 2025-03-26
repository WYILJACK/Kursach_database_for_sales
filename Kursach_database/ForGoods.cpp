#include "ForGoods.h"

#include "ForClient.h"
#include "ForCourier.h"
#include "ForMarkets.h"
#include "ForOrder.h"
#include "ForDelivery.h"


System::Void Kursachdatabase::ForGoods::Client_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForClient^ window = gcnew ForClient(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForGoods::Courier_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForCourier^ window = gcnew ForCourier(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForGoods::Market_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForMarkets^ window = gcnew ForMarkets(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForGoods::Order_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForOrder^ window = gcnew ForOrder(this->worker);
	window->Show();
	this->Close();
}

System::Void Kursachdatabase::ForGoods::Delivery_Click(System::Object^ sender, System::EventArgs^ e)
{
	ForDelivery^ window = gcnew ForDelivery(this->worker);
	window->Show();
	this->Close();
}