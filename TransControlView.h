#pragma once



// CTransControlView form view

class CTransControlView : public CFormView
{
	DECLARE_DYNCREATE(CTransControlView)

protected:
	CTransControlView();           // protected constructor used by dynamic creation
	virtual ~CTransControlView();

public:
	enum { IDD = IDD_TRANSCONTROLVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


