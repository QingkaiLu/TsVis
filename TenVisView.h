
// TenVisView.h : interface of the CTenVisView class
//

#pragma once


class CTenVisView : public CView
{
protected: // create from serialization only
	CTenVisView();
	DECLARE_DYNCREATE(CTenVisView)

// Attributes
public:
	CTenVisDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTenVisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TenVisView.cpp
inline CTenVisDoc* CTenVisView::GetDocument() const
   { return reinterpret_cast<CTenVisDoc*>(m_pDocument); }
#endif

