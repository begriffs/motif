#include <Xm/Xm.h>
#include <Xm/Label.h>

XtAppContext context;
XmStringCharSet char_set=XmSTRING_DEFAULT_CHARSET;

Widget toplevel, label;

int main(int argc, char **argv)
{
	Arg al[10];
	int ac = 0;

	toplevel = XtAppInitialize(&context, "", NULL, 0, &argc, argv, NULL, NULL, 0);
	XtSetArg(al[ac], XmNlabelString,
			XmStringCreateLtoR("Hello world", char_set));
	ac++;
	label = XmCreateLabel(toplevel, "label", al, ac);
	XtManageChild(label);

	XtRealizeWidget(toplevel);
	XtAppMainLoop(context);
}
