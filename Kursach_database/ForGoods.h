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
	/// Сводка для ForGoods
	/// </summary>
	public ref class ForGoods : public System::Windows::Forms::Form
	{
	public:
		pqxx::nontransaction* worker;

		ForGoods(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForGoods(pqxx::nontransaction* worker) {
			this->worker = worker;
			InitializeComponent();
		}

		bool check_str(std::string str) {
			for (auto c : str)
			{
				if ((int(c) < 65 || int(c) > 90) && (int(c) < 97 || int(c) > 122) && (int(c) < 48 || int(c) > 57) && (int(c) != 32)) {
					return false;
				}
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
		~ForGoods()
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
	private: System::Windows::Forms::Button^ Market;
	private: System::Windows::Forms::Button^ Order;
	private: System::Windows::Forms::Button^ Delivery;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::TextBox^ firm;
	private: System::Windows::Forms::TextBox^ len;
	private: System::Windows::Forms::TextBox^ wid;
	private: System::Windows::Forms::TextBox^ power;
	private: System::Windows::Forms::TextBox^ color;
	private: System::Windows::Forms::TextBox^ price;
	private: System::Windows::Forms::TextBox^ warant;








	private: System::Windows::Forms::TextBox^ name;
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
			this->Market = (gcnew System::Windows::Forms::Button());
			this->Order = (gcnew System::Windows::Forms::Button());
			this->Delivery = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->model = (gcnew System::Windows::Forms::TextBox());
			this->firm = (gcnew System::Windows::Forms::TextBox());
			this->len = (gcnew System::Windows::Forms::TextBox());
			this->wid = (gcnew System::Windows::Forms::TextBox());
			this->power = (gcnew System::Windows::Forms::TextBox());
			this->color = (gcnew System::Windows::Forms::TextBox());
			this->price = (gcnew System::Windows::Forms::TextBox());
			this->warant = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->add_new = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Client
			// 
			this->Client->Location = System::Drawing::Point(12, 445);
			this->Client->Name = L"Client";
			this->Client->Size = System::Drawing::Size(117, 34);
			this->Client->TabIndex = 1;
			this->Client->Text = L"Клиент";
			this->Client->UseVisualStyleBackColor = true;
			this->Client->Click += gcnew System::EventHandler(this, &ForGoods::Client_Click);
			// 
			// Courier
			// 
			this->Courier->Location = System::Drawing::Point(135, 445);
			this->Courier->Name = L"Courier";
			this->Courier->Size = System::Drawing::Size(117, 34);
			this->Courier->TabIndex = 2;
			this->Courier->Text = L"Курьер";
			this->Courier->UseVisualStyleBackColor = true;
			this->Courier->Click += gcnew System::EventHandler(this, &ForGoods::Courier_Click);
			// 
			// Market
			// 
			this->Market->Location = System::Drawing::Point(258, 445);
			this->Market->Name = L"Market";
			this->Market->Size = System::Drawing::Size(117, 34);
			this->Market->TabIndex = 3;
			this->Market->Text = L"Магазин";
			this->Market->UseVisualStyleBackColor = true;
			this->Market->Click += gcnew System::EventHandler(this, &ForGoods::Market_Click);
			// 
			// Order
			// 
			this->Order->Location = System::Drawing::Point(381, 445);
			this->Order->Name = L"Order";
			this->Order->Size = System::Drawing::Size(117, 34);
			this->Order->TabIndex = 4;
			this->Order->Text = L"Заказ";
			this->Order->UseVisualStyleBackColor = true;
			this->Order->Click += gcnew System::EventHandler(this, &ForGoods::Order_Click);
			// 
			// Delivery
			// 
			this->Delivery->Location = System::Drawing::Point(504, 445);
			this->Delivery->Name = L"Delivery";
			this->Delivery->Size = System::Drawing::Size(117, 34);
			this->Delivery->TabIndex = 5;
			this->Delivery->Text = L"Доставка";
			this->Delivery->UseVisualStyleBackColor = true;
			this->Delivery->Click += gcnew System::EventHandler(this, &ForGoods::Delivery_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Название";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Модель";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(167, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Фирма";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(501, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Цвет";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(322, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Мощность";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(501, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(110, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Ширина Товара";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(322, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(98, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Длина товара";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(501, 155);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 16);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Гарантийный срок";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(322, 155);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(40, 16);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Цена";
			// 
			// model
			// 
			this->model->Location = System::Drawing::Point(12, 32);
			this->model->Name = L"model";
			this->model->Size = System::Drawing::Size(100, 22);
			this->model->TabIndex = 15;
			// 
			// firm
			// 
			this->firm->Location = System::Drawing::Point(170, 32);
			this->firm->Name = L"firm";
			this->firm->Size = System::Drawing::Size(100, 22);
			this->firm->TabIndex = 16;
			// 
			// len
			// 
			this->len->Location = System::Drawing::Point(325, 32);
			this->len->Name = L"len";
			this->len->Size = System::Drawing::Size(100, 22);
			this->len->TabIndex = 17;
			// 
			// wid
			// 
			this->wid->Location = System::Drawing::Point(504, 32);
			this->wid->Name = L"wid";
			this->wid->Size = System::Drawing::Size(100, 22);
			this->wid->TabIndex = 18;
			// 
			// power
			// 
			this->power->Location = System::Drawing::Point(325, 104);
			this->power->Name = L"power";
			this->power->Size = System::Drawing::Size(100, 22);
			this->power->TabIndex = 19;
			// 
			// color
			// 
			this->color->Location = System::Drawing::Point(504, 104);
			this->color->Name = L"color";
			this->color->Size = System::Drawing::Size(100, 22);
			this->color->TabIndex = 20;
			// 
			// price
			// 
			this->price->Location = System::Drawing::Point(325, 174);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(100, 22);
			this->price->TabIndex = 21;
			// 
			// warant
			// 
			this->warant->Location = System::Drawing::Point(504, 174);
			this->warant->Name = L"warant";
			this->warant->Size = System::Drawing::Size(100, 22);
			this->warant->TabIndex = 22;
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(12, 104);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(258, 22);
			this->name->TabIndex = 23;
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(16, 174);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(219, 23);
			this->add_new->TabIndex = 24;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForGoods::add_new_Click);
			// 
			// ForGoods
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->name);
			this->Controls->Add(this->warant);
			this->Controls->Add(this->price);
			this->Controls->Add(this->color);
			this->Controls->Add(this->power);
			this->Controls->Add(this->wid);
			this->Controls->Add(this->len);
			this->Controls->Add(this->firm);
			this->Controls->Add(this->model);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Delivery);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->Market);
			this->Controls->Add(this->Courier);
			this->Controls->Add(this->Client);
			this->Name = L"ForGoods";
			this->Text = L"ForGoods";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Courier_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Market_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Order_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delivery_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string model_n = msclr::interop::marshal_as<std::string>(model->Text);
		std::string firm_n = msclr::interop::marshal_as<std::string>(firm->Text);
		std::string name_n = msclr::interop::marshal_as<std::string>(name->Text);
		std::string len_n = msclr::interop::marshal_as<std::string>(len->Text);
		std::string wid_n = msclr::interop::marshal_as<std::string>(wid->Text);
		std::string power_n = msclr::interop::marshal_as<std::string>(power->Text);
		std::string color_n = msclr::interop::marshal_as<std::string>(color->Text);
		std::string price_n = msclr::interop::marshal_as<std::string>(price->Text);
		std::string warant_n = msclr::interop::marshal_as<std::string>(warant->Text);
		
			if (isInteger(price_n) && isInteger(warant_n) && isInteger(len_n) && isInteger(power_n) && isInteger(wid_n) && check_str(model_n) && check_str(firm_n) && check_str(name_n) && check_str(color_n)) {
				worker->exec(std::format("INSERT INTO goods (name_of_goods, firm, model, length_of_goods, width_of_goods, power_of_goods, color, price, warranty_period) VALUES ('{}','{}','{}',{},{},{},'{}',{},{});", name_n, firm_n, model_n, len_n, wid_n, power_n, color_n, price_n, warant_n));
				worker->exec("commit;");
				MessageBox::Show("Товар Добавлен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Проверьте данные", "Ошибка в данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
	}
};
}
