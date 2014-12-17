#pragma once


// C3DContainerView view

class C3DContainerView : public CView
{
	DECLARE_DYNCREATE(C3DContainerView)

protected:
	C3DContainerView();           // protected constructor used by dynamic creation
	virtual ~C3DContainerView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


