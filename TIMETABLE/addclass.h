#pragma once

#include <unordered_map>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace TIMETABLE {

    public ref class addclass : public System::Windows::Forms::Form
    {
    public:
        addclass(void)
        {
            InitializeComponent();
        }

    protected:
        ~addclass()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::ComboBox^ comboBoxStudentID;
        System::Windows::Forms::ComboBox^ comboBoxTeacherID;
        System::Windows::Forms::ComboBox^ comboBoxRoomID;
        System::Windows::Forms::ComboBox^ comboBoxCourseID;
        System::Windows::Forms::TextBox^ textBoxDay;
        System::Windows::Forms::TextBox^ textBoxStartTime;
        System::Windows::Forms::TextBox^ textBoxEndTime;
        System::Windows::Forms::TextBox^ textBoxSection;
        System::Windows::Forms::Button^ buttonAddClass;
        System::Windows::Forms::Label^ labelStudentID;
        System::Windows::Forms::Label^ labelTeacherID;
        System::Windows::Forms::Label^ labelRoomID;
        System::Windows::Forms::Label^ labelCourseID;
        System::Windows::Forms::Label^ labelDay;
        System::Windows::Forms::Label^ labelStartTime;
        System::Windows::Forms::Label^ labelEndTime;
        System::Windows::Forms::Label^ labelSection;

        void InitializeComponent(void)
        {
            this->comboBoxStudentID = (gcnew System::Windows::Forms::ComboBox());
            this->comboBoxTeacherID = (gcnew System::Windows::Forms::ComboBox());
            this->comboBoxRoomID = (gcnew System::Windows::Forms::ComboBox());
            this->comboBoxCourseID = (gcnew System::Windows::Forms::ComboBox());
            this->textBoxDay = (gcnew System::Windows::Forms::TextBox());
            this->textBoxStartTime = (gcnew System::Windows::Forms::TextBox());
            this->textBoxEndTime = (gcnew System::Windows::Forms::TextBox());
            this->textBoxSection = (gcnew System::Windows::Forms::TextBox());
            this->buttonAddClass = (gcnew System::Windows::Forms::Button());
            this->labelStudentID = (gcnew System::Windows::Forms::Label());
            this->labelTeacherID = (gcnew System::Windows::Forms::Label());
            this->labelRoomID = (gcnew System::Windows::Forms::Label());
            this->labelCourseID = (gcnew System::Windows::Forms::Label());
            this->labelDay = (gcnew System::Windows::Forms::Label());
            this->labelStartTime = (gcnew System::Windows::Forms::Label());
            this->labelEndTime = (gcnew System::Windows::Forms::Label());
            this->labelSection = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // comboBoxStudentID
            // 
            this->comboBoxStudentID->FormattingEnabled = true;
            this->comboBoxStudentID->Location = System::Drawing::Point(130, 30);
            this->comboBoxStudentID->Name = L"comboBoxStudentID";
            this->comboBoxStudentID->Size = System::Drawing::Size(100, 21);
            this->comboBoxStudentID->TabIndex = 0;
            // 
            // comboBoxTeacherID
            // 
            this->comboBoxTeacherID->FormattingEnabled = true;
            this->comboBoxTeacherID->Location = System::Drawing::Point(130, 60);
            this->comboBoxTeacherID->Name = L"comboBoxTeacherID";
            this->comboBoxTeacherID->Size = System::Drawing::Size(100, 21);
            this->comboBoxTeacherID->TabIndex = 1;
            // 
            // comboBoxRoomID
            // 
            this->comboBoxRoomID->FormattingEnabled = true;
            this->comboBoxRoomID->Location = System::Drawing::Point(130, 90);
            this->comboBoxRoomID->Name = L"comboBoxRoomID";
            this->comboBoxRoomID->Size = System::Drawing::Size(100, 21);
            this->comboBoxRoomID->TabIndex = 2;
            // 
            // comboBoxCourseID
            // 
            this->comboBoxCourseID->FormattingEnabled = true;
            this->comboBoxCourseID->Location = System::Drawing::Point(130, 120);
            this->comboBoxCourseID->Name = L"comboBoxCourseID";
            this->comboBoxCourseID->Size = System::Drawing::Size(100, 21);
            this->comboBoxCourseID->TabIndex = 3;
            // 
            // textBoxDay
            // 
            this->textBoxDay->Location = System::Drawing::Point(130, 150);
            this->textBoxDay->Name = L"textBoxDay";
            this->textBoxDay->Size = System::Drawing::Size(100, 20);
            this->textBoxDay->TabIndex = 4;
            // 
            // textBoxStartTime
            // 
            this->textBoxStartTime->Location = System::Drawing::Point(130, 180);
            this->textBoxStartTime->Name = L"textBoxStartTime";
            this->textBoxStartTime->Size = System::Drawing::Size(100, 20);
            this->textBoxStartTime->TabIndex = 5;
            // 
            // textBoxEndTime
            // 
            this->textBoxEndTime->Location = System::Drawing::Point(130, 210);
            this->textBoxEndTime->Name = L"textBoxEndTime";
            this->textBoxEndTime->Size = System::Drawing::Size(100, 20);
            this->textBoxEndTime->TabIndex = 6;
            // 
            // textBoxSection
            // 
            this->textBoxSection->Location = System::Drawing::Point(130, 240);
            this->textBoxSection->Name = L"textBoxSection";
            this->textBoxSection->Size = System::Drawing::Size(100, 20);
            this->textBoxSection->TabIndex = 7;
            // 
            // buttonAddClass
            // 
            this->buttonAddClass->Location = System::Drawing::Point(50, 280);
            this->buttonAddClass->Name = L"buttonAddClass";
            this->buttonAddClass->Size = System::Drawing::Size(75, 23);
            this->buttonAddClass->TabIndex = 8;
            this->buttonAddClass->Text = L"Add";
            this->buttonAddClass->UseVisualStyleBackColor = true;
            this->buttonAddClass->Click += gcnew System::EventHandler(this, &addclass::buttonAddClass_Click);
            // 
            // labelStudentID
            // 
            this->labelStudentID->AutoSize = true;
            this->labelStudentID->Location = System::Drawing::Point(30, 30);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(63, 13);
            this->labelStudentID->Text = L"Student ID:";
            // 
            // labelTeacherID
            // 
            this->labelTeacherID->AutoSize = true;
            this->labelTeacherID->Location = System::Drawing::Point(30, 60);
            this->labelTeacherID->Name = L"labelTeacherID";
            this->labelTeacherID->Size = System::Drawing::Size(68, 13);
            this->labelTeacherID->TabIndex = 10;
            this->labelTeacherID->Text = L"Teacher ID:";
            // 
            // labelRoomID
            // 
            this->labelRoomID->AutoSize = true;
            this->labelRoomID->Location = System::Drawing::Point(30, 90);
            this->labelRoomID->Name = L"labelRoomID";
            this->labelRoomID->Size = System::Drawing::Size(56, 13);
            this->labelRoomID->TabIndex = 11;
            this->labelRoomID->Text = L"Room ID:";
            // 
            // labelCourseID
            // 
            this->labelCourseID->AutoSize = true;
            this->labelCourseID->Location = System::Drawing::Point(30, 120);
            this->labelCourseID->Name = L"labelCourseID";
            this->labelCourseID->Size = System::Drawing::Size(63, 13);
            this->labelCourseID->TabIndex = 12;
            this->labelCourseID->Text = L"Course ID:";
            // 
            // labelDay
            // 
            this->labelDay->AutoSize = true;
            this->labelDay->Location = System::Drawing::Point(30, 150);
            this->labelDay->Name = L"labelDay";
            this->labelDay->Size = System::Drawing::Size(31, 13);
            this->labelDay->TabIndex = 13;
            this->labelDay->Text = L"Day:";
            // 
            // labelStartTime
            // 
            this->labelStartTime->AutoSize = true;
            this->labelStartTime->Location = System::Drawing::Point(30, 180);
            this->labelStartTime->Name = L"labelStartTime";
            this->labelStartTime->Size = System::Drawing::Size(61, 13);
            this->labelStartTime->TabIndex = 14;
            this->labelStartTime->Text = L"Start Time:";
            // 
            // labelEndTime
            // 
            this->labelEndTime->AutoSize = true;
            this->labelEndTime->Location = System::Drawing::Point(30, 210);
            this->labelEndTime->Name = L"labelEndTime";
            this->labelEndTime->Size = System::Drawing::Size(58, 13);
            this->labelEndTime->TabIndex = 15;
            this->labelEndTime->Text = L"End Time:";
            // 
            // labelSection
            // 
            this->labelSection->AutoSize = true;
            this->labelSection->Location = System::Drawing::Point(30, 240);
            this->labelSection->Name = L"labelSection";
            this->labelSection->Size = System::Drawing::Size(46, 13);
            this->labelSection->TabIndex = 16;
            this->labelSection->Text = L"Section:";
            //
            // addclass
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 331);
            this->Controls->Add(this->labelSection);
            this->Controls->Add(this->labelEndTime);
            this->Controls->Add(this->labelStartTime);
            this->Controls->Add(this->labelDay);
            this->Controls->Add(this->labelCourseID);
            this->Controls->Add(this->labelRoomID);
            this->Controls->Add(this->labelTeacherID);
            this->Controls->Add(this->labelStudentID);
            this->Controls->Add(this->buttonAddClass);
            this->Controls->Add(this->textBoxSection);
            this->Controls->Add(this->textBoxEndTime);
            this->Controls->Add(this->textBoxStartTime);
            this->Controls->Add(this->textBoxDay);
            this->Controls->Add(this->comboBoxCourseID);
            this->Controls->Add(this->comboBoxRoomID);
            this->Controls->Add(this->comboBoxTeacherID);
            this->Controls->Add(this->comboBoxStudentID);
            this->Name = L"addclass";
            this->Text = L"Add Class";
            this->Load += gcnew System::EventHandler(this, &addclass::addclass_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void addclass_Load(System::Object^ sender, System::EventArgs^ e) {
        // Load data into ComboBoxes
        LoadComboBoxItems("Students", "Name", comboBoxStudentID);
        LoadComboBoxItems("Teachers", "Name", comboBoxTeacherID);
        LoadComboBoxItems("Rooms", "RoomNumber", comboBoxRoomID);
        LoadComboBoxItems("Courses", "CourseName", comboBoxCourseID);
    }

           // Function to load items from database table into ComboBox
           void LoadComboBoxItems(String^ tableName, String^ columnName, ComboBox^ comboBox) {
               String^ connectionString = "Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;";
               String^ query = "SELECT " + columnName + " FROM " + tableName + ";";

               try {
                   // Open connection
                   SqlConnection^ connection = gcnew SqlConnection(connectionString);
                   SqlCommand^ command = gcnew SqlCommand(query, connection);
                   connection->Open();

                   // Read data
                   SqlDataReader^ reader = command->ExecuteReader();
                   while (reader->Read()) {
                       String^ item = reader[columnName]->ToString();
                       comboBox->Items->Add(item);
                   }

                   // Close connection
                   reader->Close();
                   connection->Close();
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message);
               }
           }

    private: System::Void buttonAddClass_Click(System::Object^ sender, System::EventArgs^ e) {
        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // Find the next available ID
        SqlCommand^ findMaxIdCmd = gcnew SqlCommand("SELECT ISNULL(MAX(ID), 0) + 1 FROM Timetable", sqlConn);
        int nextId = (int)findMaxIdCmd->ExecuteScalar();

        // Create a SQL command to insert data into the "Timetable" table
        SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Timetable (ID, StudentID, TeacherID, RoomID, CourseID, Day, StartTime, EndTime, Section) VALUES (@ID, (SELECT ID FROM Students WHERE Name = @StudentName), (SELECT ID FROM Teachers WHERE Name = @TeacherName), (SELECT ID FROM Rooms WHERE RoomNumber = @RoomName), (SELECT ID FROM Courses WHERE CourseName = @CourseName), @Day, @StartTime, @EndTime, @Section)", sqlConn);

        // Set parameter values
        try {
            cmd->Parameters->AddWithValue("@ID", nextId);
            cmd->Parameters->AddWithValue("@StudentName", comboBoxStudentID->SelectedItem->ToString());
            cmd->Parameters->AddWithValue("@TeacherName", comboBoxTeacherID->SelectedItem->ToString());
            cmd->Parameters->AddWithValue("@RoomName", comboBoxRoomID->SelectedItem->ToString());
            cmd->Parameters->AddWithValue("@CourseName", comboBoxCourseID->SelectedItem->ToString());
            cmd->Parameters->AddWithValue("@Day", textBoxDay->Text);
            cmd->Parameters->AddWithValue("@StartTime", TimeSpan::Parse(textBoxStartTime->Text));
            cmd->Parameters->AddWithValue("@EndTime", TimeSpan::Parse(textBoxEndTime->Text));
            cmd->Parameters->AddWithValue("@Section", textBoxSection->Text);
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message);
            return;
        }

        // Execute the SQL command
        cmd->ExecuteNonQuery();

        // Close the database connection
        sqlConn->Close();

        // Display a message box indicating that the class has been added
        MessageBox::Show("Class added successfully!");

        // Clear the TextBoxes for next input
        textBoxDay->Clear();
        textBoxStartTime->Clear();
        textBoxEndTime->Clear();
        textBoxSection->Clear();
    }
    };
}
