#include "myapp.hpp"
#include "MyFrame.hpp"

bool MyApp::OnInit() {
	MyFrame* frame = new MyFrame("Les stocks du MIBDE", wxPoint(0, 0), wxSize(1600, 830));
	frame->Show(true);
	return true;
}


IMPLEMENT_APP(MyApp);

