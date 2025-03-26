#pragma once

#include <pqxx/pqxx>
#include <format>
#include <string>
#include "pqxx/nontransaction"


namespace Kursachdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ForCourier
	/// </summary>
	public ref class ForCourier : public System::Windows::Forms::Form
	{
	public:
		pqxx::nontransaction* worker;

		ForCourier(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ForCourier(pqxx::nontransaction* worker) {
			this->worker = worker;
			InitializeComponent();
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

		bool check_name(std::string name) {
			for (auto c : name)
			{
				if ((int(c) < 65 || int(c) > 90) && (int(c) < 97 || int(c) > 122) && (int(c) != 32)) {
					return false;
				}
			}
			return true;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ForCourier()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Client;
	protected:

	private: System::Windows::Forms::Button^ Goods;
	private: System::Windows::Forms::Button^ Market;
	private: System::Windows::Forms::Button^ Order;
	private: System::Windows::Forms::Button^ Delivery;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ fullname;
	private: System::Windows::Forms::TextBox^ phone;
	private: System::Windows::Forms::Button^ add_new;







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
			this->Goods = (gcnew System::Windows::Forms::Button());
			this->Market = (gcnew System::Windows::Forms::Button());
			this->Order = (gcnew System::Windows::Forms::Button());
			this->Delivery = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fullname = (gcnew System::Windows::Forms::TextBox());
			this->phone = (gcnew System::Windows::Forms::TextBox());
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
			this->Client->Click += gcnew System::EventHandler(this, &ForCourier::Client_Click);
			// 
			// Goods
			// 
			this->Goods->Location = System::Drawing::Point(135, 445);
			this->Goods->Name = L"Goods";
			this->Goods->Size = System::Drawing::Size(117, 34);
			this->Goods->TabIndex = 1;
			this->Goods->Text = L"Товар";
			this->Goods->UseVisualStyleBackColor = true;
			this->Goods->Click += gcnew System::EventHandler(this, &ForCourier::Goods_Click);
			// 
			// Market
			// 
			this->Market->Location = System::Drawing::Point(258, 445);
			this->Market->Name = L"Market";
			this->Market->Size = System::Drawing::Size(117, 34);
			this->Market->TabIndex = 2;
			this->Market->Text = L"Магазин";
			this->Market->UseVisualStyleBackColor = true;
			this->Market->Click += gcnew System::EventHandler(this, &ForCourier::Market_Click);
			// 
			// Order
			// 
			this->Order->Location = System::Drawing::Point(381, 445);
			this->Order->Name = L"Order";
			this->Order->Size = System::Drawing::Size(117, 34);
			this->Order->TabIndex = 3;
			this->Order->Text = L"Заказ";
			this->Order->UseVisualStyleBackColor = true;
			this->Order->Click += gcnew System::EventHandler(this, &ForCourier::Order_Click);
			// 
			// Delivery
			// 
			this->Delivery->Location = System::Drawing::Point(504, 445);
			this->Delivery->Name = L"Delivery";
			this->Delivery->Size = System::Drawing::Size(117, 34);
			this->Delivery->TabIndex = 4;
			this->Delivery->Text = L"Доставка";
			this->Delivery->UseVisualStyleBackColor = true;
			this->Delivery->Click += gcnew System::EventHandler(this, &ForCourier::Delivery_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(177, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ФИО Курьера";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Номер телефона";
			// 
			// fullname
			// 
			this->fullname->Location = System::Drawing::Point(18, 66);
			this->fullname->Name = L"fullname";
			this->fullname->Size = System::Drawing::Size(321, 22);
			this->fullname->TabIndex = 7;
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(18, 149);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(321, 22);
			this->phone->TabIndex = 8;
			// 
			// add_new
			// 
			this->add_new->Location = System::Drawing::Point(18, 193);
			this->add_new->Name = L"add_new";
			this->add_new->Size = System::Drawing::Size(111, 39);
			this->add_new->TabIndex = 9;
			this->add_new->Text = L"Добавить";
			this->add_new->UseVisualStyleBackColor = true;
			this->add_new->Click += gcnew System::EventHandler(this, &ForCourier::add_new_Click);
			// 
			// ForCourier
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 491);
			this->Controls->Add(this->add_new);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->fullname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Delivery);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->Market);
			this->Controls->Add(this->Goods);
			this->Controls->Add(this->Client);
			this->Name = L"ForCourier";
			this->Text = L"ForCourier";
			this->Load += gcnew System::EventHandler(this, &ForCourier::ForCourier_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
private: System::Void Client_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Goods_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Market_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Order_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Delivery_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void add_new_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ForCourier_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
