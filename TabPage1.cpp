// TabPage1.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "TabPage1.h"
#include "afxdialogex.h"


// CTabPage1 dialog

IMPLEMENT_DYNAMIC(CTabPage1, CDialogEx)

CTabPage1::CTabPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabPage1::IDD, pParent)
{

}

CTabPage1::~CTabPage1()
{
}

void CTabPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabPage1, CDialogEx)
END_MESSAGE_MAP()


// CTabPage1 message handlers
