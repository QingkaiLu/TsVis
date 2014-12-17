#pragma once


// CTabPage1 dialog

class CTabPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabPage1)

public:
	CTabPage1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabPage1();

// Dialog Data
	enum { IDD = IDD_TABPAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
