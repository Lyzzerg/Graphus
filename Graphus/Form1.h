#pragma once
//#pragma warning ( disable : 4368 )
#include "GraphicStorage.h"
#include "THeadList.h"
#include <stdio.h>
namespace Graphus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace LIST;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		int tmpx, tmpy, lay;
		TObject *point;
		int DrawingMode; //0-point 1-line;
		TGroup *group, *layers;
		TChart *chart;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  layotnum;
	private: System::Windows::Forms::Button^  decreaselayot;
	private: System::Windows::Forms::Button^  increaselayot;







	public: 
		Graphics^ gr;
		Form1(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			group= new TGroup;
			layers = new TGroup;
			chart= new TChart;
			DrawingMode=0;
			lay = 0;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->layotnum = (gcnew System::Windows::Forms::Label());
			this->decreaselayot = (gcnew System::Windows::Forms::Button());
			this->increaselayot = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(341, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Hide";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 274);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Show";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(13, 13);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(78, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"ChartMode";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckStateChanged);
			// 
			// layotnum
			// 
			this->layotnum->AutoSize = true;
			this->layotnum->Location = System::Drawing::Point(154, 280);
			this->layotnum->Name = L"layotnum";
			this->layotnum->Size = System::Drawing::Size(25, 13);
			this->layotnum->TabIndex = 4;
			this->layotnum->Text = L"000";
			// 
			// decreaselayot
			// 
			this->decreaselayot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold));
			this->decreaselayot->Location = System::Drawing::Point(185, 274);
			this->decreaselayot->Name = L"decreaselayot";
			this->decreaselayot->Size = System::Drawing::Size(30, 23);
			this->decreaselayot->TabIndex = 5;
			this->decreaselayot->Text = L"-";
			this->decreaselayot->UseVisualStyleBackColor = true;
			this->decreaselayot->Click += gcnew System::EventHandler(this, &Form1::decreaselayot_Click);
			// 
			// increaselayot
			// 
			this->increaselayot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold));
			this->increaselayot->Location = System::Drawing::Point(118, 274);
			this->increaselayot->Name = L"increaselayot";
			this->increaselayot->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->increaselayot->Size = System::Drawing::Size(30, 23);
			this->increaselayot->TabIndex = 6;
			this->increaselayot->Text = L"+";
			this->increaselayot->UseVisualStyleBackColor = true;
			this->increaselayot->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::increaselayot_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(428, 309);
			this->Controls->Add(this->increaselayot);
			this->Controls->Add(this->decreaselayot);
			this->Controls->Add(this->layotnum);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (checkBox1->CheckState == CheckState::Unchecked)
					group->Hide(gr);
				 else
				 {
					 layers->objects->pCurrent->value->Hide(gr);
				 }
			 }
	private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			 {
				
				 if(point!=NULL)
					point->MoveTo(gr, e->Location.X, e->Location.Y);
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (checkBox1->CheckState == CheckState::Unchecked)
					group->Show(gr);
				 else
				 {
					 layers->objects->pCurrent->value->Show(gr);
				 }
			 }
private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	tmpx = e->Location.X;
	tmpy = e->Location.Y;
}
private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (checkBox1->CheckState == CheckState::Unchecked)
	{
		if (e->Location.X == tmpx && e->Location.Y == tmpy)
		{
			group->AddObj(new TPoint());
			group->objects->setCurrent(1);
			group->objects->pCurrent->value->MoveTo(gr, tmpx, tmpy);
		}
		else
		{
			group->AddObj(new TLine(tmpx, tmpy, e->Location.X, e->Location.Y));
			group->objects->setCurrent(1);
			group->objects->pCurrent->value->Show(gr);
		}
	}
	else
	{
		dynamic_cast<TChart*>(layers->objects->pCurrent->value)->AddClosestLine(tmpx, tmpy, e->Location.X, e->Location.Y);
		layers->objects->pCurrent->value->Show(gr);
	}
}
private: System::Void checkBox1_CheckStateChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (checkBox1->CheckState == CheckState::Unchecked)
	{
		chart->Hide(gr);
		group->Show(gr);
	}
	else
	{
		group->Hide(gr);
	}
}
private: System::Void increaselayot_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e){
	if(lay<999)
		lay++;
	layotnum->Text = "" + lay;
	if (layers->quantity < lay)
	{
		if (layers->quantity != 0)
			layers->objects->pCurrent->value->Hide(gr);
		layers->AddObj(new TChart());
		layers->objects->setCurrent(layers->quantity-lay+1);
		layers->objects->pCurrent->value->Show(gr);
	}
	else
	{
		layers->objects->pCurrent->value->Hide(gr);
		layers->objects->setCurrent(layers->quantity - lay + 1);
		layers->objects->pCurrent->value->Show(gr);
	}
}
private: System::Void decreaselayot_Click(System::Object^  sender, System::EventArgs^  e) {
	if (lay > 1)
	{
		layers->objects->pCurrent->value->Hide(gr);
		lay--;
		layotnum->Text = "" + lay;
		layers->objects->setCurrent(layers->quantity - lay + 1);
		layers->objects->pCurrent->value->Show(gr);
	}
}
};
}

