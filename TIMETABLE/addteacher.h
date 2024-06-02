#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace TIMETABLE {

    public ref class addteacher : public System::Windows::Forms::Form
    {
    public:
        addteacher(void)
        {
            InitializeComponent();
        }

    protected:
        ~addteacher()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxTeacherName;
        System::Windows::Forms::Button^ buttonAddTeacher;
        System::Windows::Forms::Button^ buttonRemoveTeacher;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBoxTeacherName = (gcnew System::Windows::Forms::TextBox());
            this->buttonAddTeacher = (gcnew System::Windows::Forms::Button());
            this->buttonRemoveTeacher = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBoxTeacherName
            // 
            this->textBoxTeacherName->Location = System::Drawing::Point(30, 30);
            this->textBoxTeacherName->Name = L"textBoxTeacherName";
            this->textBoxTeacherName->Size = System::Drawing::Size(200, 20);
            this->textBoxTeacherName->TabIndex = 0;
            // 
            // buttonAddTeacher
            // 
            this->buttonAddTeacher->Location = System::Drawing::Point(30, 70);
            this->buttonAddTeacher->Name = L"buttonAddTeacher";
            this->buttonAddTeacher->Size = System::Drawing::Size(75, 23);
            this->buttonAddTeacher->TabIndex = 1;
            this->buttonAddTeacher->Text = L"Add";
            this->buttonAddTeacher->UseVisualStyleBackColor = true;
            this->buttonAddTeacher->Click += gcnew System::EventHandler(this, &addteacher::buttonAddTeacher_Click);
            // 
            // buttonRemoveTeacher
            // 
            this->buttonRemoveTeacher->Location = System::Drawing::Point(130, 70);
            this->buttonRemoveTeacher->Name = L"buttonRemoveTeacher";
            this->buttonRemoveTeacher->Size = System::Drawing::Size(75, 23);
            this->buttonRemoveTeacher->TabIndex = 2;
            this->buttonRemoveTeacher->Text = L"Remove";
            this->buttonRemoveTeacher->UseVisualStyleBackColor = true;
            this->buttonRemoveTeacher->Click += gcnew System::EventHandler(this, &addteacher::buttonRemoveTeacher_Click);
            // 
            // addteacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->buttonRemoveTeacher);
            this->Controls->Add(this->buttonAddTeacher);
            this->Controls->Add(this->textBoxTeacherName);
            this->Name = L"addteacher";
            this->Text = L"addteacher";
            this->Load += gcnew System::EventHandler(this, &addteacher::addteacher_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void buttonAddTeacher_Click(System::Object^ sender, System::EventArgs^ e) {
        // Retrieve teacher name from the TextBox
        String^ teacherName = textBoxTeacherName->Text;

        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // Create a SQL command to insert the teacher into the Teachers table
        SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Teachers (Name) VALUES (@Name)", sqlConn);
        cmd->Parameters->AddWithValue("@Name", teacherName);

        // Execute the SQL command to insert the teacher
        try {
            cmd->ExecuteNonQuery();
            MessageBox::Show("Teacher added successfully!");
        }
        catch (SqlException^ ex) {
            MessageBox::Show("Error adding teacher: " + ex->Message);
        }

        // Close the database connection
        sqlConn->Close();
    }

    private: System::Void buttonRemoveTeacher_Click(System::Object^ sender, System::EventArgs^ e) {
        // Retrieve teacher name from the TextBox
        String^ teacherName = textBoxTeacherName->Text;

        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // First, get the teacher's ID
        SqlCommand^ getIdCmd = gcnew SqlCommand("SELECT ID FROM Teachers WHERE Name = @Name", sqlConn);
        getIdCmd->Parameters->AddWithValue("@Name", teacherName);
        SqlDataReader^ reader = getIdCmd->ExecuteReader();
        int teacherId = -1;
        if (reader->Read()) {
            teacherId = reader->GetInt32(0);
        }
        reader->Close();

        if (teacherId != -1) {
            // Delete related records in the Timetable table
            SqlCommand^ deleteTimetableCmd = gcnew SqlCommand("DELETE FROM Timetable WHERE TeacherID = @TeacherID", sqlConn);
            deleteTimetableCmd->Parameters->AddWithValue("@TeacherID", teacherId);

            try {
                deleteTimetableCmd->ExecuteNonQuery();
            }
            catch (SqlException^ ex) {
                MessageBox::Show("Error removing related timetable entries: " + ex->Message);
                sqlConn->Close();
                return;
            }

            // Create a SQL command to delete the teacher from the Teachers table
            SqlCommand^ deleteTeacherCmd = gcnew SqlCommand("DELETE FROM Teachers WHERE ID = @TeacherID", sqlConn);
            deleteTeacherCmd->Parameters->AddWithValue("@TeacherID", teacherId);

            // Execute the SQL command to delete the teacher
            try {
                int rowsAffected = deleteTeacherCmd->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show("Teacher removed successfully!");
                }
                else {
                    MessageBox::Show("Teacher not found!");
                }
            }
            catch (SqlException^ ex) {
                MessageBox::Show("Error removing teacher: " + ex->Message);
            }
        }
        else {
            MessageBox::Show("Teacher not found!");
        }

        // Close the database connection
        sqlConn->Close();
    }


    private: System::Void addteacher_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
