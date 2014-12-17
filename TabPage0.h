#pragma once


// CTabPage0 dialog

class CTabPage0 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabPage0)

public:
	CTabPage0(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabPage0();

// Dialog Data
	enum { IDD = IDD_TABPAGE0 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
