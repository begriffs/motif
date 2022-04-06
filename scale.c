#include <Xm/Xm.h>
#include <Xm/Scale.h>

XtAppContext context;

Widget toplevel, scale;

int main(int argc, char **argv)
{
	Arg al[10];
	int ac;

	toplevel = XtAppInitialize(&context, "", NULL, 0, &argc, argv, NULL, NULL, 0);

	ac = 0;
	XtSetArg(al[ac], XmNshowValue, True); ac++;
	scale = XmCreateScale(toplevel, "scale", al, ac);
	XtManageChild(scale);

	XtRealizeWidget(toplevel);
	XtAppMainLoop(context);
}
