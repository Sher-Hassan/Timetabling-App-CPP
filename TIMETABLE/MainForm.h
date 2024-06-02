#pragma once
#include "viewtimetable.h"
#include "addclass.h"
#include "removeclass.h"
#include "addstudent.h"
#include "addteacher.h"
#include "coursewise.h"
#include "daywise.h"
#include "studentwise.h"
#include "teacherwise.h"

namespace TIMETABLE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ viewtimetable;
	protected:
	private: System::Windows::Forms::Button^ swtimetable;
	private: System::Windows::Forms::Button^ twtimetable;
	private: System::Windows::Forms::Button^ cwtimetable;
	private: System::Windows::Forms::Button^ addteacher;
	private: System::Windows::Forms::Button^ addstudent;


	private: System::Windows::Forms::Button^ dwtimetable;
	private: System::Windows::Forms::Button^ addclass;
	private: System::Windows::Forms::Button^ removeclass;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->viewtimetable = (gcnew System::Windows::Forms::Button());
			this->swtimetable = (gcnew System::Windows::Forms::Button());
			this->twtimetable = (gcnew System::Windows::Forms::Button());
			this->cwtimetable = (gcnew System::Windows::Forms::Button());
			this->addteacher = (gcnew System::Windows::Forms::Button());
			this->addstudent = (gcnew System::Windows::Forms::Button());
			this->dwtimetable = (gcnew System::Windows::Forms::Button());
			this->addclass = (gcnew System::Windows::Forms::Button());
			this->removeclass = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// viewtimetable
			// 
			this->viewtimetable->Location = System::Drawing::Point(42, 12);
			this->viewtimetable->Name = L"viewtimetable";
			this->viewtimetable->Size = System::Drawing::Size(201, 23);
			this->viewtimetable->TabIndex = 0;
			this->viewtimetable->Text = L"View Timetable";
			this->viewtimetable->UseVisualStyleBackColor = true;
			this->viewtimetable->Click += gcnew System::EventHandler(this, &MainForm::viewtimetable_Click);
			// 
			// swtimetable
			// 
			this->swtimetable->Location = System::Drawing::Point(42, 41);
			this->swtimetable->Name = L"swtimetable";
			this->swtimetable->Size = System::Drawing::Size(201, 23);
			this->swtimetable->TabIndex = 1;
			this->swtimetable->Text = L"Student Wise Timetable";
			this->swtimetable->UseVisualStyleBackColor = true;
			this->swtimetable->Click += gcnew System::EventHandler(this, &MainForm::swtimetable_Click);
			// 
			// twtimetable
			// 
			this->twtimetable->Location = System::Drawing::Point(42, 70);
			this->twtimetable->Name = L"twtimetable";
			this->twtimetable->Size = System::Drawing::Size(201, 23);
			this->twtimetable->TabIndex = 2;
			this->twtimetable->Text = L"Teacher Wise Timetable";
			this->twtimetable->UseVisualStyleBackColor = true;
			this->twtimetable->Click += gcnew System::EventHandler(this, &MainForm::twtimetable_Click);
			// 
			// cwtimetable
			// 
			this->cwtimetable->Location = System::Drawing::Point(42, 99);
			this->cwtimetable->Name = L"cwtimetable";
			this->cwtimetable->Size = System::Drawing::Size(201, 23);
			this->cwtimetable->TabIndex = 3;
			this->cwtimetable->Text = L"Course Wise Timetable";
			this->cwtimetable->UseVisualStyleBackColor = true;
			this->cwtimetable->Click += gcnew System::EventHandler(this, &MainForm::cwtimetable_Click);
			// 
			// addteacher
			// 
			this->addteacher->Location = System::Drawing::Point(42, 216);
			this->addteacher->Name = L"addteacher";
			this->addteacher->Size = System::Drawing::Size(201, 23);
			this->addteacher->TabIndex = 4;
			this->addteacher->Text = L"Add/Remove Teacher";
			this->addteacher->UseVisualStyleBackColor = true;
			this->addteacher->Click += gcnew System::EventHandler(this, &MainForm::addteacher_Click);
			// 
			// addstudent
			// 
			this->addstudent->Location = System::Drawing::Point(42, 245);
			this->addstudent->Name = L"addstudent";
			this->addstudent->Size = System::Drawing::Size(201, 23);
			this->addstudent->TabIndex = 5;
			this->addstudent->Text = L"Add/Remove Student";
			this->addstudent->UseVisualStyleBackColor = true;
			this->addstudent->Click += gcnew System::EventHandler(this, &MainForm::addstudent_Click);
			// 
			// dwtimetable
			// 
			this->dwtimetable->Location = System::Drawing::Point(42, 128);
			this->dwtimetable->Name = L"dwtimetable";
			this->dwtimetable->Size = System::Drawing::Size(201, 23);
			this->dwtimetable->TabIndex = 6;
			this->dwtimetable->Text = L"Day Wise Timetable";
			this->dwtimetable->UseVisualStyleBackColor = true;
			this->dwtimetable->Click += gcnew System::EventHandler(this, &MainForm::dwtimetable_Click);
			// 
			// addclass
			// 
			this->addclass->Location = System::Drawing::Point(42, 157);
			this->addclass->Name = L"addclass";
			this->addclass->Size = System::Drawing::Size(201, 23);
			this->addclass->TabIndex = 7;
			this->addclass->Text = L"Add Class";
			this->addclass->UseVisualStyleBackColor = true;
			this->addclass->Click += gcnew System::EventHandler(this, &MainForm::addclass_Click);
			// 
			// removeclass
			// 
			this->removeclass->Location = System::Drawing::Point(42, 187);
			this->removeclass->Name = L"removeclass";
			this->removeclass->Size = System::Drawing::Size(201, 23);
			this->removeclass->TabIndex = 8;
			this->removeclass->Text = L"Remove Class";
			this->removeclass->UseVisualStyleBackColor = true;
			this->removeclass->Click += gcnew System::EventHandler(this, &MainForm::removeclass_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(287, 390);
			this->Controls->Add(this->removeclass);
			this->Controls->Add(this->addclass);
			this->Controls->Add(this->dwtimetable);
			this->Controls->Add(this->addstudent);
			this->Controls->Add(this->addteacher);
			this->Controls->Add(this->cwtimetable);
			this->Controls->Add(this->twtimetable);
			this->Controls->Add(this->swtimetable);
			this->Controls->Add(this->viewtimetable);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void viewtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
    // Create an instance of the ViewTimetable form
    TIMETABLE::viewtimetable^ viewTimetableForm = gcnew TIMETABLE::viewtimetable();

    // Show the ViewTimetable form 
    viewTimetableForm->Show();
}
private: System::Void swtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
    // Create an instance of the StudentWise form
    TIMETABLE::studentwise^ studentWiseForm = gcnew TIMETABLE::studentwise();

    // Show the StudentWise form
    studentWiseForm->Show();
}
private: System::Void twtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the TeacherWise form
	TIMETABLE::teacherwise^ teacherWiseForm = gcnew TIMETABLE::teacherwise();

	// Show the TeacherWise form
	teacherWiseForm->Show();
}
private: System::Void cwtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the CourseWise form
	TIMETABLE::coursewise^ courseWiseForm = gcnew TIMETABLE::coursewise();

	// Show the CourseWise form
	courseWiseForm->Show();
}
private: System::Void dwtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the DayWise form
	TIMETABLE::daywise^ dayWiseForm = gcnew TIMETABLE::daywise();

	// Show the DayWise form
	dayWiseForm->Show();
}
private: System::Void addclass_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the AddClass form
	TIMETABLE::addclass^ addClassForm = gcnew TIMETABLE::addclass();

	// Show the AddClass form
	addClassForm->Show();
}
private: System::Void addteacher_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the AddTeacher form
	TIMETABLE::addteacher^ addTeacherForm = gcnew TIMETABLE::addteacher();

	// Show the AddTeacher form
	addTeacherForm->Show();
}
private: System::Void addstudent_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the AddStudent form
	TIMETABLE::addstudent^ addStudentForm = gcnew TIMETABLE::addstudent();

	// Show the AddStudent form
	addStudentForm->Show();
}
private: System::Void removeclass_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the AddClass form
	TIMETABLE::removeclass^ removeClassForm = gcnew TIMETABLE::removeclass();

	// Show the AddClass form
	removeClassForm->Show();
}
};
}
