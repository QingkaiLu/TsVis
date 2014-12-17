
// TenVisView.cpp : implementation of the CTenVisView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TenVis.h"
#endif

#include "TenVisDoc.h"
#include "TenVisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTenVisView

IMPLEMENT_DYNCREATE(CTenVisView, CView)

BEGIN_MESSAGE_MAP(CTenVisView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTenVisView construction/destruction

CTenVisView::CTenVisView()
{
	// TODO: add construction code here

}

CTenVisView::~CTenVisView()
{
}

BOOL CTenVisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTenVisView drawing

void CTenVisView::OnDraw(CDC* /*pDC*/)
{
	CTenVisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTenVisView printing

BOOL CTenVisView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTenVisView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTenVisView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTenVisView diagnostics

#ifdef _DEBUG
void CTenVisView::AssertValid() const
{
	CView::AssertValid();
}

void CTenVisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTenVisDoc* CTenVisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTenVisDoc)));
	return (CTenVisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTenVisView message handlers
