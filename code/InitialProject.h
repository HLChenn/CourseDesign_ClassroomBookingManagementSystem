#pragma once
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include<conio.h>


//���ļ�������1.���˵���ʼ����2.��¼���ڣ�3.������Ա���Ӳ˵�ѡ��
void RunMainMenu();
void Login(string fileName, int choice, int select);
void managerMenu(User* manager);                         ///���к������õ�ע�;��ڶ�Ӧ��Դ�ļ���
void normalStudentMenu(User* normalstudent);
void MonitorMenu(User* monitor);
void CounsellorMenu(User* counsellor);
void TechnicianMenu(User* technician);



