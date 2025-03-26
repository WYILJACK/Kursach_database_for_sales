#pragma once

#include <pqxx/pqxx>
#include <iostream>
#include <format>
#include <msclr\marshal_cppstd.h>
#include "pqxx/nontransaction"


namespace Kursachdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ForDelivery
	/// </summary>
	public ref class ForDelivery : public System::Windows::Forms::Form
	{
	public:
		pqxx::nontransaction * worker;

		ForDelivery(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForDelivery(pqxx::nontransaction* worker) {
			this->worker = worker;
			InitializeComponent();

			pqxx::result result_for_orders = worker->exec("SELECT order_id FROM orders");
			pqxx::result result_for_clients = worker->exec("SELECT phone_number FROM clients");
			pqxx::result result_for_courier = worker->exec("SELECT phone_number FROM courier");

			for (auto row : result_for_orders) {
				for (auto res : row) {
					id_order->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}

			for (auto row : result_for_clients) {
				for (auto res : row) {
					phone_client->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}

			for (auto row : result_for_courier) {
				for (auto res : row) {
					phone_courier->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}
		}

		bool check_date(std::string str) {
			std::string buf = "";
			int flag = 0;

			for (auto l : str) {
				if (flag == 2 && l != ':') {
					return false;
				}
				else if (flag == 2) {
					buf = "";
					flag++;
					continue;
				}

				if (flag == 5 && l != ':') {
					return false;
				}
				else if (flag == 5) {
					buf = "";
					flag++;
					continue;
				}

				if (!isdigit(l) && flag != 2 && flag != 5) { return false; }


				buf += l;
				flag++;
			}
			return true;
		}

		bool check_time(std::string str) {
			std::string buf = "";
			int flag = 0;

			for (auto l : str) {
				if (flag == 2 && l != ':') {
					return false;
				}
				else if (flag == 2) {
					buf = "";
					flag++;
					continue;
				}

				if (!isdigit(l) && flag != 2) { return false; }


				buf += l;
				flag++;
			}
			return true;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ForDelivery()
		{
			worker = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Client;
	private: System::Windows::Forms::Button^ Courier;
	private: System::Windows::Forms::Button^ Goods;
	private: System::Windows::Forms::Button^ Market;
	private: System::Windows::Forms::Button^ Order;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ phone_client;
	private: System::Windows::Forms::ComboBox^ phone_courier;
	private: System::Windows::Forms::ComboBox^ id_order;
	private: System::Windows::Forms::TextBox^ date;
	private: System::Windows::Forms::TextBox^ time;
	private: System::Windows::Forms::Button^ add_new;

	protected:

	protected:





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Client = (gcnew System::Windows::Forms::Button());
			this->Courier = (gcnew System::Windows::Forms::Button());
			this->Goods = (gcnew System::Windows::Forms::Button());
			this->Market = (gcnew System::Windows::Forms::Button());
			this->Order = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->phone_client = (gcnew System::Windows::Forms::ComboBox());
			this->phone_courier = (gcnew System::Windows::Forms::ComboBox());
			this->id_order = (gcnew System::Windows::Forms::ComboBox());
			this->date = (gcnew System::Windows::Forms::TextBox());
			this->time = (gcnew System::Windows::Forms::TextBox());
			this->add_new = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Client
			// 
			this->Client->Location = System::Drawing::Point(12, 445);
			this->Client->Name = L"Client";
			this->Client->Size = System::Drawing::Size(117, 34);
			this->Client->TabIndex = 0;
			this->Client->Text = L"Клиент";
			this->Client->UseVisualStyleBackColor = true;
			this->Client->Click += gcnew System::EventHandler(this, &ForDelivery::Client_Click);
			// 
			// Courier
			// 
			this->Courier->Location = System::Drawing::Point(135, 445);
			this->Courier->Name = L"Courier";
			this->Courier->Size = System::Drawing::Size(117, 34);
			this->Courier->TabIndex = 1;
			this->Courier->Text = L"Курьер";
			this->Courier->UseVisualStyleBackColor = true;
			this->Courier->Click += gcnew System::EventHandler(this, &ForDelivery::Courier_Click);
			// 
			// Goods
			// 
			this->Goods->Location = System::Drawing::Point(258, 445);
			this->Goods->Name = L"Goods";
			this->Goods->Size = System::Drawing::Size(117, 34);
			this->Goods->TabIndex = 2;
			this->Goods->Text = L"Товары";
			this->Goods->UseVisualStyleBackColor = true;
			this->Goods->Click += gcnew System::EventHandler(this, &ForDelivery::Goods_Click);
			// 
			// Market
			// 
			this->Market->Location = System::Drawing::Point(381, 445);
			this->Market->Name = L"Market";
			this->Market->Size = System::Drawing::Size(117, 34);
			this->Market->TabIndex = 3;
			this->Market->Text = L"Магазин";
			this->Market->UseVisualStyleBackColor = true;
			this->Market->Click += gcnew System::EventHandler(this, &ForDelivery::Market_Click);
			// 
			// Order
			// 
			this->Order->Location = System::Drawing::Point(504, 445);
			this->Order->Name = L"Order";
			this->Order->Size = System::Drawing::Size(117, 34);
			this->Order->TabIndex = 4;
			this->Order->Text = L"Заказ";
			this->Order->UseVisualStyleBackColor = true;
			this->Order->Click += gcnew System::EventHandler(this, &ForDelivery::Order_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Код заказа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(200, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Дата доставки";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(386, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Время доставки";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 150);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Номер телефона клиента";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(268, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(176, 16);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Номер телефона курьера";
			// 
			// phone_client
			// 
			this->phone_client->FormattingEnabled = true;
			this->phone_client->Location = System::Drawing::Point(25, 169);
			this->phone_client->Name = L"phone_client";
			this->phone_client->Size = System::Drawing::Size(173, 24);
			this->phone_client->TabIndex = 10;
			// 
			// phone_courier
			// 
			this->phone_courier->FormattingEnabled = true;
			this->phone_courier->Location = System::Drawing::Point(271, 169);
			this->phone_courier->Name = L"phone_courier";
			this->phone_courier->Size = System::Drawing::Size(173, 24);
			this->phone_courier->TabIndex = 11;
			// 
			// id_order
			// 
			this->id_order->FormattingEnabled = true;
			this->id_order->Location = System::Drawing::Point(25, 50);
			this->id_order->Name = L"id_order";
			this->id_order->Size = System::Drawing::Size(133, 24);
			this->id_order->TabIndex = 12;
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(203, 52);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(122, 22);
			this->date->TabIndex = 13;
			// 
			// time
			// 
			this->time->Location = System::Drawing::Point(389, 52);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(122, 22);
			this->time->TabIndex = 14;
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(25, 218);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(117, 50);
			this->add_new->TabIndex = 15;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForDelivery::add_new_Click);
			// 
			// ForDelivery
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->time);
			this->Controls->Add(this->date);
			this->Controls->Add(this->id_order);
			this->Controls->Add(this->phone_courier);
			this->Controls->Add(this->phone_client);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->Market);
			this->Controls->Add(this->Goods);
			this->Controls->Add(this->Courier);
			this->Controls->Add(this->Client);
			this->Name = L"ForDelivery";
			this->Text = L"ForDelivery";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Courier_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Goods_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Market_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Order_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string date_n = msclr::interop::marshal_as<std::string>(date->Text);
		std::string time_n = msclr::interop::marshal_as<std::string>(time->Text);
		std::string id_order_n = msclr::interop::marshal_as<std::string>(id_order->Text);
		std::string phone_client_n = msclr::interop::marshal_as<std::string>(phone_client->Text);
		std::string phone_courier_n = msclr::interop::marshal_as<std::string>(phone_courier->Text);

		if (check_date(date_n) && check_time(time_n)) {
			worker->exec(std::format("INSERT INTO delivery (orders_id, date_of_delivery, time_of_delivery, client_number, courier_number) VALUES ({},'{}-{}-{}','{}:{}:00',{},{});", id_order_n, date_n.substr(6, 4), date_n.substr(0, 2), date_n.substr(3, 2), time_n.substr(0, 2), time_n.substr(3, 2), phone_client_n, phone_courier_n));
			worker->exec("commit;");
			MessageBox::Show("Доставка Добавлена", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
