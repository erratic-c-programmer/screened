#ifndef INCLUDE_INCLUDE
#include "../../include.h"
#endif
#ifndef INCLUDE_STROP
#include "../../dynstr/headers/strop.h"
#endif
#ifndef INCLUDE_SCREENINFO
#include "../../screenop/headers/screeninfo.h"
#endif
#ifndef INCLUDE_SCREENMANIP
#include "../../screenop/headers/screenmanip.h"
#endif
#define INCLUDE_OUTPUT
void refreshscrn(editor_status *estat);
void clearscrn(editor_status *estat);
void tildes(editor_status *estat, short unsigned int startrow);
void ptop(editor_status *estat, const char *s);
void pmid(editor_status *estat, const char *s);
void pbot(editor_status *estat, const char *s);
void pline(editor_status *estat, int ln, const char *s);
