#pragma once

#include <pqxx/pqxx>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <format>
#include <iostream>
#include <Windows.h>
#include "pqxx/nontransaction"


namespace Kursachdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ForClient
	/// </summary>
	public ref class ForClient : public System::Windows::Forms::Form
	{
	public:
		pqxx::nontransaction* worker;

		ForClient(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForClient(pqxx::nontransaction *worker) {
			this->worker = worker;
			InitializeComponent();
		}
		bool check_name(std::string name) {
			for (auto c:name)
			{
				if ((int(c) < 65 || int(c) > 90) && (int(c) < 97 || int(c) > 122) && (int(c) != 32)) {
					return false;
				}
			}
			return true;

		}
		bool check_adres(std::string adres) {
			for (auto c : adres)
			{
				if ((int(c) < 65 || int(c) > 90) && (int(c) < 97 || int(c) > 122) && (int(c) < 48 || int(c) > 57) && (int(c) != 32)) {
					return false;
				}
			}
			return true;
		}

		bool isInteger(std::string str) {
			if (str.empty() && str.length() == 11) {
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
		~ForClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CourierTriger;
	private: System::Windows::Forms::Button^ Goods;
	private: System::Windows::Forms::Button^ Market;
	private: System::Windows::Forms::Button^ Order;
	private: System::Windows::Forms::Button^ Delivery;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ full_name;
	private: System::Windows::Forms::TextBox^ phone;
	private: System::Windows::Forms::TextBox^ adres;
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
			this->CourierTriger = (gcnew System::Windows::Forms::Button());
			this->Goods = (gcnew System::Windows::Forms::Button());
			this->Market = (gcnew System::Windows::Forms::Button());
			this->Order = (gcnew System::Windows::Forms::Button());
			this->Delivery = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->full_name = (gcnew System::Windows::Forms::TextBox());
			this->phone = (gcnew System::Windows::Forms::TextBox());
			this->adres = (gcnew System::Windows::Forms::TextBox());
			this->add_new = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// CourierTriger
			// 
			this->CourierTriger->Location = System::Drawing::Point(12, 445);
			this->CourierTriger->Name = L"CourierTriger";
			this->CourierTriger->Size = System::Drawing::Size(117, 34);
			this->CourierTriger->TabIndex = 0;
			this->CourierTriger->Text = L"Курьер";
			this->CourierTriger->UseVisualStyleBackColor = true;
			this->CourierTriger->Click += gcnew System::EventHandler(this, &ForClient::CourierTriger_Click);
			// 
			// Goods
			// 
			this->Goods->Location = System::Drawing::Point(135, 445);
			this->Goods->Name = L"Goods";
			this->Goods->Size = System::Drawing::Size(117, 34);
			this->Goods->TabIndex = 1;
			this->Goods->Text = L"Товар";
			this->Goods->UseVisualStyleBackColor = true;
			this->Goods->Click += gcnew System::EventHandler(this, &ForClient::Goods_Click);
			// 
			// Market
			// 
			this->Market->Location = System::Drawing::Point(258, 445);
			this->Market->Name = L"Market";
			this->Market->Size = System::Drawing::Size(117, 34);
			this->Market->TabIndex = 2;
			this->Market->Text = L"Магазин";
			this->Market->UseVisualStyleBackColor = true;
			this->Market->Click += gcnew System::EventHandler(this, &ForClient::Market_Click);
			// 
			// Order
			// 
			this->Order->Location = System::Drawing::Point(381, 445);
			this->Order->Name = L"Order";
			this->Order->Size = System::Drawing::Size(117, 34);
			this->Order->TabIndex = 3;
			this->Order->Text = L"Заказ";
			this->Order->UseVisualStyleBackColor = true;
			this->Order->Click += gcnew System::EventHandler(this, &ForClient::Order_Click);
			// 
			// Delivery
			// 
			this->Delivery->Location = System::Drawing::Point(504, 445);
			this->Delivery->Name = L"Delivery";
			this->Delivery->Size = System::Drawing::Size(117, 34);
			this->Delivery->TabIndex = 4;
			this->Delivery->Text = L"Доставка";
			this->Delivery->UseVisualStyleBackColor = true;
			this->Delivery->Click += gcnew System::EventHandler(this, &ForClient::Delivery_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ФИО Клиента";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(315, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Номер телефона клиента";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(200, 29);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Адрес доставки";
			// 
			// full_name
			// 
			this->full_name->Location = System::Drawing::Point(12, 64);
			this->full_name->Name = L"full_name";
			this->full_name->Size = System::Drawing::Size(330, 22);
			this->full_name->TabIndex = 8;
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(12, 121);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(330, 22);
			this->phone->TabIndex = 9;
			// 
			// adres
			// 
			this->adres->Location = System::Drawing::Point(12, 178);
			this->adres->Name = L"adres";
			this->adres->Size = System::Drawing::Size(330, 22);
			this->adres->TabIndex = 10;
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(12, 215);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(117, 37);
			this->add_new->TabIndex = 11;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForClient::add_new_Click);
			// 
			// ForClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->adres);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->full_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Delivery);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->Market);
			this->Controls->Add(this->Goods);
			this->Controls->Add(this->CourierTriger);
			this->Name = L"ForClient";
			this->Text = L"ForClient";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
private: System::Void CourierTriger_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Goods_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Market_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Order_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Delivery_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string fullname = msclr::interop::marshal_as<std::string>(full_name->Text);
	std::string phone_num = msclr::interop::marshal_as<std::string>(phone->Text);
	std::string client_addres = msclr::interop::marshal_as<std::string>(adres->Text);

	if (check_name(fullname) && check_adres(client_addres) && isInteger(phone_num)) {
		try {
			worker->exec(std::format("INSERT INTO clients VALUES ({},'{}','{}');", phone_num, fullname, client_addres));
			worker->exec("commit;");
			MessageBox::Show("Клиент Добавлен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (const std::exception& e)
		{
			MessageBox::Show("Добавление клиента с уже существующим номером", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	else {
		MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}
};
}
