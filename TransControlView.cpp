// TransControlView.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "TransControlView.h"


// CTransControlView

IMPLEMENT_DYNCREATE(CTransControlView, CFormView)

CTransControlView::CTransControlView()
	: CFormView(CTransControlView::IDD)
{

}

CTransControlView::~CTransControlView()
{
}

void CTransControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTransControlView, CFormView)
END_MESSAGE_MAP()


// CTransControlView diagnostics

#ifdef _DEBUG
void CTransControlView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTransControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTransControlView message handlers
