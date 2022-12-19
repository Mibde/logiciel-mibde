#include "myapp.h"
#include "MyFrame.h"
bool MyApp::OnInit() {
	MyFrame* frame = new MyFrame("Les stock du MIBDE", wxPoint(0, 0), wxSize(1545, 830));
	frame->Show(true);
	return true;
}


IMPLEMENT_APP(MyApp);

