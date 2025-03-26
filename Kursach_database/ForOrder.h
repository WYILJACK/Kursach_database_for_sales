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
	/// Сводка для ForOrder
	/// </summary>
	public ref class ForOrder : public System::Windows::Forms::Form
	{
	public:
		
		pqxx::nontransaction* worker;

		ForOrder(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForOrder(pqxx::nontransaction* worker) {
			InitializeComponent();
			this->worker = worker;
			pqxx::result result_for_market = worker->exec("SELECT store_id FROM online_stores");
			pqxx::result result_for_good = worker->exec("SELECT goods_id FROM goods");
			pqxx::result result_for_phone = worker->exec("SELECT phone_number FROM clients");

			for (auto row : result_for_phone) {
				for (auto res : row) {
					phone->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}

			for (auto row : result_for_good) {
				for (auto res : row) {
					id_goods->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}

			for (auto row : result_for_market) {
				for (auto res : row) {
					id_market->Items->Add(msclr::interop::marshal_as<String^>(res.c_str()));
				}
			}

		}

		bool check_date(std::string str) {
			std::string buf = "";
			int flag = 0;

			for (auto l : str) {
				if (flag == 2 && l!=':') {
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

				if (!isdigit(l) && flag!=2 && flag!=5) { return false; }


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

				if (!isdigit(l) && flag!=2) { return false; }


				buf += l;
				flag++;
			}
			return true;

		}

		bool isInteger(std::string str) {
			if (str.empty()) {
				return false;
			}
			for (char c : str) {
				if (!isdigit(c)) {
					return false;
				}
			}
			return true;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ForOrder()
		{
			worker = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Client;
	protected:
	private: System::Windows::Forms::Button^ Courier;
	private: System::Windows::Forms::Button^ Goods;
	private: System::Windows::Forms::Button^ Market;
	private: System::Windows::Forms::Button^ Delivery;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ id_market;
	private: System::Windows::Forms::ComboBox^ id_goods;
	private: System::Windows::Forms::ComboBox^ phone;
	private: System::Windows::Forms::TextBox^ date;
	private: System::Windows::Forms::TextBox^ time;
	private: System::Windows::Forms::TextBox^ count;
	private: System::Windows::Forms::Button^ add_new;






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
			this->Delivery = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->id_market = (gcnew System::Windows::Forms::ComboBox());
			this->id_goods = (gcnew System::Windows::Forms::ComboBox());
			this->phone = (gcnew System::Windows::Forms::ComboBox());
			this->date = (gcnew System::Windows::Forms::TextBox());
			this->time = (gcnew System::Windows::Forms::TextBox());
			this->count = (gcnew System::Windows::Forms::TextBox());
			this->add_new = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Client
			// 
			this->Client->Location = System::Drawing::Point(12, 445);
			this->Client->Name = L"Client";
			this->Client->Size = System::Drawing::Size(117, 34);
			this->Client->TabIndex = 2;
			this->Client->Text = L"Клиент";
			this->Client->UseVisualStyleBackColor = true;
			this->Client->Click += gcnew System::EventHandler(this, &ForOrder::Client_Click);
			// 
			// Courier
			// 
			this->Courier->Location = System::Drawing::Point(135, 445);
			this->Courier->Name = L"Courier";
			this->Courier->Size = System::Drawing::Size(117, 34);
			this->Courier->TabIndex = 3;
			this->Courier->Text = L"Курьер";
			this->Courier->UseVisualStyleBackColor = true;
			this->Courier->Click += gcnew System::EventHandler(this, &ForOrder::Courier_Click);
			// 
			// Goods
			// 
			this->Goods->Location = System::Drawing::Point(258, 445);
			this->Goods->Name = L"Goods";
			this->Goods->Size = System::Drawing::Size(117, 34);
			this->Goods->TabIndex = 4;
			this->Goods->Text = L"Товар";
			this->Goods->UseVisualStyleBackColor = true;
			this->Goods->Click += gcnew System::EventHandler(this, &ForOrder::Goods_Click);
			// 
			// Market
			// 
			this->Market->Location = System::Drawing::Point(381, 445);
			this->Market->Name = L"Market";
			this->Market->Size = System::Drawing::Size(117, 34);
			this->Market->TabIndex = 5;
			this->Market->Text = L"Магазин";
			this->Market->UseVisualStyleBackColor = true;
			this->Market->Click += gcnew System::EventHandler(this, &ForOrder::Market_Click);
			// 
			// Delivery
			// 
			this->Delivery->Location = System::Drawing::Point(504, 445);
			this->Delivery->Name = L"Delivery";
			this->Delivery->Size = System::Drawing::Size(117, 34);
			this->Delivery->TabIndex = 6;
			this->Delivery->Text = L"Доставка";
			this->Delivery->UseVisualStyleBackColor = true;
			this->Delivery->Click += gcnew System::EventHandler(this, &ForOrder::Delivery_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 16);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Код магазина";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Дата";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Количество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(208, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Код товара";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(208, 82);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Время";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(208, 137);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Номер телефона";
			// 
			// id_market
			// 
			this->id_market->FormattingEnabled = true;
			this->id_market->Location = System::Drawing::Point(13, 45);
			this->id_market->Name = L"id_market";
			this->id_market->Size = System::Drawing::Size(121, 24);
			this->id_market->TabIndex = 13;
			// 
			// id_goods
			// 
			this->id_goods->FormattingEnabled = true;
			this->id_goods->Location = System::Drawing::Point(211, 45);
			this->id_goods->Name = L"id_goods";
			this->id_goods->Size = System::Drawing::Size(121, 24);
			this->id_goods->TabIndex = 14;
			// 
			// phone
			// 
			this->phone->FormattingEnabled = true;
			this->phone->Location = System::Drawing::Point(211, 156);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(121, 24);
			this->phone->TabIndex = 15;
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(13, 101);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(121, 22);
			this->date->TabIndex = 16;
			// 
			// time
			// 
			this->time->Location = System::Drawing::Point(211, 101);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(121, 22);
			this->time->TabIndex = 17;
			// 
			// count
			// 
			this->count->Location = System::Drawing::Point(13, 156);
			this->count->Name = L"count";
			this->count->Size = System::Drawing::Size(121, 22);
			this->count->TabIndex = 18;
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(13, 193);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(121, 23);
			this->add_new->TabIndex = 19;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForOrder::add_new_Click);
			// 
			// ForOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->count);
			this->Controls->Add(this->time);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->id_goods);
			this->Controls->Add(this->id_market);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Delivery);
			this->Controls->Add(this->Market);
			this->Controls->Add(this->Goods);
			this->Controls->Add(this->Courier);
			this->Controls->Add(this->Client);
			this->Name = L"ForOrder";
			this->Text = L"ForOrder";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Courier_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Goods_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Market_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delivery_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string date_n = msclr::interop::marshal_as<std::string>(date->Text);
		std::string time_n = msclr::interop::marshal_as<std::string>(time->Text);
		std::string id_market_n = msclr::interop::marshal_as<std::string>(id_market->Text);
		std::string id_goods_n = msclr::interop::marshal_as<std::string>(id_goods->Text);
		std::string phone_num = msclr::interop::marshal_as<std::string>(phone->Text);
		std::string count_n = msclr::interop::marshal_as<std::string>(count->Text);

		if (check_date(date_n) && check_time(time_n) && isInteger(count_n)) {
			worker->exec(std::format("INSERT INTO orders (store_id, goods_id, date, time, count, client_phone) VALUES ({},{},'{}-{}-{}','{}:{}:00',{},{});", id_market_n, id_goods_n, date_n.substr(6,4), date_n.substr(0,2), date_n.substr(3,2), time_n.substr(0,2), time_n.substr(3,2), count_n, phone_num));
			worker->exec("commit;");
			MessageBox::Show("Заказ Добавлен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
