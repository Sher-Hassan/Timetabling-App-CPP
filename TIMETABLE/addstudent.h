#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace TIMETABLE {

    /// <summary>
    /// Summary for addstudent
    /// </summary>
    public ref class addstudent : public System::Windows::Forms::Form
    {
    public:
        addstudent(void)
        {
            InitializeComponent();
        }

    protected:
        ~addstudent()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxStudentName;
        System::Windows::Forms::Button^ buttonAdd;
        System::Windows::Forms::Button^ buttonRemove;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBoxStudentName = (gcnew System::Windows::Forms::TextBox());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->buttonRemove = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBoxStudentName
            // 
            this->textBoxStudentName->Location = System::Drawing::Point(30, 30);
            this->textBoxStudentName->Name = L"textBoxStudentName";
            this->textBoxStudentName->Size = System::Drawing::Size(200, 20);
            this->textBoxStudentName->TabIndex = 0;
            // 
            // buttonAdd
            // 
            this->buttonAdd->Location = System::Drawing::Point(30, 70);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(75, 23);
            this->buttonAdd->TabIndex = 1;
            this->buttonAdd->Text = L"Add";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew System::EventHandler(this, &addstudent::buttonAdd_Click);
            // 
            // buttonRemove
            // 
            this->buttonRemove->Location = System::Drawing::Point(130, 70);
            this->buttonRemove->Name = L"buttonRemove";
            this->buttonRemove->Size = System::Drawing::Size(75, 23);
            this->buttonRemove->TabIndex = 2;
            this->buttonRemove->Text = L"Remove";
            this->buttonRemove->UseVisualStyleBackColor = true;
            this->buttonRemove->Click += gcnew System::EventHandler(this, &addstudent::buttonRemove_Click);
            // 
            // addstudent
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->buttonRemove);
            this->Controls->Add(this->buttonAdd);
            this->Controls->Add(this->textBoxStudentName);
            this->Name = L"addstudent";
            this->Text = L"addstudent";
            this->Load += gcnew System::EventHandler(this, &addstudent::addstudent_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        // Retrieve student name from the TextBox
        String^ studentName = textBoxStudentName->Text;

        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // Create a SQL command to insert the student into the Students table
        SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Students (Name) VALUES (@Name)", sqlConn);
        cmd->Parameters->AddWithValue("@Name", studentName);

        // Execute the SQL command to insert the student
        try {
            cmd->ExecuteNonQuery();
            MessageBox::Show("Student added successfully!");
        }
        catch (SqlException^ ex) {
            MessageBox::Show("Error adding student: " + ex->Message);
        }

        // Close the database connection
        sqlConn->Close();
    }

    private: System::Void buttonRemove_Click(System::Object^ sender, System::EventArgs^ e) {
        // Retrieve student name from the TextBox
        String^ studentName = textBoxStudentName->Text;

        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // First, get the student's ID
        SqlCommand^ getIdCmd = gcnew SqlCommand("SELECT ID FROM Students WHERE Name = @Name", sqlConn);
        getIdCmd->Parameters->AddWithValue("@Name", studentName);
        SqlDataReader^ reader = getIdCmd->ExecuteReader();
        int studentId = -1;
        if (reader->Read()) {
            studentId = reader->GetInt32(0);
        }
        reader->Close();

        if (studentId != -1) {
            // Delete related records in the Timetable table (if any)
            SqlCommand^ deleteTimetableCmd = gcnew SqlCommand("DELETE FROM Timetable WHERE StudentID = @StudentID", sqlConn);
            deleteTimetableCmd->Parameters->AddWithValue("@StudentID", studentId);

            try {
                deleteTimetableCmd->ExecuteNonQuery();
            }
            catch (SqlException^ ex) {
                MessageBox::Show("Error removing related timetable entries: " + ex->Message);
                sqlConn->Close();
                return;
            }

            // Create a SQL command to delete the student from the Students table
            SqlCommand^ deleteStudentCmd = gcnew SqlCommand("DELETE FROM Students WHERE ID = @StudentID", sqlConn);
            deleteStudentCmd->Parameters->AddWithValue("@StudentID", studentId);

            // Execute the SQL command to delete the student
            try {
                int rowsAffected = deleteStudentCmd->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show("Student removed successfully!");
                }
                else {
                    MessageBox::Show("Student not found!");
                }
            }
            catch (SqlException^ ex) {
                MessageBox::Show("Error removing student: " + ex->Message);
            }
        }
        else {
            MessageBox::Show("Student not found!");
        }

        // Close the database connection
        sqlConn->Close();
    }

    private: System::Void addstudent_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
