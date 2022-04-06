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

	/* Yeppp, got burned by this initially:
	 *
	 * XtSetArg(3)
	 *
	 * Note that you should not use auto-increment or auto-decrement within the
	 * first argument to XtSetArg.  XtSetArg can be implemented as a macro that
	 * dereferences the first argument twice.
	 */
	XtSetArg(al[ac], XmNlabelString,
			XmStringCreateLtoR("Hello world", char_set));
	ac++;
	label = XmCreateLabel(toplevel, "label", al, ac);
	XtManageChild(label);

	XtRealizeWidget(toplevel);
	XtAppMainLoop(context);
}
