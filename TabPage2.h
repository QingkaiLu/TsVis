#pragma once


// CTabPage2 dialog

class CTabPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabPage2)

public:
	CTabPage2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabPage2();

// Dialog Data
	enum { IDD = IDD_TABPAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
