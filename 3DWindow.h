#pragma once
#include "Polyhedron\Polyhedron.h"
#include "glut.h"
#include "TenVisDoc.h"
#include "FieldRenderer.h"
// C3DWindow

class C3DWindow : public CWnd
{
	DECLARE_DYNAMIC(C3DWindow)

public:
	C3DWindow();
	virtual ~C3DWindow();

	void createWindow(int left, int top, CWnd* parent, CTenVisDoc* pDoc);
	void initOpenGL(void);
protected:
	DECLARE_MESSAGE_MAP()
	UINT_PTR mRenderTimer;
	CTenVisDoc* mDoc;
	HDC mDC;
	
protected:
	HGLRC mRC;
public:
	FieldRenderer* mFieldRenderer;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	CPoint mLastMouseClick;
	/**
	 * Indicate left mouse button down in captured in this window.
	 * Without this, when double-click a file in the open-file-dialog to
	 * load a polyhedron, it would attach an unmeant rotation to the mesh.
	 */
	bool	mLButtonDownReceived;
	bool	mMButtonDownReceived; ///< @see mLButtonDownReceived
	bool	mRButtonDownReceived;

};


