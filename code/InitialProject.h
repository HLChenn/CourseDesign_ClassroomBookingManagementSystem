#pragma once
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include<conio.h>


//此文件包含：1.主菜单初始化；2.登录窗口；3.各类人员的子菜单选择
void RunMainMenu();
void Login(string fileName, int choice, int select);
void managerMenu(User* manager);                         ///所有函数作用的注释均在对应的源文件中
void normalStudentMenu(User* normalstudent);
void MonitorMenu(User* monitor);
void CounsellorMenu(User* counsellor);
void TechnicianMenu(User* technician);



