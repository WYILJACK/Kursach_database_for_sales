#pragma once

#include <pqxx/pqxx>
#include <format>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <iostream>
#include "pqxx/nontransaction"


namespace Kursachdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ForMarkets
	/// </summary>
	public ref class ForMarkets : public System::Windows::Forms::Form
	{
	public:
		pqxx::nontransaction* worker;

		ForMarkets(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForMarkets(pqxx::nontransaction* worker) {
			this->worker = worker;
			InitializeComponent();
		}

		bool check_adres(std::string adres) {
			for (auto c : adres)
			{
				if ((int(c) <= 65 || int(c) >= 90) && (int(c) <= 97 || int(c) >= 122) && (int(c) <= 48 || int(c) >= 57) && (int(c) != 32)) {
					return false;
				}
			}
			return true;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ForMarkets()
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
	private: System::Windows::Forms::Button^ Order;
	private: System::Windows::Forms::Button^ Delivery;
	private: System::Windows::Forms::Label^ adres;
	private: System::Windows::Forms::TextBox^ eadres;
	private: System::Windows::Forms::TextBox^ adress;

	private: System::Windows::Forms::Label^ lable;
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
			this->Order = (gcnew System::Windows::Forms::Button());
			this->Delivery = (gcnew System::Windows::Forms::Button());
			this->adres = (gcnew System::Windows::Forms::Label());
			this->eadres = (gcnew System::Windows::Forms::TextBox());
			this->adress = (gcnew System::Windows::Forms::TextBox());
			this->lable = (gcnew System::Windows::Forms::Label());
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
			this->Client->Click += gcnew System::EventHandler(this, &ForMarkets::Client_Click);
			// 
			// Courier
			// 
			this->Courier->Location = System::Drawing::Point(135, 445);
			this->Courier->Name = L"Courier";
			this->Courier->Size = System::Drawing::Size(117, 34);
			this->Courier->TabIndex = 3;
			this->Courier->Text = L"Курьер";
			this->Courier->UseVisualStyleBackColor = true;
			this->Courier->Click += gcnew System::EventHandler(this, &ForMarkets::Courier_Click);
			// 
			// Goods
			// 
			this->Goods->Location = System::Drawing::Point(258, 445);
			this->Goods->Name = L"Goods";
			this->Goods->Size = System::Drawing::Size(117, 34);
			this->Goods->TabIndex = 4;
			this->Goods->Text = L"Товары";
			this->Goods->UseVisualStyleBackColor = true;
			this->Goods->Click += gcnew System::EventHandler(this, &ForMarkets::Goods_Click);
			// 
			// Order
			// 
			this->Order->Location = System::Drawing::Point(381, 445);
			this->Order->Name = L"Order";
			this->Order->Size = System::Drawing::Size(117, 34);
			this->Order->TabIndex = 5;
			this->Order->Text = L"Заказ";
			this->Order->UseVisualStyleBackColor = true;
			this->Order->Click += gcnew System::EventHandler(this, &ForMarkets::Order_Click);
			// 
			// Delivery
			// 
			this->Delivery->Location = System::Drawing::Point(504, 445);
			this->Delivery->Name = L"Delivery";
			this->Delivery->Size = System::Drawing::Size(117, 34);
			this->Delivery->TabIndex = 6;
			this->Delivery->Text = L"Доставка";
			this->Delivery->UseVisualStyleBackColor = true;
			this->Delivery->Click += gcnew System::EventHandler(this, &ForMarkets::Delivery_Click);
			// 
			// adres
			// 
			this->adres->AutoSize = true;
			this->adres->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->adres->Location = System::Drawing::Point(24, 88);
			this->adres->Name = L"adres";
			this->adres->Size = System::Drawing::Size(176, 29);
			this->adres->TabIndex = 7;
			this->adres->Text = L"Адрес склада";
			// 
			// eadres
			// 
			this->eadres->Location = System::Drawing::Point(29, 63);
			this->eadres->Name = L"eadres";
			this->eadres->Size = System::Drawing::Size(321, 22);
			this->eadres->TabIndex = 8;
			// 
			// adress
			// 
			this->adress->Location = System::Drawing::Point(29, 129);
			this->adress->Name = L"adress";
			this->adress->Size = System::Drawing::Size(321, 22);
			this->adress->TabIndex = 9;
			// 
			// lable
			// 
			this->lable->AutoSize = true;
			this->lable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lable->Location = System::Drawing::Point(26, 31);
			this->lable->Name = L"lable";
			this->lable->Size = System::Drawing::Size(248, 29);
			this->lable->TabIndex = 10;
			this->lable->Text = L"Электронный адрес";
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(29, 169);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(100, 48);
			this->add_new->TabIndex = 11;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForMarkets::add_new_Click);
			// 
			// ForMarkets
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->lable);
			this->Controls->Add(this->adress);
			this->Controls->Add(this->eadres);
			this->Controls->Add(this->adres);
			this->Controls->Add(this->Delivery);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->Goods);
			this->Controls->Add(this->Courier);
			this->Controls->Add(this->Client);
			this->Name = L"ForMarkets";
			this->Text = L"ForMarkets";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Courier_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Goods_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Order_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delivery_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string eadres_n = msclr::interop::marshal_as<std::string>(eadres->Text);
		std::string adress_n = msclr::interop::marshal_as<std::string>(adress->Text);

		if (check_adres(adress_n)) {
			worker->exec(std::format("INSERT INTO online_stores (email, warehouse_address) VALUES ('{}','{}');",eadres_n,adress_n));
			worker->exec("commit;");
			MessageBox::Show("Магазин Добавлен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
