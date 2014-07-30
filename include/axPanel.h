#ifndef __AX_PANEL__
#define __AX_PANEL__

#include "axApp.h"


class axPanel : public axWindow
{
public:
	axPanel(axApp* app, axWindow* parent, const axRect& rect);

	void UpdateAll();
	virtual void Update();

	void GrabMouse();
	void UnGrabMouse();
	bool IsGrabbed();
	bool IsMouseHoverWindow();
	void DeleteWindow(axWindow* win);

	axApp* GetApp();

	void BlockDrawing();
	void BlockDrawing(const axRect& rect);

	void UnBlockDrawing();

private:
	axApp* _app;
};

#endif //__AX_PANEL__