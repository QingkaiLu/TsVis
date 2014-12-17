#pragma once
#include "MyTabCtrl.h"



// CInputView form view

class CInputView : public CFormView
{
	DECLARE_DYNCREATE(CInputView)

protected:
	CInputView();           // protected constructor used by dynamic creation
	virtual ~CInputView();

public:
	enum { IDD = IDD_INPUTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMyTabCtrl mTabCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


