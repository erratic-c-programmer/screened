#include "headers/bufman.h"

bool add_buf(editor_status *estat, char *fname)
{
	if (estat->open_bufs < MAX_BUF_SZ) {
		estat->buffers[estat->open_bufs - 1].fd = open(fname, O_RDONLY|O_CREAT);
		estat->buffers[estat->open_bufs - 1].filename = fname;
		++(estat->open_bufs);
		return true;
	} else {
		return false;
	}
}

bool rm_buf(editor_status *estat, char *fname)
{
	for (int i = 0; i < MAX_BUF_SZ; ++i) {
		if (estat->buffers[i].filename == fname) {
			close(estat->buffers[i].fd);
			estat->buffers[i].fd = 0;
			estat->buffers[i].filename = "\0";
			--(estat->open_bufs);
			return true;
		} else {
			return false;
		}
	}
}
