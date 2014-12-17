#pragma once
#include "TabPage0.h"
#include "TabPage1.h"
#include "TabPage2.h"

// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabPage0* mPage0;
	CTabPage1* mPage1;
	CTabPage2* mPage2;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
	void activatePages(void);
	void createPages(void);
};


